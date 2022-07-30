#include "../src/lpdt.h"
#include <stdio.h>

void hello(char const* name)
{
  printf("%s, ", "Hello");
  lpdt_println(name,
      lpdt_color_fgbg(lpdt_fg(LPDT_COLOR_BLUE)),
      LPDT_EFFECT_BOLD | LPDT_EFFECT_UNDERLINE);
  /* lpdt_println(name, */
  /*     lpdt_color_fgbg(lpdt_fg(LPDT_COLOR_BLUE)), */
  /*     LPDT_EFFECT_BOLD | LPDT_EFFECT_UNDERLINE); */
  lpdt_println(name, lpdt_color_fgbg_rgb(lpdt_rgb_fg(123,54,255)), 0);
  lpdt_println(name, lpdt_color_fgbg_rgb(lpdt_rgb_bg(200, 200, 0)), 0);
  /* lpdt_println(name, lpdt_color_fgbg_rgb(lpdt_rgb_fg(0,255,255)), 0); */
  /* lpdt_println(name, lpdt_color_fgbg_rgb(lpdt_rgb_bg(0,255,255)), 0); */
}

int main(int argc, char const* argv[])
{
  if ( argc > 1)
      hello(argv[1]);
  else
      hello("world");
}
