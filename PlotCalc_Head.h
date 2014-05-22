#ifndef PC_H
#define PC_H

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
//#include "computation_core_head.h"

#define awruk_size 99
#define plot_amount 16
#define const_amount 16
#define var_amount 16
#define func_amount 2
#define width 800
#define height 600

#define enter 13
#define backspace 8
#define esc 27
#define space 32
#define F1 59	//double with first 0
#define alt 18	//OOO
#define del 83	//double with first -32
#define tab 9
#define arr_up 72	//double with first -32
#define arr_down 80	//double with first -32
#define arr_right 77	//double with first -32
#define arr_left 75	//double with first -32
#define shift 16	//OOO
#define insert 82	//double with first -32
#define switch_key 224

#define NUM 1
#define FUNC 2
#define CONST 3
#define VAR 4

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


typedef struct Dbase
{
	char name[8];
	double data;
} Dbase;

/*Main variables declaration*/
extern int e;
extern double ans;
extern double M;
extern char c;
extern char string[awruk_size];
extern int i;
extern List plots;
extern List ariph;
extern Note* Pointer_plots;
extern Note* Pointer_ariph;
extern Note* Pointer_vars;
extern Dbase* database_func;
extern Dbase* database_const;
extern Dbase* vars;

/*Functions*/
//Open session to save
int session_open();

//Save plot
int plot_save(Note* point);

//Close session of storage
int session_close(List* ariph, List* var);

//Analise string and calculate/save/build
int string_analyse(char* str, Note* point, List *ariph);

//Initialise database
Dbase* func_init(Dbase* fc);

#endif