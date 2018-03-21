/*
 * ============================================================================
 *
 *       Filename:  add.c
 *
 *    Description:  Floating point addition
 *
 *        Version:  1.0
 *        Created:  03/10/2018 12:16:08 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Fang Yuan (yfang@nju.edu.cn)
 *   Organization:  nju
 *
 * ============================================================================
 */

#include "float.h"

int comp24(int x)    /* 24bit true form -> 2's complement */
{
    if (x & 0x00800000) {    /* if x is negative */
        x &= ~0x00800000;    /* clear sign bit */
        x = (~x) + 1;
    }
    return x;
}

Float add (Float a, Float b)
{
    int dexp = a.exp - b.exp;
    unsigned int sign;
    int frac_a = a.frac;
    int frac_b = b.frac;        /* 24bit->32bit, avoid overflow */

    frac_a = comp24(frac_a);
    frac_b = comp24(frac_b);

    if (dexp > 0) {             /* right shift the smaller one */
        frac_b >>= dexp;
    } else {
        a.exp = b.exp;
        frac_a >>= (-dexp);
    }
}
