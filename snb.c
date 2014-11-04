#define _GNU_SOURCE
#define _XOPEN_SOURCE_EXTENDED 1

#include <stdio.h>
#include <stdlib.h>

#include <error.h>
#include <locale.h>
#include <ncurses.h>
#include <wchar.h>

#include "data.h"
#include "ui.h"

int main(int argc, char *argv[]) {
  FILE *fp;
  Result res;
  
  setlocale(LC_ALL, "");

  if (argc > 1) {
    fp = fopen(argv[1], "r");
    if (fp == NULL) {
      perror("Can't open your file");
      exit(1);
    }
  } else
    fp = fopen("test-data-1.txt", "r");

  if (fp) {
    res = data_load(fp);
    fclose(fp);
  } else
    res = entry_new(80);

  if (!res.success) {
    fwprintf(stderr, L"ERROR: %S.\n", res.msg);
    perror("Unix error");
    exit(2);
  }

  ui_start();

  res = ui_set_root((Entry *)res.data);
  if (!res.success) {
    fwprintf(stderr, L"ERROR: %S.\n", res.msg);
    perror("Unix error");
    exit(3);
  }
  ui_refresh();

  ui_mainloop();
  ui_stop();

  res = ui_get_root();
  if (!res.success) {
    fwprintf(stderr, L"ERROR: %S.\n", res.msg);
    perror("Unix error");
    exit(4);
  }

  data_unload((Entry *)res.data);

  return 0;
}