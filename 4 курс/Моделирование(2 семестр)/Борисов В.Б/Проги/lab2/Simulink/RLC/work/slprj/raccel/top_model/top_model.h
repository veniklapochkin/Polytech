#include "__cf_top_model.h"
#ifndef RTW_HEADER_top_model_h_
#define RTW_HEADER_top_model_h_
#include <stddef.h>
#include <string.h>
#include "rtw_modelmap.h"
#ifndef top_model_COMMON_INCLUDES_
#define top_model_COMMON_INCLUDES_
#include <stdlib.h>
#include "rtwtypes.h"
#include "sigstream_rtw.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "raccel.h"
#include "rt_logging.h"
#include "dt_info.h"
#include "ext_work.h"
#endif
#include "top_model_types.h"
#include "multiword_types.h"
#include "rt_defines.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#define MODEL_NAME top_model
#define NSAMPLE_TIMES (3) 
#define NINPUTS (0)       
#define NOUTPUTS (0)     
#define NBLOCKIO (8) 
#define NUM_ZC_EVENTS (0) 
#ifndef NCSTATES
#define NCSTATES (2)   
#elif NCSTATES != 2
#error Invalid specification of NCSTATES defined in compiler command
#endif
#ifndef rtmGetDataMapInfo
#define rtmGetDataMapInfo(rtm) (*rt_dataMapInfoPtr)
#endif
#ifndef rtmSetDataMapInfo
#define rtmSetDataMapInfo(rtm, val) (rt_dataMapInfoPtr = &val)
#endif
#ifndef IN_RACCEL_MAIN
#endif
typedef struct { real_T lqz5eb13m5 ; real_T gcepvrppvm ; real_T hey4rg5ecd [
3 ] ; real_T b0e4zv5wkz ; real_T ibavoiuhze ; real_T mjhba54g25 ; real_T
lforaawtak ; real_T j4r0modjy1 ; } B ; typedef struct { real_T jfqhxizyfp ;
void * lhk1ptgr5q [ 19 ] ; struct { void * LoggedData [ 2 ] ; } oeogfugera ;
int_T pkwq4ihcru [ 9 ] ; int_T mgu5fmgbhc ; boolean_T b223zlexoi ; } DW ;
typedef struct { real_T gdqxzxc4pa [ 2 ] ; } X ; typedef struct { real_T
gdqxzxc4pa [ 2 ] ; } XDot ; typedef struct { boolean_T gdqxzxc4pa [ 2 ] ; }
XDis ; typedef struct { real_T gdqxzxc4pa [ 2 ] ; } CStateAbsTol ; typedef
struct { real_T hsunwt3h0f [ 2 ] ; real_T nmpkc1oxeh ; } ZCV ; typedef struct
{ rtwCAPI_ModelMappingInfo mmi ; } DataMapInfo ; struct P_ { real_T
DCVoltageSource_Amplitude ; real_T uRsw_Gain ; real_T SwitchCurrents_Value ;
real_T StateSpace_P1_Size [ 2 ] ; real_T StateSpace_P1 [ 4 ] ; real_T
StateSpace_P2_Size [ 2 ] ; real_T StateSpace_P2 [ 4 ] ; real_T
StateSpace_P3_Size [ 2 ] ; real_T StateSpace_P3 [ 6 ] ; real_T
StateSpace_P4_Size [ 2 ] ; real_T StateSpace_P4 [ 6 ] ; real_T
StateSpace_P5_Size [ 2 ] ; real_T StateSpace_P5 [ 2 ] ; real_T
StateSpace_P6_Size [ 2 ] ; real_T StateSpace_P6 ; real_T StateSpace_P7_Size [
2 ] ; real_T StateSpace_P7 ; real_T StateSpace_P8_Size [ 2 ] ; real_T
StateSpace_P8 ; real_T StateSpace_P9_Size [ 2 ] ; real_T StateSpace_P9 ;
real_T StateSpace_P10_Size [ 2 ] ; real_T StateSpace_P10 ; real_T
StateSpace_P11_Size [ 2 ] ; real_T StateSpace_P11 ; real_T
StateSpace_P12_Size [ 2 ] ; real_T StateSpace_P12 ; real_T u1_Value ; real_T
Switch_Threshold ; real_T Step_Time ; real_T Step_Y0 ; real_T Step_YFinal ;
real_T donotdeletethisgain_Gain ; real_T donotdeletethisgain_Gain_hmfyrmqciv
; } ; extern const char * RT_MEMORY_ALLOCATION_ERROR ; extern B rtB ; extern
X rtX ; extern DW rtDW ; extern P rtP ; extern const
rtwCAPI_ModelMappingStaticInfo * top_model_GetCAPIStaticMap ( void ) ; extern
SimStruct * const rtS ; extern const int_T gblNumToFiles ; extern const int_T
gblNumFrFiles ; extern const int_T gblNumFrWksBlocks ; extern rtInportTUtable
* gblInportTUtables ; extern const char * gblInportFileName ; extern const
int_T gblNumRootInportBlks ; extern const int_T gblNumModelInputs ; extern
const int_T gblInportDataTypeIdx [ ] ; extern const int_T gblInportDims [ ] ;
extern const int_T gblInportComplex [ ] ; extern const int_T
gblInportInterpoFlag [ ] ; extern const int_T gblInportContinuous [ ] ;
extern const int_T gblParameterTuningTid ; extern DataMapInfo *
rt_dataMapInfoPtr ; extern rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr ;
void MdlOutputs ( int_T tid ) ; void MdlOutputsParameterSampleTime ( int_T
tid ) ; void MdlUpdate ( int_T tid ) ; void MdlTerminate ( void ) ; void
MdlInitializeSizes ( void ) ; void MdlInitializeSampleTimes ( void ) ;
SimStruct * raccel_register_model ( void ) ;
#endif
