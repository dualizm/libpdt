#include <stdlib.h>
#include <string.h>

#include "lpdt_codes.h"
#include "lpdt_text.h"

struct lpdt_color_fgbg_s* lpdt_make_color_fgbg_base(enum lpdt_colors_code_e const color_fg,
    enum lpdt_colors_code_e const color_bg)
{
  struct lpdt_color_fgbg_s * new_param = malloc(sizeof(*new_param));
  new_param->fg = color_fg;
  new_param->bg = color_bg;

  return new_param;
}

struct lpdt_color_fgbg_s* lpdt_make_color_fgbg_wrap(struct lpdt_make_color_fgbg_args args)
{
  enum lpdt_colors_code_e const color_fg = args.color_fg ? args.color_fg : LPDT_NOT_USE_THAT_COLOR_NONE;
  enum lpdt_colors_code_e const color_bg = args.color_bg ? args.color_bg : LPDT_NOT_USE_THAT_COLOR_NONE;
  return lpdt_make_color_fgbg_base(color_fg, color_bg);
}

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
