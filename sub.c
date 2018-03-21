/*
 * ============================================================================
 *
 *       Filename:  sub.c
 *
 *    Description:  Floating-point subtraction
 *
 *        Version:  1.0
 *        Created:  03/16/2018 13:52:00 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Fang Yuan (yfang@nju.edu.cn)
 *   Organization:  nju
 *
 * ============================================================================
 */

#include "float.h"

Float negate(Float x)   /* return negative of x */
{
    x.frac ^= 0x00800000;
    return x;
}

Float sub(Float a, Float b)
{
    b = negate(b);
    return add(a, b);
}
