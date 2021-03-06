#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "PlotCalc_Head.h"

/* Functions */
//Input string to infix notation
int str_to_inf(List* lt, char* in, Dbase* fc, Dbase* ct, Dbase* vr, int var_amount, int mess, double M, int* symbol);

//Queue to postfix
List* inf_to_post(List* inf);

//Calculate postfix
double post_calc(List* post, double* ans, int* coord, int* mess, double resz, int up, int right);

//Transfers answer to the rational form
Rat_num* ans_to_rat(double ans);

//Finds closest lexems
int lexem_find(int* smb, char* in, List* lt, Dbase* db, int amount, int mode);

//Create new Element
Element* element_create(char key, double data);

//Create new Ariph
Ariph* ariph_create(char* string, double ans);

//Create new Plot
Plot* plot_create(char* string, List* post, int* coord);

//Copies list of elements
List* queu_el_copy(List* in);

//Extract element key
char key(Note* el);

//Extract element data
double data(Note* el);

//Rewrite element key
void ins_key(Note* el, char in);

//Rewrite element data
void ins_data(Note* el, double in);

//ctg
double ctg(double in);