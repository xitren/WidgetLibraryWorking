/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   widget.h
 * Author: gusev_a
 *
 * Created on 27 июня 2018 г., 15:52
 */

#ifndef WIDGET_POLY_H
#define WIDGET_POLY_H

#include <stdint.h>
#include <stdio.h>
#include "widget.h"
//#include "visual.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifndef MARKING_UNUSED_PARAMETER
#define MARKING_UNUSED_PARAMETER(X) (void)(X)
#endif
   

typedef void (*WidgetFunction_t)(uint16_t X, uint16_t Y, 
                                uint16_t Width, uint16_t Height, 
                                uint16_t Color,
                                DrawParameterList_t* params);  
    
typedef struct _tagWidgetNameRelativeTableRecord_t {
    char*                    type_name;
    WidgetFunction_t         relative_function;
    WidgetFunction_t         relative_dynamic_function;
} WidgetNameRelativeTableRecord;


typedef struct _UserSettings_t {
    uint8_t       year;
    uint8_t       month;
    uint8_t       day;
    uint8_t       date;
    uint8_t       hour;
    uint8_t       min;
    uint8_t       tch_fix;
    uint8_t       tch_pass;
    uint8_t       tch_adapt;
} UserSettings_t;

UserSettings_t UserSettings; 

uint32_t rgb565_to_rgb888(uint16_t rgb565);
uint16_t rgb888_to_rgb565(uint32_t rgb888);

WidgetFunction_t findDrawFunction(char* class_name);
WidgetFunction_t findDynamicDrawFunction(char* class_name);

void Draw_Arrow(uint16_t X, uint16_t Y, 
                uint16_t Width, uint16_t Height, uint16_t Color,
                DrawParameterList_t* params);

void Draw_Clock(uint16_t X, uint16_t Y, 
                uint16_t Width, uint16_t Height, uint16_t Color,
                DrawParameterList_t* params);

void Draw_Button(uint16_t X, uint16_t Y, 
                uint16_t Width, uint16_t Height, uint16_t Color,
                DrawParameterList_t* params);

void Draw_ButtonUp(uint16_t X, uint16_t Y, 
                uint16_t Width, uint16_t Height, uint16_t Color,
                DrawParameterList_t* params);

void Draw_ButtonDown(uint16_t X, uint16_t Y, 
                uint16_t Width, uint16_t Height,  uint16_t Color,
                DrawParameterList_t* params);

void Draw_ButtonLeft(uint16_t X, uint16_t Y, 
                uint16_t Width, uint16_t Height,  uint16_t Color,
                DrawParameterList_t* params);

void Draw_ButtonUpTre(uint16_t X, uint16_t Y,
        uint16_t Width, uint16_t Height, uint16_t Color,
        DrawParameterList_t* params);

void Draw_ButtonDownTre(uint16_t X, uint16_t Y,
        uint16_t Width, uint16_t Height, uint16_t Color,
        DrawParameterList_t* params);

void Draw_Time(uint16_t X, uint16_t Y, 
                uint16_t Width, uint16_t Height, uint16_t Color,
                DrawParameterList_t* params);

void Draw_Date(uint16_t X, uint16_t Y, 
                uint16_t Width, uint16_t Height, uint16_t Color,
                DrawParameterList_t* params);

void Draw_Label(uint16_t X, uint16_t Y, 
                uint16_t Width, uint16_t Height,  uint16_t Color,
                DrawParameterList_t* params);

void Draw_Battery(uint16_t X, uint16_t Y, 
                uint16_t Width, uint16_t Height,  uint16_t Color, 
                DrawParameterList_t* params);

void Draw_GraphLinear2D(uint16_t X, uint16_t Y, 
                uint16_t Width, uint16_t Height,  uint16_t Color,
                DrawParameterList_t* params);

void Draw_AutoTable(uint16_t X, uint16_t Y, 
                uint16_t Width, uint16_t Height,  uint16_t Color,
                DrawParameterList_t* params);

void Draw_AutoTable_Resize(uint16_t X, uint16_t Y, 
                uint16_t Width, uint16_t Height,  uint16_t Color,
                DrawParameterList_t* params);

void Draw_TabManager(uint16_t X, uint16_t Y, 
                uint16_t Width, uint16_t Height,  uint16_t Color,
                DrawParameterList_t* params);

void Draw_DynamicField(uint16_t X, uint16_t Y, 
                uint16_t Width, uint16_t Height,  uint16_t Color,
                DrawParameterList_t* params);

void Draw_ToggleButton(uint16_t X, uint16_t Y, 
                uint16_t Width, uint16_t Height,  uint16_t Color,
                DrawParameterList_t* params);

void Draw_RollButton(uint16_t X, uint16_t Y, 
                uint16_t Width, uint16_t Height,  uint16_t Color,
                DrawParameterList_t* params);

void Draw_RollButtonH(uint16_t X, uint16_t Y,
        uint16_t Width, uint16_t Height, uint16_t Color,
        DrawParameterList_t* params);

void Draw_Engine(uint16_t X, uint16_t Y, 
                uint16_t Width, uint16_t Height,  uint16_t Color,
                DrawParameterList_t* params);


void Draw_Dialog(uint16_t X, uint16_t Y,
        uint16_t Width, uint16_t Height, uint16_t Color,
        DrawParameterList_t* params);


void ParamsChange_AutoTable(DrawObject_t *ObjectOnScene);
void ParamsChange_AutoTable_slave(DrawObject_t *ObjectOnScene);
void ParamsChange_TabManager(DrawObject_t *ObjectOnScene);
void ParamsChange_RollButton(DrawObject_t *ObjectOnScene);
void ParamsChange_Button(DrawObject_t *ObjectOnScene);
void ParamsChange_ToggleButton(DrawObject_t *ObjectOnScene);

void PointerOn_Button(DrawObject_t *ObjectOnScene);
void PointerOn_SlaveButton(DrawObject_t *ObjectOnScene);
void PointerOn_PushButton(DrawObject_t *ObjectOnScene);

void PointerOut_Button(DrawObject_t *ObjectOnScene);
void PointerEnter_Button(DrawObject_t *ObjectOnScene);
void PointerLeave_Button(DrawObject_t *ObjectOnScene);

void PointerOn_ToggleButton(DrawObject_t *ObjectOnScene);
void PointerOut_ToggleButton(DrawObject_t *ObjectOnScene);

void PointerOn_Label(DrawObject_t *ObjectOnScene);
void PointerOut_Label(DrawObject_t *ObjectOnScene);

void PointerMove_RollButton(DrawObject_t *ObjectOnScene);
void PointerMove_RollButtonH(DrawObject_t *ObjectOnScene);

#define DRAW_TABLE_SIZE 22

extern const WidgetNameRelativeTableRecord draw_table[DRAW_TABLE_SIZE];

#define NTAB    20

#ifdef __cplusplus
}
#endif

#endif /* WIDGET_POLY_H */

