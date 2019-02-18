//
//-----------------------------------
//	LCD garphic library
//-----------------------------------
//
//
//
//-----------------------------------
//	How to use this library
//-----------------------------------
//
//
//-----------------------------------

#ifndef LCD_GFX_H
#define LCD_GFX_H

#include "fonts.h"
#include "LCD_STM32_Driver.h"

#define     LCD_WIDTH               LCD_SCREEN_WIDTH
#define     LCD_HEIGHT              LCD_SCREEN_HEIGHT

#define     HORIZONTAL_IMAGE        0
#define     VERTICAL_IMAGE          1
#define     Y_AXIS                  1
#define     X_AXIS                  2

#define     CHAR_BUF_SIZE           2000       


#define UNUSED(X) (void)X      /* To avoid gcc/g++ warnings */

#if defined ( __GNUC__ ) && !defined (__CC_ARM) /* GNU Compiler */
  #ifndef __weak
    #define __weak   __attribute__((weak))
  #endif /* __weak */
  #ifndef __packed
    #define __packed __attribute__((__packed__))
  #endif /* __packed */
#endif /* __GNUC__ */


void LCD_Init(void);

void LCD_Fill_Screen(uint32_t Colour);

void LCD_Draw_Horizontal_Line(uint16_t X, uint16_t Y, uint16_t Width, uint32_t Colour);
void LCD_Draw_Vertical_Line(uint16_t X, uint16_t Y, uint16_t Width, uint32_t Colour);
void LCD_Draw_Line(uint16_t color, uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2);
void LCD_Draw_Rect(uint32_t color, uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2);
void LCD_Draw_Filled_Rect(uint32_t Colour, uint16_t X0, uint16_t Y0, uint16_t X1, uint16_t Y1);
//void LCD_Draw_Rect_Coord(uint16_t X0, uint16_t Y0, uint16_t X1, uint16_t Y1, uint16_t Colour);
//void LCD_Draw_Filled_Rect_Coord(uint16_t Colour, uint16_t X0, uint16_t Y0, uint16_t X1, uint16_t Y1);


//USING CONVERTER: http://www.digole.com/tools/PicturetoC_Hex_converter.php
//65K colour (2Bytes / Pixel)
void LCD_Draw_Image(uint8_t *buf, uint16_t X0, uint16_t X1, uint16_t Y0, uint16_t Y1);

uint16_t find_strlen(uint8_t* text, uint8_t size);
uint16_t find_textlen(uint8_t* text, uint8_t size, uint16_t width, uint16_t *text_width);
void LCD_Draw_Char(char Character, uint16_t X, uint16_t Y, uint16_t Colour, uint16_t Size, uint16_t BackColour);
void LCD_Draw_Text(const uint8_t *Text, uint16_t X, uint16_t Y, uint16_t Colour, uint16_t Size, uint16_t BackColour);

void LCD_Draw_Triangle(uint16_t X1, uint16_t Y1,
        uint16_t X2, uint16_t Y2,
        uint16_t X3, uint16_t Y3,
        uint16_t Color);

void LCD_Draw_Filled_Triangle(uint16_t Color, uint16_t pt_x, uint16_t pt_y,
        uint16_t v1_x, uint16_t v1_y,
        uint16_t v2_x, uint16_t v2_y,
        uint16_t v3_x, uint16_t v3_y);

void LCD_Draw_Filled_Triangle_Gradient(uint16_t Color1, uint16_t Color2,
        uint16_t pt_x, uint16_t pt_y,
        uint16_t v1_x, uint16_t v1_y,
        uint16_t v2_x, uint16_t v2_y,
        uint16_t v3_x, uint16_t v3_y);
void LCD_Draw_Gradient(uint16_t x, uint16_t y, uint16_t w, uint16_t h,
        uint16_t Color1, uint16_t Color2, uint16_t axis);

void LCD_Draw_Circle(uint16_t X, uint16_t Y, uint16_t Radius, uint16_t Colour);
void LCD_Draw_Filled_Circle(uint16_t X, uint16_t Y, uint16_t Radius, uint16_t Colour);
void LCD_Draw_Filled_Ellipse(uint16_t X0, uint16_t Y0,
        uint16_t A, uint16_t B, uint16_t Colour);
void LCD_Draw_Ellipse(uint16_t X0, uint16_t Y0,
        uint16_t A, uint16_t B, uint16_t Colour);


// low level
void LCD_Configure(void);
void LCD_Draw_Rectangle(uint16_t X, uint16_t Y, uint16_t Width, uint16_t Height, uint32_t Colour);
void LCD_Draw_Pixel(uint16_t X,uint16_t Y,uint16_t Colour);
void LCD_Draw_Picture(uint8_t *buf, uint16_t X0, uint16_t X1, uint16_t Y0, uint16_t Y1);

#endif
