#ifndef COLORS_H
#define COLORS_H

#define COLOR_KEY     1
#define COLOR_INFO    2
#define COLOR_OK      3
#define COLOR_WARN    4
#define COLOR_ERROR   5
#define COLOR_CURRENT 6
#define COLOR_CROSSED 7

// This is special: if the terminal can assume default colors
// then this is the default background color (= -1). Otherwise
// this is set to COLOR_BLACK. It should be safe to use within
// colors_init();
int BG_COLOR;

void colors_init();

#endif
