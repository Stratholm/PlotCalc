#pragma once

/*Includes*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*Structures*/
//Pointer
typedef void* Point;

//Single note
typedef struct Note
{
	struct Note *prev, *next;
	Point data;
	int num;
} Note;

//Single queue
typedef struct List
{
    Note *head, *tail;
	int amount;
} List;

/*Main Variables*/

/*Functions*/
//Create queue
void queue_create(List* queu);

//Add element in the end
void queue_add_end(List *queu, Point el);

//Delete element
int queue_el_del(List *queu, int num);

//Go forward
void queue_qo_fwd(List *queu, Note *Point);

//Go back
void queue_go_back(List *queu, Note *Point);

//Renumber all notes
int queue_renum(List* queu);