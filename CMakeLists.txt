cmake_minimum_required(VERSION 3.20)
project(5c C)

set(CMAKE_C_STANDARD 11)

add_executable(5c main.c libs/sorts/sorts.h libs/sorts/sorts.c libs/algorithms/algorithms.h libs/algorithms/algorithms.c)
