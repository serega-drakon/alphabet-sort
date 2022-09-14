cmake_minimum_required(VERSION 3.23)
project(alphabet_sort_new)

set(CMAKE_CXX_STANDARD 14)

include_directories(alphabet-sort-debug)
include_directories(alphabet-sort-debug/include)
include_directories(alphabet-sort-release)
include_directories(alphabet-sort-release/include)

add_executable(alphabet_sort_new
        alphabet-sort-debug/include/fileio.h
        alphabet-sort-debug/include/int_array_2d.h
        alphabet-sort-debug/main.c
        alphabet-sort-debug/main_in.txt
        alphabet-sort-debug/main_out.txt
        alphabet-sort-release/include/fileio.h
        alphabet-sort-release/include/int_array_2d.h
        alphabet-sort-release/main.c
        alphabet-sort-release/main_in.txt
        alphabet-sort-release/main_out.txt)
