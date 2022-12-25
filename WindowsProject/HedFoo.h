#pragma once
#ifndef HEDFOO
#define HEDFOO

//#define 
//размеры окна 
#define default_window_x_pixel 800
#define default_window_y_pixel 500
#define hi_window_x_pixel 1920
#define hi_window_y_pixel 1080
#define me_window_x_pixel 960
#define me_window_y_pixel 540
#define lo_window_x_pixel 720
#define lo_window_y_pixel 405
//#define
//команды
#define IB_CM_OPEN 1
#define IB_CM_OPEN_INFO 2
#define IB_CM_DONETION 3

#define IB_CM_BUTTOM_ONE_CLIC 100

//#define
#include "framework.h"
LRESULT __stdcall WorkWindowsProcedure(HWND, UINT, WPARAM, LPARAM);
void __stdcall MainAddMenu(HWND);
void __stdcall MainAddAcshen(HWND);


#endif