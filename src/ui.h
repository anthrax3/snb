#ifndef UI_H
#define UI_H

#define DLG_MIN_SPACE 32

struct UI_File {
  bool loaded;
  char *path;
} UI_File;

int ui_scr_width;

Result ui_set_root(Entry *e);
Result ui_get_root();
void ui_start();
void ui_stop();
void ui_refresh();
void ui_mainloop();

#endif
