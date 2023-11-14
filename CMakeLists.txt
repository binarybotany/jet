cmake_minimum_required(VERSION 3.20)

project(jet LANGUAGES CXX)

set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(jet_core)
add_subdirectory(jet_ioc)
add_subdirectory(jet_render)
add_subdirectory(jet_ui)

add_subdirectory(src bin)