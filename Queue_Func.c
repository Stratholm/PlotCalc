#include "Queue_Head.h"
#include "PlotCalc_Head.h"
_list List;


/*Functions*/

//Create queue
void Queue_Create(_list* queu)
{
	queu->head=NULL;
	queu->tail=NULL;

}

//Создание элемента в конце очереди
void Queue_Creat(_list *queu, Element el)
{
    _note *note=(_note*)malloc(sizeof(_note));
    note->numb=val;
    note->next=NULL;
    note->prev=queu->tail;
    *note->equas=*eq;
    if (queu->head==NULL) queu->head=note;
    if (queu->tail!=NULL)
    queu->tail->next=note;
    queu->tail=note;
}

//Идти вперед по очереди
void Queue_Go_Fwd(_list *queu, _note *Point)
{
    if (Point->next!=NULL)
    *Point=*Point->next;
}

//Идти назад по очереди
void Queue_Go_Back(_list *queu, _note *Point)
{
    if (Point->prev!=NULL)
    Point=Point->prev;
}
