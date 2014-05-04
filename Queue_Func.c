#pragma once

/*Includes*/
#include "Queue_Head.h"
#include "PlotCalc_Head.h"

/*Functions*/
//Create queue
void queue_create(List* queu)
{
	queu->head = NULL;
	queu->tail = NULL;
	queu->amount = 0; 
}
/*
//Create Note
void note_create(Note* note)
{
	Note note = (Note)malloc(sizeof(Note));
    note->next = NULL;
    note->prev = NULL;
	note->data = NULL;
}
*/
//Add element in the end
void queue_add_end(List *queu, Point el)
{
    Note *note = (Note*)malloc(sizeof(Note));
    note->next = NULL;
    note->prev = queu->tail;
	note->data = el;
	note->num = note->prev->num++;
    if (queu->head == NULL) 
		queu->head = note;
    if (queu->tail != NULL)
		queu->tail->next = note;
    queu->tail = note;
}

//Delete element
int queue_el_del(List *queu, int num)
{
	if (queu->head != NULL)
	{
		Note *point = (Note*)malloc(sizeof(Note));
		if (num != queu->head->next->num)
		{
			point = point->next;
			if (point != NULL)
			{
				queue_el_del(queu, num);
			}
			else
				return 0;
		}
		point->prev->next = point->next;
		return 1;
	}
	else 
		return 0;
}

//Go forward
void queue_qo_fwd (List *queu, Note *point)
{
    if (point->next != NULL)
		point = point->next;
}

//Go back
void queue_go_back(List *queu, Note *point)
{
    if (point->prev != NULL)
		point = point->prev;
}
