/*Includes*/
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <ctype.h>
#include <assert.h>
#include <Windows.h>
#include "Stack_Head.h"

#define awruk_size 128
#define plot_size 16

/*Main variables declaration*/
extern int e;

/*Structures*/
typedef struct _element
{
	char key;
	double data;
} Element;

/*Functions*/

//Input string to infix notation
char* str_to_inf(char* in);