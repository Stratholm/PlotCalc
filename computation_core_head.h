#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include "PlotCalc_Head.h"
#include "Queue_Head.h"

/* Functions */
//Input string to infix notation
List* str_to_inf(char* in);

//Queue to postfix
List* inf_to_post(List* inf);

//Calculate postfix
double post_calc(List* post);
/*
//Transfers answer to the rational form
Rat_num ans_to_rat(double ans);
*/
