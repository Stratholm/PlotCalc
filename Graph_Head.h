//Graph_Head.h - a header, which works with graphics. Sakuya is best. Lunars - fuck yourself.

/*Includes*/
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <SDL2/SDL.h>           //for graphics
#include <SDL2/SDL_ttf.h>       //for text
#include "PlotCalc_Head.h"


/*Structures*/
extern SDL_Window *win;         //a window
extern SDL_Renderer *ren;       //drawing in the window
extern TTF_Font *font;          //fonts
extern SDL_Color textColor;

/*Functions*/
//First Buffer Initialize
void screen_first_init();

//Clear Screen
void screen_clear();

//creates frame
void screen_frame_create();

//print in sdl
void print_graph(char* Str, int tmX, int tmY);

//Main window initialization
void interface_main(Note* point, char *str, double M, List* ariph, List* plots, Dbase* vars,int message);

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

//SDL turns off
void graph_exit();

//Variables list
void interface_list_vars(Dbase* var);

//Plots list
void interface_list_plots(List* plot);

