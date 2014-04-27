/*Includes*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct _Stack Stack;

/*Main variables declaration*/
extern int user_size;
extern int user_increment;
extern int default_size;
extern Stack st;

/*Functions*/

/*Pointer*/
typedef void* point;

/*Stack structure*/
typedef struct _Stack 
{
	point* sk;
	int len, size;    
} Stack;

/*Create empty stack*/
void stack_create(Stack* st, int user_size);

/*Resize stacks*/
int stack_resize(Stack* st, int user_size, int user_increment, int default_size);

/*Delete stack*/
void stack_destroy(Stack* st);

/*Show stack size*/
void stack_size(Stack* st);

/*Push elememnt*/
void stack_push(Stack *st, int user_size, int user_increment, int default_size);

/*Pop element*/
void stack_pop(Stack *st, int user_size, int user_increment, int default_size);

/*Peek element*/
void stack_peek(Stack* st);

/*Show memory usage*/
void mem_size(Stack* st);

/*Stack settings*/
void stack_settings(char c, int* user_size, int* user_increment, int* e);
