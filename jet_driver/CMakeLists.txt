cmake_minimum_required(VERSION 3.4...3.20 FATAL_ERROR)

project(jet_driver
        VERSION 0.0.0
        DESCRIPTION "Test driver for jet engine" 
        HOMEPAGE_URL "https://github.com/binarybotany/jet"
        LANGUAGES CXX)

set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(../jet_renderer jet_renderer)

add_subdirectory(src bin)