/*
 * Final_Project.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Final_Project".
 *
 * Model version              : 1.114
 * Simulink Coder version : 8.11 (R2016b) 25-Aug-2016
 * C source code generated on : Wed Feb 15 16:02:52 2017
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Final_Project.h"
#include "Final_Project_private.h"
#include "Final_Project_dt.h"

/* options for Simulink Desktop Real-Time board 0 */
static double SLDRTBoardOptions0[] = {
  3.232235954E+9,
  8888.0,
};

/* list of Simulink Desktop Real-Time timers */
const int SLDRTTimerCount = 1;
const double SLDRTTimers[2] = {
  0.01, 0.0,
};

/* list of Simulink Desktop Real-Time boards */
const int SLDRTBoardCount = 1;
SLDRTBOARD SLDRTBoards[1] = {
  { "Standard_Devices/UDP_Protocol", 4012U, 2, SLDRTBoardOptions0 },
};

/* Block signals (auto storage) */
B_Final_Project_T Final_Project_B;

/* Continuous states */
X_Final_Project_T Final_Project_X;

/* Block states (auto storage) */
DW_Final_Project_T Final_Project_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_Final_Project_T Final_Project_PrevZCX;

/* Real-time model */
RT_MODEL_Final_Project_T Final_Project_M_;
RT_MODEL_Final_Project_T *const Final_Project_M = &Final_Project_M_;

/*
 * This function updates continuous states using the ODE1 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE1_IntgData *id = (ODE1_IntgData *)rtsiGetSolverData(si);
  real_T *f0 = id->f[0];
  int_T i;
  int_T nXc = 2;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  Final_Project_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; ++i) {
    x[i] += h * f0[i];
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

/* Model output function */
void Final_Project_output(void)
{
  boolean_T zcEvent;
  ZCEventType zcEvent_0;
  int32_T i;
  real_T u0;
  real_T u1;
  real_T u2;
  if (rtmIsMajorTimeStep(Final_Project_M)) {
    /* set solver stop time */
    if (!(Final_Project_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&Final_Project_M->solverInfo,
                            ((Final_Project_M->Timing.clockTickH0 + 1) *
        Final_Project_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&Final_Project_M->solverInfo,
                            ((Final_Project_M->Timing.clockTick0 + 1) *
        Final_Project_M->Timing.stepSize0 + Final_Project_M->Timing.clockTickH0 *
        Final_Project_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(Final_Project_M)) {
    Final_Project_M->Timing.t[0] = rtsiGetT(&Final_Project_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(Final_Project_M)) {
    /* S-Function Block: <Root>/Packet Output */
    Final_Project_B.PacketOutput = 0;  /* Missed Ticks value is always zero */

    /* no code required */

    /* S-Function Block: <Root>/Packet Input */
    {
      uint8_T indata[12U];
      int status = RTBIO_DriverIO(0, STREAMINPUT, IOREAD, 12U,
        &Final_Project_P.PacketInput_PacketID, (double*) indata, NULL);
      Final_Project_B.PacketInput_o2 = 0;/* Missed Ticks value is always zero */
      if (status & 0x1) {
        RTWin_ANYTYPEPTR indp;
        indp.p_uint8_T = indata;

        {
          int_T i1;
          int16_T *y0 = &Final_Project_B.PacketInput_o1[0];
          for (i1=0; i1 < 6; i1++) {
            {
              /* int16_T, big endian */
              uint8_T* blkoutptr = ((uint8_T *) &y0[i1]) + 2;
              *--blkoutptr = *indp.p_uint8_T++;
              *--blkoutptr = *indp.p_uint8_T++;
            }
          }
        }
      }
    }

    for (i = 0; i < 6; i++) {
      /* DataTypeConversion: '<Root>/Data Type Conversion2' */
      Final_Project_B.DataTypeConversion2[i] = Final_Project_B.PacketInput_o1[i];

      /* Product: '<Root>/Divide' incorporates:
       *  Constant: '<Root>/Constant1'
       */
      Final_Project_B.Divide[i] = Final_Project_B.DataTypeConversion2[i] /
        Final_Project_P.Constant1_Value;
    }

    Final_Project_B.Sum2 = Final_Project_B.Divide[1] -
      Final_Project_P.Umrechnung_Value;

    /* Abs: '<Root>/Abs' */
    Final_Project_B.Abs = fabs(Final_Project_B.Sum2);

    /* Gain: '<Root>/Angle' */
    Final_Project_B.Angle = Final_Project_P.Angle_Gain * Final_Project_B.Abs;
  }

  /* TransferFcn: '<Root>/Filter' */
  Final_Project_B.ArmAngle = 0.0;
  Final_Project_B.ArmAngle += Final_Project_P.Filter_C *
    Final_Project_X.Filter_CSTATE;

  /* Sum: '<Root>/Sum' incorporates:
   *  Constant: '<Root>/Sollwert '
   */
  Final_Project_B.Sum = Final_Project_P.Sollwert_Value -
    Final_Project_B.ArmAngle;

  /* Integrator: '<Root>/Integrator' incorporates:
   *  Constant: '<Root>/ControlActive'
   */
  if (rtmIsMajorTimeStep(Final_Project_M)) {
    zcEvent_0 = rt_ZCFcn(ANY_ZERO_CROSSING,
                         &Final_Project_PrevZCX.Integrator_Reset_ZCE,
                         (Final_Project_P.ControlActive_Value));
    zcEvent = (zcEvent_0 != NO_ZCEVENT);

    /* evaluate zero-crossings */
    if (zcEvent) {
      Final_Project_X.Integrator_CSTATE = Final_Project_P.Integrator_IC;
    }
  }

  Final_Project_B.Integrator = Final_Project_X.Integrator_CSTATE;

  /* End of Integrator: '<Root>/Integrator' */

  /* Switch: '<Root>/Control Switch' incorporates:
   *  Constant: '<Root>/ControlActive'
   *  Constant: '<Root>/Off'
   */
  if (Final_Project_P.ControlActive_Value >
      Final_Project_P.ControlSwitch_Threshold) {
    /* Fcn: '<Root>/Vorsteuerung' */
    Final_Project_B.Vorsteuerung = sin(Final_Project_B.ArmAngle *
      3.1415926535897931 / 180.0) * 0.162 * 1.5 * 9.81 / 0.015;

    /* Gain: '<Root>/P' */
    Final_Project_B.P = Final_Project_P.P_Gain * Final_Project_B.Sum;

    /* Sum: '<Root>/Sum1' */
    Final_Project_B.Sum1 = (Final_Project_B.P + Final_Project_B.Integrator) +
      Final_Project_B.Vorsteuerung;

    /* Gain: '<Root>/curPulse' */
    Final_Project_B.curPulse = Final_Project_P.curPulse_Gain *
      Final_Project_B.Sum1;

    /* Quantizer: '<Root>/Quantizer' */
    u0 = Final_Project_B.curPulse;
    Final_Project_B.Quantizer = rt_roundd_snf(u0 /
      Final_Project_P.Quantizer_Interval) * Final_Project_P.Quantizer_Interval;

    /* Saturate: '<Root>/Saturation' */
    u0 = Final_Project_B.Quantizer;
    u1 = Final_Project_P.Saturation_LowerSat;
    u2 = Final_Project_P.Saturation_UpperSat;
    if (u0 > u2) {
      Final_Project_B.Saturation = u2;
    } else if (u0 < u1) {
      Final_Project_B.Saturation = u1;
    } else {
      Final_Project_B.Saturation = u0;
    }

    /* End of Saturate: '<Root>/Saturation' */
    Final_Project_B.ControlSwitch = Final_Project_B.Saturation;
  } else {
    Final_Project_B.ControlSwitch = Final_Project_P.Off_Value;
  }

  /* End of Switch: '<Root>/Control Switch' */

  /* Gain: '<Root>/I' */
  Final_Project_B.I = Final_Project_P.I_Gain * Final_Project_B.Sum;
  if (rtmIsMajorTimeStep(Final_Project_M)) {
    /* Constant: '<Root>/Current' */
    Final_Project_B.Current = Final_Project_P.Current_Value;

    /* Constant: '<Root>/stim mode' */
    Final_Project_B.stimmode = Final_Project_P.stimmode_Value;

    /* Level2 S-Function Block: '<S1>/S-Function' (sfc_clm) */
    {
      SimStruct *rts = Final_Project_M->childSfunctions[0];
      sfcnOutputs(rts, 1);
    }

    /* DataTypeConversion: '<Root>/Data Type Conversion' incorporates:
     *  Constant: '<Root>/Constant'
     */
    u0 = floor(Final_Project_P.Constant_Value);
    if (rtIsNaN(u0) || rtIsInf(u0)) {
      u0 = 0.0;
    } else {
      u0 = fmod(u0, 256.0);
    }

    Final_Project_B.DataTypeConversion = (uint8_T)(u0 < 0.0 ? (int32_T)(uint8_T)
      -(int8_T)(uint8_T)-u0 : (int32_T)(uint8_T)u0);

    /* End of DataTypeConversion: '<Root>/Data Type Conversion' */

    /* Level2 S-Function Block: '<S2>/S-Function' (sf_rtsync) */
    {
      SimStruct *rts = Final_Project_M->childSfunctions[1];
      sfcnOutputs(rts, 1);
    }
  }
}

/* Model update function */
void Final_Project_update(void)
{
  if (rtmIsMajorTimeStep(Final_Project_M)) {
    /* S-Function Block: <Root>/Packet Output */
    {
      uint8_T outdata[1U];
      RTWin_ANYTYPEPTR outdp;
      outdp.p_uint8_T = outdata;

      {
        uint8_T pktin = Final_Project_B.DataTypeConversion;
        int8_T pktout = pktin>=MAX_int8_T ? MAX_int8_T : (int8_T) pktin;
        *outdp.p_int8_T++ = pktout;
      }

      RTBIO_DriverIO(0, STREAMOUTPUT, IOWRITE, 1U,
                     &Final_Project_P.PacketOutput_PacketID, (double*) outdata,
                     NULL);
    }
  }

  if (rtmIsMajorTimeStep(Final_Project_M)) {
    rt_ertODEUpdateContinuousStates(&Final_Project_M->solverInfo);
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++Final_Project_M->Timing.clockTick0)) {
    ++Final_Project_M->Timing.clockTickH0;
  }

  Final_Project_M->Timing.t[0] = rtsiGetSolverStopTime
    (&Final_Project_M->solverInfo);

  {
    /* Update absolute timer for sample time: [0.01s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++Final_Project_M->Timing.clockTick1)) {
      ++Final_Project_M->Timing.clockTickH1;
    }

    Final_Project_M->Timing.t[1] = Final_Project_M->Timing.clockTick1 *
      Final_Project_M->Timing.stepSize1 + Final_Project_M->Timing.clockTickH1 *
      Final_Project_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void Final_Project_derivatives(void)
{
  XDot_Final_Project_T *_rtXdot;
  _rtXdot = ((XDot_Final_Project_T *) Final_Project_M->derivs);

  /* Derivatives for TransferFcn: '<Root>/Filter' */
  _rtXdot->Filter_CSTATE = 0.0;
  _rtXdot->Filter_CSTATE += Final_Project_P.Filter_A *
    Final_Project_X.Filter_CSTATE;
  _rtXdot->Filter_CSTATE += Final_Project_B.Angle;

  /* Derivatives for Integrator: '<Root>/Integrator' */
  _rtXdot->Integrator_CSTATE = Final_Project_B.I;
}

/* Model initialize function */
void Final_Project_initialize(void)
{
  /* S-Function Block: <Root>/Packet Output */
  /* no initial value should be set */

  /* Start for Constant: '<Root>/Current' */
  Final_Project_B.Current = Final_Project_P.Current_Value;

  /* Start for Constant: '<Root>/stim mode' */
  Final_Project_B.stimmode = Final_Project_P.stimmode_Value;

  /* Level2 S-Function Block: '<S1>/S-Function' (sfc_clm) */
  {
    SimStruct *rts = Final_Project_M->childSfunctions[0];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S2>/S-Function' (sf_rtsync) */
  {
    SimStruct *rts = Final_Project_M->childSfunctions[1];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  Final_Project_PrevZCX.Integrator_Reset_ZCE = UNINITIALIZED_ZCSIG;

  /* InitializeConditions for TransferFcn: '<Root>/Filter' */
  Final_Project_X.Filter_CSTATE = 0.0;

  /* InitializeConditions for Integrator: '<Root>/Integrator' */
  Final_Project_X.Integrator_CSTATE = Final_Project_P.Integrator_IC;
}

/* Model terminate function */
void Final_Project_terminate(void)
{
  /* S-Function Block: <Root>/Packet Output */
  /* no initial value should be set */

  /* Level2 S-Function Block: '<S1>/S-Function' (sfc_clm) */
  {
    SimStruct *rts = Final_Project_M->childSfunctions[0];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S2>/S-Function' (sf_rtsync) */
  {
    SimStruct *rts = Final_Project_M->childSfunctions[1];
    sfcnTerminate(rts);
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/

/* Solver interface called by GRT_Main */
#ifndef USE_GENERATED_SOLVER

void rt_ODECreateIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEDestroyIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEUpdateContinuousStates(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

#endif

void MdlOutputs(int_T tid)
{
  Final_Project_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  Final_Project_update();
  UNUSED_PARAMETER(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  Final_Project_initialize();
}

void MdlTerminate(void)
{
  Final_Project_terminate();
}

/* Registration function */
RT_MODEL_Final_Project_T *Final_Project(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Final_Project_M, 0,
                sizeof(RT_MODEL_Final_Project_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Final_Project_M->solverInfo,
                          &Final_Project_M->Timing.simTimeStep);
    rtsiSetTPtr(&Final_Project_M->solverInfo, &rtmGetTPtr(Final_Project_M));
    rtsiSetStepSizePtr(&Final_Project_M->solverInfo,
                       &Final_Project_M->Timing.stepSize0);
    rtsiSetdXPtr(&Final_Project_M->solverInfo, &Final_Project_M->derivs);
    rtsiSetContStatesPtr(&Final_Project_M->solverInfo, (real_T **)
                         &Final_Project_M->contStates);
    rtsiSetNumContStatesPtr(&Final_Project_M->solverInfo,
      &Final_Project_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&Final_Project_M->solverInfo,
      &Final_Project_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&Final_Project_M->solverInfo,
      &Final_Project_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&Final_Project_M->solverInfo,
      &Final_Project_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&Final_Project_M->solverInfo, (&rtmGetErrorStatus
      (Final_Project_M)));
    rtsiSetRTModelPtr(&Final_Project_M->solverInfo, Final_Project_M);
  }

  rtsiSetSimTimeStep(&Final_Project_M->solverInfo, MAJOR_TIME_STEP);
  Final_Project_M->intgData.f[0] = Final_Project_M->odeF[0];
  Final_Project_M->contStates = ((real_T *) &Final_Project_X);
  rtsiSetSolverData(&Final_Project_M->solverInfo, (void *)
                    &Final_Project_M->intgData);
  rtsiSetSolverName(&Final_Project_M->solverInfo,"ode1");
  Final_Project_M->solverInfoPtr = (&Final_Project_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = Final_Project_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    Final_Project_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    Final_Project_M->Timing.sampleTimes =
      (&Final_Project_M->Timing.sampleTimesArray[0]);
    Final_Project_M->Timing.offsetTimes =
      (&Final_Project_M->Timing.offsetTimesArray[0]);

    /* task periods */
    Final_Project_M->Timing.sampleTimes[0] = (0.0);
    Final_Project_M->Timing.sampleTimes[1] = (0.01);

    /* task offsets */
    Final_Project_M->Timing.offsetTimes[0] = (0.0);
    Final_Project_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(Final_Project_M, &Final_Project_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = Final_Project_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    Final_Project_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(Final_Project_M, 20.0);
  Final_Project_M->Timing.stepSize0 = 0.01;
  Final_Project_M->Timing.stepSize1 = 0.01;

  /* External mode info */
  Final_Project_M->Sizes.checksums[0] = (4061985548U);
  Final_Project_M->Sizes.checksums[1] = (2770466373U);
  Final_Project_M->Sizes.checksums[2] = (1634856377U);
  Final_Project_M->Sizes.checksums[3] = (302652773U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[2];
    Final_Project_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Final_Project_M->extModeInfo,
      &Final_Project_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Final_Project_M->extModeInfo,
                        Final_Project_M->Sizes.checksums);
    rteiSetTPtr(Final_Project_M->extModeInfo, rtmGetTPtr(Final_Project_M));
  }

  Final_Project_M->solverInfoPtr = (&Final_Project_M->solverInfo);
  Final_Project_M->Timing.stepSize = (0.01);
  rtsiSetFixedStepSize(&Final_Project_M->solverInfo, 0.01);
  rtsiSetSolverMode(&Final_Project_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  Final_Project_M->blockIO = ((void *) &Final_Project_B);
  (void) memset(((void *) &Final_Project_B), 0,
                sizeof(B_Final_Project_T));

  /* parameters */
  Final_Project_M->defaultParam = ((real_T *)&Final_Project_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &Final_Project_X;
    Final_Project_M->contStates = (x);
    (void) memset((void *)&Final_Project_X, 0,
                  sizeof(X_Final_Project_T));
  }

  /* states (dwork) */
  Final_Project_M->dwork = ((void *) &Final_Project_DW);
  (void) memset((void *)&Final_Project_DW, 0,
                sizeof(DW_Final_Project_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    Final_Project_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* child S-Function registration */
  {
    RTWSfcnInfo *sfcnInfo = &Final_Project_M->NonInlinedSFcns.sfcnInfo;
    Final_Project_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus(Final_Project_M)));
    rtssSetNumRootSampTimesPtr(sfcnInfo, &Final_Project_M->Sizes.numSampTimes);
    Final_Project_M->NonInlinedSFcns.taskTimePtrs[0] = &(rtmGetTPtr
      (Final_Project_M)[0]);
    Final_Project_M->NonInlinedSFcns.taskTimePtrs[1] = &(rtmGetTPtr
      (Final_Project_M)[1]);
    rtssSetTPtrPtr(sfcnInfo,Final_Project_M->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(Final_Project_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(Final_Project_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput(Final_Project_M));
    rtssSetStepSizePtr(sfcnInfo, &Final_Project_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested(Final_Project_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &Final_Project_M->derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo, &Final_Project_M->zCCacheNeedsReset);
    rtssSetBlkStateChangePtr(sfcnInfo, &Final_Project_M->blkStateChange);
    rtssSetSampleHitsPtr(sfcnInfo, &Final_Project_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo,
      &Final_Project_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &Final_Project_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &Final_Project_M->solverInfoPtr);
  }

  Final_Project_M->Sizes.numSFcns = (2);

  /* register each child */
  {
    (void) memset((void *)&Final_Project_M->NonInlinedSFcns.childSFunctions[0],
                  0,
                  2*sizeof(SimStruct));
    Final_Project_M->childSfunctions =
      (&Final_Project_M->NonInlinedSFcns.childSFunctionPtrs[0]);
    Final_Project_M->childSfunctions[0] =
      (&Final_Project_M->NonInlinedSFcns.childSFunctions[0]);
    Final_Project_M->childSfunctions[1] =
      (&Final_Project_M->NonInlinedSFcns.childSFunctions[1]);

    /* Level2 S-Function Block: Final_Project/<S1>/S-Function (sfc_clm) */
    {
      SimStruct *rts = Final_Project_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod = Final_Project_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset = Final_Project_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap = Final_Project_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Final_Project_M->NonInlinedSFcns.blkInfo2[0]);
      }

      ssSetRTWSfcnInfo(rts, Final_Project_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Final_Project_M->NonInlinedSFcns.methods2[0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Final_Project_M->NonInlinedSFcns.methods3[0]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &Final_Project_M->NonInlinedSFcns.methods4[0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Final_Project_M->NonInlinedSFcns.statesInfo2[0]);
        ssSetPeriodicStatesInfo(rts,
          &Final_Project_M->NonInlinedSFcns.periodicStatesInfo[0]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 3);
        ssSetPortInfoForInputs(rts,
          &Final_Project_M->NonInlinedSFcns.Sfcn0.inputPortInfo[0]);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, &Final_Project_B.Current);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }

        /* port 1 */
        {
          ssSetInputPortRequiredContiguous(rts, 1, 1);
          ssSetInputPortSignal(rts, 1, &Final_Project_B.ControlSwitch);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 1);
        }

        /* port 2 */
        {
          ssSetInputPortRequiredContiguous(rts, 2, 1);
          ssSetInputPortSignal(rts, 2, &Final_Project_B.stimmode);
          _ssSetInputPortNumDimensions(rts, 2, 1);
          ssSetInputPortWidth(rts, 2, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Final_Project_M->NonInlinedSFcns.Sfcn0.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &Final_Project_B.SFunction));
        }
      }

      /* path info */
      ssSetModelName(rts, "S-Function");
      ssSetPath(rts, "Final_Project/Stimulator Interface/S-Function");
      ssSetRTModel(rts,Final_Project_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Final_Project_M->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 8);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Final_Project_P.SFunction_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Final_Project_P.SFunction_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)Final_Project_P.SFunction_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)Final_Project_P.SFunction_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)Final_Project_P.SFunction_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)Final_Project_P.SFunction_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)Final_Project_P.SFunction_P7_Size);
        ssSetSFcnParam(rts, 7, (mxArray*)Final_Project_P.SFunction_P8_Size);
      }

      /* registration */
      sfc_clm(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetInputPortWidth(rts, 0, 1);
      ssSetInputPortDataType(rts, 0, SS_DOUBLE);
      ssSetInputPortComplexSignal(rts, 0, 0);
      ssSetInputPortFrameData(rts, 0, 0);
      ssSetInputPortWidth(rts, 1, 1);
      ssSetInputPortDataType(rts, 1, SS_DOUBLE);
      ssSetInputPortComplexSignal(rts, 1, 0);
      ssSetInputPortFrameData(rts, 1, 0);
      ssSetInputPortWidth(rts, 2, 1);
      ssSetInputPortDataType(rts, 2, SS_DOUBLE);
      ssSetInputPortComplexSignal(rts, 2, 0);
      ssSetInputPortFrameData(rts, 2, 0);
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetInputPortConnected(rts, 1, 1);
      _ssSetInputPortConnected(rts, 2, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
      ssSetInputPortBufferDstPort(rts, 1, -1);
      ssSetInputPortBufferDstPort(rts, 2, -1);
    }

    /* Level2 S-Function Block: Final_Project/<S2>/S-Function (sf_rtsync) */
    {
      SimStruct *rts = Final_Project_M->childSfunctions[1];

      /* timing info */
      time_T *sfcnPeriod = Final_Project_M->NonInlinedSFcns.Sfcn1.sfcnPeriod;
      time_T *sfcnOffset = Final_Project_M->NonInlinedSFcns.Sfcn1.sfcnOffset;
      int_T *sfcnTsMap = Final_Project_M->NonInlinedSFcns.Sfcn1.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Final_Project_M->NonInlinedSFcns.blkInfo2[1]);
      }

      ssSetRTWSfcnInfo(rts, Final_Project_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Final_Project_M->NonInlinedSFcns.methods2[1]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Final_Project_M->NonInlinedSFcns.methods3[1]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &Final_Project_M->NonInlinedSFcns.methods4[1]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Final_Project_M->NonInlinedSFcns.statesInfo2[1]);
        ssSetPeriodicStatesInfo(rts,
          &Final_Project_M->NonInlinedSFcns.periodicStatesInfo[1]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Final_Project_M->NonInlinedSFcns.Sfcn1.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &Final_Project_B.SFunction_e));
        }
      }

      /* path info */
      ssSetModelName(rts, "S-Function");
      ssSetPath(rts, "Final_Project/rt_sync/S-Function");
      ssSetRTModel(rts,Final_Project_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Final_Project_M->NonInlinedSFcns.Sfcn1.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Final_Project_P.SFunction_P1_Size_i);
        ssSetSFcnParam(rts, 1, (mxArray*)Final_Project_P.SFunction_P2_Size_m);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *) &Final_Project_DW.SFunction_RWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &Final_Project_M->NonInlinedSFcns.Sfcn1.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &Final_Project_M->NonInlinedSFcns.Sfcn1.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* RWORK */
        ssSetDWorkWidth(rts, 0, 3);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &Final_Project_DW.SFunction_RWORK[0]);
      }

      /* registration */
      sf_rtsync(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }
  }

  /* Initialize Sizes */
  Final_Project_M->Sizes.numContStates = (2);/* Number of continuous states */
  Final_Project_M->Sizes.numPeriodicContStates = (0);/* Number of periodic continuous states */
  Final_Project_M->Sizes.numY = (0);   /* Number of model outputs */
  Final_Project_M->Sizes.numU = (0);   /* Number of model inputs */
  Final_Project_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  Final_Project_M->Sizes.numSampTimes = (2);/* Number of sample times */
  Final_Project_M->Sizes.numBlocks = (30);/* Number of blocks */
  Final_Project_M->Sizes.numBlockIO = (24);/* Number of block outputs */
  Final_Project_M->Sizes.numBlockPrms = (53);/* Sum of parameter "widths" */
  return Final_Project_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
