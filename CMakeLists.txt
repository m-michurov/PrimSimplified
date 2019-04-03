cmake_minimum_required(VERSION 3.12)
project(PrimSimplified C)

set(CMAKE_C_STANDARD 11)

add_executable(Prim main.c prim.c graph.h errcodes.h graph.c ensure.h)