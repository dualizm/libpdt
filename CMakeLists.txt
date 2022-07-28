cmake_minimum_required(VERSION 3.2)

project(lpdt
        VERSION 1.0
        LANGUAGES C)

include_directories(src)

set(LPDT_SOURCE
  src/lpdt.c
  src/color.c)

add_library(${PROJECT_NAME} ${LPDT_SOURCE})
