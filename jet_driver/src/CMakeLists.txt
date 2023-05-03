cmake_minimum_required(VERSION 3.4...3.20 FATAL_ERROR)

add_executable(jet_driver main.cc)
target_include_directories(jet_driver PRIVATE ../../jet_renderer/include)
target_link_libraries(jet_driver PRIVATE jet_renderer)