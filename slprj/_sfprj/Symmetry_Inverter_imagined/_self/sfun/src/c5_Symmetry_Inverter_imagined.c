/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Symmetry_Inverter_imagined_sfun.h"
#include "c5_Symmetry_Inverter_imagined.h"
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
static const char * c5_debug_family_names[7] = { "CC_mtx", "nargin", "nargout",
  "amp", "phase", "t", "CC" };

/* Function Declarations */
static void initialize_c5_Symmetry_Inverter_imagined
  (SFc5_Symmetry_Inverter_imaginedInstanceStruct *chartInstance);
static void initialize_params_c5_Symmetry_Inverter_imagined
  (SFc5_Symmetry_Inverter_imaginedInstanceStruct *chartInstance);
static void enable_c5_Symmetry_Inverter_imagined
  (SFc5_Symmetry_Inverter_imaginedInstanceStruct *chartInstance);
static void disable_c5_Symmetry_Inverter_imagined
  (SFc5_Symmetry_Inverter_imaginedInstanceStruct *chartInstance);
static void c5_update_debugger_state_c5_Symmetry_Inverter_imagined
  (SFc5_Symmetry_Inverter_imaginedInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c5_Symmetry_Inverter_imagined
  (SFc5_Symmetry_Inverter_imaginedInstanceStruct *chartInstance);
static void set_sim_state_c5_Symmetry_Inverter_imagined
  (SFc5_Symmetry_Inverter_imaginedInstanceStruct *chartInstance, const mxArray
   *c5_st);
static void finalize_c5_Symmetry_Inverter_imagined
  (SFc5_Symmetry_Inverter_imaginedInstanceStruct *chartInstance);
static void sf_c5_Symmetry_Inverter_imagined
  (SFc5_Symmetry_Inverter_imaginedInstanceStruct *chartInstance);
static void initSimStructsc5_Symmetry_Inverter_imagined
  (SFc5_Symmetry_Inverter_imaginedInstanceStruct *chartInstance);
static void registerMessagesc5_Symmetry_Inverter_imagined
  (SFc5_Symmetry_Inverter_imaginedInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c5_machineNumber, uint32_T
  c5_chartNumber);
static const mxArray *c5_sf_marshallOut(void *chartInstanceVoid, void *c5_inData);
static void c5_emlrt_marshallIn(SFc5_Symmetry_Inverter_imaginedInstanceStruct
  *chartInstance, const mxArray *c5_CC, const char_T *c5_identifier, real_T
  c5_y[3]);
static void c5_b_emlrt_marshallIn(SFc5_Symmetry_Inverter_imaginedInstanceStruct *
  chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId,
  real_T c5_y[3]);
static void c5_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static const mxArray *c5_b_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static real_T c5_c_emlrt_marshallIn
  (SFc5_Symmetry_Inverter_imaginedInstanceStruct *chartInstance, const mxArray
   *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static const mxArray *c5_c_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static void c5_d_emlrt_marshallIn(SFc5_Symmetry_Inverter_imaginedInstanceStruct *
  chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId,
  real_T c5_y[12]);
static void c5_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static const mxArray *c5_d_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static int32_T c5_e_emlrt_marshallIn
  (SFc5_Symmetry_Inverter_imaginedInstanceStruct *chartInstance, const mxArray
   *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static uint8_T c5_f_emlrt_marshallIn
  (SFc5_Symmetry_Inverter_imaginedInstanceStruct *chartInstance, const mxArray
   *c5_b_is_active_c5_Symmetry_Inverter_imagined, const char_T *c5_identifier);
static uint8_T c5_g_emlrt_marshallIn
  (SFc5_Symmetry_Inverter_imaginedInstanceStruct *chartInstance, const mxArray
   *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void init_dsm_address_info(SFc5_Symmetry_Inverter_imaginedInstanceStruct *
  chartInstance);

/* Function Definitions */
static void initialize_c5_Symmetry_Inverter_imagined
  (SFc5_Symmetry_Inverter_imaginedInstanceStruct *chartInstance)
{
  chartInstance->c5_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c5_is_active_c5_Symmetry_Inverter_imagined = 0U;
}

static void initialize_params_c5_Symmetry_Inverter_imagined
  (SFc5_Symmetry_Inverter_imaginedInstanceStruct *chartInstance)
{
}

static void enable_c5_Symmetry_Inverter_imagined
  (SFc5_Symmetry_Inverter_imaginedInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c5_Symmetry_Inverter_imagined
  (SFc5_Symmetry_Inverter_imaginedInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c5_update_debugger_state_c5_Symmetry_Inverter_imagined
  (SFc5_Symmetry_Inverter_imaginedInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c5_Symmetry_Inverter_imagined
  (SFc5_Symmetry_Inverter_imaginedInstanceStruct *chartInstance)
{
  const mxArray *c5_st;
  const mxArray *c5_y = NULL;
  int32_T c5_i0;
  real_T c5_u[3];
  const mxArray *c5_b_y = NULL;
  uint8_T c5_hoistedGlobal;
  uint8_T c5_b_u;
  const mxArray *c5_c_y = NULL;
  real_T (*c5_CC)[3];
  c5_CC = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c5_st = NULL;
  c5_st = NULL;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_createcellarray(2), FALSE);
  for (c5_i0 = 0; c5_i0 < 3; c5_i0++) {
    c5_u[c5_i0] = (*c5_CC)[c5_i0];
  }

  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", c5_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_setcell(c5_y, 0, c5_b_y);
  c5_hoistedGlobal = chartInstance->c5_is_active_c5_Symmetry_Inverter_imagined;
  c5_b_u = c5_hoistedGlobal;
  c5_c_y = NULL;
  sf_mex_assign(&c5_c_y, sf_mex_create("y", &c5_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c5_y, 1, c5_c_y);
  sf_mex_assign(&c5_st, c5_y, FALSE);
  return c5_st;
}

static void set_sim_state_c5_Symmetry_Inverter_imagined
  (SFc5_Symmetry_Inverter_imaginedInstanceStruct *chartInstance, const mxArray
   *c5_st)
{
  const mxArray *c5_u;
  real_T c5_dv0[3];
  int32_T c5_i1;
  real_T (*c5_CC)[3];
  c5_CC = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c5_doneDoubleBufferReInit = TRUE;
  c5_u = sf_mex_dup(c5_st);
  c5_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c5_u, 0)), "CC",
                      c5_dv0);
  for (c5_i1 = 0; c5_i1 < 3; c5_i1++) {
    (*c5_CC)[c5_i1] = c5_dv0[c5_i1];
  }

  chartInstance->c5_is_active_c5_Symmetry_Inverter_imagined =
    c5_f_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c5_u, 1)),
    "is_active_c5_Symmetry_Inverter_imagined");
  sf_mex_destroy(&c5_u);
  c5_update_debugger_state_c5_Symmetry_Inverter_imagined(chartInstance);
  sf_mex_destroy(&c5_st);
}

static void finalize_c5_Symmetry_Inverter_imagined
  (SFc5_Symmetry_Inverter_imaginedInstanceStruct *chartInstance)
{
}

static void sf_c5_Symmetry_Inverter_imagined
  (SFc5_Symmetry_Inverter_imaginedInstanceStruct *chartInstance)
{
  int32_T c5_i2;
  int32_T c5_i3;
  int32_T c5_i4;
  real_T c5_hoistedGlobal;
  int32_T c5_i5;
  real_T c5_amp[3];
  int32_T c5_i6;
  real_T c5_phase[3];
  real_T c5_t;
  uint32_T c5_debug_family_var_map[7];
  real_T c5_CC_mtx[12];
  real_T c5_nargin = 3.0;
  real_T c5_nargout = 1.0;
  real_T c5_CC[3];
  int32_T c5_i7;
  real_T c5_b;
  real_T c5_y;
  real_T c5_a;
  real_T c5_b_b;
  real_T c5_b_y;
  real_T c5_x;
  real_T c5_b_x;
  real_T c5_b_a;
  real_T c5_c_b;
  real_T c5_c_y;
  real_T c5_d_b;
  real_T c5_d_y;
  real_T c5_c_a;
  real_T c5_e_b;
  real_T c5_e_y;
  real_T c5_c_x;
  real_T c5_d_x;
  real_T c5_d_a;
  real_T c5_f_b;
  real_T c5_f_y;
  real_T c5_g_b;
  real_T c5_g_y;
  real_T c5_e_a;
  real_T c5_h_b;
  real_T c5_h_y;
  real_T c5_e_x;
  real_T c5_f_x;
  real_T c5_f_a;
  real_T c5_i_b;
  real_T c5_i_y;
  real_T c5_j_y[3];
  int32_T c5_i8;
  int32_T c5_i9;
  real_T *c5_b_t;
  real_T (*c5_b_CC)[3];
  real_T (*c5_b_phase)[3];
  real_T (*c5_b_amp)[3];
  c5_b_t = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c5_b_phase = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 1);
  c5_b_CC = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c5_b_amp = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 4U, chartInstance->c5_sfEvent);
  for (c5_i2 = 0; c5_i2 < 3; c5_i2++) {
    _SFD_DATA_RANGE_CHECK((*c5_b_amp)[c5_i2], 0U);
  }

  for (c5_i3 = 0; c5_i3 < 3; c5_i3++) {
    _SFD_DATA_RANGE_CHECK((*c5_b_CC)[c5_i3], 1U);
  }

  for (c5_i4 = 0; c5_i4 < 3; c5_i4++) {
    _SFD_DATA_RANGE_CHECK((*c5_b_phase)[c5_i4], 2U);
  }

  _SFD_DATA_RANGE_CHECK(*c5_b_t, 3U);
  chartInstance->c5_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 4U, chartInstance->c5_sfEvent);
  c5_hoistedGlobal = *c5_b_t;
  for (c5_i5 = 0; c5_i5 < 3; c5_i5++) {
    c5_amp[c5_i5] = (*c5_b_amp)[c5_i5];
  }

  for (c5_i6 = 0; c5_i6 < 3; c5_i6++) {
    c5_phase[c5_i6] = (*c5_b_phase)[c5_i6];
  }

  c5_t = c5_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 7U, 7U, c5_debug_family_names,
    c5_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_CC_mtx, 0U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargin, 1U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargout, 2U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c5_amp, 3U, c5_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c5_phase, 4U, c5_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_t, 5U, c5_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_CC, 6U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 3);
  for (c5_i7 = 0; c5_i7 < 3; c5_i7++) {
    c5_CC[c5_i7] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 5);
  c5_CC_mtx[0] = c5_amp[0];
  c5_CC_mtx[3] = 50.0;
  c5_CC_mtx[6] = c5_phase[0];
  c5_CC_mtx[9] = 0.0;
  c5_CC_mtx[1] = c5_amp[1];
  c5_CC_mtx[4] = 50.0;
  c5_CC_mtx[7] = c5_phase[1];
  c5_CC_mtx[10] = 0.0;
  c5_CC_mtx[2] = c5_amp[2];
  c5_CC_mtx[5] = 50.0;
  c5_CC_mtx[8] = c5_phase[2];
  c5_CC_mtx[11] = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 13);
  c5_b = c5_CC_mtx[3];
  c5_y = 6.2831853071795862 * c5_b;
  c5_a = c5_y;
  c5_b_b = c5_t;
  c5_b_y = c5_a * c5_b_b;
  c5_x = c5_b_y + c5_CC_mtx[6];
  c5_b_x = c5_x;
  c5_b_x = muDoubleScalarSin(c5_b_x);
  c5_b_a = c5_CC_mtx[0];
  c5_c_b = c5_b_x;
  c5_c_y = c5_b_a * c5_c_b;
  c5_d_b = c5_CC_mtx[4];
  c5_d_y = 6.2831853071795862 * c5_d_b;
  c5_c_a = c5_d_y;
  c5_e_b = c5_t;
  c5_e_y = c5_c_a * c5_e_b;
  c5_c_x = c5_e_y + c5_CC_mtx[7];
  c5_d_x = c5_c_x;
  c5_d_x = muDoubleScalarSin(c5_d_x);
  c5_d_a = c5_CC_mtx[1];
  c5_f_b = c5_d_x;
  c5_f_y = c5_d_a * c5_f_b;
  c5_g_b = c5_CC_mtx[5];
  c5_g_y = 6.2831853071795862 * c5_g_b;
  c5_e_a = c5_g_y;
  c5_h_b = c5_t;
  c5_h_y = c5_e_a * c5_h_b;
  c5_e_x = c5_h_y + c5_CC_mtx[8];
  c5_f_x = c5_e_x;
  c5_f_x = muDoubleScalarSin(c5_f_x);
  c5_f_a = c5_CC_mtx[2];
  c5_i_b = c5_f_x;
  c5_i_y = c5_f_a * c5_i_b;
  c5_j_y[0] = c5_c_y + c5_CC_mtx[9];
  c5_j_y[1] = c5_f_y + c5_CC_mtx[10];
  c5_j_y[2] = c5_i_y + c5_CC_mtx[11];
  for (c5_i8 = 0; c5_i8 < 3; c5_i8++) {
    c5_CC[c5_i8] = c5_j_y[c5_i8];
  }

  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, -13);
  _SFD_SYMBOL_SCOPE_POP();
  for (c5_i9 = 0; c5_i9 < 3; c5_i9++) {
    (*c5_b_CC)[c5_i9] = c5_CC[c5_i9];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, chartInstance->c5_sfEvent);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_Symmetry_Inverter_imaginedMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc5_Symmetry_Inverter_imagined
  (SFc5_Symmetry_Inverter_imaginedInstanceStruct *chartInstance)
{
}

static void registerMessagesc5_Symmetry_Inverter_imagined
  (SFc5_Symmetry_Inverter_imaginedInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c5_machineNumber, uint32_T
  c5_chartNumber)
{
}

static const mxArray *c5_sf_marshallOut(void *chartInstanceVoid, void *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i10;
  real_T c5_b_inData[3];
  int32_T c5_i11;
  real_T c5_u[3];
  const mxArray *c5_y = NULL;
  SFc5_Symmetry_Inverter_imaginedInstanceStruct *chartInstance;
  chartInstance = (SFc5_Symmetry_Inverter_imaginedInstanceStruct *)
    chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  for (c5_i10 = 0; c5_i10 < 3; c5_i10++) {
    c5_b_inData[c5_i10] = (*(real_T (*)[3])c5_inData)[c5_i10];
  }

  for (c5_i11 = 0; c5_i11 < 3; c5_i11++) {
    c5_u[c5_i11] = c5_b_inData[c5_i11];
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, FALSE);
  return c5_mxArrayOutData;
}

static void c5_emlrt_marshallIn(SFc5_Symmetry_Inverter_imaginedInstanceStruct
  *chartInstance, const mxArray *c5_CC, const char_T *c5_identifier, real_T
  c5_y[3])
{
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_CC), &c5_thisId, c5_y);
  sf_mex_destroy(&c5_CC);
}

static void c5_b_emlrt_marshallIn(SFc5_Symmetry_Inverter_imaginedInstanceStruct *
  chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId,
  real_T c5_y[3])
{
  real_T c5_dv1[3];
  int32_T c5_i12;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), c5_dv1, 1, 0, 0U, 1, 0U, 1, 3);
  for (c5_i12 = 0; c5_i12 < 3; c5_i12++) {
    c5_y[c5_i12] = c5_dv1[c5_i12];
  }

  sf_mex_destroy(&c5_u);
}

static void c5_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_CC;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  real_T c5_y[3];
  int32_T c5_i13;
  SFc5_Symmetry_Inverter_imaginedInstanceStruct *chartInstance;
  chartInstance = (SFc5_Symmetry_Inverter_imaginedInstanceStruct *)
    chartInstanceVoid;
  c5_CC = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_CC), &c5_thisId, c5_y);
  sf_mex_destroy(&c5_CC);
  for (c5_i13 = 0; c5_i13 < 3; c5_i13++) {
    (*(real_T (*)[3])c5_outData)[c5_i13] = c5_y[c5_i13];
  }

  sf_mex_destroy(&c5_mxArrayInData);
}

static const mxArray *c5_b_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  real_T c5_u;
  const mxArray *c5_y = NULL;
  SFc5_Symmetry_Inverter_imaginedInstanceStruct *chartInstance;
  chartInstance = (SFc5_Symmetry_Inverter_imaginedInstanceStruct *)
    chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_u = *(real_T *)c5_inData;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", &c5_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, FALSE);
  return c5_mxArrayOutData;
}

static real_T c5_c_emlrt_marshallIn
  (SFc5_Symmetry_Inverter_imaginedInstanceStruct *chartInstance, const mxArray
   *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  real_T c5_y;
  real_T c5_d0;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_d0, 1, 0, 0U, 0, 0U, 0);
  c5_y = c5_d0;
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static void c5_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_nargout;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  real_T c5_y;
  SFc5_Symmetry_Inverter_imaginedInstanceStruct *chartInstance;
  chartInstance = (SFc5_Symmetry_Inverter_imaginedInstanceStruct *)
    chartInstanceVoid;
  c5_nargout = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_nargout), &c5_thisId);
  sf_mex_destroy(&c5_nargout);
  *(real_T *)c5_outData = c5_y;
  sf_mex_destroy(&c5_mxArrayInData);
}

static const mxArray *c5_c_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i14;
  int32_T c5_i15;
  int32_T c5_i16;
  real_T c5_b_inData[12];
  int32_T c5_i17;
  int32_T c5_i18;
  int32_T c5_i19;
  real_T c5_u[12];
  const mxArray *c5_y = NULL;
  SFc5_Symmetry_Inverter_imaginedInstanceStruct *chartInstance;
  chartInstance = (SFc5_Symmetry_Inverter_imaginedInstanceStruct *)
    chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_i14 = 0;
  for (c5_i15 = 0; c5_i15 < 4; c5_i15++) {
    for (c5_i16 = 0; c5_i16 < 3; c5_i16++) {
      c5_b_inData[c5_i16 + c5_i14] = (*(real_T (*)[12])c5_inData)[c5_i16 +
        c5_i14];
    }

    c5_i14 += 3;
  }

  c5_i17 = 0;
  for (c5_i18 = 0; c5_i18 < 4; c5_i18++) {
    for (c5_i19 = 0; c5_i19 < 3; c5_i19++) {
      c5_u[c5_i19 + c5_i17] = c5_b_inData[c5_i19 + c5_i17];
    }

    c5_i17 += 3;
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 0, 0U, 1U, 0U, 2, 3, 4), FALSE);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, FALSE);
  return c5_mxArrayOutData;
}

static void c5_d_emlrt_marshallIn(SFc5_Symmetry_Inverter_imaginedInstanceStruct *
  chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId,
  real_T c5_y[12])
{
  real_T c5_dv2[12];
  int32_T c5_i20;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), c5_dv2, 1, 0, 0U, 1, 0U, 2, 3, 4);
  for (c5_i20 = 0; c5_i20 < 12; c5_i20++) {
    c5_y[c5_i20] = c5_dv2[c5_i20];
  }

  sf_mex_destroy(&c5_u);
}

static void c5_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_CC_mtx;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  real_T c5_y[12];
  int32_T c5_i21;
  int32_T c5_i22;
  int32_T c5_i23;
  SFc5_Symmetry_Inverter_imaginedInstanceStruct *chartInstance;
  chartInstance = (SFc5_Symmetry_Inverter_imaginedInstanceStruct *)
    chartInstanceVoid;
  c5_CC_mtx = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_CC_mtx), &c5_thisId, c5_y);
  sf_mex_destroy(&c5_CC_mtx);
  c5_i21 = 0;
  for (c5_i22 = 0; c5_i22 < 4; c5_i22++) {
    for (c5_i23 = 0; c5_i23 < 3; c5_i23++) {
      (*(real_T (*)[12])c5_outData)[c5_i23 + c5_i21] = c5_y[c5_i23 + c5_i21];
    }

    c5_i21 += 3;
  }

  sf_mex_destroy(&c5_mxArrayInData);
}

const mxArray *sf_c5_Symmetry_Inverter_imagined_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c5_nameCaptureInfo;
  c5_ResolvedFunctionInfo c5_info[3];
  c5_ResolvedFunctionInfo (*c5_b_info)[3];
  const mxArray *c5_m0 = NULL;
  int32_T c5_i24;
  c5_ResolvedFunctionInfo *c5_r0;
  c5_nameCaptureInfo = NULL;
  c5_nameCaptureInfo = NULL;
  c5_b_info = (c5_ResolvedFunctionInfo (*)[3])c5_info;
  (*c5_b_info)[0].context = "";
  (*c5_b_info)[0].name = "mtimes";
  (*c5_b_info)[0].dominantType = "double";
  (*c5_b_info)[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c5_b_info)[0].fileTimeLo = 1289519692U;
  (*c5_b_info)[0].fileTimeHi = 0U;
  (*c5_b_info)[0].mFileTimeLo = 0U;
  (*c5_b_info)[0].mFileTimeHi = 0U;
  (*c5_b_info)[1].context = "";
  (*c5_b_info)[1].name = "sin";
  (*c5_b_info)[1].dominantType = "double";
  (*c5_b_info)[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  (*c5_b_info)[1].fileTimeLo = 1343830386U;
  (*c5_b_info)[1].fileTimeHi = 0U;
  (*c5_b_info)[1].mFileTimeLo = 0U;
  (*c5_b_info)[1].mFileTimeHi = 0U;
  (*c5_b_info)[2].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  (*c5_b_info)[2].name = "eml_scalar_sin";
  (*c5_b_info)[2].dominantType = "double";
  (*c5_b_info)[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  (*c5_b_info)[2].fileTimeLo = 1286818736U;
  (*c5_b_info)[2].fileTimeHi = 0U;
  (*c5_b_info)[2].mFileTimeLo = 0U;
  (*c5_b_info)[2].mFileTimeHi = 0U;
  sf_mex_assign(&c5_m0, sf_mex_createstruct("nameCaptureInfo", 1, 3), FALSE);
  for (c5_i24 = 0; c5_i24 < 3; c5_i24++) {
    c5_r0 = &c5_info[c5_i24];
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", c5_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c5_r0->context)), "context", "nameCaptureInfo",
                    c5_i24);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", c5_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c5_r0->name)), "name", "nameCaptureInfo", c5_i24);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", c5_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c5_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c5_i24);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", c5_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c5_r0->resolved)), "resolved", "nameCaptureInfo",
                    c5_i24);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", &c5_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c5_i24);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", &c5_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c5_i24);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", &c5_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c5_i24);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", &c5_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c5_i24);
  }

  sf_mex_assign(&c5_nameCaptureInfo, c5_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c5_nameCaptureInfo);
  return c5_nameCaptureInfo;
}

static const mxArray *c5_d_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_u;
  const mxArray *c5_y = NULL;
  SFc5_Symmetry_Inverter_imaginedInstanceStruct *chartInstance;
  chartInstance = (SFc5_Symmetry_Inverter_imaginedInstanceStruct *)
    chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_u = *(int32_T *)c5_inData;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", &c5_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, FALSE);
  return c5_mxArrayOutData;
}

static int32_T c5_e_emlrt_marshallIn
  (SFc5_Symmetry_Inverter_imaginedInstanceStruct *chartInstance, const mxArray
   *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  int32_T c5_y;
  int32_T c5_i25;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_i25, 1, 6, 0U, 0, 0U, 0);
  c5_y = c5_i25;
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static void c5_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_b_sfEvent;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  int32_T c5_y;
  SFc5_Symmetry_Inverter_imaginedInstanceStruct *chartInstance;
  chartInstance = (SFc5_Symmetry_Inverter_imaginedInstanceStruct *)
    chartInstanceVoid;
  c5_b_sfEvent = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_b_sfEvent),
    &c5_thisId);
  sf_mex_destroy(&c5_b_sfEvent);
  *(int32_T *)c5_outData = c5_y;
  sf_mex_destroy(&c5_mxArrayInData);
}

static uint8_T c5_f_emlrt_marshallIn
  (SFc5_Symmetry_Inverter_imaginedInstanceStruct *chartInstance, const mxArray
   *c5_b_is_active_c5_Symmetry_Inverter_imagined, const char_T *c5_identifier)
{
  uint8_T c5_y;
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c5_b_is_active_c5_Symmetry_Inverter_imagined), &c5_thisId);
  sf_mex_destroy(&c5_b_is_active_c5_Symmetry_Inverter_imagined);
  return c5_y;
}

static uint8_T c5_g_emlrt_marshallIn
  (SFc5_Symmetry_Inverter_imaginedInstanceStruct *chartInstance, const mxArray
   *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  uint8_T c5_y;
  uint8_T c5_u0;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_u0, 1, 3, 0U, 0, 0U, 0);
  c5_y = c5_u0;
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static void init_dsm_address_info(SFc5_Symmetry_Inverter_imaginedInstanceStruct *
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

void sf_c5_Symmetry_Inverter_imagined_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(870148927U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(950086832U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1694634316U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1788296179U);
}

mxArray *sf_c5_Symmetry_Inverter_imagined_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("1t6DQ7L01qAEXT9jUHJOd");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

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

mxArray *sf_c5_Symmetry_Inverter_imagined_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c5_Symmetry_Inverter_imagined(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"CC\",},{M[8],M[0],T\"is_active_c5_Symmetry_Inverter_imagined\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c5_Symmetry_Inverter_imagined_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc5_Symmetry_Inverter_imaginedInstanceStruct *chartInstance;
    chartInstance = (SFc5_Symmetry_Inverter_imaginedInstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Symmetry_Inverter_imaginedMachineNumber_,
           5,
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,632);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)
            c5_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          real_T *c5_t;
          real_T (*c5_amp)[3];
          real_T (*c5_CC)[3];
          real_T (*c5_phase)[3];
          c5_t = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c5_phase = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 1);
          c5_CC = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
          c5_amp = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c5_amp);
          _SFD_SET_DATA_VALUE_PTR(1U, *c5_CC);
          _SFD_SET_DATA_VALUE_PTR(2U, *c5_phase);
          _SFD_SET_DATA_VALUE_PTR(3U, c5_t);
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
  return "OOQvghDeQ1YeaC3nf6q7IC";
}

static void sf_opaque_initialize_c5_Symmetry_Inverter_imagined(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc5_Symmetry_Inverter_imaginedInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c5_Symmetry_Inverter_imagined
    ((SFc5_Symmetry_Inverter_imaginedInstanceStruct*) chartInstanceVar);
  initialize_c5_Symmetry_Inverter_imagined
    ((SFc5_Symmetry_Inverter_imaginedInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c5_Symmetry_Inverter_imagined(void
  *chartInstanceVar)
{
  enable_c5_Symmetry_Inverter_imagined
    ((SFc5_Symmetry_Inverter_imaginedInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c5_Symmetry_Inverter_imagined(void
  *chartInstanceVar)
{
  disable_c5_Symmetry_Inverter_imagined
    ((SFc5_Symmetry_Inverter_imaginedInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c5_Symmetry_Inverter_imagined(void
  *chartInstanceVar)
{
  sf_c5_Symmetry_Inverter_imagined
    ((SFc5_Symmetry_Inverter_imaginedInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c5_Symmetry_Inverter_imagined
  (SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c5_Symmetry_Inverter_imagined
    ((SFc5_Symmetry_Inverter_imaginedInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c5_Symmetry_Inverter_imagined();/* state var info */
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

extern void sf_internal_set_sim_state_c5_Symmetry_Inverter_imagined(SimStruct* S,
  const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c5_Symmetry_Inverter_imagined();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c5_Symmetry_Inverter_imagined
    ((SFc5_Symmetry_Inverter_imaginedInstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c5_Symmetry_Inverter_imagined
  (SimStruct* S)
{
  return sf_internal_get_sim_state_c5_Symmetry_Inverter_imagined(S);
}

static void sf_opaque_set_sim_state_c5_Symmetry_Inverter_imagined(SimStruct* S,
  const mxArray *st)
{
  sf_internal_set_sim_state_c5_Symmetry_Inverter_imagined(S, st);
}

static void sf_opaque_terminate_c5_Symmetry_Inverter_imagined(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc5_Symmetry_Inverter_imaginedInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Symmetry_Inverter_imagined_optimization_info();
    }

    finalize_c5_Symmetry_Inverter_imagined
      ((SFc5_Symmetry_Inverter_imaginedInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc5_Symmetry_Inverter_imagined
    ((SFc5_Symmetry_Inverter_imaginedInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c5_Symmetry_Inverter_imagined(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c5_Symmetry_Inverter_imagined
      ((SFc5_Symmetry_Inverter_imaginedInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c5_Symmetry_Inverter_imagined(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Symmetry_Inverter_imagined_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      5);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,5,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,5,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,5);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,5,3);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,5,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,5);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3154276884U));
  ssSetChecksum1(S,(2951922392U));
  ssSetChecksum2(S,(3611705973U));
  ssSetChecksum3(S,(2039645740U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c5_Symmetry_Inverter_imagined(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c5_Symmetry_Inverter_imagined(SimStruct *S)
{
  SFc5_Symmetry_Inverter_imaginedInstanceStruct *chartInstance;
  chartInstance = (SFc5_Symmetry_Inverter_imaginedInstanceStruct *)utMalloc
    (sizeof(SFc5_Symmetry_Inverter_imaginedInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc5_Symmetry_Inverter_imaginedInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c5_Symmetry_Inverter_imagined;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c5_Symmetry_Inverter_imagined;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c5_Symmetry_Inverter_imagined;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c5_Symmetry_Inverter_imagined;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c5_Symmetry_Inverter_imagined;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c5_Symmetry_Inverter_imagined;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c5_Symmetry_Inverter_imagined;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c5_Symmetry_Inverter_imagined;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c5_Symmetry_Inverter_imagined;
  chartInstance->chartInfo.mdlStart = mdlStart_c5_Symmetry_Inverter_imagined;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c5_Symmetry_Inverter_imagined;
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

void c5_Symmetry_Inverter_imagined_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c5_Symmetry_Inverter_imagined(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c5_Symmetry_Inverter_imagined(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c5_Symmetry_Inverter_imagined(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c5_Symmetry_Inverter_imagined_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
