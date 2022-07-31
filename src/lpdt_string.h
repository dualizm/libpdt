#pragma once
#ifndef LPDT_STRING_H_
#define LPDT_STRING_H_
#include "lpdt_text.h"

// string for color
typedef struct lpdt_dyed_string_s
{
  char *data;
  unsigned long long len_data;
  unsigned char r, g, b;
  enum lpdt_color_type_e color_fg;
} lpdt_string_t;

#endif /* LPDT_STRING_H_ */
