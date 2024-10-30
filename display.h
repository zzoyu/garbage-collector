#ifndef __DISPLAY_H__
#define __DISPLAY_H__

#include <ssd1306.h>

void displayInit();
void displayClear();
void drawNormal();
void drawOuch();
void drawSmile();

#endif // __DISPLAY_H__