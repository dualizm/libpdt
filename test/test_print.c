#include "../src/lpdt.h"
#include <stdio.h>

void hello(char const* name)
{
  printf("%s\n", "Hello? Are you");
  lpdt_println(name,
      lpdt_color_fgbg(lpdt_fg(LPDT_COLOR_BLUE)),
      LPDT_EFFECT_BOLD | LPDT_EFFECT_UNDERLINE);
  /* lpdt_println(name, */
  /*     lpdt_color_fgbg(lpdt_fg(LPDT_COLOR_BLUE)), */
  /*     LPDT_EFFECT_BOLD | LPDT_EFFECT_UNDERLINE); */
  lpdt_println(name, lpdt_color_fgbg_rgb(lpdt_rgb_fg(123,54,255), lpdt_rgb_bg(21,80,34)), 0);
  lpdt_println(name, lpdt_color_fgbg_rgb(lpdt_rgb_bg(200, 200, 0), lpdt_rgb_fg(0,156,4)), 0);
  lpdt_println(name, lpdt_color_fgbg(lpdt_fg(LPDT_COLOR_CYAN), lpdt_bg(LPDT_COLOR_RED)), 0);
  lpdt_println(name, lpdt_color_fgbg(lpdt_bg(LPDT_COLOR_CYAN), lpdt_fg(LPDT_COLOR_RED)), 0);

  lpdt_println("I'm hero", lpdt_color_fgbg(0), LPDT_EFFECT_BOLD);
  lpdt_println("I'm hero", lpdt_color_fgbg(0), LPDT_EFFECT_UNDERLINE);
  lpdt_println("I'm hero", lpdt_color_fgbg(0), LPDT_EFFECT_BLINK);
  lpdt_println("I'm hero", lpdt_color_fgbg(0), LPDT_EFFECT_RAPID_BLINK);
  lpdt_println("I'm hero", lpdt_color_fgbg(0), LPDT_EFFECT_FAINT);
  lpdt_println("I'm hero", lpdt_color_fgbg(0), LPDT_EFFECT_ITALIC);
  lpdt_println("I'm hero", lpdt_color_fgbg(0), LPDT_EFFECT_OVERLINE);
}

int main(int argc, char const* argv[])
{
  if ( argc > 1)
      hello(argv[1]);
  else
      hello("world");
}
