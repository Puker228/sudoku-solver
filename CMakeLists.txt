cmake_minimum_required(VERSION 4.3)
project(sudoku_solver C)

set(CMAKE_C_STANDARD 11)

add_library(sudoku SHARED
    src/solve.c
)

target_include_directories(sudoku PUBLIC src)

add_executable(sudoku_solver
        main.c)

target_link_libraries(sudoku_solver PRIVATE sudoku)
