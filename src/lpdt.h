#pragma once
#ifndef LPDT_H_
#define LPDT_H_
#include "lpdt_text.h"
#include <stdarg.h>
#include <stdnoreturn.h>

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
 * %lC - LPDT_COLOR_...
 * %lE - LPDT_EFFECT...
 *
 */
noreturn 
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


/*!
 * @brief Function prints colored text
 * @param[in] msg printabel text
 * @param[in] color color text 
 */
extern void lpdt_printcl(char const* msg,
    struct lpdt_color_fgbg_s * color);

/*!
 * @brief Function prints colored rgb text
 * @param[in] msg printabel text
 * @param[in] color color text
 */
extern void lpdt_printcl_rgb(char const* msg,
    struct lpdt_color_fgbg_rgb_s * color);

/*!
 * @brief Function prints text with effects
 * @param[in] msg printabel text
 * @param[in] effects text effects LPDT_EFFECT_...
 */
extern void lpdt_printef(char const* msg,
    enum lpdt_effects_code_e const effects);

extern void lpdt_printre(char const* msg,
    enum lpdt_reset_code_e const reset);

#define LPDT_PRINT_COLOR_(COLOR) _Generic((COLOR), \
    struct lpdt_color_fgbg_s * : lpdt_print_color_code_, \
    struct lpdt_color_fgbg_rgb_s * : lpdt_print_color_rgb_code_) \
    (COLOR)

#define LPDT_PRINT_TEXT_(MSG) \
  fputs(MSG, stdout)

#define LPDT_PRINT_END_CODE_ \
  fputs(lpdt_code_end(), stdout)

#define LPDT_PRINT_EFFECTS_CODE_(EFFECTS) \
  struct lpdt_buffer_effect_s * macro_buffer_effects = lpdt_make_buffer_effect(effects); \
  fputs(macro_buffer_effects->data, stdout); \
  free(macro_buffer_effects)

static inline void lpdt_verify_and_print_code_color_(enum lpdt_colors_code_e const color,
    enum lpdt_color_type_e const type);

static inline void lpdt_print_color_code_(struct lpdt_color_fgbg_s * color);

static inline void lpdt_print_color_rgb_code_(struct lpdt_color_fgbg_rgb_s * color);

static inline void lpdt_verify_and_print_code_color_rgb_(void * color,
    enum lpdt_color_type_e const type);

#endif /* LPDT_H_ */
