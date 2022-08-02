#pragma once
#ifndef LPDT_CODES_H_
#define LPDT_CODES_H_
/*!
|+------------------------------------------------------------------------+|*
 * @file
 * @brief This file contains api for getting anci codes
 * @authors notidman
 * @version 1.0
 * @date 26-07-22
 * @copyright MIT License

|+---------------------------------| LPDT |-------------------------------+|*
*/

//! Color encoding enumeration
enum lpdt_colors_code_e
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
  LPDT_COLOR_DEFAULT         = 0xFF,
};

//! Text effect enumeration
enum lpdt_effects_code_e
{
  LPDT_EFFECT_RESET       = 0x00,
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

//! Reset codes enumeration
enum lpdt_reset_code_e
{
  LPDT_RESET_ATTRIB   = 0x01,
  LPDT_RESET_FG       = 0x02,
  LPDT_RESET_BG       = 0x03,
  LPDT_RESET_COLOR    = 0x04,
  LPDT_RESET_FONT     = 0x05,
};

//! Text type enumeration
enum lpdt_color_type_e
{
  LPDT_FG = 0x01,
  LPDT_BG = 0x02,
};

//! Buffer for code rgb
#define LPDT_MAX_BUFFER_CODE_RGB_ 20
struct lpdt_buffer_code_rgb_s
{
  char data[LPDT_MAX_BUFFER_CODE_RGB_];
};

/*!
 *@brief Allocates memory for buffer with rgb code
 *@return new buffer
 */
extern struct lpdt_buffer_code_rgb_s * lpdt_malloc_buffer_code_rgb(void);

/*!
 * @brief get control characters for desired effect.
 * @param[in] effect effect name
 * @return effect code
 */
extern char const* lpdt_code_effect(enum lpdt_effects_code_e const effect);

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
extern char const* lpdt_code_color(enum lpdt_colors_code_e const color,
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
extern void lpdt_code_rgb(struct lpdt_buffer_code_rgb_s *destination,
    unsigned char const r, unsigned char const g, unsigned char const b,
    enum lpdt_color_type_e const type);

/*!
 *@brief function returns reset code
 *@param[in] reset_code reset code name
 *@return reset code
 */
extern char const* lpdt_code_reset(enum lpdt_reset_code_e const reset_code);

#endif /* LPDT_CODES_H_ */

