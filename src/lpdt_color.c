#include "lpdt_color.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char const* lpdt_color_code(enum lpdt_colors_e const color,
    enum lpdt_color_type_e const type) 
{
  if ( type == LPDT_FG)
  {
    switch(color)
    {
      case LPDT_BLACK:          return "\033[0;30m"  ; break;
      case LPDT_RED:            return "\033[0;31m"  ; break;
      case LPDT_GREEN:          return "\033[0;32m"  ; break;
      case LPDT_YELLOW:         return "\033[0;33m"  ; break;
      case LPDT_BLUE:           return "\033[0;34m"  ; break;
      case LPDT_MAGENTA:        return "\033[0;35m"  ; break;
      case LPDT_CYAN:           return "\033[0;36m"  ; break;
      case LPDT_WHITE:          return "\033[0;37m"  ; break;
      case LPDT_STANDARD:       return "\033[0;39m"  ; break;
      case LPDT_BRIGHT_BLACK:   return "\033[0;90m"  ; break;
      case LPDT_BRIGHT_RED:     return "\033[0;91m"  ; break;
      case LPDT_BRIGHT_GREEN:   return "\033[0;92m"  ; break;
      case LPDT_BRIGHT_YELLOW:  return "\033[0;93m"  ; break;
      case LPDT_BRIGHT_BLUE:    return "\033[0;94m"  ; break;
      case LPDT_BRIGHT_MAGENTA: return "\033[0;95m"  ; break;
      case LPDT_BRIGHT_CYAN:    return "\033[0;96m"  ; break;
      case LPDT_BRIGHT_WHITE:   return "\033[0;97m"  ; break;
      case LPDT_END:            return "\033[0m"     ; break;
    }
  }
  else if ( type == LPDT_BG)
  {
    switch(color)
    {
      case LPDT_BLACK:          return "\033[0;40m"  ; break;
      case LPDT_RED:            return "\033[0;41m"  ; break;
      case LPDT_GREEN:          return "\033[0;42m"  ; break;
      case LPDT_YELLOW:         return "\033[0;43m"  ; break;
      case LPDT_BLUE:           return "\033[0;44m"  ; break;
      case LPDT_MAGENTA:        return "\033[0;45m"  ; break;
      case LPDT_CYAN:           return "\033[0;46m"  ; break;
      case LPDT_WHITE:          return "\033[0;47m"  ; break;
      case LPDT_STANDARD:       return "\033[0;49m"  ; break;
      case LPDT_BRIGHT_BLACK:   return "\033[0;100m" ; break;
      case LPDT_BRIGHT_RED:     return "\033[0;101m" ; break;
      case LPDT_BRIGHT_GREEN:   return "\033[0;102m" ; break;
      case LPDT_BRIGHT_YELLOW:  return "\033[0;103m" ; break;
      case LPDT_BRIGHT_BLUE:    return "\033[0;104m" ; break;
      case LPDT_BRIGHT_MAGENTA: return "\033[0;105m" ; break;
      case LPDT_BRIGHT_CYAN:    return "\033[0;106m" ; break;
      case LPDT_BRIGHT_WHITE:   return "\033[0;107m" ; break;
      case LPDT_END:            return "\033[0m"     ; break;
    }
  }
  else 
  {
    return "\033[0m";
  }
}

extern void lpdt_code_rgb(struct lpdt_buffer_code_rgb_s * destination,
    unsigned char const r, unsigned char const g, unsigned char const b,
    enum lpdt_color_type_e const type)
{
  if ( type == LPDT_FG)
  {
    snprintf(destination->data, LPDT_BUFFER_CODE_RGB_LEN_,
        "\033[38;2;%d;%d;%dm", r, g, b);
  }
  else if ( type == LPDT_BG)
  {
    snprintf(destination->data, LPDT_BUFFER_CODE_RGB_LEN_,
        "\033[48;2;%d;%d;%dm", r, g, b);
  }
}

extern char const* lpdt_code_effect(enum lpdt_effects_e const effect) 
{
  switch (effect)
  {
    case LPDT_BOLD:        return "\033[1m"; break;
    case LPDT_FAINT:       return "\033[2m"; break;
    case LPDT_ITALIC:      return "\033[3m"; break;
    case LPDT_UNDERLINE:   return "\033[4m"; break;
    case LPDT_BLINK:       return "\033[5m"; break;
    case LPDT_RAPID_BLINK: return "\033[5m"; break;
    case LPDT_INVERSE:     return "\033[7m"; break;
    case LPDT_INVISIBLE:   return "\033[8m"; break;
    case LPDT_OVERLINE:    return "\033[9m"; break;
    default:               return "error"  ; break;
  }
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

extern struct lpdt_color_param_s* lpdt_make_color_param(enum lpdt_colors_e const color_fg,
    enum lpdt_colors_e const color_bg)
{
  struct lpdt_color_param_s * new_param = malloc(sizeof(*new_param));
  new_param->fg = color_fg;
  new_param->bg = color_bg;
  return new_param;
}

extern struct lpdt_color_param_rgb_s* lpdt_make_color_param_rgb(struct lpdt_color_rgb_fg_s const color_fg,
    struct lpdt_color_rgb_bg_s const color_bg)
{
  struct lpdt_color_param_rgb_s * new_param = malloc(sizeof(*new_param));
  new_param->fg = color_fg;
  new_param->bg = color_bg;
  return new_param;
}

extern struct lpdt_buffer_code_rgb_s* lpdt_make_buffer_rgb_code(void)
{
  struct lpdt_buffer_code_rgb_s * new_buffer = malloc(sizeof(*new_buffer));
  return new_buffer;
}

extern struct lpdt_buffer_effect_s* lpdt_make_buffer_effect(enum lpdt_effects_e const effects)
{
  struct lpdt_buffer_effect_s * new_buffer = malloc(sizeof(*new_buffer));

  // .... Код инициализации

  return new_buffer;
}
