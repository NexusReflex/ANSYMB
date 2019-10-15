/*
 * Final_Project_private.h
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

#ifndef RTW_HEADER_Final_Project_private_h_
#define RTW_HEADER_Final_Project_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"

extern real_T rt_roundd_snf(real_T u);
extern void sfc_clm(SimStruct *rts);
extern void sf_rtsync(SimStruct *rts);

/* private model entry point functions */
extern void Final_Project_derivatives(void);

#endif                                 /* RTW_HEADER_Final_Project_private_h_ */
