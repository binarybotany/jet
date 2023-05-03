cmake_minimum_required(VERSION 3.4...3.20 FATAL_ERROR)

project(jet_renderer
        VERSION 0.0.0
        DESCRIPTION "Jet low level renderer library" 
        HOMEPAGE_URL "https://github.com/binarybotany/jet"
        LANGUAGES CXX)

set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(GLFW_BUILD_EXAMPLES OFF)
set(GLFW_BUILD_TESTS OFF)
set(GLFW_BUILD_DOCS OFF)
set(GLFW_INSTALL OFF)

set(jet_renderer_headers
    "src/window.h"
    "src/window_configuration.h")

set(jet_renderer_sources
    "src/window.cc")

add_library(jet_renderer STATIC ${jet_renderer_headers} ${jet_renderer_sources})

add_subdirectory(extern/glad)
target_include_directories(jet_renderer PUBLIC extern/glad/include)

add_subdirectory(extern/glfw)
target_include_directories(jet_renderer PUBLIC extern/glfw/include)

target_link_libraries(jet_renderer PRIVATE glad glfw)
