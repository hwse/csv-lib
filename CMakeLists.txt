cmake_minimum_required(VERSION 3.16)
project(csv_lib)

set(CMAKE_CXX_STANDARD 17)

add_library(csv_lib library.cpp library.h)

# Use namespace to export library
add_library(csv_lib::csv_lib ALIAS csv_lib)