#include <stdio.h>
#include <string.h>

#define N 9

static void print_grid(int grid[N][N], const char *text) {
  printf("%s\n", text);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      printf("%d ", grid[i][j]);
      if (j == 2 || j == 5)
        printf("| ");
    }
    printf("\n");
    if (i == 2 || i == 5)
      printf("------+-------+------\n");
  }
}

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

  const int br = row - row % 3;
  const int bc = col - col % 3;
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      if (grid[br + i][bc + j] == num) {
        return 0;
      }

  return 1;
}

static int solve_sudoku(int grid[N][N]) {
  for (int row = 0; row < N; row++) {
    for (int col = 0; col < N; col++) {
      if (grid[row][col] != 0) {
        continue;
      }

      for (int num = 1; num <= 9; num++) {
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

int main(void) {
  int field[N][N] = {
      {6, 0, 0, 0, 7, 0, 0, 0, 2}, {0, 5, 8, 3, 6, 2, 4, 7, 0},
      {0, 0, 0, 9, 0, 8, 0, 0, 0}, {9, 6, 0, 0, 8, 0, 0, 1, 4},
      {0, 1, 2, 0, 0, 0, 8, 9, 0}, {8, 4, 0, 0, 9, 0, 0, 3, 5},
      {0, 0, 0, 8, 0, 7, 0, 0, 0}, {0, 3, 1, 4, 2, 6, 9, 5, 0},
      {4, 0, 0, 0, 1, 0, 0, 0, 7},
  };

  int ans_field[N][N];
  memcpy(ans_field, field, sizeof(field));

  print_grid(field, "orig:");
  printf("\n\n");

  if (solve_sudoku(ans_field)) {
    print_grid(ans_field, "solved:");
  } else {
    printf("no answer\n");
  }
  return 0;
}
