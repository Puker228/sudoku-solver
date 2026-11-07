#include "Raven.h"

static void on_quit(Rid sender, const char *action, void *user_data) {
  (void)sender;
  (void)action;
  (void)user_data;
  Rquit(0);
}

int main(void) {
  if (!Rinit(R_BACKEND_VULKAN))
    return 1;
  Raction_bind("app.quit", on_quit, NULL);
  if (Rwindow_create_from_xml_file("window.xml") == R_INVALID_ID)
    return 1;
  while (Rwait_frame(-1.0)) {
  }
  Rshutdown();
  return 0;
}
