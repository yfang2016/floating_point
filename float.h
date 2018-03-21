/*
 * ============================================================================
 *
 *       Filename:  float.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/07/2018 06:56:01 PM
 *       Revision:  none
 *       Compiler: 
 *
 *         Author:  Fang Yuan (yfang@nju.edu.cn)
 *   Organization:  nju
 *
 * ============================================================================
 */

#ifndef _FLOAT_H
#define _FLOAT_H

typedef struct {
    unsigned int frac: 24;
    char exp: 8;
} Float;

Float add(Float, Float);
Float sub(Float, Float);
Float mul(Float, Float);

#endif
