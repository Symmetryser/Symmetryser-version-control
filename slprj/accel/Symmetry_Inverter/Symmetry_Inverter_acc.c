#include "__cf_Symmetry_Inverter.h"
#include <math.h>
#include "Symmetry_Inverter_acc.h"
#include "Symmetry_Inverter_acc_private.h"
#include <stdio.h>
#include "simstruc.h"
#include "fixedpoint.h"
#define CodeFormat S-Function
#define AccDefine1 Accelerator_S-Function
void du0chwvarz ( SimStruct * const S , uint8_T ksk2pleye5 , real_T
mrsjjo1pm3 , aqltkq4cux * localB , ho5bisyg5s * localDW , kpxnznidsa *
localZCE ) { if ( ssIsMajorTimeStep ( S ) ) { if ( ( ksk2pleye5 > 0 ) && (
localZCE -> cjykxy22sh != POS_ZCSIG ) ) { localB -> odlvr5yghp = mrsjjo1pm3 ;
localDW -> d4vcswe40h = 4 ; } localZCE -> cjykxy22sh = ( uint8_T ) (
ksk2pleye5 > 0 ? ( int32_T ) POS_ZCSIG : ( int32_T ) ZERO_ZCSIG ) ; } } void
ocdv12l4fg ( SimStruct * const S ) { } static void mdlOutputs ( SimStruct * S
, int_T tid ) { real_T fd41t0nagf ; real_T lf00dhirwu ; real_T ov0cn5ftaw ;
uint8_T ecy1x0ohg2 ; uint8_T dlmcln4tuw ; uint8_T opsm05wieh ; uint8_T
nuulzpk4qm ; uint8_T ihocbfoadn ; uint8_T gw33spiy22 ; uint8_T pm1b3421h2 ;
uint8_T gatc3rwfms ; uint8_T ilbjt5rxkz ; uint8_T aqwxdbj0k4 ; int_T iy ;
real_T * lastU ; int32_T currentOffset ; int32_T nSampsAtBot ; int32_T nSamps
; real_T dcitqx0ard ; real_T bjl3y1gcxg [ 4 ] ; uint8_T bndfwnfbkf ; real_T
gime5op03j ; real_T pwlqqhqnbo [ 5 ] ; uint8_T hsfviugd2d ; real_T iwgbzhsqhx
[ 6 ] ; uint8_T ikt3un5pyi ; real_T hwd4lxqhnm ; uint8_T hymumnqtkk ; real_T
mihkphv2i2 ; uint8_T kpwfvppgkk ; real_T gkf5fa2yry ; uint8_T jcv3oz4ctl ;
real_T nnn1bluskv ; uint8_T f01uf0muqs ; real_T htipj0hasr ; uint8_T
pbvwdg10pf ; real_T avxjbnjco1 ; real_T k0su4zabty [ 2 ] ; uint8_T h12y5q450h
; ZCEventType zcEvent ; real_T ht4f3rwmc2 ; uint8_T mix5pprv2s ; real_T
fm1gkwovlt ; real_T mmwkc1tw0v ; real_T l3qxnpkzc1 [ 128 ] ; creal_T
ixzt4fky32 [ 128 ] ; creal_T olodqvk5ca [ 128 ] ; creal_T luutowss1p [ 128 ]
; int32_T i ; n3qi1whofz * _rtB ; loikxjbxjg * _rtP ; f1xhd02yjc * _rtX ;
o24blyp2sp * _rtZCE ; ew10rzwqr2 * _rtDW ; _rtDW = ( ( ew10rzwqr2 * )
ssGetRootDWork ( S ) ) ; _rtZCE = ( ( o24blyp2sp * ) _ssGetPrevZCSigState ( S
) ) ; _rtX = ( ( f1xhd02yjc * ) ssGetContStates ( S ) ) ; _rtP = ( (
loikxjbxjg * ) ssGetDefaultParam ( S ) ) ; _rtB = ( ( n3qi1whofz * )
_ssGetBlockIO ( S ) ) ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { memcpy ( & _rtB
-> e2240z2lbw [ 0 ] , & _rtP -> P_5 [ 0 ] , 72U * sizeof ( real_T ) ) ;
dcitqx0ard = _rtP -> P_6 ; } if ( ssIsSampleHit ( S , 10 , 0 ) ) { bndfwnfbkf
= _rtDW -> bwa13dvhzm ; bjl3y1gcxg [ 0 ] = _rtP -> P_7 [ 0 ] ; bjl3y1gcxg [ 1
] = _rtP -> P_7 [ 1 ] ; bjl3y1gcxg [ 2 ] = _rtP -> P_7 [ 2 ] ; bjl3y1gcxg [ 3
] = _rtP -> P_7 [ 3 ] ; if ( ssIsMajorTimeStep ( S ) ) { _rtB -> dyfingntqe =
bjl3y1gcxg [ bndfwnfbkf ] ; } else { if ( bndfwnfbkf > 3 ) { i = 3 ; } else {
i = bndfwnfbkf ; } _rtB -> dyfingntqe = bjl3y1gcxg [ i ] ; } } if (
ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> ewu05buqol = dcitqx0ard * _rtB ->
dyfingntqe ; } _rtB -> hxty5sixdw = ssGetT ( S ) ; if ( ssIsSampleHit ( S , 3
, 0 ) ) { ssCallAccelRunBlock ( S , 22 , 7 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 22 , 8 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 22 , 9 , SS_CALL_MDL_OUTPUTS ) ; } if (
ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> izuj5ssv31 = _rtP -> P_8 ; _rtB ->
jz1jye4mnv = _rtP -> P_9 ; _rtB -> memzvtwqv5 = _rtP -> P_10 ; } _rtB ->
eadzpiyxtw = ( ( f1xhd02yjc * ) ssGetContStates ( S ) ) -> iw32rf0o5j ; _rtB
-> l4w2p1hj0y = 0.0 ; _rtB -> l4w2p1hj0y += _rtP -> P_13 * _rtX -> marcvhut23
; if ( ssIsSampleHit ( S , 1 , 0 ) ) { if ( ssIsMajorTimeStep ( S ) ) { _rtDW
-> frrd52hwwa = ( _rtB -> l4w2p1hj0y > kesz3x3i1i ( S ) -> exararf2lq ) ; }
_rtB -> ke4du3u321 = _rtDW -> frrd52hwwa ; _rtB -> mcehnzrusy = _rtDW ->
eaysl4zk4f ; } if ( ssIsMajorTimeStep ( S ) ) { ZCEventType zcEvent ;
boolean_T resetIntg = false ; zcEvent = rt_ZCFcn ( RISING_ZERO_CROSSING , & (
( o24blyp2sp * ) _ssGetPrevZCSigState ( S ) ) -> mb1rqhvcmu , _rtB ->
ke4du3u321 ) ; if ( zcEvent || _rtDW -> nwv5vwpnq5 . IcNeedsLoading ) {
resetIntg = true ; ( ( f1xhd02yjc * ) ssGetContStates ( S ) ) -> i25grusegg =
_rtB -> mcehnzrusy ; } if ( resetIntg ) { ssSetSolverNeedsReset ( S ) ; } }
if ( ssIsMajorTimeStep ( S ) ) { if ( ( ( f1xhd02yjc * ) ssGetContStates ( S
) ) -> i25grusegg >= _rtP -> P_16 ) { ( ( f1xhd02yjc * ) ssGetContStates ( S
) ) -> i25grusegg = _rtP -> P_16 ; } else if ( ( ( f1xhd02yjc * )
ssGetContStates ( S ) ) -> i25grusegg <= _rtP -> P_17 ) { ( ( f1xhd02yjc * )
ssGetContStates ( S ) ) -> i25grusegg = _rtP -> P_17 ; } } _rtB -> g5sfuzf0ld
= ( ( f1xhd02yjc * ) ssGetContStates ( S ) ) -> i25grusegg ; _rtB ->
jp0usc5l2x = _rtP -> P_18 * _rtB -> g5sfuzf0ld ; if ( ssIsMajorTimeStep ( S )
) { _rtDW -> bpdjjmjuvy = _rtB -> jp0usc5l2x >= _rtP -> P_19 ? 1 : _rtB ->
jp0usc5l2x > _rtP -> P_20 ? 0 : - 1 ; } _rtB -> idaypp3nsx = _rtDW ->
bpdjjmjuvy == 1 ? _rtP -> P_19 : _rtDW -> bpdjjmjuvy == - 1 ? _rtP -> P_20 :
_rtB -> jp0usc5l2x ; switch ( ( int32_T ) _rtB -> memzvtwqv5 ) { case 1 :
_rtB -> ijbwir3czw = _rtB -> eadzpiyxtw ; break ; case 2 : _rtB -> ijbwir3czw
= muDoubleScalarExp ( - 0.15265486658117317 * _rtB -> idaypp3nsx ) *
44.081744803935024 ; break ; case 3 : _rtB -> ijbwir3czw = _rtB -> eadzpiyxtw
; break ; default : _rtB -> ijbwir3czw = _rtB -> eadzpiyxtw ; break ; }
gime5op03j = 210.0 / ( 210.0 - _rtB -> idaypp3nsx ) * 0.10378442688350696 *
_rtB -> idaypp3nsx ; fd41t0nagf = - _rtB -> ke4du3u321 * -
0.10378442688350696 * _rtB -> l4w2p1hj0y * ( 210.0 / ( 210.0 - _rtB ->
idaypp3nsx ) ) ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> mu3vmx2rdk =
_rtP -> P_21 ; _rtB -> bofkdncv5w = _rtP -> P_22 ; } if ( ssIsMajorTimeStep (
S ) ) { _rtDW -> hfbxz3gox4 = _rtB -> jp0usc5l2x >= _rtP -> P_23 ? 1 : _rtB
-> jp0usc5l2x > _rtP -> P_24 ? 0 : - 1 ; } _rtB -> dyefzfuy5o = _rtDW ->
hfbxz3gox4 == 1 ? _rtP -> P_23 : _rtDW -> hfbxz3gox4 == - 1 ? _rtP -> P_24 :
_rtB -> jp0usc5l2x ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { if (
ssIsMajorTimeStep ( S ) ) { _rtDW -> kpmwlx5oij = ( _rtB -> l4w2p1hj0y <
kesz3x3i1i ( S ) -> gopkhhzniv ) ; } _rtB -> d3nrbwlvhi = _rtDW -> kpmwlx5oij
; _rtB -> dcrovtlztw = _rtP -> P_26 ; _rtB -> pxq4ipdaux = _rtP -> P_27 ;
_rtB -> pu0pzjxe0p = _rtP -> P_28 ; } switch ( ( int32_T ) _rtB -> mu3vmx2rdk
) { case 1 : _rtB -> axnzpgnsc2 [ 0 ] = _rtB -> bofkdncv5w * _rtB ->
dyefzfuy5o ; _rtB -> axnzpgnsc2 [ 1 ] = _rtB -> bofkdncv5w * _rtB ->
l4w2p1hj0y ; _rtB -> axnzpgnsc2 [ 2 ] = _rtB -> bofkdncv5w * _rtB ->
d3nrbwlvhi ; _rtB -> fkhsmgvufw = - _rtB -> axnzpgnsc2 [ 2 ] * -
0.10378442688350696 * _rtB -> axnzpgnsc2 [ 1 ] * ( 210.0 / ( _rtB ->
axnzpgnsc2 [ 0 ] + 21.0 ) ) ; break ; case 2 : _rtB -> aota04fcav [ 0 ] =
_rtB -> dcrovtlztw * _rtB -> dyefzfuy5o ; _rtB -> aota04fcav [ 1 ] = _rtB ->
dcrovtlztw * _rtB -> l4w2p1hj0y ; _rtB -> aota04fcav [ 2 ] = _rtB ->
dcrovtlztw * _rtB -> d3nrbwlvhi ; _rtB -> fkhsmgvufw = - _rtB -> aota04fcav [
2 ] * - 0.10378442688350696 * _rtB -> aota04fcav [ 1 ] * ( 210.0 / ( _rtB ->
aota04fcav [ 0 ] + 21.0 ) ) ; break ; case 3 : _rtB -> a1dhlytx2n [ 0 ] =
_rtB -> pxq4ipdaux * _rtB -> dyefzfuy5o ; _rtB -> a1dhlytx2n [ 1 ] = _rtB ->
pxq4ipdaux * _rtB -> l4w2p1hj0y ; _rtB -> a1dhlytx2n [ 2 ] = _rtB ->
pxq4ipdaux * _rtB -> d3nrbwlvhi ; _rtB -> fkhsmgvufw = - _rtB -> a1dhlytx2n [
2 ] * - 0.10378442688350696 * _rtB -> a1dhlytx2n [ 1 ] * ( 210.0 / (
muDoubleScalarAbs ( _rtB -> a1dhlytx2n [ 0 ] ) + 21.0 ) ) ; break ; default :
_rtB -> pp4aonnimk [ 0 ] = _rtB -> pu0pzjxe0p * _rtB -> dyefzfuy5o ; _rtB ->
pp4aonnimk [ 1 ] = _rtB -> pu0pzjxe0p * _rtB -> l4w2p1hj0y ; _rtB ->
pp4aonnimk [ 2 ] = _rtB -> pu0pzjxe0p * _rtB -> d3nrbwlvhi ; _rtB ->
fkhsmgvufw = - _rtB -> pp4aonnimk [ 2 ] * - 0.10378442688350696 * _rtB ->
pp4aonnimk [ 1 ] * ( 210.0 / ( muDoubleScalarAbs ( _rtB -> pp4aonnimk [ 0 ] )
+ 21.0 ) ) ; break ; } _rtB -> ghfriakbun = ( ( ( _rtB -> jz1jye4mnv + _rtB
-> ijbwir3czw ) + gime5op03j ) + fd41t0nagf ) + _rtB -> fkhsmgvufw ; if (
ssIsSampleHit ( S , 1 , 0 ) ) { if ( ssIsMajorTimeStep ( S ) ) { _rtDW ->
duson3i4we = ( _rtB -> ghfriakbun > _rtB -> izuj5ssv31 ) ; } _rtB ->
pohagirjky = _rtDW -> duson3i4we ; } _rtB -> pfllrnj0g4 = _rtP -> P_29 * _rtB
-> l4w2p1hj0y ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { if ( ssIsMajorTimeStep (
S ) ) { _rtDW -> pvotw1e2w4 = ( _rtB -> ghfriakbun < _rtB -> pfllrnj0g4 ) ; }
_rtB -> kjdddzxv2v = _rtDW -> pvotw1e2w4 ; } if ( _rtB -> kjdddzxv2v ) { _rtB
-> oduijwlj5n = _rtB -> pfllrnj0g4 ; } else { _rtB -> oduijwlj5n = _rtB ->
ghfriakbun ; } if ( _rtB -> pohagirjky ) { _rtB -> pfphhhvu0t = _rtB ->
izuj5ssv31 ; } else { _rtB -> pfphhhvu0t = _rtB -> oduijwlj5n ; } if (
ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> c13aos0l1o = _rtP -> P_30 ; _rtB ->
memslrjuax = _rtP -> P_31 ; _rtB -> nq4dovwsyg = _rtP -> P_32 ; _rtB ->
lmtfwb5554 [ 0 ] = _rtP -> P_33 [ 0 ] ; _rtB -> lmtfwb5554 [ 1 ] = _rtP ->
P_33 [ 1 ] ; _rtB -> lmtfwb5554 [ 2 ] = _rtP -> P_33 [ 2 ] ; _rtB ->
lmtfwb5554 [ 3 ] = _rtP -> P_33 [ 3 ] ; _rtB -> airhqt1p5m [ 0 ] = _rtP ->
P_34 [ 0 ] ; _rtB -> airhqt1p5m [ 1 ] = _rtP -> P_34 [ 1 ] ; _rtB ->
airhqt1p5m [ 2 ] = _rtP -> P_34 [ 2 ] ; _rtB -> airhqt1p5m [ 3 ] = _rtP ->
P_34 [ 3 ] ; _rtB -> jhlgee02kn [ 0 ] = _rtP -> P_35 [ 0 ] ; _rtB ->
jhlgee02kn [ 1 ] = _rtP -> P_35 [ 1 ] ; _rtB -> jhlgee02kn [ 2 ] = _rtP ->
P_35 [ 2 ] ; _rtB -> jhlgee02kn [ 3 ] = _rtP -> P_35 [ 3 ] ; _rtB ->
d1agul0qm3 [ 0 ] = _rtP -> P_36 [ 0 ] ; _rtB -> d1agul0qm3 [ 1 ] = _rtP ->
P_36 [ 1 ] ; _rtB -> d1agul0qm3 [ 2 ] = _rtP -> P_36 [ 2 ] ; _rtB ->
d1agul0qm3 [ 3 ] = _rtP -> P_36 [ 3 ] ; _rtB -> fsleaztt3y [ 0 ] = _rtP ->
P_37 [ 0 ] ; _rtB -> fsleaztt3y [ 1 ] = _rtP -> P_37 [ 1 ] ; _rtB ->
fsleaztt3y [ 2 ] = _rtP -> P_37 [ 2 ] ; _rtB -> fsleaztt3y [ 3 ] = _rtP ->
P_37 [ 3 ] ; _rtB -> faj2vu1boy [ 0 ] = _rtP -> P_38 [ 0 ] ; _rtB ->
faj2vu1boy [ 1 ] = _rtP -> P_38 [ 1 ] ; _rtB -> faj2vu1boy [ 2 ] = _rtP ->
P_38 [ 2 ] ; _rtB -> faj2vu1boy [ 3 ] = _rtP -> P_38 [ 3 ] ; _rtB ->
bvagspv0oq [ 0 ] = _rtP -> P_39 [ 0 ] ; _rtB -> bvagspv0oq [ 1 ] = _rtP ->
P_39 [ 1 ] ; _rtB -> bvagspv0oq [ 2 ] = _rtP -> P_39 [ 2 ] ; _rtB ->
bvagspv0oq [ 3 ] = _rtP -> P_39 [ 3 ] ; _rtB -> fnaux4ibif [ 0 ] = _rtP ->
P_40 [ 0 ] ; _rtB -> fnaux4ibif [ 1 ] = _rtP -> P_40 [ 1 ] ; _rtB ->
fnaux4ibif [ 2 ] = _rtP -> P_40 [ 2 ] ; _rtB -> fnaux4ibif [ 3 ] = _rtP ->
P_40 [ 3 ] ; _rtB -> dxmpu5vf2g [ 0 ] = _rtP -> P_41 [ 0 ] ; _rtB ->
dxmpu5vf2g [ 1 ] = _rtP -> P_41 [ 1 ] ; _rtB -> dxmpu5vf2g [ 2 ] = _rtP ->
P_41 [ 2 ] ; _rtB -> dxmpu5vf2g [ 3 ] = _rtP -> P_41 [ 3 ] ; }
ssCallAccelRunBlock ( S , 22 , 58 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
n0my1kv3qw = _rtP -> P_42 * _rtB -> ovm3w2lfpw [ 90 ] ; _rtB -> djkfjoojb1 =
_rtP -> P_43 * _rtB -> ovm3w2lfpw [ 91 ] ; _rtB -> msawr52aum = _rtP -> P_44
* _rtB -> ovm3w2lfpw [ 92 ] ; ssCallAccelRunBlock ( S , 22 , 62 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> i5wrcnby0e = _rtP -> P_45 * _rtB ->
ovm3w2lfpw [ 77 ] ; _rtB -> aej4mpguxl = _rtP -> P_46 * _rtB -> ovm3w2lfpw [
78 ] ; _rtB -> as3uvdafdj = _rtP -> P_47 * _rtB -> ovm3w2lfpw [ 79 ] ;
ssCallAccelRunBlock ( S , 22 , 66 , SS_CALL_MDL_OUTPUTS ) ; if (
ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> nyvlpdut0q = _rtP -> P_48 ; } _rtB ->
jbxwdzmlei = _rtP -> P_49 * _rtB -> ovm3w2lfpw [ 60 ] ; if (
ssIsMajorTimeStep ( S ) ) { _rtDW -> ny0cfybzy2 = ( _rtB -> ftb5et0t1g [ 60 ]
>= _rtP -> P_50 ) ; } if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> m2hidmav4s
= _rtP -> P_51 ; } _rtB -> blu3tprwd0 = _rtP -> P_52 * _rtB -> ovm3w2lfpw [
61 ] ; if ( ssIsMajorTimeStep ( S ) ) { _rtDW -> pgq5ld4g30 = ( _rtB ->
ftb5et0t1g [ 61 ] >= _rtP -> P_53 ) ; } if ( ssIsSampleHit ( S , 1 , 0 ) ) {
_rtB -> ab04z3shqy = _rtP -> P_54 ; } _rtB -> bwofsvqv2i = _rtP -> P_55 *
_rtB -> ovm3w2lfpw [ 62 ] ; if ( ssIsMajorTimeStep ( S ) ) { _rtDW ->
efyplrbem1 = ( _rtB -> ftb5et0t1g [ 62 ] >= _rtP -> P_56 ) ; } if (
ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> mhqz5apwoa = _rtP -> P_57 ; } _rtB ->
l5rabbdoul = _rtP -> P_58 * _rtB -> ovm3w2lfpw [ 63 ] ; if (
ssIsMajorTimeStep ( S ) ) { _rtDW -> deu0ydbzxz = ( _rtB -> ftb5et0t1g [ 63 ]
>= _rtP -> P_59 ) ; } if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> fjal1ohi2d
= _rtP -> P_60 ; } _rtB -> dhutlmm52k = ssGetT ( S ) ; if ( ssIsSampleHit ( S
, 1 , 0 ) ) { _rtB -> cvlyo04spt = _rtP -> P_61 ; } if ( ssIsMajorTimeStep (
S ) ) { _rtDW -> ejc10yehw2 = ( _rtB -> dhutlmm52k > _rtP -> P_62 ) ; } if (
_rtDW -> ejc10yehw2 ) { fd41t0nagf = _rtB -> fjal1ohi2d ; } else { fd41t0nagf
= _rtB -> cvlyo04spt ; } if ( ssIsSampleHit ( S , 1 , 0 ) ) { dcitqx0ard =
_rtP -> P_63 ; } if ( ssIsSampleHit ( S , 8 , 0 ) ) { hsfviugd2d = _rtDW ->
n30m4wwaoj ; for ( i = 0 ; i < 5 ; i ++ ) { pwlqqhqnbo [ i ] = _rtP -> P_64 [
i ] ; } if ( ssIsMajorTimeStep ( S ) ) { _rtB -> pvkwgjttqe = pwlqqhqnbo [
hsfviugd2d ] ; } else { if ( hsfviugd2d > 4 ) { i = 4 ; } else { i =
hsfviugd2d ; } _rtB -> pvkwgjttqe = pwlqqhqnbo [ i ] ; } _rtB -> jld0zezp14 =
_rtDW -> ddcecwrf1k ; } if ( ssIsSampleHit ( S , 9 , 0 ) ) { ikt3un5pyi =
_rtDW -> eayuayh5wq ; for ( i = 0 ; i < 6 ; i ++ ) { iwgbzhsqhx [ i ] = _rtP
-> P_66 [ i ] ; } if ( ssIsMajorTimeStep ( S ) ) { _rtB -> g33hpvt5an =
iwgbzhsqhx [ ikt3un5pyi ] ; } else { if ( ikt3un5pyi > 5 ) { i = 5 ; } else {
i = ikt3un5pyi ; } _rtB -> g33hpvt5an = iwgbzhsqhx [ i ] ; } } if (
ssIsSampleHit ( S , 1 , 0 ) ) { hwd4lxqhnm = dcitqx0ard * _rtB -> pvkwgjttqe
* _rtB -> jld0zezp14 * _rtB -> g33hpvt5an ; dcitqx0ard = _rtP -> P_67 ; } if
( ssIsSampleHit ( S , 8 , 0 ) ) { _rtB -> gqy1iwlpof = _rtDW -> d5qoy21xx2 ;
} if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> h0tm5jpspj = ( hwd4lxqhnm +
dcitqx0ard ) + _rtB -> gqy1iwlpof ; } _rtB -> ocfwemxngx = fd41t0nagf * _rtB
-> h0tm5jpspj ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { dcitqx0ard = _rtP ->
P_69 ; } if ( ssIsSampleHit ( S , 9 , 0 ) ) { hymumnqtkk = _rtDW ->
jwpjduc0fo ; for ( i = 0 ; i < 6 ; i ++ ) { iwgbzhsqhx [ i ] = _rtP -> P_70 [
i ] ; } if ( ssIsMajorTimeStep ( S ) ) { _rtB -> i11gvaulm2 = iwgbzhsqhx [
hymumnqtkk ] ; } else { if ( hymumnqtkk > 5 ) { i = 5 ; } else { i =
hymumnqtkk ; } _rtB -> i11gvaulm2 = iwgbzhsqhx [ i ] ; } } if ( ssIsSampleHit
( S , 1 , 0 ) ) { mihkphv2i2 = dcitqx0ard * _rtB -> pvkwgjttqe * _rtB ->
jld0zezp14 * _rtB -> i11gvaulm2 ; dcitqx0ard = _rtP -> P_71 ; } if (
ssIsSampleHit ( S , 8 , 0 ) ) { _rtB -> iv3yl0cmph = _rtDW -> bcgeygemi4 ; }
if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> nkswbpokok = ( mihkphv2i2 +
dcitqx0ard ) + _rtB -> iv3yl0cmph ; } _rtB -> nftk0kjosi = fd41t0nagf * _rtB
-> nkswbpokok ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { dcitqx0ard = _rtP ->
P_73 ; } if ( ssIsSampleHit ( S , 9 , 0 ) ) { kpwfvppgkk = _rtDW ->
mvz31rqucg ; for ( i = 0 ; i < 6 ; i ++ ) { iwgbzhsqhx [ i ] = _rtP -> P_74 [
i ] ; } if ( ssIsMajorTimeStep ( S ) ) { _rtB -> clc0a3wnzo = iwgbzhsqhx [
kpwfvppgkk ] ; } else { if ( kpwfvppgkk > 5 ) { i = 5 ; } else { i =
kpwfvppgkk ; } _rtB -> clc0a3wnzo = iwgbzhsqhx [ i ] ; } } if ( ssIsSampleHit
( S , 1 , 0 ) ) { gkf5fa2yry = dcitqx0ard * _rtB -> pvkwgjttqe * _rtB ->
jld0zezp14 * _rtB -> clc0a3wnzo ; dcitqx0ard = _rtP -> P_75 ; } if (
ssIsSampleHit ( S , 8 , 0 ) ) { _rtB -> a3o4eswgqo = _rtDW -> nvjcinerze ; }
if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> fkcanuypeq = ( gkf5fa2yry +
dcitqx0ard ) + _rtB -> a3o4eswgqo ; } _rtB -> isu50abzro = fd41t0nagf * _rtB
-> fkcanuypeq ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { dcitqx0ard = _rtP ->
P_77 ; } if ( ssIsSampleHit ( S , 9 , 0 ) ) { jcv3oz4ctl = _rtDW ->
gp42job5lm ; for ( i = 0 ; i < 6 ; i ++ ) { iwgbzhsqhx [ i ] = _rtP -> P_78 [
i ] ; } if ( ssIsMajorTimeStep ( S ) ) { _rtB -> fkch2b3p1p = iwgbzhsqhx [
jcv3oz4ctl ] ; } else { if ( jcv3oz4ctl > 5 ) { i = 5 ; } else { i =
jcv3oz4ctl ; } _rtB -> fkch2b3p1p = iwgbzhsqhx [ i ] ; } } if ( ssIsSampleHit
( S , 1 , 0 ) ) { nnn1bluskv = dcitqx0ard * _rtB -> pvkwgjttqe * _rtB ->
jld0zezp14 * _rtB -> fkch2b3p1p ; dcitqx0ard = _rtP -> P_79 ; } if (
ssIsSampleHit ( S , 8 , 0 ) ) { _rtB -> exx3tcwlit = _rtDW -> etqztvh0rt ; }
if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> bdwey5lcj0 = ( nnn1bluskv +
dcitqx0ard ) + _rtB -> exx3tcwlit ; } _rtB -> fnu2eua1i3 = fd41t0nagf * _rtB
-> bdwey5lcj0 ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { dcitqx0ard = _rtP ->
P_81 ; } if ( ssIsSampleHit ( S , 9 , 0 ) ) { f01uf0muqs = _rtDW ->
htlixbax51 ; for ( i = 0 ; i < 6 ; i ++ ) { iwgbzhsqhx [ i ] = _rtP -> P_82 [
i ] ; } if ( ssIsMajorTimeStep ( S ) ) { _rtB -> oliporf2sd = iwgbzhsqhx [
f01uf0muqs ] ; } else { if ( f01uf0muqs > 5 ) { i = 5 ; } else { i =
f01uf0muqs ; } _rtB -> oliporf2sd = iwgbzhsqhx [ i ] ; } } if ( ssIsSampleHit
( S , 1 , 0 ) ) { htipj0hasr = dcitqx0ard * _rtB -> pvkwgjttqe * _rtB ->
jld0zezp14 * _rtB -> oliporf2sd ; dcitqx0ard = _rtP -> P_83 ; } if (
ssIsSampleHit ( S , 8 , 0 ) ) { _rtB -> bvpqb3l42o = _rtDW -> gjqzyinbwr ; }
if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> ofyjcqejw4 = ( htipj0hasr +
dcitqx0ard ) + _rtB -> bvpqb3l42o ; } _rtB -> ii22huq5re = fd41t0nagf * _rtB
-> ofyjcqejw4 ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { dcitqx0ard = _rtP ->
P_85 ; } if ( ssIsSampleHit ( S , 9 , 0 ) ) { pbvwdg10pf = _rtDW ->
pip1bq031s ; for ( i = 0 ; i < 6 ; i ++ ) { iwgbzhsqhx [ i ] = _rtP -> P_86 [
i ] ; } if ( ssIsMajorTimeStep ( S ) ) { _rtB -> kfh14bb3hi = iwgbzhsqhx [
pbvwdg10pf ] ; } else { if ( pbvwdg10pf > 5 ) { i = 5 ; } else { i =
pbvwdg10pf ; } _rtB -> kfh14bb3hi = iwgbzhsqhx [ i ] ; } } if ( ssIsSampleHit
( S , 1 , 0 ) ) { avxjbnjco1 = dcitqx0ard * _rtB -> pvkwgjttqe * _rtB ->
jld0zezp14 * _rtB -> kfh14bb3hi ; dcitqx0ard = _rtP -> P_87 ; } if (
ssIsSampleHit ( S , 8 , 0 ) ) { _rtB -> puyh5g5s5l = _rtDW -> irewrnl3me ; }
if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> aoytrb1fmc = ( avxjbnjco1 +
dcitqx0ard ) + _rtB -> puyh5g5s5l ; } _rtB -> kmwtokd53y = fd41t0nagf * _rtB
-> aoytrb1fmc ; _rtB -> g2vzhikr4s = ssGetT ( S ) ; _rtB -> l30qfhrzx4 [ 0 ]
= _rtB -> ocfwemxngx ; _rtB -> l30qfhrzx4 [ 1 ] = _rtB -> nftk0kjosi ; _rtB
-> l30qfhrzx4 [ 2 ] = _rtB -> isu50abzro ; _rtB -> mob5pbv2gl [ 0 ] = _rtB ->
fnu2eua1i3 ; _rtB -> mob5pbv2gl [ 1 ] = _rtB -> ii22huq5re ; _rtB ->
mob5pbv2gl [ 2 ] = _rtB -> kmwtokd53y ; ssCallAccelRunBlock ( S , 15 , 2 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> g3ydlb30di = _rtB -> ge1fao0knn [ 0 ] - _rtB
-> n0my1kv3qw ; if ( ssIsSampleHit ( S , 2 , 0 ) ) { if ( _rtB -> g3ydlb30di
>= _rtP -> P_89 ) { _rtDW -> f1w3anjcx5 = true ; } else { if ( _rtB ->
g3ydlb30di <= _rtP -> P_90 ) { _rtDW -> f1w3anjcx5 = false ; } } if ( _rtDW
-> f1w3anjcx5 ) { _rtB -> ougdz5fga0 = _rtP -> P_91 ; } else { _rtB ->
ougdz5fga0 = _rtP -> P_92 ; } if ( _rtB -> g3ydlb30di >= _rtP -> P_93 ) {
_rtDW -> ofpb15cd1t = true ; } else { if ( _rtB -> g3ydlb30di <= _rtP -> P_94
) { _rtDW -> ofpb15cd1t = false ; } } if ( _rtDW -> ofpb15cd1t ) { _rtB ->
dbvhkdyuyj = _rtP -> P_95 ; } else { _rtB -> dbvhkdyuyj = _rtP -> P_96 ; }
ssCallAccelRunBlock ( S , 22 , 158 , SS_CALL_MDL_OUTPUTS ) ; } if (
ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> nua1ifn2ft = _rtP -> P_97 ; } _rtB ->
gdgcup5ay1 = _rtP -> P_98 * _rtB -> ovm3w2lfpw [ 64 ] ; if (
ssIsMajorTimeStep ( S ) ) { _rtDW -> fpsvzkocqn = ( _rtB -> ftb5et0t1g [ 64 ]
>= _rtP -> P_99 ) ; } if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> bfmwwf4gzf
= _rtP -> P_100 ; } _rtB -> elmgwhl3w4 = _rtP -> P_101 * _rtB -> ovm3w2lfpw [
65 ] ; if ( ssIsMajorTimeStep ( S ) ) { _rtDW -> eujlpkewze = ( _rtB ->
ftb5et0t1g [ 65 ] >= _rtP -> P_102 ) ; } if ( ssIsSampleHit ( S , 1 , 0 ) ) {
_rtB -> j0e2yv4rsu = _rtP -> P_103 ; } _rtB -> aomq5t253d = _rtP -> P_104 *
_rtB -> ovm3w2lfpw [ 66 ] ; if ( ssIsMajorTimeStep ( S ) ) { _rtDW ->
e1hxijvilh = ( _rtB -> ftb5et0t1g [ 66 ] >= _rtP -> P_105 ) ; } if (
ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> gco3wejvbf = _rtP -> P_106 ; } _rtB
-> kk5adlxsoq = _rtP -> P_107 * _rtB -> ovm3w2lfpw [ 67 ] ; if (
ssIsMajorTimeStep ( S ) ) { _rtDW -> jrnljxx0eq = ( _rtB -> ftb5et0t1g [ 67 ]
>= _rtP -> P_108 ) ; } _rtB -> je2i0xyxud = _rtB -> ge1fao0knn [ 1 ] - _rtB
-> djkfjoojb1 ; if ( ssIsSampleHit ( S , 2 , 0 ) ) { if ( _rtB -> je2i0xyxud
>= _rtP -> P_109 ) { _rtDW -> eimtkf2df3 = true ; } else { if ( _rtB ->
je2i0xyxud <= _rtP -> P_110 ) { _rtDW -> eimtkf2df3 = false ; } } if ( _rtDW
-> eimtkf2df3 ) { _rtB -> okc1ybg3ld = _rtP -> P_111 ; } else { _rtB ->
okc1ybg3ld = _rtP -> P_112 ; } if ( _rtB -> je2i0xyxud >= _rtP -> P_113 ) {
_rtDW -> hhbucalj0f = true ; } else { if ( _rtB -> je2i0xyxud <= _rtP ->
P_114 ) { _rtDW -> hhbucalj0f = false ; } } if ( _rtDW -> hhbucalj0f ) { _rtB
-> mpqagzmh35 = _rtP -> P_115 ; } else { _rtB -> mpqagzmh35 = _rtP -> P_116 ;
} ssCallAccelRunBlock ( S , 22 , 197 , SS_CALL_MDL_OUTPUTS ) ; } if (
ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> d3t2kwqjk1 = _rtP -> P_117 ; } _rtB
-> k21odkt05q = _rtP -> P_118 * _rtB -> ovm3w2lfpw [ 68 ] ; if (
ssIsMajorTimeStep ( S ) ) { _rtDW -> fzqxrbnx0n = ( _rtB -> ftb5et0t1g [ 68 ]
>= _rtP -> P_119 ) ; } if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB ->
fij2ik035q = _rtP -> P_120 ; } _rtB -> g2unlcbyho = _rtP -> P_121 * _rtB ->
ovm3w2lfpw [ 69 ] ; if ( ssIsMajorTimeStep ( S ) ) { _rtDW -> pq4eew2pr2 = (
_rtB -> ftb5et0t1g [ 69 ] >= _rtP -> P_122 ) ; } if ( ssIsSampleHit ( S , 1 ,
0 ) ) { _rtB -> czaph1rchy = _rtP -> P_123 ; } _rtB -> ghgu3utw3b = _rtP ->
P_124 * _rtB -> ovm3w2lfpw [ 70 ] ; if ( ssIsMajorTimeStep ( S ) ) { _rtDW ->
nw5dzkmbax = ( _rtB -> ftb5et0t1g [ 70 ] >= _rtP -> P_125 ) ; } if (
ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> lbtwmebxkb = _rtP -> P_126 ; } _rtB
-> edqa2mnati = _rtP -> P_127 * _rtB -> ovm3w2lfpw [ 71 ] ; if (
ssIsMajorTimeStep ( S ) ) { _rtDW -> okj3gkk2bj = ( _rtB -> ftb5et0t1g [ 71 ]
>= _rtP -> P_128 ) ; } _rtB -> cmx0hya2da = _rtB -> ge1fao0knn [ 2 ] - _rtB
-> msawr52aum ; if ( ssIsSampleHit ( S , 2 , 0 ) ) { if ( _rtB -> cmx0hya2da
>= _rtP -> P_129 ) { _rtDW -> iaxdbgthkh = true ; } else { if ( _rtB ->
cmx0hya2da <= _rtP -> P_130 ) { _rtDW -> iaxdbgthkh = false ; } } if ( _rtDW
-> iaxdbgthkh ) { _rtB -> dvk12j3dwg = _rtP -> P_131 ; } else { _rtB ->
dvk12j3dwg = _rtP -> P_132 ; } if ( _rtB -> cmx0hya2da >= _rtP -> P_133 ) {
_rtDW -> jnfi3wqg4m = true ; } else { if ( _rtB -> cmx0hya2da <= _rtP ->
P_134 ) { _rtDW -> jnfi3wqg4m = false ; } } if ( _rtDW -> jnfi3wqg4m ) { _rtB
-> izkkxy1gwr = _rtP -> P_135 ; } else { _rtB -> izkkxy1gwr = _rtP -> P_136 ;
} ssCallAccelRunBlock ( S , 22 , 236 , SS_CALL_MDL_OUTPUTS ) ; } _rtB ->
pbfute0ymn = _rtP -> P_137 * _rtB -> ovm3w2lfpw [ 73 ] ; ssCallAccelRunBlock
( S , 22 , 249 , SS_CALL_MDL_OUTPUTS ) ; if ( ssIsSampleHit ( S , 1 , 0 ) ) {
_rtB -> pymy1uhgoa = _rtP -> P_138 ; } _rtB -> kkmf4iqsvw = _rtB ->
pbfute0ymn - _rtB -> pymy1uhgoa ; if ( ssIsSampleHit ( S , 7 , 0 ) ) {
h12y5q450h = _rtDW -> dcxemsgm1d ; k0su4zabty [ 0 ] = _rtP -> P_139 [ 0 ] ;
k0su4zabty [ 1 ] = _rtP -> P_139 [ 1 ] ; if ( ssIsMajorTimeStep ( S ) ) {
dcitqx0ard = k0su4zabty [ h12y5q450h ] ; } else { if ( h12y5q450h > 1 ) { i =
1 ; } else { i = h12y5q450h ; } dcitqx0ard = k0su4zabty [ i ] ; } if (
ssIsMajorTimeStep ( S ) ) { zcEvent = rt_ZCFcn ( RISING_ZERO_CROSSING , &
_rtZCE -> jmnieu1ii5 , ( dcitqx0ard ) ) ; if ( zcEvent != NO_ZCEVENT ) { _rtB
-> nmmnzp2wqn = _rtB -> kkmf4iqsvw ; _rtDW -> dhjpke3f5m = 4 ; } } gime5op03j
= _rtP -> P_140 * _rtB -> nmmnzp2wqn ; if ( gime5op03j > _rtP -> P_141 ) {
_rtB -> a2jb424zjr = _rtP -> P_141 ; } else if ( gime5op03j < _rtP -> P_142 )
{ _rtB -> a2jb424zjr = _rtP -> P_142 ; } else { _rtB -> a2jb424zjr =
gime5op03j ; } ssCallAccelRunBlock ( S , 22 , 258 , SS_CALL_MDL_OUTPUTS ) ; }
_rtB -> awfl0tc14q = _rtP -> P_143 * _rtB -> ovm3w2lfpw [ 89 ] ;
ssCallAccelRunBlock ( S , 22 , 260 , SS_CALL_MDL_OUTPUTS ) ; if (
ssIsSampleHit ( S , 7 , 0 ) ) { ssCallAccelRunBlock ( S , 22 , 261 ,
SS_CALL_MDL_OUTPUTS ) ; } if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB ->
ms0r5bhozb = _rtP -> P_144 ; } _rtB -> frsnt5mwuy = _rtP -> P_145 * _rtB ->
ovm3w2lfpw [ 58 ] ; if ( ssIsMajorTimeStep ( S ) ) { _rtDW -> oy2u4cfzda = (
_rtB -> ftb5et0t1g [ 58 ] >= _rtP -> P_146 ) ; } if ( ssIsSampleHit ( S , 1 ,
0 ) ) { _rtB -> l4qaeulru3 = _rtP -> P_147 ; } _rtB -> irnzrlxyi4 = _rtP ->
P_148 * _rtB -> ovm3w2lfpw [ 57 ] ; if ( ssIsMajorTimeStep ( S ) ) { _rtDW ->
n2wi5itpvd = ( _rtB -> ftb5et0t1g [ 57 ] >= _rtP -> P_149 ) ; }
ssCallAccelRunBlock ( S , 22 , 274 , SS_CALL_MDL_OUTPUTS ) ; if (
ssIsSampleHit ( S , 6 , 0 ) ) { if ( ssGetLogOutput ( S ) ) { { const char *
errMsg = ( NULL ) ; void * fp = ( void * ) _rtDW -> j414mzkoiq . FilePtr ; if
( fp != ( NULL ) ) { { real_T t ; void * u ; t = ssGetTaskTime ( S , 6 ) ; u
= ( void * ) & _rtB -> a2jb424zjr ; errMsg = rtwH5LoggingCollectionWrite ( 1
, fp , 0 , t , u ) ; if ( errMsg != ( NULL ) ) { ssSetErrorStatus ( S ,
errMsg ) ; return ; } } } } } if ( ssGetLogOutput ( S ) ) { { const char *
errMsg = ( NULL ) ; void * fp = ( void * ) _rtDW -> aonubktc1w . FilePtr ; if
( fp != ( NULL ) ) { { real_T t ; void * u ; t = ssGetTaskTime ( S , 6 ) ; u
= ( void * ) & _rtB -> awfl0tc14q ; errMsg = rtwH5LoggingCollectionWrite ( 1
, fp , 0 , t , u ) ; if ( errMsg != ( NULL ) ) { ssSetErrorStatus ( S ,
errMsg ) ; return ; } } } } } if ( ssGetLogOutput ( S ) ) { { const char *
errMsg = ( NULL ) ; void * fp = ( void * ) _rtDW -> ombofhd1yt . FilePtr ; if
( fp != ( NULL ) ) { { real_T t ; void * u ; t = ssGetTaskTime ( S , 6 ) ; u
= ( void * ) & _rtB -> pbfute0ymn ; errMsg = rtwH5LoggingCollectionWrite ( 1
, fp , 0 , t , u ) ; if ( errMsg != ( NULL ) ) { ssSetErrorStatus ( S ,
errMsg ) ; return ; } } } } } } _rtB -> ejpddzq3ue = _rtB -> a2jb424zjr -
_rtB -> awfl0tc14q ; if ( ssIsSampleHit ( S , 3 , 0 ) ) { if ( _rtB ->
ejpddzq3ue >= _rtP -> P_150 ) { _rtDW -> fczadvmwsx = true ; } else { if (
_rtB -> ejpddzq3ue <= _rtP -> P_151 ) { _rtDW -> fczadvmwsx = false ; } } if
( _rtDW -> fczadvmwsx ) { _rtB -> lgf4ryrjf1 = _rtP -> P_152 ; } else { _rtB
-> lgf4ryrjf1 = _rtP -> P_153 ; } ssCallAccelRunBlock ( S , 22 , 280 ,
SS_CALL_MDL_OUTPUTS ) ; if ( _rtB -> ejpddzq3ue >= _rtP -> P_154 ) { _rtDW ->
iif1gh1ysz = true ; } else { if ( _rtB -> ejpddzq3ue <= _rtP -> P_155 ) {
_rtDW -> iif1gh1ysz = false ; } } if ( _rtDW -> iif1gh1ysz ) { _rtB ->
ibnzype1ta = _rtP -> P_156 ; } else { _rtB -> ibnzype1ta = _rtP -> P_157 ; }
ssCallAccelRunBlock ( S , 22 , 282 , SS_CALL_MDL_OUTPUTS ) ; } if (
ssIsSampleHit ( S , 7 , 0 ) ) { h12y5q450h = ( uint8_T ) ( ( uint32_T )
h12y5q450h + _rtP -> P_428 ) ; if ( h12y5q450h > _rtP -> P_430 ) { _rtB ->
dkuc5gkown = _rtP -> P_429 ; } else { _rtB -> dkuc5gkown = h12y5q450h ; } }
dcitqx0ard = _rtP -> P_159 * ssGetT ( S ) ; lf00dhirwu = ( 1.0 - ( dcitqx0ard
- muDoubleScalarFloor ( dcitqx0ard ) ) * 2.0 ) * _rtP -> P_158 ; _rtB ->
mhe4ekema0 = 0.0 ; i = 0 ; while ( i < 1 ) { _rtB -> mhe4ekema0 += _rtP ->
P_162 * _rtX -> lfttirzzy4 [ 7 ] ; i = 1 ; } if ( ssIsSampleHit ( S , 1 , 0 )
) { _rtB -> oetpnucadb = _rtP -> P_164 ; } _rtB -> aya2kqzqo2 = ( uint8_T ) (
lf00dhirwu > _rtB -> oetpnucadb ) ; if ( ssIsSampleHit ( S , 1 , 0 ) ) {
du0chwvarz ( S , _rtB -> aya2kqzqo2 , _rtB -> mhe4ekema0 , & _rtB ->
fssshrzc0m , & _rtDW -> fssshrzc0m , & _rtZCE -> fssshrzc0m ) ; mmwkc1tw0v =
muDoubleScalarSign ( _rtB -> fssshrzc0m . odlvr5yghp ) ; _rtB -> b2bumzu252 =
_rtP -> P_165 ; } _rtB -> oywhgxfmgj = ( uint8_T ) ( lf00dhirwu > _rtB ->
b2bumzu252 ) ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { du0chwvarz ( S , _rtB ->
oywhgxfmgj , _rtB -> mhe4ekema0 , & _rtB -> mhfwxoqzqd , & _rtDW ->
mhfwxoqzqd , & _rtZCE -> mhfwxoqzqd ) ; ht4f3rwmc2 = ( mmwkc1tw0v +
muDoubleScalarSign ( _rtB -> mhfwxoqzqd . odlvr5yghp ) ) * _rtP -> P_166 ; }
if ( ssIsSampleHit ( S , 7 , 0 ) ) { _rtB -> bjc2grpvx5 = _rtDW -> pq2lgjwnyq
; } if ( ssIsSampleHit ( S , 1 , 0 ) ) { ov0cn5ftaw = ht4f3rwmc2 + _rtB ->
bjc2grpvx5 ; _rtB -> ivqb4tfvel = _rtP -> P_168 ; } _rtB -> g2pkkb13zj = (
uint8_T ) ( lf00dhirwu > _rtB -> ivqb4tfvel ) ; if ( ssIsSampleHit ( S , 1 ,
0 ) ) { du0chwvarz ( S , _rtB -> g2pkkb13zj , ov0cn5ftaw , & _rtB ->
du0chwvarzb , & _rtDW -> du0chwvarzb , & _rtZCE -> du0chwvarzb ) ; _rtB ->
g0djczy3by = _rtP -> P_169 ; } _rtB -> as3uvdafdj = ( lf00dhirwu + _rtB ->
du0chwvarzb . odlvr5yghp ) + _rtB -> g0djczy3by ; ssCallAccelRunBlock ( S ,
22 , 312 , SS_CALL_MDL_OUTPUTS ) ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB
-> n2bi4g0qbu = _rtP -> P_170 ; } _rtB -> bxx44eywkz = _rtP -> P_171 * _rtB
-> ovm3w2lfpw [ 59 ] ; if ( ssIsMajorTimeStep ( S ) ) { _rtDW -> pupgn0bajh =
( _rtB -> ftb5et0t1g [ 59 ] >= _rtP -> P_172 ) ; } _rtB -> arj2k15smn = _rtP
-> P_173 * _rtB -> ovm3w2lfpw [ 88 ] ; _rtB -> j4cxrlxyc2 = _rtB ->
as3uvdafdj - _rtB -> arj2k15smn ; if ( ssIsSampleHit ( S , 3 , 0 ) ) { if (
_rtB -> j4cxrlxyc2 >= _rtP -> P_174 ) { _rtDW -> ksqnpjd4ja = true ; } else {
if ( _rtB -> j4cxrlxyc2 <= _rtP -> P_175 ) { _rtDW -> ksqnpjd4ja = false ; }
} if ( _rtDW -> ksqnpjd4ja ) { _rtB -> b2iwujsdlg = _rtP -> P_176 ; } else {
_rtB -> b2iwujsdlg = _rtP -> P_177 ; } } _rtB -> omc1zmu52y = _rtP -> P_178 *
_rtB -> ovm3w2lfpw [ 72 ] ; _rtB -> mwz2pti1y3 = _rtB -> omc1zmu52y * _rtB ->
arj2k15smn ; _rtB -> exte1o3kqg = 0.0 ; _rtB -> exte1o3kqg += _rtP -> P_181 *
_rtX -> loxeezbu2l ; if ( ( _rtDW -> bjr1bmo40x >= ssGetT ( S ) ) && ( _rtDW
-> ffo1wggexx >= ssGetT ( S ) ) ) { _rtB -> ntcj1yousd = 0.0 ; } else {
dcitqx0ard = _rtDW -> bjr1bmo40x ; lastU = & _rtDW -> akxsn5iktm ; if ( _rtDW
-> bjr1bmo40x < _rtDW -> ffo1wggexx ) { if ( _rtDW -> ffo1wggexx < ssGetT ( S
) ) { dcitqx0ard = _rtDW -> ffo1wggexx ; lastU = & _rtDW -> o2byh3o11z ; } }
else { if ( _rtDW -> bjr1bmo40x >= ssGetT ( S ) ) { dcitqx0ard = _rtDW ->
ffo1wggexx ; lastU = & _rtDW -> o2byh3o11z ; } } _rtB -> ntcj1yousd = ( _rtB
-> exte1o3kqg - * lastU ) / ( ssGetT ( S ) - dcitqx0ard ) ; } _rtB ->
d1rhtio1df = _rtP -> P_183 * _rtB -> ovm3w2lfpw [ 98 ] ; if (
ssIsMajorTimeStep ( S ) ) { _rtDW -> palfhjdwle = _rtB -> d1rhtio1df >= 0.0 ?
1 : 0 ; } _rtB -> d145rcau3z = _rtDW -> palfhjdwle > 0 ? _rtB -> d1rhtio1df :
- _rtB -> d1rhtio1df ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { if (
ssIsMajorTimeStep ( S ) ) { _rtDW -> hynzqqhhv5 = ( _rtB -> d1rhtio1df <
kesz3x3i1i ( S ) -> l3qe21v1e2 ) ; } _rtB -> a4arqfztwi = _rtP -> P_185 * (
real_T ) _rtDW -> hynzqqhhv5 ; } _rtB -> i5exegdn4c = _rtB -> a4arqfztwi -
_rtB -> eadzpiyxtw ; _rtB -> ms3s4ul31v = _rtB -> d145rcau3z * _rtB ->
i5exegdn4c ; _rtB -> n2aisujrds = _rtP -> P_186 * _rtB -> ms3s4ul31v ; _rtB
-> dx5gafotgs = _rtP -> P_187 * _rtB -> idaypp3nsx ; if ( ssIsSampleHit ( S ,
1 , 0 ) ) { _rtB -> da2312frri = _rtP -> P_188 ; } _rtB -> p5n1pfjpfe = _rtP
-> P_189 * _rtB -> ovm3w2lfpw [ 20 ] ; if ( ssIsMajorTimeStep ( S ) ) { _rtDW
-> pxygmu31l3 = ( _rtB -> ftb5et0t1g [ 20 ] >= _rtP -> P_190 ) ; } if ( _rtDW
-> pxygmu31l3 ) { _rtB -> odual2fzdv = _rtB -> p5n1pfjpfe ; } else { _rtB ->
odual2fzdv = _rtB -> da2312frri ; } if ( ssIsMajorTimeStep ( S ) ) { _rtDW ->
c02vm2g2tr = _rtB -> odual2fzdv >= _rtP -> P_191 ? 1 : _rtB -> odual2fzdv >
_rtP -> P_192 ? 0 : - 1 ; } if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB ->
mndchf0vky = _rtP -> P_193 ; } _rtB -> guhh5sivl4 = _rtP -> P_194 * _rtB ->
ovm3w2lfpw [ 19 ] ; if ( ssIsMajorTimeStep ( S ) ) { _rtDW -> jknmckmyup = (
_rtB -> ftb5et0t1g [ 19 ] >= _rtP -> P_195 ) ; } if ( _rtDW -> jknmckmyup ) {
_rtB -> pe4hgyh2xo = _rtB -> guhh5sivl4 ; } else { _rtB -> pe4hgyh2xo = _rtB
-> mndchf0vky ; } if ( ssIsMajorTimeStep ( S ) ) { _rtDW -> mqbqvay1op = _rtB
-> pe4hgyh2xo >= _rtP -> P_196 ? 1 : _rtB -> pe4hgyh2xo > _rtP -> P_197 ? 0 :
- 1 ; } if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> bknl1drthr = _rtP ->
P_198 ; } _rtB -> pqmelongo5 = _rtP -> P_199 * _rtB -> ovm3w2lfpw [ 18 ] ; if
( ssIsMajorTimeStep ( S ) ) { _rtDW -> bi40ragzhz = ( _rtB -> ftb5et0t1g [ 18
] >= _rtP -> P_200 ) ; } if ( _rtDW -> bi40ragzhz ) { _rtB -> a1rxyogj52 =
_rtB -> pqmelongo5 ; } else { _rtB -> a1rxyogj52 = _rtB -> bknl1drthr ; } if
( ssIsMajorTimeStep ( S ) ) { _rtDW -> owwxghrcx2 = _rtB -> a1rxyogj52 >=
_rtP -> P_201 ? 1 : _rtB -> a1rxyogj52 > _rtP -> P_202 ? 0 : - 1 ; }
ssCallAccelRunBlock ( S , 22 , 378 , SS_CALL_MDL_OUTPUTS ) ; if (
ssIsSampleHit ( S , 10 , 0 ) ) { h12y5q450h = ( uint8_T ) ( ( uint32_T )
bndfwnfbkf + _rtP -> P_431 ) ; if ( h12y5q450h > _rtP -> P_433 ) { _rtB ->
paisrbathf = _rtP -> P_432 ; } else { _rtB -> paisrbathf = h12y5q450h ; } }
if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> iv0hauw0jy = _rtP -> P_203 ; }
if ( ssIsSampleHit ( S , 3 , 0 ) ) { if ( ssGetLogOutput ( S ) ) { { const
char * errMsg = ( NULL ) ; void * fp = ( void * ) _rtDW -> mx4rdqag32 .
FilePtr ; if ( fp != ( NULL ) ) { { real_T t ; void * u ; t = ssGetTaskTime (
S , 3 ) ; u = ( void * ) & _rtB -> ge1fao0knn [ 0 ] ; errMsg =
rtwH5LoggingCollectionWrite ( 1 , fp , 0 , t , u ) ; if ( errMsg != ( NULL )
) { ssSetErrorStatus ( S , errMsg ) ; return ; } } } } } _rtB -> ptxaiu4c5g [
0 ] = _rtB -> ocfwemxngx ; _rtB -> ptxaiu4c5g [ 1 ] = _rtB -> nftk0kjosi ;
_rtB -> ptxaiu4c5g [ 2 ] = _rtB -> isu50abzro ; if ( ssGetLogOutput ( S ) ) {
{ const char * errMsg = ( NULL ) ; void * fp = ( void * ) _rtDW -> dpe20mpaho
. FilePtr ; if ( fp != ( NULL ) ) { { real_T t ; void * u ; t = ssGetTaskTime
( S , 3 ) ; u = ( void * ) & _rtB -> ptxaiu4c5g [ 0 ] ; errMsg =
rtwH5LoggingCollectionWrite ( 1 , fp , 0 , t , u ) ; if ( errMsg != ( NULL )
) { ssSetErrorStatus ( S , errMsg ) ; return ; } } } } } _rtB -> ptxaiu4c5g [
0 ] = _rtB -> fnu2eua1i3 ; _rtB -> ptxaiu4c5g [ 1 ] = _rtB -> ii22huq5re ;
_rtB -> ptxaiu4c5g [ 2 ] = _rtB -> kmwtokd53y ; if ( ssGetLogOutput ( S ) ) {
{ const char * errMsg = ( NULL ) ; void * fp = ( void * ) _rtDW -> my5lw0lb5v
. FilePtr ; if ( fp != ( NULL ) ) { { real_T t ; void * u ; t = ssGetTaskTime
( S , 3 ) ; u = ( void * ) & _rtB -> ptxaiu4c5g [ 0 ] ; errMsg =
rtwH5LoggingCollectionWrite ( 1 , fp , 0 , t , u ) ; if ( errMsg != ( NULL )
) { ssSetErrorStatus ( S , errMsg ) ; return ; } } } } } } if ( ssIsSampleHit
( S , 8 , 0 ) ) { mix5pprv2s = _rtDW -> iridzv04lr ; for ( i = 0 ; i < 5 ; i
++ ) { pwlqqhqnbo [ i ] = _rtP -> P_204 [ i ] ; } if ( ssIsMajorTimeStep ( S
) ) { _rtB -> cuxiruvoop = pwlqqhqnbo [ mix5pprv2s ] ; } else { if (
mix5pprv2s > 4 ) { i = 4 ; } else { i = mix5pprv2s ; } _rtB -> cuxiruvoop =
pwlqqhqnbo [ i ] ; } } if ( ssIsSampleHit ( S , 1 , 0 ) ) { ecy1x0ohg2 = (
uint8_T ) ( _rtB -> cuxiruvoop == _rtP -> P_205 ) ; dlmcln4tuw = ( uint8_T )
( _rtB -> cuxiruvoop == _rtP -> P_206 ) ; } if ( ssIsSampleHit ( S , 3 , 0 )
) { aqwxdbj0k4 = ( uint8_T ) ( _rtB -> cuxiruvoop == _rtP -> P_207 ) ; } if (
ssIsSampleHit ( S , 1 , 0 ) ) { opsm05wieh = ( uint8_T ) ( _rtB -> cuxiruvoop
== _rtP -> P_208 ) ; } _rtB -> g4gfps5rto = _rtP -> P_209 * _rtB ->
ovm3w2lfpw [ 74 ] ; if ( ssIsSampleHit ( S , 4 , 0 ) ) { _rtB -> ncbwikhlbp =
_rtB -> g4gfps5rto ; nSamps = 1 ; nSampsAtBot = 256 - _rtDW -> lu0obu4t34 ;
iy = _rtDW -> lu0obu4t34 ; if ( nSampsAtBot <= 1 ) { i = 0 ; while ( i <
nSampsAtBot ) { _rtDW -> fr0xsvp4gx [ _rtDW -> lu0obu4t34 ] = _rtB ->
ncbwikhlbp ; i = 1 ; } iy = 0 ; nSamps = 1 - nSampsAtBot ; } for ( i = 0 ; i
< nSamps ; i ++ ) { _rtDW -> fr0xsvp4gx [ iy + i ] = _rtB -> ncbwikhlbp ; }
_rtDW -> lu0obu4t34 ++ ; if ( _rtDW -> lu0obu4t34 >= 256 ) { _rtDW ->
lu0obu4t34 -= 256 ; } _rtDW -> pt3sjbepyg ++ ; if ( _rtDW -> pt3sjbepyg > 256
) { _rtDW -> bdubz2zcns = ( _rtDW -> bdubz2zcns + _rtDW -> pt3sjbepyg ) - 256
; if ( _rtDW -> bdubz2zcns > 256 ) { _rtDW -> bdubz2zcns -= 256 ; } _rtDW ->
pt3sjbepyg = 256 ; } } if ( ssIsSampleHit ( S , 8 , 0 ) ) { _rtDW ->
pt3sjbepyg -= 128 ; if ( _rtDW -> pt3sjbepyg < 0 ) { _rtDW -> bdubz2zcns +=
_rtDW -> pt3sjbepyg ; if ( _rtDW -> bdubz2zcns < 0 ) { _rtDW -> bdubz2zcns +=
256 ; } _rtDW -> pt3sjbepyg = 0 ; } iy = 0 ; currentOffset = _rtDW ->
bdubz2zcns ; if ( _rtDW -> bdubz2zcns < 0 ) { currentOffset = _rtDW ->
bdubz2zcns + 256 ; } nSampsAtBot = 256 - currentOffset ; nSamps = 128 ; if (
nSampsAtBot <= 128 ) { for ( i = 0 ; i < nSampsAtBot ; i ++ ) { l3qxnpkzc1 [
i ] = _rtDW -> fr0xsvp4gx [ currentOffset + i ] ; } iy = nSampsAtBot ;
currentOffset = 0 ; nSamps = 128 - nSampsAtBot ; } for ( i = 0 ; i < nSamps ;
i ++ ) { l3qxnpkzc1 [ iy + i ] = _rtDW -> fr0xsvp4gx [ currentOffset + i ] ;
} _rtDW -> bdubz2zcns = currentOffset + nSamps ; LibOutputs_FFT ( & _rtDW ->
g0dxtingc2 [ 0U ] , & l3qxnpkzc1 [ 0U ] , & ixzt4fky32 [ 0U ] , 128 , 1 ) ;
for ( i = 0 ; i < 128 ; i ++ ) { gime5op03j = ixzt4fky32 [ i ] . re ;
dcitqx0ard = ixzt4fky32 [ i ] . im ; ixzt4fky32 [ i ] . re = gime5op03j /
128.0 ; ixzt4fky32 [ i ] . im = dcitqx0ard / 128.0 ; } for ( i = 0 ; i < 128
; i ++ ) { l3qxnpkzc1 [ i ] = muDoubleScalarHypot ( ixzt4fky32 [ i ] . re ,
ixzt4fky32 [ i ] . im ) ; } iy = 0 ; for ( i = 0 ; i < 128 ; i ++ ) { if (
do3swhr3tu . lv4xvroz02 [ iy ] ) { _rtB -> kicboaeuzo = l3qxnpkzc1 [ i ] ; }
iy ++ ; if ( iy >= 128 ) { iy = 0 ; } } } if ( ssIsSampleHit ( S , 3 , 0 ) )
{ _rtB -> grydhtsl53 = _rtP -> P_211 * _rtB -> kicboaeuzo ; } _rtB ->
plzblj5boe = _rtP -> P_212 * _rtB -> ovm3w2lfpw [ 75 ] ; if ( ssIsSampleHit (
S , 4 , 0 ) ) { _rtB -> pq2hkag0lk = _rtB -> plzblj5boe ; nSamps = 1 ;
nSampsAtBot = 256 - _rtDW -> hrrxbi0ejs ; iy = _rtDW -> hrrxbi0ejs ; if (
nSampsAtBot <= 1 ) { i = 0 ; while ( i < nSampsAtBot ) { _rtDW -> jhs4syrwe0
[ _rtDW -> hrrxbi0ejs ] = _rtB -> pq2hkag0lk ; i = 1 ; } iy = 0 ; nSamps = 1
- nSampsAtBot ; } for ( i = 0 ; i < nSamps ; i ++ ) { _rtDW -> jhs4syrwe0 [
iy + i ] = _rtB -> pq2hkag0lk ; } _rtDW -> hrrxbi0ejs ++ ; if ( _rtDW ->
hrrxbi0ejs >= 256 ) { _rtDW -> hrrxbi0ejs -= 256 ; } _rtDW -> e3sxa4ibm4 ++ ;
if ( _rtDW -> e3sxa4ibm4 > 256 ) { _rtDW -> lg0g0cnn1s = ( _rtDW ->
lg0g0cnn1s + _rtDW -> e3sxa4ibm4 ) - 256 ; if ( _rtDW -> lg0g0cnn1s > 256 ) {
_rtDW -> lg0g0cnn1s -= 256 ; } _rtDW -> e3sxa4ibm4 = 256 ; } } if (
ssIsSampleHit ( S , 8 , 0 ) ) { _rtDW -> e3sxa4ibm4 -= 128 ; if ( _rtDW ->
e3sxa4ibm4 < 0 ) { _rtDW -> lg0g0cnn1s += _rtDW -> e3sxa4ibm4 ; if ( _rtDW ->
lg0g0cnn1s < 0 ) { _rtDW -> lg0g0cnn1s += 256 ; } _rtDW -> e3sxa4ibm4 = 0 ; }
iy = 0 ; currentOffset = _rtDW -> lg0g0cnn1s ; if ( _rtDW -> lg0g0cnn1s < 0 )
{ currentOffset = _rtDW -> lg0g0cnn1s + 256 ; } nSampsAtBot = 256 -
currentOffset ; nSamps = 128 ; if ( nSampsAtBot <= 128 ) { for ( i = 0 ; i <
nSampsAtBot ; i ++ ) { l3qxnpkzc1 [ i ] = _rtDW -> jhs4syrwe0 [ currentOffset
+ i ] ; } iy = nSampsAtBot ; currentOffset = 0 ; nSamps = 128 - nSampsAtBot ;
} for ( i = 0 ; i < nSamps ; i ++ ) { l3qxnpkzc1 [ iy + i ] = _rtDW ->
jhs4syrwe0 [ currentOffset + i ] ; } _rtDW -> lg0g0cnn1s = currentOffset +
nSamps ; LibOutputs_FFT ( & _rtDW -> nnyrcll0wz [ 0U ] , & l3qxnpkzc1 [ 0U ]
, & olodqvk5ca [ 0U ] , 128 , 1 ) ; for ( i = 0 ; i < 128 ; i ++ ) {
gime5op03j = olodqvk5ca [ i ] . re ; dcitqx0ard = olodqvk5ca [ i ] . im ;
olodqvk5ca [ i ] . re = gime5op03j / 128.0 ; olodqvk5ca [ i ] . im =
dcitqx0ard / 128.0 ; } for ( i = 0 ; i < 128 ; i ++ ) { l3qxnpkzc1 [ i ] =
muDoubleScalarHypot ( olodqvk5ca [ i ] . re , olodqvk5ca [ i ] . im ) ; } iy
= 0 ; for ( i = 0 ; i < 128 ; i ++ ) { if ( do3swhr3tu . lv4xvroz02 [ iy ] )
{ _rtB -> oajnhobhux = l3qxnpkzc1 [ i ] ; } iy ++ ; if ( iy >= 128 ) { iy = 0
; } } } if ( ssIsSampleHit ( S , 3 , 0 ) ) { _rtB -> n5k2srobcg = _rtP ->
P_214 * _rtB -> oajnhobhux ; } _rtB -> muco1isgcq = _rtP -> P_215 * _rtB ->
ovm3w2lfpw [ 76 ] ; if ( ssIsSampleHit ( S , 4 , 0 ) ) { _rtB -> e2ukpxsd0i =
_rtB -> muco1isgcq ; nSamps = 1 ; nSampsAtBot = 256 - _rtDW -> gcmlshhue0 ;
iy = _rtDW -> gcmlshhue0 ; if ( nSampsAtBot <= 1 ) { i = 0 ; while ( i <
nSampsAtBot ) { _rtDW -> pe4hoeyc2m [ _rtDW -> gcmlshhue0 ] = _rtB ->
e2ukpxsd0i ; i = 1 ; } iy = 0 ; nSamps = 1 - nSampsAtBot ; } for ( i = 0 ; i
< nSamps ; i ++ ) { _rtDW -> pe4hoeyc2m [ iy + i ] = _rtB -> e2ukpxsd0i ; }
_rtDW -> gcmlshhue0 ++ ; if ( _rtDW -> gcmlshhue0 >= 256 ) { _rtDW ->
gcmlshhue0 -= 256 ; } _rtDW -> o4r10aq4gy ++ ; if ( _rtDW -> o4r10aq4gy > 256
) { _rtDW -> miaz2chtef = ( _rtDW -> miaz2chtef + _rtDW -> o4r10aq4gy ) - 256
; if ( _rtDW -> miaz2chtef > 256 ) { _rtDW -> miaz2chtef -= 256 ; } _rtDW ->
o4r10aq4gy = 256 ; } } if ( ssIsSampleHit ( S , 8 , 0 ) ) { _rtDW ->
o4r10aq4gy -= 128 ; if ( _rtDW -> o4r10aq4gy < 0 ) { _rtDW -> miaz2chtef +=
_rtDW -> o4r10aq4gy ; if ( _rtDW -> miaz2chtef < 0 ) { _rtDW -> miaz2chtef +=
256 ; } _rtDW -> o4r10aq4gy = 0 ; } iy = 0 ; currentOffset = _rtDW ->
miaz2chtef ; if ( _rtDW -> miaz2chtef < 0 ) { currentOffset = _rtDW ->
miaz2chtef + 256 ; } nSampsAtBot = 256 - currentOffset ; nSamps = 128 ; if (
nSampsAtBot <= 128 ) { for ( i = 0 ; i < nSampsAtBot ; i ++ ) { l3qxnpkzc1 [
i ] = _rtDW -> pe4hoeyc2m [ currentOffset + i ] ; } iy = nSampsAtBot ;
currentOffset = 0 ; nSamps = 128 - nSampsAtBot ; } for ( i = 0 ; i < nSamps ;
i ++ ) { l3qxnpkzc1 [ iy + i ] = _rtDW -> pe4hoeyc2m [ currentOffset + i ] ;
} _rtDW -> miaz2chtef = currentOffset + nSamps ; LibOutputs_FFT ( & _rtDW ->
jv2qdaeb0l [ 0U ] , & l3qxnpkzc1 [ 0U ] , & luutowss1p [ 0U ] , 128 , 1 ) ;
for ( i = 0 ; i < 128 ; i ++ ) { gime5op03j = luutowss1p [ i ] . re ;
dcitqx0ard = luutowss1p [ i ] . im ; luutowss1p [ i ] . re = gime5op03j /
128.0 ; luutowss1p [ i ] . im = dcitqx0ard / 128.0 ; } for ( i = 0 ; i < 128
; i ++ ) { l3qxnpkzc1 [ i ] = muDoubleScalarHypot ( luutowss1p [ i ] . re ,
luutowss1p [ i ] . im ) ; } iy = 0 ; for ( i = 0 ; i < 128 ; i ++ ) { if (
do3swhr3tu . lv4xvroz02 [ iy ] ) { _rtB -> lu3h5ivu05 = l3qxnpkzc1 [ i ] ; }
iy ++ ; if ( iy >= 128 ) { iy = 0 ; } } } if ( ssIsSampleHit ( S , 3 , 0 ) )
{ _rtB -> cjzh5xgbf3 = _rtP -> P_217 * _rtB -> lu3h5ivu05 ; } if (
ssIsSampleHit ( S , 8 , 0 ) ) { for ( i = 0 ; i < 128 ; i ++ ) { l3qxnpkzc1 [
i ] = muDoubleScalarAtan2 ( ixzt4fky32 [ i ] . im , ixzt4fky32 [ i ] . re ) ;
} iy = 0 ; for ( i = 0 ; i < 128 ; i ++ ) { if ( do3swhr3tu . lv4xvroz02 [ iy
] ) { _rtB -> d2qjc0nneb = l3qxnpkzc1 [ i ] ; } iy ++ ; if ( iy >= 128 ) { iy
= 0 ; } } for ( i = 0 ; i < 128 ; i ++ ) { l3qxnpkzc1 [ i ] =
muDoubleScalarAtan2 ( olodqvk5ca [ i ] . im , olodqvk5ca [ i ] . re ) ; } iy
= 0 ; for ( i = 0 ; i < 128 ; i ++ ) { if ( do3swhr3tu . lv4xvroz02 [ iy ] )
{ _rtB -> jab4ap5j4h = l3qxnpkzc1 [ i ] ; } iy ++ ; if ( iy >= 128 ) { iy = 0
; } } for ( i = 0 ; i < 128 ; i ++ ) { l3qxnpkzc1 [ i ] = muDoubleScalarAtan2
( luutowss1p [ i ] . im , luutowss1p [ i ] . re ) ; } iy = 0 ; for ( i = 0 ;
i < 128 ; i ++ ) { if ( do3swhr3tu . lv4xvroz02 [ iy ] ) { _rtB -> h5lzcknqpu
= l3qxnpkzc1 [ i ] ; } iy ++ ; if ( iy >= 128 ) { iy = 0 ; } } } if (
ssIsSampleHit ( S , 3 , 0 ) ) { ssCallAccelRunBlock ( S , 1 , 0 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> ojdot4pkfv = _rtP -> P_218 * _rtB ->
b5d54pwvku ; du0chwvarz ( S , aqwxdbj0k4 , _rtB -> ojdot4pkfv , & _rtB ->
p3gjluzuqz , & _rtDW -> p3gjluzuqz , & _rtZCE -> p3gjluzuqz ) ; _rtB ->
kfx5eql4r3 = _rtP -> P_219 * _rtB -> p3gjluzuqz . odlvr5yghp ; } if (
ssIsSampleHit ( S , 1 , 0 ) ) { du0chwvarz ( S , ecy1x0ohg2 , _rtB ->
ojdot4pkfv , & _rtB -> agf2mbnhrj , & _rtDW -> agf2mbnhrj , & _rtZCE ->
agf2mbnhrj ) ; du0chwvarz ( S , dlmcln4tuw , _rtB -> ojdot4pkfv , & _rtB ->
dojgv3nl4w , & _rtDW -> dojgv3nl4w , & _rtZCE -> dojgv3nl4w ) ; dcitqx0ard =
muDoubleScalarSign ( _rtB -> agf2mbnhrj . odlvr5yghp - _rtB -> dojgv3nl4w .
odlvr5yghp ) ; du0chwvarz ( S , opsm05wieh , _rtB -> ojdot4pkfv , & _rtB ->
f2pm3ohglf , & _rtDW -> f2pm3ohglf , & _rtZCE -> f2pm3ohglf ) ; _rtB ->
kowycaqpi5 = ( muDoubleScalarSign ( _rtB -> dojgv3nl4w . odlvr5yghp - _rtB ->
f2pm3ohglf . odlvr5yghp ) + dcitqx0ard ) * _rtP -> P_220 ; } if (
ssIsSampleHit ( S , 8 , 0 ) ) { h12y5q450h = ( uint8_T ) ( ( uint32_T )
mix5pprv2s + _rtP -> P_435 ) ; if ( h12y5q450h > _rtP -> P_437 ) { _rtB ->
i4fkxcebgm = _rtP -> P_436 ; } else { _rtB -> i4fkxcebgm = h12y5q450h ; }
h12y5q450h = ( uint8_T ) ( ( uint32_T ) hsfviugd2d + _rtP -> P_438 ) ; if (
h12y5q450h > _rtP -> P_440 ) { _rtB -> kk0dl1ht4y = _rtP -> P_439 ; } else {
_rtB -> kk0dl1ht4y = h12y5q450h ; } _rtB -> bacxkriwhg = _rtB -> oliporf2sd *
_rtB -> cuxiruvoop ; } if ( ssIsSampleHit ( S , 1 , 0 ) ) { nuulzpk4qm = (
uint8_T ) ( _rtB -> bacxkriwhg == _rtP -> P_221 ) ; } if ( ssIsSampleHit ( S
, 5 , 0 ) ) { fm1gkwovlt = _rtDW -> ptzitxz1xb ; } if ( ssIsSampleHit ( S , 1
, 0 ) ) { _rtB -> bmicf5ony1 = _rtP -> P_223 ; } if ( ssIsSampleHit ( S , 5 ,
0 ) ) { if ( fm1gkwovlt > _rtP -> P_224 ) { _rtB -> g2rlrhgfrr = _rtP ->
P_224 ; } else if ( fm1gkwovlt < _rtP -> P_225 ) { _rtB -> g2rlrhgfrr = _rtP
-> P_225 ; } else { _rtB -> g2rlrhgfrr = fm1gkwovlt ; } } _rtB -> lt5patlltq
= _rtB -> jld0zezp14 * _rtB -> kowycaqpi5 * _rtB -> bmicf5ony1 * fd41t0nagf +
_rtB -> g2rlrhgfrr ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { du0chwvarz ( S ,
nuulzpk4qm , _rtB -> lt5patlltq , & _rtB -> evksckf5yd , & _rtDW ->
evksckf5yd , & _rtZCE -> evksckf5yd ) ; } if ( ssIsSampleHit ( S , 9 , 0 ) )
{ h12y5q450h = ( uint8_T ) ( ( uint32_T ) f01uf0muqs + _rtP -> P_441 ) ; if (
h12y5q450h > _rtP -> P_443 ) { _rtB -> jpj5a4m5zx = _rtP -> P_442 ; } else {
_rtB -> jpj5a4m5zx = h12y5q450h ; } } if ( ssIsSampleHit ( S , 8 , 0 ) ) {
_rtB -> angufhvmaj = _rtB -> g33hpvt5an * _rtB -> cuxiruvoop ; } if (
ssIsSampleHit ( S , 1 , 0 ) ) { ihocbfoadn = ( uint8_T ) ( _rtB -> angufhvmaj
== _rtP -> P_226 ) ; } if ( ssIsSampleHit ( S , 5 , 0 ) ) { fm1gkwovlt =
_rtDW -> agml1ijzs4 ; } if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB ->
lxlwbmsjkx = _rtP -> P_228 ; } if ( ssIsSampleHit ( S , 5 , 0 ) ) { if (
fm1gkwovlt > _rtP -> P_229 ) { _rtB -> mrrxgyrmsq = _rtP -> P_229 ; } else if
( fm1gkwovlt < _rtP -> P_230 ) { _rtB -> mrrxgyrmsq = _rtP -> P_230 ; } else
{ _rtB -> mrrxgyrmsq = fm1gkwovlt ; } } _rtB -> kqcjgmty2h = _rtB ->
jld0zezp14 * _rtB -> kowycaqpi5 * _rtB -> lxlwbmsjkx * fd41t0nagf * _rtB ->
iv0hauw0jy + _rtB -> mrrxgyrmsq ; if ( ssIsSampleHit ( S , 1 , 0 ) ) {
du0chwvarz ( S , ihocbfoadn , _rtB -> kqcjgmty2h , & _rtB -> ihf2rerjiy , &
_rtDW -> ihf2rerjiy , & _rtZCE -> ihf2rerjiy ) ; } if ( ssIsSampleHit ( S , 9
, 0 ) ) { h12y5q450h = ( uint8_T ) ( ( uint32_T ) ikt3un5pyi + _rtP -> P_444
) ; if ( h12y5q450h > _rtP -> P_446 ) { _rtB -> cxd5xzpnzu = _rtP -> P_445 ;
} else { _rtB -> cxd5xzpnzu = h12y5q450h ; } } if ( ssIsSampleHit ( S , 8 , 0
) ) { _rtB -> kyczzmg4le = _rtB -> i11gvaulm2 * _rtB -> cuxiruvoop ; } if (
ssIsSampleHit ( S , 1 , 0 ) ) { gw33spiy22 = ( uint8_T ) ( _rtB -> kyczzmg4le
== _rtP -> P_231 ) ; } if ( ssIsSampleHit ( S , 5 , 0 ) ) { fm1gkwovlt =
_rtDW -> gi5fv1o4t2 ; } if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB ->
jkvtvzpbms = _rtP -> P_233 ; } if ( ssIsSampleHit ( S , 5 , 0 ) ) { if (
fm1gkwovlt > _rtP -> P_234 ) { _rtB -> lapxty4tlx = _rtP -> P_234 ; } else if
( fm1gkwovlt < _rtP -> P_235 ) { _rtB -> lapxty4tlx = _rtP -> P_235 ; } else
{ _rtB -> lapxty4tlx = fm1gkwovlt ; } } _rtB -> d32amdipfe = _rtB ->
jld0zezp14 * _rtB -> kowycaqpi5 * _rtB -> jkvtvzpbms * fd41t0nagf * _rtB ->
iv0hauw0jy + _rtB -> lapxty4tlx ; if ( ssIsSampleHit ( S , 1 , 0 ) ) {
du0chwvarz ( S , gw33spiy22 , _rtB -> d32amdipfe , & _rtB -> jjwutrcwja , &
_rtDW -> jjwutrcwja , & _rtZCE -> jjwutrcwja ) ; } if ( ssIsSampleHit ( S , 9
, 0 ) ) { h12y5q450h = ( uint8_T ) ( ( uint32_T ) hymumnqtkk + _rtP -> P_447
) ; if ( h12y5q450h > _rtP -> P_449 ) { _rtB -> hhlfhf52lq = _rtP -> P_448 ;
} else { _rtB -> hhlfhf52lq = h12y5q450h ; } } if ( ssIsSampleHit ( S , 8 , 0
) ) { _rtB -> l5t2bnhi5s = _rtB -> clc0a3wnzo * _rtB -> cuxiruvoop ; } if (
ssIsSampleHit ( S , 1 , 0 ) ) { pm1b3421h2 = ( uint8_T ) ( _rtB -> l5t2bnhi5s
== _rtP -> P_236 ) ; } if ( ssIsSampleHit ( S , 5 , 0 ) ) { fm1gkwovlt =
_rtDW -> jutruqwjjq ; } if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB ->
bne3sbsxza = _rtP -> P_238 ; } if ( ssIsSampleHit ( S , 5 , 0 ) ) { if (
fm1gkwovlt > _rtP -> P_239 ) { _rtB -> fefnfxazje = _rtP -> P_239 ; } else if
( fm1gkwovlt < _rtP -> P_240 ) { _rtB -> fefnfxazje = _rtP -> P_240 ; } else
{ _rtB -> fefnfxazje = fm1gkwovlt ; } } _rtB -> hoen13rb3s = _rtB ->
jld0zezp14 * _rtB -> kowycaqpi5 * _rtB -> bne3sbsxza * fd41t0nagf * _rtB ->
iv0hauw0jy + _rtB -> fefnfxazje ; if ( ssIsSampleHit ( S , 1 , 0 ) ) {
du0chwvarz ( S , pm1b3421h2 , _rtB -> hoen13rb3s , & _rtB -> pjnmj4pukv , &
_rtDW -> pjnmj4pukv , & _rtZCE -> pjnmj4pukv ) ; } if ( ssIsSampleHit ( S , 9
, 0 ) ) { h12y5q450h = ( uint8_T ) ( ( uint32_T ) kpwfvppgkk + _rtP -> P_450
) ; if ( h12y5q450h > _rtP -> P_452 ) { _rtB -> o5wkgz1fw2 = _rtP -> P_451 ;
} else { _rtB -> o5wkgz1fw2 = h12y5q450h ; } } if ( ssIsSampleHit ( S , 8 , 0
) ) { _rtB -> nf4l1fhby1 = _rtB -> fkch2b3p1p * _rtB -> cuxiruvoop ; } if (
ssIsSampleHit ( S , 1 , 0 ) ) { gatc3rwfms = ( uint8_T ) ( _rtB -> nf4l1fhby1
== _rtP -> P_241 ) ; } if ( ssIsSampleHit ( S , 5 , 0 ) ) { fm1gkwovlt =
_rtDW -> iia3j0x4g1 ; } if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB ->
fbrjrek10t = _rtP -> P_243 ; } if ( ssIsSampleHit ( S , 5 , 0 ) ) { if (
fm1gkwovlt > _rtP -> P_244 ) { _rtB -> muoxq2gdrm = _rtP -> P_244 ; } else if
( fm1gkwovlt < _rtP -> P_245 ) { _rtB -> muoxq2gdrm = _rtP -> P_245 ; } else
{ _rtB -> muoxq2gdrm = fm1gkwovlt ; } } _rtB -> hmgrbkit3j = _rtB ->
jld0zezp14 * _rtB -> kowycaqpi5 * _rtB -> fbrjrek10t * fd41t0nagf + _rtB ->
muoxq2gdrm ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { du0chwvarz ( S , gatc3rwfms
, _rtB -> hmgrbkit3j , & _rtB -> dspspwprkx , & _rtDW -> dspspwprkx , &
_rtZCE -> dspspwprkx ) ; } if ( ssIsSampleHit ( S , 9 , 0 ) ) { h12y5q450h =
( uint8_T ) ( ( uint32_T ) jcv3oz4ctl + _rtP -> P_453 ) ; if ( h12y5q450h >
_rtP -> P_455 ) { _rtB -> gbxxxcelvm = _rtP -> P_454 ; } else { _rtB ->
gbxxxcelvm = h12y5q450h ; } } if ( ssIsSampleHit ( S , 8 , 0 ) ) { _rtB ->
keyy35cgqm = _rtB -> kfh14bb3hi * _rtB -> cuxiruvoop ; } if ( ssIsSampleHit (
S , 1 , 0 ) ) { ilbjt5rxkz = ( uint8_T ) ( _rtB -> keyy35cgqm == _rtP ->
P_246 ) ; } if ( ssIsSampleHit ( S , 5 , 0 ) ) { fm1gkwovlt = _rtDW ->
dvvslw54fh ; } if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> anzcrwz3rj = _rtP
-> P_248 ; } if ( ssIsSampleHit ( S , 5 , 0 ) ) { if ( fm1gkwovlt > _rtP ->
P_249 ) { _rtB -> f1taqborzv = _rtP -> P_249 ; } else if ( fm1gkwovlt < _rtP
-> P_250 ) { _rtB -> f1taqborzv = _rtP -> P_250 ; } else { _rtB -> f1taqborzv
= fm1gkwovlt ; } } _rtB -> jve4xjzsvx = _rtB -> jld0zezp14 * _rtB ->
kowycaqpi5 * _rtB -> anzcrwz3rj * fd41t0nagf + _rtB -> f1taqborzv ; if (
ssIsSampleHit ( S , 1 , 0 ) ) { du0chwvarz ( S , ilbjt5rxkz , _rtB ->
jve4xjzsvx , & _rtB -> cf2m0e35rt , & _rtDW -> cf2m0e35rt , & _rtZCE ->
cf2m0e35rt ) ; } if ( ssIsSampleHit ( S , 9 , 0 ) ) { h12y5q450h = ( uint8_T
) ( ( uint32_T ) pbvwdg10pf + _rtP -> P_456 ) ; if ( h12y5q450h > _rtP ->
P_458 ) { _rtB -> jcfktaxszb = _rtP -> P_457 ; } else { _rtB -> jcfktaxszb =
h12y5q450h ; } } if ( ssIsSampleHit ( S , 3 , 0 ) ) { if ( ssGetLogOutput ( S
) ) { { const char * errMsg = ( NULL ) ; void * fp = ( void * ) _rtDW ->
graf24zqf1 . FilePtr ; if ( fp != ( NULL ) ) { { real_T t ; void * u ; t =
ssGetTaskTime ( S , 3 ) ; u = ( void * ) & _rtB -> b5d54pwvku ; errMsg =
rtwH5LoggingCollectionWrite ( 1 , fp , 0 , t , u ) ; if ( errMsg != ( NULL )
) { ssSetErrorStatus ( S , errMsg ) ; return ; } } } } } _rtB -> ptxaiu4c5g [
0 ] = _rtB -> grydhtsl53 ; _rtB -> ptxaiu4c5g [ 1 ] = _rtB -> n5k2srobcg ;
_rtB -> ptxaiu4c5g [ 2 ] = _rtB -> cjzh5xgbf3 ; if ( ssGetLogOutput ( S ) ) {
{ const char * errMsg = ( NULL ) ; void * fp = ( void * ) _rtDW -> cfmhgd0nw4
. FilePtr ; if ( fp != ( NULL ) ) { { real_T t ; void * u ; t = ssGetTaskTime
( S , 3 ) ; u = ( void * ) & _rtB -> ptxaiu4c5g [ 0 ] ; errMsg =
rtwH5LoggingCollectionWrite ( 1 , fp , 0 , t , u ) ; if ( errMsg != ( NULL )
) { ssSetErrorStatus ( S , errMsg ) ; return ; } } } } } _rtB -> ptxaiu4c5g [
0 ] = _rtB -> d2qjc0nneb ; _rtB -> ptxaiu4c5g [ 1 ] = _rtB -> jab4ap5j4h ;
_rtB -> ptxaiu4c5g [ 2 ] = _rtB -> h5lzcknqpu ; if ( ssGetLogOutput ( S ) ) {
{ const char * errMsg = ( NULL ) ; void * fp = ( void * ) _rtDW -> azrdsvpvna
. FilePtr ; if ( fp != ( NULL ) ) { { real_T t ; void * u ; t = ssGetTaskTime
( S , 3 ) ; u = ( void * ) & _rtB -> ptxaiu4c5g [ 0 ] ; errMsg =
rtwH5LoggingCollectionWrite ( 1 , fp , 0 , t , u ) ; if ( errMsg != ( NULL )
) { ssSetErrorStatus ( S , errMsg ) ; return ; } } } } } _rtB -> ptxaiu4c5g [
0 ] = _rtB -> g4gfps5rto ; _rtB -> ptxaiu4c5g [ 1 ] = _rtB -> plzblj5boe ;
_rtB -> ptxaiu4c5g [ 2 ] = _rtB -> muco1isgcq ; ssCallAccelRunBlock ( S , 22
, 586 , SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 22 , 587 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 22 , 588 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 22 , 589 ,
SS_CALL_MDL_OUTPUTS ) ; } if ( ssIsSampleHit ( S , 8 , 0 ) ) {
ssCallAccelRunBlock ( S , 22 , 590 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 22 , 591 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 22 , 592 , SS_CALL_MDL_OUTPUTS ) ; } _rtB ->
aldjq0rf22 = _rtP -> P_251 * _rtB -> ovm3w2lfpw [ 95 ] ; _rtB -> fhv4txyo1j =
_rtP -> P_252 * _rtB -> ovm3w2lfpw [ 96 ] ; _rtB -> bqxjoa0nbx = _rtP ->
P_253 * _rtB -> ovm3w2lfpw [ 97 ] ; if ( ssIsSampleHit ( S , 3 , 0 ) ) { _rtB
-> ptxaiu4c5g [ 0 ] = _rtB -> aldjq0rf22 ; _rtB -> ptxaiu4c5g [ 1 ] = _rtB ->
fhv4txyo1j ; _rtB -> ptxaiu4c5g [ 2 ] = _rtB -> bqxjoa0nbx ; if (
ssGetLogOutput ( S ) ) { { const char * errMsg = ( NULL ) ; void * fp = (
void * ) _rtDW -> h3bhmmxmba . FilePtr ; if ( fp != ( NULL ) ) { { real_T t ;
void * u ; t = ssGetTaskTime ( S , 3 ) ; u = ( void * ) & _rtB -> ptxaiu4c5g
[ 0 ] ; errMsg = rtwH5LoggingCollectionWrite ( 1 , fp , 0 , t , u ) ; if (
errMsg != ( NULL ) ) { ssSetErrorStatus ( S , errMsg ) ; return ; } } } } } }
_rtB -> mihqyehm3m = _rtP -> P_254 * _rtB -> ovm3w2lfpw [ 82 ] ; _rtB ->
myrsyq3qms = _rtP -> P_255 * _rtB -> ovm3w2lfpw [ 83 ] ; _rtB -> kblwwwgiuj =
_rtP -> P_256 * _rtB -> ovm3w2lfpw [ 84 ] ; if ( ssIsSampleHit ( S , 3 , 0 )
) { _rtB -> ptxaiu4c5g [ 0 ] = _rtB -> mihqyehm3m ; _rtB -> ptxaiu4c5g [ 1 ]
= _rtB -> myrsyq3qms ; _rtB -> ptxaiu4c5g [ 2 ] = _rtB -> kblwwwgiuj ; if (
ssGetLogOutput ( S ) ) { { const char * errMsg = ( NULL ) ; void * fp = (
void * ) _rtDW -> pbssgv5ciz . FilePtr ; if ( fp != ( NULL ) ) { { real_T t ;
void * u ; t = ssGetTaskTime ( S , 3 ) ; u = ( void * ) & _rtB -> ptxaiu4c5g
[ 0 ] ; errMsg = rtwH5LoggingCollectionWrite ( 1 , fp , 0 , t , u ) ; if (
errMsg != ( NULL ) ) { ssSetErrorStatus ( S , errMsg ) ; return ; } } } } } }
if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> ghyhxctpdr = _rtP -> P_257 ;
_rtB -> p0ipfcmntr = _rtP -> P_258 ; } _rtB -> bqp0zjziar = ssGetT ( S ) ; if
( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> fkkjnmajvp = _rtP -> P_259 ; } if (
ssIsMajorTimeStep ( S ) ) { _rtDW -> mqghmym3fp = ( _rtB -> bqp0zjziar > _rtP
-> P_260 ) ; } if ( _rtDW -> mqghmym3fp ) { lf00dhirwu = _rtB -> p0ipfcmntr ;
} else { lf00dhirwu = _rtB -> fkkjnmajvp ; } fd41t0nagf = ssGetT ( S ) ; _rtB
-> l2vitmrji2 = rt_Lookup ( _rtP -> P_261 , 6 , fd41t0nagf , _rtP -> P_262 )
; if ( _rtB -> ghyhxctpdr >= _rtP -> P_263 ) { _rtB -> c154iuygaz =
lf00dhirwu ; } else { _rtB -> c154iuygaz = _rtB -> l2vitmrji2 ; } if (
ssIsSampleHit ( S , 1 , 0 ) ) { ssCallAccelRunBlock ( S , 22 , 650 ,
SS_CALL_MDL_OUTPUTS ) ; } if ( ( _rtDW -> akp24mq0we >= ssGetT ( S ) ) && (
_rtDW -> lil4u4ahda >= ssGetT ( S ) ) ) { _rtB -> pimj2yxjrj = 0.0 ; } else {
dcitqx0ard = _rtDW -> akp24mq0we ; lastU = & _rtDW -> nb1yf2latz ; if ( _rtDW
-> akp24mq0we < _rtDW -> lil4u4ahda ) { if ( _rtDW -> lil4u4ahda < ssGetT ( S
) ) { dcitqx0ard = _rtDW -> lil4u4ahda ; lastU = & _rtDW -> na1ro2yz1c ; } }
else { if ( _rtDW -> akp24mq0we >= ssGetT ( S ) ) { dcitqx0ard = _rtDW ->
lil4u4ahda ; lastU = & _rtDW -> na1ro2yz1c ; } } _rtB -> pimj2yxjrj = ( _rtB
-> l2vitmrji2 - * lastU ) / ( ssGetT ( S ) - dcitqx0ard ) ; } if (
ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> jn2mutjqd1 = _rtP -> P_267 ; } if (
ssIsMajorTimeStep ( S ) ) { _rtDW -> eielcflecf = ( _rtB -> bqp0zjziar > _rtP
-> P_268 ) ; } if ( _rtDW -> eielcflecf ) { lf00dhirwu = _rtB -> p0ipfcmntr ;
} else { lf00dhirwu = _rtB -> fkkjnmajvp ; } fd41t0nagf = ssGetT ( S ) ; _rtB
-> oiw4peemyt = rt_Lookup ( _rtP -> P_269 , 6 , fd41t0nagf , _rtP -> P_270 )
; if ( _rtB -> jn2mutjqd1 >= _rtP -> P_271 ) { _rtB -> ngzccrp2u3 =
lf00dhirwu ; } else { _rtB -> ngzccrp2u3 = _rtB -> oiw4peemyt ; } if (
ssIsSampleHit ( S , 1 , 0 ) ) { ssCallAccelRunBlock ( S , 22 , 661 ,
SS_CALL_MDL_OUTPUTS ) ; } if ( ( _rtDW -> lcaqj5fzqx >= ssGetT ( S ) ) && (
_rtDW -> bgbbgunjez >= ssGetT ( S ) ) ) { _rtB -> j2uygvwij0 = 0.0 ; } else {
dcitqx0ard = _rtDW -> lcaqj5fzqx ; lastU = & _rtDW -> fzovofsgfr ; if ( _rtDW
-> lcaqj5fzqx < _rtDW -> bgbbgunjez ) { if ( _rtDW -> bgbbgunjez < ssGetT ( S
) ) { dcitqx0ard = _rtDW -> bgbbgunjez ; lastU = & _rtDW -> jhhq5tn2os ; } }
else { if ( _rtDW -> lcaqj5fzqx >= ssGetT ( S ) ) { dcitqx0ard = _rtDW ->
bgbbgunjez ; lastU = & _rtDW -> jhhq5tn2os ; } } _rtB -> j2uygvwij0 = ( _rtB
-> oiw4peemyt - * lastU ) / ( ssGetT ( S ) - dcitqx0ard ) ; } if (
ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> jbc3sgnzkz = _rtP -> P_275 ; } if (
ssIsMajorTimeStep ( S ) ) { _rtDW -> k24hugtjqt = ( _rtB -> bqp0zjziar > _rtP
-> P_276 ) ; } if ( _rtDW -> k24hugtjqt ) { lf00dhirwu = _rtB -> p0ipfcmntr ;
} else { lf00dhirwu = _rtB -> fkkjnmajvp ; } fd41t0nagf = ssGetT ( S ) ; _rtB
-> oxubidsgv5 = rt_Lookup ( _rtP -> P_277 , 6 , fd41t0nagf , _rtP -> P_278 )
; if ( _rtB -> jbc3sgnzkz >= _rtP -> P_279 ) { _rtB -> hdza4oa1tt =
lf00dhirwu ; } else { _rtB -> hdza4oa1tt = _rtB -> oxubidsgv5 ; } if (
ssIsSampleHit ( S , 1 , 0 ) ) { ssCallAccelRunBlock ( S , 22 , 672 ,
SS_CALL_MDL_OUTPUTS ) ; } if ( ( _rtDW -> ntwmp1zcea >= ssGetT ( S ) ) && (
_rtDW -> dufh5gari0 >= ssGetT ( S ) ) ) { _rtB -> ax2p3nngvb = 0.0 ; } else {
dcitqx0ard = _rtDW -> ntwmp1zcea ; lastU = & _rtDW -> pmmr2hc351 ; if ( _rtDW
-> ntwmp1zcea < _rtDW -> dufh5gari0 ) { if ( _rtDW -> dufh5gari0 < ssGetT ( S
) ) { dcitqx0ard = _rtDW -> dufh5gari0 ; lastU = & _rtDW -> cmtw4ie32s ; } }
else { if ( _rtDW -> ntwmp1zcea >= ssGetT ( S ) ) { dcitqx0ard = _rtDW ->
dufh5gari0 ; lastU = & _rtDW -> cmtw4ie32s ; } } _rtB -> ax2p3nngvb = ( _rtB
-> oxubidsgv5 - * lastU ) / ( ssGetT ( S ) - dcitqx0ard ) ; } if (
ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> lzt2wseett = _rtP -> P_283 ; _rtB ->
db0o2blhlh = _rtP -> P_284 ; } lf00dhirwu = ssGetT ( S ) ; _rtB -> fw41uzozrg
= rt_Lookup ( _rtP -> P_285 , 6 , lf00dhirwu , _rtP -> P_286 ) ; if ( _rtB ->
lzt2wseett >= _rtP -> P_287 ) { _rtB -> jtuyjbreh1 = _rtB -> db0o2blhlh ; }
else { _rtB -> jtuyjbreh1 = _rtB -> fw41uzozrg ; } if ( ssIsSampleHit ( S , 1
, 0 ) ) { ssCallAccelRunBlock ( S , 22 , 683 , SS_CALL_MDL_OUTPUTS ) ; } if (
( _rtDW -> hihr1wdmnl >= ssGetT ( S ) ) && ( _rtDW -> pkcgvdllnd >= ssGetT (
S ) ) ) { _rtB -> psbwypggg2 = 0.0 ; } else { dcitqx0ard = _rtDW ->
hihr1wdmnl ; lastU = & _rtDW -> lwmzevgbkl ; if ( _rtDW -> hihr1wdmnl < _rtDW
-> pkcgvdllnd ) { if ( _rtDW -> pkcgvdllnd < ssGetT ( S ) ) { dcitqx0ard =
_rtDW -> pkcgvdllnd ; lastU = & _rtDW -> ihgep3eq3u ; } } else { if ( _rtDW
-> hihr1wdmnl >= ssGetT ( S ) ) { dcitqx0ard = _rtDW -> pkcgvdllnd ; lastU =
& _rtDW -> ihgep3eq3u ; } } _rtB -> psbwypggg2 = ( _rtB -> fw41uzozrg - *
lastU ) / ( ssGetT ( S ) - dcitqx0ard ) ; } if ( ssIsSampleHit ( S , 1 , 0 )
) { _rtB -> itmdhiihsq [ 0 ] = _rtP -> P_291 [ 0 ] ; _rtB -> itmdhiihsq [ 1 ]
= _rtP -> P_291 [ 1 ] ; _rtB -> itmdhiihsq [ 2 ] = _rtP -> P_291 [ 2 ] ; _rtB
-> itmdhiihsq [ 3 ] = _rtP -> P_291 [ 3 ] ; _rtB -> oxelrrmb4w = _rtP ->
P_292 ; _rtB -> pijxnbqjr1 = _rtP -> P_293 ; } lf00dhirwu = ssGetT ( S ) ;
_rtB -> fjr4qfqjjb = rt_Lookup ( _rtP -> P_294 , 6 , lf00dhirwu , _rtP ->
P_295 ) ; if ( _rtB -> oxelrrmb4w >= _rtP -> P_296 ) { _rtB -> bba0q5be0v =
_rtB -> pijxnbqjr1 ; } else { _rtB -> bba0q5be0v = _rtB -> fjr4qfqjjb ; } if
( ssIsSampleHit ( S , 1 , 0 ) ) { ssCallAccelRunBlock ( S , 22 , 703 ,
SS_CALL_MDL_OUTPUTS ) ; } if ( ( _rtDW -> as10pgcy1c >= ssGetT ( S ) ) && (
_rtDW -> aczuqlqnju >= ssGetT ( S ) ) ) { _rtB -> jszde2yl3v = 0.0 ; } else {
dcitqx0ard = _rtDW -> as10pgcy1c ; lastU = & _rtDW -> gb3l1fa040 ; if ( _rtDW
-> as10pgcy1c < _rtDW -> aczuqlqnju ) { if ( _rtDW -> aczuqlqnju < ssGetT ( S
) ) { dcitqx0ard = _rtDW -> aczuqlqnju ; lastU = & _rtDW -> mu2kg3d13s ; } }
else { if ( _rtDW -> as10pgcy1c >= ssGetT ( S ) ) { dcitqx0ard = _rtDW ->
aczuqlqnju ; lastU = & _rtDW -> mu2kg3d13s ; } } _rtB -> jszde2yl3v = ( _rtB
-> fjr4qfqjjb - * lastU ) / ( ssGetT ( S ) - dcitqx0ard ) ; } if (
ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> hj15hny5gv [ 0 ] = _rtP -> P_300 [ 0
] ; _rtB -> hj15hny5gv [ 1 ] = _rtP -> P_300 [ 1 ] ; _rtB -> hj15hny5gv [ 2 ]
= _rtP -> P_300 [ 2 ] ; _rtB -> hj15hny5gv [ 3 ] = _rtP -> P_300 [ 3 ] ; _rtB
-> c1qomcp0nz = _rtP -> P_301 ; _rtB -> eumahfdr2q = _rtP -> P_302 ; }
lf00dhirwu = ssGetT ( S ) ; _rtB -> m2ofdiylcx = rt_Lookup ( _rtP -> P_303 ,
6 , lf00dhirwu , _rtP -> P_304 ) ; if ( _rtB -> c1qomcp0nz >= _rtP -> P_305 )
{ _rtB -> au2yw43sv3 = _rtB -> eumahfdr2q ; } else { _rtB -> au2yw43sv3 =
_rtB -> m2ofdiylcx ; } if ( ssIsSampleHit ( S , 1 , 0 ) ) {
ssCallAccelRunBlock ( S , 22 , 723 , SS_CALL_MDL_OUTPUTS ) ; } if ( ( _rtDW
-> kd4axxolcq >= ssGetT ( S ) ) && ( _rtDW -> px3puybbg2 >= ssGetT ( S ) ) )
{ _rtB -> lbycvykmgv = 0.0 ; } else { dcitqx0ard = _rtDW -> kd4axxolcq ;
lastU = & _rtDW -> n5uxvn15h3 ; if ( _rtDW -> kd4axxolcq < _rtDW ->
px3puybbg2 ) { if ( _rtDW -> px3puybbg2 < ssGetT ( S ) ) { dcitqx0ard = _rtDW
-> px3puybbg2 ; lastU = & _rtDW -> eppjrrt5hr ; } } else { if ( _rtDW ->
kd4axxolcq >= ssGetT ( S ) ) { dcitqx0ard = _rtDW -> px3puybbg2 ; lastU = &
_rtDW -> eppjrrt5hr ; } } _rtB -> lbycvykmgv = ( _rtB -> m2ofdiylcx - * lastU
) / ( ssGetT ( S ) - dcitqx0ard ) ; } if ( ssIsSampleHit ( S , 1 , 0 ) ) {
_rtB -> ld4xhexado [ 0 ] = _rtP -> P_309 [ 0 ] ; _rtB -> ld4xhexado [ 1 ] =
_rtP -> P_309 [ 1 ] ; _rtB -> ld4xhexado [ 2 ] = _rtP -> P_309 [ 2 ] ; _rtB
-> ld4xhexado [ 3 ] = _rtP -> P_309 [ 3 ] ; _rtB -> ngejd01lt2 = _rtP ->
P_310 ; _rtB -> nuzyufkji3 = _rtP -> P_311 ; } lf00dhirwu = ssGetT ( S ) ;
_rtB -> n21omilfin = rt_Lookup ( _rtP -> P_312 , 6 , lf00dhirwu , _rtP ->
P_313 ) ; if ( _rtB -> ngejd01lt2 >= _rtP -> P_314 ) { _rtB -> ek44vxf00x =
_rtB -> nuzyufkji3 ; } else { _rtB -> ek44vxf00x = _rtB -> n21omilfin ; } if
( ssIsSampleHit ( S , 1 , 0 ) ) { ssCallAccelRunBlock ( S , 22 , 745 ,
SS_CALL_MDL_OUTPUTS ) ; } if ( ( _rtDW -> bvi1nidy5m >= ssGetT ( S ) ) && (
_rtDW -> mo3krrlmpu >= ssGetT ( S ) ) ) { _rtB -> hkxgi4hicd = 0.0 ; } else {
dcitqx0ard = _rtDW -> bvi1nidy5m ; lastU = & _rtDW -> g1mvvuhb2x ; if ( _rtDW
-> bvi1nidy5m < _rtDW -> mo3krrlmpu ) { if ( _rtDW -> mo3krrlmpu < ssGetT ( S
) ) { dcitqx0ard = _rtDW -> mo3krrlmpu ; lastU = & _rtDW -> blukxx0wjw ; } }
else { if ( _rtDW -> bvi1nidy5m >= ssGetT ( S ) ) { dcitqx0ard = _rtDW ->
mo3krrlmpu ; lastU = & _rtDW -> blukxx0wjw ; } } _rtB -> hkxgi4hicd = ( _rtB
-> n21omilfin - * lastU ) / ( ssGetT ( S ) - dcitqx0ard ) ; } if (
ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> m4fxakpcpr [ 0 ] = _rtP -> P_318 [ 0
] ; _rtB -> m4fxakpcpr [ 1 ] = _rtP -> P_318 [ 1 ] ; _rtB -> m4fxakpcpr [ 2 ]
= _rtP -> P_318 [ 2 ] ; _rtB -> m4fxakpcpr [ 3 ] = _rtP -> P_318 [ 3 ] ; _rtB
-> oskroizmwz = _rtP -> P_319 ; _rtB -> ejoyj5dy1t = _rtP -> P_320 ; }
lf00dhirwu = ssGetT ( S ) ; _rtB -> fdgwr40qza = rt_Lookup ( _rtP -> P_321 ,
6 , lf00dhirwu , _rtP -> P_322 ) ; if ( _rtB -> oskroizmwz >= _rtP -> P_323 )
{ _rtB -> p5ehyumbnr = _rtB -> ejoyj5dy1t ; } else { _rtB -> p5ehyumbnr =
_rtB -> fdgwr40qza ; } if ( ssIsSampleHit ( S , 1 , 0 ) ) {
ssCallAccelRunBlock ( S , 22 , 765 , SS_CALL_MDL_OUTPUTS ) ; } if ( ( _rtDW
-> ixbvclhhpb >= ssGetT ( S ) ) && ( _rtDW -> n1lmx5wu3c >= ssGetT ( S ) ) )
{ _rtB -> idfhyvpuhl = 0.0 ; } else { dcitqx0ard = _rtDW -> ixbvclhhpb ;
lastU = & _rtDW -> jnlfud1dvn ; if ( _rtDW -> ixbvclhhpb < _rtDW ->
n1lmx5wu3c ) { if ( _rtDW -> n1lmx5wu3c < ssGetT ( S ) ) { dcitqx0ard = _rtDW
-> n1lmx5wu3c ; lastU = & _rtDW -> k01edtry13 ; } } else { if ( _rtDW ->
ixbvclhhpb >= ssGetT ( S ) ) { dcitqx0ard = _rtDW -> n1lmx5wu3c ; lastU = &
_rtDW -> k01edtry13 ; } } _rtB -> idfhyvpuhl = ( _rtB -> fdgwr40qza - * lastU
) / ( ssGetT ( S ) - dcitqx0ard ) ; } if ( ssIsSampleHit ( S , 1 , 0 ) ) {
_rtB -> fnxmxsmhto [ 0 ] = _rtP -> P_327 [ 0 ] ; _rtB -> fnxmxsmhto [ 1 ] =
_rtP -> P_327 [ 1 ] ; _rtB -> fnxmxsmhto [ 2 ] = _rtP -> P_327 [ 2 ] ; _rtB
-> fnxmxsmhto [ 3 ] = _rtP -> P_327 [ 3 ] ; _rtB -> c4v5ofmejj = _rtP ->
P_328 ; _rtB -> nxklidt3ik = _rtP -> P_329 ; } lf00dhirwu = ssGetT ( S ) ;
_rtB -> hyoheftkam = rt_Lookup ( _rtP -> P_330 , 6 , lf00dhirwu , _rtP ->
P_331 ) ; if ( _rtB -> c4v5ofmejj >= _rtP -> P_332 ) { _rtB -> mrdcldmxsf =
_rtB -> nxklidt3ik ; } else { _rtB -> mrdcldmxsf = _rtB -> hyoheftkam ; } if
( ssIsSampleHit ( S , 1 , 0 ) ) { ssCallAccelRunBlock ( S , 22 , 785 ,
SS_CALL_MDL_OUTPUTS ) ; } if ( ( _rtDW -> fxubmsah3k >= ssGetT ( S ) ) && (
_rtDW -> d0fyomm1ti >= ssGetT ( S ) ) ) { _rtB -> fmuoopn133 = 0.0 ; } else {
dcitqx0ard = _rtDW -> fxubmsah3k ; lastU = & _rtDW -> hlpdm1dqii ; if ( _rtDW
-> fxubmsah3k < _rtDW -> d0fyomm1ti ) { if ( _rtDW -> d0fyomm1ti < ssGetT ( S
) ) { dcitqx0ard = _rtDW -> d0fyomm1ti ; lastU = & _rtDW -> ngjpm1iptv ; } }
else { if ( _rtDW -> fxubmsah3k >= ssGetT ( S ) ) { dcitqx0ard = _rtDW ->
d0fyomm1ti ; lastU = & _rtDW -> ngjpm1iptv ; } } _rtB -> fmuoopn133 = ( _rtB
-> hyoheftkam - * lastU ) / ( ssGetT ( S ) - dcitqx0ard ) ; } if (
ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> mp2l433lgy [ 0 ] = _rtP -> P_336 [ 0
] ; _rtB -> mp2l433lgy [ 1 ] = _rtP -> P_336 [ 1 ] ; _rtB -> mp2l433lgy [ 2 ]
= _rtP -> P_336 [ 2 ] ; _rtB -> mp2l433lgy [ 3 ] = _rtP -> P_336 [ 3 ] ; _rtB
-> cxcgaegktn = _rtP -> P_337 ; _rtB -> fat11j54rk = _rtP -> P_338 ; }
lf00dhirwu = ssGetT ( S ) ; _rtB -> d5f2a5su5x = rt_Lookup ( _rtP -> P_339 ,
6 , lf00dhirwu , _rtP -> P_340 ) ; if ( _rtB -> cxcgaegktn >= _rtP -> P_341 )
{ _rtB -> jxox2jlgax = _rtB -> fat11j54rk ; } else { _rtB -> jxox2jlgax =
_rtB -> d5f2a5su5x ; } if ( ssIsSampleHit ( S , 1 , 0 ) ) {
ssCallAccelRunBlock ( S , 22 , 807 , SS_CALL_MDL_OUTPUTS ) ; } if ( ( _rtDW
-> in2mxzxekv >= ssGetT ( S ) ) && ( _rtDW -> ciqyyvncvs >= ssGetT ( S ) ) )
{ _rtB -> jn4jvowsdb = 0.0 ; } else { dcitqx0ard = _rtDW -> in2mxzxekv ;
lastU = & _rtDW -> fo5mttneq3 ; if ( _rtDW -> in2mxzxekv < _rtDW ->
ciqyyvncvs ) { if ( _rtDW -> ciqyyvncvs < ssGetT ( S ) ) { dcitqx0ard = _rtDW
-> ciqyyvncvs ; lastU = & _rtDW -> efdshsf0xz ; } } else { if ( _rtDW ->
in2mxzxekv >= ssGetT ( S ) ) { dcitqx0ard = _rtDW -> ciqyyvncvs ; lastU = &
_rtDW -> efdshsf0xz ; } } _rtB -> jn4jvowsdb = ( _rtB -> d5f2a5su5x - * lastU
) / ( ssGetT ( S ) - dcitqx0ard ) ; } if ( ssIsSampleHit ( S , 1 , 0 ) ) {
_rtB -> lq3fve1wsv [ 0 ] = _rtP -> P_345 [ 0 ] ; _rtB -> lq3fve1wsv [ 1 ] =
_rtP -> P_345 [ 1 ] ; _rtB -> lq3fve1wsv [ 2 ] = _rtP -> P_345 [ 2 ] ; _rtB
-> lq3fve1wsv [ 3 ] = _rtP -> P_345 [ 3 ] ; _rtB -> nb2a4mhgfu = _rtP ->
P_346 ; _rtB -> mw42qnsi52 = _rtP -> P_347 ; } lf00dhirwu = ssGetT ( S ) ;
_rtB -> bee2lpp1c2 = rt_Lookup ( _rtP -> P_348 , 6 , lf00dhirwu , _rtP ->
P_349 ) ; if ( _rtB -> nb2a4mhgfu >= _rtP -> P_350 ) { _rtB -> oqqtyppp2s =
_rtB -> mw42qnsi52 ; } else { _rtB -> oqqtyppp2s = _rtB -> bee2lpp1c2 ; } if
( ssIsSampleHit ( S , 1 , 0 ) ) { ssCallAccelRunBlock ( S , 22 , 827 ,
SS_CALL_MDL_OUTPUTS ) ; } if ( ( _rtDW -> mo23tn4kgp >= ssGetT ( S ) ) && (
_rtDW -> dugrc1azdb >= ssGetT ( S ) ) ) { _rtB -> dn2xaakyeg = 0.0 ; } else {
dcitqx0ard = _rtDW -> mo23tn4kgp ; lastU = & _rtDW -> kcfaqt2psq ; if ( _rtDW
-> mo23tn4kgp < _rtDW -> dugrc1azdb ) { if ( _rtDW -> dugrc1azdb < ssGetT ( S
) ) { dcitqx0ard = _rtDW -> dugrc1azdb ; lastU = & _rtDW -> k4hamys051 ; } }
else { if ( _rtDW -> mo23tn4kgp >= ssGetT ( S ) ) { dcitqx0ard = _rtDW ->
dugrc1azdb ; lastU = & _rtDW -> k4hamys051 ; } } _rtB -> dn2xaakyeg = ( _rtB
-> bee2lpp1c2 - * lastU ) / ( ssGetT ( S ) - dcitqx0ard ) ; } if (
ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> bgiywxjdvz [ 0 ] = _rtP -> P_354 [ 0
] ; _rtB -> bgiywxjdvz [ 1 ] = _rtP -> P_354 [ 1 ] ; _rtB -> bgiywxjdvz [ 2 ]
= _rtP -> P_354 [ 2 ] ; _rtB -> bgiywxjdvz [ 3 ] = _rtP -> P_354 [ 3 ] ; _rtB
-> ovcb3hf0cd = _rtP -> P_355 ; _rtB -> atyjqtsk4f = _rtP -> P_356 ; }
lf00dhirwu = ssGetT ( S ) ; _rtB -> l5elgfbepn = rt_Lookup ( _rtP -> P_357 ,
6 , lf00dhirwu , _rtP -> P_358 ) ; if ( _rtB -> ovcb3hf0cd >= _rtP -> P_359 )
{ _rtB -> kpsnvas2dr = _rtB -> atyjqtsk4f ; } else { _rtB -> kpsnvas2dr =
_rtB -> l5elgfbepn ; } if ( ssIsSampleHit ( S , 1 , 0 ) ) {
ssCallAccelRunBlock ( S , 22 , 847 , SS_CALL_MDL_OUTPUTS ) ; } if ( ( _rtDW
-> d5biyu44pj >= ssGetT ( S ) ) && ( _rtDW -> jzsprnybyy >= ssGetT ( S ) ) )
{ _rtB -> bgnyp22hcm = 0.0 ; } else { dcitqx0ard = _rtDW -> d5biyu44pj ;
lastU = & _rtDW -> ovy4gvhwoy ; if ( _rtDW -> d5biyu44pj < _rtDW ->
jzsprnybyy ) { if ( _rtDW -> jzsprnybyy < ssGetT ( S ) ) { dcitqx0ard = _rtDW
-> jzsprnybyy ; lastU = & _rtDW -> ko3aupuzs4 ; } } else { if ( _rtDW ->
d5biyu44pj >= ssGetT ( S ) ) { dcitqx0ard = _rtDW -> jzsprnybyy ; lastU = &
_rtDW -> ko3aupuzs4 ; } } _rtB -> bgnyp22hcm = ( _rtB -> l5elgfbepn - * lastU
) / ( ssGetT ( S ) - dcitqx0ard ) ; } if ( ssIsSampleHit ( S , 1 , 0 ) ) {
_rtB -> ixrhvmng3e [ 0 ] = _rtP -> P_363 [ 0 ] ; _rtB -> ixrhvmng3e [ 1 ] =
_rtP -> P_363 [ 1 ] ; _rtB -> ixrhvmng3e [ 2 ] = _rtP -> P_363 [ 2 ] ; _rtB
-> ixrhvmng3e [ 3 ] = _rtP -> P_363 [ 3 ] ; _rtB -> eiobpro0cj = _rtP ->
P_364 ; _rtB -> lkbkdar3mq = _rtP -> P_365 ; } _rtB -> aqz30p2tek = ssGetT (
S ) ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> kybirzexyq = _rtP -> P_366
; } if ( ssIsMajorTimeStep ( S ) ) { _rtDW -> kntlmr3oin = ( _rtB ->
aqz30p2tek > _rtP -> P_367 ) ; } if ( _rtDW -> kntlmr3oin ) { lf00dhirwu =
_rtB -> lkbkdar3mq ; } else { lf00dhirwu = _rtB -> kybirzexyq ; } fd41t0nagf
= ssGetT ( S ) ; _rtB -> ad0pu05yfe = rt_Lookup ( _rtP -> P_368 , 6 ,
fd41t0nagf , _rtP -> P_369 ) ; if ( _rtB -> eiobpro0cj >= _rtP -> P_370 ) {
_rtB -> ixhi405de5 = lf00dhirwu ; } else { _rtB -> ixhi405de5 = _rtB ->
ad0pu05yfe ; } if ( ssIsSampleHit ( S , 1 , 0 ) ) { ssCallAccelRunBlock ( S ,
22 , 876 , SS_CALL_MDL_OUTPUTS ) ; } if ( ( _rtDW -> fww1xsjcty >= ssGetT ( S
) ) && ( _rtDW -> hfedwdq0tg >= ssGetT ( S ) ) ) { _rtB -> pr52boqidq = 0.0 ;
} else { dcitqx0ard = _rtDW -> fww1xsjcty ; lastU = & _rtDW -> hgdeeilk33 ;
if ( _rtDW -> fww1xsjcty < _rtDW -> hfedwdq0tg ) { if ( _rtDW -> hfedwdq0tg <
ssGetT ( S ) ) { dcitqx0ard = _rtDW -> hfedwdq0tg ; lastU = & _rtDW ->
dskzy3qq1o ; } } else { if ( _rtDW -> fww1xsjcty >= ssGetT ( S ) ) {
dcitqx0ard = _rtDW -> hfedwdq0tg ; lastU = & _rtDW -> dskzy3qq1o ; } } _rtB
-> pr52boqidq = ( _rtB -> ad0pu05yfe - * lastU ) / ( ssGetT ( S ) -
dcitqx0ard ) ; } if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> k3cmdqrav4 =
_rtP -> P_374 ; } if ( ssIsMajorTimeStep ( S ) ) { _rtDW -> pxt5cayfvv = (
_rtB -> aqz30p2tek > _rtP -> P_375 ) ; } if ( _rtDW -> pxt5cayfvv ) {
lf00dhirwu = _rtB -> lkbkdar3mq ; } else { lf00dhirwu = _rtB -> kybirzexyq ;
} fd41t0nagf = ssGetT ( S ) ; _rtB -> otlato2gfz = rt_Lookup ( _rtP -> P_376
, 6 , fd41t0nagf , _rtP -> P_377 ) ; if ( _rtB -> k3cmdqrav4 >= _rtP -> P_378
) { _rtB -> b5ti2bjms4 = lf00dhirwu ; } else { _rtB -> b5ti2bjms4 = _rtB ->
otlato2gfz ; } if ( ssIsSampleHit ( S , 1 , 0 ) ) { ssCallAccelRunBlock ( S ,
22 , 887 , SS_CALL_MDL_OUTPUTS ) ; } if ( ( _rtDW -> axi04dugoj >= ssGetT ( S
) ) && ( _rtDW -> or5edoufmk >= ssGetT ( S ) ) ) { _rtB -> evqeudp0my = 0.0 ;
} else { dcitqx0ard = _rtDW -> axi04dugoj ; lastU = & _rtDW -> bg5gcpdwec ;
if ( _rtDW -> axi04dugoj < _rtDW -> or5edoufmk ) { if ( _rtDW -> or5edoufmk <
ssGetT ( S ) ) { dcitqx0ard = _rtDW -> or5edoufmk ; lastU = & _rtDW ->
ox1y3mvsvl ; } } else { if ( _rtDW -> axi04dugoj >= ssGetT ( S ) ) {
dcitqx0ard = _rtDW -> or5edoufmk ; lastU = & _rtDW -> ox1y3mvsvl ; } } _rtB
-> evqeudp0my = ( _rtB -> otlato2gfz - * lastU ) / ( ssGetT ( S ) -
dcitqx0ard ) ; } if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> jur2rmoxjs =
_rtP -> P_382 ; } if ( ssIsMajorTimeStep ( S ) ) { _rtDW -> osxzntkeui = (
_rtB -> aqz30p2tek > _rtP -> P_383 ) ; } if ( _rtDW -> osxzntkeui ) {
lf00dhirwu = _rtB -> lkbkdar3mq ; } else { lf00dhirwu = _rtB -> kybirzexyq ;
} fd41t0nagf = ssGetT ( S ) ; _rtB -> gzahtu1h0r = rt_Lookup ( _rtP -> P_384
, 6 , fd41t0nagf , _rtP -> P_385 ) ; if ( _rtB -> jur2rmoxjs >= _rtP -> P_386
) { _rtB -> mcigg4rerp = lf00dhirwu ; } else { _rtB -> mcigg4rerp = _rtB ->
gzahtu1h0r ; } if ( ssIsSampleHit ( S , 1 , 0 ) ) { ssCallAccelRunBlock ( S ,
22 , 898 , SS_CALL_MDL_OUTPUTS ) ; } if ( ( _rtDW -> dgx0pzxe0j >= ssGetT ( S
) ) && ( _rtDW -> f2q2cyywqj >= ssGetT ( S ) ) ) { _rtB -> fixqfw4dtv = 0.0 ;
} else { dcitqx0ard = _rtDW -> dgx0pzxe0j ; lastU = & _rtDW -> dzpof3s3ht ;
if ( _rtDW -> dgx0pzxe0j < _rtDW -> f2q2cyywqj ) { if ( _rtDW -> f2q2cyywqj <
ssGetT ( S ) ) { dcitqx0ard = _rtDW -> f2q2cyywqj ; lastU = & _rtDW ->
lmj53gkvqj ; } } else { if ( _rtDW -> dgx0pzxe0j >= ssGetT ( S ) ) {
dcitqx0ard = _rtDW -> f2q2cyywqj ; lastU = & _rtDW -> lmj53gkvqj ; } } _rtB
-> fixqfw4dtv = ( _rtB -> gzahtu1h0r - * lastU ) / ( ssGetT ( S ) -
dcitqx0ard ) ; } if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> bui4mwn2dk =
_rtP -> P_390 ; _rtB -> hsmze4xjcb = _rtP -> P_391 ; } _rtB -> nufvkjgydv =
ssGetT ( S ) ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> dxet5l4qdp = _rtP
-> P_392 ; } if ( ssIsMajorTimeStep ( S ) ) { _rtDW -> l3lsrpapb5 = ( _rtB ->
nufvkjgydv > _rtP -> P_393 ) ; } if ( _rtDW -> l3lsrpapb5 ) { lf00dhirwu =
_rtB -> hsmze4xjcb ; } else { lf00dhirwu = _rtB -> dxet5l4qdp ; } fd41t0nagf
= ssGetT ( S ) ; _rtB -> bdalgpoie2 = rt_Lookup ( _rtP -> P_394 , 6 ,
fd41t0nagf , _rtP -> P_395 ) ; if ( _rtB -> bui4mwn2dk >= _rtP -> P_396 ) {
_rtB -> ovvjgfvrbi = lf00dhirwu ; } else { _rtB -> ovvjgfvrbi = _rtB ->
bdalgpoie2 ; } if ( ssIsSampleHit ( S , 1 , 0 ) ) { ssCallAccelRunBlock ( S ,
22 , 919 , SS_CALL_MDL_OUTPUTS ) ; } if ( ( _rtDW -> cfo3id0zd0 >= ssGetT ( S
) ) && ( _rtDW -> pssjqgfv3g >= ssGetT ( S ) ) ) { _rtB -> iftnmhe3rg = 0.0 ;
} else { dcitqx0ard = _rtDW -> cfo3id0zd0 ; lastU = & _rtDW -> fkppfphbi1 ;
if ( _rtDW -> cfo3id0zd0 < _rtDW -> pssjqgfv3g ) { if ( _rtDW -> pssjqgfv3g <
ssGetT ( S ) ) { dcitqx0ard = _rtDW -> pssjqgfv3g ; lastU = & _rtDW ->
gayfcac1c2 ; } } else { if ( _rtDW -> cfo3id0zd0 >= ssGetT ( S ) ) {
dcitqx0ard = _rtDW -> pssjqgfv3g ; lastU = & _rtDW -> gayfcac1c2 ; } } _rtB
-> iftnmhe3rg = ( _rtB -> bdalgpoie2 - * lastU ) / ( ssGetT ( S ) -
dcitqx0ard ) ; } if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> cq2cs20tht =
_rtP -> P_400 ; } if ( ssIsMajorTimeStep ( S ) ) { _rtDW -> bbzpmr53sa = (
_rtB -> nufvkjgydv > _rtP -> P_401 ) ; } if ( _rtDW -> bbzpmr53sa ) {
lf00dhirwu = _rtB -> hsmze4xjcb ; } else { lf00dhirwu = _rtB -> dxet5l4qdp ;
} fd41t0nagf = ssGetT ( S ) ; _rtB -> kdikmmto4j = rt_Lookup ( _rtP -> P_402
, 6 , fd41t0nagf , _rtP -> P_403 ) ; if ( _rtB -> cq2cs20tht >= _rtP -> P_404
) { _rtB -> de2tfgnaa1 = lf00dhirwu ; } else { _rtB -> de2tfgnaa1 = _rtB ->
kdikmmto4j ; } if ( ssIsSampleHit ( S , 1 , 0 ) ) { ssCallAccelRunBlock ( S ,
22 , 930 , SS_CALL_MDL_OUTPUTS ) ; } if ( ( _rtDW -> mxhxxqi0fv >= ssGetT ( S
) ) && ( _rtDW -> munn2qqbl3 >= ssGetT ( S ) ) ) { _rtB -> htuuwwr5e0 = 0.0 ;
} else { dcitqx0ard = _rtDW -> mxhxxqi0fv ; lastU = & _rtDW -> kyamekchg0 ;
if ( _rtDW -> mxhxxqi0fv < _rtDW -> munn2qqbl3 ) { if ( _rtDW -> munn2qqbl3 <
ssGetT ( S ) ) { dcitqx0ard = _rtDW -> munn2qqbl3 ; lastU = & _rtDW ->
f4rv2qsdac ; } } else { if ( _rtDW -> mxhxxqi0fv >= ssGetT ( S ) ) {
dcitqx0ard = _rtDW -> munn2qqbl3 ; lastU = & _rtDW -> f4rv2qsdac ; } } _rtB
-> htuuwwr5e0 = ( _rtB -> kdikmmto4j - * lastU ) / ( ssGetT ( S ) -
dcitqx0ard ) ; } if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> bgia3itjza =
_rtP -> P_408 ; } if ( ssIsMajorTimeStep ( S ) ) { _rtDW -> pf2p44jdzz = (
_rtB -> nufvkjgydv > _rtP -> P_409 ) ; } if ( _rtDW -> pf2p44jdzz ) {
lf00dhirwu = _rtB -> hsmze4xjcb ; } else { lf00dhirwu = _rtB -> dxet5l4qdp ;
} fd41t0nagf = ssGetT ( S ) ; _rtB -> axwdtgq4x3 = rt_Lookup ( _rtP -> P_410
, 6 , fd41t0nagf , _rtP -> P_411 ) ; if ( _rtB -> bgia3itjza >= _rtP -> P_412
) { _rtB -> d0xkjx4wja = lf00dhirwu ; } else { _rtB -> d0xkjx4wja = _rtB ->
axwdtgq4x3 ; } if ( ssIsSampleHit ( S , 1 , 0 ) ) { ssCallAccelRunBlock ( S ,
22 , 941 , SS_CALL_MDL_OUTPUTS ) ; } if ( ( _rtDW -> iiyytfhzq0 >= ssGetT ( S
) ) && ( _rtDW -> oxctatvhvv >= ssGetT ( S ) ) ) { _rtB -> pwmkrzyfh0 = 0.0 ;
} else { dcitqx0ard = _rtDW -> iiyytfhzq0 ; lastU = & _rtDW -> ehxix0iptb ;
if ( _rtDW -> iiyytfhzq0 < _rtDW -> oxctatvhvv ) { if ( _rtDW -> oxctatvhvv <
ssGetT ( S ) ) { dcitqx0ard = _rtDW -> oxctatvhvv ; lastU = & _rtDW ->
i1ok2cnj4x ; } } else { if ( _rtDW -> iiyytfhzq0 >= ssGetT ( S ) ) {
dcitqx0ard = _rtDW -> oxctatvhvv ; lastU = & _rtDW -> i1ok2cnj4x ; } } _rtB
-> pwmkrzyfh0 = ( _rtB -> axwdtgq4x3 - * lastU ) / ( ssGetT ( S ) -
dcitqx0ard ) ; } lf00dhirwu = _rtP -> P_416 * _rtB -> ovm3w2lfpw [ 85 ] ;
fd41t0nagf = _rtP -> P_417 * _rtB -> ovm3w2lfpw [ 86 ] ; _rtB -> az5lck3won [
0 ] = lf00dhirwu ; _rtB -> az5lck3won [ 1 ] = fd41t0nagf ; _rtB -> az5lck3won
[ 2 ] = _rtP -> P_418 * _rtB -> ovm3w2lfpw [ 87 ] ; ssCallAccelRunBlock ( S ,
22 , 1005 , SS_CALL_MDL_OUTPUTS ) ; UNUSED_PARAMETER ( tid ) ; }
#define MDL_UPDATE
static void mdlUpdate ( SimStruct * S , int_T tid ) { real_T * lastU ;
n3qi1whofz * _rtB ; loikxjbxjg * _rtP ; ew10rzwqr2 * _rtDW ; _rtDW = ( (
ew10rzwqr2 * ) ssGetRootDWork ( S ) ) ; _rtP = ( ( loikxjbxjg * )
ssGetDefaultParam ( S ) ) ; _rtB = ( ( n3qi1whofz * ) _ssGetBlockIO ( S ) ) ;
if ( ssIsSampleHit ( S , 10 , 0 ) ) { _rtDW -> bwa13dvhzm = _rtB ->
paisrbathf ; } if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtDW -> eaysl4zk4f =
_rtB -> dx5gafotgs ; } _rtDW -> nwv5vwpnq5 . IcNeedsLoading = 0 ; { enum {
INTG_NORMAL , INTG_LEAVING_UPPER_SAT , INTG_LEAVING_LOWER_SAT ,
INTG_UPPER_SAT , INTG_LOWER_SAT } ; if ( ( ( f1xhd02yjc * ) ssGetContStates (
S ) ) -> i25grusegg == _rtP -> P_16 ) { switch ( _rtDW -> iuyqtjjw5g ) { case
INTG_UPPER_SAT : if ( _rtB -> d1rhtio1df < 0.0 ) { ssSetSolverNeedsReset ( S
) ; _rtDW -> iuyqtjjw5g = INTG_LEAVING_UPPER_SAT ; } break ; case
INTG_LEAVING_UPPER_SAT : if ( _rtB -> d1rhtio1df >= 0.0 ) { _rtDW ->
iuyqtjjw5g = INTG_UPPER_SAT ; ssSetSolverNeedsReset ( S ) ; } break ; default
: ssSetSolverNeedsReset ( S ) ; if ( _rtB -> d1rhtio1df < 0.0 ) { _rtDW ->
iuyqtjjw5g = INTG_LEAVING_UPPER_SAT ; } else { _rtDW -> iuyqtjjw5g =
INTG_UPPER_SAT ; } break ; } } else if ( ( ( f1xhd02yjc * ) ssGetContStates (
S ) ) -> i25grusegg == _rtP -> P_17 ) { switch ( _rtDW -> iuyqtjjw5g ) { case
INTG_LOWER_SAT : if ( _rtB -> d1rhtio1df > 0.0 ) { ssSetSolverNeedsReset ( S
) ; _rtDW -> iuyqtjjw5g = INTG_LEAVING_LOWER_SAT ; } break ; case
INTG_LEAVING_LOWER_SAT : if ( _rtB -> d1rhtio1df <= 0.0 ) { _rtDW ->
iuyqtjjw5g = INTG_LOWER_SAT ; ssSetSolverNeedsReset ( S ) ; } break ; default
: ssSetSolverNeedsReset ( S ) ; if ( _rtB -> d1rhtio1df > 0.0 ) { _rtDW ->
iuyqtjjw5g = INTG_LEAVING_LOWER_SAT ; } else { _rtDW -> iuyqtjjw5g =
INTG_LOWER_SAT ; } break ; } } else { _rtDW -> iuyqtjjw5g = INTG_NORMAL ; } }
ssCallAccelRunBlock ( S , 0 , 0 , SS_CALL_MDL_UPDATE ) ; if ( ssIsSampleHit (
S , 8 , 0 ) ) { _rtDW -> n30m4wwaoj = _rtB -> kk0dl1ht4y ; _rtDW ->
ddcecwrf1k = _rtB -> kfx5eql4r3 ; } if ( ssIsSampleHit ( S , 9 , 0 ) ) {
_rtDW -> eayuayh5wq = _rtB -> cxd5xzpnzu ; } if ( ssIsSampleHit ( S , 8 , 0 )
) { _rtDW -> d5qoy21xx2 = _rtB -> ihf2rerjiy . odlvr5yghp ; } if (
ssIsSampleHit ( S , 9 , 0 ) ) { _rtDW -> jwpjduc0fo = _rtB -> hhlfhf52lq ; }
if ( ssIsSampleHit ( S , 8 , 0 ) ) { _rtDW -> bcgeygemi4 = _rtB -> jjwutrcwja
. odlvr5yghp ; } if ( ssIsSampleHit ( S , 9 , 0 ) ) { _rtDW -> mvz31rqucg =
_rtB -> o5wkgz1fw2 ; } if ( ssIsSampleHit ( S , 8 , 0 ) ) { _rtDW ->
nvjcinerze = _rtB -> pjnmj4pukv . odlvr5yghp ; } if ( ssIsSampleHit ( S , 9 ,
0 ) ) { _rtDW -> gp42job5lm = _rtB -> gbxxxcelvm ; } if ( ssIsSampleHit ( S ,
8 , 0 ) ) { _rtDW -> etqztvh0rt = _rtB -> dspspwprkx . odlvr5yghp ; } if (
ssIsSampleHit ( S , 9 , 0 ) ) { _rtDW -> htlixbax51 = _rtB -> jpj5a4m5zx ; }
if ( ssIsSampleHit ( S , 8 , 0 ) ) { _rtDW -> gjqzyinbwr = _rtB -> evksckf5yd
. odlvr5yghp ; } if ( ssIsSampleHit ( S , 9 , 0 ) ) { _rtDW -> pip1bq031s =
_rtB -> jcfktaxszb ; } if ( ssIsSampleHit ( S , 8 , 0 ) ) { _rtDW ->
irewrnl3me = _rtB -> cf2m0e35rt . odlvr5yghp ; } if ( ssIsSampleHit ( S , 7 ,
0 ) ) { _rtDW -> dcxemsgm1d = _rtB -> dkuc5gkown ; _rtDW -> pq2lgjwnyq = _rtB
-> du0chwvarzb . odlvr5yghp ; } if ( _rtDW -> bjr1bmo40x == ( rtInf ) ) {
_rtDW -> bjr1bmo40x = ssGetT ( S ) ; lastU = & _rtDW -> akxsn5iktm ; } else
if ( _rtDW -> ffo1wggexx == ( rtInf ) ) { _rtDW -> ffo1wggexx = ssGetT ( S )
; lastU = & _rtDW -> o2byh3o11z ; } else if ( _rtDW -> bjr1bmo40x < _rtDW ->
ffo1wggexx ) { _rtDW -> bjr1bmo40x = ssGetT ( S ) ; lastU = & _rtDW ->
akxsn5iktm ; } else { _rtDW -> ffo1wggexx = ssGetT ( S ) ; lastU = & _rtDW ->
o2byh3o11z ; } * lastU = _rtB -> exte1o3kqg ; if ( ssIsSampleHit ( S , 8 , 0
) ) { _rtDW -> iridzv04lr = _rtB -> i4fkxcebgm ; } if ( ssIsSampleHit ( S , 5
, 0 ) ) { _rtDW -> ptzitxz1xb = _rtB -> evksckf5yd . odlvr5yghp ; _rtDW ->
agml1ijzs4 = _rtB -> ihf2rerjiy . odlvr5yghp ; _rtDW -> gi5fv1o4t2 = _rtB ->
jjwutrcwja . odlvr5yghp ; _rtDW -> jutruqwjjq = _rtB -> pjnmj4pukv .
odlvr5yghp ; _rtDW -> iia3j0x4g1 = _rtB -> dspspwprkx . odlvr5yghp ; _rtDW ->
dvvslw54fh = _rtB -> cf2m0e35rt . odlvr5yghp ; } if ( _rtDW -> akp24mq0we ==
( rtInf ) ) { _rtDW -> akp24mq0we = ssGetT ( S ) ; lastU = & _rtDW ->
nb1yf2latz ; } else if ( _rtDW -> lil4u4ahda == ( rtInf ) ) { _rtDW ->
lil4u4ahda = ssGetT ( S ) ; lastU = & _rtDW -> na1ro2yz1c ; } else if ( _rtDW
-> akp24mq0we < _rtDW -> lil4u4ahda ) { _rtDW -> akp24mq0we = ssGetT ( S ) ;
lastU = & _rtDW -> nb1yf2latz ; } else { _rtDW -> lil4u4ahda = ssGetT ( S ) ;
lastU = & _rtDW -> na1ro2yz1c ; } * lastU = _rtB -> l2vitmrji2 ; if ( _rtDW
-> lcaqj5fzqx == ( rtInf ) ) { _rtDW -> lcaqj5fzqx = ssGetT ( S ) ; lastU = &
_rtDW -> fzovofsgfr ; } else if ( _rtDW -> bgbbgunjez == ( rtInf ) ) { _rtDW
-> bgbbgunjez = ssGetT ( S ) ; lastU = & _rtDW -> jhhq5tn2os ; } else if (
_rtDW -> lcaqj5fzqx < _rtDW -> bgbbgunjez ) { _rtDW -> lcaqj5fzqx = ssGetT (
S ) ; lastU = & _rtDW -> fzovofsgfr ; } else { _rtDW -> bgbbgunjez = ssGetT (
S ) ; lastU = & _rtDW -> jhhq5tn2os ; } * lastU = _rtB -> oiw4peemyt ; if (
_rtDW -> ntwmp1zcea == ( rtInf ) ) { _rtDW -> ntwmp1zcea = ssGetT ( S ) ;
lastU = & _rtDW -> pmmr2hc351 ; } else if ( _rtDW -> dufh5gari0 == ( rtInf )
) { _rtDW -> dufh5gari0 = ssGetT ( S ) ; lastU = & _rtDW -> cmtw4ie32s ; }
else if ( _rtDW -> ntwmp1zcea < _rtDW -> dufh5gari0 ) { _rtDW -> ntwmp1zcea =
ssGetT ( S ) ; lastU = & _rtDW -> pmmr2hc351 ; } else { _rtDW -> dufh5gari0 =
ssGetT ( S ) ; lastU = & _rtDW -> cmtw4ie32s ; } * lastU = _rtB -> oxubidsgv5
; if ( _rtDW -> hihr1wdmnl == ( rtInf ) ) { _rtDW -> hihr1wdmnl = ssGetT ( S
) ; lastU = & _rtDW -> lwmzevgbkl ; } else if ( _rtDW -> pkcgvdllnd == (
rtInf ) ) { _rtDW -> pkcgvdllnd = ssGetT ( S ) ; lastU = & _rtDW ->
ihgep3eq3u ; } else if ( _rtDW -> hihr1wdmnl < _rtDW -> pkcgvdllnd ) { _rtDW
-> hihr1wdmnl = ssGetT ( S ) ; lastU = & _rtDW -> lwmzevgbkl ; } else { _rtDW
-> pkcgvdllnd = ssGetT ( S ) ; lastU = & _rtDW -> ihgep3eq3u ; } * lastU =
_rtB -> fw41uzozrg ; if ( _rtDW -> as10pgcy1c == ( rtInf ) ) { _rtDW ->
as10pgcy1c = ssGetT ( S ) ; lastU = & _rtDW -> gb3l1fa040 ; } else if ( _rtDW
-> aczuqlqnju == ( rtInf ) ) { _rtDW -> aczuqlqnju = ssGetT ( S ) ; lastU = &
_rtDW -> mu2kg3d13s ; } else if ( _rtDW -> as10pgcy1c < _rtDW -> aczuqlqnju )
{ _rtDW -> as10pgcy1c = ssGetT ( S ) ; lastU = & _rtDW -> gb3l1fa040 ; } else
{ _rtDW -> aczuqlqnju = ssGetT ( S ) ; lastU = & _rtDW -> mu2kg3d13s ; } *
lastU = _rtB -> fjr4qfqjjb ; if ( _rtDW -> kd4axxolcq == ( rtInf ) ) { _rtDW
-> kd4axxolcq = ssGetT ( S ) ; lastU = & _rtDW -> n5uxvn15h3 ; } else if (
_rtDW -> px3puybbg2 == ( rtInf ) ) { _rtDW -> px3puybbg2 = ssGetT ( S ) ;
lastU = & _rtDW -> eppjrrt5hr ; } else if ( _rtDW -> kd4axxolcq < _rtDW ->
px3puybbg2 ) { _rtDW -> kd4axxolcq = ssGetT ( S ) ; lastU = & _rtDW ->
n5uxvn15h3 ; } else { _rtDW -> px3puybbg2 = ssGetT ( S ) ; lastU = & _rtDW ->
eppjrrt5hr ; } * lastU = _rtB -> m2ofdiylcx ; if ( _rtDW -> bvi1nidy5m == (
rtInf ) ) { _rtDW -> bvi1nidy5m = ssGetT ( S ) ; lastU = & _rtDW ->
g1mvvuhb2x ; } else if ( _rtDW -> mo3krrlmpu == ( rtInf ) ) { _rtDW ->
mo3krrlmpu = ssGetT ( S ) ; lastU = & _rtDW -> blukxx0wjw ; } else if ( _rtDW
-> bvi1nidy5m < _rtDW -> mo3krrlmpu ) { _rtDW -> bvi1nidy5m = ssGetT ( S ) ;
lastU = & _rtDW -> g1mvvuhb2x ; } else { _rtDW -> mo3krrlmpu = ssGetT ( S ) ;
lastU = & _rtDW -> blukxx0wjw ; } * lastU = _rtB -> n21omilfin ; if ( _rtDW
-> ixbvclhhpb == ( rtInf ) ) { _rtDW -> ixbvclhhpb = ssGetT ( S ) ; lastU = &
_rtDW -> jnlfud1dvn ; } else if ( _rtDW -> n1lmx5wu3c == ( rtInf ) ) { _rtDW
-> n1lmx5wu3c = ssGetT ( S ) ; lastU = & _rtDW -> k01edtry13 ; } else if (
_rtDW -> ixbvclhhpb < _rtDW -> n1lmx5wu3c ) { _rtDW -> ixbvclhhpb = ssGetT (
S ) ; lastU = & _rtDW -> jnlfud1dvn ; } else { _rtDW -> n1lmx5wu3c = ssGetT (
S ) ; lastU = & _rtDW -> k01edtry13 ; } * lastU = _rtB -> fdgwr40qza ; if (
_rtDW -> fxubmsah3k == ( rtInf ) ) { _rtDW -> fxubmsah3k = ssGetT ( S ) ;
lastU = & _rtDW -> hlpdm1dqii ; } else if ( _rtDW -> d0fyomm1ti == ( rtInf )
) { _rtDW -> d0fyomm1ti = ssGetT ( S ) ; lastU = & _rtDW -> ngjpm1iptv ; }
else if ( _rtDW -> fxubmsah3k < _rtDW -> d0fyomm1ti ) { _rtDW -> fxubmsah3k =
ssGetT ( S ) ; lastU = & _rtDW -> hlpdm1dqii ; } else { _rtDW -> d0fyomm1ti =
ssGetT ( S ) ; lastU = & _rtDW -> ngjpm1iptv ; } * lastU = _rtB -> hyoheftkam
; if ( _rtDW -> in2mxzxekv == ( rtInf ) ) { _rtDW -> in2mxzxekv = ssGetT ( S
) ; lastU = & _rtDW -> fo5mttneq3 ; } else if ( _rtDW -> ciqyyvncvs == (
rtInf ) ) { _rtDW -> ciqyyvncvs = ssGetT ( S ) ; lastU = & _rtDW ->
efdshsf0xz ; } else if ( _rtDW -> in2mxzxekv < _rtDW -> ciqyyvncvs ) { _rtDW
-> in2mxzxekv = ssGetT ( S ) ; lastU = & _rtDW -> fo5mttneq3 ; } else { _rtDW
-> ciqyyvncvs = ssGetT ( S ) ; lastU = & _rtDW -> efdshsf0xz ; } * lastU =
_rtB -> d5f2a5su5x ; if ( _rtDW -> mo23tn4kgp == ( rtInf ) ) { _rtDW ->
mo23tn4kgp = ssGetT ( S ) ; lastU = & _rtDW -> kcfaqt2psq ; } else if ( _rtDW
-> dugrc1azdb == ( rtInf ) ) { _rtDW -> dugrc1azdb = ssGetT ( S ) ; lastU = &
_rtDW -> k4hamys051 ; } else if ( _rtDW -> mo23tn4kgp < _rtDW -> dugrc1azdb )
{ _rtDW -> mo23tn4kgp = ssGetT ( S ) ; lastU = & _rtDW -> kcfaqt2psq ; } else
{ _rtDW -> dugrc1azdb = ssGetT ( S ) ; lastU = & _rtDW -> k4hamys051 ; } *
lastU = _rtB -> bee2lpp1c2 ; if ( _rtDW -> d5biyu44pj == ( rtInf ) ) { _rtDW
-> d5biyu44pj = ssGetT ( S ) ; lastU = & _rtDW -> ovy4gvhwoy ; } else if (
_rtDW -> jzsprnybyy == ( rtInf ) ) { _rtDW -> jzsprnybyy = ssGetT ( S ) ;
lastU = & _rtDW -> ko3aupuzs4 ; } else if ( _rtDW -> d5biyu44pj < _rtDW ->
jzsprnybyy ) { _rtDW -> d5biyu44pj = ssGetT ( S ) ; lastU = & _rtDW ->
ovy4gvhwoy ; } else { _rtDW -> jzsprnybyy = ssGetT ( S ) ; lastU = & _rtDW ->
ko3aupuzs4 ; } * lastU = _rtB -> l5elgfbepn ; if ( _rtDW -> fww1xsjcty == (
rtInf ) ) { _rtDW -> fww1xsjcty = ssGetT ( S ) ; lastU = & _rtDW ->
hgdeeilk33 ; } else if ( _rtDW -> hfedwdq0tg == ( rtInf ) ) { _rtDW ->
hfedwdq0tg = ssGetT ( S ) ; lastU = & _rtDW -> dskzy3qq1o ; } else if ( _rtDW
-> fww1xsjcty < _rtDW -> hfedwdq0tg ) { _rtDW -> fww1xsjcty = ssGetT ( S ) ;
lastU = & _rtDW -> hgdeeilk33 ; } else { _rtDW -> hfedwdq0tg = ssGetT ( S ) ;
lastU = & _rtDW -> dskzy3qq1o ; } * lastU = _rtB -> ad0pu05yfe ; if ( _rtDW
-> axi04dugoj == ( rtInf ) ) { _rtDW -> axi04dugoj = ssGetT ( S ) ; lastU = &
_rtDW -> bg5gcpdwec ; } else if ( _rtDW -> or5edoufmk == ( rtInf ) ) { _rtDW
-> or5edoufmk = ssGetT ( S ) ; lastU = & _rtDW -> ox1y3mvsvl ; } else if (
_rtDW -> axi04dugoj < _rtDW -> or5edoufmk ) { _rtDW -> axi04dugoj = ssGetT (
S ) ; lastU = & _rtDW -> bg5gcpdwec ; } else { _rtDW -> or5edoufmk = ssGetT (
S ) ; lastU = & _rtDW -> ox1y3mvsvl ; } * lastU = _rtB -> otlato2gfz ; if (
_rtDW -> dgx0pzxe0j == ( rtInf ) ) { _rtDW -> dgx0pzxe0j = ssGetT ( S ) ;
lastU = & _rtDW -> dzpof3s3ht ; } else if ( _rtDW -> f2q2cyywqj == ( rtInf )
) { _rtDW -> f2q2cyywqj = ssGetT ( S ) ; lastU = & _rtDW -> lmj53gkvqj ; }
else if ( _rtDW -> dgx0pzxe0j < _rtDW -> f2q2cyywqj ) { _rtDW -> dgx0pzxe0j =
ssGetT ( S ) ; lastU = & _rtDW -> dzpof3s3ht ; } else { _rtDW -> f2q2cyywqj =
ssGetT ( S ) ; lastU = & _rtDW -> lmj53gkvqj ; } * lastU = _rtB -> gzahtu1h0r
; if ( _rtDW -> cfo3id0zd0 == ( rtInf ) ) { _rtDW -> cfo3id0zd0 = ssGetT ( S
) ; lastU = & _rtDW -> fkppfphbi1 ; } else if ( _rtDW -> pssjqgfv3g == (
rtInf ) ) { _rtDW -> pssjqgfv3g = ssGetT ( S ) ; lastU = & _rtDW ->
gayfcac1c2 ; } else if ( _rtDW -> cfo3id0zd0 < _rtDW -> pssjqgfv3g ) { _rtDW
-> cfo3id0zd0 = ssGetT ( S ) ; lastU = & _rtDW -> fkppfphbi1 ; } else { _rtDW
-> pssjqgfv3g = ssGetT ( S ) ; lastU = & _rtDW -> gayfcac1c2 ; } * lastU =
_rtB -> bdalgpoie2 ; if ( _rtDW -> mxhxxqi0fv == ( rtInf ) ) { _rtDW ->
mxhxxqi0fv = ssGetT ( S ) ; lastU = & _rtDW -> kyamekchg0 ; } else if ( _rtDW
-> munn2qqbl3 == ( rtInf ) ) { _rtDW -> munn2qqbl3 = ssGetT ( S ) ; lastU = &
_rtDW -> f4rv2qsdac ; } else if ( _rtDW -> mxhxxqi0fv < _rtDW -> munn2qqbl3 )
{ _rtDW -> mxhxxqi0fv = ssGetT ( S ) ; lastU = & _rtDW -> kyamekchg0 ; } else
{ _rtDW -> munn2qqbl3 = ssGetT ( S ) ; lastU = & _rtDW -> f4rv2qsdac ; } *
lastU = _rtB -> kdikmmto4j ; if ( _rtDW -> iiyytfhzq0 == ( rtInf ) ) { _rtDW
-> iiyytfhzq0 = ssGetT ( S ) ; lastU = & _rtDW -> ehxix0iptb ; } else if (
_rtDW -> oxctatvhvv == ( rtInf ) ) { _rtDW -> oxctatvhvv = ssGetT ( S ) ;
lastU = & _rtDW -> i1ok2cnj4x ; } else if ( _rtDW -> iiyytfhzq0 < _rtDW ->
oxctatvhvv ) { _rtDW -> iiyytfhzq0 = ssGetT ( S ) ; lastU = & _rtDW ->
ehxix0iptb ; } else { _rtDW -> oxctatvhvv = ssGetT ( S ) ; lastU = & _rtDW ->
i1ok2cnj4x ; } * lastU = _rtB -> axwdtgq4x3 ; UNUSED_PARAMETER ( tid ) ; }
#define MDL_DERIVATIVES
static void mdlDerivatives ( SimStruct * S ) { int_T is ; int_T ri ; static
const int8_T ir [ 9 ] = { 0 , 2 , 3 , 6 , 7 , 10 , 11 , 14 , 15 } ; static
const int8_T ir_p [ 9 ] = { 0 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 } ; static
const int8_T jc [ 15 ] = { 0 , 1 , 0 , 1 , 2 , 3 , 2 , 3 , 4 , 5 , 4 , 5 , 6
, 7 , 6 } ; n3qi1whofz * _rtB ; loikxjbxjg * _rtP ; f1xhd02yjc * _rtX ;
pqmvzr1kvu * _rtXdot ; ew10rzwqr2 * _rtDW ; _rtDW = ( ( ew10rzwqr2 * )
ssGetRootDWork ( S ) ) ; _rtXdot = ( ( pqmvzr1kvu * ) ssGetdX ( S ) ) ; _rtX
= ( ( f1xhd02yjc * ) ssGetContStates ( S ) ) ; _rtP = ( ( loikxjbxjg * )
ssGetDefaultParam ( S ) ) ; _rtB = ( ( n3qi1whofz * ) _ssGetBlockIO ( S ) ) ;
{ ( ( pqmvzr1kvu * ) ssGetdX ( S ) ) -> iw32rf0o5j = _rtB -> n2aisujrds ; }
_rtXdot -> marcvhut23 = 0.0 ; _rtXdot -> marcvhut23 += _rtP -> P_12 * _rtX ->
marcvhut23 ; _rtXdot -> marcvhut23 += _rtB -> d1rhtio1df ; { enum {
INTG_NORMAL , INTG_LEAVING_UPPER_SAT , INTG_LEAVING_LOWER_SAT ,
INTG_UPPER_SAT , INTG_LOWER_SAT } ; if ( ( _rtDW -> iuyqtjjw5g !=
INTG_UPPER_SAT ) && ( _rtDW -> iuyqtjjw5g != INTG_LOWER_SAT ) ) { ( (
pqmvzr1kvu * ) ssGetdX ( S ) ) -> i25grusegg = _rtB -> d1rhtio1df ; ( (
biadadh31q * ) ssGetContStateDisabled ( S ) ) -> i25grusegg = false ; } else
{ ( ( pqmvzr1kvu * ) ssGetdX ( S ) ) -> i25grusegg = 0.0 ; if ( ( _rtDW ->
iuyqtjjw5g == INTG_UPPER_SAT ) || ( _rtDW -> iuyqtjjw5g == INTG_LOWER_SAT ) )
{ ( ( biadadh31q * ) ssGetContStateDisabled ( S ) ) -> i25grusegg = true ; }
} } ssCallAccelRunBlock ( S , 0 , 0 , SS_CALL_MDL_DERIVATIVES ) ; memset ( &
_rtXdot -> lfttirzzy4 [ 0 ] , 0 , sizeof ( real_T ) << 3U ) ; for ( ri = 0 ;
ri < 8 ; ri ++ ) { for ( is = ir [ ri ] ; is < ir [ ri + 1 ] ; is ++ ) {
_rtXdot -> lfttirzzy4 [ ri ] += _rtP -> P_160 [ is ] * _rtX -> lfttirzzy4 [
jc [ is ] ] ; } } for ( ri = 0 ; ri < 8 ; ri ++ ) { is = ir_p [ ri ] ; while
( is < 1 ) { _rtXdot -> lfttirzzy4 [ ri ] += _rtP -> P_161 * _rtB ->
ntcj1yousd ; is = 1 ; } } _rtXdot -> loxeezbu2l = 0.0 ; _rtXdot -> loxeezbu2l
+= _rtP -> P_179 * _rtX -> loxeezbu2l ; _rtXdot -> loxeezbu2l += _rtP ->
P_180 * _rtB -> mwz2pti1y3 ; }
#define MDL_ZERO_CROSSINGS
static void mdlZeroCrossings ( SimStruct * S ) { n3qi1whofz * _rtB ;
loikxjbxjg * _rtP ; d15n1ti4kq * _rtZCSV ; ew10rzwqr2 * _rtDW ; _rtDW = ( (
ew10rzwqr2 * ) ssGetRootDWork ( S ) ) ; _rtZCSV = ( ( d15n1ti4kq * )
ssGetSolverZcSignalVector ( S ) ) ; _rtP = ( ( loikxjbxjg * )
ssGetDefaultParam ( S ) ) ; _rtB = ( ( n3qi1whofz * ) _ssGetBlockIO ( S ) ) ;
_rtZCSV -> frxsoxhdgk = _rtB -> l4w2p1hj0y - kesz3x3i1i ( S ) -> exararf2lq ;
{ enum { INTG_NORMAL , INTG_LEAVING_UPPER_SAT , INTG_LEAVING_LOWER_SAT ,
INTG_UPPER_SAT , INTG_LOWER_SAT } ; if ( _rtDW -> iuyqtjjw5g ==
INTG_LEAVING_UPPER_SAT && ( ( f1xhd02yjc * ) ssGetContStates ( S ) ) ->
i25grusegg >= _rtP -> P_16 ) { ( ( d15n1ti4kq * ) ssGetSolverZcSignalVector (
S ) ) -> dd5pqpfsvk = 0.0 ; } else { ( ( d15n1ti4kq * )
ssGetSolverZcSignalVector ( S ) ) -> dd5pqpfsvk = ( ( f1xhd02yjc * )
ssGetContStates ( S ) ) -> i25grusegg - _rtP -> P_16 ; } if ( _rtDW ->
iuyqtjjw5g == INTG_LEAVING_LOWER_SAT && ( ( f1xhd02yjc * ) ssGetContStates (
S ) ) -> i25grusegg <= _rtP -> P_17 ) { ( ( d15n1ti4kq * )
ssGetSolverZcSignalVector ( S ) ) -> a3bcu0amnk = 0.0 ; } else { ( (
d15n1ti4kq * ) ssGetSolverZcSignalVector ( S ) ) -> a3bcu0amnk = ( (
f1xhd02yjc * ) ssGetContStates ( S ) ) -> i25grusegg - _rtP -> P_17 ; } {
boolean_T anyStateSaturated = false ; if ( ( _rtDW -> iuyqtjjw5g ==
INTG_UPPER_SAT ) || ( _rtDW -> iuyqtjjw5g == INTG_LOWER_SAT ) ) {
anyStateSaturated = true ; } if ( anyStateSaturated ) { ( ( d15n1ti4kq * )
ssGetSolverZcSignalVector ( S ) ) -> dxmtido3pw = _rtB -> d1rhtio1df ; } else
{ ( ( d15n1ti4kq * ) ssGetSolverZcSignalVector ( S ) ) -> dxmtido3pw = 0.0 ;
} } } _rtZCSV -> jsmg3y5tvz = _rtB -> jp0usc5l2x - _rtP -> P_19 ; _rtZCSV ->
p35orceu0g = _rtB -> jp0usc5l2x - _rtP -> P_20 ; _rtZCSV -> kssrt5o4rr = _rtB
-> jp0usc5l2x - _rtP -> P_23 ; _rtZCSV -> m0oth4lvic = _rtB -> jp0usc5l2x -
_rtP -> P_24 ; _rtZCSV -> jzzavo45eh = _rtB -> l4w2p1hj0y - kesz3x3i1i ( S )
-> gopkhhzniv ; _rtZCSV -> exjywotrnw = _rtB -> ghfriakbun - _rtB ->
izuj5ssv31 ; _rtZCSV -> ozr3czm3hk = _rtB -> ghfriakbun - _rtB -> pfllrnj0g4
; ssCallAccelRunBlock ( S , 0 , 0 , SS_CALL_MDL_ZERO_CROSSINGS ) ; _rtZCSV ->
ll54q2z4pp = _rtB -> ftb5et0t1g [ 60 ] - _rtP -> P_50 ; _rtZCSV -> dbjhoajuif
= _rtB -> ftb5et0t1g [ 61 ] - _rtP -> P_53 ; _rtZCSV -> h4ghco41kj = _rtB ->
ftb5et0t1g [ 62 ] - _rtP -> P_56 ; _rtZCSV -> mq4r4lu3y5 = _rtB -> ftb5et0t1g
[ 63 ] - _rtP -> P_59 ; _rtZCSV -> mp2cxa5kzw = _rtB -> dhutlmm52k - _rtP ->
P_62 ; _rtZCSV -> nomybauvzp = _rtB -> ftb5et0t1g [ 64 ] - _rtP -> P_99 ;
_rtZCSV -> gpx2cqeqic = _rtB -> ftb5et0t1g [ 65 ] - _rtP -> P_102 ; _rtZCSV
-> ew1ko2eijc = _rtB -> ftb5et0t1g [ 66 ] - _rtP -> P_105 ; _rtZCSV ->
ojcu4e0b01 = _rtB -> ftb5et0t1g [ 67 ] - _rtP -> P_108 ; _rtZCSV ->
mtiftbb1bi = _rtB -> ftb5et0t1g [ 68 ] - _rtP -> P_119 ; _rtZCSV ->
d2r34gzyii = _rtB -> ftb5et0t1g [ 69 ] - _rtP -> P_122 ; _rtZCSV ->
aeohk2iylm = _rtB -> ftb5et0t1g [ 70 ] - _rtP -> P_125 ; _rtZCSV ->
ogarptlkbu = _rtB -> ftb5et0t1g [ 71 ] - _rtP -> P_128 ; _rtZCSV ->
mhwpjdyprk = _rtB -> ftb5et0t1g [ 58 ] - _rtP -> P_146 ; _rtZCSV ->
ezssebxqix = _rtB -> ftb5et0t1g [ 57 ] - _rtP -> P_149 ; _rtZCSV ->
m4s03gxfrn = _rtB -> ftb5et0t1g [ 59 ] - _rtP -> P_172 ; _rtZCSV ->
d1cnkny53v = _rtB -> d1rhtio1df ; _rtZCSV -> ejlt1uw1tl = _rtB -> d1rhtio1df
- kesz3x3i1i ( S ) -> l3qe21v1e2 ; _rtZCSV -> hvdxrqewjp = _rtB -> ftb5et0t1g
[ 20 ] - _rtP -> P_190 ; _rtZCSV -> nstomqtnmi = _rtB -> odual2fzdv - _rtP ->
P_191 ; _rtZCSV -> kntqbci5k5 = _rtB -> odual2fzdv - _rtP -> P_192 ; _rtZCSV
-> pbssrmxf14 = _rtB -> ftb5et0t1g [ 19 ] - _rtP -> P_195 ; _rtZCSV ->
k3k2xdnqtf = _rtB -> pe4hgyh2xo - _rtP -> P_196 ; _rtZCSV -> e4lojp0gfm =
_rtB -> pe4hgyh2xo - _rtP -> P_197 ; _rtZCSV -> gr5n23obhk = _rtB ->
ftb5et0t1g [ 18 ] - _rtP -> P_200 ; _rtZCSV -> clio0b4vcm = _rtB ->
a1rxyogj52 - _rtP -> P_201 ; _rtZCSV -> eqbvy3mlof = _rtB -> a1rxyogj52 -
_rtP -> P_202 ; _rtZCSV -> f3yu0dgysd = _rtB -> bqp0zjziar - _rtP -> P_260 ;
ssCallAccelRunBlock ( S , 22 , 650 , SS_CALL_MDL_ZERO_CROSSINGS ) ; _rtZCSV
-> dtksj22a0p = _rtB -> pimj2yxjrj - _rtP -> P_266 ; _rtZCSV -> gn4f1315nx =
_rtB -> bqp0zjziar - _rtP -> P_268 ; ssCallAccelRunBlock ( S , 22 , 661 ,
SS_CALL_MDL_ZERO_CROSSINGS ) ; _rtZCSV -> ahuv1wstls = _rtB -> j2uygvwij0 -
_rtP -> P_274 ; _rtZCSV -> ltz1csxd5g = _rtB -> bqp0zjziar - _rtP -> P_276 ;
ssCallAccelRunBlock ( S , 22 , 672 , SS_CALL_MDL_ZERO_CROSSINGS ) ; _rtZCSV
-> nxpgv3mueu = _rtB -> ax2p3nngvb - _rtP -> P_282 ; ssCallAccelRunBlock ( S
, 22 , 683 , SS_CALL_MDL_ZERO_CROSSINGS ) ; _rtZCSV -> go0jtm0dde = _rtB ->
psbwypggg2 - _rtP -> P_290 ; ssCallAccelRunBlock ( S , 22 , 703 ,
SS_CALL_MDL_ZERO_CROSSINGS ) ; _rtZCSV -> pmt0rm5j3j = _rtB -> jszde2yl3v -
_rtP -> P_299 ; ssCallAccelRunBlock ( S , 22 , 723 ,
SS_CALL_MDL_ZERO_CROSSINGS ) ; _rtZCSV -> lzedeovvop = _rtB -> lbycvykmgv -
_rtP -> P_308 ; ssCallAccelRunBlock ( S , 22 , 745 ,
SS_CALL_MDL_ZERO_CROSSINGS ) ; _rtZCSV -> nvv3foqmbs = _rtB -> hkxgi4hicd -
_rtP -> P_317 ; ssCallAccelRunBlock ( S , 22 , 765 ,
SS_CALL_MDL_ZERO_CROSSINGS ) ; _rtZCSV -> pkhhmhhpvo = _rtB -> idfhyvpuhl -
_rtP -> P_326 ; ssCallAccelRunBlock ( S , 22 , 785 ,
SS_CALL_MDL_ZERO_CROSSINGS ) ; _rtZCSV -> bqw1sjxtf1 = _rtB -> fmuoopn133 -
_rtP -> P_335 ; ssCallAccelRunBlock ( S , 22 , 807 ,
SS_CALL_MDL_ZERO_CROSSINGS ) ; _rtZCSV -> ca1hu1jfwh = _rtB -> jn4jvowsdb -
_rtP -> P_344 ; ssCallAccelRunBlock ( S , 22 , 827 ,
SS_CALL_MDL_ZERO_CROSSINGS ) ; _rtZCSV -> klaaquxwty = _rtB -> dn2xaakyeg -
_rtP -> P_353 ; ssCallAccelRunBlock ( S , 22 , 847 ,
SS_CALL_MDL_ZERO_CROSSINGS ) ; _rtZCSV -> ayttmsf4bx = _rtB -> bgnyp22hcm -
_rtP -> P_362 ; _rtZCSV -> bskcn42xo0 = _rtB -> aqz30p2tek - _rtP -> P_367 ;
ssCallAccelRunBlock ( S , 22 , 876 , SS_CALL_MDL_ZERO_CROSSINGS ) ; _rtZCSV
-> d02n5g3lfm = _rtB -> pr52boqidq - _rtP -> P_373 ; _rtZCSV -> crwbhhjlzh =
_rtB -> aqz30p2tek - _rtP -> P_375 ; ssCallAccelRunBlock ( S , 22 , 887 ,
SS_CALL_MDL_ZERO_CROSSINGS ) ; _rtZCSV -> lgl54j0vjz = _rtB -> evqeudp0my -
_rtP -> P_381 ; _rtZCSV -> bgkjlj3qsl = _rtB -> aqz30p2tek - _rtP -> P_383 ;
ssCallAccelRunBlock ( S , 22 , 898 , SS_CALL_MDL_ZERO_CROSSINGS ) ; _rtZCSV
-> iczl10bgov = _rtB -> fixqfw4dtv - _rtP -> P_389 ; _rtZCSV -> orjmi1hsic =
_rtB -> nufvkjgydv - _rtP -> P_393 ; ssCallAccelRunBlock ( S , 22 , 919 ,
SS_CALL_MDL_ZERO_CROSSINGS ) ; _rtZCSV -> czltvee4m4 = _rtB -> iftnmhe3rg -
_rtP -> P_399 ; _rtZCSV -> crllk3ykqc = _rtB -> nufvkjgydv - _rtP -> P_401 ;
ssCallAccelRunBlock ( S , 22 , 930 , SS_CALL_MDL_ZERO_CROSSINGS ) ; _rtZCSV
-> h04upjgfra = _rtB -> htuuwwr5e0 - _rtP -> P_407 ; _rtZCSV -> mqhjxwoo5z =
_rtB -> nufvkjgydv - _rtP -> P_409 ; ssCallAccelRunBlock ( S , 22 , 941 ,
SS_CALL_MDL_ZERO_CROSSINGS ) ; _rtZCSV -> nabdjxvlrk = _rtB -> pwmkrzyfh0 -
_rtP -> P_415 ; } static void mdlInitializeSizes ( SimStruct * S ) {
ssSetChecksumVal ( S , 0 , 3543154362U ) ; ssSetChecksumVal ( S , 1 ,
563680052U ) ; ssSetChecksumVal ( S , 2 , 2681623729U ) ; ssSetChecksumVal (
S , 3 , 988641381U ) ; { mxArray * slVerStructMat = NULL ; mxArray * slStrMat
= mxCreateString ( "simulink" ) ; char slVerChar [ 10 ] ; int status =
mexCallMATLAB ( 1 , & slVerStructMat , 1 , & slStrMat , "ver" ) ; if ( status
== 0 ) { mxArray * slVerMat = mxGetField ( slVerStructMat , 0 , "Version" ) ;
if ( slVerMat == NULL ) { status = 1 ; } else { status = mxGetString (
slVerMat , slVerChar , 10 ) ; } } mxDestroyArray ( slStrMat ) ;
mxDestroyArray ( slVerStructMat ) ; if ( ( status == 1 ) || ( strcmp (
slVerChar , "8.3" ) != 0 ) ) { return ; } } ssSetOptions ( S ,
SS_OPTION_EXCEPTION_FREE_CODE ) ; if ( ssGetSizeofDWork ( S ) != sizeof (
ew10rzwqr2 ) ) { ssSetErrorStatus ( S ,
"Unexpected error: Internal DWork sizes do "
"not match for accelerator mex file." ) ; } if ( ssGetSizeofGlobalBlockIO ( S
) != sizeof ( n3qi1whofz ) ) { ssSetErrorStatus ( S ,
"Unexpected error: Internal BlockIO sizes do "
"not match for accelerator mex file." ) ; } { int ssSizeofParams ;
ssGetSizeofParams ( S , & ssSizeofParams ) ; if ( ssSizeofParams != sizeof (
loikxjbxjg ) ) { static char msg [ 256 ] ; sprintf ( msg ,
"Unexpected error: Internal Parameters sizes do "
"not match for accelerator mex file." ) ; } } _ssSetDefaultParam ( S , (
real_T * ) & o2iu0a2jke ) ; _ssSetConstBlockIO ( S , & odcn43wyyk ) ;
rt_InitInfAndNaN ( sizeof ( real_T ) ) ; ( ( loikxjbxjg * ) ssGetDefaultParam
( S ) ) -> P_17 = rtMinusInf ; ( ( loikxjbxjg * ) ssGetDefaultParam ( S ) )
-> P_191 = rtInf ; ( ( loikxjbxjg * ) ssGetDefaultParam ( S ) ) -> P_196 =
rtInf ; ( ( loikxjbxjg * ) ssGetDefaultParam ( S ) ) -> P_201 = rtInf ; }
static void mdlInitializeSampleTimes ( SimStruct * S ) { { SimStruct * childS
; SysOutputFcn * callSysFcns ; childS = ssGetSFunction ( S , 1 ) ;
callSysFcns = ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ]
= ( SysOutputFcn ) ( NULL ) ; childS = ssGetSFunction ( S , 2 ) ; callSysFcns
= ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ] = (
SysOutputFcn ) ( NULL ) ; } } static void mdlTerminate ( SimStruct * S ) { }
#include "simulink.c"
