/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Symmetry_Inverter_imagined_sfun.h"
#include "c6_Symmetry_Inverter_imagined.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Symmetry_Inverter_imagined_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c6_debug_family_names[22] = { "x1", "y1", "x2", "y2",
  "Amplitude_1", "Phase_1", "Amplitude_2", "Phase_2", "Amplitude_1_ex",
  "Phase_1_ex", "Amplitude_2_ex", "Phase_2_ex", "nargin", "nargout",
  "amplitude_R", "amplitude_S", "amplitude_T", "phase_R", "phase_S", "phase_T",
  "GEO_norm", "Mean" };

/* Function Declarations */
static void initialize_c6_Symmetry_Inverter_imagined
  (SFc6_Symmetry_Inverter_imaginedInstanceStruct *chartInstance);
static void initialize_params_c6_Symmetry_Inverter_imagined
  (SFc6_Symmetry_Inverter_imaginedInstanceStruct *chartInstance);
static void enable_c6_Symmetry_Inverter_imagined
  (SFc6_Symmetry_Inverter_imaginedInstanceStruct *chartInstance);
static void disable_c6_Symmetry_Inverter_imagined
  (SFc6_Symmetry_Inverter_imaginedInstanceStruct *chartInstance);
static void c6_update_debugger_state_c6_Symmetry_Inverter_imagined
  (SFc6_Symmetry_Inverter_imaginedInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c6_Symmetry_Inverter_imagined
  (SFc6_Symmetry_Inverter_imaginedInstanceStruct *chartInstance);
static void set_sim_state_c6_Symmetry_Inverter_imagined
  (SFc6_Symmetry_Inverter_imaginedInstanceStruct *chartInstance, const mxArray
   *c6_st);
static void finalize_c6_Symmetry_Inverter_imagined
  (SFc6_Symmetry_Inverter_imaginedInstanceStruct *chartInstance);
static void sf_gateway_c6_Symmetry_Inverter_imagined
  (SFc6_Symmetry_Inverter_imaginedInstanceStruct *chartInstance);
static void initSimStructsc6_Symmetry_Inverter_imagined
  (SFc6_Symmetry_Inverter_imaginedInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c6_machineNumber, uint32_T
  c6_chartNumber, uint32_T c6_instanceNumber);
static const mxArray *c6_sf_marshallOut(void *chartInstanceVoid, void *c6_inData);
static void c6_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static const mxArray *c6_b_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static void c6_emlrt_marshallIn(SFc6_Symmetry_Inverter_imaginedInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId,
  real_T c6_y[4]);
static void c6_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static const mxArray *c6_c_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static void c6_b_emlrt_marshallIn(SFc6_Symmetry_Inverter_imaginedInstanceStruct *
  chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId,
  real_T c6_y[3]);
static void c6_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static void c6_info_helper(const mxArray **c6_info);
static const mxArray *c6_emlrt_marshallOut(const char * c6_u);
static const mxArray *c6_b_emlrt_marshallOut(const uint32_T c6_u);
static real_T c6_c_emlrt_marshallIn
  (SFc6_Symmetry_Inverter_imaginedInstanceStruct *chartInstance, const mxArray
   *c6_geometry_solver, const char_T *c6_identifier);
static real_T c6_d_emlrt_marshallIn
  (SFc6_Symmetry_Inverter_imaginedInstanceStruct *chartInstance, const mxArray
   *c6_u, const emlrtMsgIdentifier *c6_parentId);
static const mxArray *c6_d_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static int32_T c6_e_emlrt_marshallIn
  (SFc6_Symmetry_Inverter_imaginedInstanceStruct *chartInstance, const mxArray
   *c6_u, const emlrtMsgIdentifier *c6_parentId);
static void c6_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static uint8_T c6_f_emlrt_marshallIn
  (SFc6_Symmetry_Inverter_imaginedInstanceStruct *chartInstance, const mxArray
   *c6_b_is_active_c6_Symmetry_Inverter_imagined, const char_T *c6_identifier);
static uint8_T c6_g_emlrt_marshallIn
  (SFc6_Symmetry_Inverter_imaginedInstanceStruct *chartInstance, const mxArray
   *c6_u, const emlrtMsgIdentifier *c6_parentId);
static void init_dsm_address_info(SFc6_Symmetry_Inverter_imaginedInstanceStruct *
  chartInstance);

/* Function Definitions */
static void initialize_c6_Symmetry_Inverter_imagined
  (SFc6_Symmetry_Inverter_imaginedInstanceStruct *chartInstance)
{
  chartInstance->c6_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c6_is_active_c6_Symmetry_Inverter_imagined = 0U;
}

static void initialize_params_c6_Symmetry_Inverter_imagined
  (SFc6_Symmetry_Inverter_imaginedInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c6_Symmetry_Inverter_imagined
  (SFc6_Symmetry_Inverter_imaginedInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c6_Symmetry_Inverter_imagined
  (SFc6_Symmetry_Inverter_imaginedInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c6_update_debugger_state_c6_Symmetry_Inverter_imagined
  (SFc6_Symmetry_Inverter_imaginedInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c6_Symmetry_Inverter_imagined
  (SFc6_Symmetry_Inverter_imaginedInstanceStruct *chartInstance)
{
  const mxArray *c6_st;
  const mxArray *c6_y = NULL;
  real_T c6_hoistedGlobal;
  real_T c6_u;
  const mxArray *c6_b_y = NULL;
  real_T c6_b_hoistedGlobal;
  real_T c6_b_u;
  const mxArray *c6_c_y = NULL;
  uint8_T c6_c_hoistedGlobal;
  uint8_T c6_c_u;
  const mxArray *c6_d_y = NULL;
  real_T *c6_GEO_norm;
  real_T *c6_Mean;
  c6_Mean = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c6_GEO_norm = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c6_st = NULL;
  c6_st = NULL;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_createcellmatrix(3, 1), false);
  c6_hoistedGlobal = *c6_GEO_norm;
  c6_u = c6_hoistedGlobal;
  c6_b_y = NULL;
  sf_mex_assign(&c6_b_y, sf_mex_create("y", &c6_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c6_y, 0, c6_b_y);
  c6_b_hoistedGlobal = *c6_Mean;
  c6_b_u = c6_b_hoistedGlobal;
  c6_c_y = NULL;
  sf_mex_assign(&c6_c_y, sf_mex_create("y", &c6_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c6_y, 1, c6_c_y);
  c6_c_hoistedGlobal = chartInstance->c6_is_active_c6_Symmetry_Inverter_imagined;
  c6_c_u = c6_c_hoistedGlobal;
  c6_d_y = NULL;
  sf_mex_assign(&c6_d_y, sf_mex_create("y", &c6_c_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c6_y, 2, c6_d_y);
  sf_mex_assign(&c6_st, c6_y, false);
  return c6_st;
}

static void set_sim_state_c6_Symmetry_Inverter_imagined
  (SFc6_Symmetry_Inverter_imaginedInstanceStruct *chartInstance, const mxArray
   *c6_st)
{
  const mxArray *c6_u;
  real_T *c6_GEO_norm;
  real_T *c6_Mean;
  c6_Mean = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c6_GEO_norm = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c6_doneDoubleBufferReInit = true;
  c6_u = sf_mex_dup(c6_st);
  *c6_GEO_norm = c6_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c6_u, 0)), "GEO_norm");
  *c6_Mean = c6_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c6_u,
    1)), "Mean");
  chartInstance->c6_is_active_c6_Symmetry_Inverter_imagined =
    c6_f_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c6_u, 2)),
    "is_active_c6_Symmetry_Inverter_imagined");
  sf_mex_destroy(&c6_u);
  c6_update_debugger_state_c6_Symmetry_Inverter_imagined(chartInstance);
  sf_mex_destroy(&c6_st);
}

static void finalize_c6_Symmetry_Inverter_imagined
  (SFc6_Symmetry_Inverter_imaginedInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c6_Symmetry_Inverter_imagined
  (SFc6_Symmetry_Inverter_imaginedInstanceStruct *chartInstance)
{
  real_T c6_hoistedGlobal;
  real_T c6_b_hoistedGlobal;
  real_T c6_c_hoistedGlobal;
  real_T c6_d_hoistedGlobal;
  real_T c6_e_hoistedGlobal;
  real_T c6_f_hoistedGlobal;
  real_T c6_amplitude_R;
  real_T c6_amplitude_S;
  real_T c6_amplitude_T;
  real_T c6_phase_R;
  real_T c6_phase_S;
  real_T c6_phase_T;
  uint32_T c6_debug_family_var_map[22];
  real_T c6_x1[4];
  real_T c6_y1[4];
  real_T c6_x2[4];
  real_T c6_y2[4];
  real_T c6_Amplitude_1[3];
  real_T c6_Phase_1[3];
  real_T c6_Amplitude_2[3];
  real_T c6_Phase_2[3];
  real_T c6_Amplitude_1_ex[4];
  real_T c6_Phase_1_ex[4];
  real_T c6_Amplitude_2_ex[4];
  real_T c6_Phase_2_ex[4];
  real_T c6_nargin = 6.0;
  real_T c6_nargout = 2.0;
  real_T c6_GEO_norm;
  real_T c6_Mean;
  int32_T c6_i0;
  int32_T c6_i1;
  int32_T c6_i2;
  int32_T c6_i3;
  real_T c6_A;
  real_T c6_x;
  real_T c6_b_x;
  real_T c6_c_x;
  int32_T c6_i4;
  int32_T c6_i5;
  int32_T c6_i6;
  int32_T c6_i7;
  int32_T c6_i8;
  int32_T c6_i9;
  real_T c6_u[4];
  const mxArray *c6_y = NULL;
  int32_T c6_i10;
  real_T c6_b_u[4];
  const mxArray *c6_b_y = NULL;
  int32_T c6_i11;
  real_T c6_c_u[4];
  const mxArray *c6_c_y = NULL;
  int32_T c6_i12;
  real_T c6_d_u[4];
  const mxArray *c6_d_y = NULL;
  real_T *c6_b_Mean;
  real_T *c6_b_GEO_norm;
  real_T *c6_b_phase_T;
  real_T *c6_b_phase_S;
  real_T *c6_b_phase_R;
  real_T *c6_b_amplitude_T;
  real_T *c6_b_amplitude_S;
  real_T *c6_b_amplitude_R;
  c6_b_Mean = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c6_b_phase_T = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c6_b_phase_S = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c6_b_phase_R = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c6_b_amplitude_T = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c6_b_amplitude_S = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c6_b_GEO_norm = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c6_b_amplitude_R = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 5U, chartInstance->c6_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c6_b_amplitude_R, 0U);
  chartInstance->c6_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 5U, chartInstance->c6_sfEvent);
  c6_hoistedGlobal = *c6_b_amplitude_R;
  c6_b_hoistedGlobal = *c6_b_amplitude_S;
  c6_c_hoistedGlobal = *c6_b_amplitude_T;
  c6_d_hoistedGlobal = *c6_b_phase_R;
  c6_e_hoistedGlobal = *c6_b_phase_S;
  c6_f_hoistedGlobal = *c6_b_phase_T;
  c6_amplitude_R = c6_hoistedGlobal;
  c6_amplitude_S = c6_b_hoistedGlobal;
  c6_amplitude_T = c6_c_hoistedGlobal;
  c6_phase_R = c6_d_hoistedGlobal;
  c6_phase_S = c6_e_hoistedGlobal;
  c6_phase_T = c6_f_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 22U, 22U, c6_debug_family_names,
    c6_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c6_x1, 0U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c6_y1, 1U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c6_x2, 2U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c6_y2, 3U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c6_Amplitude_1, 4U, c6_c_sf_marshallOut,
    c6_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c6_Phase_1, 5U, c6_c_sf_marshallOut,
    c6_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c6_Amplitude_2, 6U, c6_c_sf_marshallOut,
    c6_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c6_Phase_2, 7U, c6_c_sf_marshallOut,
    c6_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c6_Amplitude_1_ex, 8U,
    c6_b_sf_marshallOut, c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c6_Phase_1_ex, 9U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c6_Amplitude_2_ex, 10U,
    c6_b_sf_marshallOut, c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c6_Phase_2_ex, 11U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_nargin, 12U, c6_sf_marshallOut,
    c6_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_nargout, 13U, c6_sf_marshallOut,
    c6_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c6_amplitude_R, 14U, c6_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c6_amplitude_S, 15U, c6_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c6_amplitude_T, 16U, c6_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c6_phase_R, 17U, c6_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c6_phase_S, 18U, c6_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c6_phase_T, 19U, c6_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_GEO_norm, 20U, c6_sf_marshallOut,
    c6_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_Mean, 21U, c6_sf_marshallOut,
    c6_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 4);
  for (c6_i0 = 0; c6_i0 < 4; c6_i0++) {
    c6_x1[c6_i0] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 5);
  for (c6_i1 = 0; c6_i1 < 4; c6_i1++) {
    c6_y1[c6_i1] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 6);
  for (c6_i2 = 0; c6_i2 < 4; c6_i2++) {
    c6_x2[c6_i2] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 7);
  for (c6_i3 = 0; c6_i3 < 4; c6_i3++) {
    c6_y2[c6_i3] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 9);
  c6_GEO_norm = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 10);
  c6_Mean = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 12);
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 15);
  c6_A = (c6_amplitude_R + c6_amplitude_S) + c6_amplitude_T;
  c6_x = c6_A;
  c6_b_x = c6_x;
  c6_c_x = c6_b_x;
  c6_Mean = c6_c_x / 3.0;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 16);
  c6_Amplitude_1[0] = c6_Mean;
  c6_Amplitude_1[1] = c6_Mean;
  c6_Amplitude_1[2] = c6_Mean;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 18);
  for (c6_i4 = 0; c6_i4 < 3; c6_i4++) {
    c6_Phase_1[c6_i4] = -2.0943951023931953 * (real_T)c6_i4;
  }

  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 21);
  c6_Amplitude_2[0] = c6_amplitude_R;
  c6_Amplitude_2[1] = c6_amplitude_S;
  c6_Amplitude_2[2] = c6_amplitude_T;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 22);
  c6_Phase_2[0] = c6_phase_R;
  c6_Phase_2[1] = c6_phase_S;
  c6_Phase_2[2] = c6_phase_T;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 25);
  for (c6_i5 = 0; c6_i5 < 3; c6_i5++) {
    c6_Amplitude_1_ex[c6_i5] = c6_Amplitude_1[c6_i5];
  }

  c6_Amplitude_1_ex[3] = c6_Amplitude_1[0];
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 26);
  for (c6_i6 = 0; c6_i6 < 3; c6_i6++) {
    c6_Phase_1_ex[c6_i6] = c6_Phase_1[c6_i6];
  }

  c6_Phase_1_ex[3] = c6_Phase_1[0];
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 27);
  for (c6_i7 = 0; c6_i7 < 3; c6_i7++) {
    c6_Amplitude_2_ex[c6_i7] = c6_Amplitude_2[c6_i7];
  }

  c6_Amplitude_2_ex[3] = c6_Amplitude_2[0];
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 28);
  for (c6_i8 = 0; c6_i8 < 3; c6_i8++) {
    c6_Phase_2_ex[c6_i8] = c6_Phase_2[c6_i8];
  }

  c6_Phase_2_ex[3] = c6_Phase_2[0];
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 30);
  for (c6_i9 = 0; c6_i9 < 4; c6_i9++) {
    c6_u[c6_i9] = c6_Amplitude_1_ex[c6_i9];
  }

  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 0, 0U, 1U, 0U, 2, 1, 4), false);
  for (c6_i10 = 0; c6_i10 < 4; c6_i10++) {
    c6_b_u[c6_i10] = c6_Phase_1_ex[c6_i10];
  }

  c6_b_y = NULL;
  sf_mex_assign(&c6_b_y, sf_mex_create("y", c6_b_u, 0, 0U, 1U, 0U, 2, 1, 4),
                false);
  for (c6_i11 = 0; c6_i11 < 4; c6_i11++) {
    c6_c_u[c6_i11] = c6_Amplitude_2_ex[c6_i11];
  }

  c6_c_y = NULL;
  sf_mex_assign(&c6_c_y, sf_mex_create("y", c6_c_u, 0, 0U, 1U, 0U, 2, 1, 4),
                false);
  for (c6_i12 = 0; c6_i12 < 4; c6_i12++) {
    c6_d_u[c6_i12] = c6_Phase_2_ex[c6_i12];
  }

  c6_d_y = NULL;
  sf_mex_assign(&c6_d_y, sf_mex_create("y", c6_d_u, 0, 0U, 1U, 0U, 2, 1, 4),
                false);
  c6_GEO_norm = c6_c_emlrt_marshallIn(chartInstance, sf_mex_call_debug
    (sfGlobalDebugInstanceStruct, "geometry_solver", 1U, 4U, 14, c6_y, 14,
     c6_b_y, 14, c6_c_y, 14, c6_d_y), "geometry_solver");
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, -30);
  _SFD_SYMBOL_SCOPE_POP();
  *c6_b_GEO_norm = c6_GEO_norm;
  *c6_b_Mean = c6_Mean;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, chartInstance->c6_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_Symmetry_Inverter_imaginedMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  _SFD_DATA_RANGE_CHECK(*c6_b_GEO_norm, 1U);
  _SFD_DATA_RANGE_CHECK(*c6_b_amplitude_S, 2U);
  _SFD_DATA_RANGE_CHECK(*c6_b_amplitude_T, 3U);
  _SFD_DATA_RANGE_CHECK(*c6_b_phase_R, 4U);
  _SFD_DATA_RANGE_CHECK(*c6_b_phase_S, 5U);
  _SFD_DATA_RANGE_CHECK(*c6_b_phase_T, 6U);
  _SFD_DATA_RANGE_CHECK(*c6_b_Mean, 7U);
}

static void initSimStructsc6_Symmetry_Inverter_imagined
  (SFc6_Symmetry_Inverter_imaginedInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c6_machineNumber, uint32_T
  c6_chartNumber, uint32_T c6_instanceNumber)
{
  (void)c6_machineNumber;
  (void)c6_chartNumber;
  (void)c6_instanceNumber;
}

static const mxArray *c6_sf_marshallOut(void *chartInstanceVoid, void *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  real_T c6_u;
  const mxArray *c6_y = NULL;
  SFc6_Symmetry_Inverter_imaginedInstanceStruct *chartInstance;
  chartInstance = (SFc6_Symmetry_Inverter_imaginedInstanceStruct *)
    chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_u = *(real_T *)c6_inData;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", &c6_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, false);
  return c6_mxArrayOutData;
}

static void c6_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_geometry_solver;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  real_T c6_y;
  SFc6_Symmetry_Inverter_imaginedInstanceStruct *chartInstance;
  chartInstance = (SFc6_Symmetry_Inverter_imaginedInstanceStruct *)
    chartInstanceVoid;
  c6_geometry_solver = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_geometry_solver),
    &c6_thisId);
  sf_mex_destroy(&c6_geometry_solver);
  *(real_T *)c6_outData = c6_y;
  sf_mex_destroy(&c6_mxArrayInData);
}

static const mxArray *c6_b_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_i13;
  real_T c6_b_inData[4];
  int32_T c6_i14;
  real_T c6_u[4];
  const mxArray *c6_y = NULL;
  SFc6_Symmetry_Inverter_imaginedInstanceStruct *chartInstance;
  chartInstance = (SFc6_Symmetry_Inverter_imaginedInstanceStruct *)
    chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  for (c6_i13 = 0; c6_i13 < 4; c6_i13++) {
    c6_b_inData[c6_i13] = (*(real_T (*)[4])c6_inData)[c6_i13];
  }

  for (c6_i14 = 0; c6_i14 < 4; c6_i14++) {
    c6_u[c6_i14] = c6_b_inData[c6_i14];
  }

  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 0, 0U, 1U, 0U, 2, 1, 4), false);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, false);
  return c6_mxArrayOutData;
}

static void c6_emlrt_marshallIn(SFc6_Symmetry_Inverter_imaginedInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId,
  real_T c6_y[4])
{
  real_T c6_dv0[4];
  int32_T c6_i15;
  (void)chartInstance;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), c6_dv0, 1, 0, 0U, 1, 0U, 2, 1, 4);
  for (c6_i15 = 0; c6_i15 < 4; c6_i15++) {
    c6_y[c6_i15] = c6_dv0[c6_i15];
  }

  sf_mex_destroy(&c6_u);
}

static void c6_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_Phase_2_ex;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  real_T c6_y[4];
  int32_T c6_i16;
  SFc6_Symmetry_Inverter_imaginedInstanceStruct *chartInstance;
  chartInstance = (SFc6_Symmetry_Inverter_imaginedInstanceStruct *)
    chartInstanceVoid;
  c6_Phase_2_ex = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_Phase_2_ex), &c6_thisId, c6_y);
  sf_mex_destroy(&c6_Phase_2_ex);
  for (c6_i16 = 0; c6_i16 < 4; c6_i16++) {
    (*(real_T (*)[4])c6_outData)[c6_i16] = c6_y[c6_i16];
  }

  sf_mex_destroy(&c6_mxArrayInData);
}

static const mxArray *c6_c_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_i17;
  real_T c6_b_inData[3];
  int32_T c6_i18;
  real_T c6_u[3];
  const mxArray *c6_y = NULL;
  SFc6_Symmetry_Inverter_imaginedInstanceStruct *chartInstance;
  chartInstance = (SFc6_Symmetry_Inverter_imaginedInstanceStruct *)
    chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  for (c6_i17 = 0; c6_i17 < 3; c6_i17++) {
    c6_b_inData[c6_i17] = (*(real_T (*)[3])c6_inData)[c6_i17];
  }

  for (c6_i18 = 0; c6_i18 < 3; c6_i18++) {
    c6_u[c6_i18] = c6_b_inData[c6_i18];
  }

  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 0, 0U, 1U, 0U, 2, 1, 3), false);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, false);
  return c6_mxArrayOutData;
}

static void c6_b_emlrt_marshallIn(SFc6_Symmetry_Inverter_imaginedInstanceStruct *
  chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId,
  real_T c6_y[3])
{
  real_T c6_dv1[3];
  int32_T c6_i19;
  (void)chartInstance;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), c6_dv1, 1, 0, 0U, 1, 0U, 2, 1, 3);
  for (c6_i19 = 0; c6_i19 < 3; c6_i19++) {
    c6_y[c6_i19] = c6_dv1[c6_i19];
  }

  sf_mex_destroy(&c6_u);
}

static void c6_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_Phase_2;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  real_T c6_y[3];
  int32_T c6_i20;
  SFc6_Symmetry_Inverter_imaginedInstanceStruct *chartInstance;
  chartInstance = (SFc6_Symmetry_Inverter_imaginedInstanceStruct *)
    chartInstanceVoid;
  c6_Phase_2 = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_Phase_2), &c6_thisId, c6_y);
  sf_mex_destroy(&c6_Phase_2);
  for (c6_i20 = 0; c6_i20 < 3; c6_i20++) {
    (*(real_T (*)[3])c6_outData)[c6_i20] = c6_y[c6_i20];
  }

  sf_mex_destroy(&c6_mxArrayInData);
}

const mxArray *sf_c6_Symmetry_Inverter_imagined_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c6_nameCaptureInfo = NULL;
  c6_nameCaptureInfo = NULL;
  sf_mex_assign(&c6_nameCaptureInfo, sf_mex_createstruct("structure", 2, 7, 1),
                false);
  c6_info_helper(&c6_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c6_nameCaptureInfo);
  return c6_nameCaptureInfo;
}

static void c6_info_helper(const mxArray **c6_info)
{
  const mxArray *c6_rhs0 = NULL;
  const mxArray *c6_lhs0 = NULL;
  const mxArray *c6_rhs1 = NULL;
  const mxArray *c6_lhs1 = NULL;
  const mxArray *c6_rhs2 = NULL;
  const mxArray *c6_lhs2 = NULL;
  const mxArray *c6_rhs3 = NULL;
  const mxArray *c6_lhs3 = NULL;
  const mxArray *c6_rhs4 = NULL;
  const mxArray *c6_lhs4 = NULL;
  const mxArray *c6_rhs5 = NULL;
  const mxArray *c6_lhs5 = NULL;
  const mxArray *c6_rhs6 = NULL;
  const mxArray *c6_lhs6 = NULL;
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("mrdivide"), "name", "name", 0);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1388460096U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1370009886U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c6_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs0), "rhs", "rhs", 0);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs0), "lhs", "lhs", 0);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 1);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 1);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c6_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs1), "rhs", "rhs", 1);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs1), "lhs", "lhs", 1);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 2);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("rdivide"), "name", "name", 2);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1363713880U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c6_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs2), "rhs", "rhs", 2);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs2), "lhs", "lhs", 2);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 3);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c6_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs3), "rhs", "rhs", 3);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs3), "lhs", "lhs", 3);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 4);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1286818796U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c6_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs4), "rhs", "rhs", 4);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs4), "lhs", "lhs", 4);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("eml_div"), "name", "name", 5);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 5);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1375980688U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c6_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs5), "rhs", "rhs", 5);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs5), "lhs", "lhs", 5);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 6);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 6);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1389307920U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c6_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs6), "rhs", "rhs", 6);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs6), "lhs", "lhs", 6);
  sf_mex_destroy(&c6_rhs0);
  sf_mex_destroy(&c6_lhs0);
  sf_mex_destroy(&c6_rhs1);
  sf_mex_destroy(&c6_lhs1);
  sf_mex_destroy(&c6_rhs2);
  sf_mex_destroy(&c6_lhs2);
  sf_mex_destroy(&c6_rhs3);
  sf_mex_destroy(&c6_lhs3);
  sf_mex_destroy(&c6_rhs4);
  sf_mex_destroy(&c6_lhs4);
  sf_mex_destroy(&c6_rhs5);
  sf_mex_destroy(&c6_lhs5);
  sf_mex_destroy(&c6_rhs6);
  sf_mex_destroy(&c6_lhs6);
}

static const mxArray *c6_emlrt_marshallOut(const char * c6_u)
{
  const mxArray *c6_y = NULL;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c6_u)), false);
  return c6_y;
}

static const mxArray *c6_b_emlrt_marshallOut(const uint32_T c6_u)
{
  const mxArray *c6_y = NULL;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", &c6_u, 7, 0U, 0U, 0U, 0), false);
  return c6_y;
}

static real_T c6_c_emlrt_marshallIn
  (SFc6_Symmetry_Inverter_imaginedInstanceStruct *chartInstance, const mxArray
   *c6_geometry_solver, const char_T *c6_identifier)
{
  real_T c6_y;
  emlrtMsgIdentifier c6_thisId;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_geometry_solver),
    &c6_thisId);
  sf_mex_destroy(&c6_geometry_solver);
  return c6_y;
}

static real_T c6_d_emlrt_marshallIn
  (SFc6_Symmetry_Inverter_imaginedInstanceStruct *chartInstance, const mxArray
   *c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  real_T c6_y;
  real_T c6_d0;
  (void)chartInstance;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), &c6_d0, 1, 0, 0U, 0, 0U, 0);
  c6_y = c6_d0;
  sf_mex_destroy(&c6_u);
  return c6_y;
}

static const mxArray *c6_d_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_u;
  const mxArray *c6_y = NULL;
  SFc6_Symmetry_Inverter_imaginedInstanceStruct *chartInstance;
  chartInstance = (SFc6_Symmetry_Inverter_imaginedInstanceStruct *)
    chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_u = *(int32_T *)c6_inData;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", &c6_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, false);
  return c6_mxArrayOutData;
}

static int32_T c6_e_emlrt_marshallIn
  (SFc6_Symmetry_Inverter_imaginedInstanceStruct *chartInstance, const mxArray
   *c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  int32_T c6_y;
  int32_T c6_i21;
  (void)chartInstance;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), &c6_i21, 1, 6, 0U, 0, 0U, 0);
  c6_y = c6_i21;
  sf_mex_destroy(&c6_u);
  return c6_y;
}

static void c6_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_b_sfEvent;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  int32_T c6_y;
  SFc6_Symmetry_Inverter_imaginedInstanceStruct *chartInstance;
  chartInstance = (SFc6_Symmetry_Inverter_imaginedInstanceStruct *)
    chartInstanceVoid;
  c6_b_sfEvent = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_b_sfEvent),
    &c6_thisId);
  sf_mex_destroy(&c6_b_sfEvent);
  *(int32_T *)c6_outData = c6_y;
  sf_mex_destroy(&c6_mxArrayInData);
}

static uint8_T c6_f_emlrt_marshallIn
  (SFc6_Symmetry_Inverter_imaginedInstanceStruct *chartInstance, const mxArray
   *c6_b_is_active_c6_Symmetry_Inverter_imagined, const char_T *c6_identifier)
{
  uint8_T c6_y;
  emlrtMsgIdentifier c6_thisId;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c6_b_is_active_c6_Symmetry_Inverter_imagined), &c6_thisId);
  sf_mex_destroy(&c6_b_is_active_c6_Symmetry_Inverter_imagined);
  return c6_y;
}

static uint8_T c6_g_emlrt_marshallIn
  (SFc6_Symmetry_Inverter_imaginedInstanceStruct *chartInstance, const mxArray
   *c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  uint8_T c6_y;
  uint8_T c6_u0;
  (void)chartInstance;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), &c6_u0, 1, 3, 0U, 0, 0U, 0);
  c6_y = c6_u0;
  sf_mex_destroy(&c6_u);
  return c6_y;
}

static void init_dsm_address_info(SFc6_Symmetry_Inverter_imaginedInstanceStruct *
  chartInstance)
{
  (void)chartInstance;
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

void sf_c6_Symmetry_Inverter_imagined_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1119329280U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(379284832U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2680098869U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(706269696U);
}

mxArray *sf_c6_Symmetry_Inverter_imagined_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("ZMplEWZRgRo1fa7IfwcVIF");
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

mxArray *sf_c6_Symmetry_Inverter_imagined_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c6_Symmetry_Inverter_imagined_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c6_Symmetry_Inverter_imagined(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[5],T\"GEO_norm\",},{M[1],M[11],T\"Mean\",},{M[8],M[0],T\"is_active_c6_Symmetry_Inverter_imagined\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c6_Symmetry_Inverter_imagined_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc6_Symmetry_Inverter_imaginedInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc6_Symmetry_Inverter_imaginedInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Symmetry_Inverter_imaginedMachineNumber_,
           6,
           1,
           1,
           0,
           8,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize ist own list of scripts */
        init_script_number_translation(_Symmetry_Inverter_imaginedMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
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
          _SFD_SET_DATA_PROPS(1,2,0,1,"GEO_norm");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,1017);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_sf_marshallOut,(MexInFcnForType)c6_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_sf_marshallOut,(MexInFcnForType)c6_sf_marshallIn);

        {
          real_T *c6_amplitude_R;
          real_T *c6_GEO_norm;
          real_T *c6_amplitude_S;
          real_T *c6_amplitude_T;
          real_T *c6_phase_R;
          real_T *c6_phase_S;
          real_T *c6_phase_T;
          real_T *c6_Mean;
          c6_Mean = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c6_phase_T = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
          c6_phase_S = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
          c6_phase_R = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c6_amplitude_T = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c6_amplitude_S = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c6_GEO_norm = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c6_amplitude_R = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c6_amplitude_R);
          _SFD_SET_DATA_VALUE_PTR(1U, c6_GEO_norm);
          _SFD_SET_DATA_VALUE_PTR(2U, c6_amplitude_S);
          _SFD_SET_DATA_VALUE_PTR(3U, c6_amplitude_T);
          _SFD_SET_DATA_VALUE_PTR(4U, c6_phase_R);
          _SFD_SET_DATA_VALUE_PTR(5U, c6_phase_S);
          _SFD_SET_DATA_VALUE_PTR(6U, c6_phase_T);
          _SFD_SET_DATA_VALUE_PTR(7U, c6_Mean);
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
  return "uCfp4CsfZCSSr4U6xkaGAH";
}

static void sf_opaque_initialize_c6_Symmetry_Inverter_imagined(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc6_Symmetry_Inverter_imaginedInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c6_Symmetry_Inverter_imagined
    ((SFc6_Symmetry_Inverter_imaginedInstanceStruct*) chartInstanceVar);
  initialize_c6_Symmetry_Inverter_imagined
    ((SFc6_Symmetry_Inverter_imaginedInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c6_Symmetry_Inverter_imagined(void
  *chartInstanceVar)
{
  enable_c6_Symmetry_Inverter_imagined
    ((SFc6_Symmetry_Inverter_imaginedInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c6_Symmetry_Inverter_imagined(void
  *chartInstanceVar)
{
  disable_c6_Symmetry_Inverter_imagined
    ((SFc6_Symmetry_Inverter_imaginedInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c6_Symmetry_Inverter_imagined(void
  *chartInstanceVar)
{
  sf_gateway_c6_Symmetry_Inverter_imagined
    ((SFc6_Symmetry_Inverter_imaginedInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c6_Symmetry_Inverter_imagined
  (SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c6_Symmetry_Inverter_imagined
    ((SFc6_Symmetry_Inverter_imaginedInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c6_Symmetry_Inverter_imagined();/* state var info */
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

extern void sf_internal_set_sim_state_c6_Symmetry_Inverter_imagined(SimStruct* S,
  const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c6_Symmetry_Inverter_imagined();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c6_Symmetry_Inverter_imagined
    ((SFc6_Symmetry_Inverter_imaginedInstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c6_Symmetry_Inverter_imagined
  (SimStruct* S)
{
  return sf_internal_get_sim_state_c6_Symmetry_Inverter_imagined(S);
}

static void sf_opaque_set_sim_state_c6_Symmetry_Inverter_imagined(SimStruct* S,
  const mxArray *st)
{
  sf_internal_set_sim_state_c6_Symmetry_Inverter_imagined(S, st);
}

static void sf_opaque_terminate_c6_Symmetry_Inverter_imagined(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc6_Symmetry_Inverter_imaginedInstanceStruct*)
                    chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Symmetry_Inverter_imagined_optimization_info();
    }

    finalize_c6_Symmetry_Inverter_imagined
      ((SFc6_Symmetry_Inverter_imaginedInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    if (crtInfo != NULL) {
      utFree((void *)crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc6_Symmetry_Inverter_imagined
    ((SFc6_Symmetry_Inverter_imaginedInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c6_Symmetry_Inverter_imagined(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    initialize_params_c6_Symmetry_Inverter_imagined
      ((SFc6_Symmetry_Inverter_imaginedInstanceStruct*)(chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c6_Symmetry_Inverter_imagined(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Symmetry_Inverter_imagined_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,6);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,6,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,6,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,6);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,6,6);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,6,2);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,6);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3108842029U));
  ssSetChecksum1(S,(3854741907U));
  ssSetChecksum2(S,(3700329206U));
  ssSetChecksum3(S,(1344968425U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c6_Symmetry_Inverter_imagined(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c6_Symmetry_Inverter_imagined(SimStruct *S)
{
  SFc6_Symmetry_Inverter_imaginedInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc6_Symmetry_Inverter_imaginedInstanceStruct *)utMalloc
    (sizeof(SFc6_Symmetry_Inverter_imaginedInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc6_Symmetry_Inverter_imaginedInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c6_Symmetry_Inverter_imagined;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c6_Symmetry_Inverter_imagined;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c6_Symmetry_Inverter_imagined;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c6_Symmetry_Inverter_imagined;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c6_Symmetry_Inverter_imagined;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c6_Symmetry_Inverter_imagined;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c6_Symmetry_Inverter_imagined;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c6_Symmetry_Inverter_imagined;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c6_Symmetry_Inverter_imagined;
  chartInstance->chartInfo.mdlStart = mdlStart_c6_Symmetry_Inverter_imagined;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c6_Symmetry_Inverter_imagined;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.debugInstance = sfGlobalDebugInstanceStruct;
  chartInstance->S = S;
  crtInfo->instanceInfo = (&(chartInstance->chartInfo));
  crtInfo->isJITEnabled = false;
  ssSetUserData(S,(void *)(crtInfo));  /* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
  chart_debug_initialization(S,1);
}

void c6_Symmetry_Inverter_imagined_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c6_Symmetry_Inverter_imagined(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c6_Symmetry_Inverter_imagined(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c6_Symmetry_Inverter_imagined(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c6_Symmetry_Inverter_imagined_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
