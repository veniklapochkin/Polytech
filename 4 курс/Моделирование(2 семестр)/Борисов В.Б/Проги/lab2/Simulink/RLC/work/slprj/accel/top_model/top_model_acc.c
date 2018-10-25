#include "__cf_top_model.h"
#include <math.h>
#include "top_model_acc.h"
#include "top_model_acc_private.h"
#include <stdio.h>
#include "slexec_vm_simstruct_bridge.h"
#include "slexec_vm_zc_functions.h"
#include "slexec_vm_lookup_functions.h"
#include "simstruc.h"
#include "fixedpoint.h"
#define CodeFormat S-Function
#define AccDefine1 Accelerator_S-Function
#include "simtarget/slAccSfcnBridge.h"
static void mdlOutputs ( SimStruct * S , int_T tid ) { real_T currentTime ;
nk5xz4lrkw * _rtB ; l53zv5j3ec * _rtP ; ofr1nz5z44 * _rtDW ; _rtDW = ( (
ofr1nz5z44 * ) ssGetRootDWork ( S ) ) ; _rtP = ( ( l53zv5j3ec * )
ssGetModelRtp ( S ) ) ; _rtB = ( ( nk5xz4lrkw * ) _ssGetModelBlockIO ( S ) )
; ssCallAccelRunBlock ( S , 1 , 2 , SS_CALL_MDL_OUTPUTS ) ; if (
ssIsMajorTimeStep ( S ) ) { _rtDW -> b223zlexoi = ( _rtB -> eicq2xizhl >=
_rtP -> P_28 ) ; } if ( _rtDW -> b223zlexoi ) { _rtB -> l2ruyolmnz = _rtP ->
P_0 * _rtB -> e4ahiam3lt [ 0 ] ; } if ( ssIsSampleHit ( S , 1 , 0 ) ) {
currentTime = ssGetTaskTime ( S , 1 ) ; if ( currentTime < _rtP -> P_29 ) {
_rtB -> enat1afski = _rtP -> P_30 ; } else { _rtB -> enat1afski = _rtP ->
P_31 ; } } _rtB -> avmab2i32q = _rtP -> P_32 * _rtB -> e4ahiam3lt [ 2 ] ;
_rtB -> ohnfztbth3 = _rtP -> P_33 * _rtB -> e4ahiam3lt [ 1 ] ;
ssCallAccelRunBlock ( S , 1 , 12 , SS_CALL_MDL_OUTPUTS ) ; UNUSED_PARAMETER (
tid ) ; } static void mdlOutputsTID2 ( SimStruct * S , int_T tid ) {
nk5xz4lrkw * _rtB ; l53zv5j3ec * _rtP ; _rtP = ( ( l53zv5j3ec * )
ssGetModelRtp ( S ) ) ; _rtB = ( ( nk5xz4lrkw * ) _ssGetModelBlockIO ( S ) )
; _rtB -> jiqn3vxzm5 = _rtP -> P_1 ; _rtB -> bycwqvz2mw = _rtP -> P_2 ; _rtB
-> h4dz0chnsk = _rtP -> P_27 ; UNUSED_PARAMETER ( tid ) ; }
#define MDL_UPDATE
static void mdlUpdate ( SimStruct * S , int_T tid ) { nk5xz4lrkw * _rtB ;
l53zv5j3ec * _rtP ; ofr1nz5z44 * _rtDW ; _rtDW = ( ( ofr1nz5z44 * )
ssGetRootDWork ( S ) ) ; _rtP = ( ( l53zv5j3ec * ) ssGetModelRtp ( S ) ) ;
_rtB = ( ( nk5xz4lrkw * ) _ssGetModelBlockIO ( S ) ) ; ssCallAccelRunBlock (
S , 1 , 2 , SS_CALL_MDL_UPDATE ) ; UNUSED_PARAMETER ( tid ) ; }
#define MDL_UPDATE
static void mdlUpdateTID2 ( SimStruct * S , int_T tid ) { UNUSED_PARAMETER (
tid ) ; }
#define MDL_DERIVATIVES
static void mdlDerivatives ( SimStruct * S ) { nk5xz4lrkw * _rtB ; l53zv5j3ec
* _rtP ; ofr1nz5z44 * _rtDW ; _rtDW = ( ( ofr1nz5z44 * ) ssGetRootDWork ( S )
) ; _rtP = ( ( l53zv5j3ec * ) ssGetModelRtp ( S ) ) ; _rtB = ( ( nk5xz4lrkw *
) _ssGetModelBlockIO ( S ) ) ; ssCallAccelRunBlock ( S , 1 , 2 ,
SS_CALL_MDL_DERIVATIVES ) ; }
#define MDL_ZERO_CROSSINGS
static void mdlZeroCrossings ( SimStruct * S ) { nk5xz4lrkw * _rtB ;
l53zv5j3ec * _rtP ; brxpehexoi * _rtZCSV ; ofr1nz5z44 * _rtDW ; _rtDW = ( (
ofr1nz5z44 * ) ssGetRootDWork ( S ) ) ; _rtZCSV = ( ( brxpehexoi * )
ssGetSolverZcSignalVector ( S ) ) ; _rtP = ( ( l53zv5j3ec * ) ssGetModelRtp (
S ) ) ; _rtB = ( ( nk5xz4lrkw * ) _ssGetModelBlockIO ( S ) ) ;
ssCallAccelRunBlock ( S , 1 , 2 , SS_CALL_MDL_ZERO_CROSSINGS ) ; _rtZCSV ->
nmpkc1oxeh = _rtB -> eicq2xizhl - _rtP -> P_28 ; } static void
mdlInitializeSizes ( SimStruct * S ) { ssSetChecksumVal ( S , 0 , 2229809696U
) ; ssSetChecksumVal ( S , 1 , 1636407764U ) ; ssSetChecksumVal ( S , 2 ,
2379755151U ) ; ssSetChecksumVal ( S , 3 , 658133578U ) ; { mxArray *
slVerStructMat = NULL ; mxArray * slStrMat = mxCreateString ( "simulink" ) ;
char slVerChar [ 10 ] ; int status = mexCallMATLAB ( 1 , & slVerStructMat , 1
, & slStrMat , "ver" ) ; if ( status == 0 ) { mxArray * slVerMat = mxGetField
( slVerStructMat , 0 , "Version" ) ; if ( slVerMat == NULL ) { status = 1 ; }
else { status = mxGetString ( slVerMat , slVerChar , 10 ) ; } }
mxDestroyArray ( slStrMat ) ; mxDestroyArray ( slVerStructMat ) ; if ( (
status == 1 ) || ( strcmp ( slVerChar , "8.7" ) != 0 ) ) { return ; } }
ssSetOptions ( S , SS_OPTION_EXCEPTION_FREE_CODE ) ; if ( ssGetSizeofDWork (
S ) != sizeof ( ofr1nz5z44 ) ) { ssSetErrorStatus ( S ,
"Unexpected error: Internal DWork sizes do "
"not match for accelerator mex file." ) ; } if ( ssGetSizeofGlobalBlockIO ( S
) != sizeof ( nk5xz4lrkw ) ) { ssSetErrorStatus ( S ,
"Unexpected error: Internal BlockIO sizes do "
"not match for accelerator mex file." ) ; } { int ssSizeofParams ;
ssGetSizeofParams ( S , & ssSizeofParams ) ; if ( ssSizeofParams != sizeof (
l53zv5j3ec ) ) { static char msg [ 256 ] ; sprintf ( msg ,
"Unexpected error: Internal Parameters sizes do "
"not match for accelerator mex file." ) ; } } _ssSetModelRtp ( S , ( real_T *
) & kpt4j3r0or ) ; rt_InitInfAndNaN ( sizeof ( real_T ) ) ; } static void
mdlInitializeSampleTimes ( SimStruct * S ) { slAccRegPrmChangeFcn ( S ,
mdlOutputsTID2 ) ; } static void mdlTerminate ( SimStruct * S ) { }
#include "simulink.c"
