/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Symmetry_Inverter_imagined_sfun.h"
#include "c3_Symmetry_Inverter_imagined.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Symmetry_Inverter_imagined_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c3_debug_family_names[12] = { "A", "V_real", "V_012",
  "nargin", "nargout", "amplitude_R", "amplitude_S", "amplitude_T", "phase_R",
  "phase_S", "phase_T", "REG_norm" };

/* Function Declarations */
static void initialize_c3_Symmetry_Inverter_imagined
  (SFc3_Symmetry_Inverter_imaginedInstanceStruct *chartInstance);
static void initialize_params_c3_Symmetry_Inverter_imagined
  (SFc3_Symmetry_Inverter_imaginedInstanceStruct *chartInstance);
static void enable_c3_Symmetry_Inverter_imagined
  (SFc3_Symmetry_Inverter_imaginedInstanceStruct *chartInstance);
static void disable_c3_Symmetry_Inverter_imagined
  (SFc3_Symmetry_Inverter_imaginedInstanceStruct *chartInstance);
static void c3_update_debugger_state_c3_Symmetry_Inverter_imagined
  (SFc3_Symmetry_Inverter_imaginedInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c3_Symmetry_Inverter_imagined
  (SFc3_Symmetry_Inverter_imaginedInstanceStruct *chartInstance);
static void set_sim_state_c3_Symmetry_Inverter_imagined
  (SFc3_Symmetry_Inverter_imaginedInstanceStruct *chartInstance, const mxArray
   *c3_st);
static void finalize_c3_Symmetry_Inverter_imagined
  (SFc3_Symmetry_Inverter_imaginedInstanceStruct *chartInstance);
static void sf_c3_Symmetry_Inverter_imagined
  (SFc3_Symmetry_Inverter_imaginedInstanceStruct *chartInstance);
static void c3_chartstep_c3_Symmetry_Inverter_imagined
  (SFc3_Symmetry_Inverter_imaginedInstanceStruct *chartInstance);
static void initSimStructsc3_Symmetry_Inverter_imagined
  (SFc3_Symmetry_Inverter_imaginedInstanceStruct *chartInstance);
static void registerMessagesc3_Symmetry_Inverter_imagined
  (SFc3_Symmetry_Inverter_imaginedInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber);
static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData);
static real_T c3_emlrt_marshallIn(SFc3_Symmetry_Inverter_imaginedInstanceStruct *
  chartInstance, const mxArray *c3_REG_norm, const char_T *c3_identifier);
static real_T c3_b_emlrt_marshallIn
  (SFc3_Symmetry_Inverter_imaginedInstanceStruct *chartInstance, const mxArray
   *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static void c3_c_emlrt_marshallIn(SFc3_Symmetry_Inverter_imaginedInstanceStruct *
  chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  creal_T c3_y[3]);
static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static void c3_info_helper(c3_ResolvedFunctionInfo c3_info[23]);
static void c3_eml_scalar_eg(SFc3_Symmetry_Inverter_imaginedInstanceStruct
  *chartInstance);
static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static int32_T c3_d_emlrt_marshallIn
  (SFc3_Symmetry_Inverter_imaginedInstanceStruct *chartInstance, const mxArray
   *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static uint8_T c3_e_emlrt_marshallIn
  (SFc3_Symmetry_Inverter_imaginedInstanceStruct *chartInstance, const mxArray
   *c3_b_is_active_c3_Symmetry_Inverter_imagined, const char_T *c3_identifier);
static uint8_T c3_f_emlrt_marshallIn
  (SFc3_Symmetry_Inverter_imaginedInstanceStruct *chartInstance, const mxArray
   *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void init_dsm_address_info(SFc3_Symmetry_Inverter_imaginedInstanceStruct *
  chartInstance);

/* Function Definitions */
static void initialize_c3_Symmetry_Inverter_imagined
  (SFc3_Symmetry_Inverter_imaginedInstanceStruct *chartInstance)
{
  chartInstance->c3_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c3_is_active_c3_Symmetry_Inverter_imagined = 0U;
}

static void initialize_params_c3_Symmetry_Inverter_imagined
  (SFc3_Symmetry_Inverter_imaginedInstanceStruct *chartInstance)
{
}

static void enable_c3_Symmetry_Inverter_imagined
  (SFc3_Symmetry_Inverter_imaginedInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c3_Symmetry_Inverter_imagined
  (SFc3_Symmetry_Inverter_imaginedInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c3_update_debugger_state_c3_Symmetry_Inverter_imagined
  (SFc3_Symmetry_Inverter_imaginedInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c3_Symmetry_Inverter_imagined
  (SFc3_Symmetry_Inverter_imaginedInstanceStruct *chartInstance)
{
  const mxArray *c3_st;
  const mxArray *c3_y = NULL;
  real_T c3_hoistedGlobal;
  real_T c3_u;
  const mxArray *c3_b_y = NULL;
  uint8_T c3_b_hoistedGlobal;
  uint8_T c3_b_u;
  const mxArray *c3_c_y = NULL;
  real_T *c3_REG_norm;
  c3_REG_norm = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c3_st = NULL;
  c3_st = NULL;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_createcellarray(2), FALSE);
  c3_hoistedGlobal = *c3_REG_norm;
  c3_u = c3_hoistedGlobal;
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c3_y, 0, c3_b_y);
  c3_b_hoistedGlobal = chartInstance->c3_is_active_c3_Symmetry_Inverter_imagined;
  c3_b_u = c3_b_hoistedGlobal;
  c3_c_y = NULL;
  sf_mex_assign(&c3_c_y, sf_mex_create("y", &c3_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c3_y, 1, c3_c_y);
  sf_mex_assign(&c3_st, c3_y, FALSE);
  return c3_st;
}

static void set_sim_state_c3_Symmetry_Inverter_imagined
  (SFc3_Symmetry_Inverter_imaginedInstanceStruct *chartInstance, const mxArray
   *c3_st)
{
  const mxArray *c3_u;
  real_T *c3_REG_norm;
  c3_REG_norm = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c3_doneDoubleBufferReInit = TRUE;
  c3_u = sf_mex_dup(c3_st);
  *c3_REG_norm = c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c3_u, 0)), "REG_norm");
  chartInstance->c3_is_active_c3_Symmetry_Inverter_imagined =
    c3_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 1)),
    "is_active_c3_Symmetry_Inverter_imagined");
  sf_mex_destroy(&c3_u);
  c3_update_debugger_state_c3_Symmetry_Inverter_imagined(chartInstance);
  sf_mex_destroy(&c3_st);
}

static void finalize_c3_Symmetry_Inverter_imagined
  (SFc3_Symmetry_Inverter_imaginedInstanceStruct *chartInstance)
{
}

static void sf_c3_Symmetry_Inverter_imagined
  (SFc3_Symmetry_Inverter_imaginedInstanceStruct *chartInstance)
{
  real_T *c3_amplitude_R;
  real_T *c3_REG_norm;
  real_T *c3_amplitude_S;
  real_T *c3_amplitude_T;
  real_T *c3_phase_R;
  real_T *c3_phase_S;
  real_T *c3_phase_T;
  c3_phase_T = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c3_phase_S = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c3_phase_R = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c3_amplitude_T = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c3_amplitude_S = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c3_REG_norm = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c3_amplitude_R = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 1U, chartInstance->c3_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c3_amplitude_R, 0U);
  _SFD_DATA_RANGE_CHECK(*c3_REG_norm, 1U);
  _SFD_DATA_RANGE_CHECK(*c3_amplitude_S, 2U);
  _SFD_DATA_RANGE_CHECK(*c3_amplitude_T, 3U);
  _SFD_DATA_RANGE_CHECK(*c3_phase_R, 4U);
  _SFD_DATA_RANGE_CHECK(*c3_phase_S, 5U);
  _SFD_DATA_RANGE_CHECK(*c3_phase_T, 6U);
  chartInstance->c3_sfEvent = CALL_EVENT;
  c3_chartstep_c3_Symmetry_Inverter_imagined(chartInstance);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_Symmetry_Inverter_imaginedMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c3_chartstep_c3_Symmetry_Inverter_imagined
  (SFc3_Symmetry_Inverter_imaginedInstanceStruct *chartInstance)
{
  real_T c3_hoistedGlobal;
  real_T c3_b_hoistedGlobal;
  real_T c3_c_hoistedGlobal;
  real_T c3_d_hoistedGlobal;
  real_T c3_e_hoistedGlobal;
  real_T c3_f_hoistedGlobal;
  real_T c3_amplitude_R;
  real_T c3_amplitude_S;
  real_T c3_amplitude_T;
  real_T c3_phase_R;
  real_T c3_phase_S;
  real_T c3_phase_T;
  uint32_T c3_debug_family_var_map[12];
  creal_T c3_A[9];
  creal_T c3_V_real[3];
  creal_T c3_V_012[3];
  real_T c3_nargin = 6.0;
  real_T c3_nargout = 1.0;
  real_T c3_REG_norm;
  int32_T c3_i0;
  static creal_T c3_a[9] = { { 0.33333333333333331, 0.0 }, { 0.33333333333333331,
      0.0 }, { 0.33333333333333331, 0.0 }, { 0.33333333333333331, 0.0 }, { -
      0.16666666666666657, 0.28867513459481287 }, { -0.1666666666666668,
      -0.28867513459481281 }, { 0.33333333333333331, 0.0 }, { -
      0.1666666666666668, -0.28867513459481281 }, { -0.16666666666666657,
      0.28867513459481287 } };

  int32_T c3_i1;
  int32_T c3_i2;
  real_T c3_b;
  static creal_T c3_dc0 = { 0.0, 1.0 };

  creal_T c3_y;
  real_T c3_b_A;
  real_T c3_x;
  real_T c3_b_x;
  real_T c3_b_y;
  real_T c3_r;
  creal_T c3_c_y;
  creal_T c3_d_y;
  real_T c3_b_b;
  real_T c3_c_A;
  real_T c3_c_x;
  real_T c3_d_x;
  real_T c3_e_y;
  real_T c3_b_r;
  creal_T c3_f_y;
  creal_T c3_g_y;
  real_T c3_c_b;
  real_T c3_d_A;
  real_T c3_e_x;
  real_T c3_f_x;
  real_T c3_h_y;
  real_T c3_c_r;
  creal_T c3_i_y;
  creal_T c3_j_y;
  int32_T c3_i3;
  creal_T c3_d_b[3];
  int32_T c3_i4;
  int32_T c3_i5;
  int32_T c3_i6;
  creal_T c3_C[3];
  int32_T c3_i7;
  int32_T c3_i8;
  int32_T c3_i9;
  int32_T c3_i10;
  int32_T c3_i11;
  int32_T c3_i12;
  creal_T c3_b_a;
  real_T c3_x1;
  real_T c3_x2;
  real_T c3_c_a;
  real_T c3_e_b;
  real_T c3_k_y;
  real_T c3_b_x1;
  real_T c3_b_x2;
  real_T c3_d_a;
  real_T c3_f_b;
  real_T c3_l_y;
  real_T c3_e_A;
  real_T c3_B;
  real_T c3_g_x;
  real_T c3_m_y;
  real_T c3_h_x;
  real_T c3_n_y;
  real_T c3_o_y;
  real_T c3_e_a;
  real_T *c3_b_REG_norm;
  real_T *c3_b_amplitude_R;
  real_T *c3_b_amplitude_S;
  real_T *c3_b_amplitude_T;
  real_T *c3_b_phase_R;
  real_T *c3_b_phase_S;
  real_T *c3_b_phase_T;
  c3_b_phase_T = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c3_b_phase_S = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c3_b_phase_R = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c3_b_amplitude_T = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c3_b_amplitude_S = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c3_b_REG_norm = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c3_b_amplitude_R = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c3_sfEvent);
  c3_hoistedGlobal = *c3_b_amplitude_R;
  c3_b_hoistedGlobal = *c3_b_amplitude_S;
  c3_c_hoistedGlobal = *c3_b_amplitude_T;
  c3_d_hoistedGlobal = *c3_b_phase_R;
  c3_e_hoistedGlobal = *c3_b_phase_S;
  c3_f_hoistedGlobal = *c3_b_phase_T;
  c3_amplitude_R = c3_hoistedGlobal;
  c3_amplitude_S = c3_b_hoistedGlobal;
  c3_amplitude_T = c3_c_hoistedGlobal;
  c3_phase_R = c3_d_hoistedGlobal;
  c3_phase_S = c3_e_hoistedGlobal;
  c3_phase_T = c3_f_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 12U, 12U, c3_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML(c3_A, 0U, c3_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_V_real, 1U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_V_012, 2U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 3U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 4U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_amplitude_R, 5U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_amplitude_S, 6U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_amplitude_T, 7U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_phase_R, 8U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_phase_S, 9U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_phase_T, 10U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_REG_norm, 11U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 4);
  for (c3_i0 = 0; c3_i0 < 9; c3_i0++) {
    c3_A[c3_i0] = c3_a[c3_i0];
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 8);
  for (c3_i1 = 0; c3_i1 < 3; c3_i1++) {
    c3_V_real[c3_i1].re = 0.0;
    c3_V_real[c3_i1].im = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 9);
  for (c3_i2 = 0; c3_i2 < 3; c3_i2++) {
    c3_V_012[c3_i2].re = 0.0;
    c3_V_012[c3_i2].im = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 10);
  c3_b = c3_phase_R;
  c3_y.re = c3_b * c3_dc0.re;
  c3_y.im = c3_b * c3_dc0.im;
  c3_b_A = c3_y.re;
  c3_x = c3_b_A;
  c3_b_x = c3_x;
  c3_b_y = c3_b_x / 2.0;
  c3_r = muDoubleScalarExp(c3_b_y);
  c3_c_y = c3_y;
  c3_d_y = c3_y;
  c3_y.re = c3_r * (c3_r * muDoubleScalarCos(c3_c_y.im));
  c3_y.im = c3_r * (c3_r * muDoubleScalarSin(c3_d_y.im));
  c3_V_real[0].re = c3_amplitude_R * c3_y.re;
  c3_V_real[0].im = c3_amplitude_R * c3_y.im;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 11);
  c3_b_b = c3_phase_S;
  c3_y.re = c3_b_b * c3_dc0.re;
  c3_y.im = c3_b_b * c3_dc0.im;
  c3_c_A = c3_y.re;
  c3_c_x = c3_c_A;
  c3_d_x = c3_c_x;
  c3_e_y = c3_d_x / 2.0;
  c3_b_r = muDoubleScalarExp(c3_e_y);
  c3_f_y = c3_y;
  c3_g_y = c3_y;
  c3_y.re = c3_b_r * (c3_b_r * muDoubleScalarCos(c3_f_y.im));
  c3_y.im = c3_b_r * (c3_b_r * muDoubleScalarSin(c3_g_y.im));
  c3_V_real[1].re = c3_amplitude_S * c3_y.re;
  c3_V_real[1].im = c3_amplitude_S * c3_y.im;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 12);
  c3_c_b = c3_phase_T;
  c3_y.re = c3_c_b * c3_dc0.re;
  c3_y.im = c3_c_b * c3_dc0.im;
  c3_d_A = c3_y.re;
  c3_e_x = c3_d_A;
  c3_f_x = c3_e_x;
  c3_h_y = c3_f_x / 2.0;
  c3_c_r = muDoubleScalarExp(c3_h_y);
  c3_i_y = c3_y;
  c3_j_y = c3_y;
  c3_y.re = c3_c_r * (c3_c_r * muDoubleScalarCos(c3_i_y.im));
  c3_y.im = c3_c_r * (c3_c_r * muDoubleScalarSin(c3_j_y.im));
  c3_V_real[2].re = c3_amplitude_T * c3_y.re;
  c3_V_real[2].im = c3_amplitude_T * c3_y.im;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 13);
  for (c3_i3 = 0; c3_i3 < 3; c3_i3++) {
    c3_d_b[c3_i3] = c3_V_real[c3_i3];
  }

  c3_eml_scalar_eg(chartInstance);
  c3_eml_scalar_eg(chartInstance);
  for (c3_i4 = 0; c3_i4 < 3; c3_i4++) {
    c3_V_012[c3_i4].re = 0.0;
    c3_V_012[c3_i4].im = 0.0;
  }

  for (c3_i5 = 0; c3_i5 < 3; c3_i5++) {
    c3_V_012[c3_i5].re = 0.0;
    c3_V_012[c3_i5].im = 0.0;
  }

  for (c3_i6 = 0; c3_i6 < 3; c3_i6++) {
    c3_C[c3_i6] = c3_V_012[c3_i6];
  }

  for (c3_i7 = 0; c3_i7 < 3; c3_i7++) {
    c3_V_012[c3_i7] = c3_C[c3_i7];
  }

  for (c3_i8 = 0; c3_i8 < 3; c3_i8++) {
    c3_C[c3_i8] = c3_V_012[c3_i8];
  }

  for (c3_i9 = 0; c3_i9 < 3; c3_i9++) {
    c3_V_012[c3_i9] = c3_C[c3_i9];
  }

  for (c3_i10 = 0; c3_i10 < 3; c3_i10++) {
    c3_V_012[c3_i10].re = 0.0;
    c3_V_012[c3_i10].im = 0.0;
    c3_i11 = 0;
    for (c3_i12 = 0; c3_i12 < 3; c3_i12++) {
      c3_b_a.re = c3_a[c3_i11 + c3_i10].re * c3_d_b[c3_i12].re - c3_a[c3_i11 +
        c3_i10].im * c3_d_b[c3_i12].im;
      c3_b_a.im = c3_a[c3_i11 + c3_i10].re * c3_d_b[c3_i12].im + c3_a[c3_i11 +
        c3_i10].im * c3_d_b[c3_i12].re;
      c3_V_012[c3_i10].re += c3_b_a.re;
      c3_V_012[c3_i10].im += c3_b_a.im;
      c3_i11 += 3;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 14);
  c3_y = c3_V_012[2];
  c3_x1 = c3_y.re;
  c3_x2 = c3_y.im;
  c3_c_a = c3_x1;
  c3_e_b = c3_x2;
  c3_k_y = muDoubleScalarHypot(c3_c_a, c3_e_b);
  c3_y = c3_V_012[1];
  c3_b_x1 = c3_y.re;
  c3_b_x2 = c3_y.im;
  c3_d_a = c3_b_x1;
  c3_f_b = c3_b_x2;
  c3_l_y = muDoubleScalarHypot(c3_d_a, c3_f_b);
  c3_e_A = c3_k_y;
  c3_B = c3_l_y;
  c3_g_x = c3_e_A;
  c3_m_y = c3_B;
  c3_h_x = c3_g_x;
  c3_n_y = c3_m_y;
  c3_o_y = c3_h_x / c3_n_y;
  c3_e_a = c3_o_y;
  c3_REG_norm = c3_e_a * 100.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, -14);
  _SFD_SYMBOL_SCOPE_POP();
  *c3_b_REG_norm = c3_REG_norm;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c3_sfEvent);
}

static void initSimStructsc3_Symmetry_Inverter_imagined
  (SFc3_Symmetry_Inverter_imaginedInstanceStruct *chartInstance)
{
}

static void registerMessagesc3_Symmetry_Inverter_imagined
  (SFc3_Symmetry_Inverter_imaginedInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber)
{
}

static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  real_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_Symmetry_Inverter_imaginedInstanceStruct *chartInstance;
  chartInstance = (SFc3_Symmetry_Inverter_imaginedInstanceStruct *)
    chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(real_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static real_T c3_emlrt_marshallIn(SFc3_Symmetry_Inverter_imaginedInstanceStruct *
  chartInstance, const mxArray *c3_REG_norm, const char_T *c3_identifier)
{
  real_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_REG_norm),
    &c3_thisId);
  sf_mex_destroy(&c3_REG_norm);
  return c3_y;
}

static real_T c3_b_emlrt_marshallIn
  (SFc3_Symmetry_Inverter_imaginedInstanceStruct *chartInstance, const mxArray
   *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  real_T c3_y;
  real_T c3_d0;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_d0, 1, 0, 0U, 0, 0U, 0);
  c3_y = c3_d0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_REG_norm;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y;
  SFc3_Symmetry_Inverter_imaginedInstanceStruct *chartInstance;
  chartInstance = (SFc3_Symmetry_Inverter_imaginedInstanceStruct *)
    chartInstanceVoid;
  c3_REG_norm = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_REG_norm),
    &c3_thisId);
  sf_mex_destroy(&c3_REG_norm);
  *(real_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i13;
  creal_T c3_b_inData[3];
  int32_T c3_i14;
  creal_T c3_u[3];
  const mxArray *c3_y = NULL;
  SFc3_Symmetry_Inverter_imaginedInstanceStruct *chartInstance;
  chartInstance = (SFc3_Symmetry_Inverter_imaginedInstanceStruct *)
    chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i13 = 0; c3_i13 < 3; c3_i13++) {
    c3_b_inData[c3_i13] = (*(creal_T (*)[3])c3_inData)[c3_i13];
  }

  for (c3_i14 = 0; c3_i14 < 3; c3_i14++) {
    c3_u[c3_i14] = c3_b_inData[c3_i14];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 1U, 1U, 0U, 1, 3), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static void c3_c_emlrt_marshallIn(SFc3_Symmetry_Inverter_imaginedInstanceStruct *
  chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  creal_T c3_y[3])
{
  creal_T c3_dcv0[3];
  int32_T c3_i15;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_dcv0, 1, 0, 1U, 1, 0U, 1, 3);
  for (c3_i15 = 0; c3_i15 < 3; c3_i15++) {
    c3_y[c3_i15] = c3_dcv0[c3_i15];
  }

  sf_mex_destroy(&c3_u);
}

static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_V_012;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  creal_T c3_y[3];
  int32_T c3_i16;
  SFc3_Symmetry_Inverter_imaginedInstanceStruct *chartInstance;
  chartInstance = (SFc3_Symmetry_Inverter_imaginedInstanceStruct *)
    chartInstanceVoid;
  c3_V_012 = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_V_012), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_V_012);
  for (c3_i16 = 0; c3_i16 < 3; c3_i16++) {
    (*(creal_T (*)[3])c3_outData)[c3_i16] = c3_y[c3_i16];
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i17;
  int32_T c3_i18;
  int32_T c3_i19;
  creal_T c3_b_inData[9];
  int32_T c3_i20;
  int32_T c3_i21;
  int32_T c3_i22;
  creal_T c3_u[9];
  const mxArray *c3_y = NULL;
  SFc3_Symmetry_Inverter_imaginedInstanceStruct *chartInstance;
  chartInstance = (SFc3_Symmetry_Inverter_imaginedInstanceStruct *)
    chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_i17 = 0;
  for (c3_i18 = 0; c3_i18 < 3; c3_i18++) {
    for (c3_i19 = 0; c3_i19 < 3; c3_i19++) {
      c3_b_inData[c3_i19 + c3_i17] = (*(creal_T (*)[9])c3_inData)[c3_i19 +
        c3_i17];
    }

    c3_i17 += 3;
  }

  c3_i20 = 0;
  for (c3_i21 = 0; c3_i21 < 3; c3_i21++) {
    for (c3_i22 = 0; c3_i22 < 3; c3_i22++) {
      c3_u[c3_i22 + c3_i20] = c3_b_inData[c3_i22 + c3_i20];
    }

    c3_i20 += 3;
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 1U, 1U, 0U, 2, 3, 3), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

const mxArray *sf_c3_Symmetry_Inverter_imagined_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c3_nameCaptureInfo;
  c3_ResolvedFunctionInfo c3_info[23];
  const mxArray *c3_m0 = NULL;
  int32_T c3_i23;
  c3_ResolvedFunctionInfo *c3_r0;
  c3_nameCaptureInfo = NULL;
  c3_nameCaptureInfo = NULL;
  c3_info_helper(c3_info);
  sf_mex_assign(&c3_m0, sf_mex_createstruct("nameCaptureInfo", 1, 23), FALSE);
  for (c3_i23 = 0; c3_i23 < 23; c3_i23++) {
    c3_r0 = &c3_info[c3_i23];
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c3_r0->context)), "context", "nameCaptureInfo",
                    c3_i23);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c3_r0->name)), "name", "nameCaptureInfo", c3_i23);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c3_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c3_i23);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c3_r0->resolved)), "resolved", "nameCaptureInfo",
                    c3_i23);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c3_i23);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c3_i23);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c3_i23);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c3_i23);
  }

  sf_mex_assign(&c3_nameCaptureInfo, c3_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c3_nameCaptureInfo);
  return c3_nameCaptureInfo;
}

static void c3_info_helper(c3_ResolvedFunctionInfo c3_info[23])
{
  c3_info[0].context = "";
  c3_info[0].name = "mrdivide";
  c3_info[0].dominantType = "double";
  c3_info[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c3_info[0].fileTimeLo = 1357951548U;
  c3_info[0].fileTimeHi = 0U;
  c3_info[0].mFileTimeLo = 1319729966U;
  c3_info[0].mFileTimeHi = 0U;
  c3_info[1].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c3_info[1].name = "rdivide";
  c3_info[1].dominantType = "double";
  c3_info[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c3_info[1].fileTimeLo = 1346510388U;
  c3_info[1].fileTimeHi = 0U;
  c3_info[1].mFileTimeLo = 0U;
  c3_info[1].mFileTimeHi = 0U;
  c3_info[2].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c3_info[2].name = "eml_scalexp_compatible";
  c3_info[2].dominantType = "double";
  c3_info[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m";
  c3_info[2].fileTimeLo = 1286818796U;
  c3_info[2].fileTimeHi = 0U;
  c3_info[2].mFileTimeLo = 0U;
  c3_info[2].mFileTimeHi = 0U;
  c3_info[3].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c3_info[3].name = "eml_div";
  c3_info[3].dominantType = "double";
  c3_info[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c3_info[3].fileTimeLo = 1313347810U;
  c3_info[3].fileTimeHi = 0U;
  c3_info[3].mFileTimeLo = 0U;
  c3_info[3].mFileTimeHi = 0U;
  c3_info[4].context = "";
  c3_info[4].name = "mtimes";
  c3_info[4].dominantType = "double";
  c3_info[4].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c3_info[4].fileTimeLo = 1289519692U;
  c3_info[4].fileTimeHi = 0U;
  c3_info[4].mFileTimeLo = 0U;
  c3_info[4].mFileTimeHi = 0U;
  c3_info[5].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m!eml_fldiv";
  c3_info[5].name = "eml_scalar_eg";
  c3_info[5].dominantType = "double";
  c3_info[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c3_info[5].fileTimeLo = 1286818796U;
  c3_info[5].fileTimeHi = 0U;
  c3_info[5].mFileTimeLo = 0U;
  c3_info[5].mFileTimeHi = 0U;
  c3_info[6].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m!eml_fldiv";
  c3_info[6].name = "eml_scalexp_alloc";
  c3_info[6].dominantType = "double";
  c3_info[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c3_info[6].fileTimeLo = 1352424860U;
  c3_info[6].fileTimeHi = 0U;
  c3_info[6].mFileTimeLo = 0U;
  c3_info[6].mFileTimeHi = 0U;
  c3_info[7].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m!eml_fldiv";
  c3_info[7].name = "abs";
  c3_info[7].dominantType = "double";
  c3_info[7].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c3_info[7].fileTimeLo = 1343830366U;
  c3_info[7].fileTimeHi = 0U;
  c3_info[7].mFileTimeLo = 0U;
  c3_info[7].mFileTimeHi = 0U;
  c3_info[8].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c3_info[8].name = "eml_scalar_abs";
  c3_info[8].dominantType = "double";
  c3_info[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c3_info[8].fileTimeLo = 1286818712U;
  c3_info[8].fileTimeHi = 0U;
  c3_info[8].mFileTimeLo = 0U;
  c3_info[8].mFileTimeHi = 0U;
  c3_info[9].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m!eml_fldiv";
  c3_info[9].name = "mtimes";
  c3_info[9].dominantType = "double";
  c3_info[9].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c3_info[9].fileTimeLo = 1289519692U;
  c3_info[9].fileTimeHi = 0U;
  c3_info[9].mFileTimeLo = 0U;
  c3_info[9].mFileTimeHi = 0U;
  c3_info[10].context = "";
  c3_info[10].name = "exp";
  c3_info[10].dominantType = "double";
  c3_info[10].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/exp.m";
  c3_info[10].fileTimeLo = 1343830380U;
  c3_info[10].fileTimeHi = 0U;
  c3_info[10].mFileTimeLo = 0U;
  c3_info[10].mFileTimeHi = 0U;
  c3_info[11].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/exp.m";
  c3_info[11].name = "eml_scalar_exp";
  c3_info[11].dominantType = "double";
  c3_info[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_exp.m";
  c3_info[11].fileTimeLo = 1301328464U;
  c3_info[11].fileTimeHi = 0U;
  c3_info[11].mFileTimeLo = 0U;
  c3_info[11].mFileTimeHi = 0U;
  c3_info[12].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_exp.m";
  c3_info[12].name = "mrdivide";
  c3_info[12].dominantType = "double";
  c3_info[12].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c3_info[12].fileTimeLo = 1357951548U;
  c3_info[12].fileTimeHi = 0U;
  c3_info[12].mFileTimeLo = 1319729966U;
  c3_info[12].mFileTimeHi = 0U;
  c3_info[13].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c3_info[13].name = "eml_index_class";
  c3_info[13].dominantType = "";
  c3_info[13].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c3_info[13].fileTimeLo = 1323170578U;
  c3_info[13].fileTimeHi = 0U;
  c3_info[13].mFileTimeLo = 0U;
  c3_info[13].mFileTimeHi = 0U;
  c3_info[14].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c3_info[14].name = "eml_scalar_eg";
  c3_info[14].dominantType = "double";
  c3_info[14].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c3_info[14].fileTimeLo = 1286818796U;
  c3_info[14].fileTimeHi = 0U;
  c3_info[14].mFileTimeLo = 0U;
  c3_info[14].mFileTimeHi = 0U;
  c3_info[15].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c3_info[15].name = "eml_xgemm";
  c3_info[15].dominantType = "char";
  c3_info[15].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c3_info[15].fileTimeLo = 1299076772U;
  c3_info[15].fileTimeHi = 0U;
  c3_info[15].mFileTimeLo = 0U;
  c3_info[15].mFileTimeHi = 0U;
  c3_info[16].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c3_info[16].name = "eml_blas_inline";
  c3_info[16].dominantType = "";
  c3_info[16].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c3_info[16].fileTimeLo = 1299076768U;
  c3_info[16].fileTimeHi = 0U;
  c3_info[16].mFileTimeLo = 0U;
  c3_info[16].mFileTimeHi = 0U;
  c3_info[17].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m!below_threshold";
  c3_info[17].name = "mtimes";
  c3_info[17].dominantType = "double";
  c3_info[17].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c3_info[17].fileTimeLo = 1289519692U;
  c3_info[17].fileTimeHi = 0U;
  c3_info[17].mFileTimeLo = 0U;
  c3_info[17].mFileTimeHi = 0U;
  c3_info[18].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c3_info[18].name = "eml_index_class";
  c3_info[18].dominantType = "";
  c3_info[18].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c3_info[18].fileTimeLo = 1323170578U;
  c3_info[18].fileTimeHi = 0U;
  c3_info[18].mFileTimeLo = 0U;
  c3_info[18].mFileTimeHi = 0U;
  c3_info[19].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c3_info[19].name = "eml_scalar_eg";
  c3_info[19].dominantType = "double";
  c3_info[19].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c3_info[19].fileTimeLo = 1286818796U;
  c3_info[19].fileTimeHi = 0U;
  c3_info[19].mFileTimeLo = 0U;
  c3_info[19].mFileTimeHi = 0U;
  c3_info[20].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c3_info[20].name = "eml_refblas_xgemm";
  c3_info[20].dominantType = "char";
  c3_info[20].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c3_info[20].fileTimeLo = 1299076774U;
  c3_info[20].fileTimeHi = 0U;
  c3_info[20].mFileTimeLo = 0U;
  c3_info[20].mFileTimeHi = 0U;
  c3_info[21].context = "";
  c3_info[21].name = "abs";
  c3_info[21].dominantType = "double";
  c3_info[21].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c3_info[21].fileTimeLo = 1343830366U;
  c3_info[21].fileTimeHi = 0U;
  c3_info[21].mFileTimeLo = 0U;
  c3_info[21].mFileTimeHi = 0U;
  c3_info[22].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c3_info[22].name = "eml_dlapy2";
  c3_info[22].dominantType = "double";
  c3_info[22].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_dlapy2.m";
  c3_info[22].fileTimeLo = 1350410654U;
  c3_info[22].fileTimeHi = 0U;
  c3_info[22].mFileTimeLo = 0U;
  c3_info[22].mFileTimeHi = 0U;
}

static void c3_eml_scalar_eg(SFc3_Symmetry_Inverter_imaginedInstanceStruct
  *chartInstance)
{
}

static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_Symmetry_Inverter_imaginedInstanceStruct *chartInstance;
  chartInstance = (SFc3_Symmetry_Inverter_imaginedInstanceStruct *)
    chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(int32_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static int32_T c3_d_emlrt_marshallIn
  (SFc3_Symmetry_Inverter_imaginedInstanceStruct *chartInstance, const mxArray
   *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  int32_T c3_y;
  int32_T c3_i24;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_i24, 1, 6, 0U, 0, 0U, 0);
  c3_y = c3_i24;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_sfEvent;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  int32_T c3_y;
  SFc3_Symmetry_Inverter_imaginedInstanceStruct *chartInstance;
  chartInstance = (SFc3_Symmetry_Inverter_imaginedInstanceStruct *)
    chartInstanceVoid;
  c3_b_sfEvent = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_sfEvent),
    &c3_thisId);
  sf_mex_destroy(&c3_b_sfEvent);
  *(int32_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static uint8_T c3_e_emlrt_marshallIn
  (SFc3_Symmetry_Inverter_imaginedInstanceStruct *chartInstance, const mxArray
   *c3_b_is_active_c3_Symmetry_Inverter_imagined, const char_T *c3_identifier)
{
  uint8_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_b_is_active_c3_Symmetry_Inverter_imagined), &c3_thisId);
  sf_mex_destroy(&c3_b_is_active_c3_Symmetry_Inverter_imagined);
  return c3_y;
}

static uint8_T c3_f_emlrt_marshallIn
  (SFc3_Symmetry_Inverter_imaginedInstanceStruct *chartInstance, const mxArray
   *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  uint8_T c3_y;
  uint8_T c3_u0;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_u0, 1, 3, 0U, 0, 0U, 0);
  c3_y = c3_u0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void init_dsm_address_info(SFc3_Symmetry_Inverter_imaginedInstanceStruct *
  chartInstance)
{
}

/* SFunction Glue Code */
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

void sf_c3_Symmetry_Inverter_imagined_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1458038795U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1670581392U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3260742826U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1349839193U);
}

mxArray *sf_c3_Symmetry_Inverter_imagined_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("NrBsKEkFV12tmzXsduVsZB");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,6,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,5,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,5,"type",mxType);
    }

    mxSetField(mxData,5,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c3_Symmetry_Inverter_imagined_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c3_Symmetry_Inverter_imagined(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"REG_norm\",},{M[8],M[0],T\"is_active_c3_Symmetry_Inverter_imagined\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c3_Symmetry_Inverter_imagined_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc3_Symmetry_Inverter_imaginedInstanceStruct *chartInstance;
    chartInstance = (SFc3_Symmetry_Inverter_imaginedInstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Symmetry_Inverter_imaginedMachineNumber_,
           3,
           1,
           1,
           7,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           ssGetPath(S),
           (void *)S);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          init_script_number_translation
            (_Symmetry_Inverter_imaginedMachineNumber_,
             chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,
             _Symmetry_Inverter_imaginedMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _Symmetry_Inverter_imaginedMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"amplitude_R");
          _SFD_SET_DATA_PROPS(1,2,0,1,"REG_norm");
          _SFD_SET_DATA_PROPS(2,1,1,0,"amplitude_S");
          _SFD_SET_DATA_PROPS(3,1,1,0,"amplitude_T");
          _SFD_SET_DATA_PROPS(4,1,1,0,"phase_R");
          _SFD_SET_DATA_PROPS(5,1,1,0,"phase_S");
          _SFD_SET_DATA_PROPS(6,1,1,0,"phase_T");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,547);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);

        {
          real_T *c3_amplitude_R;
          real_T *c3_REG_norm;
          real_T *c3_amplitude_S;
          real_T *c3_amplitude_T;
          real_T *c3_phase_R;
          real_T *c3_phase_S;
          real_T *c3_phase_T;
          c3_phase_T = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
          c3_phase_S = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
          c3_phase_R = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c3_amplitude_T = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c3_amplitude_S = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c3_REG_norm = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c3_amplitude_R = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c3_amplitude_R);
          _SFD_SET_DATA_VALUE_PTR(1U, c3_REG_norm);
          _SFD_SET_DATA_VALUE_PTR(2U, c3_amplitude_S);
          _SFD_SET_DATA_VALUE_PTR(3U, c3_amplitude_T);
          _SFD_SET_DATA_VALUE_PTR(4U, c3_phase_R);
          _SFD_SET_DATA_VALUE_PTR(5U, c3_phase_S);
          _SFD_SET_DATA_VALUE_PTR(6U, c3_phase_T);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _Symmetry_Inverter_imaginedMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "iFEmVdwOmuRS3l88HaCuD";
}

static void sf_opaque_initialize_c3_Symmetry_Inverter_imagined(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc3_Symmetry_Inverter_imaginedInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c3_Symmetry_Inverter_imagined
    ((SFc3_Symmetry_Inverter_imaginedInstanceStruct*) chartInstanceVar);
  initialize_c3_Symmetry_Inverter_imagined
    ((SFc3_Symmetry_Inverter_imaginedInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c3_Symmetry_Inverter_imagined(void
  *chartInstanceVar)
{
  enable_c3_Symmetry_Inverter_imagined
    ((SFc3_Symmetry_Inverter_imaginedInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c3_Symmetry_Inverter_imagined(void
  *chartInstanceVar)
{
  disable_c3_Symmetry_Inverter_imagined
    ((SFc3_Symmetry_Inverter_imaginedInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c3_Symmetry_Inverter_imagined(void
  *chartInstanceVar)
{
  sf_c3_Symmetry_Inverter_imagined
    ((SFc3_Symmetry_Inverter_imaginedInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c3_Symmetry_Inverter_imagined
  (SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c3_Symmetry_Inverter_imagined
    ((SFc3_Symmetry_Inverter_imaginedInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c3_Symmetry_Inverter_imagined();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_raw2high'.\n");
  }

  return plhs[0];
}

extern void sf_internal_set_sim_state_c3_Symmetry_Inverter_imagined(SimStruct* S,
  const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c3_Symmetry_Inverter_imagined();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c3_Symmetry_Inverter_imagined
    ((SFc3_Symmetry_Inverter_imaginedInstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c3_Symmetry_Inverter_imagined
  (SimStruct* S)
{
  return sf_internal_get_sim_state_c3_Symmetry_Inverter_imagined(S);
}

static void sf_opaque_set_sim_state_c3_Symmetry_Inverter_imagined(SimStruct* S,
  const mxArray *st)
{
  sf_internal_set_sim_state_c3_Symmetry_Inverter_imagined(S, st);
}

static void sf_opaque_terminate_c3_Symmetry_Inverter_imagined(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc3_Symmetry_Inverter_imaginedInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Symmetry_Inverter_imagined_optimization_info();
    }

    finalize_c3_Symmetry_Inverter_imagined
      ((SFc3_Symmetry_Inverter_imaginedInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc3_Symmetry_Inverter_imagined
    ((SFc3_Symmetry_Inverter_imaginedInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c3_Symmetry_Inverter_imagined(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c3_Symmetry_Inverter_imagined
      ((SFc3_Symmetry_Inverter_imaginedInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c3_Symmetry_Inverter_imagined(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Symmetry_Inverter_imagined_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      3);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,3,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,3,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,3);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,3,6);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,3,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 6; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,3);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1803342455U));
  ssSetChecksum1(S,(1210260776U));
  ssSetChecksum2(S,(796717877U));
  ssSetChecksum3(S,(4105591722U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c3_Symmetry_Inverter_imagined(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c3_Symmetry_Inverter_imagined(SimStruct *S)
{
  SFc3_Symmetry_Inverter_imaginedInstanceStruct *chartInstance;
  chartInstance = (SFc3_Symmetry_Inverter_imaginedInstanceStruct *)utMalloc
    (sizeof(SFc3_Symmetry_Inverter_imaginedInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc3_Symmetry_Inverter_imaginedInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c3_Symmetry_Inverter_imagined;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c3_Symmetry_Inverter_imagined;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c3_Symmetry_Inverter_imagined;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c3_Symmetry_Inverter_imagined;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c3_Symmetry_Inverter_imagined;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c3_Symmetry_Inverter_imagined;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c3_Symmetry_Inverter_imagined;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c3_Symmetry_Inverter_imagined;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c3_Symmetry_Inverter_imagined;
  chartInstance->chartInfo.mdlStart = mdlStart_c3_Symmetry_Inverter_imagined;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c3_Symmetry_Inverter_imagined;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->S = S;
  ssSetUserData(S,(void *)(&(chartInstance->chartInfo)));/* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
  chart_debug_initialization(S,1);
}

void c3_Symmetry_Inverter_imagined_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c3_Symmetry_Inverter_imagined(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c3_Symmetry_Inverter_imagined(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c3_Symmetry_Inverter_imagined(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c3_Symmetry_Inverter_imagined_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
