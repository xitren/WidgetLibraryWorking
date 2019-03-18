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

#ifndef WIDGET_H
#define WIDGET_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#define MAX_NUM_OF_DRAW_PARAMETERS 16
#define MAX_ID_LENGHT 16

#define POINTER_OVER   "pointerover"
#define POINTER_ENTER  "pointerenter"
#define POINTER_DOWN   "pointerdown"
#define POINTER_MOVE   "pointermove"
#define POINTER_UP     "pointerup"
#define POINTER_CANCEL "pointercancel"
#define POINTER_OUT    "pointerout"
#define POINTER_LEAVE  "pointerleave"
    
#define OBJECT_STRUCTURE        \
    uint16_t                         ID;\
    char*                            Type;\
    uint16_t                         X;\
    uint16_t                         Y;\
    uint16_t                         Width;\
    uint16_t                         Height;\
    uint16_t                         Color;\
    CallbackEventFunction_t          FunctionLink_PointerOver;\
    CallbackEventFunction_t          FunctionLink_PointerEnter;\
    CallbackEventFunction_t          FunctionLink_PointerDown;\
    CallbackEventFunction_t          FunctionLink_PointerMove;\
    CallbackEventFunction_t          FunctionLink_PointerUp;\
    CallbackEventFunction_t          FunctionLink_PointerCancel;\
    CallbackEventFunction_t          FunctionLink_PointerOut;\
    CallbackEventFunction_t          FunctionLink_PointerLeave;\
    CallbackEventFunction_t          FunctionLink_ParamsChange;\
    CallbackEventFunction_t          FunctionLink_Click;\
    DrawParameterList_t              Parameters;

typedef struct _tagDrawParameter_t
{
   char*                            strParam;
   uint32_t                         intParam;
} DrawParameter_t;

typedef struct _tagDrawParameterList_t
{
   int                              NumberofParameters;
   DrawParameter_t                  Params[MAX_NUM_OF_DRAW_PARAMETERS];
} DrawParameterList_t;

typedef struct _tagDrawObject_t DrawObject_t;

typedef uint16_t (*CRCFunction_t)(uint8_t *DATA, uint16_t N);  
typedef int (*CallbackEventFunction_t)(DrawObject_t *EventSource);  

typedef struct _tagDrawObject_t
{
   OBJECT_STRUCTURE
   uint8_t                          Draw;
   uint8_t                          DynamicDraw;
   uint8_t                          DrawDirection;
   uint16_t                         Consistancy;
} DrawObject_t;

#define DRAW_OBJECTS_SIZE 100
extern DrawObject_t ObjectsOnScene[DRAW_OBJECTS_SIZE];

void DrawObjects();
void InitObjects();
int Add_Object(char* ID, char* Type, 
        uint16_t X, uint16_t Y, 
        uint16_t Width, uint16_t Height, 
        uint16_t Colour, 
        CallbackEventFunction_t func_params_change,
        CallbackEventFunction_t func_ptrover,
        CallbackEventFunction_t func_ptrout,
        CallbackEventFunction_t func_ptrenter,
        CallbackEventFunction_t func_ptrleave,
        CallbackEventFunction_t func_ptrmove,
        CallbackEventFunction_t func_click
    );

void Clear_Objects(void);

void SetFirstVisibleIndex(char* ID);
void SetLastVisibleIndex(char* ID);
void ResetVisibleIndex(void);

uint32_t Get_Object_Size(void);

int Resize_Object(char* ID, uint16_t X_, uint16_t Y_, uint16_t Width_, uint16_t Height_);

int Set_Object_Position(char* ID, uint16_t X_, uint16_t Y_, uint16_t Width_, uint16_t Height_);
int Set_Object_Parameter(char* ID, char* strParam, uint32_t intParam);
int Get_Object_Parameter(char* ID, char* strParam);

DrawParameterList_t* Get_Object_Parameters(char* ID);

int Set_Object_Visible(char* ID);
int Set_Object_Invisible(char* ID);

int Test_Object_Type(void);
int Send_Object_Back(char* ID);
int Bring_Object_Front(char* ID);

void Add_Parameter(DrawParameterList_t* params, char* strParam, uint32_t intParam);
void Remove_Parameter(DrawParameterList_t* params, char* strParam);
int Set_Parameter(DrawParameterList_t* params, char* strParam, uint32_t intParam);
uint32_t Get_Parameter(DrawParameterList_t* params, char* strParam);

void Add_To_Screen(char *ID);
void Clear_Screen();

void checkAndCall_PointerCancel(void);
void checkAndCall_PointerDown(uint16_t X, uint16_t Y);
void checkAndCall_PointerUp(uint16_t X, uint16_t Y);
void checkAndCall_PointerOn(uint16_t X, uint16_t Y);
void checkAndCall_PointerOut(uint16_t X, uint16_t Y);
void checkAndCall_PointerOff(uint16_t X, uint16_t Y) ;
void checkAndCall_PointerEnter(uint16_t X1, uint16_t Y1,uint16_t X2, uint16_t Y2);
void checkAndCall_PointerLeave(uint16_t X1, uint16_t Y1,uint16_t X2, uint16_t Y2);
void checkAndCall_PointerMove(uint16_t X1, uint16_t Y1,uint16_t X2, uint16_t Y2);

CallbackEventFunction_t checkAndCall_Click(uint16_t ID);



#ifdef __cplusplus
}
#endif

#endif /* WIDGET_H */

