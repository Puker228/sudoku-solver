#include "Raven.h"
#include "solve.h"

#include <stdio.h>

static void on_quit(Rid sender, const char *action, void *user_data) {
  (void)sender;
  (void)action;
  (void)user_data;
  Rquit(0);
}

static void solve_button(Rid button, void *user_data) {
  (void)button;
  Rid window = *(Rid *)user_data;
  int grid[N][N] = {{0}};

  for (int row = 0; row < N; row++) {
    for (int column = 0; column < N; column++) {
      char name[16];
      snprintf(name, sizeof(name), "OriginalCell%d%d", row + 1, column + 1);
      Rid cell = Rwidget_find(window, name);
      const char *text = Rtext_input_get_text(cell);
      if (text[0] != '\0')
        grid[row][column] = text[0] - '0';
    }
  }

  if (!solve_sudoku(grid))
    return;

  for (int row = 0; row < N; row++) {
    for (int column = 0; column < N; column++) {
      char name[16];
      snprintf(name, sizeof(name), "SolvedCell%d%d", row + 1, column + 1);
      Rid cell = Rwidget_find(window, name);
      char value[2] = {grid[row][column] + '0', '\0'};
      Rtext_input_set_text(cell, value);
    }
  }
}

static int validate_cell_input(Rid widget, const REvent *event,
                               void *user_data) {
  (void)widget;
  (void)user_data;
  return event->type == R_EVENT_TEXT &&
         (event->codepoint < '1' || event->codepoint > '9');
}

int main(void) {
  if (!Rinit(R_BACKEND_VULKAN))
    return 1;
  Raction_bind("app.quit", on_quit, NULL);
  Rid window = Rwindow_create_from_xml_file("window.xml");
  if (window == R_INVALID_ID)
    return 1;

  for (int row = 1; row <= 9; row++) {
    for (int column = 1; column <= 9; column++) {
      char name[16];
      snprintf(name, sizeof(name), "OriginalCell%d%d", row, column);
      Rid cell = Rwidget_find(window, name);
      if (cell != R_INVALID_ID)
        Rwidget_set_event_callback(cell, validate_cell_input, NULL);
    }
  }

  Rid button = Rwidget_find(window, "SolveButton");
  if (button != R_INVALID_ID)
    Rbutton_set_clicked_callback(button, solve_button, &window);

  while (Rwait_frame(-1.0)) {
  }
  Rshutdown();
  return 0;
}
