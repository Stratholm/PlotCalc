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

#define awruk_size 99
#define plot_amount 16
#define var_amount 16
#define width 800
#define height 600

#define enter 13
#define backspace 8
#define esc 27
#define space 32
#define F1 112
#define alt 18
#define del 46
#define tab 9
#define up 38
#define down 40

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

//Ariphmetical equasions
typedef struct Ariph
{
	char string[awruk_size];
	double ans;
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

//Rational form
typedef struct Rat_num
{
	double val;
	int pow;
} Rat_num;

/*Functions*/
//Input string to infix notation
List* str_to_inf(char* in);

//Queue to postfix
List* inf_to_post(List* inf);

//Calculate postfix
double post_calc(List* post);

//Transferes answer to the rational form
Rat_num ans_to_rat(double ans);

//Open sessinon to save
int session_open();

//Save plot
int plot_save(Note* point);

//Close session of storage
int session_close(List* ariph, List* var);

//Exit screen
void interface_exit();

//(Main/ariph count) screen  help
void interface_help_main();

//Analyse string and calculate/save/build
int string_analyse(char* str, Note* point);