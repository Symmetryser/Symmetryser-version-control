/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Symmetry_Inverter_imagined_sfun.h"
#include "c4_Symmetry_Inverter_imagined.h"
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
static const char * c4_debug_family_names[7] = { "CC_mtx", "nargin", "nargout",
  "amp", "phase", "t", "CC" };

/* Function Declarations */
static void initialize_c4_Symmetry_Inverter_imagined
  (SFc4_Symmetry_Inverter_imaginedInstanceStruct *chartInstance);
static void initialize_params_c4_Symmetry_Inverter_imagined
  (SFc4_Symmetry_Inverter_imaginedInstanceStruct *chartInstance);
static void enable_c4_Symmetry_Inverter_imagined
  (SFc4_Symmetry_Inverter_imaginedInstanceStruct *chartInstance);
static void disable_c4_Symmetry_Inverter_imagined
  (SFc4_Symmetry_Inverter_imaginedInstanceStruct *chartInstance);
static void c4_update_debugger_state_c4_Symmetry_Inverter_imagined
  (SFc4_Symmetry_Inverter_imaginedInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c4_Symmetry_Inverter_imagined
  (SFc4_Symmetry_Inverter_imaginedInstanceStruct *chartInstance);
static void set_sim_state_c4_Symmetry_Inverter_imagined
  (SFc4_Symmetry_Inverter_imaginedInstanceStruct *chartInstance, const mxArray
   *c4_st);
static void finalize_c4_Symmetry_Inverter_imagined
  (SFc4_Symmetry_Inverter_imaginedInstanceStruct *chartInstance);
static void sf_c4_Symmetry_Inverter_imagined
  (SFc4_Symmetry_Inverter_imaginedInstanceStruct *chartInstance);
static void initSimStructsc4_Symmetry_Inverter_imagined
  (SFc4_Symmetry_Inverter_imaginedInstanceStruct *chartInstance);
static void registerMessagesc4_Symmetry_Inverter_imagined
  (SFc4_Symmetry_Inverter_imaginedInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
  c4_chartNumber);
static const mxArray *c4_sf_marshallOut(void *chartInstanceVoid, void *c4_inData);
static void c4_emlrt_marshallIn(SFc4_Symmetry_Inverter_imaginedInstanceStruct
  *chartInstance, const mxArray *c4_CC, const char_T *c4_identifier, real_T
  c4_y[3]);
static void c4_b_emlrt_marshallIn(SFc4_Symmetry_Inverter_imaginedInstanceStruct *
  chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId,
  real_T c4_y[3]);
static void c4_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_b_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static real_T c4_c_emlrt_marshallIn
  (SFc4_Symmetry_Inverter_imaginedInstanceStruct *chartInstance, const mxArray
   *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_c_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static void c4_d_emlrt_marshallIn(SFc4_Symmetry_Inverter_imaginedInstanceStruct *
  chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId,
  real_T c4_y[12]);
static void c4_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_d_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static int32_T c4_e_emlrt_marshallIn
  (SFc4_Symmetry_Inverter_imaginedInstanceStruct *chartInstance, const mxArray
   *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static uint8_T c4_f_emlrt_marshallIn
  (SFc4_Symmetry_Inverter_imaginedInstanceStruct *chartInstance, const mxArray
   *c4_b_is_active_c4_Symmetry_Inverter_imagined, const char_T *c4_identifier);
static uint8_T c4_g_emlrt_marshallIn
  (SFc4_Symmetry_Inverter_imaginedInstanceStruct *chartInstance, const mxArray
   *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void init_dsm_address_info(SFc4_Symmetry_Inverter_imaginedInstanceStruct *
  chartInstance);

/* Function Definitions */
static void initialize_c4_Symmetry_Inverter_imagined
  (SFc4_Symmetry_Inverter_imaginedInstanceStruct *chartInstance)
{
  chartInstance->c4_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c4_is_active_c4_Symmetry_Inverter_imagined = 0U;
}

static void initialize_params_c4_Symmetry_Inverter_imagined
  (SFc4_Symmetry_Inverter_imaginedInstanceStruct *chartInstance)
{
}

static void enable_c4_Symmetry_Inverter_imagined
  (SFc4_Symmetry_Inverter_imaginedInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c4_Symmetry_Inverter_imagined
  (SFc4_Symmetry_Inverter_imaginedInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c4_update_debugger_state_c4_Symmetry_Inverter_imagined
  (SFc4_Symmetry_Inverter_imaginedInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c4_Symmetry_Inverter_imagined
  (SFc4_Symmetry_Inverter_imaginedInstanceStruct *chartInstance)
{
  const mxArray *c4_st;
  const mxArray *c4_y = NULL;
  int32_T c4_i0;
  real_T c4_u[3];
  const mxArray *c4_b_y = NULL;
  uint8_T c4_hoistedGlobal;
  uint8_T c4_b_u;
  const mxArray *c4_c_y = NULL;
  real_T (*c4_CC)[3];
  c4_CC = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c4_st = NULL;
  c4_st = NULL;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_createcellarray(2), FALSE);
  for (c4_i0 = 0; c4_i0 < 3; c4_i0++) {
    c4_u[c4_i0] = (*c4_CC)[c4_i0];
  }

  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_setcell(c4_y, 0, c4_b_y);
  c4_hoistedGlobal = chartInstance->c4_is_active_c4_Symmetry_Inverter_imagined;
  c4_b_u = c4_hoistedGlobal;
  c4_c_y = NULL;
  sf_mex_assign(&c4_c_y, sf_mex_create("y", &c4_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c4_y, 1, c4_c_y);
  sf_mex_assign(&c4_st, c4_y, FALSE);
  return c4_st;
}

static void set_sim_state_c4_Symmetry_Inverter_imagined
  (SFc4_Symmetry_Inverter_imaginedInstanceStruct *chartInstance, const mxArray
   *c4_st)
{
  const mxArray *c4_u;
  real_T c4_dv0[3];
  int32_T c4_i1;
  real_T (*c4_CC)[3];
  c4_CC = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c4_doneDoubleBufferReInit = TRUE;
  c4_u = sf_mex_dup(c4_st);
  c4_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 0)), "CC",
                      c4_dv0);
  for (c4_i1 = 0; c4_i1 < 3; c4_i1++) {
    (*c4_CC)[c4_i1] = c4_dv0[c4_i1];
  }

  chartInstance->c4_is_active_c4_Symmetry_Inverter_imagined =
    c4_f_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 1)),
    "is_active_c4_Symmetry_Inverter_imagined");
  sf_mex_destroy(&c4_u);
  c4_update_debugger_state_c4_Symmetry_Inverter_imagined(chartInstance);
  sf_mex_destroy(&c4_st);
}

static void finalize_c4_Symmetry_Inverter_imagined
  (SFc4_Symmetry_Inverter_imaginedInstanceStruct *chartInstance)
{
}

static void sf_c4_Symmetry_Inverter_imagined
  (SFc4_Symmetry_Inverter_imaginedInstanceStruct *chartInstance)
{
  int32_T c4_i2;
  int32_T c4_i3;
  real_T c4_hoistedGlobal;
  real_T c4_b_hoistedGlobal;
  real_T c4_amp;
  int32_T c4_i4;
  real_T c4_phase[3];
  real_T c4_t;
  uint32_T c4_debug_family_var_map[7];
  real_T c4_CC_mtx[12];
  real_T c4_nargin = 3.0;
  real_T c4_nargout = 1.0;
  real_T c4_CC[3];
  int32_T c4_i5;
  real_T c4_b;
  real_T c4_y;
  real_T c4_a;
  real_T c4_b_b;
  real_T c4_b_y;
  real_T c4_x;
  real_T c4_b_x;
  real_T c4_b_a;
  real_T c4_c_b;
  real_T c4_c_y;
  real_T c4_d_b;
  real_T c4_d_y;
  real_T c4_c_a;
  real_T c4_e_b;
  real_T c4_e_y;
  real_T c4_c_x;
  real_T c4_d_x;
  real_T c4_d_a;
  real_T c4_f_b;
  real_T c4_f_y;
  real_T c4_g_b;
  real_T c4_g_y;
  real_T c4_e_a;
  real_T c4_h_b;
  real_T c4_h_y;
  real_T c4_e_x;
  real_T c4_f_x;
  real_T c4_f_a;
  real_T c4_i_b;
  real_T c4_i_y;
  real_T c4_j_y[3];
  int32_T c4_i6;
  int32_T c4_i7;
  real_T *c4_b_amp;
  real_T *c4_b_t;
  real_T (*c4_b_CC)[3];
  real_T (*c4_b_phase)[3];
  c4_b_t = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c4_b_phase = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 1);
  c4_b_CC = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c4_b_amp = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 3U, chartInstance->c4_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c4_b_amp, 0U);
  for (c4_i2 = 0; c4_i2 < 3; c4_i2++) {
    _SFD_DATA_RANGE_CHECK((*c4_b_CC)[c4_i2], 1U);
  }

  for (c4_i3 = 0; c4_i3 < 3; c4_i3++) {
    _SFD_DATA_RANGE_CHECK((*c4_b_phase)[c4_i3], 2U);
  }

  _SFD_DATA_RANGE_CHECK(*c4_b_t, 3U);
  chartInstance->c4_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 3U, chartInstance->c4_sfEvent);
  c4_hoistedGlobal = *c4_b_amp;
  c4_b_hoistedGlobal = *c4_b_t;
  c4_amp = c4_hoistedGlobal;
  for (c4_i4 = 0; c4_i4 < 3; c4_i4++) {
    c4_phase[c4_i4] = (*c4_b_phase)[c4_i4];
  }

  c4_t = c4_b_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 7U, 7U, c4_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_CC_mtx, 0U, c4_c_sf_marshallOut,
    c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 1U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 2U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_amp, 3U, c4_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_phase, 4U, c4_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_t, 5U, c4_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_CC, 6U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 4);
  for (c4_i5 = 0; c4_i5 < 3; c4_i5++) {
    c4_CC[c4_i5] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 5);
  c4_CC_mtx[0] = c4_amp;
  c4_CC_mtx[3] = 50.0;
  c4_CC_mtx[6] = c4_phase[0];
  c4_CC_mtx[9] = 0.0;
  c4_CC_mtx[1] = c4_amp;
  c4_CC_mtx[4] = 50.0;
  c4_CC_mtx[7] = c4_phase[0] - 2.0943951023931953;
  c4_CC_mtx[10] = 0.0;
  c4_CC_mtx[2] = c4_amp;
  c4_CC_mtx[5] = 50.0;
  c4_CC_mtx[8] = c4_phase[0] - 4.1887902047863905;
  c4_CC_mtx[11] = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 13);
  c4_b = c4_CC_mtx[3];
  c4_y = 6.2831853071795862 * c4_b;
  c4_a = c4_y;
  c4_b_b = c4_t;
  c4_b_y = c4_a * c4_b_b;
  c4_x = c4_b_y + c4_CC_mtx[6];
  c4_b_x = c4_x;
  c4_b_x = muDoubleScalarSin(c4_b_x);
  c4_b_a = c4_CC_mtx[0];
  c4_c_b = c4_b_x;
  c4_c_y = c4_b_a * c4_c_b;
  c4_d_b = c4_CC_mtx[4];
  c4_d_y = 6.2831853071795862 * c4_d_b;
  c4_c_a = c4_d_y;
  c4_e_b = c4_t;
  c4_e_y = c4_c_a * c4_e_b;
  c4_c_x = c4_e_y + c4_CC_mtx[7];
  c4_d_x = c4_c_x;
  c4_d_x = muDoubleScalarSin(c4_d_x);
  c4_d_a = c4_CC_mtx[1];
  c4_f_b = c4_d_x;
  c4_f_y = c4_d_a * c4_f_b;
  c4_g_b = c4_CC_mtx[5];
  c4_g_y = 6.2831853071795862 * c4_g_b;
  c4_e_a = c4_g_y;
  c4_h_b = c4_t;
  c4_h_y = c4_e_a * c4_h_b;
  c4_e_x = c4_h_y + c4_CC_mtx[8];
  c4_f_x = c4_e_x;
  c4_f_x = muDoubleScalarSin(c4_f_x);
  c4_f_a = c4_CC_mtx[2];
  c4_i_b = c4_f_x;
  c4_i_y = c4_f_a * c4_i_b;
  c4_j_y[0] = c4_c_y + c4_CC_mtx[9];
  c4_j_y[1] = c4_f_y + c4_CC_mtx[10];
  c4_j_y[2] = c4_i_y + c4_CC_mtx[11];
  for (c4_i6 = 0; c4_i6 < 3; c4_i6++) {
    c4_CC[c4_i6] = c4_j_y[c4_i6];
  }

  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, -13);
  _SFD_SYMBOL_SCOPE_POP();
  for (c4_i7 = 0; c4_i7 < 3; c4_i7++) {
    (*c4_b_CC)[c4_i7] = c4_CC[c4_i7];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c4_sfEvent);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_Symmetry_Inverter_imaginedMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc4_Symmetry_Inverter_imagined
  (SFc4_Symmetry_Inverter_imaginedInstanceStruct *chartInstance)
{
}

static void registerMessagesc4_Symmetry_Inverter_imagined
  (SFc4_Symmetry_Inverter_imaginedInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
  c4_chartNumber)
{
}

static const mxArray *c4_sf_marshallOut(void *chartInstanceVoid, void *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i8;
  real_T c4_b_inData[3];
  int32_T c4_i9;
  real_T c4_u[3];
  const mxArray *c4_y = NULL;
  SFc4_Symmetry_Inverter_imaginedInstanceStruct *chartInstance;
  chartInstance = (SFc4_Symmetry_Inverter_imaginedInstanceStruct *)
    chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i8 = 0; c4_i8 < 3; c4_i8++) {
    c4_b_inData[c4_i8] = (*(real_T (*)[3])c4_inData)[c4_i8];
  }

  for (c4_i9 = 0; c4_i9 < 3; c4_i9++) {
    c4_u[c4_i9] = c4_b_inData[c4_i9];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, FALSE);
  return c4_mxArrayOutData;
}

static void c4_emlrt_marshallIn(SFc4_Symmetry_Inverter_imaginedInstanceStruct
  *chartInstance, const mxArray *c4_CC, const char_T *c4_identifier, real_T
  c4_y[3])
{
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_CC), &c4_thisId, c4_y);
  sf_mex_destroy(&c4_CC);
}

static void c4_b_emlrt_marshallIn(SFc4_Symmetry_Inverter_imaginedInstanceStruct *
  chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId,
  real_T c4_y[3])
{
  real_T c4_dv1[3];
  int32_T c4_i10;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), c4_dv1, 1, 0, 0U, 1, 0U, 1, 3);
  for (c4_i10 = 0; c4_i10 < 3; c4_i10++) {
    c4_y[c4_i10] = c4_dv1[c4_i10];
  }

  sf_mex_destroy(&c4_u);
}

static void c4_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_CC;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  real_T c4_y[3];
  int32_T c4_i11;
  SFc4_Symmetry_Inverter_imaginedInstanceStruct *chartInstance;
  chartInstance = (SFc4_Symmetry_Inverter_imaginedInstanceStruct *)
    chartInstanceVoid;
  c4_CC = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_CC), &c4_thisId, c4_y);
  sf_mex_destroy(&c4_CC);
  for (c4_i11 = 0; c4_i11 < 3; c4_i11++) {
    (*(real_T (*)[3])c4_outData)[c4_i11] = c4_y[c4_i11];
  }

  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_b_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  real_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_Symmetry_Inverter_imaginedInstanceStruct *chartInstance;
  chartInstance = (SFc4_Symmetry_Inverter_imaginedInstanceStruct *)
    chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_u = *(real_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, FALSE);
  return c4_mxArrayOutData;
}

static real_T c4_c_emlrt_marshallIn
  (SFc4_Symmetry_Inverter_imaginedInstanceStruct *chartInstance, const mxArray
   *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  real_T c4_y;
  real_T c4_d0;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_d0, 1, 0, 0U, 0, 0U, 0);
  c4_y = c4_d0;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_nargout;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  real_T c4_y;
  SFc4_Symmetry_Inverter_imaginedInstanceStruct *chartInstance;
  chartInstance = (SFc4_Symmetry_Inverter_imaginedInstanceStruct *)
    chartInstanceVoid;
  c4_nargout = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_nargout), &c4_thisId);
  sf_mex_destroy(&c4_nargout);
  *(real_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_c_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i12;
  int32_T c4_i13;
  int32_T c4_i14;
  real_T c4_b_inData[12];
  int32_T c4_i15;
  int32_T c4_i16;
  int32_T c4_i17;
  real_T c4_u[12];
  const mxArray *c4_y = NULL;
  SFc4_Symmetry_Inverter_imaginedInstanceStruct *chartInstance;
  chartInstance = (SFc4_Symmetry_Inverter_imaginedInstanceStruct *)
    chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_i12 = 0;
  for (c4_i13 = 0; c4_i13 < 4; c4_i13++) {
    for (c4_i14 = 0; c4_i14 < 3; c4_i14++) {
      c4_b_inData[c4_i14 + c4_i12] = (*(real_T (*)[12])c4_inData)[c4_i14 +
        c4_i12];
    }

    c4_i12 += 3;
  }

  c4_i15 = 0;
  for (c4_i16 = 0; c4_i16 < 4; c4_i16++) {
    for (c4_i17 = 0; c4_i17 < 3; c4_i17++) {
      c4_u[c4_i17 + c4_i15] = c4_b_inData[c4_i17 + c4_i15];
    }

    c4_i15 += 3;
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 2, 3, 4), FALSE);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, FALSE);
  return c4_mxArrayOutData;
}

static void c4_d_emlrt_marshallIn(SFc4_Symmetry_Inverter_imaginedInstanceStruct *
  chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId,
  real_T c4_y[12])
{
  real_T c4_dv2[12];
  int32_T c4_i18;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), c4_dv2, 1, 0, 0U, 1, 0U, 2, 3, 4);
  for (c4_i18 = 0; c4_i18 < 12; c4_i18++) {
    c4_y[c4_i18] = c4_dv2[c4_i18];
  }

  sf_mex_destroy(&c4_u);
}

static void c4_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_CC_mtx;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  real_T c4_y[12];
  int32_T c4_i19;
  int32_T c4_i20;
  int32_T c4_i21;
  SFc4_Symmetry_Inverter_imaginedInstanceStruct *chartInstance;
  chartInstance = (SFc4_Symmetry_Inverter_imaginedInstanceStruct *)
    chartInstanceVoid;
  c4_CC_mtx = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_CC_mtx), &c4_thisId, c4_y);
  sf_mex_destroy(&c4_CC_mtx);
  c4_i19 = 0;
  for (c4_i20 = 0; c4_i20 < 4; c4_i20++) {
    for (c4_i21 = 0; c4_i21 < 3; c4_i21++) {
      (*(real_T (*)[12])c4_outData)[c4_i21 + c4_i19] = c4_y[c4_i21 + c4_i19];
    }

    c4_i19 += 3;
  }

  sf_mex_destroy(&c4_mxArrayInData);
}

const mxArray *sf_c4_Symmetry_Inverter_imagined_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c4_nameCaptureInfo;
  c4_ResolvedFunctionInfo c4_info[7];
  c4_ResolvedFunctionInfo (*c4_b_info)[7];
  const mxArray *c4_m0 = NULL;
  int32_T c4_i22;
  c4_ResolvedFunctionInfo *c4_r0;
  c4_nameCaptureInfo = NULL;
  c4_nameCaptureInfo = NULL;
  c4_b_info = (c4_ResolvedFunctionInfo (*)[7])c4_info;
  (*c4_b_info)[0].context = "";
  (*c4_b_info)[0].name = "mrdivide";
  (*c4_b_info)[0].dominantType = "double";
  (*c4_b_info)[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c4_b_info)[0].fileTimeLo = 1357951548U;
  (*c4_b_info)[0].fileTimeHi = 0U;
  (*c4_b_info)[0].mFileTimeLo = 1319729966U;
  (*c4_b_info)[0].mFileTimeHi = 0U;
  (*c4_b_info)[1].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c4_b_info)[1].name = "rdivide";
  (*c4_b_info)[1].dominantType = "double";
  (*c4_b_info)[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c4_b_info)[1].fileTimeLo = 1346510388U;
  (*c4_b_info)[1].fileTimeHi = 0U;
  (*c4_b_info)[1].mFileTimeLo = 0U;
  (*c4_b_info)[1].mFileTimeHi = 0U;
  (*c4_b_info)[2].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c4_b_info)[2].name = "eml_scalexp_compatible";
  (*c4_b_info)[2].dominantType = "double";
  (*c4_b_info)[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m";
  (*c4_b_info)[2].fileTimeLo = 1286818796U;
  (*c4_b_info)[2].fileTimeHi = 0U;
  (*c4_b_info)[2].mFileTimeLo = 0U;
  (*c4_b_info)[2].mFileTimeHi = 0U;
  (*c4_b_info)[3].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c4_b_info)[3].name = "eml_div";
  (*c4_b_info)[3].dominantType = "double";
  (*c4_b_info)[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  (*c4_b_info)[3].fileTimeLo = 1313347810U;
  (*c4_b_info)[3].fileTimeHi = 0U;
  (*c4_b_info)[3].mFileTimeLo = 0U;
  (*c4_b_info)[3].mFileTimeHi = 0U;
  (*c4_b_info)[4].context = "";
  (*c4_b_info)[4].name = "mtimes";
  (*c4_b_info)[4].dominantType = "double";
  (*c4_b_info)[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c4_b_info)[4].fileTimeLo = 1289519692U;
  (*c4_b_info)[4].fileTimeHi = 0U;
  (*c4_b_info)[4].mFileTimeLo = 0U;
  (*c4_b_info)[4].mFileTimeHi = 0U;
  (*c4_b_info)[5].context = "";
  (*c4_b_info)[5].name = "sin";
  (*c4_b_info)[5].dominantType = "double";
  (*c4_b_info)[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  (*c4_b_info)[5].fileTimeLo = 1343830386U;
  (*c4_b_info)[5].fileTimeHi = 0U;
  (*c4_b_info)[5].mFileTimeLo = 0U;
  (*c4_b_info)[5].mFileTimeHi = 0U;
  (*c4_b_info)[6].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  (*c4_b_info)[6].name = "eml_scalar_sin";
  (*c4_b_info)[6].dominantType = "double";
  (*c4_b_info)[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  (*c4_b_info)[6].fileTimeLo = 1286818736U;
  (*c4_b_info)[6].fileTimeHi = 0U;
  (*c4_b_info)[6].mFileTimeLo = 0U;
  (*c4_b_info)[6].mFileTimeHi = 0U;
  sf_mex_assign(&c4_m0, sf_mex_createstruct("nameCaptureInfo", 1, 7), FALSE);
  for (c4_i22 = 0; c4_i22 < 7; c4_i22++) {
    c4_r0 = &c4_info[c4_i22];
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", c4_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c4_r0->context)), "context", "nameCaptureInfo",
                    c4_i22);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", c4_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c4_r0->name)), "name", "nameCaptureInfo", c4_i22);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", c4_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c4_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c4_i22);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", c4_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c4_r0->resolved)), "resolved", "nameCaptureInfo",
                    c4_i22);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", &c4_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c4_i22);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", &c4_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c4_i22);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", &c4_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c4_i22);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", &c4_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c4_i22);
  }

  sf_mex_assign(&c4_nameCaptureInfo, c4_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c4_nameCaptureInfo);
  return c4_nameCaptureInfo;
}

static const mxArray *c4_d_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_Symmetry_Inverter_imaginedInstanceStruct *chartInstance;
  chartInstance = (SFc4_Symmetry_Inverter_imaginedInstanceStruct *)
    chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_u = *(int32_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, FALSE);
  return c4_mxArrayOutData;
}

static int32_T c4_e_emlrt_marshallIn
  (SFc4_Symmetry_Inverter_imaginedInstanceStruct *chartInstance, const mxArray
   *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  int32_T c4_y;
  int32_T c4_i23;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_i23, 1, 6, 0U, 0, 0U, 0);
  c4_y = c4_i23;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_b_sfEvent;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  int32_T c4_y;
  SFc4_Symmetry_Inverter_imaginedInstanceStruct *chartInstance;
  chartInstance = (SFc4_Symmetry_Inverter_imaginedInstanceStruct *)
    chartInstanceVoid;
  c4_b_sfEvent = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_sfEvent),
    &c4_thisId);
  sf_mex_destroy(&c4_b_sfEvent);
  *(int32_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static uint8_T c4_f_emlrt_marshallIn
  (SFc4_Symmetry_Inverter_imaginedInstanceStruct *chartInstance, const mxArray
   *c4_b_is_active_c4_Symmetry_Inverter_imagined, const char_T *c4_identifier)
{
  uint8_T c4_y;
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c4_b_is_active_c4_Symmetry_Inverter_imagined), &c4_thisId);
  sf_mex_destroy(&c4_b_is_active_c4_Symmetry_Inverter_imagined);
  return c4_y;
}

static uint8_T c4_g_emlrt_marshallIn
  (SFc4_Symmetry_Inverter_imaginedInstanceStruct *chartInstance, const mxArray
   *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  uint8_T c4_y;
  uint8_T c4_u0;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_u0, 1, 3, 0U, 0, 0U, 0);
  c4_y = c4_u0;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void init_dsm_address_info(SFc4_Symmetry_Inverter_imaginedInstanceStruct *
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

void sf_c4_Symmetry_Inverter_imagined_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(633476332U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3593379129U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3134667233U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(4006316550U);
}

mxArray *sf_c4_Symmetry_Inverter_imagined_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("SejQJQPLKIzkCiabyXOz6F");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

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
      pr[0] = (double)(3);
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
      pr[0] = (double)(3);
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

mxArray *sf_c4_Symmetry_Inverter_imagined_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c4_Symmetry_Inverter_imagined(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"CC\",},{M[8],M[0],T\"is_active_c4_Symmetry_Inverter_imagined\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c4_Symmetry_Inverter_imagined_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc4_Symmetry_Inverter_imaginedInstanceStruct *chartInstance;
    chartInstance = (SFc4_Symmetry_Inverter_imaginedInstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Symmetry_Inverter_imaginedMachineNumber_,
           4,
           1,
           1,
           4,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"amp");
          _SFD_SET_DATA_PROPS(1,2,0,1,"CC");
          _SFD_SET_DATA_PROPS(2,1,1,0,"phase");
          _SFD_SET_DATA_PROPS(3,1,1,0,"t");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,646);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)
            c4_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          real_T *c4_amp;
          real_T *c4_t;
          real_T (*c4_CC)[3];
          real_T (*c4_phase)[3];
          c4_t = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c4_phase = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 1);
          c4_CC = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
          c4_amp = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c4_amp);
          _SFD_SET_DATA_VALUE_PTR(1U, *c4_CC);
          _SFD_SET_DATA_VALUE_PTR(2U, *c4_phase);
          _SFD_SET_DATA_VALUE_PTR(3U, c4_t);
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
  return "aqabbMzr8EZxSk5U9LsRMB";
}

static void sf_opaque_initialize_c4_Symmetry_Inverter_imagined(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc4_Symmetry_Inverter_imaginedInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c4_Symmetry_Inverter_imagined
    ((SFc4_Symmetry_Inverter_imaginedInstanceStruct*) chartInstanceVar);
  initialize_c4_Symmetry_Inverter_imagined
    ((SFc4_Symmetry_Inverter_imaginedInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c4_Symmetry_Inverter_imagined(void
  *chartInstanceVar)
{
  enable_c4_Symmetry_Inverter_imagined
    ((SFc4_Symmetry_Inverter_imaginedInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c4_Symmetry_Inverter_imagined(void
  *chartInstanceVar)
{
  disable_c4_Symmetry_Inverter_imagined
    ((SFc4_Symmetry_Inverter_imaginedInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c4_Symmetry_Inverter_imagined(void
  *chartInstanceVar)
{
  sf_c4_Symmetry_Inverter_imagined
    ((SFc4_Symmetry_Inverter_imaginedInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c4_Symmetry_Inverter_imagined
  (SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c4_Symmetry_Inverter_imagined
    ((SFc4_Symmetry_Inverter_imaginedInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c4_Symmetry_Inverter_imagined();/* state var info */
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

extern void sf_internal_set_sim_state_c4_Symmetry_Inverter_imagined(SimStruct* S,
  const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c4_Symmetry_Inverter_imagined();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c4_Symmetry_Inverter_imagined
    ((SFc4_Symmetry_Inverter_imaginedInstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c4_Symmetry_Inverter_imagined
  (SimStruct* S)
{
  return sf_internal_get_sim_state_c4_Symmetry_Inverter_imagined(S);
}

static void sf_opaque_set_sim_state_c4_Symmetry_Inverter_imagined(SimStruct* S,
  const mxArray *st)
{
  sf_internal_set_sim_state_c4_Symmetry_Inverter_imagined(S, st);
}

static void sf_opaque_terminate_c4_Symmetry_Inverter_imagined(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc4_Symmetry_Inverter_imaginedInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Symmetry_Inverter_imagined_optimization_info();
    }

    finalize_c4_Symmetry_Inverter_imagined
      ((SFc4_Symmetry_Inverter_imaginedInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc4_Symmetry_Inverter_imagined
    ((SFc4_Symmetry_Inverter_imaginedInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c4_Symmetry_Inverter_imagined(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c4_Symmetry_Inverter_imagined
      ((SFc4_Symmetry_Inverter_imaginedInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c4_Symmetry_Inverter_imagined(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Symmetry_Inverter_imagined_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      4);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,4,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,4,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,4);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,4,3);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,4,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 3; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,4);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3216676653U));
  ssSetChecksum1(S,(284053387U));
  ssSetChecksum2(S,(1815025021U));
  ssSetChecksum3(S,(2864013558U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c4_Symmetry_Inverter_imagined(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c4_Symmetry_Inverter_imagined(SimStruct *S)
{
  SFc4_Symmetry_Inverter_imaginedInstanceStruct *chartInstance;
  chartInstance = (SFc4_Symmetry_Inverter_imaginedInstanceStruct *)utMalloc
    (sizeof(SFc4_Symmetry_Inverter_imaginedInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc4_Symmetry_Inverter_imaginedInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c4_Symmetry_Inverter_imagined;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c4_Symmetry_Inverter_imagined;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c4_Symmetry_Inverter_imagined;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c4_Symmetry_Inverter_imagined;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c4_Symmetry_Inverter_imagined;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c4_Symmetry_Inverter_imagined;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c4_Symmetry_Inverter_imagined;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c4_Symmetry_Inverter_imagined;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c4_Symmetry_Inverter_imagined;
  chartInstance->chartInfo.mdlStart = mdlStart_c4_Symmetry_Inverter_imagined;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c4_Symmetry_Inverter_imagined;
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

void c4_Symmetry_Inverter_imagined_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c4_Symmetry_Inverter_imagined(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c4_Symmetry_Inverter_imagined(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c4_Symmetry_Inverter_imagined(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c4_Symmetry_Inverter_imagined_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
