/* Include files */

#include "Symmetry_Inverter_imagined_sfun.h"
#include "Symmetry_Inverter_imagined_sfun_debug_macros.h"
#include "c1_Symmetry_Inverter_imagined.h"
#include "c2_Symmetry_Inverter_imagined.h"
#include "c3_Symmetry_Inverter_imagined.h"
#include "c4_Symmetry_Inverter_imagined.h"
#include "c5_Symmetry_Inverter_imagined.h"
#include "c6_Symmetry_Inverter_imagined.h"
#include "c7_Symmetry_Inverter_imagined.h"
#include "c8_Symmetry_Inverter_imagined.h"
#include "c9_Symmetry_Inverter_imagined.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _Symmetry_Inverter_imaginedMachineNumber_;

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

  if (chartFileNumber==2) {
    c2_Symmetry_Inverter_imagined_method_dispatcher(simstructPtr, method, data);
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

  if (chartFileNumber==6) {
    c6_Symmetry_Inverter_imagined_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==7) {
    c7_Symmetry_Inverter_imagined_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==8) {
    c8_Symmetry_Inverter_imagined_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==9) {
    c9_Symmetry_Inverter_imagined_method_dispatcher(simstructPtr, method, data);
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
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2382311335U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1640222560U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3102473200U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(10949680U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(674415114U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2426248082U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1000325487U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3683618400U);
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

       case 2:
        {
          extern void sf_c2_Symmetry_Inverter_imagined_get_check_sum(mxArray
            *plhs[]);
          sf_c2_Symmetry_Inverter_imagined_get_check_sum(plhs);
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

       case 6:
        {
          extern void sf_c6_Symmetry_Inverter_imagined_get_check_sum(mxArray
            *plhs[]);
          sf_c6_Symmetry_Inverter_imagined_get_check_sum(plhs);
          break;
        }

       case 7:
        {
          extern void sf_c7_Symmetry_Inverter_imagined_get_check_sum(mxArray
            *plhs[]);
          sf_c7_Symmetry_Inverter_imagined_get_check_sum(plhs);
          break;
        }

       case 8:
        {
          extern void sf_c8_Symmetry_Inverter_imagined_get_check_sum(mxArray
            *plhs[]);
          sf_c8_Symmetry_Inverter_imagined_get_check_sum(plhs);
          break;
        }

       case 9:
        {
          extern void sf_c9_Symmetry_Inverter_imagined_get_check_sum(mxArray
            *plhs[]);
          sf_c9_Symmetry_Inverter_imagined_get_check_sum(plhs);
          break;
        }

       default:
        ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0.0);
      }
    } else if (!strcmp(commandName,"target")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3031367619U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(4001028638U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3978939492U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(838979348U);
    } else {
      return 0;
    }
  } else {
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(235139219U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1967682663U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3410707366U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1668312237U);
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
        if (strcmp(aiChksum, "jYDvlzojYbJaGjzWCJwAFD") == 0) {
          extern mxArray
            *sf_c1_Symmetry_Inverter_imagined_get_autoinheritance_info(void);
          plhs[0] = sf_c1_Symmetry_Inverter_imagined_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 2:
      {
        if (strcmp(aiChksum, "fCnnemRVuE1bwmfCuBnifC") == 0) {
          extern mxArray
            *sf_c2_Symmetry_Inverter_imagined_get_autoinheritance_info(void);
          plhs[0] = sf_c2_Symmetry_Inverter_imagined_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 3:
      {
        if (strcmp(aiChksum, "c2Sajbvn8gke6gpn5No10") == 0) {
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
        if (strcmp(aiChksum, "QhAUgpc9OAd5Vl0psdYwnF") == 0) {
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
        if (strcmp(aiChksum, "cUHvHJHPjVDDEQG4SfhjXD") == 0) {
          extern mxArray
            *sf_c5_Symmetry_Inverter_imagined_get_autoinheritance_info(void);
          plhs[0] = sf_c5_Symmetry_Inverter_imagined_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 6:
      {
        if (strcmp(aiChksum, "ZMplEWZRgRo1fa7IfwcVIF") == 0) {
          extern mxArray
            *sf_c6_Symmetry_Inverter_imagined_get_autoinheritance_info(void);
          plhs[0] = sf_c6_Symmetry_Inverter_imagined_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 7:
      {
        if (strcmp(aiChksum, "vMhR4D5JT80Z84n4PjNq8E") == 0) {
          extern mxArray
            *sf_c7_Symmetry_Inverter_imagined_get_autoinheritance_info(void);
          plhs[0] = sf_c7_Symmetry_Inverter_imagined_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 8:
      {
        if (strcmp(aiChksum, "jwac9r7nLnPpdIyo5bPL4F") == 0) {
          extern mxArray
            *sf_c8_Symmetry_Inverter_imagined_get_autoinheritance_info(void);
          plhs[0] = sf_c8_Symmetry_Inverter_imagined_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 9:
      {
        if (strcmp(aiChksum, "47fitrQjJJEhtmVAJKMhME") == 0) {
          extern mxArray
            *sf_c9_Symmetry_Inverter_imagined_get_autoinheritance_info(void);
          plhs[0] = sf_c9_Symmetry_Inverter_imagined_get_autoinheritance_info();
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

     case 2:
      {
        extern const mxArray
          *sf_c2_Symmetry_Inverter_imagined_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c2_Symmetry_Inverter_imagined_get_eml_resolved_functions_info();
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

     case 6:
      {
        extern const mxArray
          *sf_c6_Symmetry_Inverter_imagined_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c6_Symmetry_Inverter_imagined_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 7:
      {
        extern const mxArray
          *sf_c7_Symmetry_Inverter_imagined_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c7_Symmetry_Inverter_imagined_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 8:
      {
        extern const mxArray
          *sf_c8_Symmetry_Inverter_imagined_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c8_Symmetry_Inverter_imagined_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 9:
      {
        extern const mxArray
          *sf_c9_Symmetry_Inverter_imagined_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c9_Symmetry_Inverter_imagined_get_eml_resolved_functions_info();
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
        if (strcmp(tpChksum, "vE4bR4eYnhWFkpZ9XgRP0B") == 0) {
          extern mxArray *sf_c1_Symmetry_Inverter_imagined_third_party_uses_info
            (void);
          plhs[0] = sf_c1_Symmetry_Inverter_imagined_third_party_uses_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "2de6fo8dsPzZpfV58c3EKB") == 0) {
          extern mxArray *sf_c2_Symmetry_Inverter_imagined_third_party_uses_info
            (void);
          plhs[0] = sf_c2_Symmetry_Inverter_imagined_third_party_uses_info();
          break;
        }
      }

     case 3:
      {
        if (strcmp(tpChksum, "qcN13yKCf8Ftf1h9Om0RBE") == 0) {
          extern mxArray *sf_c3_Symmetry_Inverter_imagined_third_party_uses_info
            (void);
          plhs[0] = sf_c3_Symmetry_Inverter_imagined_third_party_uses_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "YIaMBM7SupfD9bzeEWnNrG") == 0) {
          extern mxArray *sf_c4_Symmetry_Inverter_imagined_third_party_uses_info
            (void);
          plhs[0] = sf_c4_Symmetry_Inverter_imagined_third_party_uses_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "EGsFrEYoiSVjDey8aIqU2E") == 0) {
          extern mxArray *sf_c5_Symmetry_Inverter_imagined_third_party_uses_info
            (void);
          plhs[0] = sf_c5_Symmetry_Inverter_imagined_third_party_uses_info();
          break;
        }
      }

     case 6:
      {
        if (strcmp(tpChksum, "uCfp4CsfZCSSr4U6xkaGAH") == 0) {
          extern mxArray *sf_c6_Symmetry_Inverter_imagined_third_party_uses_info
            (void);
          plhs[0] = sf_c6_Symmetry_Inverter_imagined_third_party_uses_info();
          break;
        }
      }

     case 7:
      {
        if (strcmp(tpChksum, "qDhNM2IE42v8vru5dChpD") == 0) {
          extern mxArray *sf_c7_Symmetry_Inverter_imagined_third_party_uses_info
            (void);
          plhs[0] = sf_c7_Symmetry_Inverter_imagined_third_party_uses_info();
          break;
        }
      }

     case 8:
      {
        if (strcmp(tpChksum, "54PCtZaH7UMNwYzD02S8cE") == 0) {
          extern mxArray *sf_c8_Symmetry_Inverter_imagined_third_party_uses_info
            (void);
          plhs[0] = sf_c8_Symmetry_Inverter_imagined_third_party_uses_info();
          break;
        }
      }

     case 9:
      {
        if (strcmp(tpChksum, "qzMxhTGgGdzMQxLjHWJ9LB") == 0) {
          extern mxArray *sf_c9_Symmetry_Inverter_imagined_third_party_uses_info
            (void);
          plhs[0] = sf_c9_Symmetry_Inverter_imagined_third_party_uses_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

unsigned int sf_Symmetry_Inverter_imagined_updateBuildInfo_args_info( int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{
  char commandName[64];
  char tpChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the updateBuildInfo_args_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  mxGetString(prhs[2], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_updateBuildInfo_args_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(tpChksum, "vE4bR4eYnhWFkpZ9XgRP0B") == 0) {
          extern mxArray
            *sf_c1_Symmetry_Inverter_imagined_updateBuildInfo_args_info(void);
          plhs[0] = sf_c1_Symmetry_Inverter_imagined_updateBuildInfo_args_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "2de6fo8dsPzZpfV58c3EKB") == 0) {
          extern mxArray
            *sf_c2_Symmetry_Inverter_imagined_updateBuildInfo_args_info(void);
          plhs[0] = sf_c2_Symmetry_Inverter_imagined_updateBuildInfo_args_info();
          break;
        }
      }

     case 3:
      {
        if (strcmp(tpChksum, "qcN13yKCf8Ftf1h9Om0RBE") == 0) {
          extern mxArray
            *sf_c3_Symmetry_Inverter_imagined_updateBuildInfo_args_info(void);
          plhs[0] = sf_c3_Symmetry_Inverter_imagined_updateBuildInfo_args_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "YIaMBM7SupfD9bzeEWnNrG") == 0) {
          extern mxArray
            *sf_c4_Symmetry_Inverter_imagined_updateBuildInfo_args_info(void);
          plhs[0] = sf_c4_Symmetry_Inverter_imagined_updateBuildInfo_args_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "EGsFrEYoiSVjDey8aIqU2E") == 0) {
          extern mxArray
            *sf_c5_Symmetry_Inverter_imagined_updateBuildInfo_args_info(void);
          plhs[0] = sf_c5_Symmetry_Inverter_imagined_updateBuildInfo_args_info();
          break;
        }
      }

     case 6:
      {
        if (strcmp(tpChksum, "uCfp4CsfZCSSr4U6xkaGAH") == 0) {
          extern mxArray
            *sf_c6_Symmetry_Inverter_imagined_updateBuildInfo_args_info(void);
          plhs[0] = sf_c6_Symmetry_Inverter_imagined_updateBuildInfo_args_info();
          break;
        }
      }

     case 7:
      {
        if (strcmp(tpChksum, "qDhNM2IE42v8vru5dChpD") == 0) {
          extern mxArray
            *sf_c7_Symmetry_Inverter_imagined_updateBuildInfo_args_info(void);
          plhs[0] = sf_c7_Symmetry_Inverter_imagined_updateBuildInfo_args_info();
          break;
        }
      }

     case 8:
      {
        if (strcmp(tpChksum, "54PCtZaH7UMNwYzD02S8cE") == 0) {
          extern mxArray
            *sf_c8_Symmetry_Inverter_imagined_updateBuildInfo_args_info(void);
          plhs[0] = sf_c8_Symmetry_Inverter_imagined_updateBuildInfo_args_info();
          break;
        }
      }

     case 9:
      {
        if (strcmp(tpChksum, "qzMxhTGgGdzMQxLjHWJ9LB") == 0) {
          extern mxArray
            *sf_c9_Symmetry_Inverter_imagined_updateBuildInfo_args_info(void);
          plhs[0] = sf_c9_Symmetry_Inverter_imagined_updateBuildInfo_args_info();
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
    (debugInstance,"Symmetry_Inverter_imagined","sfun",0,9,0,0,0);
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
