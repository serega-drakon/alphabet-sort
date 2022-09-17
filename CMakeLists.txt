cmake_minimum_required(VERSION 3.23)
project(alphabet_sort_new)

set(CMAKE_CXX_STANDARD 14)

include_directories(alphabet-sort-release/include)

add_executable(alphabet_sort_new
        alphabet-sort-release/main.c
        alphabet-sort-release/include/alphabet.c
        alphabet-sort-release/include/alphabet.h
        alphabet-sort-release/include/fileio.c
        alphabet-sort-release/include/fileio.h
        alphabet-sort-release/include/funcs2d.c
        alphabet-sort-release/include/funcs2d.h
        alphabet-sort-release/include/intArray2d.c
        alphabet-sort-release/include/intArray2d.h)
