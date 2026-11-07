cmake_minimum_required(VERSION 3.16)
project(sudoku_solver C)

option(SUDOKU_BUILD_GUI "Build the Sudoku GUI" ON)

set(CMAKE_C_STANDARD 11)

add_library(sudoku SHARED
        src/solve.c
)

target_include_directories(sudoku PUBLIC src)

add_executable(sudoku_solver
        main.c)

target_link_libraries(sudoku_solver PRIVATE sudoku)

if(SUDOKU_BUILD_GUI)
    include(FetchContent)

    set(RAVEN_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
    set(RAVEN_BUILD_TESTS OFF CACHE BOOL "" FORCE)
    set(RAVEN_BUILD_TOOLS OFF CACHE BOOL "" FORCE)
    set(RAVEN_BUILD_WEB OFF CACHE BOOL "" FORCE)

    FetchContent_Declare(
        raven
        GIT_REPOSITORY https://github.com/oscar-soirey/Raven.git
        GIT_TAG v0.2.2
        GIT_SHALLOW TRUE
    )

    FetchContent_MakeAvailable(raven)

    add_executable(sudoku_gui
        gui/gui.c
    )

    add_custom_command(TARGET sudoku_gui POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${CMAKE_CURRENT_SOURCE_DIR}/gui/window.xml"
            "$<TARGET_FILE_DIR:sudoku_gui>/window.xml"
    )

    target_include_directories(sudoku_gui PRIVATE
        "/gui"
    )

    target_link_libraries(sudoku_gui PRIVATE
        sudoku
        raven::raven
    )
endif()
