#include "solve.h"

static int can_place(int grid[N][N], const int row, const int col,
                     const int num) {
  for (int i = 0; i < N; i++) {
    if (grid[row][i] == num) {
      return 0;
    }
    if (grid[i][col] == num) {
      return 0;
    }
  }

  const int box_r = row - (row % 3);
  const int box_c = col - (col % 3);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (grid[box_r + i][box_c + j] == num) {
        return 0;
      }
    }
  }

  return 1;
}

int solve_sudoku(int grid[N][N]) {
  for (int row = 0; row < N; row++) {
    for (int col = 0; col < N; col++) {
      if (grid[row][col] != 0) {
        continue;
      }

      for (int num = 1; num <= N; num++) {
        if (can_place(grid, row, col, num)) {
          grid[row][col] = num;
          if (solve_sudoku(grid)) {
            return 1;
          }
          grid[row][col] = 0;
        }
      }
      return 0;
    }
  }
  return 1;
}
