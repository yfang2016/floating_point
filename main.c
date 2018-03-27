/*
 * ============================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/10/2018 16:20:25 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Fang Yuan (yfang@nju.edu.cn)
 *   Organization:  nju
 *
 * ============================================================================
 */

#include <stdio.h>
#include "float.h"

/* 
* ===  FUNCTION  =============================================================
*         Name:  main
*  Description:  
* ============================================================================
*/
int main (int argc, char *argv[])
{
    Float x1, x2;
    Float x3;

    /* Format of Floating point is defined as:
     * exponent: 8bit, 2's complement
     * fraction, 24bit, true form
     */

    /* x1=-12.567 
       12.567 = 1100.1001000100100111 = 0.11001001000100100111*2^4
       -12.567 = 1.11001001000100100111*2^4
    */
    x1.exp = 4;
    x1.frac = 0b111001001000100100111000;

    /* x2 = 34.069
      34.069 = 100010.000100011010101 = 0.100010000100011010101*2^6
    */
    x2.exp = 6;
    x2.frac = 0b010001000010001101010100;

    x3 = add(x1, x2);
    printf("exp:%d, frac: %06X\n", x3.exp, x3.frac);

    x3 = sub(x1, x2);
    printf("exp:%d, frac: %06X\n", x3.exp, x3.frac);

    x3 = mul(x1, x2);
    printf("exp:%d, frac: %06X\n", x3.exp, x3.frac);
}
