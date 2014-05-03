/*Includes*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Queue_Head.h"
#pragma once


/*Structures*/

//Pointer
typedef void* point;

//Stack
typedef struct _Stack 
{
	point* sk;
	int len, size;    
} Stack;

/*Main variables declaration*/

/*Functions*/

//Create empty stack
void stack_create(Stack* st, int size);

//Push elememnt
int stack_push(Stack* st, point* ph);

//Pop element
point stack_pop(Stack* st);

//Peek element
_list stack_peek(Stack* st);

