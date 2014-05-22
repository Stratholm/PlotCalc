#ifndef CC_H
#define CC_H

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include "PlotCalc_Head.h"

/* Functions */
//Input string to infix notation
List str_to_inf(char* in, Dbase* fc, Dbase* ct, Dbase* var);

//Queue to postfix
List* inf_to_post(List* inf);

//Calculate postfix
double post_calc(List* post);

//Transfers answer to the rational form
Rat_num* ans_to_rat(double ans);

//Finds closest lexems
int lexem_find(unsigned int* smb, char* in, List* lt, Dbase* db, int amount, int mode);

#endif