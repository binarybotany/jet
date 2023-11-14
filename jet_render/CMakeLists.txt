cmake_minimum_required(VERSION 3.20)

project(jet_render LANGUAGES CXX)

set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(jet_render STATIC include/jet/render.h render.cc)
target_include_directories(jet_render PUBLIC include)