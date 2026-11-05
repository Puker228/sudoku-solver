#include <stdio.h>
#include <string.h>

#include "src/solve.h"

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

int main(void) {
  int field[N][N] = {
      {0, 0, 3, 9, 0, 0, 0, 2, 6}, {7, 0, 0, 0, 0, 8, 3, 0, 5},
      {0, 0, 0, 0, 0, 0, 0, 9, 0}, {0, 0, 5, 0, 0, 0, 6, 0, 0},
      {4, 0, 0, 1, 8, 3, 0, 0, 0}, {8, 0, 9, 0, 0, 6, 0, 3, 4},
      {0, 5, 2, 4, 1, 0, 7, 8, 0}, {0, 8, 0, 3, 0, 0, 0, 0, 0},
      {3, 0, 0, 8, 0, 0, 2, 0, 9},
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
