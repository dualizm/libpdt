#include "lpdt_color.h"
#include <stdio.h>
#include <stdlib.h>

extern char const* color_code(enum lpdt_colors_e const color,
    enum lpdt_color_type_e const type) 
{
  if ( type == fg)
  {
    switch(color)
    {
      case black:          return "\033[0;30m"  ; break;
      case red:            return "\033[0;31m"  ; break;
      case green:          return "\033[0;32m"  ; break;
      case yellow:         return "\033[0;33m"  ; break;
      case blue:           return "\033[0;34m"  ; break;
      case magenta:        return "\033[0;35m"  ; break;
      case cyan:           return "\033[0;36m"  ; break;
      case white:          return "\033[0;37m"  ; break;
      case standard:       return "\033[0;39m"  ; break;
      case bright_black:   return "\033[0;90m"  ; break;
      case bright_red:     return "\033[0;91m"  ; break;
      case bright_green:   return "\033[0;92m"  ; break;
      case bright_yellow:  return "\033[0;93m"  ; break;
      case bright_blue:    return "\033[0;94m"  ; break;
      case bright_magenta: return "\033[0;95m"  ; break;
      case bright_cyan:    return "\033[0;96m"  ; break;
      case bright_white:   return "\033[0;97m"  ; break;
      case end:            return "\033[0m"     ; break;
    }
  }
  else if ( type == bg)
  {
    switch(color)
    {
      case black:          return "\033[0;40m"  ; break;
      case red:            return "\033[0;41m"  ; break;
      case green:          return "\033[0;42m"  ; break;
      case yellow:         return "\033[0;43m"  ; break;
      case blue:           return "\033[0;44m"  ; break;
      case magenta:        return "\033[0;45m"  ; break;
      case cyan:           return "\033[0;46m"  ; break;
      case white:          return "\033[0;47m"  ; break;
      case standard:       return "\033[0;49m"  ; break;
      case bright_black:   return "\033[0;100m" ; break;
      case bright_red:     return "\033[0;101m" ; break;
      case bright_green:   return "\033[0;102m" ; break;
      case bright_yellow:  return "\033[0;103m" ; break;
      case bright_blue:    return "\033[0;104m" ; break;
      case bright_magenta: return "\033[0;105m" ; break;
      case bright_cyan:    return "\033[0;106m" ; break;
      case bright_white:   return "\033[0;107m" ; break;
      case end:            return "\033[0m"     ; break;
    }
  }
  else 
  {
    return "\033[0m";
  }
}

extern void code_rgb(char destination[17],
    char const r, char const g, char const b,
    enum lpdt_color_type_e const type)
{
  if ( type == fg)
  {
    sprintf(destination, "\033[38;2;%d;%d;%dm", r, g, b);
  }
  else if ( type == bg)
  {
    sprintf(destination, "\033[48;2;%d;%d;%dm", r, g, b);
  }
}

extern char const* code_effect(enum lpdt_effect_e const effect) 
{
  switch (effect)
  {
    case bold:        return "\033[1m"; break;
    case faint:       return "\033[2m"; break;
    case italic:      return "\033[3m"; break;
    case underline:   return "\033[4m"; break;
    case blink:       return "\033[5m"; break;
    case rapid_blink: return "\033[5m"; break;
    case inverse:     return "\033[7m"; break;
    case invisible:   return "\033[8m"; break;
    case overline:    return "\033[9m"; break;
  }
}

extern struct lpdt_color_s* init_color( enum lpdt_color_type_e const type,
    enum lpdt_colors_e const color)
{
  struct lpdt_color_s * new_color = 
    (struct lpdt_color_s*)malloc(sizeof(struct lpdt_color_s));

  new_color->color  = color;
  new_color->type   = type; 
  return new_color;
}

extern struct lpdt_color_rgb_s* init_color_rgb(enum lpdt_color_type_e const type,
    char const r, char const g, char const b)
{
  struct lpdt_color_rgb_s * new_color =
    (struct lpdt_color_rgb_s*)malloc(sizeof(struct lpdt_color_rgb_s));

  new_color->type = type;
  new_color->r = r;
  new_color->g = g;
  new_color->b = b;
  return new_color;
}
