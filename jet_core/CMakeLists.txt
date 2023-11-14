cmake_minimum_required(VERSION 3.20)

project(jet_core LANGUAGES CXX)

set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(jet_core STATIC include/jet/core.h core.cc)
target_include_directories(jet_core PUBLIC include)