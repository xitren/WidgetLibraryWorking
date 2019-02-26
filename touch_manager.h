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

#ifndef TOUCH_MANAGER_H
#define TOUCH_MANAGER_H

#include <stdint.h>
#include "widget.h"

#ifdef __cplusplus
extern "C" {
#endif

#define MAX_TOUCHES_LENGHT 6

typedef enum 
{
  POINTER_STATUS_ON        = 0x00U,
  POINTER_STATUS_OUT       = 0x01U,
  POINTER_STATUS_MOVED     = 0x02U,
  POINTER_STATUS_STATIC    = 0x03U,
  POINTER_STATUS_ERROR     = 0x04U
} TouchStatusTypeDef;
    
typedef struct _tagTouchParameter_t
{
   uint16_t                         xParam;
   uint16_t                         yParam;
   uint8_t                          outParam;
} TouchParameter_t;

typedef struct _tagTouchManager_t
{
   TouchParameter_t                 touch[MAX_TOUCHES_LENGHT];
   TouchStatusTypeDef               current_mode;
} TouchManager_t;

void InitTouchManager();
void Add_Touch(uint16_t X, uint16_t Y);
TouchStatusTypeDef Get_TouchStatus();
void Cycle_Handler();

#ifdef __cplusplus
}
#endif

#endif /* TOUCH_MANAGER_H */

