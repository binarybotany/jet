cmake_minimum_required(VERSION 3.20)

project(jet_core LANGUAGES CXX)

set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(extern/json)

set(jet_core_headers 
    "include/jet/core.h"
    "configuration.h"
    "file.h"
    "logger.h")

set(jet_core_sources
    "file.cc"
    "logger.cc")

add_library(jet_core STATIC ${jet_core_headers} ${jet_core_sources})
target_include_directories(jet_core PUBLIC include)
target_link_libraries(jet_core PUBLIC nlohmann_json::nlohmann_json)