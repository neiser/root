/*===------------- avx512bwintrin.h - AVX512BW intrinsics ------------------===
 *
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 *===-----------------------------------------------------------------------===
 */
#ifndef __IMMINTRIN_H
#error "Never use <avx512bwintrin.h> directly; include <immintrin.h> instead."
#endif

#ifndef __AVX512BWINTRIN_H
#define __AVX512BWINTRIN_H

typedef unsigned int __mmask32;
typedef unsigned long long __mmask64;

/* Define the default attributes for the functions in this file. */
#define __DEFAULT_FN_ATTRS __attribute__((__always_inline__, __nodebug__, __target__("avx512bw")))

static  __inline __m512i __DEFAULT_FN_ATTRS
_mm512_setzero_qi(void) {
  return (__m512i)(__v64qi){ 0, 0, 0, 0, 0, 0, 0, 0,
                             0, 0, 0, 0, 0, 0, 0, 0,
                             0, 0, 0, 0, 0, 0, 0, 0,
                             0, 0, 0, 0, 0, 0, 0, 0,
                             0, 0, 0, 0, 0, 0, 0, 0,
                             0, 0, 0, 0, 0, 0, 0, 0,
                             0, 0, 0, 0, 0, 0, 0, 0,
                             0, 0, 0, 0, 0, 0, 0, 0 };
}

static  __inline __m512i __DEFAULT_FN_ATTRS
_mm512_setzero_hi(void) {
  return (__m512i)(__v32hi){ 0, 0, 0, 0, 0, 0, 0, 0,
                             0, 0, 0, 0, 0, 0, 0, 0,
                             0, 0, 0, 0, 0, 0, 0, 0,
                             0, 0, 0, 0, 0, 0, 0, 0 };
}

/* Integer compare */

static __inline__ __mmask64 __DEFAULT_FN_ATTRS
_mm512_cmpeq_epi8_mask(__m512i __a, __m512i __b) {
  return (__mmask64)__builtin_ia32_pcmpeqb512_mask((__v64qi)__a, (__v64qi)__b,
                                                   (__mmask64)-1);
}

static __inline__ __mmask64 __DEFAULT_FN_ATTRS
_mm512_mask_cmpeq_epi8_mask(__mmask64 __u, __m512i __a, __m512i __b) {
  return (__mmask64)__builtin_ia32_pcmpeqb512_mask((__v64qi)__a, (__v64qi)__b,
                                                   __u);
}

static __inline__ __mmask64 __DEFAULT_FN_ATTRS
_mm512_cmpeq_epu8_mask(__m512i __a, __m512i __b) {
  return (__mmask64)__builtin_ia32_ucmpb512_mask((__v64qi)__a, (__v64qi)__b, 0,
                                                 (__mmask64)-1);
}

static __inline__ __mmask64 __DEFAULT_FN_ATTRS
_mm512_mask_cmpeq_epu8_mask(__mmask64 __u, __m512i __a, __m512i __b) {
  return (__mmask64)__builtin_ia32_ucmpb512_mask((__v64qi)__a, (__v64qi)__b, 0,
                                                 __u);
}

static __inline__ __mmask32 __DEFAULT_FN_ATTRS
_mm512_cmpeq_epi16_mask(__m512i __a, __m512i __b) {
  return (__mmask32)__builtin_ia32_pcmpeqw512_mask((__v32hi)__a, (__v32hi)__b,
                                                   (__mmask32)-1);
}

static __inline__ __mmask32 __DEFAULT_FN_ATTRS
_mm512_mask_cmpeq_epi16_mask(__mmask32 __u, __m512i __a, __m512i __b) {
  return (__mmask32)__builtin_ia32_pcmpeqw512_mask((__v32hi)__a, (__v32hi)__b,
                                                   __u);
}

static __inline__ __mmask32 __DEFAULT_FN_ATTRS
_mm512_cmpeq_epu16_mask(__m512i __a, __m512i __b) {
  return (__mmask32)__builtin_ia32_ucmpw512_mask((__v32hi)__a, (__v32hi)__b, 0,
                                                 (__mmask32)-1);
}

static __inline__ __mmask32 __DEFAULT_FN_ATTRS
_mm512_mask_cmpeq_epu16_mask(__mmask32 __u, __m512i __a, __m512i __b) {
  return (__mmask32)__builtin_ia32_ucmpw512_mask((__v32hi)__a, (__v32hi)__b, 0,
                                                 __u);
}

static __inline__ __mmask64 __DEFAULT_FN_ATTRS
_mm512_cmpge_epi8_mask(__m512i __a, __m512i __b) {
  return (__mmask64)__builtin_ia32_cmpb512_mask((__v64qi)__a, (__v64qi)__b, 5,
                                                (__mmask64)-1);
}

static __inline__ __mmask64 __DEFAULT_FN_ATTRS
_mm512_mask_cmpge_epi8_mask(__mmask64 __u, __m512i __a, __m512i __b) {
  return (__mmask64)__builtin_ia32_cmpb512_mask((__v64qi)__a, (__v64qi)__b, 5,
                                                __u);
}

static __inline__ __mmask64 __DEFAULT_FN_ATTRS
_mm512_cmpge_epu8_mask(__m512i __a, __m512i __b) {
  return (__mmask64)__builtin_ia32_ucmpb512_mask((__v64qi)__a, (__v64qi)__b, 5,
                                                 (__mmask64)-1);
}

static __inline__ __mmask64 __DEFAULT_FN_ATTRS
_mm512_mask_cmpge_epu8_mask(__mmask64 __u, __m512i __a, __m512i __b) {
  return (__mmask64)__builtin_ia32_ucmpb512_mask((__v64qi)__a, (__v64qi)__b, 5,
                                                 __u);
}

static __inline__ __mmask32 __DEFAULT_FN_ATTRS
_mm512_cmpge_epi16_mask(__m512i __a, __m512i __b) {
  return (__mmask32)__builtin_ia32_cmpw512_mask((__v32hi)__a, (__v32hi)__b, 5,
                                                (__mmask32)-1);
}

static __inline__ __mmask32 __DEFAULT_FN_ATTRS
_mm512_mask_cmpge_epi16_mask(__mmask32 __u, __m512i __a, __m512i __b) {
  return (__mmask32)__builtin_ia32_cmpw512_mask((__v32hi)__a, (__v32hi)__b, 5,
                                                __u);
}

static __inline__ __mmask32 __DEFAULT_FN_ATTRS
_mm512_cmpge_epu16_mask(__m512i __a, __m512i __b) {
  return (__mmask32)__builtin_ia32_ucmpw512_mask((__v32hi)__a, (__v32hi)__b, 5,
                                                 (__mmask32)-1);
}

static __inline__ __mmask32 __DEFAULT_FN_ATTRS
_mm512_mask_cmpge_epu16_mask(__mmask32 __u, __m512i __a, __m512i __b) {
  return (__mmask32)__builtin_ia32_ucmpw512_mask((__v32hi)__a, (__v32hi)__b, 5,
                                                 __u);
}

static __inline__ __mmask64 __DEFAULT_FN_ATTRS
_mm512_cmpgt_epi8_mask(__m512i __a, __m512i __b) {
  return (__mmask64)__builtin_ia32_pcmpgtb512_mask((__v64qi)__a, (__v64qi)__b,
                                                   (__mmask64)-1);
}

static __inline__ __mmask64 __DEFAULT_FN_ATTRS
_mm512_mask_cmpgt_epi8_mask(__mmask64 __u, __m512i __a, __m512i __b) {
  return (__mmask64)__builtin_ia32_pcmpgtb512_mask((__v64qi)__a, (__v64qi)__b,
                                                   __u);
}

static __inline__ __mmask64 __DEFAULT_FN_ATTRS
_mm512_cmpgt_epu8_mask(__m512i __a, __m512i __b) {
  return (__mmask64)__builtin_ia32_ucmpb512_mask((__v64qi)__a, (__v64qi)__b, 6,
                                                 (__mmask64)-1);
}

static __inline__ __mmask64 __DEFAULT_FN_ATTRS
_mm512_mask_cmpgt_epu8_mask(__mmask64 __u, __m512i __a, __m512i __b) {
  return (__mmask64)__builtin_ia32_ucmpb512_mask((__v64qi)__a, (__v64qi)__b, 6,
                                                 __u);
}

static __inline__ __mmask32 __DEFAULT_FN_ATTRS
_mm512_cmpgt_epi16_mask(__m512i __a, __m512i __b) {
  return (__mmask32)__builtin_ia32_pcmpgtw512_mask((__v32hi)__a, (__v32hi)__b,
                                                   (__mmask32)-1);
}

static __inline__ __mmask32 __DEFAULT_FN_ATTRS
_mm512_mask_cmpgt_epi16_mask(__mmask32 __u, __m512i __a, __m512i __b) {
  return (__mmask32)__builtin_ia32_pcmpgtw512_mask((__v32hi)__a, (__v32hi)__b,
                                                   __u);
}

static __inline__ __mmask32 __DEFAULT_FN_ATTRS
_mm512_cmpgt_epu16_mask(__m512i __a, __m512i __b) {
  return (__mmask32)__builtin_ia32_ucmpw512_mask((__v32hi)__a, (__v32hi)__b, 6,
                                                 (__mmask32)-1);
}

static __inline__ __mmask32 __DEFAULT_FN_ATTRS
_mm512_mask_cmpgt_epu16_mask(__mmask32 __u, __m512i __a, __m512i __b) {
  return (__mmask32)__builtin_ia32_ucmpw512_mask((__v32hi)__a, (__v32hi)__b, 6,
                                                 __u);
}

static __inline__ __mmask64 __DEFAULT_FN_ATTRS
_mm512_cmple_epi8_mask(__m512i __a, __m512i __b) {
  return (__mmask64)__builtin_ia32_cmpb512_mask((__v64qi)__a, (__v64qi)__b, 2,
                                                (__mmask64)-1);
}

static __inline__ __mmask64 __DEFAULT_FN_ATTRS
_mm512_mask_cmple_epi8_mask(__mmask64 __u, __m512i __a, __m512i __b) {
  return (__mmask64)__builtin_ia32_cmpb512_mask((__v64qi)__a, (__v64qi)__b, 2,
                                                __u);
}

static __inline__ __mmask64 __DEFAULT_FN_ATTRS
_mm512_cmple_epu8_mask(__m512i __a, __m512i __b) {
  return (__mmask64)__builtin_ia32_ucmpb512_mask((__v64qi)__a, (__v64qi)__b, 2,
                                                 (__mmask64)-1);
}

static __inline__ __mmask64 __DEFAULT_FN_ATTRS
_mm512_mask_cmple_epu8_mask(__mmask64 __u, __m512i __a, __m512i __b) {
  return (__mmask64)__builtin_ia32_ucmpb512_mask((__v64qi)__a, (__v64qi)__b, 2,
                                                 __u);
}

static __inline__ __mmask32 __DEFAULT_FN_ATTRS
_mm512_cmple_epi16_mask(__m512i __a, __m512i __b) {
  return (__mmask32)__builtin_ia32_cmpw512_mask((__v32hi)__a, (__v32hi)__b, 2,
                                                (__mmask32)-1);
}

static __inline__ __mmask32 __DEFAULT_FN_ATTRS
_mm512_mask_cmple_epi16_mask(__mmask32 __u, __m512i __a, __m512i __b) {
  return (__mmask32)__builtin_ia32_cmpw512_mask((__v32hi)__a, (__v32hi)__b, 2,
                                                __u);
}

static __inline__ __mmask32 __DEFAULT_FN_ATTRS
_mm512_cmple_epu16_mask(__m512i __a, __m512i __b) {
  return (__mmask32)__builtin_ia32_ucmpw512_mask((__v32hi)__a, (__v32hi)__b, 2,
                                                 (__mmask32)-1);
}

static __inline__ __mmask32 __DEFAULT_FN_ATTRS
_mm512_mask_cmple_epu16_mask(__mmask32 __u, __m512i __a, __m512i __b) {
  return (__mmask32)__builtin_ia32_ucmpw512_mask((__v32hi)__a, (__v32hi)__b, 2,
                                                 __u);
}

static __inline__ __mmask64 __DEFAULT_FN_ATTRS
_mm512_cmplt_epi8_mask(__m512i __a, __m512i __b) {
  return (__mmask64)__builtin_ia32_cmpb512_mask((__v64qi)__a, (__v64qi)__b, 1,
                                                (__mmask64)-1);
}

static __inline__ __mmask64 __DEFAULT_FN_ATTRS
_mm512_mask_cmplt_epi8_mask(__mmask64 __u, __m512i __a, __m512i __b) {
  return (__mmask64)__builtin_ia32_cmpb512_mask((__v64qi)__a, (__v64qi)__b, 1,
                                                __u);
}

static __inline__ __mmask64 __DEFAULT_FN_ATTRS
_mm512_cmplt_epu8_mask(__m512i __a, __m512i __b) {
  return (__mmask64)__builtin_ia32_ucmpb512_mask((__v64qi)__a, (__v64qi)__b, 1,
                                                 (__mmask64)-1);
}

static __inline__ __mmask64 __DEFAULT_FN_ATTRS
_mm512_mask_cmplt_epu8_mask(__mmask64 __u, __m512i __a, __m512i __b) {
  return (__mmask64)__builtin_ia32_ucmpb512_mask((__v64qi)__a, (__v64qi)__b, 1,
                                                 __u);
}

static __inline__ __mmask32 __DEFAULT_FN_ATTRS
_mm512_cmplt_epi16_mask(__m512i __a, __m512i __b) {
  return (__mmask32)__builtin_ia32_cmpw512_mask((__v32hi)__a, (__v32hi)__b, 1,
                                                (__mmask32)-1);
}

static __inline__ __mmask32 __DEFAULT_FN_ATTRS
_mm512_mask_cmplt_epi16_mask(__mmask32 __u, __m512i __a, __m512i __b) {
  return (__mmask32)__builtin_ia32_cmpw512_mask((__v32hi)__a, (__v32hi)__b, 1,
                                                __u);
}

static __inline__ __mmask32 __DEFAULT_FN_ATTRS
_mm512_cmplt_epu16_mask(__m512i __a, __m512i __b) {
  return (__mmask32)__builtin_ia32_ucmpw512_mask((__v32hi)__a, (__v32hi)__b, 1,
                                                 (__mmask32)-1);
}

static __inline__ __mmask32 __DEFAULT_FN_ATTRS
_mm512_mask_cmplt_epu16_mask(__mmask32 __u, __m512i __a, __m512i __b) {
  return (__mmask32)__builtin_ia32_ucmpw512_mask((__v32hi)__a, (__v32hi)__b, 1,
                                                 __u);
}

static __inline__ __mmask64 __DEFAULT_FN_ATTRS
_mm512_cmpneq_epi8_mask(__m512i __a, __m512i __b) {
  return (__mmask64)__builtin_ia32_cmpb512_mask((__v64qi)__a, (__v64qi)__b, 4,
                                                (__mmask64)-1);
}

static __inline__ __mmask64 __DEFAULT_FN_ATTRS
_mm512_mask_cmpneq_epi8_mask(__mmask64 __u, __m512i __a, __m512i __b) {
  return (__mmask64)__builtin_ia32_cmpb512_mask((__v64qi)__a, (__v64qi)__b, 4,
                                                __u);
}

static __inline__ __mmask64 __DEFAULT_FN_ATTRS
_mm512_cmpneq_epu8_mask(__m512i __a, __m512i __b) {
  return (__mmask64)__builtin_ia32_ucmpb512_mask((__v64qi)__a, (__v64qi)__b, 4,
                                                 (__mmask64)-1);
}

static __inline__ __mmask64 __DEFAULT_FN_ATTRS
_mm512_mask_cmpneq_epu8_mask(__mmask64 __u, __m512i __a, __m512i __b) {
  return (__mmask64)__builtin_ia32_ucmpb512_mask((__v64qi)__a, (__v64qi)__b, 4,
                                                 __u);
}

static __inline__ __mmask32 __DEFAULT_FN_ATTRS
_mm512_cmpneq_epi16_mask(__m512i __a, __m512i __b) {
  return (__mmask32)__builtin_ia32_cmpw512_mask((__v32hi)__a, (__v32hi)__b, 4,
                                                (__mmask32)-1);
}

static __inline__ __mmask32 __DEFAULT_FN_ATTRS
_mm512_mask_cmpneq_epi16_mask(__mmask32 __u, __m512i __a, __m512i __b) {
  return (__mmask32)__builtin_ia32_cmpw512_mask((__v32hi)__a, (__v32hi)__b, 4,
                                                __u);
}

static __inline__ __mmask32 __DEFAULT_FN_ATTRS
_mm512_cmpneq_epu16_mask(__m512i __a, __m512i __b) {
  return (__mmask32)__builtin_ia32_ucmpw512_mask((__v32hi)__a, (__v32hi)__b, 4,
                                                 (__mmask32)-1);
}

static __inline__ __mmask32 __DEFAULT_FN_ATTRS
_mm512_mask_cmpneq_epu16_mask(__mmask32 __u, __m512i __a, __m512i __b) {
  return (__mmask32)__builtin_ia32_ucmpw512_mask((__v32hi)__a, (__v32hi)__b, 4,
                                                 __u);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_add_epi8 (__m512i __A, __m512i __B) {
  return (__m512i) ((__v64qu) __A + (__v64qu) __B);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_mask_add_epi8 (__m512i __W, __mmask64 __U, __m512i __A, __m512i __B) {
  return (__m512i) __builtin_ia32_paddb512_mask ((__v64qi) __A,
             (__v64qi) __B,
             (__v64qi) __W,
             (__mmask64) __U);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_maskz_add_epi8 (__mmask64 __U, __m512i __A, __m512i __B) {
  return (__m512i) __builtin_ia32_paddb512_mask ((__v64qi) __A,
             (__v64qi) __B,
             (__v64qi) _mm512_setzero_qi(),
             (__mmask64) __U);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_sub_epi8 (__m512i __A, __m512i __B) {
  return (__m512i) ((__v64qu) __A - (__v64qu) __B);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_mask_sub_epi8 (__m512i __W, __mmask64 __U, __m512i __A, __m512i __B) {
  return (__m512i) __builtin_ia32_psubb512_mask ((__v64qi) __A,
             (__v64qi) __B,
             (__v64qi) __W,
             (__mmask64) __U);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_maskz_sub_epi8 (__mmask64 __U, __m512i __A, __m512i __B) {
  return (__m512i) __builtin_ia32_psubb512_mask ((__v64qi) __A,
             (__v64qi) __B,
             (__v64qi) _mm512_setzero_qi(),
             (__mmask64) __U);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_add_epi16 (__m512i __A, __m512i __B) {
  return (__m512i) ((__v32hu) __A + (__v32hu) __B);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_mask_add_epi16 (__m512i __W, __mmask32 __U, __m512i __A, __m512i __B) {
  return (__m512i) __builtin_ia32_paddw512_mask ((__v32hi) __A,
             (__v32hi) __B,
             (__v32hi) __W,
             (__mmask32) __U);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_maskz_add_epi16 (__mmask32 __U, __m512i __A, __m512i __B) {
  return (__m512i) __builtin_ia32_paddw512_mask ((__v32hi) __A,
             (__v32hi) __B,
             (__v32hi) _mm512_setzero_hi(),
             (__mmask32) __U);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_sub_epi16 (__m512i __A, __m512i __B) {
  return (__m512i) ((__v32hu) __A - (__v32hu) __B);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_mask_sub_epi16 (__m512i __W, __mmask32 __U, __m512i __A, __m512i __B) {
  return (__m512i) __builtin_ia32_psubw512_mask ((__v32hi) __A,
             (__v32hi) __B,
             (__v32hi) __W,
             (__mmask32) __U);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_maskz_sub_epi16 (__mmask32 __U, __m512i __A, __m512i __B) {
  return (__m512i) __builtin_ia32_psubw512_mask ((__v32hi) __A,
             (__v32hi) __B,
             (__v32hi) _mm512_setzero_hi(),
             (__mmask32) __U);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_mullo_epi16 (__m512i __A, __m512i __B) {
  return (__m512i) ((__v32hu) __A * (__v32hu) __B);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_mask_mullo_epi16 (__m512i __W, __mmask32 __U, __m512i __A, __m512i __B) {
  return (__m512i) __builtin_ia32_pmullw512_mask ((__v32hi) __A,
              (__v32hi) __B,
              (__v32hi) __W,
              (__mmask32) __U);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_maskz_mullo_epi16 (__mmask32 __U, __m512i __A, __m512i __B) {
  return (__m512i) __builtin_ia32_pmullw512_mask ((__v32hi) __A,
              (__v32hi) __B,
              (__v32hi) _mm512_setzero_hi(),
              (__mmask32) __U);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_mask_blend_epi8 (__mmask64 __U, __m512i __A, __m512i __W)
{
  return (__m512i) __builtin_ia32_selectb_512 ((__mmask64) __U,
              (__v64qi) __W,
              (__v64qi) __A);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_mask_blend_epi16 (__mmask32 __U, __m512i __A, __m512i __W)
{
  return (__m512i) __builtin_ia32_selectw_512 ((__mmask32) __U,
              (__v32hi) __W,
              (__v32hi) __A);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_abs_epi8 (__m512i __A)
{
  return (__m512i) __builtin_ia32_pabsb512_mask ((__v64qi) __A,
              (__v64qi) _mm512_setzero_qi(),
              (__mmask64) -1);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_mask_abs_epi8 (__m512i __W, __mmask64 __U, __m512i __A)
{
  return (__m512i) __builtin_ia32_pabsb512_mask ((__v64qi) __A,
              (__v64qi) __W,
              (__mmask64) __U);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_maskz_abs_epi8 (__mmask64 __U, __m512i __A)
{
  return (__m512i) __builtin_ia32_pabsb512_mask ((__v64qi) __A,
              (__v64qi) _mm512_setzero_qi(),
              (__mmask64) __U);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_abs_epi16 (__m512i __A)
{
  return (__m512i) __builtin_ia32_pabsw512_mask ((__v32hi) __A,
              (__v32hi) _mm512_setzero_hi(),
              (__mmask32) -1);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_mask_abs_epi16 (__m512i __W, __mmask32 __U, __m512i __A)
{
  return (__m512i) __builtin_ia32_pabsw512_mask ((__v32hi) __A,
              (__v32hi) __W,
              (__mmask32) __U);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_maskz_abs_epi16 (__mmask32 __U, __m512i __A)
{
  return (__m512i) __builtin_ia32_pabsw512_mask ((__v32hi) __A,
              (__v32hi) _mm512_setzero_hi(),
              (__mmask32) __U);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_packs_epi32 (__m512i __A, __m512i __B)
{
  return (__m512i) __builtin_ia32_packssdw512_mask ((__v16si) __A,
              (__v16si) __B,
              (__v32hi) _mm512_setzero_hi(),
              (__mmask32) -1);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_maskz_packs_epi32 (__mmask32 __M, __m512i __A, __m512i __B)
{
  return (__m512i) __builtin_ia32_packssdw512_mask ((__v16si) __A,
              (__v16si) __B,
              (__v32hi) _mm512_setzero_hi(),
              __M);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_mask_packs_epi32 (__m512i __W, __mmask32 __M, __m512i __A,
       __m512i __B)
{
  return (__m512i) __builtin_ia32_packssdw512_mask ((__v16si) __A,
              (__v16si) __B,
              (__v32hi) __W,
              __M);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_packs_epi16 (__m512i __A, __m512i __B)
{
  return (__m512i) __builtin_ia32_packsswb512_mask ((__v32hi) __A,
              (__v32hi) __B,
              (__v64qi) _mm512_setzero_qi(),
              (__mmask64) -1);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_mask_packs_epi16 (__m512i __W, __mmask64 __M, __m512i __A,
       __m512i __B)
{
  return (__m512i) __builtin_ia32_packsswb512_mask ((__v32hi) __A,
              (__v32hi) __B,
              (__v64qi) __W,
              (__mmask64) __M);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_maskz_packs_epi16 (__mmask64 __M, __m512i __A, __m512i __B)
{
  return (__m512i) __builtin_ia32_packsswb512_mask ((__v32hi) __A,
              (__v32hi) __B,
              (__v64qi) _mm512_setzero_qi(),
              __M);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_packus_epi32 (__m512i __A, __m512i __B)
{
  return (__m512i) __builtin_ia32_packusdw512_mask ((__v16si) __A,
              (__v16si) __B,
              (__v32hi) _mm512_setzero_hi(),
              (__mmask32) -1);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_maskz_packus_epi32 (__mmask32 __M, __m512i __A, __m512i __B)
{
  return (__m512i) __builtin_ia32_packusdw512_mask ((__v16si) __A,
              (__v16si) __B,
              (__v32hi) _mm512_setzero_hi(),
              __M);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_mask_packus_epi32 (__m512i __W, __mmask32 __M, __m512i __A,
        __m512i __B)
{
  return (__m512i) __builtin_ia32_packusdw512_mask ((__v16si) __A,
              (__v16si) __B,
              (__v32hi) __W,
              __M);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_packus_epi16 (__m512i __A, __m512i __B)
{
  return (__m512i) __builtin_ia32_packuswb512_mask ((__v32hi) __A,
              (__v32hi) __B,
              (__v64qi) _mm512_setzero_qi(),
              (__mmask64) -1);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_mask_packus_epi16 (__m512i __W, __mmask64 __M, __m512i __A,
        __m512i __B)
{
  return (__m512i) __builtin_ia32_packuswb512_mask ((__v32hi) __A,
              (__v32hi) __B,
              (__v64qi) __W,
              (__mmask64) __M);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_maskz_packus_epi16 (__mmask64 __M, __m512i __A, __m512i __B)
{
  return (__m512i) __builtin_ia32_packuswb512_mask ((__v32hi) __A,
              (__v32hi) __B,
              (__v64qi) _mm512_setzero_qi(),
              (__mmask64) __M);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_adds_epi8 (__m512i __A, __m512i __B)
{
  return (__m512i) __builtin_ia32_paddsb512_mask ((__v64qi) __A,
              (__v64qi) __B,
              (__v64qi) _mm512_setzero_qi(),
              (__mmask64) -1);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_mask_adds_epi8 (__m512i __W, __mmask64 __U, __m512i __A,
           __m512i __B)
{
  return (__m512i) __builtin_ia32_paddsb512_mask ((__v64qi) __A,
              (__v64qi) __B,
              (__v64qi) __W,
              (__mmask64) __U);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_maskz_adds_epi8 (__mmask64 __U, __m512i __A, __m512i __B)
{
  return (__m512i) __builtin_ia32_paddsb512_mask ((__v64qi) __A,
              (__v64qi) __B,
              (__v64qi) _mm512_setzero_qi(),
              (__mmask64) __U);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_adds_epi16 (__m512i __A, __m512i __B)
{
  return (__m512i) __builtin_ia32_paddsw512_mask ((__v32hi) __A,
              (__v32hi) __B,
              (__v32hi) _mm512_setzero_hi(),
              (__mmask32) -1);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_mask_adds_epi16 (__m512i __W, __mmask32 __U, __m512i __A,
      __m512i __B)
{
  return (__m512i) __builtin_ia32_paddsw512_mask ((__v32hi) __A,
              (__v32hi) __B,
              (__v32hi) __W,
              (__mmask32) __U);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_maskz_adds_epi16 (__mmask32 __U, __m512i __A, __m512i __B)
{
  return (__m512i) __builtin_ia32_paddsw512_mask ((__v32hi) __A,
              (__v32hi) __B,
              (__v32hi) _mm512_setzero_hi(),
              (__mmask32) __U);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_adds_epu8 (__m512i __A, __m512i __B)
{
  return (__m512i) __builtin_ia32_paddusb512_mask ((__v64qi) __A,
              (__v64qi) __B,
              (__v64qi) _mm512_setzero_qi(),
              (__mmask64) -1);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_mask_adds_epu8 (__m512i __W, __mmask64 __U, __m512i __A,
           __m512i __B)
{
  return (__m512i) __builtin_ia32_paddusb512_mask ((__v64qi) __A,
              (__v64qi) __B,
              (__v64qi) __W,
              (__mmask64) __U);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_maskz_adds_epu8 (__mmask64 __U, __m512i __A, __m512i __B)
{
  return (__m512i) __builtin_ia32_paddusb512_mask ((__v64qi) __A,
              (__v64qi) __B,
              (__v64qi) _mm512_setzero_qi(),
              (__mmask64) __U);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_adds_epu16 (__m512i __A, __m512i __B)
{
  return (__m512i) __builtin_ia32_paddusw512_mask ((__v32hi) __A,
              (__v32hi) __B,
              (__v32hi) _mm512_setzero_hi(),
              (__mmask32) -1);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_mask_adds_epu16 (__m512i __W, __mmask32 __U, __m512i __A,
      __m512i __B)
{
  return (__m512i) __builtin_ia32_paddusw512_mask ((__v32hi) __A,
              (__v32hi) __B,
              (__v32hi) __W,
              (__mmask32) __U);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_maskz_adds_epu16 (__mmask32 __U, __m512i __A, __m512i __B)
{
  return (__m512i) __builtin_ia32_paddusw512_mask ((__v32hi) __A,
              (__v32hi) __B,
              (__v32hi) _mm512_setzero_hi(),
              (__mmask32) __U);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_avg_epu8 (__m512i __A, __m512i __B)
{
  return (__m512i) __builtin_ia32_pavgb512_mask ((__v64qi) __A,
              (__v64qi) __B,
              (__v64qi) _mm512_setzero_qi(),
              (__mmask64) -1);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_mask_avg_epu8 (__m512i __W, __mmask64 __U, __m512i __A,
          __m512i __B)
{
  return (__m512i) __builtin_ia32_pavgb512_mask ((__v64qi) __A,
              (__v64qi) __B,
              (__v64qi) __W,
              (__mmask64) __U);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_maskz_avg_epu8 (__mmask64 __U, __m512i __A, __m512i __B)
{
  return (__m512i) __builtin_ia32_pavgb512_mask ((__v64qi) __A,
              (__v64qi) __B,
              (__v64qi) _mm512_setzero_qi(),
              (__mmask64) __U);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_avg_epu16 (__m512i __A, __m512i __B)
{
  return (__m512i) __builtin_ia32_pavgw512_mask ((__v32hi) __A,
              (__v32hi) __B,
              (__v32hi) _mm512_setzero_hi(),
              (__mmask32) -1);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_mask_avg_epu16 (__m512i __W, __mmask32 __U, __m512i __A,
           __m512i __B)
{
  return (__m512i) __builtin_ia32_pavgw512_mask ((__v32hi) __A,
              (__v32hi) __B,
              (__v32hi) __W,
              (__mmask32) __U);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_maskz_avg_epu16 (__mmask32 __U, __m512i __A, __m512i __B)
{
  return (__m512i) __builtin_ia32_pavgw512_mask ((__v32hi) __A,
              (__v32hi) __B,
              (__v32hi) _mm512_setzero_hi(),
              (__mmask32) __U);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_max_epi8 (__m512i __A, __m512i __B)
{
  return (__m512i) __builtin_ia32_pmaxsb512_mask ((__v64qi) __A,
              (__v64qi) __B,
              (__v64qi) _mm512_setzero_qi(),
              (__mmask64) -1);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_maskz_max_epi8 (__mmask64 __M, __m512i __A, __m512i __B)
{
  return (__m512i) __builtin_ia32_pmaxsb512_mask ((__v64qi) __A,
              (__v64qi) __B,
              (__v64qi) _mm512_setzero_qi(),
              (__mmask64) __M);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_mask_max_epi8 (__m512i __W, __mmask64 __M, __m512i __A,
          __m512i __B)
{
  return (__m512i) __builtin_ia32_pmaxsb512_mask ((__v64qi) __A,
              (__v64qi) __B,
              (__v64qi) __W,
              (__mmask64) __M);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_max_epi16 (__m512i __A, __m512i __B)
{
  return (__m512i) __builtin_ia32_pmaxsw512_mask ((__v32hi) __A,
              (__v32hi) __B,
              (__v32hi) _mm512_setzero_hi(),
              (__mmask32) -1);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_maskz_max_epi16 (__mmask32 __M, __m512i __A, __m512i __B)
{
  return (__m512i) __builtin_ia32_pmaxsw512_mask ((__v32hi) __A,
              (__v32hi) __B,
              (__v32hi) _mm512_setzero_hi(),
              (__mmask32) __M);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_mask_max_epi16 (__m512i __W, __mmask32 __M, __m512i __A,
           __m512i __B)
{
  return (__m512i) __builtin_ia32_pmaxsw512_mask ((__v32hi) __A,
              (__v32hi) __B,
              (__v32hi) __W,
              (__mmask32) __M);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_max_epu8 (__m512i __A, __m512i __B)
{
  return (__m512i) __builtin_ia32_pmaxub512_mask ((__v64qi) __A,
              (__v64qi) __B,
              (__v64qi) _mm512_setzero_qi(),
              (__mmask64) -1);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_maskz_max_epu8 (__mmask64 __M, __m512i __A, __m512i __B)
{
  return (__m512i) __builtin_ia32_pmaxub512_mask ((__v64qi) __A,
              (__v64qi) __B,
              (__v64qi) _mm512_setzero_qi(),
              (__mmask64) __M);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_mask_max_epu8 (__m512i __W, __mmask64 __M, __m512i __A,
          __m512i __B)
{
  return (__m512i) __builtin_ia32_pmaxub512_mask ((__v64qi) __A,
              (__v64qi) __B,
              (__v64qi) __W,
              (__mmask64) __M);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_max_epu16 (__m512i __A, __m512i __B)
{
  return (__m512i) __builtin_ia32_pmaxuw512_mask ((__v32hi) __A,
              (__v32hi) __B,
              (__v32hi) _mm512_setzero_hi(),
              (__mmask32) -1);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_maskz_max_epu16 (__mmask32 __M, __m512i __A, __m512i __B)
{
  return (__m512i) __builtin_ia32_pmaxuw512_mask ((__v32hi) __A,
              (__v32hi) __B,
              (__v32hi) _mm512_setzero_hi(),
              (__mmask32) __M);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_mask_max_epu16 (__m512i __W, __mmask32 __M, __m512i __A,
           __m512i __B)
{
  return (__m512i) __builtin_ia32_pmaxuw512_mask ((__v32hi) __A,
              (__v32hi) __B,
              (__v32hi) __W,
              (__mmask32) __M);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_min_epi8 (__m512i __A, __m512i __B)
{
  return (__m512i) __builtin_ia32_pminsb512_mask ((__v64qi) __A,
              (__v64qi) __B,
              (__v64qi) _mm512_setzero_qi(),
              (__mmask64) -1);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_maskz_min_epi8 (__mmask64 __M, __m512i __A, __m512i __B)
{
  return (__m512i) __builtin_ia32_pminsb512_mask ((__v64qi) __A,
              (__v64qi) __B,
              (__v64qi) _mm512_setzero_qi(),
              (__mmask64) __M);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_mask_min_epi8 (__m512i __W, __mmask64 __M, __m512i __A,
          __m512i __B)
{
  return (__m512i) __builtin_ia32_pminsb512_mask ((__v64qi) __A,
              (__v64qi) __B,
              (__v64qi) __W,
              (__mmask64) __M);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_min_epi16 (__m512i __A, __m512i __B)
{
  return (__m512i) __builtin_ia32_pminsw512_mask ((__v32hi) __A,
              (__v32hi) __B,
              (__v32hi) _mm512_setzero_hi(),
              (__mmask32) -1);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_maskz_min_epi16 (__mmask32 __M, __m512i __A, __m512i __B)
{
  return (__m512i) __builtin_ia32_pminsw512_mask ((__v32hi) __A,
              (__v32hi) __B,
              (__v32hi) _mm512_setzero_hi(),
              (__mmask32) __M);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_mask_min_epi16 (__m512i __W, __mmask32 __M, __m512i __A,
           __m512i __B)
{
  return (__m512i) __builtin_ia32_pminsw512_mask ((__v32hi) __A,
              (__v32hi) __B,
              (__v32hi) __W,
              (__mmask32) __M);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_min_epu8 (__m512i __A, __m512i __B)
{
  return (__m512i) __builtin_ia32_pminub512_mask ((__v64qi) __A,
              (__v64qi) __B,
              (__v64qi) _mm512_setzero_qi(),
              (__mmask64) -1);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_maskz_min_epu8 (__mmask64 __M, __m512i __A, __m512i __B)
{
  return (__m512i) __builtin_ia32_pminub512_mask ((__v64qi) __A,
              (__v64qi) __B,
              (__v64qi) _mm512_setzero_qi(),
              (__mmask64) __M);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_mask_min_epu8 (__m512i __W, __mmask64 __M, __m512i __A,
          __m512i __B)
{
  return (__m512i) __builtin_ia32_pminub512_mask ((__v64qi) __A,
              (__v64qi) __B,
              (__v64qi) __W,
              (__mmask64) __M);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_min_epu16 (__m512i __A, __m512i __B)
{
  return (__m512i) __builtin_ia32_pminuw512_mask ((__v32hi) __A,
              (__v32hi) __B,
              (__v32hi) _mm512_setzero_hi(),
              (__mmask32) -1);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_maskz_min_epu16 (__mmask32 __M, __m512i __A, __m512i __B)
{
  return (__m512i) __builtin_ia32_pminuw512_mask ((__v32hi) __A,
              (__v32hi) __B,
              (__v32hi) _mm512_setzero_hi(),
              (__mmask32) __M);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_mask_min_epu16 (__m512i __W, __mmask32 __M, __m512i __A,
           __m512i __B)
{
  return (__m512i) __builtin_ia32_pminuw512_mask ((__v32hi) __A,
              (__v32hi) __B,
              (__v32hi) __W,
              (__mmask32) __M);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_shuffle_epi8 (__m512i __A, __m512i __B)
{
  return (__m512i) __builtin_ia32_pshufb512_mask ((__v64qi) __A,
              (__v64qi) __B,
              (__v64qi) _mm512_setzero_qi(),
              (__mmask64) -1);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_mask_shuffle_epi8 (__m512i __W, __mmask64 __U, __m512i __A,
        __m512i __B)
{
  return (__m512i) __builtin_ia32_pshufb512_mask ((__v64qi) __A,
              (__v64qi) __B,
              (__v64qi) __W,
              (__mmask64) __U);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_maskz_shuffle_epi8 (__mmask64 __U, __m512i __A, __m512i __B)
{
  return (__m512i) __builtin_ia32_pshufb512_mask ((__v64qi) __A,
              (__v64qi) __B,
              (__v64qi) _mm512_setzero_qi(),
              (__mmask64) __U);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_subs_epi8 (__m512i __A, __m512i __B)
{
  return (__m512i) __builtin_ia32_psubsb512_mask ((__v64qi) __A,
              (__v64qi) __B,
              (__v64qi) _mm512_setzero_qi(),
              (__mmask64) -1);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_mask_subs_epi8 (__m512i __W, __mmask64 __U, __m512i __A,
           __m512i __B)
{
  return (__m512i) __builtin_ia32_psubsb512_mask ((__v64qi) __A,
              (__v64qi) __B,
              (__v64qi) __W,
              (__mmask64) __U);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_maskz_subs_epi8 (__mmask64 __U, __m512i __A, __m512i __B)
{
  return (__m512i) __builtin_ia32_psubsb512_mask ((__v64qi) __A,
              (__v64qi) __B,
              (__v64qi) _mm512_setzero_qi(),
              (__mmask64) __U);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_subs_epi16 (__m512i __A, __m512i __B)
{
  return (__m512i) __builtin_ia32_psubsw512_mask ((__v32hi) __A,
              (__v32hi) __B,
              (__v32hi) _mm512_setzero_hi(),
              (__mmask32) -1);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_mask_subs_epi16 (__m512i __W, __mmask32 __U, __m512i __A,
      __m512i __B)
{
  return (__m512i) __builtin_ia32_psubsw512_mask ((__v32hi) __A,
              (__v32hi) __B,
              (__v32hi) __W,
              (__mmask32) __U);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_maskz_subs_epi16 (__mmask32 __U, __m512i __A, __m512i __B)
{
  return (__m512i) __builtin_ia32_psubsw512_mask ((__v32hi) __A,
              (__v32hi) __B,
              (__v32hi) _mm512_setzero_hi(),
              (__mmask32) __U);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_subs_epu8 (__m512i __A, __m512i __B)
{
  return (__m512i) __builtin_ia32_psubusb512_mask ((__v64qi) __A,
              (__v64qi) __B,
              (__v64qi) _mm512_setzero_qi(),
              (__mmask64) -1);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_mask_subs_epu8 (__m512i __W, __mmask64 __U, __m512i __A,
           __m512i __B)
{
  return (__m512i) __builtin_ia32_psubusb512_mask ((__v64qi) __A,
              (__v64qi) __B,
              (__v64qi) __W,
              (__mmask64) __U);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_maskz_subs_epu8 (__mmask64 __U, __m512i __A, __m512i __B)
{
  return (__m512i) __builtin_ia32_psubusb512_mask ((__v64qi) __A,
              (__v64qi) __B,
              (__v64qi) _mm512_setzero_qi(),
              (__mmask64) __U);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_subs_epu16 (__m512i __A, __m512i __B)
{
  return (__m512i) __builtin_ia32_psubusw512_mask ((__v32hi) __A,
              (__v32hi) __B,
              (__v32hi) _mm512_setzero_hi(),
              (__mmask32) -1);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_mask_subs_epu16 (__m512i __W, __mmask32 __U, __m512i __A,
      __m512i __B)
{
  return (__m512i) __builtin_ia32_psubusw512_mask ((__v32hi) __A,
              (__v32hi) __B,
              (__v32hi) __W,
              (__mmask32) __U);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_maskz_subs_epu16 (__mmask32 __U, __m512i __A, __m512i __B)
{
  return (__m512i) __builtin_ia32_psubusw512_mask ((__v32hi) __A,
              (__v32hi) __B,
              (__v32hi) _mm512_setzero_hi(),
              (__mmask32) __U);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_mask2_permutex2var_epi16 (__m512i __A, __m512i __I,
         __mmask32 __U, __m512i __B)
{
  return (__m512i) __builtin_ia32_vpermi2varhi512_mask ((__v32hi) __A,
              (__v32hi) __I /* idx */ ,
              (__v32hi) __B,
              (__mmask32) __U);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_permutex2var_epi16 (__m512i __A, __m512i __I, __m512i __B)
{
  return (__m512i) __builtin_ia32_vpermt2varhi512_mask ((__v32hi) __I /* idx */,
              (__v32hi) __A,
              (__v32hi) __B,
              (__mmask32) -1);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_mask_permutex2var_epi16 (__m512i __A, __mmask32 __U,
        __m512i __I, __m512i __B)
{
  return (__m512i) __builtin_ia32_vpermt2varhi512_mask ((__v32hi) __I /* idx */,
              (__v32hi) __A,
              (__v32hi) __B,
              (__mmask32) __U);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_maskz_permutex2var_epi16 (__mmask32 __U, __m512i __A,
         __m512i __I, __m512i __B)
{
  return (__m512i) __builtin_ia32_vpermt2varhi512_maskz ((__v32hi) __I
              /* idx */ ,
              (__v32hi) __A,
              (__v32hi) __B,
              (__mmask32) __U);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_mulhrs_epi16 (__m512i __A, __m512i __B)
{
  return (__m512i) __builtin_ia32_pmulhrsw512_mask ((__v32hi) __A,
                (__v32hi) __B,
                (__v32hi) _mm512_setzero_hi(),
                (__mmask32) -1);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_mask_mulhrs_epi16 (__m512i __W, __mmask32 __U, __m512i __A,
        __m512i __B)
{
  return (__m512i) __builtin_ia32_pmulhrsw512_mask ((__v32hi) __A,
                (__v32hi) __B,
                (__v32hi) __W,
                (__mmask32) __U);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_maskz_mulhrs_epi16 (__mmask32 __U, __m512i __A, __m512i __B)
{
  return (__m512i) __builtin_ia32_pmulhrsw512_mask ((__v32hi) __A,
                (__v32hi) __B,
                (__v32hi) _mm512_setzero_hi(),
                (__mmask32) __U);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_mulhi_epi16 (__m512i __A, __m512i __B)
{
  return (__m512i) __builtin_ia32_pmulhw512_mask ((__v32hi) __A,
              (__v32hi) __B,
              (__v32hi) _mm512_setzero_hi(),
              (__mmask32) -1);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_mask_mulhi_epi16 (__m512i __W, __mmask32 __U, __m512i __A,
       __m512i __B)
{
  return (__m512i) __builtin_ia32_pmulhw512_mask ((__v32hi) __A,
              (__v32hi) __B,
              (__v32hi) __W,
              (__mmask32) __U);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_maskz_mulhi_epi16 (__mmask32 __U, __m512i __A, __m512i __B)
{
  return (__m512i) __builtin_ia32_pmulhw512_mask ((__v32hi) __A,
              (__v32hi) __B,
              (__v32hi) _mm512_setzero_hi(),
              (__mmask32) __U);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_mulhi_epu16 (__m512i __A, __m512i __B)
{
  return (__m512i) __builtin_ia32_pmulhuw512_mask ((__v32hi) __A,
               (__v32hi) __B,
               (__v32hi) _mm512_setzero_hi(),
               (__mmask32) -1);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_mask_mulhi_epu16 (__m512i __W, __mmask32 __U, __m512i __A,
       __m512i __B)
{
  return (__m512i) __builtin_ia32_pmulhuw512_mask ((__v32hi) __A,
               (__v32hi) __B,
               (__v32hi) __W,
               (__mmask32) __U);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_maskz_mulhi_epu16 (__mmask32 __U, __m512i __A, __m512i __B)
{
  return (__m512i) __builtin_ia32_pmulhuw512_mask ((__v32hi) __A,
               (__v32hi) __B,
               (__v32hi) _mm512_setzero_hi(),
               (__mmask32) __U);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_maddubs_epi16 (__m512i __X, __m512i __Y) {
  return (__m512i) __builtin_ia32_pmaddubsw512_mask ((__v64qi) __X,
                 (__v64qi) __Y,
                 (__v32hi) _mm512_setzero_hi(),
                 (__mmask32) -1);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_mask_maddubs_epi16 (__m512i __W, __mmask32 __U, __m512i __X,
         __m512i __Y) {
  return (__m512i) __builtin_ia32_pmaddubsw512_mask ((__v64qi) __X,
                 (__v64qi) __Y,
                 (__v32hi) __W,
                 (__mmask32) __U);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_maskz_maddubs_epi16 (__mmask32 __U, __m512i __X, __m512i __Y) {
  return (__m512i) __builtin_ia32_pmaddubsw512_mask ((__v64qi) __X,
                 (__v64qi) __Y,
                 (__v32hi) _mm512_setzero_hi(),
                 (__mmask32) __U);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_madd_epi16 (__m512i __A, __m512i __B) {
  return (__m512i) __builtin_ia32_pmaddwd512_mask ((__v32hi) __A,
               (__v32hi) __B,
               (__v16si) _mm512_setzero_si512(),
               (__mmask16) -1);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_mask_madd_epi16 (__m512i __W, __mmask16 __U, __m512i __A,
      __m512i __B) {
  return (__m512i) __builtin_ia32_pmaddwd512_mask ((__v32hi) __A,
               (__v32hi) __B,
               (__v16si) __W,
               (__mmask16) __U);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_maskz_madd_epi16 (__mmask16 __U, __m512i __A, __m512i __B) {
  return (__m512i) __builtin_ia32_pmaddwd512_mask ((__v32hi) __A,
               (__v32hi) __B,
               (__v16si) _mm512_setzero_si512(),
               (__mmask16) __U);
}

static __inline__ __m256i __DEFAULT_FN_ATTRS
_mm512_cvtsepi16_epi8 (__m512i __A) {
  return (__m256i) __builtin_ia32_pmovswb512_mask ((__v32hi) __A,
               (__v32qi)_mm256_setzero_si256(),
               (__mmask32) -1);
}

static __inline__ __m256i __DEFAULT_FN_ATTRS
_mm512_mask_cvtsepi16_epi8 (__m256i __O, __mmask32 __M, __m512i __A) {
  return (__m256i) __builtin_ia32_pmovswb512_mask ((__v32hi) __A,
               (__v32qi)__O,
               __M);
}

static __inline__ __m256i __DEFAULT_FN_ATTRS
_mm512_maskz_cvtsepi16_epi8 (__mmask32 __M, __m512i __A) {
  return (__m256i) __builtin_ia32_pmovswb512_mask ((__v32hi) __A,
               (__v32qi) _mm256_setzero_si256(),
               __M);
}

static __inline__ __m256i __DEFAULT_FN_ATTRS
_mm512_cvtusepi16_epi8 (__m512i __A) {
  return (__m256i) __builtin_ia32_pmovuswb512_mask ((__v32hi) __A,
                (__v32qi) _mm256_setzero_si256(),
                (__mmask32) -1);
}

static __inline__ __m256i __DEFAULT_FN_ATTRS
_mm512_mask_cvtusepi16_epi8 (__m256i __O, __mmask32 __M, __m512i __A) {
  return (__m256i) __builtin_ia32_pmovuswb512_mask ((__v32hi) __A,
                (__v32qi) __O,
                __M);
}

static __inline__ __m256i __DEFAULT_FN_ATTRS
_mm512_maskz_cvtusepi16_epi8 (__mmask32 __M, __m512i __A) {
  return (__m256i) __builtin_ia32_pmovuswb512_mask ((__v32hi) __A,
                (__v32qi) _mm256_setzero_si256(),
                __M);
}

static __inline__ __m256i __DEFAULT_FN_ATTRS
_mm512_cvtepi16_epi8 (__m512i __A) {
  return (__m256i) __builtin_ia32_pmovwb512_mask ((__v32hi) __A,
              (__v32qi) _mm256_setzero_si256(),
              (__mmask32) -1);
}

static __inline__ __m256i __DEFAULT_FN_ATTRS
_mm512_mask_cvtepi16_epi8 (__m256i __O, __mmask32 __M, __m512i __A) {
  return (__m256i) __builtin_ia32_pmovwb512_mask ((__v32hi) __A,
              (__v32qi) __O,
              __M);
}

static __inline__ __m256i __DEFAULT_FN_ATTRS
_mm512_maskz_cvtepi16_epi8 (__mmask32 __M, __m512i __A) {
  return (__m256i) __builtin_ia32_pmovwb512_mask ((__v32hi) __A,
              (__v32qi) _mm256_setzero_si256(),
              __M);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_unpackhi_epi8 (__m512i __A, __m512i __B) {
  return (__m512i) __builtin_ia32_punpckhbw512_mask ((__v64qi) __A,
                 (__v64qi) __B,
                 (__v64qi) _mm512_setzero_qi(),
                 (__mmask64) -1);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_mask_unpackhi_epi8 (__m512i __W, __mmask64 __U, __m512i __A,
         __m512i __B) {
  return (__m512i) __builtin_ia32_punpckhbw512_mask ((__v64qi) __A,
                 (__v64qi) __B,
                 (__v64qi) __W,
                 (__mmask64) __U);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_maskz_unpackhi_epi8 (__mmask64 __U, __m512i __A, __m512i __B) {
  return (__m512i) __builtin_ia32_punpckhbw512_mask ((__v64qi) __A,
                 (__v64qi) __B,
                 (__v64qi) _mm512_setzero_qi(),
                 (__mmask64) __U);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_unpackhi_epi16 (__m512i __A, __m512i __B) {
  return (__m512i) __builtin_ia32_punpckhwd512_mask ((__v32hi) __A,
                 (__v32hi) __B,
                 (__v32hi) _mm512_setzero_hi(),
                 (__mmask32) -1);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_mask_unpackhi_epi16 (__m512i __W, __mmask32 __U, __m512i __A,
          __m512i __B) {
  return (__m512i) __builtin_ia32_punpckhwd512_mask ((__v32hi) __A,
                 (__v32hi) __B,
                 (__v32hi) __W,
                 (__mmask32) __U);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_maskz_unpackhi_epi16 (__mmask32 __U, __m512i __A, __m512i __B) {
  return (__m512i) __builtin_ia32_punpckhwd512_mask ((__v32hi) __A,
                 (__v32hi) __B,
                 (__v32hi) _mm512_setzero_hi(),
                 (__mmask32) __U);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_unpacklo_epi8 (__m512i __A, __m512i __B) {
  return (__m512i) __builtin_ia32_punpcklbw512_mask ((__v64qi) __A,
                 (__v64qi) __B,
                 (__v64qi) _mm512_setzero_qi(),
                 (__mmask64) -1);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_mask_unpacklo_epi8 (__m512i __W, __mmask64 __U, __m512i __A,
         __m512i __B) {
  return (__m512i) __builtin_ia32_punpcklbw512_mask ((__v64qi) __A,
                 (__v64qi) __B,
                 (__v64qi) __W,
                 (__mmask64) __U);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_maskz_unpacklo_epi8 (__mmask64 __U, __m512i __A, __m512i __B) {
  return (__m512i) __builtin_ia32_punpcklbw512_mask ((__v64qi) __A,
                 (__v64qi) __B,
                 (__v64qi) _mm512_setzero_qi(),
                 (__mmask64) __U);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_unpacklo_epi16 (__m512i __A, __m512i __B) {
  return (__m512i) __builtin_ia32_punpcklwd512_mask ((__v32hi) __A,
                 (__v32hi) __B,
                 (__v32hi) _mm512_setzero_hi(),
                 (__mmask32) -1);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_mask_unpacklo_epi16 (__m512i __W, __mmask32 __U, __m512i __A,
          __m512i __B) {
  return (__m512i) __builtin_ia32_punpcklwd512_mask ((__v32hi) __A,
                 (__v32hi) __B,
                 (__v32hi) __W,
                 (__mmask32) __U);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_maskz_unpacklo_epi16 (__mmask32 __U, __m512i __A, __m512i __B) {
  return (__m512i) __builtin_ia32_punpcklwd512_mask ((__v32hi) __A,
                 (__v32hi) __B,
                 (__v32hi) _mm512_setzero_hi(),
                 (__mmask32) __U);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_cvtepi8_epi16 (__m256i __A)
{
  return (__m512i) __builtin_ia32_pmovsxbw512_mask ((__v32qi) __A,
                (__v32hi)
                _mm512_setzero_hi (),
                (__mmask32) -1);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_mask_cvtepi8_epi16 (__m512i __W, __mmask32 __U, __m256i __A)
{
  return (__m512i) __builtin_ia32_pmovsxbw512_mask ((__v32qi) __A,
                (__v32hi) __W,
                (__mmask32) __U);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_maskz_cvtepi8_epi16 (__mmask32 __U, __m256i __A)
{
  return (__m512i) __builtin_ia32_pmovsxbw512_mask ((__v32qi) __A,
                (__v32hi)
                _mm512_setzero_hi(),
                (__mmask32) __U);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_cvtepu8_epi16 (__m256i __A)
{
  return (__m512i) __builtin_ia32_pmovzxbw512_mask ((__v32qi) __A,
                (__v32hi)
                _mm512_setzero_hi (),
                (__mmask32) -1);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_mask_cvtepu8_epi16 (__m512i __W, __mmask32 __U, __m256i __A)
{
  return (__m512i) __builtin_ia32_pmovzxbw512_mask ((__v32qi) __A,
                (__v32hi) __W,
                (__mmask32) __U);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_maskz_cvtepu8_epi16 (__mmask32 __U, __m256i __A)
{
  return (__m512i) __builtin_ia32_pmovzxbw512_mask ((__v32qi) __A,
                (__v32hi)
                _mm512_setzero_hi(),
                (__mmask32) __U);
}


#define _mm512_cmp_epi8_mask(a, b, p) __extension__ ({ \
  (__mmask64)__builtin_ia32_cmpb512_mask((__v64qi)(__m512i)(a), \
                                         (__v64qi)(__m512i)(b), (int)(p), \
                                         (__mmask64)-1); })

#define _mm512_mask_cmp_epi8_mask(m, a, b, p) __extension__ ({ \
  (__mmask64)__builtin_ia32_cmpb512_mask((__v64qi)(__m512i)(a), \
                                         (__v64qi)(__m512i)(b), (int)(p), \
                                         (__mmask64)(m)); })

#define _mm512_cmp_epu8_mask(a, b, p) __extension__ ({ \
  (__mmask64)__builtin_ia32_ucmpb512_mask((__v64qi)(__m512i)(a), \
                                          (__v64qi)(__m512i)(b), (int)(p), \
                                          (__mmask64)-1); })

#define _mm512_mask_cmp_epu8_mask(m, a, b, p) __extension__ ({ \
  (__mmask64)__builtin_ia32_ucmpb512_mask((__v64qi)(__m512i)(a), \
                                          (__v64qi)(__m512i)(b), (int)(p), \
                                          (__mmask64)(m)); })

#define _mm512_cmp_epi16_mask(a, b, p) __extension__ ({ \
  (__mmask32)__builtin_ia32_cmpw512_mask((__v32hi)(__m512i)(a), \
                                         (__v32hi)(__m512i)(b), (int)(p), \
                                         (__mmask32)-1); })

#define _mm512_mask_cmp_epi16_mask(m, a, b, p) __extension__ ({ \
  (__mmask32)__builtin_ia32_cmpw512_mask((__v32hi)(__m512i)(a), \
                                         (__v32hi)(__m512i)(b), (int)(p), \
                                         (__mmask32)(m)); })

#define _mm512_cmp_epu16_mask(a, b, p) __extension__ ({ \
  (__mmask32)__builtin_ia32_ucmpw512_mask((__v32hi)(__m512i)(a), \
                                          (__v32hi)(__m512i)(b), (int)(p), \
                                          (__mmask32)-1); })

#define _mm512_mask_cmp_epu16_mask(m, a, b, p) __extension__ ({ \
  (__mmask32)__builtin_ia32_ucmpw512_mask((__v32hi)(__m512i)(a), \
                                          (__v32hi)(__m512i)(b), (int)(p), \
                                          (__mmask32)(m)); })

#define _mm512_shufflehi_epi16(A, imm) __extension__ ({ \
  (__m512i)__builtin_ia32_pshufhw512_mask((__v32hi)(__m512i)(A), (int)(imm), \
                                          (__v32hi)_mm512_setzero_hi(), \
                                          (__mmask32)-1); })

#define _mm512_mask_shufflehi_epi16(W, U, A, imm) __extension__ ({ \
  (__m512i)__builtin_ia32_pshufhw512_mask((__v32hi)(__m512i)(A), (int)(imm), \
                                          (__v32hi)(__m512i)(W), \
                                          (__mmask32)(U)); })


#define _mm512_maskz_shufflehi_epi16(U, A, imm) __extension__ ({ \
  (__m512i)__builtin_ia32_pshufhw512_mask((__v32hi)(__m512i)(A), (int)(imm), \
                                          (__v32hi)_mm512_setzero_hi(), \
                                          (__mmask32)(U)); })

#define _mm512_shufflelo_epi16(A, imm) __extension__ ({ \
  (__m512i)__builtin_ia32_pshuflw512_mask((__v32hi)(__m512i)(A), (int)(imm), \
                                          (__v32hi)_mm512_setzero_hi(), \
                                          (__mmask32)-1); })


#define _mm512_mask_shufflelo_epi16(W, U, A, imm) __extension__ ({ \
  (__m512i)__builtin_ia32_pshuflw512_mask((__v32hi)(__m512i)(A), (int)(imm), \
                                          (__v32hi)(__m512i)(W), \
                                          (__mmask32)(U)); })


#define _mm512_maskz_shufflelo_epi16(U, A, imm) __extension__ ({ \
  (__m512i)__builtin_ia32_pshuflw512_mask((__v32hi)(__m512i)(A), (int)(imm), \
                                          (__v32hi)_mm512_setzero_hi(), \
                                          (__mmask32)(U)); })

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_sllv_epi16 (__m512i __A, __m512i __B)
{
  return (__m512i) __builtin_ia32_psllv32hi_mask ((__v32hi) __A,
              (__v32hi) __B,
              (__v32hi)
              _mm512_setzero_hi (),
              (__mmask32) -1);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_mask_sllv_epi16 (__m512i __W, __mmask32 __U, __m512i __A,
      __m512i __B)
{
  return (__m512i) __builtin_ia32_psllv32hi_mask ((__v32hi) __A,
              (__v32hi) __B,
              (__v32hi) __W,
              (__mmask32) __U);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_maskz_sllv_epi16 (__mmask32 __U, __m512i __A, __m512i __B)
{
  return (__m512i) __builtin_ia32_psllv32hi_mask ((__v32hi) __A,
              (__v32hi) __B,
              (__v32hi)
              _mm512_setzero_hi (),
              (__mmask32) __U);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_sll_epi16 (__m512i __A, __m128i __B)
{
  return (__m512i) __builtin_ia32_psllw512_mask ((__v32hi) __A,
             (__v8hi) __B,
             (__v32hi)
             _mm512_setzero_hi (),
             (__mmask32) -1);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_mask_sll_epi16 (__m512i __W, __mmask32 __U, __m512i __A,
           __m128i __B)
{
  return (__m512i) __builtin_ia32_psllw512_mask ((__v32hi) __A,
             (__v8hi) __B,
             (__v32hi) __W,
             (__mmask32) __U);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_maskz_sll_epi16 (__mmask32 __U, __m512i __A, __m128i __B)
{
  return (__m512i) __builtin_ia32_psllw512_mask ((__v32hi) __A,
             (__v8hi) __B,
             (__v32hi)
             _mm512_setzero_hi (),
             (__mmask32) __U);
}

#define _mm512_slli_epi16(A, B) __extension__ ({ \
  (__m512i)__builtin_ia32_psllwi512_mask((__v32hi)(__m512i)(A), (int)(B), \
                                         (__v32hi)_mm512_setzero_hi(), \
                                         (__mmask32)-1); })

#define _mm512_mask_slli_epi16(W, U, A, B) __extension__ ({ \
  (__m512i)__builtin_ia32_psllwi512_mask((__v32hi)(__m512i)(A), (int)(B), \
                                         (__v32hi)(__m512i)(W), \
                                         (__mmask32)(U)); })

#define _mm512_maskz_slli_epi16(U, A, B) __extension__ ({ \
  (__m512i)__builtin_ia32_psllwi512_mask((__v32hi)(__m512i)(A), (int)(B), \
                                         (__v32hi)_mm512_setzero_hi(), \
                                         (__mmask32)(U)); })


static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_srlv_epi16 (__m512i __A, __m512i __B)
{
  return (__m512i) __builtin_ia32_psrlv32hi_mask ((__v32hi) __A,
              (__v32hi) __B,
              (__v32hi)
              _mm512_setzero_hi (),
              (__mmask32) -1);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_mask_srlv_epi16 (__m512i __W, __mmask32 __U, __m512i __A,
      __m512i __B)
{
  return (__m512i) __builtin_ia32_psrlv32hi_mask ((__v32hi) __A,
              (__v32hi) __B,
              (__v32hi) __W,
              (__mmask32) __U);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_maskz_srlv_epi16 (__mmask32 __U, __m512i __A, __m512i __B)
{
  return (__m512i) __builtin_ia32_psrlv32hi_mask ((__v32hi) __A,
              (__v32hi) __B,
              (__v32hi)
              _mm512_setzero_hi (),
              (__mmask32) __U);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_srav_epi16 (__m512i __A, __m512i __B)
{
  return (__m512i) __builtin_ia32_psrav32hi_mask ((__v32hi) __A,
              (__v32hi) __B,
              (__v32hi)
              _mm512_setzero_hi (),
              (__mmask32) -1);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_mask_srav_epi16 (__m512i __W, __mmask32 __U, __m512i __A,
      __m512i __B)
{
  return (__m512i) __builtin_ia32_psrav32hi_mask ((__v32hi) __A,
              (__v32hi) __B,
              (__v32hi) __W,
              (__mmask32) __U);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_maskz_srav_epi16 (__mmask32 __U, __m512i __A, __m512i __B)
{
  return (__m512i) __builtin_ia32_psrav32hi_mask ((__v32hi) __A,
              (__v32hi) __B,
              (__v32hi)
              _mm512_setzero_hi (),
              (__mmask32) __U);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_sra_epi16 (__m512i __A, __m128i __B)
{
 return (__m512i) __builtin_ia32_psraw512_mask ((__v32hi) __A,
             (__v8hi) __B,
             (__v32hi)
             _mm512_setzero_hi (),
             (__mmask32) -1);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_mask_sra_epi16 (__m512i __W, __mmask32 __U, __m512i __A,
           __m128i __B)
{
  return (__m512i) __builtin_ia32_psraw512_mask ((__v32hi) __A,
             (__v8hi) __B,
             (__v32hi) __W,
            (__mmask32) __U);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_maskz_sra_epi16 (__mmask32 __U, __m512i __A, __m128i __B)
{
  return (__m512i) __builtin_ia32_psraw512_mask ((__v32hi) __A,
             (__v8hi) __B,
             (__v32hi)
             _mm512_setzero_hi (),
            (__mmask32) __U);
}

#define _mm512_srai_epi16(A, B) __extension__ ({ \
  (__m512i)__builtin_ia32_psrawi512_mask((__v32hi)(__m512i)(A), (int)(B), \
                                         (__v32hi)_mm512_setzero_hi(), \
                                         (__mmask32)-1); })

#define _mm512_mask_srai_epi16(W, U, A, B) __extension__ ({ \
  (__m512i)__builtin_ia32_psrawi512_mask((__v32hi)(__m512i)(A), (int)(B), \
                                         (__v32hi)(__m512i)(W), \
                                         (__mmask32)(U)); })

#define _mm512_maskz_srai_epi16(U, A, B) __extension__ ({ \
  (__m512i)__builtin_ia32_psrawi512_mask((__v32hi)(__m512i)(A), (int)(B), \
                                         (__v32hi)_mm512_setzero_hi(), \
                                         (__mmask32)(U)); })


static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_srl_epi16 (__m512i __A, __m128i __B)
{
  return (__m512i) __builtin_ia32_psrlw512_mask ((__v32hi) __A,
             (__v8hi) __B,
             (__v32hi)
             _mm512_setzero_hi (),
             (__mmask32) -1);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_mask_srl_epi16 (__m512i __W, __mmask32 __U, __m512i __A,
           __m128i __B)
{
  return (__m512i) __builtin_ia32_psrlw512_mask ((__v32hi) __A,
             (__v8hi) __B,
             (__v32hi) __W,
             (__mmask32) __U);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_maskz_srl_epi16 (__mmask32 __U, __m512i __A, __m128i __B)
{
  return (__m512i) __builtin_ia32_psrlw512_mask ((__v32hi) __A,
             (__v8hi) __B,
             (__v32hi)
             _mm512_setzero_hi (),
             (__mmask32) __U);
}

#define _mm512_srli_epi16(A, imm) __extension__ ({ \
  (__m512i)__builtin_ia32_psrlwi512_mask((__v32hi)(__m512i)(A), (int)(imm), \
                                         (__v32hi)_mm512_setzero_hi(), \
                                         (__mmask32)-1); })

#define _mm512_mask_srli_epi16(W, U, A, imm) __extension__ ({ \
  (__m512i)__builtin_ia32_psrlwi512_mask((__v32hi)(__m512i)(A), (int)(imm), \
                                         (__v32hi)(__m512i)(W), \
                                         (__mmask32)(U)); })

#define _mm512_maskz_srli_epi16(U, A, imm) __extension__ ({ \
  (__m512i)__builtin_ia32_psrlwi512_mask((__v32hi)(__m512i)(A), (int)(imm), \
                                         (__v32hi)_mm512_setzero_hi(), \
                                         (__mmask32)(U)); })



static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_mask_mov_epi16 (__m512i __W, __mmask32 __U, __m512i __A)
{
  return (__m512i) __builtin_ia32_selectw_512 ((__mmask32) __U,
                (__v32hi) __A,
                (__v32hi) __W);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_maskz_mov_epi16 (__mmask32 __U, __m512i __A)
{
  return (__m512i) __builtin_ia32_selectw_512 ((__mmask32) __U,
                (__v32hi) __A,
                (__v32hi) _mm512_setzero_hi ());
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_mask_mov_epi8 (__m512i __W, __mmask64 __U, __m512i __A)
{
  return (__m512i) __builtin_ia32_selectb_512 ((__mmask64) __U,
                (__v64qi) __A,
                (__v64qi) __W);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_maskz_mov_epi8 (__mmask64 __U, __m512i __A)
{
  return (__m512i) __builtin_ia32_selectb_512 ((__mmask64) __U,
                (__v64qi) __A,
                (__v64qi) _mm512_setzero_hi ());
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_mask_set1_epi8 (__m512i __O, __mmask64 __M, char __A)
{
  return (__m512i) __builtin_ia32_pbroadcastb512_gpr_mask (__A,
                 (__v64qi) __O,
                 __M);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_maskz_set1_epi8 (__mmask64 __M, char __A)
{
  return (__m512i) __builtin_ia32_pbroadcastb512_gpr_mask (__A,
                 (__v64qi)
                 _mm512_setzero_qi(),
                 __M);
}

static __inline__ __mmask64 __DEFAULT_FN_ATTRS
_mm512_kunpackd (__mmask64 __A, __mmask64 __B)
{
  return (__mmask64) __builtin_ia32_kunpckdi ((__mmask64) __A,
                (__mmask64) __B);
}

static __inline__ __mmask32 __DEFAULT_FN_ATTRS
_mm512_kunpackw (__mmask32 __A, __mmask32 __B)
{
  return (__mmask32) __builtin_ia32_kunpcksi ((__mmask32) __A,
                (__mmask32) __B);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_mask_loadu_epi16 (__m512i __W, __mmask32 __U, void const *__P)
{
  return (__m512i) __builtin_ia32_loaddquhi512_mask ((__v32hi *) __P,
                 (__v32hi) __W,
                 (__mmask32) __U);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_maskz_loadu_epi16 (__mmask32 __U, void const *__P)
{
  return (__m512i) __builtin_ia32_loaddquhi512_mask ((__v32hi *) __P,
                 (__v32hi)
                 _mm512_setzero_hi (),
                 (__mmask32) __U);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_mask_loadu_epi8 (__m512i __W, __mmask64 __U, void const *__P)
{
  return (__m512i) __builtin_ia32_loaddquqi512_mask ((__v64qi *) __P,
                 (__v64qi) __W,
                 (__mmask64) __U);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_maskz_loadu_epi8 (__mmask64 __U, void const *__P)
{
  return (__m512i) __builtin_ia32_loaddquqi512_mask ((__v64qi *) __P,
                 (__v64qi)
                 _mm512_setzero_hi (),
                 (__mmask64) __U);
}
static __inline__ void __DEFAULT_FN_ATTRS
_mm512_mask_storeu_epi16 (void *__P, __mmask32 __U, __m512i __A)
{
  __builtin_ia32_storedquhi512_mask ((__v32hi *) __P,
             (__v32hi) __A,
             (__mmask32) __U);
}

static __inline__ void __DEFAULT_FN_ATTRS
_mm512_mask_storeu_epi8 (void *__P, __mmask64 __U, __m512i __A)
{
  __builtin_ia32_storedquqi512_mask ((__v64qi *) __P,
             (__v64qi) __A,
             (__mmask64) __U);
}

static __inline__ __mmask64 __DEFAULT_FN_ATTRS
_mm512_test_epi8_mask (__m512i __A, __m512i __B)
{
  return (__mmask64) __builtin_ia32_ptestmb512 ((__v64qi) __A,
            (__v64qi) __B,
            (__mmask64) -1);
}

static __inline__ __mmask64 __DEFAULT_FN_ATTRS
_mm512_mask_test_epi8_mask (__mmask64 __U, __m512i __A, __m512i __B)
{
  return (__mmask64) __builtin_ia32_ptestmb512 ((__v64qi) __A,
            (__v64qi) __B, __U);
}

static __inline__ __mmask32 __DEFAULT_FN_ATTRS
_mm512_test_epi16_mask (__m512i __A, __m512i __B)
{
  return (__mmask32) __builtin_ia32_ptestmw512 ((__v32hi) __A,
            (__v32hi) __B,
            (__mmask32) -1);
}

static __inline__ __mmask32 __DEFAULT_FN_ATTRS
_mm512_mask_test_epi16_mask (__mmask32 __U, __m512i __A, __m512i __B)
{
  return (__mmask32) __builtin_ia32_ptestmw512 ((__v32hi) __A,
            (__v32hi) __B, __U);
}

static __inline__ __mmask64 __DEFAULT_FN_ATTRS
_mm512_testn_epi8_mask (__m512i __A, __m512i __B)
{
  return (__mmask64) __builtin_ia32_ptestnmb512 ((__v64qi) __A,
             (__v64qi) __B,
             (__mmask64) -1);
}

static __inline__ __mmask64 __DEFAULT_FN_ATTRS
_mm512_mask_testn_epi8_mask (__mmask64 __U, __m512i __A, __m512i __B)
{
  return (__mmask64) __builtin_ia32_ptestnmb512 ((__v64qi) __A,
             (__v64qi) __B, __U);
}

static __inline__ __mmask32 __DEFAULT_FN_ATTRS
_mm512_testn_epi16_mask (__m512i __A, __m512i __B)
{
  return (__mmask32) __builtin_ia32_ptestnmw512 ((__v32hi) __A,
             (__v32hi) __B,
             (__mmask32) -1);
}

static __inline__ __mmask32 __DEFAULT_FN_ATTRS
_mm512_mask_testn_epi16_mask (__mmask32 __U, __m512i __A, __m512i __B)
{
  return (__mmask32) __builtin_ia32_ptestnmw512 ((__v32hi) __A,
             (__v32hi) __B, __U);
}

static __inline__ __mmask64 __DEFAULT_FN_ATTRS
_mm512_movepi8_mask (__m512i __A)
{
  return (__mmask64) __builtin_ia32_cvtb2mask512 ((__v64qi) __A);
}

static __inline__ __mmask32 __DEFAULT_FN_ATTRS
_mm512_movepi16_mask (__m512i __A)
{
  return (__mmask32) __builtin_ia32_cvtw2mask512 ((__v32hi) __A);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_movm_epi8 (__mmask64 __A)
{
  return (__m512i) __builtin_ia32_cvtmask2b512 (__A);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_movm_epi16 (__mmask32 __A)
{
  return (__m512i) __builtin_ia32_cvtmask2w512 (__A);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_broadcastb_epi8 (__m128i __A)
{
  return (__m512i) __builtin_ia32_pbroadcastb512_mask ((__v16qi) __A,
                   (__v64qi) _mm512_setzero_si512(),
                   (__mmask64) -1);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_mask_broadcastb_epi8 (__m512i __O, __mmask64 __M, __m128i __A)
{
  return (__m512i) __builtin_ia32_pbroadcastb512_mask ((__v16qi) __A,
                   (__v64qi) __O,
                   __M);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_maskz_broadcastb_epi8 (__mmask64 __M, __m128i __A)
{
  return (__m512i) __builtin_ia32_pbroadcastb512_mask ((__v16qi) __A,
                   (__v64qi) _mm512_setzero_qi(),
                   __M);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_mask_set1_epi16 (__m512i __O, __mmask32 __M, short __A)
{
  return (__m512i) __builtin_ia32_pbroadcastw512_gpr_mask (__A,
                 (__v32hi) __O,
                 __M);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_maskz_set1_epi16 (__mmask32 __M, short __A)
{
  return (__m512i) __builtin_ia32_pbroadcastw512_gpr_mask (__A,
                 (__v32hi) _mm512_setzero_hi(),
                 __M);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_broadcastw_epi16 (__m128i __A)
{
  return (__m512i) __builtin_ia32_pbroadcastw512_mask ((__v8hi) __A,
                   (__v32hi) _mm512_setzero_si512(),
                   (__mmask32) -1);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_mask_broadcastw_epi16 (__m512i __O, __mmask32 __M, __m128i __A)
{
  return (__m512i) __builtin_ia32_pbroadcastw512_mask ((__v8hi) __A,
                   (__v32hi) __O,
                   __M);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_maskz_broadcastw_epi16 (__mmask32 __M, __m128i __A)
{
  return (__m512i) __builtin_ia32_pbroadcastw512_mask ((__v8hi) __A,
                   (__v32hi) _mm512_setzero_hi(),
                   __M);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_permutexvar_epi16 (__m512i __A, __m512i __B)
{
  return (__m512i) __builtin_ia32_permvarhi512_mask ((__v32hi) __B,
                 (__v32hi) __A,
                 (__v32hi) _mm512_undefined_epi32 (),
                 (__mmask32) -1);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_maskz_permutexvar_epi16 (__mmask32 __M, __m512i __A,
        __m512i __B)
{
  return (__m512i) __builtin_ia32_permvarhi512_mask ((__v32hi) __B,
                 (__v32hi) __A,
                 (__v32hi) _mm512_setzero_hi(),
                 (__mmask32) __M);
}

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_mask_permutexvar_epi16 (__m512i __W, __mmask32 __M, __m512i __A,
             __m512i __B)
{
  return (__m512i) __builtin_ia32_permvarhi512_mask ((__v32hi) __B,
                 (__v32hi) __A,
                 (__v32hi) __W,
                 (__mmask32) __M);
}

#define _mm512_alignr_epi8(A, B, N) __extension__ ({\
  (__m512i)__builtin_ia32_palignr512_mask((__v64qi)(__m512i)(A), \
                                          (__v64qi)(__m512i)(B), (int)(N), \
                                          (__v64qi)_mm512_undefined_pd(), \
                                          (__mmask64)-1); })

#define _mm512_mask_alignr_epi8(W, U, A, B, N) __extension__({\
  (__m512i)__builtin_ia32_palignr512_mask((__v64qi)(__m512i)(A), \
                                          (__v64qi)(__m512i)(B), (int)(N), \
                                          (__v64qi)(__m512i)(W), \
                                          (__mmask64)(U)); })

#define _mm512_maskz_alignr_epi8(U, A, B, N) __extension__({\
  (__m512i)__builtin_ia32_palignr512_mask((__v64qi)(__m512i)(A), \
                                          (__v64qi)(__m512i)(B), (int)(N), \
                                          (__v64qi)_mm512_setzero_si512(), \
                                          (__mmask64)(U)); })

#define _mm512_dbsad_epu8(A, B, imm) __extension__ ({\
  (__m512i)__builtin_ia32_dbpsadbw512_mask((__v64qi)(__m512i)(A), \
                                           (__v64qi)(__m512i)(B), (int)(imm), \
                                           (__v32hi)_mm512_undefined_epi32(), \
                                           (__mmask32)-1); })

#define _mm512_mask_dbsad_epu8(W, U, A, B, imm) ({\
  (__m512i)__builtin_ia32_dbpsadbw512_mask((__v64qi)(__m512i)(A), \
                                           (__v64qi)(__m512i)(B), (int)(imm), \
                                           (__v32hi)(__m512i)(W), \
                                           (__mmask32)(U)); })

#define _mm512_maskz_dbsad_epu8(U, A, B, imm) ({\
  (__m512i)__builtin_ia32_dbpsadbw512_mask((__v64qi)(__m512i)(A), \
                                           (__v64qi)(__m512i)(B), (int)(imm), \
                                           (__v32hi)_mm512_setzero_hi(), \
                                           (__mmask32)(U)); })

static __inline__ __m512i __DEFAULT_FN_ATTRS
_mm512_sad_epu8 (__m512i __A, __m512i __B)
{
 return (__m512i) __builtin_ia32_psadbw512 ((__v64qi) __A,
               (__v64qi) __B);
}



#undef __DEFAULT_FN_ATTRS

#endif
