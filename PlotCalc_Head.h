#pragma once

/*Includes*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <assert.h>
#include "Queue_Head.h"

#define awruk_size 86
#define plot_amount 11
#define var_max_amount 7
#define const_amount 2
#define func_amount 14
#define sym_allow_quant 72
#define dbase_name_len 8
#define screen_width 800
#define screen_height 600
#define ariph_height 7
#define plot_height 11
#define cell 50

#define enter 13
#define backspace 8
#define esc 27
#define space 32
#define F1 58
#define alt -30
#define del 127
#define tab 9
#define arr_up 59
#define arr_down 60
#define arr_right 62
#define arr_left 61
#define insert 63

#define NUM 1
#define FUNC 2
#define CONS 3
#define ARIPH 4
#define VAR 5
#define LB 6
#define RB 7
#define ERR_EMPTY 8
#define ERR_CONST 9
#define ERR_SPEC 10
#define ERR_EQUAS 11
#define VAR_RE 12
#define ERR_LEX 13
#define ERR_FRAC 14
#define ERR_BR 15
#define X_VAR 16
#define ERR_ZERO_DIV 17
#define ERR_NEG_DEG 18
#define ERR_NEG_LN 19
#define ERR_NEG_ROOT 20
#define ERR_CTG 21
#define ERR_TAN 22
#define ERR_LONG_VAR 23
#define ERR 24

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
	int coord[screen_width];
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
extern int symbol;
extern List plot_list;
extern List ariph;
extern List plot;
extern List* postfix;
extern List ariph_list;
extern Note* Pointer_plots;
extern Note* Pointer_ariph;
extern Note* Pointer_vars;
extern Dbase* database_func;
extern Dbase* database_const;
extern Dbase* vars;
extern int sym_allow[sym_allow_quant];
extern int var_amount;
extern int coordinates[screen_width];
extern int push_right;
extern int push_up;
extern double resize;


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

//Recalculate plots
 plots_recalc(List* plot_list, double* ans, int* coord, int* mess, double resz, int up, int right);

//Delete all history
int recent_del(List* ariph, List* plot, Dbase* var, Note* point, int* var_amount);

//
////Initialize allowed symbols
//void sym_allow_init(int* sm);
