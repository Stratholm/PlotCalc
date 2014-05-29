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
//#include "Graph_Head.h"
//#include "computation_core_head.h"

#define awruk_size 86
#define plot_amount 16
#define var_max_amount 16
#define const_amount 1
#define func_amount 3
#define sym_allow_quant 72
#define dbase_name_len 8
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
#define CONS 3
#define ARIPH 4
#define VAR 5
#define ERR_EMPTY 6
#define ERR_CONST 7
#define ERR_SPEC 8
#define ERR_EQUAS 9
#define VAR_RE 10
#define ERR_FRAC 11

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

//Functions database
typedef struct Dbase
{
	char name[dbase_name_len];
	double data;
} Dbase;

/*Main variables declaration*/
extern int e;
extern double ans;
extern double M;
extern char c;
extern int message;
extern char string[awruk_size];
extern int i;
extern List plots;
extern List ariph;
extern List ariph_list;
extern Note* Pointer_plots;
extern Note* Pointer_ariph;
extern Note* Pointer_vars;
extern Dbase* database_func;
extern Dbase* database_const;
extern Dbase* vars;
extern int sym_allow[sym_allow_quant];
extern int var_amount;


/*Functions*/
//Open session to save
int session_open();

//Save plot
int plot_save(Note* point);

//Close session of storage
int session_close(List* ariph, List* var);

//Analise string and calculate/save/build
int string_analyse(char* str, Note* point, Dbase* fc, Dbase* ct, Dbase* vr, int var_amount);

//Initialise functions database
Dbase* func_init(Dbase* fc);

//Initialise constants database
Dbase* const_init(Dbase* ct);

//Initialise variables
Dbase* vars_init(Dbase* vr);


//
////Initialize allowed symbols
//void sym_allow_init(int* sm);