#include "__cf_top_model.h"
#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "top_model_capi_host.h"
#define sizeof(s) ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el) ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s) (s)    
#else
#include "builtin_typeid_types.h"
#include "top_model.h"
#include "top_model_capi.h"
#include "top_model_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST                  
#define TARGET_STRING(s)               (NULL)                    
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif
static const rtwCAPI_Signals rtBlockSignals [ ] = { { 0 , 0 , TARGET_STRING (
"top_model/Step" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 1 , 0 ,
TARGET_STRING ( "top_model/Voltage Measurement/do not delete this gain" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 2 , 0 , TARGET_STRING (
"top_model/Voltage Measurement1/do not delete this gain" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 1 } , { 3 , 0 , TARGET_STRING (
"top_model/DC Voltage Source/Model/DC" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 ,
0 , 2 } , { 4 , 1 , TARGET_STRING ( "top_model/Ideal Switch/Model/1//Rsw" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 5 , 0 , TARGET_STRING (
"top_model/powergui/EquivalentModel1/State-Space" ) , TARGET_STRING ( "" ) ,
0 , 0 , 1 , 0 , 1 } , { 6 , 0 , TARGET_STRING (
"top_model/powergui/EquivalentModel1/State-Space" ) , TARGET_STRING ( "" ) ,
1 , 0 , 0 , 0 , 1 } , { 7 , 0 , TARGET_STRING (
"top_model/powergui/EquivalentModel1/Sources/SwitchCurrents" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 2 } , { 0 , 0 , ( NULL ) , ( NULL ) ,
0 , 0 , 0 , 0 , 0 } } ; static const rtwCAPI_BlockParameters
rtBlockParameters [ ] = { { 8 , TARGET_STRING ( "top_model/DC Voltage Source"
) , TARGET_STRING ( "Amplitude" ) , 0 , 0 , 0 } , { 9 , TARGET_STRING (
"top_model/Step" ) , TARGET_STRING ( "Time" ) , 0 , 0 , 0 } , { 10 ,
TARGET_STRING ( "top_model/Step" ) , TARGET_STRING ( "Before" ) , 0 , 0 , 0 }
, { 11 , TARGET_STRING ( "top_model/Step" ) , TARGET_STRING ( "After" ) , 0 ,
0 , 0 } , { 12 , TARGET_STRING (
"top_model/Voltage Measurement/do not delete this gain" ) , TARGET_STRING (
"Gain" ) , 0 , 0 , 0 } , { 13 , TARGET_STRING (
"top_model/Voltage Measurement1/do not delete this gain" ) , TARGET_STRING (
"Gain" ) , 0 , 0 , 0 } , { 14 , TARGET_STRING (
"top_model/Ideal Switch/Model/0 1" ) , TARGET_STRING ( "Value" ) , 0 , 0 , 0
} , { 15 , TARGET_STRING ( "top_model/Ideal Switch/Model/1//Rsw" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 16 , TARGET_STRING (
"top_model/Ideal Switch/Model/Switch" ) , TARGET_STRING ( "Threshold" ) , 0 ,
0 , 0 } , { 17 , TARGET_STRING (
"top_model/powergui/EquivalentModel1/State-Space" ) , TARGET_STRING ( "P1" )
, 0 , 2 , 0 } , { 18 , TARGET_STRING (
"top_model/powergui/EquivalentModel1/State-Space" ) , TARGET_STRING ( "P2" )
, 0 , 2 , 0 } , { 19 , TARGET_STRING (
"top_model/powergui/EquivalentModel1/State-Space" ) , TARGET_STRING ( "P3" )
, 0 , 3 , 0 } , { 20 , TARGET_STRING (
"top_model/powergui/EquivalentModel1/State-Space" ) , TARGET_STRING ( "P4" )
, 0 , 3 , 0 } , { 21 , TARGET_STRING (
"top_model/powergui/EquivalentModel1/State-Space" ) , TARGET_STRING ( "P5" )
, 0 , 4 , 0 } , { 22 , TARGET_STRING (
"top_model/powergui/EquivalentModel1/State-Space" ) , TARGET_STRING ( "P6" )
, 0 , 0 , 0 } , { 23 , TARGET_STRING (
"top_model/powergui/EquivalentModel1/State-Space" ) , TARGET_STRING ( "P7" )
, 0 , 0 , 0 } , { 24 , TARGET_STRING (
"top_model/powergui/EquivalentModel1/State-Space" ) , TARGET_STRING ( "P8" )
, 0 , 0 , 0 } , { 25 , TARGET_STRING (
"top_model/powergui/EquivalentModel1/State-Space" ) , TARGET_STRING ( "P9" )
, 0 , 0 , 0 } , { 26 , TARGET_STRING (
"top_model/powergui/EquivalentModel1/State-Space" ) , TARGET_STRING ( "P10" )
, 0 , 0 , 0 } , { 27 , TARGET_STRING (
"top_model/powergui/EquivalentModel1/State-Space" ) , TARGET_STRING ( "P11" )
, 0 , 0 , 0 } , { 28 , TARGET_STRING (
"top_model/powergui/EquivalentModel1/State-Space" ) , TARGET_STRING ( "P12" )
, 0 , 0 , 0 } , { 29 , TARGET_STRING (
"top_model/powergui/EquivalentModel1/Sources/SwitchCurrents" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 0 , ( NULL ) , ( NULL ) , 0 , 0 ,
0 } } ; static const rtwCAPI_ModelParameters rtModelParameters [ ] = { { 0 ,
( NULL ) , 0 , 0 , 0 } } ;
#ifndef HOST_CAPI_BUILD
static void * rtDataAddrMap [ ] = { & rtB . ibavoiuhze , & rtB . lforaawtak ,
& rtB . mjhba54g25 , & rtB . gcepvrppvm , & rtB . j4r0modjy1 , & rtB .
hey4rg5ecd [ 0 ] , & rtB . b0e4zv5wkz , & rtB . lqz5eb13m5 , & rtP .
DCVoltageSource_Amplitude , & rtP . Step_Time , & rtP . Step_Y0 , & rtP .
Step_YFinal , & rtP . donotdeletethisgain_Gain_hmfyrmqciv , & rtP .
donotdeletethisgain_Gain , & rtP . u1_Value , & rtP . uRsw_Gain , & rtP .
Switch_Threshold , & rtP . StateSpace_P1 [ 0 ] , & rtP . StateSpace_P2 [ 0 ]
, & rtP . StateSpace_P3 [ 0 ] , & rtP . StateSpace_P4 [ 0 ] , & rtP .
StateSpace_P5 [ 0 ] , & rtP . StateSpace_P6 , & rtP . StateSpace_P7 , & rtP .
StateSpace_P8 , & rtP . StateSpace_P9 , & rtP . StateSpace_P10 , & rtP .
StateSpace_P11 , & rtP . StateSpace_P12 , & rtP . SwitchCurrents_Value , } ;
static int32_T * rtVarDimsAddrMap [ ] = { ( NULL ) } ;
#endif
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap [ ] = { { "double" ,
"real_T" , 0 , 0 , sizeof ( real_T ) , SS_DOUBLE , 0 , 0 } } ;
#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif
static TARGET_CONST rtwCAPI_ElementMap rtElementMap [ ] = { { ( NULL ) , 0 ,
0 , 0 , 0 } , } ; static const rtwCAPI_DimensionMap rtDimensionMap [ ] = { {
rtwCAPI_SCALAR , 0 , 2 , 0 } , { rtwCAPI_VECTOR , 2 , 2 , 0 } , {
rtwCAPI_MATRIX_COL_MAJOR , 4 , 2 , 0 } , { rtwCAPI_MATRIX_COL_MAJOR , 6 , 2 ,
0 } , { rtwCAPI_VECTOR , 8 , 2 , 0 } } ; static const uint_T rtDimensionArray
[ ] = { 1 , 1 , 3 , 1 , 2 , 2 , 3 , 2 , 2 , 1 } ; static const real_T
rtcapiStoredFloats [ ] = { 1.0 , 0.0 } ; static const rtwCAPI_FixPtMap
rtFixPtMap [ ] = { { ( NULL ) , ( NULL ) , rtwCAPI_FIX_RESERVED , 0 , 0 , 0 }
, } ; static const rtwCAPI_SampleTimeMap rtSampleTimeMap [ ] = { { ( const
void * ) & rtcapiStoredFloats [ 0 ] , ( const void * ) & rtcapiStoredFloats [
1 ] , 1 , 0 } , { ( const void * ) & rtcapiStoredFloats [ 1 ] , ( const void
* ) & rtcapiStoredFloats [ 1 ] , 0 , 0 } , { ( NULL ) , ( NULL ) , 2 , 0 } }
; static rtwCAPI_ModelMappingStaticInfo mmiStatic = { { rtBlockSignals , 8 ,
( NULL ) , 0 , ( NULL ) , 0 } , { rtBlockParameters , 22 , rtModelParameters
, 0 } , { ( NULL ) , 0 } , { rtDataTypeMap , rtDimensionMap , rtFixPtMap ,
rtElementMap , rtSampleTimeMap , rtDimensionArray } , "float" , { 1928136815U
, 601463414U , 2580167177U , 1135433388U } , ( NULL ) , 0 , 0 } ; const
rtwCAPI_ModelMappingStaticInfo * top_model_GetCAPIStaticMap ( ) { return &
mmiStatic ; }
#ifndef HOST_CAPI_BUILD
void top_model_InitializeDataMapInfo ( SimStruct * const rtS ) {
rtwCAPI_SetVersion ( ( * rt_dataMapInfoPtr ) . mmi , 1 ) ;
rtwCAPI_SetStaticMap ( ( * rt_dataMapInfoPtr ) . mmi , & mmiStatic ) ;
rtwCAPI_SetLoggingStaticMap ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetDataAddressMap ( ( * rt_dataMapInfoPtr ) . mmi , rtDataAddrMap ) ;
rtwCAPI_SetVarDimsAddressMap ( ( * rt_dataMapInfoPtr ) . mmi ,
rtVarDimsAddrMap ) ; rtwCAPI_SetInstanceLoggingInfo ( ( * rt_dataMapInfoPtr )
. mmi , ( NULL ) ) ; rtwCAPI_SetChildMMIArray ( ( * rt_dataMapInfoPtr ) . mmi
, ( NULL ) ) ; rtwCAPI_SetChildMMIArrayLen ( ( * rt_dataMapInfoPtr ) . mmi ,
0 ) ; }
#else
#ifdef __cplusplus
extern "C" {
#endif
void top_model_host_InitializeDataMapInfo ( top_model_host_DataMapInfo_T *
dataMap , const char * path ) { rtwCAPI_SetVersion ( dataMap -> mmi , 1 ) ;
rtwCAPI_SetStaticMap ( dataMap -> mmi , & mmiStatic ) ;
rtwCAPI_SetDataAddressMap ( dataMap -> mmi , NULL ) ;
rtwCAPI_SetVarDimsAddressMap ( dataMap -> mmi , NULL ) ; rtwCAPI_SetPath (
dataMap -> mmi , path ) ; rtwCAPI_SetFullPath ( dataMap -> mmi , NULL ) ;
rtwCAPI_SetChildMMIArray ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( dataMap -> mmi , 0 ) ; }
#ifdef __cplusplus
}
#endif
#endif
