cmake_minimum_required(VERSION 3.20)

project(jet_ecs LANGUAGES CXX)

set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(extern/entt)

set(jet_ecs_headers 
    "include/jet/ecs.h" 
    "entity_manager.h")

set(jet_ecs_sources 
    "entity_manager.cc" 
    "ecs.cc")

add_library(jet_ecs STATIC ${jet_ecs_headers} ${jet_ecs_sources})
target_include_directories(jet_ecs PUBLIC include)
target_link_libraries(jet_ecs PUBLIC EnTT::EnTT)