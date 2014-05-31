//Graph_Head.h - a header, which works with graphics. Sakuya is best. Lunars - fuck yourself.

/*Includes*/
#pragma once
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "PlotCalc_Head.h"


/*Structures*/
extern const int NotUsed; //default colors

/*External Variables*/
extern HDC hdc; //console

/*Functions*/
//First Buffer Initialize
void screen_first_init();

//Clear Screen
void screen_clear();

//creates frame
void screen_frame_create();

//Main console initialization
void interface_main(Note* point, char *str, double M, List* ariph, List* plots, Dbase* vars);

//Drawing asix
void graph_draw_asix(int right, int up);

//Drawing graphs
void graph_draw_graps(List plots);

//Exit screen
void interface_exit();

//(Main/ariph count) screen  help
void interface_help_main();

//Plots screen help
void interface_help_plots();

//Variables list
void interface_list_vars(Dbase* var);

//Plots list
void interface_list_plots(List* plot);

