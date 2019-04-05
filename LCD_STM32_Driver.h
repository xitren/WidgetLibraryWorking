
#include <stdint.h>

#ifndef LCD_STM32_DRIVER_H
#define LCD_STM32_DRIVER_H

#define FRAME_RAM  0x20062000  

#define LCD_SCREEN_HEIGHT_FULL  272 
#define LCD_SCREEN_HEIGHT       128 
#define LCD_SCREEN_WIDTH        480

#define BURST_MAX_SIZE 	500

#define BLACK       0x0000    
#define NAVY        0x000F    
#define DARKGREEN   0x03E0    
#define DARKCYAN    0x03EF      
#define MAROON      0x7800      
#define PURPLE      0x780F      
#define OLIVE       0x7BE0
#define SILVER      0xad75   // 0xafafaf  
#define LIGHTGREY   0xC618      
#define DARKGREY    0x7BEF      
#define BLUE        0x001F     
#define LIGHTBLUE   0x7DFF  
#define DARKBLUE    0x3BFF
#define GREEN       0x07E0      
#define CYAN        0x07FF      
#define RED         0xF800     
#define MAGENTA     0xF81F      
#define YELLOW      0xFFE0      
#define WHITE       0xFFFF      
#define ORANGE      0xFD20      
#define GREENYELLOW 0xAFE5     
#define PINK        0xF81F

#define SHIFT_RED   11      
#define SHIFT_GREEN 5     
#define SHIFT_BLUE  0

#define SCREEN_VERTICAL_1		0
#define SCREEN_HORIZONTAL_1		1
#define SCREEN_VERTICAL_2		2
#define SCREEN_HORIZONTAL_2		3

//void WF52QTL_Init(void);
//void WF52QTL_Fill_Screen(uint32_t Colour);
//void WF52QTL_Draw_Rectangle(uint16_t X, uint16_t Y, uint16_t Width, uint16_t Height, uint32_t Colour);
//void WF52QTL_Draw_Horizontal_Line(uint16_t X, uint16_t Y, uint16_t Width, uint32_t Colour);
//void WF52QTL_Draw_Vertical_Line(uint16_t X, uint16_t Y, uint16_t Height, uint32_t Colour);
//
//void WF52QTL_Draw_Pixel(uint16_t X,uint16_t Y,uint16_t Colour);
//void WF52QTL_Draw_Picture(uint8_t *buf, uint16_t X0, uint16_t X1, uint16_t Y0, uint16_t Y1);


//void Bresenham(uint16_t Color, uint16_t x0, uint16_t y0, uint16_t x, uint16_t y);   // ??

#endif

