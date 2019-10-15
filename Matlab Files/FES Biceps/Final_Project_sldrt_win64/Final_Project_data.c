/*
 * Final_Project_data.c
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

/* Block parameters (auto storage) */
P_Final_Project_T Final_Project_P = {
  100000.0,                            /* Mask Parameter: PacketOutput_MaxMissedTicks
                                        * Referenced by: '<Root>/Packet Output'
                                        */
  100000.0,                            /* Mask Parameter: PacketInput_MaxMissedTicks
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
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<Root>/P'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/curPulse'
                                        */
  10.0,                                /* Expression: 10
                                        * Referenced by: '<Root>/Quantizer'
                                        */
  300.0,                               /* Expression: 300
                                        * Referenced by: '<Root>/Saturation'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Saturation'
                                        */
  10.0,                                /* Expression: 10
                                        * Referenced by: '<Root>/Constant1'
                                        */
  90.0,                                /* Expression: 90
                                        * Referenced by: '<Root>/Umrechnung'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Angle'
                                        */
  45.0,                                /* Expression: 45
                                        * Referenced by: '<Root>/Sollwert '
                                        */
  -10.0,                               /* Computed Parameter: Filter_A
                                        * Referenced by: '<Root>/Filter'
                                        */
  10.0,                                /* Computed Parameter: Filter_C
                                        * Referenced by: '<Root>/Filter'
                                        */
  10.0,                                /* Expression: 10
                                        * Referenced by: '<Root>/ControlActive'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Off'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Control Switch'
                                        */
  15.0,                                /* Expression: 15
                                        * Referenced by: '<Root>/Current'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<Root>/I'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/stim mode'
                                        */

  /*  Computed Parameter: SFunction_P1_Size
   * Referenced by: '<S1>/S-Function'
   */
  { 1.0, 1.0 },
  0.01,                                /* Expression: Ts
                                        * Referenced by: '<S1>/S-Function'
                                        */

  /*  Computed Parameter: SFunction_P2_Size
   * Referenced by: '<S1>/S-Function'
   */
  { 1.0, 1.0 },
  3.0,                                 /* Expression: com_port
                                        * Referenced by: '<S1>/S-Function'
                                        */

  /*  Computed Parameter: SFunction_P3_Size
   * Referenced by: '<S1>/S-Function'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: channelstim
                                        * Referenced by: '<S1>/S-Function'
                                        */

  /*  Computed Parameter: SFunction_P4_Size
   * Referenced by: '<S1>/S-Function'
   */
  { 1.0, 1.0 },
  20.0,                                /* Expression: tsone
                                        * Referenced by: '<S1>/S-Function'
                                        */

  /*  Computed Parameter: SFunction_P5_Size
   * Referenced by: '<S1>/S-Function'
   */
  { 1.0, 1.0 },
  4.0,                                 /* Expression: tstwo
                                        * Referenced by: '<S1>/S-Function'
                                        */

  /*  Computed Parameter: SFunction_P6_Size
   * Referenced by: '<S1>/S-Function'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/S-Function'
                                        */

  /*  Computed Parameter: SFunction_P7_Size
   * Referenced by: '<S1>/S-Function'
   */
  { 0.0, 0.0 },

  /*  Computed Parameter: SFunction_P8_Size
   * Referenced by: '<S1>/S-Function'
   */
  { 0.0, 0.0 },
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Constant'
                                        */

  /*  Computed Parameter: SFunction_P1_Size_i
   * Referenced by: '<S2>/S-Function'
   */
  { 1.0, 1.0 },
  0.01,                                /* Expression: Ts
                                        * Referenced by: '<S2>/S-Function'
                                        */

  /*  Computed Parameter: SFunction_P2_Size_m
   * Referenced by: '<S2>/S-Function'
   */
  { 1.0, 1.0 },
  0.0                                  /* Expression: strict
                                        * Referenced by: '<S2>/S-Function'
                                        */
};
