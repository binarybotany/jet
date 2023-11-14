cmake_minimum_required(VERSION 3.20)

project(jet_render LANGUAGES CXX)

set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(GLFW_BUILD_EXAMPLES OFF)
set(GLFW_BUILD_TESTS OFF)
set(GLFW_BUILD_DOCS OFF)
set(GLFW_INSTALL OFF)

add_subdirectory(extern/glad)
add_subdirectory(extern/glfw)

set(jet_render_headers 
    "include/jet/render.h"
    "window.h")

set(jet_render_sources
    "render.cc"
    "window.cc")

add_library(jet_render STATIC ${jet_render_headers} ${jet_render_sources})
target_include_directories(jet_render PUBLIC include)
target_link_libraries(jet_render PUBLIC glfw glad jet_core)