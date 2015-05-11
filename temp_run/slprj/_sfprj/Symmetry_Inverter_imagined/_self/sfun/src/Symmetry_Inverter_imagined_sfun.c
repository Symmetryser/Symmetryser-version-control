/* Include files */

#include "Symmetry_Inverter_imagined_sfun.h"
#include "Symmetry_Inverter_imagined_sfun_debug_macros.h"
#include "c1_Symmetry_Inverter_imagined.h"
#include "c3_Symmetry_Inverter_imagined.h"
#include "c4_Symmetry_Inverter_imagined.h"
#include "c5_Symmetry_Inverter_imagined.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _Symmetry_Inverter_imaginedMachineNumber_;
real_T _sfTime_;

/* Function Declarations */

/* Function Definitions */
void Symmetry_Inverter_imagined_initializer(void)
{
}

void Symmetry_Inverter_imagined_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_Symmetry_Inverter_imagined_method_dispatcher(SimStruct
  *simstructPtr, unsigned int chartFileNumber, const char* specsCksum, int_T
  method, void *data)
{
  if (chartFileNumber==1) {
    c1_Symmetry_Inverter_imagined_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==3) {
    c3_Symmetry_Inverter_imagined_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==4) {
    c4_Symmetry_Inverter_imagined_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==5) {
    c5_Symmetry_Inverter_imagined_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

unsigned int sf_Symmetry_Inverter_imagined_process_check_sum_call( int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[20];
  if (nrhs<1 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the checksum */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"sf_get_check_sum"))
    return 0;
  plhs[0] = mxCreateDoubleMatrix( 1,4,mxREAL);
  if (nrhs>1 && mxIsChar(prhs[1])) {
    mxGetString(prhs[1], commandName,sizeof(commandName)/sizeof(char));
    commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
    if (!strcmp(commandName,"machine")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(514552180U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3635861611U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(29953782U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2046746597U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(26462945U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3054059497U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(4086618368U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2167780738U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 1:
        {
          extern void sf_c1_Symmetry_Inverter_imagined_get_check_sum(mxArray
            *plhs[]);
          sf_c1_Symmetry_Inverter_imagined_get_check_sum(plhs);
          break;
        }

       case 3:
        {
          extern void sf_c3_Symmetry_Inverter_imagined_get_check_sum(mxArray
            *plhs[]);
          sf_c3_Symmetry_Inverter_imagined_get_check_sum(plhs);
          break;
        }

       case 4:
        {
          extern void sf_c4_Symmetry_Inverter_imagined_get_check_sum(mxArray
            *plhs[]);
          sf_c4_Symmetry_Inverter_imagined_get_check_sum(plhs);
          break;
        }

       case 5:
        {
          extern void sf_c5_Symmetry_Inverter_imagined_get_check_sum(mxArray
            *plhs[]);
          sf_c5_Symmetry_Inverter_imagined_get_check_sum(plhs);
          break;
        }

       default:
        ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0.0);
      }
    } else if (!strcmp(commandName,"target")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3564696471U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(678668628U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1090454852U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3896867807U);
    } else {
      return 0;
    }
  } else {
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2702894331U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1848812169U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2870661965U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3723092825U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_Symmetry_Inverter_imagined_autoinheritance_info( int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[32];
  char aiChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the autoinheritance_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_autoinheritance_info"))
    return 0;
  mxGetString(prhs[2], aiChksum,sizeof(aiChksum)/sizeof(char));
  aiChksum[(sizeof(aiChksum)/sizeof(char)-1)] = '\0';

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(aiChksum, "WwfmAdrfE2U9F4ttUXOw6E") == 0) {
          extern mxArray
            *sf_c1_Symmetry_Inverter_imagined_get_autoinheritance_info(void);
          plhs[0] = sf_c1_Symmetry_Inverter_imagined_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 3:
      {
        if (strcmp(aiChksum, "NrBsKEkFV12tmzXsduVsZB") == 0) {
          extern mxArray
            *sf_c3_Symmetry_Inverter_imagined_get_autoinheritance_info(void);
          plhs[0] = sf_c3_Symmetry_Inverter_imagined_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 4:
      {
        if (strcmp(aiChksum, "kWdqI56RZmoy4NIG1OdcKE") == 0) {
          extern mxArray
            *sf_c4_Symmetry_Inverter_imagined_get_autoinheritance_info(void);
          plhs[0] = sf_c4_Symmetry_Inverter_imagined_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 5:
      {
        if (strcmp(aiChksum, "1t6DQ7L01qAEXT9jUHJOd") == 0) {
          extern mxArray
            *sf_c5_Symmetry_Inverter_imagined_get_autoinheritance_info(void);
          plhs[0] = sf_c5_Symmetry_Inverter_imagined_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_Symmetry_Inverter_imagined_get_eml_resolved_functions_info( int
  nlhs, mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[64];
  if (nrhs<2 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the get_eml_resolved_functions_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_eml_resolved_functions_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        extern const mxArray
          *sf_c1_Symmetry_Inverter_imagined_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c1_Symmetry_Inverter_imagined_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 3:
      {
        extern const mxArray
          *sf_c3_Symmetry_Inverter_imagined_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c3_Symmetry_Inverter_imagined_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 4:
      {
        extern const mxArray
          *sf_c4_Symmetry_Inverter_imagined_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c4_Symmetry_Inverter_imagined_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 5:
      {
        extern const mxArray
          *sf_c5_Symmetry_Inverter_imagined_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c5_Symmetry_Inverter_imagined_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_Symmetry_Inverter_imagined_third_party_uses_info( int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{
  char commandName[64];
  char tpChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the third_party_uses_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  mxGetString(prhs[2], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_third_party_uses_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(tpChksum, "ktYHmvfGc85gfcdboGS9jE") == 0) {
          extern mxArray *sf_c1_Symmetry_Inverter_imagined_third_party_uses_info
            (void);
          plhs[0] = sf_c1_Symmetry_Inverter_imagined_third_party_uses_info();
          break;
        }
      }

     case 3:
      {
        if (strcmp(tpChksum, "iFEmVdwOmuRS3l88HaCuD") == 0) {
          extern mxArray *sf_c3_Symmetry_Inverter_imagined_third_party_uses_info
            (void);
          plhs[0] = sf_c3_Symmetry_Inverter_imagined_third_party_uses_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "iSMDRJtdsuRUsnAaL3F3j") == 0) {
          extern mxArray *sf_c4_Symmetry_Inverter_imagined_third_party_uses_info
            (void);
          plhs[0] = sf_c4_Symmetry_Inverter_imagined_third_party_uses_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "OOQvghDeQ1YeaC3nf6q7IC") == 0) {
          extern mxArray *sf_c5_Symmetry_Inverter_imagined_third_party_uses_info
            (void);
          plhs[0] = sf_c5_Symmetry_Inverter_imagined_third_party_uses_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

void Symmetry_Inverter_imagined_debug_initialize(struct SfDebugInstanceStruct*
  debugInstance)
{
  _Symmetry_Inverter_imaginedMachineNumber_ = sf_debug_initialize_machine
    (debugInstance,"Symmetry_Inverter_imagined","sfun",0,4,0,0,0);
  sf_debug_set_machine_event_thresholds(debugInstance,
    _Symmetry_Inverter_imaginedMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(debugInstance,
    _Symmetry_Inverter_imaginedMachineNumber_,0);
}

void Symmetry_Inverter_imagined_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_Symmetry_Inverter_imagined_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info(
      "Symmetry_Inverter_imagined", "Symmetry_Inverter_imagined");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_Symmetry_Inverter_imagined_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}
