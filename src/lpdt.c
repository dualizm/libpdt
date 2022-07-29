#include <stdio.h>

#include "lpdt.h"

extern void lpdt_print_dyed_colors(void * msg,
    unsigned long long size_msg,
    struct lpdt_color_param_s const* color,
    enum lpdt_effects_e const effects)
{
  struct lpdt_buffer_effect_s *buffer_effect = lpdt_make_buffer_effect(effects);

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
