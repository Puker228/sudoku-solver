cmake_minimum_required(VERSION 3.16)
project(sudoku_solver C)

find_package(raven REQUIRED)            # -DCMAKE_PREFIX_PATH=<the Raven package>

set(CMAKE_C_STANDARD 11)

add_library(sudoku SHARED
        src/solve.c
)

target_include_directories(sudoku PUBLIC src)

add_executable(sudoku_solver
        main.c)

target_link_libraries(sudoku_solver PRIVATE sudoku)

add_executable(sudoku_gui
    gui/gui.c
)

target_include_directories(sudoku_gui PRIVATE
    "/gui"
)

target_link_libraries(sudoku_gui PRIVATE
    sudoku
    raven::raven
)
