/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Symmetry_Inverter_imagined_sfun.h"
#include "c7_Symmetry_Inverter_imagined.h"
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
static const char * c7_debug_family_names[14] = { "N", "V_real", "R_error",
  "S_error", "T_error", "nargin", "nargout", "amplitude_R", "amplitude_S",
  "amplitude_T", "phase_R", "phase_S", "phase_T", "VEC_norm" };

/* Function Declarations */
static void initialize_c7_Symmetry_Inverter_imagined
  (SFc7_Symmetry_Inverter_imaginedInstanceStruct *chartInstance);
static void initialize_params_c7_Symmetry_Inverter_imagined
  (SFc7_Symmetry_Inverter_imaginedInstanceStruct *chartInstance);
static void enable_c7_Symmetry_Inverter_imagined
  (SFc7_Symmetry_Inverter_imaginedInstanceStruct *chartInstance);
static void disable_c7_Symmetry_Inverter_imagined
  (SFc7_Symmetry_Inverter_imaginedInstanceStruct *chartInstance);
static void c7_update_debugger_state_c7_Symmetry_Inverter_imagined
  (SFc7_Symmetry_Inverter_imaginedInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c7_Symmetry_Inverter_imagined
  (SFc7_Symmetry_Inverter_imaginedInstanceStruct *chartInstance);
static void set_sim_state_c7_Symmetry_Inverter_imagined
  (SFc7_Symmetry_Inverter_imaginedInstanceStruct *chartInstance, const mxArray
   *c7_st);
static void finalize_c7_Symmetry_Inverter_imagined
  (SFc7_Symmetry_Inverter_imaginedInstanceStruct *chartInstance);
static void sf_c7_Symmetry_Inverter_imagined
  (SFc7_Symmetry_Inverter_imaginedInstanceStruct *chartInstance);
static void initSimStructsc7_Symmetry_Inverter_imagined
  (SFc7_Symmetry_Inverter_imaginedInstanceStruct *chartInstance);
static void registerMessagesc7_Symmetry_Inverter_imagined
  (SFc7_Symmetry_Inverter_imaginedInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c7_machineNumber, uint32_T
  c7_chartNumber);
static const mxArray *c7_sf_marshallOut(void *chartInstanceVoid, void *c7_inData);
static real_T c7_emlrt_marshallIn(SFc7_Symmetry_Inverter_imaginedInstanceStruct *
  chartInstance, const mxArray *c7_VEC_norm, const char_T *c7_identifier);
static real_T c7_b_emlrt_marshallIn
  (SFc7_Symmetry_Inverter_imaginedInstanceStruct *chartInstance, const mxArray
   *c7_u, const emlrtMsgIdentifier *c7_parentId);
static void c7_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData);
static const mxArray *c7_b_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static creal_T c7_c_emlrt_marshallIn
  (SFc7_Symmetry_Inverter_imaginedInstanceStruct *chartInstance, const mxArray
   *c7_u, const emlrtMsgIdentifier *c7_parentId);
static void c7_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData);
static const mxArray *c7_c_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static void c7_d_emlrt_marshallIn(SFc7_Symmetry_Inverter_imaginedInstanceStruct *
  chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId,
  creal_T c7_y[3]);
static void c7_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData);
static void c7_info_helper(c7_ResolvedFunctionInfo c7_info[15]);
static const mxArray *c7_d_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static int32_T c7_e_emlrt_marshallIn
  (SFc7_Symmetry_Inverter_imaginedInstanceStruct *chartInstance, const mxArray
   *c7_u, const emlrtMsgIdentifier *c7_parentId);
static void c7_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData);
static uint8_T c7_f_emlrt_marshallIn
  (SFc7_Symmetry_Inverter_imaginedInstanceStruct *chartInstance, const mxArray
   *c7_b_is_active_c7_Symmetry_Inverter_imagined, const char_T *c7_identifier);
static uint8_T c7_g_emlrt_marshallIn
  (SFc7_Symmetry_Inverter_imaginedInstanceStruct *chartInstance, const mxArray
   *c7_u, const emlrtMsgIdentifier *c7_parentId);
static void init_dsm_address_info(SFc7_Symmetry_Inverter_imaginedInstanceStruct *
  chartInstance);

/* Function Definitions */
static void initialize_c7_Symmetry_Inverter_imagined
  (SFc7_Symmetry_Inverter_imaginedInstanceStruct *chartInstance)
{
  chartInstance->c7_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c7_is_active_c7_Symmetry_Inverter_imagined = 0U;
}

static void initialize_params_c7_Symmetry_Inverter_imagined
  (SFc7_Symmetry_Inverter_imaginedInstanceStruct *chartInstance)
{
}

static void enable_c7_Symmetry_Inverter_imagined
  (SFc7_Symmetry_Inverter_imaginedInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c7_Symmetry_Inverter_imagined
  (SFc7_Symmetry_Inverter_imaginedInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c7_update_debugger_state_c7_Symmetry_Inverter_imagined
  (SFc7_Symmetry_Inverter_imaginedInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c7_Symmetry_Inverter_imagined
  (SFc7_Symmetry_Inverter_imaginedInstanceStruct *chartInstance)
{
  const mxArray *c7_st;
  const mxArray *c7_y = NULL;
  real_T c7_hoistedGlobal;
  real_T c7_u;
  const mxArray *c7_b_y = NULL;
  uint8_T c7_b_hoistedGlobal;
  uint8_T c7_b_u;
  const mxArray *c7_c_y = NULL;
  real_T *c7_VEC_norm;
  c7_VEC_norm = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c7_st = NULL;
  c7_st = NULL;
  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_createcellarray(2), FALSE);
  c7_hoistedGlobal = *c7_VEC_norm;
  c7_u = c7_hoistedGlobal;
  c7_b_y = NULL;
  sf_mex_assign(&c7_b_y, sf_mex_create("y", &c7_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c7_y, 0, c7_b_y);
  c7_b_hoistedGlobal = chartInstance->c7_is_active_c7_Symmetry_Inverter_imagined;
  c7_b_u = c7_b_hoistedGlobal;
  c7_c_y = NULL;
  sf_mex_assign(&c7_c_y, sf_mex_create("y", &c7_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c7_y, 1, c7_c_y);
  sf_mex_assign(&c7_st, c7_y, FALSE);
  return c7_st;
}

static void set_sim_state_c7_Symmetry_Inverter_imagined
  (SFc7_Symmetry_Inverter_imaginedInstanceStruct *chartInstance, const mxArray
   *c7_st)
{
  const mxArray *c7_u;
  real_T *c7_VEC_norm;
  c7_VEC_norm = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c7_doneDoubleBufferReInit = TRUE;
  c7_u = sf_mex_dup(c7_st);
  *c7_VEC_norm = c7_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c7_u, 0)), "VEC_norm");
  chartInstance->c7_is_active_c7_Symmetry_Inverter_imagined =
    c7_f_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c7_u, 1)),
    "is_active_c7_Symmetry_Inverter_imagined");
  sf_mex_destroy(&c7_u);
  c7_update_debugger_state_c7_Symmetry_Inverter_imagined(chartInstance);
  sf_mex_destroy(&c7_st);
}

static void finalize_c7_Symmetry_Inverter_imagined
  (SFc7_Symmetry_Inverter_imaginedInstanceStruct *chartInstance)
{
}

static void sf_c7_Symmetry_Inverter_imagined
  (SFc7_Symmetry_Inverter_imaginedInstanceStruct *chartInstance)
{
  real_T c7_hoistedGlobal;
  real_T c7_b_hoistedGlobal;
  real_T c7_c_hoistedGlobal;
  real_T c7_d_hoistedGlobal;
  real_T c7_e_hoistedGlobal;
  real_T c7_f_hoistedGlobal;
  real_T c7_amplitude_R;
  real_T c7_amplitude_S;
  real_T c7_amplitude_T;
  real_T c7_phase_R;
  real_T c7_phase_S;
  real_T c7_phase_T;
  uint32_T c7_debug_family_var_map[14];
  creal_T c7_N;
  creal_T c7_V_real[3];
  creal_T c7_R_error;
  creal_T c7_S_error;
  creal_T c7_T_error;
  real_T c7_nargin = 6.0;
  real_T c7_nargout = 1.0;
  real_T c7_VEC_norm;
  static creal_T c7_dc0 = { 0.0, 0.0 };

  int32_T c7_i0;
  real_T c7_b;
  static creal_T c7_dc1 = { 0.0, 1.0 };

  creal_T c7_y;
  real_T c7_A;
  real_T c7_x;
  real_T c7_b_x;
  real_T c7_b_y;
  real_T c7_r;
  creal_T c7_c_y;
  creal_T c7_d_y;
  real_T c7_b_b;
  real_T c7_b_A;
  real_T c7_c_x;
  real_T c7_d_x;
  real_T c7_e_y;
  real_T c7_b_r;
  creal_T c7_f_y;
  creal_T c7_g_y;
  real_T c7_c_b;
  real_T c7_c_A;
  real_T c7_e_x;
  real_T c7_f_x;
  real_T c7_h_y;
  real_T c7_c_r;
  creal_T c7_i_y;
  creal_T c7_j_y;
  static creal_T c7_dc2 = { 230.0, 0.0 };

  static creal_T c7_dc3 = { -114.99999999999994, -199.18584287042091 };

  static creal_T c7_dc4 = { -115.0000000000001, 199.18584287042086 };

  creal_T c7_d_b;
  creal_T c7_k_y;
  real_T c7_x1;
  real_T c7_x2;
  real_T c7_a;
  real_T c7_e_b;
  real_T c7_l_y;
  creal_T c7_m_y;
  real_T c7_b_x1;
  real_T c7_b_x2;
  real_T c7_b_a;
  real_T c7_f_b;
  real_T c7_n_y;
  creal_T c7_o_y;
  real_T c7_c_x1;
  real_T c7_c_x2;
  real_T c7_c_a;
  real_T c7_g_b;
  real_T c7_p_y;
  real_T *c7_b_phase_T;
  real_T *c7_b_phase_S;
  real_T *c7_b_phase_R;
  real_T *c7_b_amplitude_T;
  real_T *c7_b_amplitude_S;
  real_T *c7_b_amplitude_R;
  real_T *c7_b_VEC_norm;
  c7_b_phase_T = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c7_b_phase_S = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c7_b_phase_R = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c7_b_amplitude_T = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c7_b_amplitude_S = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c7_b_VEC_norm = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c7_b_amplitude_R = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 6U, chartInstance->c7_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c7_b_amplitude_R, 0U);
  _SFD_DATA_RANGE_CHECK(*c7_b_VEC_norm, 1U);
  _SFD_DATA_RANGE_CHECK(*c7_b_amplitude_S, 2U);
  _SFD_DATA_RANGE_CHECK(*c7_b_amplitude_T, 3U);
  _SFD_DATA_RANGE_CHECK(*c7_b_phase_R, 4U);
  _SFD_DATA_RANGE_CHECK(*c7_b_phase_S, 5U);
  _SFD_DATA_RANGE_CHECK(*c7_b_phase_T, 6U);
  chartInstance->c7_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 6U, chartInstance->c7_sfEvent);
  c7_hoistedGlobal = *c7_b_amplitude_R;
  c7_b_hoistedGlobal = *c7_b_amplitude_S;
  c7_c_hoistedGlobal = *c7_b_amplitude_T;
  c7_d_hoistedGlobal = *c7_b_phase_R;
  c7_e_hoistedGlobal = *c7_b_phase_S;
  c7_f_hoistedGlobal = *c7_b_phase_T;
  c7_amplitude_R = c7_hoistedGlobal;
  c7_amplitude_S = c7_b_hoistedGlobal;
  c7_amplitude_T = c7_c_hoistedGlobal;
  c7_phase_R = c7_d_hoistedGlobal;
  c7_phase_S = c7_e_hoistedGlobal;
  c7_phase_T = c7_f_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 14U, 14U, c7_debug_family_names,
    c7_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_N, 0U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_V_real, 1U, c7_c_sf_marshallOut,
    c7_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_R_error, 2U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_S_error, 3U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_T_error, 4U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargin, 5U, c7_sf_marshallOut,
    c7_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargout, 6U, c7_sf_marshallOut,
    c7_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c7_amplitude_R, 7U, c7_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c7_amplitude_S, 8U, c7_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c7_amplitude_T, 9U, c7_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c7_phase_R, 10U, c7_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c7_phase_S, 11U, c7_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c7_phase_T, 12U, c7_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_VEC_norm, 13U, c7_sf_marshallOut,
    c7_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 5);
  c7_N = c7_dc0;
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 6);
  for (c7_i0 = 0; c7_i0 < 3; c7_i0++) {
    c7_V_real[c7_i0].re = 0.0;
    c7_V_real[c7_i0].im = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 8);
  c7_b = c7_phase_R;
  c7_y.re = c7_b * c7_dc1.re;
  c7_y.im = c7_b * c7_dc1.im;
  c7_A = c7_y.re;
  c7_x = c7_A;
  c7_b_x = c7_x;
  c7_b_y = c7_b_x / 2.0;
  c7_r = muDoubleScalarExp(c7_b_y);
  c7_c_y = c7_y;
  c7_d_y = c7_y;
  c7_y.re = c7_r * (c7_r * muDoubleScalarCos(c7_c_y.im));
  c7_y.im = c7_r * (c7_r * muDoubleScalarSin(c7_d_y.im));
  c7_V_real[0].re = c7_amplitude_R * c7_y.re;
  c7_V_real[0].im = c7_amplitude_R * c7_y.im;
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 9);
  c7_b_b = c7_phase_S;
  c7_y.re = c7_b_b * c7_dc1.re;
  c7_y.im = c7_b_b * c7_dc1.im;
  c7_b_A = c7_y.re;
  c7_c_x = c7_b_A;
  c7_d_x = c7_c_x;
  c7_e_y = c7_d_x / 2.0;
  c7_b_r = muDoubleScalarExp(c7_e_y);
  c7_f_y = c7_y;
  c7_g_y = c7_y;
  c7_y.re = c7_b_r * (c7_b_r * muDoubleScalarCos(c7_f_y.im));
  c7_y.im = c7_b_r * (c7_b_r * muDoubleScalarSin(c7_g_y.im));
  c7_V_real[1].re = c7_amplitude_S * c7_y.re;
  c7_V_real[1].im = c7_amplitude_S * c7_y.im;
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 10);
  c7_c_b = c7_phase_T;
  c7_y.re = c7_c_b * c7_dc1.re;
  c7_y.im = c7_c_b * c7_dc1.im;
  c7_c_A = c7_y.re;
  c7_e_x = c7_c_A;
  c7_f_x = c7_e_x;
  c7_h_y = c7_f_x / 2.0;
  c7_c_r = muDoubleScalarExp(c7_h_y);
  c7_i_y = c7_y;
  c7_j_y = c7_y;
  c7_y.re = c7_c_r * (c7_c_r * muDoubleScalarCos(c7_i_y.im));
  c7_y.im = c7_c_r * (c7_c_r * muDoubleScalarSin(c7_j_y.im));
  c7_V_real[2].re = c7_amplitude_T * c7_y.re;
  c7_V_real[2].im = c7_amplitude_T * c7_y.im;
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 12);
  c7_R_error.re = c7_dc2.re - c7_V_real[0].re;
  c7_R_error.im = c7_dc2.im - c7_V_real[0].im;
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 13);
  c7_S_error.re = c7_dc3.re - c7_V_real[1].re;
  c7_S_error.im = c7_dc3.im - c7_V_real[1].im;
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 14);
  c7_T_error.re = c7_dc4.re - c7_V_real[2].re;
  c7_T_error.im = c7_dc4.im - c7_V_real[2].im;
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 15);
  c7_y = c7_R_error;
  c7_d_b = c7_S_error;
  c7_k_y = c7_y;
  c7_y.re = c7_k_y.re * c7_d_b.re - c7_k_y.im * c7_d_b.im;
  c7_y.im = c7_k_y.re * c7_d_b.im + c7_k_y.im * c7_d_b.re;
  c7_x1 = c7_y.re;
  c7_x2 = c7_y.im;
  c7_a = c7_x1;
  c7_e_b = c7_x2;
  c7_l_y = muDoubleScalarHypot(c7_a, c7_e_b);
  c7_y = c7_R_error;
  c7_d_b = c7_T_error;
  c7_m_y = c7_y;
  c7_y.re = c7_m_y.re * c7_d_b.re - c7_m_y.im * c7_d_b.im;
  c7_y.im = c7_m_y.re * c7_d_b.im + c7_m_y.im * c7_d_b.re;
  c7_b_x1 = c7_y.re;
  c7_b_x2 = c7_y.im;
  c7_b_a = c7_b_x1;
  c7_f_b = c7_b_x2;
  c7_n_y = muDoubleScalarHypot(c7_b_a, c7_f_b);
  c7_y = c7_S_error;
  c7_d_b = c7_T_error;
  c7_o_y = c7_y;
  c7_y.re = c7_o_y.re * c7_d_b.re - c7_o_y.im * c7_d_b.im;
  c7_y.im = c7_o_y.re * c7_d_b.im + c7_o_y.im * c7_d_b.re;
  c7_c_x1 = c7_y.re;
  c7_c_x2 = c7_y.im;
  c7_c_a = c7_c_x1;
  c7_g_b = c7_c_x2;
  c7_p_y = muDoubleScalarHypot(c7_c_a, c7_g_b);
  c7_VEC_norm = (c7_l_y + c7_n_y) + c7_p_y;
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, -15);
  _SFD_SYMBOL_SCOPE_POP();
  *c7_b_VEC_norm = c7_VEC_norm;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 6U, chartInstance->c7_sfEvent);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_Symmetry_Inverter_imaginedMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc7_Symmetry_Inverter_imagined
  (SFc7_Symmetry_Inverter_imaginedInstanceStruct *chartInstance)
{
}

static void registerMessagesc7_Symmetry_Inverter_imagined
  (SFc7_Symmetry_Inverter_imaginedInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c7_machineNumber, uint32_T
  c7_chartNumber)
{
}

static const mxArray *c7_sf_marshallOut(void *chartInstanceVoid, void *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  real_T c7_u;
  const mxArray *c7_y = NULL;
  SFc7_Symmetry_Inverter_imaginedInstanceStruct *chartInstance;
  chartInstance = (SFc7_Symmetry_Inverter_imaginedInstanceStruct *)
    chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  c7_u = *(real_T *)c7_inData;
  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", &c7_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, FALSE);
  return c7_mxArrayOutData;
}

static real_T c7_emlrt_marshallIn(SFc7_Symmetry_Inverter_imaginedInstanceStruct *
  chartInstance, const mxArray *c7_VEC_norm, const char_T *c7_identifier)
{
  real_T c7_y;
  emlrtMsgIdentifier c7_thisId;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_y = c7_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_VEC_norm),
    &c7_thisId);
  sf_mex_destroy(&c7_VEC_norm);
  return c7_y;
}

static real_T c7_b_emlrt_marshallIn
  (SFc7_Symmetry_Inverter_imaginedInstanceStruct *chartInstance, const mxArray
   *c7_u, const emlrtMsgIdentifier *c7_parentId)
{
  real_T c7_y;
  real_T c7_d0;
  sf_mex_import(c7_parentId, sf_mex_dup(c7_u), &c7_d0, 1, 0, 0U, 0, 0U, 0);
  c7_y = c7_d0;
  sf_mex_destroy(&c7_u);
  return c7_y;
}

static void c7_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData)
{
  const mxArray *c7_VEC_norm;
  const char_T *c7_identifier;
  emlrtMsgIdentifier c7_thisId;
  real_T c7_y;
  SFc7_Symmetry_Inverter_imaginedInstanceStruct *chartInstance;
  chartInstance = (SFc7_Symmetry_Inverter_imaginedInstanceStruct *)
    chartInstanceVoid;
  c7_VEC_norm = sf_mex_dup(c7_mxArrayInData);
  c7_identifier = c7_varName;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_y = c7_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_VEC_norm),
    &c7_thisId);
  sf_mex_destroy(&c7_VEC_norm);
  *(real_T *)c7_outData = c7_y;
  sf_mex_destroy(&c7_mxArrayInData);
}

static const mxArray *c7_b_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  creal_T c7_u;
  const mxArray *c7_y = NULL;
  SFc7_Symmetry_Inverter_imaginedInstanceStruct *chartInstance;
  chartInstance = (SFc7_Symmetry_Inverter_imaginedInstanceStruct *)
    chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  c7_u = *(creal_T *)c7_inData;
  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", &c7_u, 0, 1U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, FALSE);
  return c7_mxArrayOutData;
}

static creal_T c7_c_emlrt_marshallIn
  (SFc7_Symmetry_Inverter_imaginedInstanceStruct *chartInstance, const mxArray
   *c7_u, const emlrtMsgIdentifier *c7_parentId)
{
  creal_T c7_y;
  creal_T c7_dc5;
  sf_mex_import(c7_parentId, sf_mex_dup(c7_u), &c7_dc5, 1, 0, 1U, 0, 0U, 0);
  c7_y = c7_dc5;
  sf_mex_destroy(&c7_u);
  return c7_y;
}

static void c7_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData)
{
  const mxArray *c7_T_error;
  const char_T *c7_identifier;
  emlrtMsgIdentifier c7_thisId;
  creal_T c7_y;
  SFc7_Symmetry_Inverter_imaginedInstanceStruct *chartInstance;
  chartInstance = (SFc7_Symmetry_Inverter_imaginedInstanceStruct *)
    chartInstanceVoid;
  c7_T_error = sf_mex_dup(c7_mxArrayInData);
  c7_identifier = c7_varName;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_y = c7_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_T_error), &c7_thisId);
  sf_mex_destroy(&c7_T_error);
  *(creal_T *)c7_outData = c7_y;
  sf_mex_destroy(&c7_mxArrayInData);
}

static const mxArray *c7_c_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_i1;
  creal_T c7_b_inData[3];
  int32_T c7_i2;
  creal_T c7_u[3];
  const mxArray *c7_y = NULL;
  SFc7_Symmetry_Inverter_imaginedInstanceStruct *chartInstance;
  chartInstance = (SFc7_Symmetry_Inverter_imaginedInstanceStruct *)
    chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  for (c7_i1 = 0; c7_i1 < 3; c7_i1++) {
    c7_b_inData[c7_i1] = (*(creal_T (*)[3])c7_inData)[c7_i1];
  }

  for (c7_i2 = 0; c7_i2 < 3; c7_i2++) {
    c7_u[c7_i2] = c7_b_inData[c7_i2];
  }

  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 0, 1U, 1U, 0U, 1, 3), FALSE);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, FALSE);
  return c7_mxArrayOutData;
}

static void c7_d_emlrt_marshallIn(SFc7_Symmetry_Inverter_imaginedInstanceStruct *
  chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId,
  creal_T c7_y[3])
{
  creal_T c7_dcv0[3];
  int32_T c7_i3;
  sf_mex_import(c7_parentId, sf_mex_dup(c7_u), c7_dcv0, 1, 0, 1U, 1, 0U, 1, 3);
  for (c7_i3 = 0; c7_i3 < 3; c7_i3++) {
    c7_y[c7_i3] = c7_dcv0[c7_i3];
  }

  sf_mex_destroy(&c7_u);
}

static void c7_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData)
{
  const mxArray *c7_V_real;
  const char_T *c7_identifier;
  emlrtMsgIdentifier c7_thisId;
  creal_T c7_y[3];
  int32_T c7_i4;
  SFc7_Symmetry_Inverter_imaginedInstanceStruct *chartInstance;
  chartInstance = (SFc7_Symmetry_Inverter_imaginedInstanceStruct *)
    chartInstanceVoid;
  c7_V_real = sf_mex_dup(c7_mxArrayInData);
  c7_identifier = c7_varName;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_V_real), &c7_thisId, c7_y);
  sf_mex_destroy(&c7_V_real);
  for (c7_i4 = 0; c7_i4 < 3; c7_i4++) {
    (*(creal_T (*)[3])c7_outData)[c7_i4] = c7_y[c7_i4];
  }

  sf_mex_destroy(&c7_mxArrayInData);
}

const mxArray *sf_c7_Symmetry_Inverter_imagined_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c7_nameCaptureInfo;
  c7_ResolvedFunctionInfo c7_info[15];
  const mxArray *c7_m0 = NULL;
  int32_T c7_i5;
  c7_ResolvedFunctionInfo *c7_r0;
  c7_nameCaptureInfo = NULL;
  c7_nameCaptureInfo = NULL;
  c7_info_helper(c7_info);
  sf_mex_assign(&c7_m0, sf_mex_createstruct("nameCaptureInfo", 1, 15), FALSE);
  for (c7_i5 = 0; c7_i5 < 15; c7_i5++) {
    c7_r0 = &c7_info[c7_i5];
    sf_mex_addfield(c7_m0, sf_mex_create("nameCaptureInfo", c7_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c7_r0->context)), "context", "nameCaptureInfo",
                    c7_i5);
    sf_mex_addfield(c7_m0, sf_mex_create("nameCaptureInfo", c7_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c7_r0->name)), "name", "nameCaptureInfo", c7_i5);
    sf_mex_addfield(c7_m0, sf_mex_create("nameCaptureInfo", c7_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c7_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c7_i5);
    sf_mex_addfield(c7_m0, sf_mex_create("nameCaptureInfo", c7_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c7_r0->resolved)), "resolved", "nameCaptureInfo",
                    c7_i5);
    sf_mex_addfield(c7_m0, sf_mex_create("nameCaptureInfo", &c7_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c7_i5);
    sf_mex_addfield(c7_m0, sf_mex_create("nameCaptureInfo", &c7_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c7_i5);
    sf_mex_addfield(c7_m0, sf_mex_create("nameCaptureInfo", &c7_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c7_i5);
    sf_mex_addfield(c7_m0, sf_mex_create("nameCaptureInfo", &c7_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c7_i5);
  }

  sf_mex_assign(&c7_nameCaptureInfo, c7_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c7_nameCaptureInfo);
  return c7_nameCaptureInfo;
}

static void c7_info_helper(c7_ResolvedFunctionInfo c7_info[15])
{
  c7_info[0].context = "";
  c7_info[0].name = "mtimes";
  c7_info[0].dominantType = "double";
  c7_info[0].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c7_info[0].fileTimeLo = 1289519692U;
  c7_info[0].fileTimeHi = 0U;
  c7_info[0].mFileTimeLo = 0U;
  c7_info[0].mFileTimeHi = 0U;
  c7_info[1].context = "";
  c7_info[1].name = "exp";
  c7_info[1].dominantType = "double";
  c7_info[1].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/exp.m";
  c7_info[1].fileTimeLo = 1343830380U;
  c7_info[1].fileTimeHi = 0U;
  c7_info[1].mFileTimeLo = 0U;
  c7_info[1].mFileTimeHi = 0U;
  c7_info[2].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/exp.m";
  c7_info[2].name = "eml_scalar_exp";
  c7_info[2].dominantType = "double";
  c7_info[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_exp.m";
  c7_info[2].fileTimeLo = 1301328464U;
  c7_info[2].fileTimeHi = 0U;
  c7_info[2].mFileTimeLo = 0U;
  c7_info[2].mFileTimeHi = 0U;
  c7_info[3].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_exp.m";
  c7_info[3].name = "mrdivide";
  c7_info[3].dominantType = "double";
  c7_info[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c7_info[3].fileTimeLo = 1357951548U;
  c7_info[3].fileTimeHi = 0U;
  c7_info[3].mFileTimeLo = 1319729966U;
  c7_info[3].mFileTimeHi = 0U;
  c7_info[4].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c7_info[4].name = "rdivide";
  c7_info[4].dominantType = "double";
  c7_info[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c7_info[4].fileTimeLo = 1346510388U;
  c7_info[4].fileTimeHi = 0U;
  c7_info[4].mFileTimeLo = 0U;
  c7_info[4].mFileTimeHi = 0U;
  c7_info[5].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c7_info[5].name = "eml_scalexp_compatible";
  c7_info[5].dominantType = "double";
  c7_info[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m";
  c7_info[5].fileTimeLo = 1286818796U;
  c7_info[5].fileTimeHi = 0U;
  c7_info[5].mFileTimeLo = 0U;
  c7_info[5].mFileTimeHi = 0U;
  c7_info[6].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c7_info[6].name = "eml_div";
  c7_info[6].dominantType = "double";
  c7_info[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c7_info[6].fileTimeLo = 1313347810U;
  c7_info[6].fileTimeHi = 0U;
  c7_info[6].mFileTimeLo = 0U;
  c7_info[6].mFileTimeHi = 0U;
  c7_info[7].context = "";
  c7_info[7].name = "mrdivide";
  c7_info[7].dominantType = "double";
  c7_info[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c7_info[7].fileTimeLo = 1357951548U;
  c7_info[7].fileTimeHi = 0U;
  c7_info[7].mFileTimeLo = 1319729966U;
  c7_info[7].mFileTimeHi = 0U;
  c7_info[8].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m!eml_fldiv";
  c7_info[8].name = "eml_scalar_eg";
  c7_info[8].dominantType = "double";
  c7_info[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c7_info[8].fileTimeLo = 1286818796U;
  c7_info[8].fileTimeHi = 0U;
  c7_info[8].mFileTimeLo = 0U;
  c7_info[8].mFileTimeHi = 0U;
  c7_info[9].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m!eml_fldiv";
  c7_info[9].name = "eml_scalexp_alloc";
  c7_info[9].dominantType = "double";
  c7_info[9].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c7_info[9].fileTimeLo = 1352424860U;
  c7_info[9].fileTimeHi = 0U;
  c7_info[9].mFileTimeLo = 0U;
  c7_info[9].mFileTimeHi = 0U;
  c7_info[10].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m!eml_fldiv";
  c7_info[10].name = "abs";
  c7_info[10].dominantType = "double";
  c7_info[10].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c7_info[10].fileTimeLo = 1343830366U;
  c7_info[10].fileTimeHi = 0U;
  c7_info[10].mFileTimeLo = 0U;
  c7_info[10].mFileTimeHi = 0U;
  c7_info[11].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c7_info[11].name = "eml_scalar_abs";
  c7_info[11].dominantType = "double";
  c7_info[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c7_info[11].fileTimeLo = 1286818712U;
  c7_info[11].fileTimeHi = 0U;
  c7_info[11].mFileTimeLo = 0U;
  c7_info[11].mFileTimeHi = 0U;
  c7_info[12].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m!eml_fldiv";
  c7_info[12].name = "mtimes";
  c7_info[12].dominantType = "double";
  c7_info[12].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c7_info[12].fileTimeLo = 1289519692U;
  c7_info[12].fileTimeHi = 0U;
  c7_info[12].mFileTimeLo = 0U;
  c7_info[12].mFileTimeHi = 0U;
  c7_info[13].context = "";
  c7_info[13].name = "abs";
  c7_info[13].dominantType = "double";
  c7_info[13].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c7_info[13].fileTimeLo = 1343830366U;
  c7_info[13].fileTimeHi = 0U;
  c7_info[13].mFileTimeLo = 0U;
  c7_info[13].mFileTimeHi = 0U;
  c7_info[14].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c7_info[14].name = "eml_dlapy2";
  c7_info[14].dominantType = "double";
  c7_info[14].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_dlapy2.m";
  c7_info[14].fileTimeLo = 1350410654U;
  c7_info[14].fileTimeHi = 0U;
  c7_info[14].mFileTimeLo = 0U;
  c7_info[14].mFileTimeHi = 0U;
}

static const mxArray *c7_d_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_u;
  const mxArray *c7_y = NULL;
  SFc7_Symmetry_Inverter_imaginedInstanceStruct *chartInstance;
  chartInstance = (SFc7_Symmetry_Inverter_imaginedInstanceStruct *)
    chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  c7_u = *(int32_T *)c7_inData;
  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", &c7_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, FALSE);
  return c7_mxArrayOutData;
}

static int32_T c7_e_emlrt_marshallIn
  (SFc7_Symmetry_Inverter_imaginedInstanceStruct *chartInstance, const mxArray
   *c7_u, const emlrtMsgIdentifier *c7_parentId)
{
  int32_T c7_y;
  int32_T c7_i6;
  sf_mex_import(c7_parentId, sf_mex_dup(c7_u), &c7_i6, 1, 6, 0U, 0, 0U, 0);
  c7_y = c7_i6;
  sf_mex_destroy(&c7_u);
  return c7_y;
}

static void c7_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData)
{
  const mxArray *c7_b_sfEvent;
  const char_T *c7_identifier;
  emlrtMsgIdentifier c7_thisId;
  int32_T c7_y;
  SFc7_Symmetry_Inverter_imaginedInstanceStruct *chartInstance;
  chartInstance = (SFc7_Symmetry_Inverter_imaginedInstanceStruct *)
    chartInstanceVoid;
  c7_b_sfEvent = sf_mex_dup(c7_mxArrayInData);
  c7_identifier = c7_varName;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_y = c7_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_b_sfEvent),
    &c7_thisId);
  sf_mex_destroy(&c7_b_sfEvent);
  *(int32_T *)c7_outData = c7_y;
  sf_mex_destroy(&c7_mxArrayInData);
}

static uint8_T c7_f_emlrt_marshallIn
  (SFc7_Symmetry_Inverter_imaginedInstanceStruct *chartInstance, const mxArray
   *c7_b_is_active_c7_Symmetry_Inverter_imagined, const char_T *c7_identifier)
{
  uint8_T c7_y;
  emlrtMsgIdentifier c7_thisId;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_y = c7_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c7_b_is_active_c7_Symmetry_Inverter_imagined), &c7_thisId);
  sf_mex_destroy(&c7_b_is_active_c7_Symmetry_Inverter_imagined);
  return c7_y;
}

static uint8_T c7_g_emlrt_marshallIn
  (SFc7_Symmetry_Inverter_imaginedInstanceStruct *chartInstance, const mxArray
   *c7_u, const emlrtMsgIdentifier *c7_parentId)
{
  uint8_T c7_y;
  uint8_T c7_u0;
  sf_mex_import(c7_parentId, sf_mex_dup(c7_u), &c7_u0, 1, 3, 0U, 0, 0U, 0);
  c7_y = c7_u0;
  sf_mex_destroy(&c7_u);
  return c7_y;
}

static void init_dsm_address_info(SFc7_Symmetry_Inverter_imaginedInstanceStruct *
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

void sf_c7_Symmetry_Inverter_imagined_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2519638725U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3740449667U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(696993200U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2599490740U);
}

mxArray *sf_c7_Symmetry_Inverter_imagined_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("LNAeo9Q4wRNhquAoEI3EYC");
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

mxArray *sf_c7_Symmetry_Inverter_imagined_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c7_Symmetry_Inverter_imagined(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"VEC_norm\",},{M[8],M[0],T\"is_active_c7_Symmetry_Inverter_imagined\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c7_Symmetry_Inverter_imagined_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc7_Symmetry_Inverter_imaginedInstanceStruct *chartInstance;
    chartInstance = (SFc7_Symmetry_Inverter_imaginedInstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Symmetry_Inverter_imaginedMachineNumber_,
           7,
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
          _SFD_SET_DATA_PROPS(1,2,0,1,"VEC_norm");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,579);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_sf_marshallOut,(MexInFcnForType)c7_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_sf_marshallOut,(MexInFcnForType)NULL);

        {
          real_T *c7_amplitude_R;
          real_T *c7_VEC_norm;
          real_T *c7_amplitude_S;
          real_T *c7_amplitude_T;
          real_T *c7_phase_R;
          real_T *c7_phase_S;
          real_T *c7_phase_T;
          c7_phase_T = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
          c7_phase_S = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
          c7_phase_R = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c7_amplitude_T = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c7_amplitude_S = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c7_VEC_norm = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c7_amplitude_R = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c7_amplitude_R);
          _SFD_SET_DATA_VALUE_PTR(1U, c7_VEC_norm);
          _SFD_SET_DATA_VALUE_PTR(2U, c7_amplitude_S);
          _SFD_SET_DATA_VALUE_PTR(3U, c7_amplitude_T);
          _SFD_SET_DATA_VALUE_PTR(4U, c7_phase_R);
          _SFD_SET_DATA_VALUE_PTR(5U, c7_phase_S);
          _SFD_SET_DATA_VALUE_PTR(6U, c7_phase_T);
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
  return "4XFENNFOFckTdyjHfR5Zd";
}

static void sf_opaque_initialize_c7_Symmetry_Inverter_imagined(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc7_Symmetry_Inverter_imaginedInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c7_Symmetry_Inverter_imagined
    ((SFc7_Symmetry_Inverter_imaginedInstanceStruct*) chartInstanceVar);
  initialize_c7_Symmetry_Inverter_imagined
    ((SFc7_Symmetry_Inverter_imaginedInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c7_Symmetry_Inverter_imagined(void
  *chartInstanceVar)
{
  enable_c7_Symmetry_Inverter_imagined
    ((SFc7_Symmetry_Inverter_imaginedInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c7_Symmetry_Inverter_imagined(void
  *chartInstanceVar)
{
  disable_c7_Symmetry_Inverter_imagined
    ((SFc7_Symmetry_Inverter_imaginedInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c7_Symmetry_Inverter_imagined(void
  *chartInstanceVar)
{
  sf_c7_Symmetry_Inverter_imagined
    ((SFc7_Symmetry_Inverter_imaginedInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c7_Symmetry_Inverter_imagined
  (SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c7_Symmetry_Inverter_imagined
    ((SFc7_Symmetry_Inverter_imaginedInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c7_Symmetry_Inverter_imagined();/* state var info */
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

extern void sf_internal_set_sim_state_c7_Symmetry_Inverter_imagined(SimStruct* S,
  const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c7_Symmetry_Inverter_imagined();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c7_Symmetry_Inverter_imagined
    ((SFc7_Symmetry_Inverter_imaginedInstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c7_Symmetry_Inverter_imagined
  (SimStruct* S)
{
  return sf_internal_get_sim_state_c7_Symmetry_Inverter_imagined(S);
}

static void sf_opaque_set_sim_state_c7_Symmetry_Inverter_imagined(SimStruct* S,
  const mxArray *st)
{
  sf_internal_set_sim_state_c7_Symmetry_Inverter_imagined(S, st);
}

static void sf_opaque_terminate_c7_Symmetry_Inverter_imagined(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc7_Symmetry_Inverter_imaginedInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Symmetry_Inverter_imagined_optimization_info();
    }

    finalize_c7_Symmetry_Inverter_imagined
      ((SFc7_Symmetry_Inverter_imaginedInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc7_Symmetry_Inverter_imagined
    ((SFc7_Symmetry_Inverter_imaginedInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c7_Symmetry_Inverter_imagined(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c7_Symmetry_Inverter_imagined
      ((SFc7_Symmetry_Inverter_imaginedInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c7_Symmetry_Inverter_imagined(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Symmetry_Inverter_imagined_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      7);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,7,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,7,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,7);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,7,6);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,7,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,7);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(571837600U));
  ssSetChecksum1(S,(2174660008U));
  ssSetChecksum2(S,(1377935646U));
  ssSetChecksum3(S,(2163581933U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c7_Symmetry_Inverter_imagined(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c7_Symmetry_Inverter_imagined(SimStruct *S)
{
  SFc7_Symmetry_Inverter_imaginedInstanceStruct *chartInstance;
  chartInstance = (SFc7_Symmetry_Inverter_imaginedInstanceStruct *)utMalloc
    (sizeof(SFc7_Symmetry_Inverter_imaginedInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc7_Symmetry_Inverter_imaginedInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c7_Symmetry_Inverter_imagined;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c7_Symmetry_Inverter_imagined;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c7_Symmetry_Inverter_imagined;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c7_Symmetry_Inverter_imagined;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c7_Symmetry_Inverter_imagined;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c7_Symmetry_Inverter_imagined;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c7_Symmetry_Inverter_imagined;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c7_Symmetry_Inverter_imagined;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c7_Symmetry_Inverter_imagined;
  chartInstance->chartInfo.mdlStart = mdlStart_c7_Symmetry_Inverter_imagined;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c7_Symmetry_Inverter_imagined;
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

void c7_Symmetry_Inverter_imagined_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c7_Symmetry_Inverter_imagined(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c7_Symmetry_Inverter_imagined(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c7_Symmetry_Inverter_imagined(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c7_Symmetry_Inverter_imagined_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
