cmake_minimum_required(VERSION 3.20)

add_executable(jet main.cc)
target_link_libraries(jet PRIVATE jet_core jet_ioc jet_render jet_ui)