#pragma once
#ifndef LPDT_H_
#define LPDT_H_
#include "lpdt_color.h"

/*!|+-----------------------------------------------------------------------+|*\
 * \file                                                                    +|*
 * \brief library for printing dyed text                                    +|*
 * \authors notidman                                                        +|*
 * \version 1.0                                                             +|*
 * \date 26-07-22                                                           +|*
 * \copyright MIT License                                                   +|*
\*|+---------------------------------| LPDT |------------------------------+|*/


#define clrprint(MSG, COLOR) _Generic((COLOR),\
    struct lpdt_color_s* : print_dyed_name(MSG,COLOR),\
    struct lpdt_color_rgb_s* : print_dyed_rgb(MSG,COLOR))

#define clrprintln(MSG, COLOR) _Generic((COLOR),\
    struct lpdt_color_s* : print_dyedln_name(MSG,COLOR),\
    struct lpdt_color_rgb_s* : print_dyedln_rgb(MSG,COLOR))

/*!
 * The function to print text to the console with 
 * certain color without line break
 *
 * \param[in] msg text for print
 * \param[in] color color struct with type,effects,color
 */
extern void print_dyed_name(char const* msg,
    struct lpdt_color_s const* color); 

/*!
 * The function to print text to the console 
 * of a certain color with a line break
 *
 * \param[in] msg text for print
 * \param[in] color color struct with type,effects,color
 */
extern void print_dyedln_name(char const* msg,
    struct lpdt_color_s const* color); 

/*!
 * The function to print text to the console with
 * rgb colors without line break
 *
 * \param[in] msg text for print
 * \param[in] color color struct with type,effects,rgb
 */
extern void print_dyed_rgb(char const* msg,
    struct lpdt_color_rgb_s const* color); 

/*!
 * The function to print text to the console with
 * rgb colors with a line break
 *
 * \param[in] msg text for print
 * \param[in] color color struct with type,effects,rgb
 */
extern void print_dyedln_rgb(char const* msg,
    struct lpdt_color_rgb_s const* color); 

/**
 *
 *
 */
extern void colorstr(char *str, colors_t color, const char *msg);

/* extern void prcolorch(colors_t color, const char ch); */ 

/* extern void prcolorchln(colors_t color, const char ch); */ 

/* extern void get_colorstrch(char *str, colors_t color, const char ch); */

#endif /* LPDT_H_ */
