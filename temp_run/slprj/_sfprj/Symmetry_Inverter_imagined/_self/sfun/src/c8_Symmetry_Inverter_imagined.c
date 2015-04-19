/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Symmetry_Inverter_imagined_sfun.h"
#include "c8_Symmetry_Inverter_imagined.h"
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
static const char * c8_debug_family_names[15] = { "N", "V_real", "R_error",
  "S_error", "T_error", "nargin", "nargout", "amplitude_R", "amplitude_S",
  "amplitude_T", "phase_R", "phase_S", "phase_T", "VEC_norm", "Mean" };

/* Function Declarations */
static void initialize_c8_Symmetry_Inverter_imagined
  (SFc8_Symmetry_Inverter_imaginedInstanceStruct *chartInstance);
static void initialize_params_c8_Symmetry_Inverter_imagined
  (SFc8_Symmetry_Inverter_imaginedInstanceStruct *chartInstance);
static void enable_c8_Symmetry_Inverter_imagined
  (SFc8_Symmetry_Inverter_imaginedInstanceStruct *chartInstance);
static void disable_c8_Symmetry_Inverter_imagined
  (SFc8_Symmetry_Inverter_imaginedInstanceStruct *chartInstance);
static void c8_update_debugger_state_c8_Symmetry_Inverter_imagined
  (SFc8_Symmetry_Inverter_imaginedInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c8_Symmetry_Inverter_imagined
  (SFc8_Symmetry_Inverter_imaginedInstanceStruct *chartInstance);
static void set_sim_state_c8_Symmetry_Inverter_imagined
  (SFc8_Symmetry_Inverter_imaginedInstanceStruct *chartInstance, const mxArray
   *c8_st);
static void finalize_c8_Symmetry_Inverter_imagined
  (SFc8_Symmetry_Inverter_imaginedInstanceStruct *chartInstance);
static void sf_c8_Symmetry_Inverter_imagined
  (SFc8_Symmetry_Inverter_imaginedInstanceStruct *chartInstance);
static void initSimStructsc8_Symmetry_Inverter_imagined
  (SFc8_Symmetry_Inverter_imaginedInstanceStruct *chartInstance);
static void registerMessagesc8_Symmetry_Inverter_imagined
  (SFc8_Symmetry_Inverter_imaginedInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c8_machineNumber, uint32_T
  c8_chartNumber);
static const mxArray *c8_sf_marshallOut(void *chartInstanceVoid, void *c8_inData);
static real_T c8_emlrt_marshallIn(SFc8_Symmetry_Inverter_imaginedInstanceStruct *
  chartInstance, const mxArray *c8_Mean, const char_T *c8_identifier);
static real_T c8_b_emlrt_marshallIn
  (SFc8_Symmetry_Inverter_imaginedInstanceStruct *chartInstance, const mxArray
   *c8_u, const emlrtMsgIdentifier *c8_parentId);
static void c8_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData);
static const mxArray *c8_b_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static creal_T c8_c_emlrt_marshallIn
  (SFc8_Symmetry_Inverter_imaginedInstanceStruct *chartInstance, const mxArray
   *c8_u, const emlrtMsgIdentifier *c8_parentId);
static void c8_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData);
static const mxArray *c8_c_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static void c8_d_emlrt_marshallIn(SFc8_Symmetry_Inverter_imaginedInstanceStruct *
  chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId,
  creal_T c8_y[3]);
static void c8_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData);
static void c8_info_helper(c8_ResolvedFunctionInfo c8_info[15]);
static const mxArray *c8_d_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static int32_T c8_e_emlrt_marshallIn
  (SFc8_Symmetry_Inverter_imaginedInstanceStruct *chartInstance, const mxArray
   *c8_u, const emlrtMsgIdentifier *c8_parentId);
static void c8_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData);
static uint8_T c8_f_emlrt_marshallIn
  (SFc8_Symmetry_Inverter_imaginedInstanceStruct *chartInstance, const mxArray
   *c8_b_is_active_c8_Symmetry_Inverter_imagined, const char_T *c8_identifier);
static uint8_T c8_g_emlrt_marshallIn
  (SFc8_Symmetry_Inverter_imaginedInstanceStruct *chartInstance, const mxArray
   *c8_u, const emlrtMsgIdentifier *c8_parentId);
static void init_dsm_address_info(SFc8_Symmetry_Inverter_imaginedInstanceStruct *
  chartInstance);

/* Function Definitions */
static void initialize_c8_Symmetry_Inverter_imagined
  (SFc8_Symmetry_Inverter_imaginedInstanceStruct *chartInstance)
{
  chartInstance->c8_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c8_is_active_c8_Symmetry_Inverter_imagined = 0U;
}

static void initialize_params_c8_Symmetry_Inverter_imagined
  (SFc8_Symmetry_Inverter_imaginedInstanceStruct *chartInstance)
{
}

static void enable_c8_Symmetry_Inverter_imagined
  (SFc8_Symmetry_Inverter_imaginedInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c8_Symmetry_Inverter_imagined
  (SFc8_Symmetry_Inverter_imaginedInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c8_update_debugger_state_c8_Symmetry_Inverter_imagined
  (SFc8_Symmetry_Inverter_imaginedInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c8_Symmetry_Inverter_imagined
  (SFc8_Symmetry_Inverter_imaginedInstanceStruct *chartInstance)
{
  const mxArray *c8_st;
  const mxArray *c8_y = NULL;
  real_T c8_hoistedGlobal;
  real_T c8_u;
  const mxArray *c8_b_y = NULL;
  real_T c8_b_hoistedGlobal;
  real_T c8_b_u;
  const mxArray *c8_c_y = NULL;
  uint8_T c8_c_hoistedGlobal;
  uint8_T c8_c_u;
  const mxArray *c8_d_y = NULL;
  real_T *c8_Mean;
  real_T *c8_VEC_norm;
  c8_Mean = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c8_VEC_norm = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c8_st = NULL;
  c8_st = NULL;
  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_createcellarray(3), FALSE);
  c8_hoistedGlobal = *c8_Mean;
  c8_u = c8_hoistedGlobal;
  c8_b_y = NULL;
  sf_mex_assign(&c8_b_y, sf_mex_create("y", &c8_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c8_y, 0, c8_b_y);
  c8_b_hoistedGlobal = *c8_VEC_norm;
  c8_b_u = c8_b_hoistedGlobal;
  c8_c_y = NULL;
  sf_mex_assign(&c8_c_y, sf_mex_create("y", &c8_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c8_y, 1, c8_c_y);
  c8_c_hoistedGlobal = chartInstance->c8_is_active_c8_Symmetry_Inverter_imagined;
  c8_c_u = c8_c_hoistedGlobal;
  c8_d_y = NULL;
  sf_mex_assign(&c8_d_y, sf_mex_create("y", &c8_c_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c8_y, 2, c8_d_y);
  sf_mex_assign(&c8_st, c8_y, FALSE);
  return c8_st;
}

static void set_sim_state_c8_Symmetry_Inverter_imagined
  (SFc8_Symmetry_Inverter_imaginedInstanceStruct *chartInstance, const mxArray
   *c8_st)
{
  const mxArray *c8_u;
  real_T *c8_Mean;
  real_T *c8_VEC_norm;
  c8_Mean = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c8_VEC_norm = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c8_doneDoubleBufferReInit = TRUE;
  c8_u = sf_mex_dup(c8_st);
  *c8_Mean = c8_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c8_u,
    0)), "Mean");
  *c8_VEC_norm = c8_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c8_u, 1)), "VEC_norm");
  chartInstance->c8_is_active_c8_Symmetry_Inverter_imagined =
    c8_f_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c8_u, 2)),
    "is_active_c8_Symmetry_Inverter_imagined");
  sf_mex_destroy(&c8_u);
  c8_update_debugger_state_c8_Symmetry_Inverter_imagined(chartInstance);
  sf_mex_destroy(&c8_st);
}

static void finalize_c8_Symmetry_Inverter_imagined
  (SFc8_Symmetry_Inverter_imaginedInstanceStruct *chartInstance)
{
}

static void sf_c8_Symmetry_Inverter_imagined
  (SFc8_Symmetry_Inverter_imaginedInstanceStruct *chartInstance)
{
  real_T c8_hoistedGlobal;
  real_T c8_b_hoistedGlobal;
  real_T c8_c_hoistedGlobal;
  real_T c8_d_hoistedGlobal;
  real_T c8_e_hoistedGlobal;
  real_T c8_f_hoistedGlobal;
  real_T c8_amplitude_R;
  real_T c8_amplitude_S;
  real_T c8_amplitude_T;
  real_T c8_phase_R;
  real_T c8_phase_S;
  real_T c8_phase_T;
  uint32_T c8_debug_family_var_map[15];
  creal_T c8_N;
  creal_T c8_V_real[3];
  creal_T c8_R_error;
  creal_T c8_S_error;
  creal_T c8_T_error;
  real_T c8_nargin = 6.0;
  real_T c8_nargout = 2.0;
  real_T c8_VEC_norm;
  real_T c8_Mean;
  real_T c8_A;
  real_T c8_x;
  real_T c8_b_x;
  static creal_T c8_dc0 = { 0.0, 0.0 };

  int32_T c8_i0;
  real_T c8_b;
  static creal_T c8_dc1 = { 0.0, 1.0 };

  creal_T c8_y;
  real_T c8_b_A;
  real_T c8_c_x;
  real_T c8_d_x;
  real_T c8_b_y;
  real_T c8_r;
  creal_T c8_c_y;
  creal_T c8_d_y;
  real_T c8_b_b;
  real_T c8_c_A;
  real_T c8_e_x;
  real_T c8_f_x;
  real_T c8_e_y;
  real_T c8_b_r;
  creal_T c8_f_y;
  creal_T c8_g_y;
  real_T c8_c_b;
  real_T c8_d_A;
  real_T c8_g_x;
  real_T c8_h_x;
  real_T c8_h_y;
  real_T c8_c_r;
  creal_T c8_i_y;
  creal_T c8_j_y;
  static creal_T c8_dc2 = { 230.0, 0.0 };

  static creal_T c8_dc3 = { -114.99999999999994, -199.18584287042091 };

  static creal_T c8_dc4 = { -115.0000000000001, 199.18584287042086 };

  creal_T c8_a;
  creal_T c8_d_b;
  creal_T c8_k_y;
  creal_T c8_b_a;
  real_T c8_x1;
  real_T c8_x2;
  real_T c8_c_a;
  real_T c8_e_b;
  real_T *c8_b_Mean;
  real_T *c8_b_VEC_norm;
  real_T *c8_b_phase_T;
  real_T *c8_b_phase_S;
  real_T *c8_b_phase_R;
  real_T *c8_b_amplitude_T;
  real_T *c8_b_amplitude_S;
  real_T *c8_b_amplitude_R;
  c8_b_Mean = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c8_b_phase_T = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c8_b_phase_S = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c8_b_phase_R = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c8_b_amplitude_T = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c8_b_amplitude_S = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c8_b_VEC_norm = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c8_b_amplitude_R = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 7U, chartInstance->c8_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c8_b_amplitude_R, 0U);
  _SFD_DATA_RANGE_CHECK(*c8_b_VEC_norm, 1U);
  _SFD_DATA_RANGE_CHECK(*c8_b_amplitude_S, 2U);
  _SFD_DATA_RANGE_CHECK(*c8_b_amplitude_T, 3U);
  _SFD_DATA_RANGE_CHECK(*c8_b_phase_R, 4U);
  _SFD_DATA_RANGE_CHECK(*c8_b_phase_S, 5U);
  _SFD_DATA_RANGE_CHECK(*c8_b_phase_T, 6U);
  _SFD_DATA_RANGE_CHECK(*c8_b_Mean, 7U);
  chartInstance->c8_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 7U, chartInstance->c8_sfEvent);
  c8_hoistedGlobal = *c8_b_amplitude_R;
  c8_b_hoistedGlobal = *c8_b_amplitude_S;
  c8_c_hoistedGlobal = *c8_b_amplitude_T;
  c8_d_hoistedGlobal = *c8_b_phase_R;
  c8_e_hoistedGlobal = *c8_b_phase_S;
  c8_f_hoistedGlobal = *c8_b_phase_T;
  c8_amplitude_R = c8_hoistedGlobal;
  c8_amplitude_S = c8_b_hoistedGlobal;
  c8_amplitude_T = c8_c_hoistedGlobal;
  c8_phase_R = c8_d_hoistedGlobal;
  c8_phase_S = c8_e_hoistedGlobal;
  c8_phase_T = c8_f_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 15U, 15U, c8_debug_family_names,
    c8_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_N, 0U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_V_real, 1U, c8_c_sf_marshallOut,
    c8_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_R_error, 2U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_S_error, 3U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_T_error, 4U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargin, 5U, c8_sf_marshallOut,
    c8_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargout, 6U, c8_sf_marshallOut,
    c8_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c8_amplitude_R, 7U, c8_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c8_amplitude_S, 8U, c8_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c8_amplitude_T, 9U, c8_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c8_phase_R, 10U, c8_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c8_phase_S, 11U, c8_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c8_phase_T, 12U, c8_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_VEC_norm, 13U, c8_sf_marshallOut,
    c8_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_Mean, 14U, c8_sf_marshallOut,
    c8_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 4);
  c8_Mean = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 5);
  c8_A = (c8_amplitude_R + c8_amplitude_S) + c8_amplitude_T;
  c8_x = c8_A;
  c8_b_x = c8_x;
  c8_Mean = c8_b_x / 3.0;
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 6);
  c8_N = c8_dc0;
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 7);
  for (c8_i0 = 0; c8_i0 < 3; c8_i0++) {
    c8_V_real[c8_i0].re = 0.0;
    c8_V_real[c8_i0].im = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 9);
  c8_b = c8_phase_R;
  c8_y.re = c8_b * c8_dc1.re;
  c8_y.im = c8_b * c8_dc1.im;
  c8_b_A = c8_y.re;
  c8_c_x = c8_b_A;
  c8_d_x = c8_c_x;
  c8_b_y = c8_d_x / 2.0;
  c8_r = muDoubleScalarExp(c8_b_y);
  c8_c_y = c8_y;
  c8_d_y = c8_y;
  c8_y.re = c8_r * (c8_r * muDoubleScalarCos(c8_c_y.im));
  c8_y.im = c8_r * (c8_r * muDoubleScalarSin(c8_d_y.im));
  c8_V_real[0].re = c8_Mean * c8_y.re;
  c8_V_real[0].im = c8_Mean * c8_y.im;
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 10);
  c8_b_b = c8_phase_S;
  c8_y.re = c8_b_b * c8_dc1.re;
  c8_y.im = c8_b_b * c8_dc1.im;
  c8_c_A = c8_y.re;
  c8_e_x = c8_c_A;
  c8_f_x = c8_e_x;
  c8_e_y = c8_f_x / 2.0;
  c8_b_r = muDoubleScalarExp(c8_e_y);
  c8_f_y = c8_y;
  c8_g_y = c8_y;
  c8_y.re = c8_b_r * (c8_b_r * muDoubleScalarCos(c8_f_y.im));
  c8_y.im = c8_b_r * (c8_b_r * muDoubleScalarSin(c8_g_y.im));
  c8_V_real[1].re = c8_Mean * c8_y.re;
  c8_V_real[1].im = c8_Mean * c8_y.im;
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 11);
  c8_c_b = c8_phase_T;
  c8_y.re = c8_c_b * c8_dc1.re;
  c8_y.im = c8_c_b * c8_dc1.im;
  c8_d_A = c8_y.re;
  c8_g_x = c8_d_A;
  c8_h_x = c8_g_x;
  c8_h_y = c8_h_x / 2.0;
  c8_c_r = muDoubleScalarExp(c8_h_y);
  c8_i_y = c8_y;
  c8_j_y = c8_y;
  c8_y.re = c8_c_r * (c8_c_r * muDoubleScalarCos(c8_i_y.im));
  c8_y.im = c8_c_r * (c8_c_r * muDoubleScalarSin(c8_j_y.im));
  c8_V_real[2].re = c8_Mean * c8_y.re;
  c8_V_real[2].im = c8_Mean * c8_y.im;
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 13);
  c8_R_error.re = c8_dc2.re - c8_V_real[0].re;
  c8_R_error.im = c8_dc2.im - c8_V_real[0].im;
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 14);
  c8_S_error.re = c8_dc3.re - c8_V_real[1].re;
  c8_S_error.im = c8_dc3.im - c8_V_real[1].im;
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 15);
  c8_T_error.re = c8_dc4.re - c8_V_real[2].re;
  c8_T_error.im = c8_dc4.im - c8_V_real[2].im;
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 17);
  c8_a = c8_R_error;
  c8_d_b = c8_S_error;
  c8_y.re = c8_a.re * c8_d_b.re - c8_a.im * c8_d_b.im;
  c8_y.im = c8_a.re * c8_d_b.im + c8_a.im * c8_d_b.re;
  c8_a = c8_R_error;
  c8_d_b = c8_T_error;
  c8_k_y.re = c8_a.re * c8_d_b.re - c8_a.im * c8_d_b.im;
  c8_k_y.im = c8_a.re * c8_d_b.im + c8_a.im * c8_d_b.re;
  c8_a = c8_S_error;
  c8_d_b = c8_T_error;
  c8_b_a = c8_a;
  c8_a.re = c8_b_a.re * c8_d_b.re - c8_b_a.im * c8_d_b.im;
  c8_a.im = c8_b_a.re * c8_d_b.im + c8_b_a.im * c8_d_b.re;
  c8_N.re = (c8_y.re + c8_k_y.re) + c8_a.re;
  c8_N.im = (c8_y.im + c8_k_y.im) + c8_a.im;
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 18);
  c8_a = c8_N;
  c8_x1 = c8_a.re;
  c8_x2 = c8_a.im;
  c8_c_a = c8_x1;
  c8_e_b = c8_x2;
  c8_VEC_norm = muDoubleScalarHypot(c8_c_a, c8_e_b);
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, -18);
  _SFD_SYMBOL_SCOPE_POP();
  *c8_b_VEC_norm = c8_VEC_norm;
  *c8_b_Mean = c8_Mean;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 7U, chartInstance->c8_sfEvent);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_Symmetry_Inverter_imaginedMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc8_Symmetry_Inverter_imagined
  (SFc8_Symmetry_Inverter_imaginedInstanceStruct *chartInstance)
{
}

static void registerMessagesc8_Symmetry_Inverter_imagined
  (SFc8_Symmetry_Inverter_imaginedInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c8_machineNumber, uint32_T
  c8_chartNumber)
{
}

static const mxArray *c8_sf_marshallOut(void *chartInstanceVoid, void *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  real_T c8_u;
  const mxArray *c8_y = NULL;
  SFc8_Symmetry_Inverter_imaginedInstanceStruct *chartInstance;
  chartInstance = (SFc8_Symmetry_Inverter_imaginedInstanceStruct *)
    chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  c8_u = *(real_T *)c8_inData;
  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", &c8_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, FALSE);
  return c8_mxArrayOutData;
}

static real_T c8_emlrt_marshallIn(SFc8_Symmetry_Inverter_imaginedInstanceStruct *
  chartInstance, const mxArray *c8_Mean, const char_T *c8_identifier)
{
  real_T c8_y;
  emlrtMsgIdentifier c8_thisId;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_y = c8_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_Mean), &c8_thisId);
  sf_mex_destroy(&c8_Mean);
  return c8_y;
}

static real_T c8_b_emlrt_marshallIn
  (SFc8_Symmetry_Inverter_imaginedInstanceStruct *chartInstance, const mxArray
   *c8_u, const emlrtMsgIdentifier *c8_parentId)
{
  real_T c8_y;
  real_T c8_d0;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_u), &c8_d0, 1, 0, 0U, 0, 0U, 0);
  c8_y = c8_d0;
  sf_mex_destroy(&c8_u);
  return c8_y;
}

static void c8_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData)
{
  const mxArray *c8_Mean;
  const char_T *c8_identifier;
  emlrtMsgIdentifier c8_thisId;
  real_T c8_y;
  SFc8_Symmetry_Inverter_imaginedInstanceStruct *chartInstance;
  chartInstance = (SFc8_Symmetry_Inverter_imaginedInstanceStruct *)
    chartInstanceVoid;
  c8_Mean = sf_mex_dup(c8_mxArrayInData);
  c8_identifier = c8_varName;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_y = c8_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_Mean), &c8_thisId);
  sf_mex_destroy(&c8_Mean);
  *(real_T *)c8_outData = c8_y;
  sf_mex_destroy(&c8_mxArrayInData);
}

static const mxArray *c8_b_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  creal_T c8_u;
  const mxArray *c8_y = NULL;
  SFc8_Symmetry_Inverter_imaginedInstanceStruct *chartInstance;
  chartInstance = (SFc8_Symmetry_Inverter_imaginedInstanceStruct *)
    chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  c8_u = *(creal_T *)c8_inData;
  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", &c8_u, 0, 1U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, FALSE);
  return c8_mxArrayOutData;
}

static creal_T c8_c_emlrt_marshallIn
  (SFc8_Symmetry_Inverter_imaginedInstanceStruct *chartInstance, const mxArray
   *c8_u, const emlrtMsgIdentifier *c8_parentId)
{
  creal_T c8_y;
  creal_T c8_dc5;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_u), &c8_dc5, 1, 0, 1U, 0, 0U, 0);
  c8_y = c8_dc5;
  sf_mex_destroy(&c8_u);
  return c8_y;
}

static void c8_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData)
{
  const mxArray *c8_T_error;
  const char_T *c8_identifier;
  emlrtMsgIdentifier c8_thisId;
  creal_T c8_y;
  SFc8_Symmetry_Inverter_imaginedInstanceStruct *chartInstance;
  chartInstance = (SFc8_Symmetry_Inverter_imaginedInstanceStruct *)
    chartInstanceVoid;
  c8_T_error = sf_mex_dup(c8_mxArrayInData);
  c8_identifier = c8_varName;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_y = c8_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_T_error), &c8_thisId);
  sf_mex_destroy(&c8_T_error);
  *(creal_T *)c8_outData = c8_y;
  sf_mex_destroy(&c8_mxArrayInData);
}

static const mxArray *c8_c_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  int32_T c8_i1;
  creal_T c8_b_inData[3];
  int32_T c8_i2;
  creal_T c8_u[3];
  const mxArray *c8_y = NULL;
  SFc8_Symmetry_Inverter_imaginedInstanceStruct *chartInstance;
  chartInstance = (SFc8_Symmetry_Inverter_imaginedInstanceStruct *)
    chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  for (c8_i1 = 0; c8_i1 < 3; c8_i1++) {
    c8_b_inData[c8_i1] = (*(creal_T (*)[3])c8_inData)[c8_i1];
  }

  for (c8_i2 = 0; c8_i2 < 3; c8_i2++) {
    c8_u[c8_i2] = c8_b_inData[c8_i2];
  }

  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", c8_u, 0, 1U, 1U, 0U, 1, 3), FALSE);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, FALSE);
  return c8_mxArrayOutData;
}

static void c8_d_emlrt_marshallIn(SFc8_Symmetry_Inverter_imaginedInstanceStruct *
  chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId,
  creal_T c8_y[3])
{
  creal_T c8_dcv0[3];
  int32_T c8_i3;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_u), c8_dcv0, 1, 0, 1U, 1, 0U, 1, 3);
  for (c8_i3 = 0; c8_i3 < 3; c8_i3++) {
    c8_y[c8_i3] = c8_dcv0[c8_i3];
  }

  sf_mex_destroy(&c8_u);
}

static void c8_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData)
{
  const mxArray *c8_V_real;
  const char_T *c8_identifier;
  emlrtMsgIdentifier c8_thisId;
  creal_T c8_y[3];
  int32_T c8_i4;
  SFc8_Symmetry_Inverter_imaginedInstanceStruct *chartInstance;
  chartInstance = (SFc8_Symmetry_Inverter_imaginedInstanceStruct *)
    chartInstanceVoid;
  c8_V_real = sf_mex_dup(c8_mxArrayInData);
  c8_identifier = c8_varName;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_V_real), &c8_thisId, c8_y);
  sf_mex_destroy(&c8_V_real);
  for (c8_i4 = 0; c8_i4 < 3; c8_i4++) {
    (*(creal_T (*)[3])c8_outData)[c8_i4] = c8_y[c8_i4];
  }

  sf_mex_destroy(&c8_mxArrayInData);
}

const mxArray *sf_c8_Symmetry_Inverter_imagined_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c8_nameCaptureInfo;
  c8_ResolvedFunctionInfo c8_info[15];
  const mxArray *c8_m0 = NULL;
  int32_T c8_i5;
  c8_ResolvedFunctionInfo *c8_r0;
  c8_nameCaptureInfo = NULL;
  c8_nameCaptureInfo = NULL;
  c8_info_helper(c8_info);
  sf_mex_assign(&c8_m0, sf_mex_createstruct("nameCaptureInfo", 1, 15), FALSE);
  for (c8_i5 = 0; c8_i5 < 15; c8_i5++) {
    c8_r0 = &c8_info[c8_i5];
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", c8_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c8_r0->context)), "context", "nameCaptureInfo",
                    c8_i5);
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", c8_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c8_r0->name)), "name", "nameCaptureInfo", c8_i5);
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", c8_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c8_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c8_i5);
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", c8_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c8_r0->resolved)), "resolved", "nameCaptureInfo",
                    c8_i5);
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", &c8_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c8_i5);
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", &c8_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c8_i5);
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", &c8_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c8_i5);
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", &c8_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c8_i5);
  }

  sf_mex_assign(&c8_nameCaptureInfo, c8_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c8_nameCaptureInfo);
  return c8_nameCaptureInfo;
}

static void c8_info_helper(c8_ResolvedFunctionInfo c8_info[15])
{
  c8_info[0].context = "";
  c8_info[0].name = "mrdivide";
  c8_info[0].dominantType = "double";
  c8_info[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c8_info[0].fileTimeLo = 1357951548U;
  c8_info[0].fileTimeHi = 0U;
  c8_info[0].mFileTimeLo = 1319729966U;
  c8_info[0].mFileTimeHi = 0U;
  c8_info[1].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c8_info[1].name = "rdivide";
  c8_info[1].dominantType = "double";
  c8_info[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c8_info[1].fileTimeLo = 1346510388U;
  c8_info[1].fileTimeHi = 0U;
  c8_info[1].mFileTimeLo = 0U;
  c8_info[1].mFileTimeHi = 0U;
  c8_info[2].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c8_info[2].name = "eml_scalexp_compatible";
  c8_info[2].dominantType = "double";
  c8_info[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m";
  c8_info[2].fileTimeLo = 1286818796U;
  c8_info[2].fileTimeHi = 0U;
  c8_info[2].mFileTimeLo = 0U;
  c8_info[2].mFileTimeHi = 0U;
  c8_info[3].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c8_info[3].name = "eml_div";
  c8_info[3].dominantType = "double";
  c8_info[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c8_info[3].fileTimeLo = 1313347810U;
  c8_info[3].fileTimeHi = 0U;
  c8_info[3].mFileTimeLo = 0U;
  c8_info[3].mFileTimeHi = 0U;
  c8_info[4].context = "";
  c8_info[4].name = "mtimes";
  c8_info[4].dominantType = "double";
  c8_info[4].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c8_info[4].fileTimeLo = 1289519692U;
  c8_info[4].fileTimeHi = 0U;
  c8_info[4].mFileTimeLo = 0U;
  c8_info[4].mFileTimeHi = 0U;
  c8_info[5].context = "";
  c8_info[5].name = "exp";
  c8_info[5].dominantType = "double";
  c8_info[5].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/exp.m";
  c8_info[5].fileTimeLo = 1343830380U;
  c8_info[5].fileTimeHi = 0U;
  c8_info[5].mFileTimeLo = 0U;
  c8_info[5].mFileTimeHi = 0U;
  c8_info[6].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/exp.m";
  c8_info[6].name = "eml_scalar_exp";
  c8_info[6].dominantType = "double";
  c8_info[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_exp.m";
  c8_info[6].fileTimeLo = 1301328464U;
  c8_info[6].fileTimeHi = 0U;
  c8_info[6].mFileTimeLo = 0U;
  c8_info[6].mFileTimeHi = 0U;
  c8_info[7].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_exp.m";
  c8_info[7].name = "mrdivide";
  c8_info[7].dominantType = "double";
  c8_info[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c8_info[7].fileTimeLo = 1357951548U;
  c8_info[7].fileTimeHi = 0U;
  c8_info[7].mFileTimeLo = 1319729966U;
  c8_info[7].mFileTimeHi = 0U;
  c8_info[8].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m!eml_fldiv";
  c8_info[8].name = "eml_scalar_eg";
  c8_info[8].dominantType = "double";
  c8_info[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c8_info[8].fileTimeLo = 1286818796U;
  c8_info[8].fileTimeHi = 0U;
  c8_info[8].mFileTimeLo = 0U;
  c8_info[8].mFileTimeHi = 0U;
  c8_info[9].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m!eml_fldiv";
  c8_info[9].name = "eml_scalexp_alloc";
  c8_info[9].dominantType = "double";
  c8_info[9].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c8_info[9].fileTimeLo = 1352424860U;
  c8_info[9].fileTimeHi = 0U;
  c8_info[9].mFileTimeLo = 0U;
  c8_info[9].mFileTimeHi = 0U;
  c8_info[10].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m!eml_fldiv";
  c8_info[10].name = "abs";
  c8_info[10].dominantType = "double";
  c8_info[10].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c8_info[10].fileTimeLo = 1343830366U;
  c8_info[10].fileTimeHi = 0U;
  c8_info[10].mFileTimeLo = 0U;
  c8_info[10].mFileTimeHi = 0U;
  c8_info[11].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c8_info[11].name = "eml_scalar_abs";
  c8_info[11].dominantType = "double";
  c8_info[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c8_info[11].fileTimeLo = 1286818712U;
  c8_info[11].fileTimeHi = 0U;
  c8_info[11].mFileTimeLo = 0U;
  c8_info[11].mFileTimeHi = 0U;
  c8_info[12].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m!eml_fldiv";
  c8_info[12].name = "mtimes";
  c8_info[12].dominantType = "double";
  c8_info[12].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c8_info[12].fileTimeLo = 1289519692U;
  c8_info[12].fileTimeHi = 0U;
  c8_info[12].mFileTimeLo = 0U;
  c8_info[12].mFileTimeHi = 0U;
  c8_info[13].context = "";
  c8_info[13].name = "abs";
  c8_info[13].dominantType = "double";
  c8_info[13].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c8_info[13].fileTimeLo = 1343830366U;
  c8_info[13].fileTimeHi = 0U;
  c8_info[13].mFileTimeLo = 0U;
  c8_info[13].mFileTimeHi = 0U;
  c8_info[14].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c8_info[14].name = "eml_dlapy2";
  c8_info[14].dominantType = "double";
  c8_info[14].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_dlapy2.m";
  c8_info[14].fileTimeLo = 1350410654U;
  c8_info[14].fileTimeHi = 0U;
  c8_info[14].mFileTimeLo = 0U;
  c8_info[14].mFileTimeHi = 0U;
}

static const mxArray *c8_d_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  int32_T c8_u;
  const mxArray *c8_y = NULL;
  SFc8_Symmetry_Inverter_imaginedInstanceStruct *chartInstance;
  chartInstance = (SFc8_Symmetry_Inverter_imaginedInstanceStruct *)
    chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  c8_u = *(int32_T *)c8_inData;
  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", &c8_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, FALSE);
  return c8_mxArrayOutData;
}

static int32_T c8_e_emlrt_marshallIn
  (SFc8_Symmetry_Inverter_imaginedInstanceStruct *chartInstance, const mxArray
   *c8_u, const emlrtMsgIdentifier *c8_parentId)
{
  int32_T c8_y;
  int32_T c8_i6;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_u), &c8_i6, 1, 6, 0U, 0, 0U, 0);
  c8_y = c8_i6;
  sf_mex_destroy(&c8_u);
  return c8_y;
}

static void c8_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData)
{
  const mxArray *c8_b_sfEvent;
  const char_T *c8_identifier;
  emlrtMsgIdentifier c8_thisId;
  int32_T c8_y;
  SFc8_Symmetry_Inverter_imaginedInstanceStruct *chartInstance;
  chartInstance = (SFc8_Symmetry_Inverter_imaginedInstanceStruct *)
    chartInstanceVoid;
  c8_b_sfEvent = sf_mex_dup(c8_mxArrayInData);
  c8_identifier = c8_varName;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_y = c8_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_b_sfEvent),
    &c8_thisId);
  sf_mex_destroy(&c8_b_sfEvent);
  *(int32_T *)c8_outData = c8_y;
  sf_mex_destroy(&c8_mxArrayInData);
}

static uint8_T c8_f_emlrt_marshallIn
  (SFc8_Symmetry_Inverter_imaginedInstanceStruct *chartInstance, const mxArray
   *c8_b_is_active_c8_Symmetry_Inverter_imagined, const char_T *c8_identifier)
{
  uint8_T c8_y;
  emlrtMsgIdentifier c8_thisId;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_y = c8_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c8_b_is_active_c8_Symmetry_Inverter_imagined), &c8_thisId);
  sf_mex_destroy(&c8_b_is_active_c8_Symmetry_Inverter_imagined);
  return c8_y;
}

static uint8_T c8_g_emlrt_marshallIn
  (SFc8_Symmetry_Inverter_imaginedInstanceStruct *chartInstance, const mxArray
   *c8_u, const emlrtMsgIdentifier *c8_parentId)
{
  uint8_T c8_y;
  uint8_T c8_u0;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_u), &c8_u0, 1, 3, 0U, 0, 0U, 0);
  c8_y = c8_u0;
  sf_mex_destroy(&c8_u);
  return c8_y;
}

static void init_dsm_address_info(SFc8_Symmetry_Inverter_imaginedInstanceStruct *
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

void sf_c8_Symmetry_Inverter_imagined_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2754256776U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(720275184U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(4163504516U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1130408971U);
}

mxArray *sf_c8_Symmetry_Inverter_imagined_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("vbdsglYUmIekFE7YB94w8E");
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

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c8_Symmetry_Inverter_imagined_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c8_Symmetry_Inverter_imagined(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[11],T\"Mean\",},{M[1],M[5],T\"VEC_norm\",},{M[8],M[0],T\"is_active_c8_Symmetry_Inverter_imagined\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c8_Symmetry_Inverter_imagined_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc8_Symmetry_Inverter_imaginedInstanceStruct *chartInstance;
    chartInstance = (SFc8_Symmetry_Inverter_imaginedInstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Symmetry_Inverter_imaginedMachineNumber_,
           8,
           1,
           1,
           8,
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
          _SFD_SET_DATA_PROPS(1,2,0,1,"VEC_norm");
          _SFD_SET_DATA_PROPS(2,1,1,0,"amplitude_S");
          _SFD_SET_DATA_PROPS(3,1,1,0,"amplitude_T");
          _SFD_SET_DATA_PROPS(4,1,1,0,"phase_R");
          _SFD_SET_DATA_PROPS(5,1,1,0,"phase_S");
          _SFD_SET_DATA_PROPS(6,1,1,0,"phase_T");
          _SFD_SET_DATA_PROPS(7,2,0,1,"Mean");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,641);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_sf_marshallOut,(MexInFcnForType)c8_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_sf_marshallOut,(MexInFcnForType)c8_sf_marshallIn);

        {
          real_T *c8_amplitude_R;
          real_T *c8_VEC_norm;
          real_T *c8_amplitude_S;
          real_T *c8_amplitude_T;
          real_T *c8_phase_R;
          real_T *c8_phase_S;
          real_T *c8_phase_T;
          real_T *c8_Mean;
          c8_Mean = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c8_phase_T = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
          c8_phase_S = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
          c8_phase_R = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c8_amplitude_T = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c8_amplitude_S = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c8_VEC_norm = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c8_amplitude_R = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c8_amplitude_R);
          _SFD_SET_DATA_VALUE_PTR(1U, c8_VEC_norm);
          _SFD_SET_DATA_VALUE_PTR(2U, c8_amplitude_S);
          _SFD_SET_DATA_VALUE_PTR(3U, c8_amplitude_T);
          _SFD_SET_DATA_VALUE_PTR(4U, c8_phase_R);
          _SFD_SET_DATA_VALUE_PTR(5U, c8_phase_S);
          _SFD_SET_DATA_VALUE_PTR(6U, c8_phase_T);
          _SFD_SET_DATA_VALUE_PTR(7U, c8_Mean);
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
  return "BZmX4e5JM53lEE94Qlkg7B";
}

static void sf_opaque_initialize_c8_Symmetry_Inverter_imagined(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc8_Symmetry_Inverter_imaginedInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c8_Symmetry_Inverter_imagined
    ((SFc8_Symmetry_Inverter_imaginedInstanceStruct*) chartInstanceVar);
  initialize_c8_Symmetry_Inverter_imagined
    ((SFc8_Symmetry_Inverter_imaginedInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c8_Symmetry_Inverter_imagined(void
  *chartInstanceVar)
{
  enable_c8_Symmetry_Inverter_imagined
    ((SFc8_Symmetry_Inverter_imaginedInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c8_Symmetry_Inverter_imagined(void
  *chartInstanceVar)
{
  disable_c8_Symmetry_Inverter_imagined
    ((SFc8_Symmetry_Inverter_imaginedInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c8_Symmetry_Inverter_imagined(void
  *chartInstanceVar)
{
  sf_c8_Symmetry_Inverter_imagined
    ((SFc8_Symmetry_Inverter_imaginedInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c8_Symmetry_Inverter_imagined
  (SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c8_Symmetry_Inverter_imagined
    ((SFc8_Symmetry_Inverter_imaginedInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c8_Symmetry_Inverter_imagined();/* state var info */
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

extern void sf_internal_set_sim_state_c8_Symmetry_Inverter_imagined(SimStruct* S,
  const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c8_Symmetry_Inverter_imagined();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c8_Symmetry_Inverter_imagined
    ((SFc8_Symmetry_Inverter_imaginedInstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c8_Symmetry_Inverter_imagined
  (SimStruct* S)
{
  return sf_internal_get_sim_state_c8_Symmetry_Inverter_imagined(S);
}

static void sf_opaque_set_sim_state_c8_Symmetry_Inverter_imagined(SimStruct* S,
  const mxArray *st)
{
  sf_internal_set_sim_state_c8_Symmetry_Inverter_imagined(S, st);
}

static void sf_opaque_terminate_c8_Symmetry_Inverter_imagined(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc8_Symmetry_Inverter_imaginedInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Symmetry_Inverter_imagined_optimization_info();
    }

    finalize_c8_Symmetry_Inverter_imagined
      ((SFc8_Symmetry_Inverter_imaginedInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc8_Symmetry_Inverter_imagined
    ((SFc8_Symmetry_Inverter_imaginedInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c8_Symmetry_Inverter_imagined(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c8_Symmetry_Inverter_imagined
      ((SFc8_Symmetry_Inverter_imaginedInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c8_Symmetry_Inverter_imagined(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Symmetry_Inverter_imagined_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      8);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,8,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,8,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,8);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,8,6);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,8,2);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=2; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 6; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,8);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1362677024U));
  ssSetChecksum1(S,(3422631075U));
  ssSetChecksum2(S,(1500057508U));
  ssSetChecksum3(S,(77389931U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c8_Symmetry_Inverter_imagined(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c8_Symmetry_Inverter_imagined(SimStruct *S)
{
  SFc8_Symmetry_Inverter_imaginedInstanceStruct *chartInstance;
  chartInstance = (SFc8_Symmetry_Inverter_imaginedInstanceStruct *)utMalloc
    (sizeof(SFc8_Symmetry_Inverter_imaginedInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc8_Symmetry_Inverter_imaginedInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c8_Symmetry_Inverter_imagined;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c8_Symmetry_Inverter_imagined;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c8_Symmetry_Inverter_imagined;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c8_Symmetry_Inverter_imagined;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c8_Symmetry_Inverter_imagined;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c8_Symmetry_Inverter_imagined;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c8_Symmetry_Inverter_imagined;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c8_Symmetry_Inverter_imagined;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c8_Symmetry_Inverter_imagined;
  chartInstance->chartInfo.mdlStart = mdlStart_c8_Symmetry_Inverter_imagined;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c8_Symmetry_Inverter_imagined;
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

void c8_Symmetry_Inverter_imagined_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c8_Symmetry_Inverter_imagined(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c8_Symmetry_Inverter_imagined(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c8_Symmetry_Inverter_imagined(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c8_Symmetry_Inverter_imagined_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
