/*Includes*/
#include "Queue_Head.h"
#include "PlotCalc_Head.h"

/*Functions*/
//Create queue
void queue_create(List* queu)
{
	//queu = (List*) malloc(sizeof(List));
	queu->head = NULL;
	queu->tail = NULL;
	queu->amount = 0;
}

//Add element in the end
void queue_add_end(List *queu, Point el)
{
    Note *note = (Note*)malloc(sizeof(Note));
    note->next = NULL;
	if (queu->head == NULL)
	{
		queu->head = note;
		queu->tail = note;
		note->prev = NULL;
		note->next = NULL;
		note->num = 1;
		queu->amount = 1;
		note->data = el;
	}
	else
	{
		note->prev = queu->tail;
		queu->tail->next = note;
		queu->tail = note;
		note->data = el;
		note->num = note->prev->num + 1;
		queu->amount++;
		/*if (queu->tail != NULL)
			queu->tail->next = note;
		queu->tail = note;*/
	}
}

//Delete element
int queue_el_del(List *queu, int num)
{
    //Note* remover = (Note*)malloc(sizeof(Note));
    Note* note = (Note*)malloc(sizeof(Note));
    note = queu->head;
    if (queu->head != NULL)
    {
		while ((note->num != num) && (note != NULL))
			note = note->next;
		if (note == NULL) 
			return 0;
		if (queu->head == queu->tail)
			{
				queu->head = NULL;
				queu->tail = NULL;
				queu->amount--;
				queue_renum(queu);
				return 1;
			}
		if (note == queu->head)
		{
			queu->head = note->next;
			note->next->prev = NULL;
			queu->amount--;
			queue_renum(queu);
			return 1;
		}
		if (note == queu->tail)
		{
			note->prev->next = NULL;
			queu->tail = note->prev;
			queu->amount--;
			queue_renum(queu);
			return 1;
		}
		else
		{
			note->next->prev = note->prev;
			note->prev->next = note->next;
			queu->amount--;
			queue_renum(queu);
			return 1;
		}
    }
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

//Renumber all notes
int queue_renum(List* queu)
{
	Note* note = (Note*)malloc(sizeof(Note));
    note = queu->head;
    if (queu->head != NULL)
    {
		queu->head->num = 1;
		note = note->next;
		while ((note != NULL))
		{
			note->num = note->prev->num + 1;
			note = note->next;
		}
		return 1;
	}
	return 0;
}