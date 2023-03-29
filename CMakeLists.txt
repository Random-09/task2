cmake_minimum_required(VERSION 3.24)
project(task2 C)

set(CMAKE_C_STANDARD 11)

add_executable(task2 main.c binary_search.h quick_sort.h binary_search.c quick_sort.c ascii_funcs.c ascii_funcs.h)
