cmake_minimum_required(VERSION 3.2)
set(CMAKE_C_COMPILER clang)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_C_STANDARD 17)

set(COMPILER_OPT_TEST -g -Werror -Wall -Wextra -Wpedantic -fPIC -march=native  )

project(lpdt
        VERSION 1.0
        LANGUAGES C)

include_directories(src)

set(LPDT_SOURCE
  src/lpdt.c
  src/lpdt_text.c
  src/lpdt_codes.c
)

add_library(pdt SHARED ${LPDT_SOURCE})
