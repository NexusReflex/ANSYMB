/***************************************************************************
                          sfc_clm.cpp  -  description
                             -------------------
    begin                :
    copyright            : (C) 2003 Max Planck Institute for Dynamics
                                    of Complex Dynamical Systems
    Author               :  Nils-Otto Negård
                            Thomas Schauer

    email                : negaard@mpi-magdburg.mpg.de

    * Adaptation for Hasomed Stimulator
    * Added /dev/stimulator for udev systems
    * Added variable PCFrequencyControl
    * For PCFrequencyControl updates are only send if sum of 
      currents and pulsewidths is larger than zero
    * Added muteperiod in ms as output 
    *

    Modified by Henrik Gollee <henrik@mech.gla.ac.uk> Nov 2006:
    *    Avoid communication with stimulator if it is not present using 
    *    static variable DoStim
    *    added error handling if initialisation fails in stim.Send_Init_Param
    *    Replaced printf with ssPrintf

 ***************************************************************************/
/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#include "sciencemode.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h> 

int retval;
static int Start;
static int PCFrequencyControl;
/*
 * You must specify the S_FUNCTION_NAME as the name of your S-function
 * (i.e. replace sfuntmpl_basic with the name of your S-function).
 */

#ifdef __cplusplus
extern "C" {
#endif

#define S_FUNCTION_NAME  sfc_clm
#define S_FUNCTION_LEVEL 2

/*
 * Need to include simstruc.h for the definition of the SimStruct and
 * its associated macro definitions.
 */
#include "simstruc.h"

/* Define for easy access to the input arguments */
#define SAMPLETIME(S) ssGetSFcnParam(S,0)
#define COMPORT(S) ssGetSFcnParam(S,1)
#define CHANNELSSTIM(S) ssGetSFcnParam(S,2)
#define TSONE(S) ssGetSFcnParam(S,3)
#define TSTWO(S) ssGetSFcnParam(S,4)
#define MODE(S) ssGetSFcnParam(S,5)
#define CHANNELLF(S) ssGetSFcnParam(S,6)
#define NFACTOR(S) ssGetSFcnParam(S,7)

/* some static variables */
static stimulator stim;
static int nc;
static char msg[256];
static int disable_flag=0;
static double *S_Channel_Stim;
static double S_Main_Time;
static double S_Group_Time;
static double S_Mode;
static double *S_Channel_Lf;
static double S_N_Factor;
static int n_lf;
static int DoStim;

/*====================*
 * S-function methods *
 *====================*/

/* Function: mdlInitializeSizes ===============================================
 * Abstract:
 *    The sizes information is used by Simulink to determine the S-function
 *    block's characteristics (number of inputs, outputs, states, etc.).
 */
static void mdlInitializeSizes(SimStruct *S)
{ 
  /* See sfuntmpl_doc.c for more details on the macros below */

  ssSetNumSFcnParams(S, 8);  /* Number of expected parameters */
  if (ssGetNumSFcnParams(S) != ssGetSFcnParamsCount(S)) {
    /* Return if number of expected != number of actual parameters */
    return;
  }

  ssSetNumContStates(S, 0);
  ssSetNumDiscStates(S, 0);

  if (!ssSetNumInputPorts(S, 3)) return;
  ssSetInputPortWidth(S, 0, DYNAMICALLY_SIZED);  /* current */
  ssSetInputPortRequiredContiguous(S, 0, true); /*direct input signal access*/
  ssSetInputPortWidth(S, 1, DYNAMICALLY_SIZED);  /* pulsewidth */
  ssSetInputPortRequiredContiguous(S, 1, true); /*direct input signal access*/
  ssSetInputPortWidth(S, 2, DYNAMICALLY_SIZED);  /* pulsewidth */
  ssSetInputPortRequiredContiguous(S, 2, true); /*direct input signal access*/

  /*
   * Set direct feedthrough flag (1=yes, 0=no).
   * A port has direct feedthrough if the input is used in either
   * the mdlOutputs or mdlGetTimeOfNextVarHit functions.
   * See matlabroot/simulink/src/sfuntmpl_directfeed.txt.
   */
  ssSetInputPortDirectFeedThrough(S, 0, 1);
  ssSetInputPortDirectFeedThrough(S, 1, 1);
  ssSetInputPortDirectFeedThrough(S, 2, 1);
  
  if (!ssSetNumOutputPorts(S, 1)) return;
  ssSetOutputPortWidth(S, 0, 1);

  ssSetNumSampleTimes(S, 1);
  ssSetNumRWork(S, 0);
  ssSetNumIWork(S, 0);
  ssSetNumPWork(S, 0);
  ssSetNumModes(S, 0);
  ssSetNumNonsampledZCs(S, 0);
  ssSetOptions(S, 0);
}

/* Function: mdlInitializeSampleTimes =========================================
 * Abstract:
 *    This function is used to specify the sample time(s) for your
 *    S-function. You must register the aame number of sample times as
 *    specified in ssSetNumSampleTimes.
 */
static void mdlInitializeSampleTimes(SimStruct *S)
{
  ssSetSampleTime(S, 0, mxGetScalar(SAMPLETIME(S))); /* USED FOR TESTING  */
  /*ssSetSampleTime(S, 0, INHERITED_SAMPLE_TIME);  */
  ssSetOffsetTime(S, 0, 0.0);

}

#undef MDL_INITIALIZE_CONDITIONS   /* Change to #undef to remove function */
#if defined(MDL_INITIALIZE_CONDITIONS)
/* Function: mdlInitializeConditions ========================================
 * Abstract:
 *    In this function, you should initialize the continuous and discrete
 *    states for your S-function block.  The initial states are placed
 *    in the state vector, ssGetContStates(S) or ssGetRealDiscStates(S).
 *    You can also perform any other initialization activities that your
 *    S-function may require. Note, this routine will be called at the
 *    start of simulation and if it is present in an enabled subsystem
 *    configured to reset states, it will be call when the enabled subsystem
 *    restarts execution to reset the states.
 */
static void mdlInitializeConditions(SimStruct *S)
{
}
#endif /* MDL_INITIALIZE_CONDITIONS */

#define MDL_START  /* Change to #undef to remove function */
#if defined(MDL_START) 
/* Function: mdlStart =======================================================
 * Abstract:
 *    This function is called once at start of model execution. If you
 *    have states that should be initialized once, this is the place
 *    to do it.
 */
static void mdlStart(SimStruct *S)
{
  unsigned int  ncc, nc1, nc2;
  int ret;
  int comport;
  //char *comport;
  int error;
  char errorStringBuffer[200];
  int j;
  /*Getting the parameters */
  S_Channel_Stim = (double *) mxGetPr(CHANNELSSTIM(S)); // Channels of stimulation
  S_Main_Time = mxGetScalar(TSONE(S));          // Main Time
  S_Group_Time = mxGetScalar(TSTWO(S));          // Group Time
  S_Mode =(double)mxGetScalar(MODE(S));           // Mode update, no more needed
  S_Channel_Lf =(double *) mxGetPr(CHANNELLF(S));      // List of channels with low freq
  S_N_Factor = (double)mxGetScalar(NFACTOR(S));      // The n_factor
  n_lf = mxGetNumberOfElements(CHANNELLF(S));
  
  /* the serial port port */
  if (!mxIsDouble(COMPORT(S))) {
    ssSetErrorStatus(S,"The first argument needs to be the number of the serial port, e.g. 1 for COM1 or /dev/ttyS0, 2 for COM2 or /dev/ttyS1 etc.\n");
    return;
  } else {
    if (mxGetNumberOfElements(COMPORT(S))!=1) {
      ssSetErrorStatus(S,"The first argument needs to be scalar, e.g. 1 or 2.\n");
      return;
    } else {
      comport = (int) mxGetScalar(COMPORT(S));   
    }
  }

  /* the channels */
  if (!mxIsNumeric(CHANNELSSTIM(S))) {
    ssSetErrorStatus(S, "The second argument indicates the channels to be stimulated.\nIt needs to be a numerical vector.\n");
    return;
  }
  if ((mxGetN(CHANNELSSTIM(S))!=1) && (mxGetM(CHANNELSSTIM(S))!=1)){
    ssSetErrorStatus(S, "The second argument needs to be a vector.\n");
    return;
  }
  /* check the dimensions */
  ncc = mxGetNumberOfElements(CHANNELSSTIM(S));
  nc1 = ssGetInputPortWidth(S,0);
  nc2 = ssGetInputPortWidth(S,1);
  if (nc1!=nc2) {
    sprintf(msg,"Both block inputs must have the same width:\n Width of current = %1,\n Width of pulsewidth = %2.\n", nc1, nc2);
    ssSetErrorStatus(S, msg);
    return;
  } else {
    nc = nc1;
  }
  if (nc!=ncc){
    sprintf(msg,"Number of channels in 2nd arguments is %i, but block inputs have a width of %i.\n They must be equal.\n", ncc, nc);
    ssSetErrorStatus(S, msg);
    return;
  }
  if (nc>8){
    sprintf(msg,"%i channels detected.\nThe maximal number of channels is 8.\n",nc);
    ssSetErrorStatus(S, msg);
    return;
  }


  DoStim=1;
  if (ssGetSimMode(S) == SS_SIMMODE_NORMAL) 
  {
    if (DoStim) {
      { 
	error=stim.Open_serial((char *) SerialPortList[comport-1]);
      }

      if (error>0) 
      {
	//ssSetErrorStatus(S,"Could not open the serial port");
	//return;
	ssWarning(S,"\nCould not open the serial port\n");
	DoStim=0;
      }
    }
    if (DoStim) {
      error=stim.Setup_serial();
      if (error>0)
      {
	//ssSetErrorStatus(S,"Error setting up port");
	//return;
	stim.Close_serial();
	ssWarning(S,"\nError setting up port. Closing serial port.\n");
	DoStim=0;
      }
    }
    if (DoStim) {
      error = stim.Send_Init_Param(ncc,S_Channel_Stim,n_lf,S_Channel_Lf,
	  S_Main_Time,S_Group_Time,S_N_Factor);
      if (error>0)
      {
	j=sprintf(errorStringBuffer,"stim.Send_Init_Param: Could not initialise the CLM!\n");
	switch (error) {
	case 1:
	  j+=sprintf(errorStringBuffer + j,"Channel_Stim==0, no channels in the channel list\n");
	  break;
	case 2:
	  j+=sprintf(errorStringBuffer + j,"Group Time > Main_Time, Initialisation unsuccessfully\n");
	  break;
	case 3:
	  j+=sprintf(errorStringBuffer + j,"Did not receive any byte from stimulator\n");
	  j+=sprintf(errorStringBuffer + j,"Stimulator switched on, Sciencemode selected?\n");
	  j+=sprintf(errorStringBuffer + j,"To run the simulation anyway unplug the stimulator!");
	  break;
	case 4:
	  j+=sprintf(errorStringBuffer + j,"did not receive confirmation from stimulator\n");
	  break;
	case 5:
	  j+=sprintf(errorStringBuffer + j,"Group Time < nc * 1.5\n");
	  break;
	}
	ssSetErrorStatus(S,errorStringBuffer);
	ssPrintf("Closing serial port...");
	error=stim.Close_serial();  
	if (error == 0) 
	  ssPrintf("done.\n");
	else 
	  ssPrintf("failed.\n");
	//ssSetErrorStatus(S,"Could not initialise the CLM!");
	//return;
	return;
	DoStim=0;
      }
      else
      {
	if (S_Main_Time==0)
	  PCFrequencyControl=1;
	else
	  PCFrequencyControl=0;
      }
    } 
  }
}

#endif /*  MDL_START */



/* Function: mdlOutputs =======================================================
 *	 Abstract:
 *    In this function, you compute the outputs of your S-function
 *    block. Generally outputs are placed in the output vector, ssGetY(S).
 */
static void mdlOutputs(SimStruct *S, int_T tid)
{

  int ret,i;
  double * S_Pulse_Current =  (real_T *)ssGetInputPortRealSignalPtrs(S,0);
  double * S_Pulse_Width =  (real_T *)ssGetInputPortRealSignalPtrs(S,1);
  double * S_Mode =  (real_T *)ssGetInputPortRealSignalPtrs(S,2);
  unsigned char stimulation_active;
  int ncc = mxGetNumberOfElements(CHANNELSSTIM(S));
  double sum_cur=0;
  double sum_pw=0;
  
  double max_mode;

  real_T       *mute_period  = ssGetOutputPortRealSignal(S,0);

  if (DoStim) {
    max_mode=1;
    for (i=0;i<ncc;i++)
    {
      sum_cur=sum_cur+S_Pulse_Current[i];
      sum_pw=sum_pw+S_Pulse_Width[i];
      if ((S_Mode[i]+1)>max_mode)
	max_mode=(S_Mode[i]+1);
    }


    //if frequency is controlled by the pc then only send updates if realy stimulation in on
    if (PCFrequencyControl==1){
      if ((sum_cur>0)&&(sum_pw>0))
      {
	ret=stim.Send_Update_Parameter(S_Pulse_Width,S_Pulse_Current,S_Mode,nc);
	* mute_period = (real_T) (double) (S_Group_Time * max_mode);
      }
      else
	* mute_period = 0;
    }
    else
    {
      //should be revised so that updates are only sent if something changes
      ret=stim.Send_Update_Parameter(S_Pulse_Width,S_Pulse_Current,S_Mode,nc);
      * mute_period = (real_T) (double) (S_Group_Time * max_mode);
    }
  } // end DoStim
   
}

#undef MDL_UPDATE  /* Change to #undef to remove function */
#if defined(MDL_UPDATE)
/* Function: mdlUpdate ======================================================
 * Abstract:
 *    This function is called once for every major integration time step.
 *    Discrete states are typically updated here, but this function is useful
 *    for performing any tasks that should only take place once per
 *    integration step.
 */
static void mdlUpdate(SimStruct *S, int_T tid)
{
}
#endif /* MDL_UPDATE */

#undef MDL_DERIVATIVES  /* Change to #undef to remove function */
#if defined(MDL_DERIVATIVES)
/* Function: mdlDerivatives =================================================
 * Abstract:
 *    In this function, you compute the S-function block's derivatives.
 *    The derivatives are placed in the derivative vector, ssGetdX(S).
 */
static void mdlDerivatives(SimStruct *S)
{
}
#endif /* MDL_DERIVATIVES */



/* Function: mdlTerminate =====================================================
 * Abstract:
 *    In this function, you should perform any actions that are necessary
 *    at the termination of a simulation.  For example, if memory was
 *    allocated in mdlStart, this is the place to free it.
 */
static void mdlTerminate(SimStruct *S)

{ int ret;
  int error;
  //  char Write_Buffer[40];
  /*
    sched_setscheduler( 0, orig_scheduling_policy, &orig_scheduler );
    sched_getparam(0,&mysched);
    printf("priority reset to %i\n",mysched.sched_priority);
  */
  if (DoStim) {
    if (ssGetSimMode(S) == SS_SIMMODE_NORMAL) 
    {
      error=stim.Send_Stop_Signal();

      ssPrintf("Updates: %d, Successful Updates %d, Unsuccessful Updates %d, Missing Responses %d \n",
	  stim.sent_updates,stim.successful_updates,stim.unsuccessful_updates,stim.sent_updates-
	  stim.successful_updates-stim.unsuccessful_updates);

      ssPrintf("Closing serial port...");

      error=stim.Close_serial();  
      if (error == 0) 
      {
	ssPrintf("done.\n");
      }
      else 
      {
	ssPrintf("failed.\n");
      }
    }
  } // end DoStim
}


/*======================================================*
 * See sfuntmpl_doc.c for the optional S-function methods *
 *======================================================*/

/*=============================*
 * Required S-function trailer *
 *=============================*/

#ifdef  MATLAB_MEX_FILE    /* Is this file being compiled as a MEX-file? */
#include "simulink.c"      /* MEX-file interface mechanism */
#else
#include "cg_sfun.h"       /* Code generation registration function */
#endif

#ifdef __cplusplus
} //end of extern C scope
#endif
