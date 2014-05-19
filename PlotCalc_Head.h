#pragma once

/*Includes*/
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <ctype.h>
#include <assert.h>
#include <Windows.h>
#include "Queue_Head.h"
#include "Graph_Head.h"
#include "comutation_core_head.h"

#define awruk_size 99
#define plot_amount 16
#define var_amount 16
#define width 800
#define height 600

#define enter 13
#define backspace 8
#define esc 27
#define space 32
#define F1 59
#define alt 18
#define del 46
#define tab 9
#define arr_up 72
#define arr_down 80
#define arr_right 77
#define arr_left 75
#define shift 16
#define insert 45
#define switch_key 224

/*Main variables declaration*/
extern int e;
extern double M;
extern char c;
extern char string[awruk_size];
extern int i;
extern List plots;
extern List ariph;
extern List vars;
extern Note* Pointer_plots;
extern Note* Pointer_ariph;
extern Note* Pointer_vars;

/*Structures*/
//Universal element
typedef struct Element
{
	char key;
	double data;
} Element;

//Single plot
typedef struct Plot
{
	char string[awruk_size];
	List postfix;
	int coord[width];
	int num;
} Plot;

//Rational form
typedef struct Rat_num
{
	double val;
	int pow;
} Rat_num;

//Ariphmetical equasions
typedef struct Ariph
{
	char string[awruk_size];
	double ans;
	Rat_num rat;
} Ariph;

//Functions database
typedef struct Func
{
	char name[8];
	int prior;
} Func;

//Constants database
typedef struct Const
{
	char name[4];
	double val;
} Const;

/*Functions*/
//Open session to save
int session_open();

//Save plot
int plot_save(Note* point);

//Close session of storage
int session_close(List* ariph, List* var);

//Variables list
void interface_list_vars(List* vars);

//Analise string and calculate/save/build
int string_analyse(char* str, Note* point, List *ariph);
