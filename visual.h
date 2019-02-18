#ifndef __VISUAL_H__
#define __VISUAL_H__

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "LCD_STM32_Driver.h"
#include "LCD_Drawing.h"

#define PI      3.141592
#define NBUF1   480

//#define TEST_MODE_0     1     // test widgets
//#define TEST_MODE_1     1       // test graphic
#define TEST_MODE_2     1       // test touch_pad

#define COLOR_BORDER    BLACK
#define COLOR_PASSIVE   LIGHTBLUE   //NAVY
#define COLOR_ACTIVE    BLUE
#define COLOR_BCKGND    WHITE
#define COLOR_TXT       WHITE
#define COLOR_EMPTY     WHITE

extern uint32_t buf1[];
extern uint32_t ibuf1;

extern char *btn_tm[5];

extern char *arr_year[10];
extern char *btn_year[10];

extern char *arr_month[12];
extern char *btn_month[12];

extern char *tbl_day[2];
extern char *btn_day1[3];
extern char *arr_day1[3];
extern char *btn_day2[4];
extern char *arr_day2[4];

extern char *btn_date[5];
extern char *arr_date[5];
extern char *date_number[31];

void screen_main();
void add_widgets_main();

void screen_config();
void add_widgets_config();

void screen_touchset();
void add_widgets_touchset();

void screen_graphic();
void add_widgets_graphic();

void screen_dialog();
void add_widgets_dialog();

#endif /*__VISUAL_H__*/