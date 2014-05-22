//Graph_Head.h - a header, which works with graphics. Sakuya is best. Lunars - fuck yourself.

/*Includes*/
#define _WIN32_WINNT 0x0500
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "PlotCalc_Head.h"
#pragma once

/*Structures*/
extern const int NotUsed; //default colors

/*External Variables*/
extern HDC hdc; //console

/*Functions*/
//First Buffer Initialize
void screen_first_init();

//Clear Screen
void screen_clear();

//Main console initialization
void interface_main(Note* point, char *str, double M);

//Drawing asix
int Graph_Draw_Asix(int right, int up);

//Exit screen
void interface_exit();

//(Main/ariph count) screen  help
void interface_help_main();

//Plots screen help
void interface_help_plots();

//Variables list
void interface_list_vars(List* vars);

//Plots list
void interface_list_plots(List* plot);
