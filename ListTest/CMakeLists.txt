cmake_minimum_required(VERSION 3.16)
project(ListTest C)

set(CMAKE_C_STANDARD 90)

add_library(list STATIC ../list/library.h ../list/library.c)
add_executable(ListTest main.c)
target_link_libraries(ListTest list)