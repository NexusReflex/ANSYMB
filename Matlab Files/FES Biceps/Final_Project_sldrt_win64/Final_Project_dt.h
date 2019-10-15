/*
 * Final_Project_dt.h
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

#include "ext_types.h"

/* data type size table */
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T)
};

/* data type name table */
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&Final_Project_B.DataTypeConversion2[0]), 0, 0, 30 },

  { (char_T *)(&Final_Project_B.PacketOutput), 6, 0, 2 },

  { (char_T *)(&Final_Project_B.PacketInput_o1[0]), 4, 0, 6 },

  { (char_T *)(&Final_Project_B.DataTypeConversion), 3, 0, 1 }
  ,

  { (char_T *)(&Final_Project_DW.SFunction_RWORK[0]), 0, 0, 3 },

  { (char_T *)(&Final_Project_DW.PacketOutput_PWORK[0]), 11, 0, 3 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  6U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&Final_Project_P.PacketOutput_MaxMissedTicks), 0, 0, 4 },

  { (char_T *)(&Final_Project_P.PacketOutput_PacketID), 6, 0, 2 },

  { (char_T *)(&Final_Project_P.P_Gain), 0, 0, 47 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  3U,
  rtPTransitions
};

/* [EOF] Final_Project_dt.h */
