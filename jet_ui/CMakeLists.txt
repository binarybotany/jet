cmake_minimum_required(VERSION 3.20)

project(jet_ui LANGUAGES CXX)

set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(jet_ui STATIC include/jet/ui.h ui.cc)
target_include_directories(jet_ui PUBLIC include)