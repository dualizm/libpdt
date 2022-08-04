#include "../src/lpdt.h"
#include <stdio.h>

void hello(char const* name)
{
  // Simple print 
  // Will be replaced in the future by lpdt_printf
  printf("%s\n", "Hello LDPT");

  // Test print text with color and effect
  lpdt_println(name, lpdt_color_fgbg_rgb(lpdt_rgb_fg(123,54,255), lpdt_rgb_bg(21,80,34)), LPDT_EFFECT_BOLD);
  lpdt_println(name, lpdt_color_fgbg_rgb(lpdt_rgb_bg(200, 200, 0), lpdt_rgb_fg(0,156,4)), LPDT_EFFECT_INVISIBLE);
  lpdt_println(name, lpdt_color_fgbg(lpdt_fg(LPDT_COLOR_CYAN), lpdt_bg(LPDT_COLOR_RED)), LPDT_EFFECT_ITALIC);
  lpdt_println(name, lpdt_color_fgbg(lpdt_bg(LPDT_COLOR_CYAN), lpdt_fg(LPDT_COLOR_RED)), LPDT_EFFECT_UNDERLINE);

  // Test print effect
  char const* frase_test_effect = "TEST SUPER EFFECT\n";
  lpdt_printef(frase_test_effect, LPDT_EFFECT_BOLD);
  lpdt_printef(frase_test_effect, LPDT_EFFECT_UNDERLINE);
  lpdt_printef(frase_test_effect, LPDT_EFFECT_BLINK);
  lpdt_printef(frase_test_effect, LPDT_EFFECT_RAPID_BLINK);
  lpdt_printef(frase_test_effect, LPDT_EFFECT_FAINT);
  lpdt_printef(frase_test_effect, LPDT_EFFECT_ITALIC);
  lpdt_printef(frase_test_effect, LPDT_EFFECT_OVERLINE);

  // Test print color
  /* char const* frase_test_color = "TEST SUPER COLOR"; */
  /* lpdt_printcl(frase_test_color, lpdt_make_color_fgbg(LPDT_COLOR_RED, LPDT_COLOR_CYAN)); */
//^---- some error.... FIX!!!
}

int main(int argc, char const* argv[])
{
  if ( argc > 1)
      hello(argv[1]);
  else
      hello("world");
}
