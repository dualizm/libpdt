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
  LPDT_BLACK           = 0x00,
  LPDT_BLUE            = 0x01,
  LPDT_GREEN           = 0x02,
  LPDT_CYAN            = 0x03,
  LPDT_RED             = 0x04,
  LPDT_MAGENTA         = 0x05,
  LPDT_YELLOW          = 0x06,
  LPDT_WHITE           = 0x07,
  LPDT_BRIGHT_BLACK    = 0x08,
  LPDT_BRIGHT_BLUE     = 0x09,
  LPDT_BRIGHT_GREEN    = 0x0A,
  LPDT_BRIGHT_CYAN     = 0x0B,
  LPDT_BRIGHT_RED      = 0x0C,
  LPDT_BRIGHT_MAGENTA  = 0x0D,
  LPDT_BRIGHT_YELLOW   = 0x0E,
  LPDT_BRIGHT_WHITE    = 0x0F,
  LPDT_STANDARD        = 0x10,
  LPDT_END             = 0xFF,
};

//! Text effect enumeration
enum lpdt_effects_e
{
  LPDT_BOLD        = 0x01,
  LPDT_FAINT       = 0x02,
  LPDT_ITALIC      = 0x04,
  LPDT_UNDERLINE   = 0x08,
  LPDT_BLINK       = 0x10,
  LPDT_RAPID_BLINK = 0x20,
  LPDT_INVERSE     = 0x40,
  LPDT_INVISIBLE   = 0x80,
  LPDT_OVERLINE    = 0x100,
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
struct lpdt_color_param_s
{
  enum lpdt_colors_e fg;
  enum lpdt_colors_e bg;
};

//! Rgb color param
struct lpdt_color_param_rgb_s
{
  struct lpdt_color_rgb_bg_s bg;
  struct lpdt_color_rgb_fg_s fg;
};

//! Buffer for effect seq char
#define LPDT_BUFFER_EFFECT_LEN 360
struct lpdt_buffer_effect_s
{
  char data[LPDT_BUFFER_EFFECT_LEN];
};

//! Buffer for code rgb
#define LPDT_BUFFER_CODE_RGB_LEN_ 20
struct lpdt_buffer_code_rgb_s
{
  char data[LPDT_BUFFER_CODE_RGB_LEN_];
};

//************************__TYPES__*******************************************

//************************__INIT_FUNCTIONS__**********************************

/*!
 *@brief init buffer for rgb code
 *@return pointer on buffer
 */
extern struct lpdt_buffer_code_rgb_s* lpdt_make_buffer_rgb_code(void);

/*!
 *@brief init buffer for effects
 *@param[in] effects effects to buffer
 *@return pointer on buffer
 */
extern struct lpdt_buffer_effect_s* lpdt_make_buffer_effect(enum lpdt_effects_e const effects);

/*!
 *@brief init new param for print
 *@param[in] color_fg foreground color text
 *@param[in] color_bg background color text
 */
extern struct lpdt_color_param_s* lpdt_make_color_param(enum lpdt_colors_e const color_fg,
    enum lpdt_colors_e const color_bg);
/*!
 *@brief init new param for print
 *@param[in] color_fg foreground rgb color text
 *@param[in] color_bg background rgb color text
 */
extern struct lpdt_color_param_rgb_s* lpdt_make_color_param_rgb(struct lpdt_color_rgb_fg_s const colorfg,
    struct lpdt_color_rgb_bg_s const color_bg);

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
extern void lpdt_code_rgb(struct lpdt_buffer_code_rgb_s * destination,
    unsigned char const r, unsigned char const g, unsigned char const b,
    enum lpdt_color_type_e const type);

//************************__FUNCTIONS__**************************************
#endif /* LPDT_COLOR_H_ */
