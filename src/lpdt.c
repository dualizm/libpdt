#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lpdt.h"
#include "lpdt_codes.h"

void lpdt_print_dyed_colors(char const* msg,
    struct lpdt_color_fgbg_s * color,
    enum lpdt_effects_code_e const effects)
{
  struct lpdt_buffer_effect_s *buffer_effect = lpdt_make_buffer_effect(effects);

  // Print color code
  LPDT_VERIFY_AND_PRINT_COLOR(color->fg, LPDT_FG)
  LPDT_VERIFY_AND_PRINT_COLOR(color->bg, LPDT_BG)
  free(color);

  // Print effect code
  fputs(buffer_effect->data, stdout);
  free(buffer_effect);

  // Print text
  fputs(msg, stdout);

  // Print end code
  fputs(lpdt_code_end(), stdout);
}

void lpdt_print_dyedln_colors(char const* msg,
    struct lpdt_color_fgbg_s * color,
    enum lpdt_effects_code_e const effects)
{
  lpdt_print_dyed_colors(msg, color, effects);
  puts("");
}

void lpdt_print_dyed_rgb(char const* msg,
    struct lpdt_color_fgbg_rgb_s * color,
    enum lpdt_effects_code_e const effects)
{
  struct lpdt_buffer_effect_s *buffer_effect = lpdt_make_buffer_effect(effects);

  // Print rgb color code
  LPDT_VERIFY_AND_PRINT_COLOR_RGB(color->fg, LPDT_FG);
  LPDT_VERIFY_AND_PRINT_COLOR_RGB(color->bg, LPDT_BG);
  free(color);

  // Print effect code
  fputs(buffer_effect->data, stdout);
  free(buffer_effect);

  // Print text
  fputs(msg, stdout);

  // Print end code
  fputs(lpdt_code_end(), stdout);
}

void lpdt_print_dyedln_rgb(char const* msg,
    struct lpdt_color_fgbg_rgb_s * color,
    enum lpdt_effects_code_e const effects)
{
  lpdt_print_dyed_rgb(msg, color, effects);
  puts("");
}


/* extern void print_dyed(colors_t const color, */
/*     colort_t const colort, char const* msg) */ 
/* { */
/*   if ( colort == FG) */ 
/*   { */
/*     printf("%s%s%s", */ 
/*         get_color(color, colort), */
/*         msg, */
/*         get_color(end, 0)); */
/*   } */
/*   else if ( colort == BG) */
/*   { */
/*   } */
/* } */

/* // The function to print text to the console */
/* // of a certain color with a line break */
/* void */ 
/* prcolorln(colors_t color, const char *msg) */ 
/* { */
/*   printf("%s%s%s\n", */ 
/*       get_color(color), */
/*       msg, */
/*       "\033[0m"); */
/* } */

/* void */
/* get_colorstr(char *str, colors_t color, const char *msg) */
/* { */
/*   sprintf(str, "%s%s%s", */ 
/*       get_color(color), */
/*       msg, */
/*       "\033[0m"); */
/* } */

/* void */ 
/* prcolorch(colors_t color, const char ch) */ 
/* { */
/*   printf("%s%c%s", */ 
/*       get_color(color), */
/*       ch, */
/*       "\033[0m"); */
/* } */

/* void */ 
/* prcolorchln(colors_t color, const char ch) */ 
/* { */
/*   printf("%s%c%s\n", */ 
/*       get_color(color), */
/*       ch, */
/*       "\033[0m"); */
/* } */

/* void */
/* get_colorstrch(char *str, colors_t color, const char ch) */
/* { */
/*   sprintf(str, "%s%c%s", */ 
/*       get_color(color), */
/*       ch, */
/*       "\033[0m"); */
/* } */
