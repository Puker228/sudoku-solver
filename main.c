#include <stdio.h>
#include <string.h>

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

  printf("orig field:\n");
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      printf("%d ", field[i][j]);

      if (j == 2 || j == 5) {
        printf("| ");
      }
    }

    printf("\n");
    if (i == 2 || i == 5) {
      printf("------+-------+------\n");
    }
  }

  printf("\n\n");

  int all_nums[9];
  size_t count = sizeof(all_nums) / sizeof(all_nums[0]);

  printf("ans field:\n");
  for (int i = 0; i < 9; i++) {
    for (int o = 0; o < count; o++) {
      all_nums[o] = o + 1;
    }

    for (int j = 0; j < 9; j++) {
      for (int x = 0; x < count; x++) {
        if (all_nums[x] == ans_field[i][j]) {
          all_nums[x] = 0;
        }
      }
    }

    for (int j = 0; j < 9; j++) {
      if (ans_field[i][j] == 0) {
        for (int y = 0; y < count; y++) {
          if (all_nums[y] != 0) {
            ans_field[i][j] = all_nums[y];
            all_nums[y] = 0;
            break;
          }
        }
      }

      printf("%d ", ans_field[i][j]);
      if (j == 2 || j == 5) {
        printf("| ");
      }
    }

    printf("\n");

    if (i == 2 || i == 5) {
      printf("------+-------+------\n");
    }
  }

  return 0;
}
