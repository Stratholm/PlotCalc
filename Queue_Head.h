#pragma once

/*Includes*///
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*Structures*/
//Элемент очереди
typedef struct _note
{
	struct _note *prev, *next;
	char equas[128];
	float numb;
} _note;

//Очередь
typedef struct _list
{
    _note *head, *tail;
} _list;

/*Main Variables*/
extern int max_size;
extern _list List;

/*Functions*/
//Создание элемента в конце очереди
void Queue_Create(_list *queu, float val, char *eq);

//Идти вперед по очереди
void Queue_Go_Fwd(_list *queu, _note *Point);

//Идти назад по очереди
void Queue_Go_Back(_list *queu, _note *Point);
