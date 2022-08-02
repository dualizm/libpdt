#pragma once
#ifndef LPDT_H_
#define LPDT_H_
#include "lpdt_text.h"

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
 * The function produces output according to the format as described below.
 * %lc - LPDT_COLOR_...
 * %le - LPDT_EFFECT...
 * %lr - LPDT_RESET_...
 *
 */
extern int lpdt_printf(char const* restrict format, ...);

/*!
 * The function to print text to the console with 
 * certain color without line break
 *
 * @param[in] MSG printable text
 * @param[in] COLOR color struct with type,effects,color
 * @param[in] EFFECTS text effects
 */
#define lpdt_print(MSG, COLOR, EFFECTS) _Generic((COLOR),\
    struct lpdt_color_fgbg_s*     : lpdt_print_dyed_colors,\
    struct lpdt_color_fgbg_rgb_s* : lpdt_print_dyed_rgb)\
    (MSG, COLOR, EFFECTS)

/*!
 * The function to print text to the console 
 * of a certain color with a line break
 *
 * @param[in] MSG printable text
 * @param[in] COLOR color struct with type,effects,color
 * @param[in] EFFECTS text effects
 */
#define lpdt_println(MSG, COLOR, EFFECTS) _Generic((COLOR),\
    struct lpdt_color_fgbg_s*     : lpdt_print_dyedln_colors,\
    struct lpdt_color_fgbg_rgb_s* : lpdt_print_dyedln_rgb)\
    (MSG, COLOR, EFFECTS)

/*!
 * The function to print text to the console with 
 * certain color without line break
 *
 * @param[in] msg printabel text
 * @param[in] color color text
 * @param[in] effects text effects
 */
extern void lpdt_print_dyed_colors(char const* msg,
    struct lpdt_color_fgbg_s* color,
    enum lpdt_effects_code_e const effects); 

/*!
 * The function to print text to the console 
 * of a certain color with a line break
 *
 * @param[in] msg printabel text
 * @param[in] color color text
 * @param[in] effects text effects
 */
extern void lpdt_print_dyedln_colors(char const* msg,
    struct lpdt_color_fgbg_s * color,
    enum lpdt_effects_code_e const effects); 

/*!
 * The function to print text to the console with
 * rgb colors without line break
 *
 * @param[in] msg printabel text
 * @param[in] color color text
 * @param[in] effects text effects
 */
extern void lpdt_print_dyed_rgb(char const* msg,
    struct lpdt_color_fgbg_rgb_s * color,
    enum lpdt_effects_code_e const effects); 

/*!
 * The function to print text to the console with
 * rgb colors with a line break
 *
 * @param[in] msg printabel text
 * @param[in] color color text
 * @param[in] effects text effects
 */
extern void lpdt_print_dyedln_rgb(char const* msg,
    struct lpdt_color_fgbg_rgb_s * color,
    enum lpdt_effects_code_e const effects); 



#define LPDT_VERIFY_AND_PRINT_COLOR(PTR_COLOR, TYPE) \
  if ( PTR_COLOR != LPDT_NOT_USE_THAT_COLOR_NONE) \
  { \
    fputs(lpdt_code_color(PTR_COLOR, TYPE), stdout);\
  }

#define LPDT_VERIFY_AND_PRINT_COLOR_RGB(PTR_COLOR, TYPE) \
  if ( PTR_COLOR != NULL ) \
  { \
    struct lpdt_buffer_code_rgb_s * macro_buffer_rgb_code = lpdt_malloc_buffer_code_rgb(); \
    lpdt_code_rgb(macro_buffer_rgb_code, PTR_COLOR->r, PTR_COLOR->g, PTR_COLOR->b, TYPE); \
    fputs(macro_buffer_rgb_code->data, stdout); \
    free(macro_buffer_rgb_code); \
    free(PTR_COLOR); \
  }


/**
 *
 *
 */
/* extern void colorstr(char *str, colors_t color, const char *msg); */

/* extern void get_colorstrch(char *str, colors_t color, const char ch); */

#endif /* LPDT_H_ */
