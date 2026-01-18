
cmake_minimum_required(VERSION 4.0)


add_library(cmath_interface INTERFACE)
target_include_directories(cmath_interface INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})