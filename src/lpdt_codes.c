#include "lpdt_codes.h"
#include <stdlib.h>
#include <stdio.h>

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

void lpdt_code_rgb(char destination[static LPDT_MAX_BUFFER_CODE_RGB_],
    unsigned char const r, unsigned char const g, unsigned char const b,
    enum lpdt_color_type_e const type)
{
  if ( type == LPDT_FG)
  {
    snprintf(destination, LPDT_MAX_BUFFER_CODE_RGB_,
        "\033[38;2;%d;%d;%dm", r, g, b);
  }
  else if ( type == LPDT_BG)
  {
    snprintf(destination, LPDT_MAX_BUFFER_CODE_RGB_,
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
