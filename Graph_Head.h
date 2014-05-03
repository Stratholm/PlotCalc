//Graph_Head.h - a header, which works with graphics. Sakuya is best. Lunars - fuck yourself.

/*Includes*/
#define _WIN32_WINNT 0x0500
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#pragma once

/*Structures*/
extern const int NotUsed; //default colors

/*External Variables*/
extern HWND hWnd; //Console window
extern HANDLE hStdOut; //Console Buffer
extern HDC hdc; //console

/*Functions*/
//Main console initialization
int Graph_Init_Console(char *Str);

//Drawing asix
int Graph_Draw_Asix(int right, int up);

