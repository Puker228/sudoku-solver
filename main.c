#include <stdio.h>
#include <string.h>

int N = 9;

void print_grid(int grid[N][N], char text[]) {
  printf("%s\n", text);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      printf("%d ", grid[i][j]);

      if (j == 2 || j == 5) {
        printf("| ");
      }
    }

    printf("\n");
    if (i == 2 || i == 5) {
      printf("------+-------+------\n");
    }
  }
}

int main(void) {
  int field[9][9] = {
      {6, 0, 0, 0, 7, 0, 0, 0, 2}, {0, 5, 8, 3, 6, 2, 4, 7, 0},
      {0, 0, 0, 9, 0, 8, 0, 0, 0}, {9, 6, 0, 0, 8, 0, 0, 1, 4},
      {0, 1, 2, 0, 0, 0, 8, 9, 0}, {8, 4, 0, 0, 9, 0, 0, 3, 5},
      {0, 0, 0, 8, 0, 7, 0, 0, 0}, {0, 3, 1, 4, 2, 6, 9, 5, 0},
      {4, 0, 0, 0, 1, 0, 0, 0, 7},
  };

  int ans_field[9][9];

  memcpy(ans_field, field, sizeof(field));

  print_grid(field, "orig:");

  printf("\n\n");

  print_grid(ans_field, "ans:");
  for (int row = 0; row < 9; row++) {
    int available_nums[9];
    for (int num = 0; num < 9; num++) {
      available_nums[num] = num + 1;
    }

    for (int clmn = 0; clmn < 9; clmn++) {
      for (int x = 0; x < 9; x++) {
        if (ans_field[row][clmn] == available_nums[x]) {
          available_nums[x] = 0;
        }

        if (ans_field[x][clmn] == available_nums[x]) {
          available_nums[x] = 0;
        }
      }
    }
  }

  return 0;
}
