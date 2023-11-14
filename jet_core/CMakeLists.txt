cmake_minimum_required(VERSION 3.20)

project(jet_core LANGUAGES CXX)

set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(jet_core_headers 
    "include/jet/core.h"
    "logger.h")

set(jet_core_sources
    "core.cc"
    "logger.cc")

add_library(jet_core STATIC ${jet_core_headers} ${jet_core_sources})
target_include_directories(jet_core PUBLIC include)