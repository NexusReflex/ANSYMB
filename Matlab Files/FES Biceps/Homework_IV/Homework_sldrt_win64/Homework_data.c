/*
 * Homework_data.c
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

/* Block parameters (auto storage) */
P_Homework_T Homework_P = {
  10.0,                                /* Mask Parameter: PacketOutput_MaxMissedTicks
                                        * Referenced by: '<Root>/Packet Output'
                                        */
  10.0,                                /* Mask Parameter: PacketInput_MaxMissedTicks
                                        * Referenced by: '<Root>/Packet Input'
                                        */
  0.0,                                 /* Mask Parameter: PacketOutput_YieldWhenWaiting
                                        * Referenced by: '<Root>/Packet Output'
                                        */
  0.0,                                 /* Mask Parameter: PacketInput_YieldWhenWaiting
                                        * Referenced by: '<Root>/Packet Input'
                                        */
  1,                                   /* Mask Parameter: PacketOutput_PacketID
                                        * Referenced by: '<Root>/Packet Output'
                                        */
  1,                                   /* Mask Parameter: PacketInput_PacketID
                                        * Referenced by: '<Root>/Packet Input'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Constant'
                                        */
  10.0                                 /* Expression: 10
                                        * Referenced by: '<Root>/Constant1'
                                        */
};
