#ifndef SUDOKU_H
#define SUDOKU_H

#define N 9
#if defined(_WIN32)
#if defined(sudoku_EXPORTS)
#define SUDOKU_API __declspec(dllexport)
#else
#define SUDOKU_API __declspec(dllimport)
#endif
#else
#define SUDOKU_API
#endif

SUDOKU_API int solve_sudoku(int grid[N][N]);

#endif
