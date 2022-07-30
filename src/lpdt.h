#pragma once
#ifndef LPDT_H_
#define LPDT_H_
#include "lpdt_color.h"

/*!
|+------------------------------------------------------------------------+|*
 * @file
 * @brief library for printing dyed text
 * @authors notidman
 * @version 1.0
 * @date 26-07-22
 * @copyright MIT License

|+---------------------------------| LPDT |-------------------------------+|*
*/


/*!
 * The function to print text to the console with 
 * certain color without line break
 *
 * @param[in] MSG printable text
 * @param[in] SIZE_MSG message type size
 * @param[in] COLOR color struct with type,effects,color
 * @param[in] EFFECTS text effects
 */
#define lpdt_print(MSG, SIZE_TYPE_MSG, COLOR, EFFECTS) _Generic((COLOR),\
    struct lpdt_color_param_s* : lpdt_print_dyed_colors,\
    struct lpdt_color_param_rgb_s* : lpdt_print_dyed_rgb)\
    (MSG, SIZE_TYPE_MSG, COLOR, EFFECTS)

/*!
 * The function to print text to the console 
 * of a certain color with a line break
 *
 * @param[in] MSG printable text
 * @param[in] SIZE_MSG message type size
 * @param[in] COLOR color struct with type,effects,color
 * @param[in] EFFECTS text effects
 */
#define lpdt_println(MSG, SIZE_TYPE_MSG, COLOR, EFFECTS) _Generic((COLOR),\
    struct lpdt_color_param_s* : lpdt_print_dyedln_colors,\
    struct lpdt_color_param_rgb_s* : lpdt_print_dyedln_rgb)\
    (MSG, SIZE_TYPE_MSG, COLOR, EFFECTS)

/*!
 * The function to print text to the console with 
 * certain color without line break
 *
 * @param[in] msg printabel text
 * @param[in] size_type_msg message type size
 * @param[in] color color text
 * @param[in] effects text effects
 */
extern void lpdt_print_dyed_colors(void * msg,
    unsigned long long size_type_msg,
    struct lpdt_color_param_s const* color,
    enum lpdt_effects_e const effects); 

/*!
 * The function to print text to the console 
 * of a certain color with a line break
 *
 * @param[in] msg printabel text
 * @param[in] size_type_msg message type size
 * @param[in] color color text
 * @param[in] effects text effects
 */
extern void lpdt_print_dyedln_colors(void * msg,
    unsigned long long size_type_msg,
    struct lpdt_color_param_s const* color,
    enum lpdt_effects_e const effects); 

/*!
 * The function to print text to the console with
 * rgb colors without line break
 *
 * @param[in] msg printabel text
 * @param[in] size_type_msg message type size
 * @param[in] color color text
 * @param[in] effects text effects
 */
extern void lpdt_print_dyed_rgb(void * msg,
    unsigned long long size_type_msg,
    struct lpdt_color_param_rgb_s const* color,
    enum lpdt_effects_e const effects); 

/*!
 * The function to print text to the console with
 * rgb colors with a line break
 *
 * @param[in] msg printabel text
 * @param[in] size_type_msg message type size
 * @param[in] color color text
 * @param[in] effects text effects
 */
extern void lpdt_print_dyedln_rgb(void * msg,
    unsigned long long size_type_msg,
    struct lpdt_color_param_rgb_s const* color,
    enum lpdt_effects_e const effects); 

/**
 *
 *
 */
/* extern void colorstr(char *str, colors_t color, const char *msg); */

/* extern void get_colorstrch(char *str, colors_t color, const char ch); */

#endif /* LPDT_H_ */
