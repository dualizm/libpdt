#pragma once
#ifndef LPDT_COLOR_H_
#define LDPT_COLOR_H_

/*!
|+------------------------------------------------------------------------+|*
 * @file
 * @brief The file contains information for obtaining a sequence of symbols of color, type, effect
 * @authors notidman
 * @version 1.0
 * @date 26-07-22
 * @copyright MIT License

|+---------------------------------| LPDT |-------------------------------+|*
*/


//************************__TYPES__*******************************************
//! Color encoding enumeration
enum lpdt_colors_e
{
  LPDT_COLOR_BLACK           = 0x00,
  LPDT_COLOR_BLUE            = 0x01,
  LPDT_COLOR_GREEN           = 0x02,
  LPDT_COLOR_CYAN            = 0x03,
  LPDT_COLOR_RED             = 0x04,
  LPDT_COLOR_MAGENTA         = 0x05,
  LPDT_COLOR_YELLOW          = 0x06,
  LPDT_COLOR_WHITE           = 0x07,
  LPDT_COLOR_BRIGHT_BLACK    = 0x08,
  LPDT_COLOR_BRIGHT_BLUE     = 0x09,
  LPDT_COLOR_BRIGHT_GREEN    = 0x0A,
  LPDT_COLOR_BRIGHT_CYAN     = 0x0B,
  LPDT_COLOR_BRIGHT_RED      = 0x0C,
  LPDT_COLOR_BRIGHT_MAGENTA  = 0x0D,
  LPDT_COLOR_BRIGHT_YELLOW   = 0x0E,
  LPDT_COLOR_BRIGHT_WHITE    = 0x0F,
  LPDT_COLOR_STANDARD        = 0x10,
};

//! Text effect enumeration
enum lpdt_effects_e
{
  LPDT_EFFECT_BOLD        = 0x01,
  LPDT_EFFECT_FAINT       = 0x02,
  LPDT_EFFECT_ITALIC      = 0x04,
  LPDT_EFFECT_UNDERLINE   = 0x08,
  LPDT_EFFECT_BLINK       = 0x10,
  LPDT_EFFECT_RAPID_BLINK = 0x20,
  LPDT_EFFECT_INVERSE     = 0x40,
  LPDT_EFFECT_INVISIBLE   = 0x80,
  LPDT_EFFECT_OVERLINE    = 0x100,
}; 

//! Text type enumeration
enum lpdt_color_type_e
{
  LPDT_FG = 0x01,
  LPDT_BG = 0x02,
};

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
  enum lpdt_colors_e * fg;
  enum lpdt_colors_e * bg;
};

//! Rgb color param
struct lpdt_color_fgbg_rgb_s
{
  struct lpdt_color_rgb_bg_s * bg;
  struct lpdt_color_rgb_fg_s * fg;
};

//! Buffer for effect seq char
#define LPDT_BUFFER_EFFECT_LEN 360
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
  enum lpdt_colors_e color_fg;
  enum lpdt_colors_e color_bg;
};

//************************__TYPES__*******************************************

//************************__INIT_FUNCTIONS__**********************************

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
extern struct lpdt_buffer_effect_s * lpdt_make_buffer_effect(enum lpdt_effects_e const effects);

/*!
 *@brief init new param for print
 *@param[in] color_fg foreground color text
 *@param[in] color_bg background color text
 */
extern struct lpdt_color_fgbg_s* lpdt_make_color_fgbg_base(enum lpdt_colors_e const* color_fg,
    enum lpdt_colors_e const* color_bg);

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

//************************__INIT_FUNCTIONS__**********************************

//************************__FUNCTIONS__***************************************
/*!
 * @brief get control characters for desired effect.
 * @param[in] effect effect name
 * @return effect code
 */
extern char const* lpdt_code_effect(enum lpdt_effects_e const effect);

/*!
 *@brief get end characters
 *@return end code
 */
extern char const* lpdt_code_end(void);

/*!
 * @brief get control characters for desired color.
 * @param[in] color color name
 * @param[in] type color type[fg,bg]
 * @return color code
 */
extern char const* lpdt_code_color(enum lpdt_colors_e const color,
    enum lpdt_color_type_e const type);

/*!
 * @brief get control characters for desired color.
 * @param[out] destination pointer to the target array into which the rgb sequence of characters will be copied.
 * @param[in] r red color code
 * @param[in] g green color code
 * @param[in] b blue color code
 * @param[in] type color type[fg,bg]
 * @return rgb color code
 */
#define MAX_BUFFER_CODE_RGB_ 20
extern void lpdt_code_rgb(char destination[static MAX_BUFFER_CODE_RGB_],
    unsigned char const r, unsigned char const g, unsigned char const b,
    enum lpdt_color_type_e const type);

//************************__FUNCTIONS__**************************************
#endif /* LPDT_COLOR_H_ */
