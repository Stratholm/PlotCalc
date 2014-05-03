/*Includes*/
#include "Stack_Head.h"
#pragma once

/*Main variables defenition*/

/*Functions*/

//Create empty stack
void stack_create(Stack* st, int size)
{
	st->sk = (point*)malloc(size*sizeof(point));
	st->len = 0;
	st->size = size;
}

//Push elememnt
int stack_push(Stack* st, point ph)
{
	if (st->sk == NULL)
	return 0;
	else
	{
		if (st->len != 0)
		st->sk[st->len] = ph;
		st->len++;
	}
}

//Pop element
point stack_pop(Stack* st)
{		
	if ((st->sk == NULL) || (st->len == 0))
		return;
	else
		st->len--;
	return st->sk[st->len+1];
}
/*
//Peek element
_list stack_peek(Stack* st)
{		
	if ((st->sk == NULL) || (st->len == 0))
		return;
	else
	return st->sk[st->len+1];
}

*/