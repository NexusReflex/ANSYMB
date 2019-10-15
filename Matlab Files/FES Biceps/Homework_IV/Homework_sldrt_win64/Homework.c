/*
 * Homework.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Homework".
 *
 * Model version              : 1.35
 * Simulink Coder version : 8.11 (R2016b) 25-Aug-2016
 * C source code generated on : Tue Jan 31 15:29:06 2017
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Homework.h"
#include "Homework_private.h"
#include "Homework_dt.h"

/* options for Simulink Desktop Real-Time board 0 */
static double SLDRTBoardOptions0[] = {
  3.232235954E+9,
  8888.0,
};

/* list of Simulink Desktop Real-Time timers */
const int SLDRTTimerCount = 1;
const double SLDRTTimers[2] = {
  0.1, 0.0,
};

/* list of Simulink Desktop Real-Time boards */
const int SLDRTBoardCount = 1;
SLDRTBOARD SLDRTBoards[1] = {
  { "Standard_Devices/UDP_Protocol", 4012U, 2, SLDRTBoardOptions0 },
};

/* Block signals (auto storage) */
B_Homework_T Homework_B;

/* Block states (auto storage) */
DW_Homework_T Homework_DW;

/* Real-time model */
RT_MODEL_Homework_T Homework_M_;
RT_MODEL_Homework_T *const Homework_M = &Homework_M_;

/* Model output function */
void Homework_output(void)
{
  real_T tmp;

  /* S-Function Block: <Root>/Packet Output */

  /* no code required */

  /* DataTypeConversion: '<Root>/Data Type Conversion' incorporates:
   *  Constant: '<Root>/Constant'
   */
  tmp = floor(Homework_P.Constant_Value);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 256.0);
  }

  Homework_B.DataTypeConversion = (uint8_T)(tmp < 0.0 ? (int32_T)(uint8_T)
    -(int8_T)(uint8_T)-tmp : (int32_T)(uint8_T)tmp);

  /* End of DataTypeConversion: '<Root>/Data Type Conversion' */
  /* S-Function Block: <Root>/Packet Input */
  {
    uint8_T indata[6U];
    int status = RTBIO_DriverIO(0, STREAMINPUT, IOREAD, 6U,
      &Homework_P.PacketInput_PacketID, (double*) indata, NULL);
    if (status & 0x1) {
      RTWin_ANYTYPEPTR indp;
      indp.p_uint8_T = indata;

      {
        /* int16_T, big endian */
        uint8_T* blkoutptr = ((uint8_T *) &Homework_B.PacketInput[0]) + 2;
        *--blkoutptr = *indp.p_uint8_T++;
        *--blkoutptr = *indp.p_uint8_T++;
      }

      {
        /* int16_T, big endian */
        uint8_T* blkoutptr = ((uint8_T *) &Homework_B.PacketInput[1]) + 2;
        *--blkoutptr = *indp.p_uint8_T++;
        *--blkoutptr = *indp.p_uint8_T++;
      }

      {
        /* int16_T, big endian */
        uint8_T* blkoutptr = ((uint8_T *) &Homework_B.PacketInput[2]) + 2;
        *--blkoutptr = *indp.p_uint8_T++;
        *--blkoutptr = *indp.p_uint8_T++;
      }
    }
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion2' */
  Homework_B.DataTypeConversion2[0] = Homework_B.PacketInput[0];

  /* Product: '<Root>/Divide' incorporates:
   *  Constant: '<Root>/Constant1'
   */
  Homework_B.Divide[0] = Homework_B.DataTypeConversion2[0] /
    Homework_P.Constant1_Value;

  /* DataTypeConversion: '<Root>/Data Type Conversion2' */
  Homework_B.DataTypeConversion2[1] = Homework_B.PacketInput[1];

  /* Product: '<Root>/Divide' incorporates:
   *  Constant: '<Root>/Constant1'
   */
  Homework_B.Divide[1] = Homework_B.DataTypeConversion2[1] /
    Homework_P.Constant1_Value;

  /* DataTypeConversion: '<Root>/Data Type Conversion2' */
  Homework_B.DataTypeConversion2[2] = Homework_B.PacketInput[2];

  /* Product: '<Root>/Divide' incorporates:
   *  Constant: '<Root>/Constant1'
   */
  Homework_B.Divide[2] = Homework_B.DataTypeConversion2[2] /
    Homework_P.Constant1_Value;
}

/* Model update function */
void Homework_update(void)
{
  /* S-Function Block: <Root>/Packet Output */
  {
    uint8_T outdata[1U];
    RTWin_ANYTYPEPTR outdp;
    outdp.p_uint8_T = outdata;

    {
      uint8_T pktin = Homework_B.DataTypeConversion;
      int8_T pktout = pktin>=MAX_int8_T ? MAX_int8_T : (int8_T) pktin;
      *outdp.p_int8_T++ = pktout;
    }

    RTBIO_DriverIO(0, STREAMOUTPUT, IOWRITE, 1U,
                   &Homework_P.PacketOutput_PacketID, (double*) outdata, NULL);
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
  if (!(++Homework_M->Timing.clockTick0)) {
    ++Homework_M->Timing.clockTickH0;
  }

  Homework_M->Timing.t[0] = Homework_M->Timing.clockTick0 *
    Homework_M->Timing.stepSize0 + Homework_M->Timing.clockTickH0 *
    Homework_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void Homework_initialize(void)
{
  /* S-Function Block: <Root>/Packet Output */
  /* no initial value should be set */
}

/* Model terminate function */
void Homework_terminate(void)
{
  /* S-Function Block: <Root>/Packet Output */
  /* no initial value should be set */
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  Homework_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  Homework_update();
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
  Homework_initialize();
}

void MdlTerminate(void)
{
  Homework_terminate();
}

/* Registration function */
RT_MODEL_Homework_T *Homework(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Homework_M, 0,
                sizeof(RT_MODEL_Homework_T));

  /* Initialize timing info */
  {
    int_T *mdlTsMap = Homework_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    Homework_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    Homework_M->Timing.sampleTimes = (&Homework_M->Timing.sampleTimesArray[0]);
    Homework_M->Timing.offsetTimes = (&Homework_M->Timing.offsetTimesArray[0]);

    /* task periods */
    Homework_M->Timing.sampleTimes[0] = (0.1);

    /* task offsets */
    Homework_M->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(Homework_M, &Homework_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = Homework_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    Homework_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(Homework_M, 15.0);
  Homework_M->Timing.stepSize0 = 0.1;

  /* External mode info */
  Homework_M->Sizes.checksums[0] = (2934200932U);
  Homework_M->Sizes.checksums[1] = (1698662035U);
  Homework_M->Sizes.checksums[2] = (1049928774U);
  Homework_M->Sizes.checksums[3] = (1107913123U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    Homework_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Homework_M->extModeInfo,
      &Homework_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Homework_M->extModeInfo, Homework_M->Sizes.checksums);
    rteiSetTPtr(Homework_M->extModeInfo, rtmGetTPtr(Homework_M));
  }

  Homework_M->solverInfoPtr = (&Homework_M->solverInfo);
  Homework_M->Timing.stepSize = (0.1);
  rtsiSetFixedStepSize(&Homework_M->solverInfo, 0.1);
  rtsiSetSolverMode(&Homework_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  Homework_M->blockIO = ((void *) &Homework_B);
  (void) memset(((void *) &Homework_B), 0,
                sizeof(B_Homework_T));

  /* parameters */
  Homework_M->defaultParam = ((real_T *)&Homework_P);

  /* states (dwork) */
  Homework_M->dwork = ((void *) &Homework_DW);
  (void) memset((void *)&Homework_DW, 0,
                sizeof(DW_Homework_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    Homework_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  Homework_M->Sizes.numContStates = (0);/* Number of continuous states */
  Homework_M->Sizes.numY = (0);        /* Number of model outputs */
  Homework_M->Sizes.numU = (0);        /* Number of model inputs */
  Homework_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  Homework_M->Sizes.numSampTimes = (1);/* Number of sample times */
  Homework_M->Sizes.numBlocks = (8);   /* Number of blocks */
  Homework_M->Sizes.numBlockIO = (4);  /* Number of block outputs */
  Homework_M->Sizes.numBlockPrms = (8);/* Sum of parameter "widths" */
  return Homework_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
