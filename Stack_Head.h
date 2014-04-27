/*Includes*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>

/*Structures*/

//Pointer
typedef void* point;

typedef struct _Stack 
{
	point* sk;
	int len, size;    
} Stack;

/*Main variables declaration*/
extern int user_size;
extern Stack st;

/*Functions*/

//Show stack size
void stack_size(Stack* st);

//Push elememnt
void stack_push(Stack *st, int user_size, int user_increment, int default_size);

//Pop element
void stack_pop(Stack *st, int user_size, int user_increment, int default_size);

//Peek element
void stack_peek(Stack* st);

//Show memory usage
void mem_size(Stack* st);

//Stack settings
void stack_settings(char c, int* user_size, int* user_increment, int* e);
