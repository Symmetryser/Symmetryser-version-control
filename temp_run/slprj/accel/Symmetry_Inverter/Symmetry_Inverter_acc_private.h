#include "__cf_Symmetry_Inverter.h"
#ifndef RTW_HEADER_Symmetry_Inverter_acc_private_h_
#define RTW_HEADER_Symmetry_Inverter_acc_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#if !defined(ss_VALIDATE_MEMORY)
#define ss_VALIDATE_MEMORY(S, ptr)   if(!(ptr)) {\
  ssSetErrorStatus(S, RT_MEMORY_ALLOCATION_ERROR);\
  }
#endif
#if !defined(rt_FREE)
#if !defined(_WIN32)
#define rt_FREE(ptr)   if((ptr) != (NULL)) {\
  free((ptr));\
  (ptr) = (NULL);\
  }
#else
#define rt_FREE(ptr)   if((ptr) != (NULL)) {\
  free((void *)(ptr));\
  (ptr) = (NULL);\
  }
#endif
#endif
#ifndef __RTWTYPES_H__
#error This file requires rtwtypes.h to be included
#endif
void du0chwvarz ( SimStruct * const S , uint8_T ksk2pleye5 , real_T
mrsjjo1pm3 , aqltkq4cux * localB , ho5bisyg5s * localDW , kpxnznidsa *
localZCE ) ;
#endif
