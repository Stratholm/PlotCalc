#pragma once

/*Includes*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*Structures*/

//Single note
typedef struct _note
{
	struct _note *prev, *next;
} _note;

//Single queue
typedef struct _list
{
    _note *head, *tail;
} _list;

/*Main Variables*/

/*Functions*/

//Create queue
void Queue_Create(_list* queu);

//Create element in the end
void Queue_Creat(_list *queu, Element el);

//Go forward
void Queue_Go_Fwd(_list *queu, _note *Point);

//Go backwards
void Queue_Go_Back(_list *queu, _note *Point);
