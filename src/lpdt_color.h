#pragma once
#ifndef LPDT_COLOR_H_
#define LDPT_COLOR_H_

/*!|+-----------------------------------------------------------------------+|*\
 * \file                                                                    +|*
 * \brief The file contains information for obtaining a sequence of symbols +|*
 * of color, type, effect                                                   +|*
 * \authors notidman                                                        +|*
 * \version 1.0                                                             +|*
 * \date 26-07-22                                                           +|*
 * \copyright MIT License                                                   +|*
\*|+---------------------------------| LPDT |------------------------------+|*/

//! Color encoding enumeration
enum lpdt_colors_e
{
  black           = 0x00,
  blue            = 0x01,
  green           = 0x02,
  cyan            = 0x03,
  red             = 0x04,
  magenta         = 0x05,
  yellow          = 0x06,
  white           = 0x07,
  bright_black    = 0x08,
  bright_blue     = 0x09,
  bright_green    = 0x0A,
  bright_cyan     = 0x0B,
  bright_red      = 0x0C,
  bright_magenta  = 0x0D,
  bright_yellow   = 0x0E,
  bright_white    = 0x0F,
  standard        = 0x10,
  end             = 0xFF,
};

//! Text effect enumeration
enum lpdt_effect_e
{
  bold        = 0x01,
  faint       = 0x02,
  italic      = 0x04,
  underline   = 0x08,
  blink       = 0x10,
  rapid_blink = 0x20,
  inverse     = 0x40,
  invisible   = 0x80,
  overline    = 0x100,
}; 

//! Text type enumeration
enum lpdt_color_type_e
{
  fg = 0x01,
  bg = 0x02,
};

/* /// Effect type */
/* union lpdt_effect_u */
/* { */
/*   struct */ 
/*   { */
/*     unsigned char bold        : 1; */
/*     unsigned char faint       : 1; */
/*     unsigned char italic      : 1; */
/*     unsigned char underline   : 1; */
/*     unsigned char blink       : 1; */
/*     unsigned char rapid_blink : 1; */
/*     unsigned char inverse     : 1; */
/*     unsigned char invisible   : 1; */
/*     unsigned char overline    : 1; */
/*   } flags; */
/*   signed char effect; */
/* }; */

//! Color for text
struct lpdt_color_s
{
  enum lpdt_color_type_e type;
  enum lpdt_colors_e color;
};

//! RGB Color for text
struct lpdt_color_rgb_s
{
  enum lpdt_color_type_e type;
  char r, g, b;
};

/*!
 * \brief init new color
 * \param[in] type color type[fg,bg]
 * \param[in] color color name
 */
extern struct lpdt_color_s* init_color( enum lpdt_color_type_e const type,
    enum lpdt_colors_e const color);

/*!
 * \brief init new rgb color
 * \param[in] type color type[fg,bg]
 * \param[in] r red   color value
 * \param[in] g green color value
 * \param[in] b blue  color value
 */
extern struct lpdt_color_rgb_s* init_color_rgb(enum lpdt_color_type_e const type,
    char const r, char const g, char const b);

/*!
 * \brief get control characters for desired effect.
 * \param[in] effect effect name
 * \return effect code
 */
extern char const* code_effect(enum lpdt_effect_e const effect);

/*!
 * \brief get control characters for desired color.
 * \param[in] color color name
 * \param[in] type color type[fg,bg]
 * \return color code
 */
extern char const* code_color(enum lpdt_colors_e const color,
    enum lpdt_color_type_e const type);

/*!
 * \brief get control characters for desired color.
 * \param[out] destination pointer to the target array into which the rgb sequence of characters will be copied.
 * \param[in] r red color code
 * \param[in] g green color code
 * \param[in] b blue color code
 * \param[in] type color type[fg,bg]
 * \return rgb color code
 */
extern void code_rgb(char destination[17],
    char const r, char const g, char const b,
    enum lpdt_color_type_e const type);

#endif /* LPDT_COLOR_H_ */
