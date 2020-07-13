cmake_minimum_required(VERSION 3.16)
project(csv_lib LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

add_library(csv_lib src/csv.cpp include/csv.h)
target_include_directories(csv_lib PUBLIC include)
target_compile_features(csv_lib PUBLIC cxx_std_17)

# Use namespace to export library
add_library(csv_lib::csv_lib ALIAS csv_lib)