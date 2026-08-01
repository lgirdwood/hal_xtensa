/* SPDX-License-Identifier: BSD-3-Clause
 *
 * Stub xt_hifi3.h for LLVM Clang builds targeting intel_ace15_mtpm.
 *
 * The full Cadence XCC TIE header (xtensa/tie/xt_hifi3.h) is only available
 * with the Cadence XCC toolchain installation. This stub provides the minimum
 * type definitions and no-op intrinsics to allow the SOF codebase to compile
 * with LLVM Clang using generic (non-HiFi) C implementations.
 *
 * Note: HiFi3 SIMD intrinsics are NOT functional with this stub. Code paths
 * that use these types must be guarded by __XCC__ checks or similar.
 * The tflm-classify.c module uses TFLM C++ kernels, not HiFi3 intrinsics.
 */

#ifndef XT_HIFI3_H
#define XT_HIFI3_H

#include <stdint.h>

/* Minimal type stubs for HiFi3 types used in format_hifi3.h */
typedef int64_t  ae_f64;
typedef int64_t  ae_int64;
typedef int32_t  ae_int32;
typedef int32_t  ae_f32;
typedef int32_t  ae_f24;
typedef int16_t  ae_int16;
typedef int16_t  ae_f16;
typedef int64_t  ae_int32x2;   /* Packed 2x32-bit (stub as scalar) */
typedef int64_t  ae_f32x2;     /* Packed 2x32-bit float (stub as scalar) */
typedef int64_t  ae_f24x2;
typedef int32_t  ae_p24f;
typedef int64_t  ae_p24x2s;
typedef int64_t  ae_p24x2f;
typedef int16_t  ae_p16s;
typedef int64_t  ae_int16x4;   /* Packed 4x16-bit (stub as scalar) */
typedef int64_t  ae_f16x4;

/* Minimal stub intrinsics - scalar no-op fallbacks for format_hifi3.h */
static inline ae_f64    AE_SLAI64S(ae_f64 x, int s)              { return x << s; }
static inline ae_int64  AE_SRAI64(ae_int64 x, int s)             { return x >> s; }
static inline int32_t   AE_MOVINT32_FROMINT64(ae_int64 x)        { return (int32_t)x; }
static inline ae_int32x2 AE_ROUND32X2F64SSYM(ae_f64 a, ae_f64 b) { (void)b; return (ae_int32x2)a; }
static inline ae_f32x2  AE_MOVDA32(int32_t x)                    { return (ae_f32x2)x; }
static inline ae_f32x2  AE_MOVDA32X2(int32_t x, int32_t y)      { (void)y; return (ae_f32x2)x; }
static inline ae_int32  AE_SAT24S(ae_f32x2 x)                    { return (ae_int32)x; }
static inline ae_int16x4 AE_SAT16X4(ae_f32x2 a, ae_f32x2 b)     { (void)b; return (ae_int16x4)a; }
static inline ae_int16  AE_MOVAD16_0(ae_int16x4 x)               { return (ae_int16)x; }
static inline ae_f32x2  AE_SLAI32S(ae_f32x2 x, int s)            { return x << s; }
static inline ae_f32x2  AE_SRAI32(ae_f32x2 x, int s)             { return x >> s; }
static inline int32_t   AE_MOVAD32_L(ae_f32x2 x)                 { return (int32_t)x; }
static inline ae_f32x2  AE_F32X2_SLAIS(ae_f32x2 x, int s)        { return x << s; }
static inline ae_f32x2  AE_F32X2_SRAI(ae_f32x2 x, int s)         { return x >> s; }
typedef int64_t ae_p16x2s;
typedef int64_t ae_int24x2;
typedef int64_t ae_valign;
static inline ae_f32x2  AE_SRAI32R(ae_f32x2 x, int s)            { return x >> s; }
static inline ae_f32x2  AE_ADD24S(ae_f32x2 a, ae_f32x2 b)          { return a + b; }
static inline void      AE_S16X2M_I(ae_f32x2 a, void *p, int off) { (void)a; (void)p; (void)off; }
static inline ae_int32x2 AE_MUL32S_HH(ae_int32x2 a, ae_int32x2 b) { return a * b; }
static inline ae_int32x2 AE_MUL32S_LL(ae_int32x2 a, ae_int32x2 b) { return a * b; }
static inline void      AE_PKSR32(ae_int32x2 a, ae_int32x2 b, int s) { (void)a; (void)b; (void)s; }
static inline ae_int32x2 AE_SEL32_HH(ae_int32x2 a, ae_int32x2 b) { return a; }
static inline ae_int32x2 AE_SEL32_LL(ae_int32x2 a, ae_int32x2 b) { return b; }
static inline void      AE_SA32X2_IP(ae_int32x2 a, int b, void *p) { (void)a; (void)b; (void)p; }
static inline void      AE_MULSF32S_LL(ae_f32x2 a, ae_f32x2 b, ae_f32x2 c) { (void)a; (void)b; (void)c; }
static inline void      AE_MULAF32S_HL(ae_f32x2 a, ae_f32x2 b, ae_f32x2 c) { (void)a; (void)b; (void)c; }
static inline ae_int32x2 AE_NEG32S(ae_int32x2 a)                 { return -a; }
static inline ae_f32x2  AE_CVTP24A16X2_LL(int16_t a, int16_t b)   { (void)a; (void)b; return 0; }
static inline ae_f32x2  AE_MULFC24RA(ae_f32x2 a, ae_f32x2 b)      { return a * b; }
static inline ae_f32x2  AE_SUB24S(ae_f32x2 a, ae_f32x2 b)         { return a - b; }
static inline ae_valign AE_ZALIGN64(void)                        { return 0; }
static inline ae_int16x4 AE_NEG16S(ae_int16x4 a)                 { return -a; }
static inline ae_int16x4 AE_SRAA16RS(ae_int16x4 a, int len)       { (void)len; return a; }
static inline ae_valign AE_LA64_PP(void *p)                       { (void)p; return 0; }
static inline void      AE_LA16X4_IP(ae_int16x4 a, ae_valign v, void *p) { (void)a; (void)v; (void)p; }
static inline ae_int16x4 AE_SLAA16S(ae_int16x4 a, int len)       { (void)len; return a; }
static inline ae_int16x4 AE_SLAI16S(ae_int16x4 a, int s)         { return a << s; }
static inline ae_int16x4 AE_L16_I(void *p, int off)               { (void)p; (void)off; return 0; }
static inline void      AE_SA16X4_IP(ae_int16x4 a, ae_valign v, void *p) { (void)a; (void)v; (void)p; }
static inline void      AE_L16_IP(ae_int16x4 a, void *p, int off) { (void)a; (void)p; (void)off; }
static inline void      AE_S16_0_IP(ae_int16x4 a, void *p, int off) { (void)a; (void)p; (void)off; }
static inline ae_int32x2 AE_MUL32_HH(ae_int32x2 a, ae_int32x2 b) { return a * b; }
static inline ae_int32x2 AE_MUL32_LL(ae_int32x2 a, ae_int32x2 b) { return a * b; }
static inline ae_int32   AE_ROUND32F48SSYM(ae_f64 a)              { return (ae_int32)a; }
static inline void      AE_S32_L_I(ae_int32 a, void *p, int off)  { (void)a; (void)p; (void)off; }
static inline void      AE_S32_L_IP(ae_int32x2 a, void *p, int off) { (void)a; (void)p; (void)off; }
static inline void      AE_S32_L_X(ae_int32 a, void *p, int off)  { (void)a; (void)p; (void)off; }
static inline void      AE_S32_L_XC(ae_int32 a, void *p, int off) { (void)a; (void)p; (void)off; }
static inline void      AE_MULAFD32X16X2_FIR_HH(ae_f64 a, ae_f64 b, ae_f32x2 c, ae_f32x2 d, ae_f32x2 e) { (void)a; (void)b; (void)c; (void)d; (void)e; }
static inline void      AE_MULAFD32X16X2_FIR_HL(ae_f64 a, ae_f64 b, ae_f32x2 c, ae_f32x2 d, ae_f32x2 e) { (void)a; (void)b; (void)c; (void)d; (void)e; }
static inline ae_int16x4 AE_ROUND16X4F32SSYM(ae_f32x2 a, ae_f32x2 b) { (void)b; return (ae_int16x4)a; }
static inline ae_int32x2 AE_ADD32S(ae_int32x2 a, ae_int32x2 b)   { return a + b; }
static inline ae_int32x2 AE_SUB32S(ae_int32x2 a, ae_int32x2 b)   { return a - b; }
static inline ae_f32x2  AE_MULF32S_HH(ae_f32x2 a, ae_f32x2 b)     { return a * b; }
static inline ae_f32x2  AE_MULF32S_HL(ae_f32x2 a, ae_f32x2 b)     { return a * b; }
static inline ae_int32x2 AE_L32X2_I(void *p, int off)             { (void)p; (void)off; return 0; }
static inline void      AE_S32X2_I(ae_int32x2 a, void *p, int off) { (void)a; (void)p; (void)off; }
static inline ae_int32x2 AE_SEL32_HL(ae_int32x2 a, ae_int32x2 b) { return a; }
static inline void      AE_S32X2_IP(ae_int32x2 a, void *p, int off) { (void)a; (void)p; (void)off; }
static inline void      AE_L32X2_IP(ae_int32x2 a, void *p, int off) { (void)a; (void)p; (void)off; }
static inline ae_int32x2 AE_SLAA32S(ae_int32x2 a, int len)       { (void)len; return a; }
static inline ae_int32x2 AE_SRAA32S(ae_int32x2 a, int len)       { (void)len; return a; }
static inline void      AE_S32X2_X(ae_int32x2 a, void *p, int off) { (void)a; (void)p; (void)off; }
static inline ae_f32x2  AE_SEL32_LH(ae_f32x2 a, ae_f32x2 b)       { return a; }
static inline ae_f32x2  AE_MULFP32X2RS(ae_f32x2 a, ae_f32x2 b)    { return a * b; }
static inline void      AE_MULAF32S_HH(ae_f32x2 a, ae_f32x2 b, ae_f32x2 c) { (void)a; (void)b; (void)c; }
static inline ae_f64    AE_ZERO64(void)                            { return 0; }
static inline void      AE_L32X2_XC(ae_f32x2 a, void *p, int off) { (void)a; (void)p; (void)off; }
static inline void      AE_SETCBEGIN0(void *p)                    { (void)p; }
static inline void      AE_SETCEND0(void *p)                      { (void)p; }
static inline ae_f64    AE_ZEROQ56(void)                          { return 0; }
static inline void      AE_L32_XC(ae_f32 a, void *p, int off)     { (void)a; (void)p; (void)off; }
static inline void      AE_MULAF32R_HH(ae_f64 a, ae_f32x2 b, ae_f32 c) { (void)a; (void)b; (void)c; }
static inline void      AE_MULAF32R_LL(ae_f64 a, ae_f32x2 b, ae_f32 c) { (void)a; (void)b; (void)c; }
static inline ae_f64    AE_MULF32R_HH(ae_f32x2 a, ae_f32 b)       { (void)a; (void)b; return 0; }
static inline ae_f64    AE_SRAA64(ae_f64 a, int shift)            { (void)shift; return a; }
static inline ae_f32    AE_F32_ADDS_F32(ae_f32 a, ae_f32 b)       { return a + b; }
static inline void      AE_MULAAFD32RA_HH_LL(ae_f64 a, ae_f32x2 b, ae_f32x2 c) { (void)a; (void)b; (void)c; }
static inline ae_f64    AE_MULF32R_LL(ae_f32x2 a, ae_f32x2 b)     { (void)a; (void)b; return 0; }
static inline void      AE_L32_IP(ae_f32 a, void *p, int off)     { (void)a; (void)p; (void)off; }
static inline void      AE_L32_XP(ae_f32 a, void *p, int off)     { (void)a; (void)p; (void)off; }
static inline ae_f32    AE_L32_X(void *p, int off)                { (void)p; (void)off; return 0; }
static inline void      AE_MULAFP32X16X2RS_L(ae_f32x2 a, ae_f32x2 b, ae_int16x4 c) { (void)a; (void)b; (void)c; }
static inline void      AE_MULAFP32X16X2RS_H(ae_f32x2 a, ae_f32x2 b, ae_int16x4 c) { (void)a; (void)b; (void)c; }
static inline void      AE_S16_0_X(ae_int16x4 a, void *p, int off) { (void)a; (void)p; (void)off; }
static inline ae_int16x4 AE_ADD16S(ae_int16x4 a, int16_t b)       { return a + b; }
static inline void      AE_LA16X4_IC(ae_int16x4 a, ae_valign v, void *p) { (void)a; (void)v; (void)p; }
static inline ae_int16x4 AE_MULFP16X4S(ae_int16x4 a, ae_int16x4 b) { return a * b; }
static inline ae_int16x4 AE_SUB16S(ae_int16x4 a, int16_t b)       { return a - b; }
static inline ae_int16x4 AE_MOVAD16_2(ae_int16x4 x)               { return x; }
static inline ae_int16x4 AE_MOVAD16_1(ae_int16x4 x)               { return x; }
typedef unsigned char xtbool4;
static inline ae_int32x2 AE_SRAA32(ae_int32x2 a, int s)         { return a >> s; }
static inline void      AE_MUL16X4(ae_int32x2 a, ae_int32x2 b, ae_int16x4 c, ae_int16x4 d) { (void)a; (void)b; (void)c; (void)d; }
static inline ae_int16x4 AE_TRUNC16X4F32(ae_int32x2 a, ae_int32x2 b) { (void)b; return (ae_int16x4)a; }
static inline void      AE_LA16X4POS_PC(ae_valign v, void *p)     { (void)v; (void)p; }
static inline void      AE_SA16X4_IC(ae_int16x4 a, ae_valign v, void *p) { (void)a; (void)v; (void)p; }
static inline ae_int16x4 AE_MOVAD16_3(ae_int16x4 x)               { return x; }
static inline xtbool4   AE_EQ16(ae_int16x4 a, ae_int16x4 b)       { return a == b; }
static inline int       XT_ALL4(xtbool4 x)                         { return x; }
static inline void      AE_LA32X2POS_PC(ae_valign v, void *p)     { (void)v; (void)p; }
static inline void      AE_SA32X2_IC(ae_int32x2 a, ae_valign v, void *p) { (void)a; (void)v; (void)p; }
static inline void      AE_LA32X2_IC(ae_int32x2 a, ae_valign v, void *p) { (void)a; (void)v; (void)p; }
static inline ae_int32x2 AE_MULFP32X16X2RAS_L(ae_int32x2 a, ae_int16x4 b) { (void)b; return a; }
static inline ae_int32x2 AE_MULFP32X16X2RAS_H(ae_int32x2 a, ae_int16x4 b) { (void)b; return a; }
static inline int32_t   AE_MOVAD32_H(ae_int32x2 x)                 { return (int32_t)x; }
static inline ae_int16x4 AE_MOVF16X4_FROMINT64(int64_t x)         { return (ae_int16x4)x; }
static inline ae_int32x2 AE_ADD32(ae_int32x2 a, ae_int32x2 b)   { return a + b; }
static inline int       AE_NSAZ32_L(ae_int32x2 a)                 { (void)a; return 0; }
static inline ae_int32x2 AE_ABS32S(ae_int32x2 a)                 { return a; }
static inline ae_int32   AE_ROUND32F48SASYM(ae_f64 a)             { return (ae_int32)a; }
static inline ae_int32x2 AE_ADD32_HL_LH(ae_int32x2 a, ae_int32x2 b) { return a + b; }
static inline ae_int32x2 AE_SLAA32(ae_int32x2 a, int s)         { return a << s; }
static inline void      AE_L16_XP(ae_int16x4 a, void *p, int off) { (void)a; (void)p; (void)off; }
static inline ae_int32x2 AE_CVT32X2F16_32(ae_int16x4 a)         { return (ae_int32x2)a; }
static inline void      AE_S16_0_XC(ae_int16x4 a, void *p, int off) { (void)a; (void)p; (void)off; }
static inline void      AE_S16_0_XP(ae_int16x4 a, void *p, int off) { (void)a; (void)p; (void)off; }
static inline ae_f32x2  AE_MOVF24X2_FROMINT32X2(ae_int32x2 a)  { return a; }
static inline ae_int32   AE_L32_I(void *p, int off)                { (void)p; (void)off; return 0; }
static inline ae_f32x2  AE_SLAI24S(ae_f32x2 a, int s)             { return a << s; }
static inline int       AE_MIN_32_signed(int a, int b)            { return a < b ? a : b; }
static inline ae_f32x2  AE_MULFP24X2R(ae_f32x2 a, ae_f32x2 b)     { return a * b; }
static inline ae_f64    AE_SLAI64(ae_f64 a, int s)                 { return a << s; }
static inline ae_f64    AE_MULF32S_LH(ae_f32 a, ae_f32 b)        { (void)a; (void)b; return 0; }
static inline ae_f64    AE_MULF32S_LL(ae_f32 a, ae_f32 b)        { (void)a; (void)b; return 0; }
static inline void      AE_MULAF32S_LL(ae_f64 a, ae_f32 b, ae_f32 c) { (void)a; (void)b; (void)c; }
static inline ae_f64    AE_ZEROP48(void)                           { return 0; }
static inline void      AE_SP24X2F_X(ae_p24x2f a, void *p, int off) { (void)a; (void)p; (void)off; }
static inline ae_int16x4 AE_L16M_X(void *p, int off)               { (void)p; (void)off; return 0; }
static inline ae_int16x4 AE_L16X4_X(void *p, int off)              { (void)p; (void)off; return 0; }
static inline void      AE_L16X4_XP(ae_int16x4 a, void *p, int off) { (void)a; (void)p; (void)off; }
static inline ae_f64    AE_MULF16SS_00(ae_int16x4 a, ae_int16x4 b) { (void)a; (void)b; return 0; }
static inline void      AE_MULAF16SS_11(ae_f64 a, ae_int16x4 b, ae_int16x4 c) { (void)a; (void)b; (void)c; }
static inline void      AE_MULAF16SS_22(ae_f64 a, ae_int16x4 b, ae_int16x4 c) { (void)a; (void)b; (void)c; }
static inline void      AE_MULAF16SS_33(ae_f64 a, ae_int16x4 b, ae_int16x4 c) { (void)a; (void)b; (void)c; }
static inline ae_f24    AE_ZERO24(void)                           { return 0; }
static inline void      AE_LA24_IP(ae_f24 a, ae_valign v, void *p) { (void)a; (void)v; (void)p; }
static inline void      AE_LA24X2_IP(ae_f24x2 a, ae_valign v, void *p) { (void)a; (void)v; (void)p; }
static inline void      AE_S32X2_XC(ae_int32x2 a, void *p, int off) { (void)a; (void)p; (void)off; }
static inline void      AE_L32F24_XC(ae_f24 a, void *p, int off)  { (void)a; (void)p; (void)off; }
static inline void      AE_SA24_IP(ae_f24 a, ae_valign v, void *p) { (void)a; (void)v; (void)p; }
static inline void      AE_L32X2F24_XC(ae_f24x2 a, void *p, int off) { (void)a; (void)p; (void)off; }
static inline void      AE_SA24X2_IP(ae_f24x2 a, ae_valign v, void *p) { (void)a; (void)v; (void)p; }
static inline ae_int32x2 AE_MOVINT24X2_FROMF24X2(ae_f24x2 a)     { return a; }
static inline int32_t   AE_MOVINT32_FROMINT16(int16_t x)          { return (int32_t)x; }
static inline ae_f32    AE_ROUND32F64SSYM(ae_f64 a)               { return (ae_f32)a; }
static inline ae_f32x2  AE_MULFP32X16X2RS_H(ae_f32x2 a, ae_int16x4 b) { (void)b; return a; }
static inline ae_f32x2  AE_MULFP32X16X2RS_L(ae_f32x2 a, ae_int16x4 b) { (void)b; return a; }
static inline ae_f32x2  AE_ROUND32X2F48SSYM(ae_f64 a, ae_f64 b)   { (void)b; return (ae_f32x2)a; }
static inline ae_int16x4 AE_ZERO16(void)                         { return 0; }
static inline void      AE_MULAFP32X2RS(ae_f32x2 a, ae_f32x2 b, ae_f32 c) { (void)a; (void)b; (void)c; }
static inline ae_int32x2 AE_ZERO32(void)                          { return 0; }
static inline ae_int32x2 AE_MIN32(ae_int32x2 a, ae_int32x2 b)     { return a < b ? a : b; }
static inline ae_int32x2 AE_MAXABS32S(ae_int32x2 a, ae_int32x2 b) { (void)b; return a; }
static inline ae_f32x2  AE_SLAI32(ae_f32x2 a, int s)              { return a << s; }
static inline ae_f32x2  AE_ROUND24X2F48SSYM(ae_f64 a, ae_f64 b)   { (void)b; return (ae_f32x2)a; }
static inline void      AE_S32_L_XP(ae_f32 a, void *p, int off)   { (void)a; (void)p; (void)off; }
static inline ae_f64    AE_MULF32RA_HH(ae_f32 a, ae_f32 b)        { (void)a; (void)b; return 0; }
static inline void      AE_LA32X2_IP(ae_f32x2 a, ae_valign v, void *p) { (void)a; (void)v; (void)p; }
static inline void      AE_MULAAFD32X16_H3_L2(ae_f64 a, ae_f32x2 b, ae_f64 c) { (void)a; (void)b; (void)c; }
static inline void      AE_MULAAFD32X16_H1_L0(ae_f64 a, ae_f32x2 b, ae_f64 c) { (void)a; (void)b; (void)c; }
static inline ae_f64    AE_SLAA64S(ae_f64 a, int shift)            { (void)shift; return a; }
static inline void      AE_MULAF32S_LH(ae_f32x2 a, ae_f32x2 b, ae_f32x2 c) { (void)a; (void)b; (void)c; }
static inline ae_valign AE_LA64_INIT(void *p)                    { (void)p; return 0; }
static inline void      AE_SA64POS_FP(ae_valign a, void *p)       { (void)a; (void)p; }

#endif /* XT_HIFI3_H */
