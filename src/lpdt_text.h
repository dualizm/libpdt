#pragma once
#ifndef LPDT_TEXT_H_
#define LDPT_TEXT_H_
#include "lpdt_codes.h"

/*!
|+------------------------------------------------------------------------+|*
 * @file
 * @brief This file contains api for working with text
 * @authors notidman
 * @version 1.0
 * @date 26-07-22
 * @copyright MIT License

|+---------------------------------| LPDT |-------------------------------+|*
*/

//! RGB fg color for text
struct lpdt_color_rgb_fg_s
{
  unsigned char r, g, b;
};

//! RGB bg color for text
struct lpdt_color_rgb_bg_s
{
  unsigned char r, g, b;
};

//! Color param
struct lpdt_color_fgbg_s
{
  enum lpdt_colors_code_e fg;
  enum lpdt_colors_code_e bg;
};

//! Rgb color param
struct lpdt_color_fgbg_rgb_s
{
  struct lpdt_color_rgb_bg_s * bg;
  struct lpdt_color_rgb_fg_s * fg;
};

//! Buffer for effect seq char
#define LPDT_BUFFER_EFFECT_LEN 72
struct lpdt_buffer_effect_s
{
  char data[LPDT_BUFFER_EFFECT_LEN];
};

//! struct for wrap args
struct lpdt_make_color_fgbg_rgb_args
{
  struct lpdt_color_rgb_fg_s* color_fg;
  struct lpdt_color_rgb_bg_s* color_bg;
};

//! struct for wrap args
struct lpdt_make_color_fgbg_args
{
  enum lpdt_colors_code_e color_fg;
  enum lpdt_colors_code_e color_bg;
};

/*!
 *@brief init buffer for rgb code
 *@return pointer on buffer
 */
extern struct lpdt_buffer_code_rgb_s * lpdt_make_buffer_rgb_code(void);

/*!
 *@brief init buffer for effects
 *@param[in] effects effects to buffer
 *@return pointer on buffer
 */
extern struct lpdt_buffer_effect_s * lpdt_make_buffer_effect(enum lpdt_effects_code_e const effects);

/*!
 *@brief init new param for print
 *@param[in] color_fg foreground color text
 *@param[in] color_bg background color text
 */
extern struct lpdt_color_fgbg_s* lpdt_make_color_fgbg_base(enum lpdt_colors_code_e const color_fg,
    enum lpdt_colors_code_e const color_bg);

/*!
 *@brief function wrapper
 *@param[in] args args for function
 */
extern struct lpdt_color_fgbg_s* lpdt_make_color_fgbg_wrap(struct lpdt_make_color_fgbg_args args);

/*!
 *@brief init new param for print
 *@param[in] color_fg foreground color text
 *@param[in] color_bg background color text
 */
#define lpdt_color_fgbg(...) lpdt_make_color_fgbg_wrap((struct lpdt_make_color_fgbg_args){__VA_ARGS__})

/*!
 *@brief init new param for print
 *@param[in] color_fg foreground rgb color text
 *@param[in] color_bg background rgb color text
 */
extern struct lpdt_color_fgbg_rgb_s* lpdt_make_color_fgbg_rgb_base(struct lpdt_color_rgb_fg_s * color_fg,
    struct lpdt_color_rgb_bg_s * color_bg);

/*!
 *@brief function wrapper
 *@param[in] args args for function
 */
extern struct lpdt_color_fgbg_rgb_s* lpdt_make_color_fgbg_rgb_wrap(struct lpdt_make_color_fgbg_rgb_args args);

/*!
 *@brief init new param for print
 *@param[in] color_fg foreground rgb color text
 *@param[in] color_bg background rgb color text
 */
#define lpdt_color_fgbg_rgb(...) lpdt_make_color_fgbg_rgb_wrap((struct lpdt_make_color_fgbg_rgb_args){__VA_ARGS__})


/*!
 *@brief init new param for color [fg]
 *@param[in] r red color
 *@param[in] g green color
 *@param[in] b blue color
 */
extern struct lpdt_color_rgb_fg_s* lpdt_make_color_fg(unsigned char r, unsigned char g, unsigned char b); 

/*!
 *@brief init new param for color [bg]
 *@param[in] r red color
 *@param[in] g green color
 *@param[in] b blue color
 */
extern struct lpdt_color_rgb_bg_s* lpdt_make_color_bg(unsigned char r, unsigned char g, unsigned char b); 

/*!
 *@brief init new param for color [fg]
 *@param[in] r red color
 *@param[in] g green color
 *@param[in] b blue color
 */
#define lpdt_rgb_fg(r,g,b) .color_fg=lpdt_make_color_fg(r,g,b)

/*!
 *@brief init new param for color [bg]
 *@param[in] r red color
 *@param[in] g green color
 *@param[in] b blue color
 */
#define lpdt_rgb_bg(r,g,b) .color_bg=lpdt_make_color_bg(r,g,b)

/*!
 *@brief init new param for color [fg]
 *@param[in] color LPDT_COLOR_... color
 */
#define lpdt_bg(color) .color_fg=color

/*!
 *@brief init new param for color [bg]
 *@param[in] color LPDT_COLOR_... color
 */
#define lpdt_fg(color) .color_bg=color

/*
*!
 * @brief init new rgb color [fg]
 * @param[in] r red   color value
 * @param[in] g green color value
 * @param[in] b blue  color value
 *
extern struct lpdt_color_rgb_fg_s* lpdt_init_color_rgb_fg(unsigned char const r,
    unsigned char const g, unsigned char const b);

*!
 * @brief init new rgb color [bg]
 * @param[in] r red   color value
 * @param[in] g green color value
 * @param[in] b blue  color value
 *
extern struct lpdt_color_rgb_bg_s* lpdt_init_color_rgb_bg(unsigned char const r,
    unsigned char const g, unsigned char const b);
*/

#endif /* LPDT_TEXT_H_ */
