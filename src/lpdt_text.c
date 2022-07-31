#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lpdt_text.h"

char const* lpdt_code_color(enum lpdt_colors_code_e const color,
    enum lpdt_color_type_e const type) 
{
  char const* code = NULL;
  if ( type == LPDT_FG)
  {
    switch(color)
    {
      case LPDT_COLOR_BLACK:          code = "\033[0;30m"  ; break;
      case LPDT_COLOR_RED:            code = "\033[0;31m"  ; break;
      case LPDT_COLOR_GREEN:          code = "\033[0;32m"  ; break;
      case LPDT_COLOR_YELLOW:         code = "\033[0;33m"  ; break;
      case LPDT_COLOR_BLUE:           code = "\033[0;34m"  ; break;
      case LPDT_COLOR_MAGENTA:        code = "\033[0;35m"  ; break;
      case LPDT_COLOR_CYAN:           code = "\033[0;36m"  ; break;
      case LPDT_COLOR_WHITE:          code = "\033[0;37m"  ; break;
      case LPDT_COLOR_DEFAULT:        code = "\033[0;39m"  ; break;
      case LPDT_COLOR_BRIGHT_BLACK:   code = "\033[0;90m"  ; break;
      case LPDT_COLOR_BRIGHT_RED:     code = "\033[0;91m"  ; break;
      case LPDT_COLOR_BRIGHT_GREEN:   code = "\033[0;92m"  ; break;
      case LPDT_COLOR_BRIGHT_YELLOW:  code = "\033[0;93m"  ; break;
      case LPDT_COLOR_BRIGHT_BLUE:    code = "\033[0;94m"  ; break;
      case LPDT_COLOR_BRIGHT_MAGENTA: code = "\033[0;95m"  ; break;
      case LPDT_COLOR_BRIGHT_CYAN:    code = "\033[0;96m"  ; break;
      case LPDT_COLOR_BRIGHT_WHITE:   code = "\033[0;97m"  ; break;
    }
  }
  else if ( type == LPDT_BG)
  {
    switch(color)
    {
      case LPDT_COLOR_BLACK:          code = "\033[0;40m"  ; break;
      case LPDT_COLOR_RED:            code = "\033[0;41m"  ; break;
      case LPDT_COLOR_GREEN:          code = "\033[0;42m"  ; break;
      case LPDT_COLOR_YELLOW:         code = "\033[0;43m"  ; break;
      case LPDT_COLOR_BLUE:           code = "\033[0;44m"  ; break;
      case LPDT_COLOR_MAGENTA:        code = "\033[0;45m"  ; break;
      case LPDT_COLOR_CYAN:           code = "\033[0;46m"  ; break;
      case LPDT_COLOR_WHITE:          code = "\033[0;47m"  ; break;
      case LPDT_COLOR_DEFAULT:        code = "\033[0;49m"  ; break;
      case LPDT_COLOR_BRIGHT_BLACK:   code = "\033[0;100m" ; break;
      case LPDT_COLOR_BRIGHT_RED:     code = "\033[0;101m" ; break;
      case LPDT_COLOR_BRIGHT_GREEN:   code = "\033[0;102m" ; break;
      case LPDT_COLOR_BRIGHT_YELLOW:  code = "\033[0;103m" ; break;
      case LPDT_COLOR_BRIGHT_BLUE:    code = "\033[0;104m" ; break;
      case LPDT_COLOR_BRIGHT_MAGENTA: code = "\033[0;105m" ; break;
      case LPDT_COLOR_BRIGHT_CYAN:    code = "\033[0;106m" ; break;
      case LPDT_COLOR_BRIGHT_WHITE:   code = "\033[0;107m" ; break;
    }
  }

  return code;
}

void lpdt_code_rgb(char destination[static MAX_BUFFER_CODE_RGB_],
    unsigned char const r, unsigned char const g, unsigned char const b,
    enum lpdt_color_type_e const type)
{
  if ( type == LPDT_FG)
  {
    snprintf(destination, MAX_BUFFER_CODE_RGB_,
        "\033[38;2;%d;%d;%dm", r, g, b);
  }
  else if ( type == LPDT_BG)
  {
    snprintf(destination, MAX_BUFFER_CODE_RGB_,
        "\033[48;2;%d;%d;%dm", r, g, b);
  }
}

char const* lpdt_code_effect(enum lpdt_effects_code_e const effect) 
{
  char const* code = NULL;
  switch (effect)
  {
    case LPDT_EFFECT_RESET:       code = "\033[0m"; break;
    case LPDT_EFFECT_BOLD:        code = "\033[1m"; break;
    case LPDT_EFFECT_FAINT:       code = "\033[2m"; break;
    case LPDT_EFFECT_ITALIC:      code = "\033[3m"; break;
    case LPDT_EFFECT_UNDERLINE:   code = "\033[4m"; break;
    case LPDT_EFFECT_BLINK:       code = "\033[5m"; break;
    case LPDT_EFFECT_RAPID_BLINK: code = "\033[5m"; break;
    case LPDT_EFFECT_INVERSE:     code = "\033[7m"; break;
    case LPDT_EFFECT_INVISIBLE:   code = "\033[8m"; break;
    case LPDT_EFFECT_OVERLINE:    code = "\033[9m"; break;
  }

  return code;
}

char const* lpdt_code_end(void)
{
  return "\033[0m";
}

extern char const* lpdt_code_reset(enum lpdt_reset_code_e const reset_code)
{
  char const* code_reset = NULL;
  switch(reset_code)
  {
    case LPDT_RESET_ATTRIB:   code_reset = "\033[22;23;24;25;27;28;29;54;55m" ; break;
    case LPDT_RESET_FG:       code_reset = "\033[39m"                         ; break;
    case LPDT_RESET_BG:       code_reset = "\033[49m"                         ; break;
    case LPDT_RESET_COLOR:    code_reset = "\033[0m"                          ; break;
    case LPDT_RESET_FONT:     code_reset = "\033[10m"                         ; break;
  }

  return code_reset;
}

/* extern struct lpdt_color_rgb_fg_s* init_color_rgb_fg(unsigned char const r, */
/*     unsigned char const g, unsigned cha const b) */
/* { */
/*   struct lpdt_color_rgb_fg_s * new_color = malloc(sizeof(*new_color)); */

/*   new_color->r = r; */
/*   new_color->g = g; */
/*   new_color->b = b; */

/*   return new_color; */
/* } */

/* extern struct lpdt_color_rgb_bg_s* init_color_rgb_bg(unsigned char const r, */
/*     unsigned char const g, unsigned char const b) */
/* { */
/*   struct lpdt_color_rgb_bg_s * new_color = malloc(sizeof(*new_color)); */

/*   new_color->r = r; */
/*   new_color->g = g; */
/*   new_color->b = b; */

/*   return new_color; */
/* } */

//---------------------------------------MAKE_COLOR_PARAM----------------------------------------------
struct lpdt_color_fgbg_s* lpdt_make_color_fgbg_base(enum lpdt_colors_code_e const* color_fg,
    enum lpdt_colors_code_e const* color_bg)
{
  struct lpdt_color_fgbg_s * new_param = malloc(sizeof(*new_param));
  if ( color_fg != NULL)
  {
    new_param->fg = malloc(sizeof(*(new_param->fg)));
    *new_param->fg = *color_fg;
  }
  else
  {
    new_param->fg = NULL;
  }

  if ( color_bg != NULL)
  {
    new_param->bg = malloc(sizeof(*(new_param->bg)));
    *new_param->bg = *color_bg;
  }
  else
  {
    new_param->bg = NULL;
  }

  return new_param;
}

struct lpdt_color_fgbg_s* lpdt_make_color_fgbg_wrap(struct lpdt_make_color_fgbg_args args)
{
  enum lpdt_colors_code_e const* color_fg = args.color_fg ? &args.color_fg : NULL;
  enum lpdt_colors_code_e const* color_bg = args.color_bg ? &args.color_bg : NULL;
  return lpdt_make_color_fgbg_base(color_fg, color_bg);
}
//---------------------------------------MAKE_COLOR_PARAM----------------------------------------------

//---------------------------------------MAKE_COLOR_PARAM_RGB------------------------------------------
struct lpdt_color_fgbg_rgb_s* lpdt_make_color_fgbg_rgb_base(struct lpdt_color_rgb_fg_s * color_fg,
    struct lpdt_color_rgb_bg_s * color_bg)
{
  struct lpdt_color_fgbg_rgb_s * new_param = malloc(sizeof(*new_param));
  if ( color_fg != NULL)
  {
    new_param->fg = color_fg;
  }
  else
  {
    new_param->fg = NULL;
  }

  if ( color_bg != NULL)
  {
    new_param->bg = color_bg;
  }
  else
  {
    new_param->bg = NULL;
  }
  
  return new_param;
}

struct lpdt_color_fgbg_rgb_s* lpdt_make_color_fgbg_rgb_wrap(struct lpdt_make_color_fgbg_rgb_args args)
{
  struct lpdt_color_rgb_fg_s * color_fg = args.color_fg ? args.color_fg : NULL;
  struct lpdt_color_rgb_bg_s * color_bg = args.color_bg ? args.color_bg : NULL;
  return lpdt_make_color_fgbg_rgb_base(color_fg, color_bg);
}

//---------------------------------------MAKE_COLOR_PARAM_RGB------------------------------------------

struct lpdt_buffer_effect_s* lpdt_make_buffer_effect(enum lpdt_effects_code_e const effects)
{
  struct lpdt_buffer_effect_s * new_buffer = malloc(sizeof(*new_buffer));
  memset(new_buffer->data, '\0', LPDT_BUFFER_EFFECT_LEN);

  for(size_t i = LPDT_EFFECT_BOLD; i < LPDT_EFFECT_OVERLINE; i <<= 1)
  {
    if ( effects & i)
      strcpy(new_buffer->data, lpdt_code_effect(i));
  }
  return new_buffer;
}


struct lpdt_color_rgb_bg_s* lpdt_make_color_bg(unsigned char r, unsigned char g, unsigned char b)
{
  struct lpdt_color_rgb_bg_s * bg = malloc(sizeof(*bg));
  bg->r = r;
  bg->g = g;
  bg->b = b;
  return bg;
}

struct lpdt_color_rgb_fg_s* lpdt_make_color_fg(unsigned char r, unsigned char g, unsigned char b)
{
  struct lpdt_color_rgb_fg_s * fg = malloc(sizeof(*fg));
  fg->r = r;
  fg->g = g;
  fg->b = b;
  return fg;
}
