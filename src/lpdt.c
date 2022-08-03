#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "lpdt.h"

#define LPDT_PRINT_TEXT_(MSG) \
  fputs(MSG, stdout)

#define LPDT_PRINT_END_CODE_ \
  fputs(lpdt_code_end(), stdout)

#define LPDT_PRINT_EFFECTS_CODE_(EFFECTS) \
  struct lpdt_buffer_effect_s * macro_buffer_effects = lpdt_make_buffer_effect(effects); \
  fputs(macro_buffer_effects->data, stdout); \
  free(macro_buffer_effects)

static inline void lpdt_verify_and_print_code_color_(enum lpdt_colors_code_e const color,
    enum lpdt_color_type_e const type)
{
  if ( color != LPDT_NOT_USE_THAT_COLOR_NONE) {
    fputs(lpdt_code_color(color, type), stdout);
  }
}

static inline void lpdt_verify_and_print_code_color_rgb_(void * color,
    enum lpdt_color_type_e const type)
{
  struct lpdt_buffer_code_rgb_s * buffer_rgb_code = lpdt_malloc_buffer_code_rgb();
  if ( type == LPDT_FG ) {
    struct lpdt_color_rgb_fg_s * color_fg = (struct lpdt_color_rgb_fg_s*)color;
    if ( ((color_fg) != NULL) ) {
      lpdt_code_rgb(buffer_rgb_code, color_fg->r, color_fg->g, color_fg->b, type);
      }
  }
  else if ( type == LPDT_BG ) {
    struct lpdt_color_rgb_bg_s * color_bg = (struct lpdt_color_rgb_bg_s*)color;
    if ( ((color_bg) != NULL) ) {
      lpdt_code_rgb(buffer_rgb_code, color_bg->r, color_bg->g, color_bg->b, type);
      }
  }
  fputs(buffer_rgb_code->data, stdout);
  free(buffer_rgb_code);
}

#define LPDT_PRINT_COLOR_CODE_(COLOR_PTR) \
  lpdt_verify_and_print_color_(COLOR_PTR->fg, LPDT_FG), \
  lpdt_verify_and_print_color_(LPDT_VERIFY_AND_PRINT_COLOR(COLOR_PTR->bg, LPDT_BG), \
  free(COLOR_PTR)

#define LPDT_PRINT_COLOR_RGB_CODE_(COLOR_RGB_PTR) \
  lpdt_verify_and_print_color_rgb_(COLOR_RGB_PTR->fg, LPDT_FG) \
  lpdt_verify_and_print_color_rgb_(COLOR_RGB_PTR->bg, LPDT_BG) \
  free(COLOR_RGB_PTR)

#define LPDT_PRINT_COLOR_(COLOR) _Generic((COLOR), \
    struct lpdt_color_fgbg_s * : LPDT_PRINT_COLOR_CODE_(COLOR), \
    struct lpdt_color_fgbg_rgb_s * : LPDT_PRINT_COLOR_RGB_CODE_(COLOR))

extern void lpdt_printcl(char const* msg,
    struct lpdt_color_fgbg_s * color)
{
  // Print text with color code
  LPDT_PRINT_COLOR(color);
  //Print text
  LPDT_PRINT_TEXT_(msg);
  // Print end code
  LPDT_PRINT_END_CODE_;
}

extern void lpdt_printcl_rgb(char const* msg,
    struct lpdt_color_fgbg_rgb_s * color)
{
  //Print color rgb code
  LPDT_PRINT_COLOR(color);
  // Print text
  LPDT_PRINT_TEXT_(msg);
  // Print end code
  LPDT_PRINT_END_CODE_;
}

extern void lpdt_printef(char const* msg,
    enum lpdt_effects_code_e const effects)
{
  // Print effects code
  LPDT_PRINT_EFFECTS_CODE_(effects);
  // Print text
  LPDT_PRINT_TEXT_(msg);
  // Print end code
  LPDT_PRINT_END_CODE_;
}

void lpdt_print_dyed_colors(char const* msg,
    struct lpdt_color_fgbg_s * color,
    enum lpdt_effects_code_e const effects)
{
  // Print color
  LPDT_PRINT_COLOR(color);

  // Print effect code
  LPDT_PRINT_EFFECTS_CODE_(effects);
  // Print text
  LPDT_PRINT_TEXT_(msg);

  // Print end code
  LPDT_PRINT_END_CODE_;
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
  // Print rgb color code
  LPDT_PRINT_COLOR(color);

  // Print effect code
  LPDT_PRINT_EFFECTS_CODE_(effects);

  // Print text
  LPDT_PRINT_TEXT_(msg);

  // Print end code
  LPDT_PRINT_END_CODE_;
}

void lpdt_print_dyedln_rgb(char const* msg,
    struct lpdt_color_fgbg_rgb_s * color,
    enum lpdt_effects_code_e const effects)
{
  lpdt_print_dyed_rgb(msg, color, effects);
  puts("");
}

noreturn 
extern int lpdt_printf(char const* restrict format, ...)
{

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
