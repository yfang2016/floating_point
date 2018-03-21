/*
 * ============================================================================
 *
 *       Filename:  mul.c
 *
 *    Description:  Floating-point multiplication
 *
 *        Version:  1.0
 *        Created:  03/19/2018 09:32:39 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Fang Yuan (yfang@nju.edu.cn)
 *   Organization:  nju
 *
 * ============================================================================
 */

#include "float.h"

Float mul (Float a, Float b)
{
    unsigned int sign = (a.frac ^ b.frac) & 0x00800000;
    unsigned int frac_a = a.frac & 0x007FFF00;  /* MSB16 */
    unsigned int frac_b = b.frac & 0x007FFF00;
    unsigned int a8 = a.frac & 0xFF;            /* LSB8 */
    unsigned int b8 = b.frac & 0xFF;
    unsigned int prod;

    /* frac_a and frac_b are unsigned true form */
    frac_a >>= 8;          /* keep MSB16 */
    frac_b >>= 8;          /* sign bit in bit23 */

    prod = frac_a * frac_b;    /* 16bitx16bit=32bit */
    prod += ((frac_a * b8) + (frac_b * a8)) >> 8;
    /* ignore LSB8 x LSB8. error may ocurr. */

    frac_a = prod >> 7;          /* 0.1xxx * 0.1xxx = 00.1xxxxxx */
    a.exp += b.exp;
    a.frac = frac_a | sign;      /* set sign bit */
    return a;
}
