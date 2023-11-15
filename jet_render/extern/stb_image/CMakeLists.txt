cmake_minimum_required(VERSION 3.20)

project(stb_image LANGUAGES C)

set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_library(stb_image STATIC include/stb_image.h src/stb_image.c)
target_include_directories(stb_image PUBLIC include)