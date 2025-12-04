
cmake_minimum_required(VERSION 4.1)


add_library(cmath INTERFACE)
target_include_directories(cmath INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})