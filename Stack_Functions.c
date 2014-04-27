/*Includes*/
#include "Stack_Head.h"

/*Main variables defenition*/
int default_size = 4;
int user_size = 4;
int user_increment = 2;
Stack st;

/*Functions*/

/*Create empty stack*/
void stack_create(Stack* st, int user_size)
{

	st->sk = (point*)malloc(user_size*sizeof(int));
	st->len = 0;
	st->size = user_size;
}

/*Resize stacks*/
int stack_resize(Stack *st, int user_size, int user_increment, int default_size)
{
	int a = 0, sz, i;
	if (st->len != 0 || st->size > default_size)
	if (st->len == st->size)
		a = 1;
	else
	if (2*user_increment*st->len < st->size)
		a = 2;
	else
		return 0;
	if (a == 1)
	{
		point* s_new = (point*)malloc(st->size*sizeof(int));
		for (i = 0; i < st->len; i++)
		{
			s_new[i] = st->sk[i];
		}
		sz = st->len;
		stack_create(st, user_size);
		st->len = sz;
		for (i = 0; i < sz; i++)
		{
			st->sk[i] = s_new[i];
		}
		return 1;
	}
	if (a == 2)
	{
		point* s_new = (point*)malloc(st->len*sizeof(int));
		for (i = 0; i <= st->len; i++)
		{
			s_new[i] = st->sk[i];
		}
		sz = st->len;
		stack_create(st, st->size/user_increment);
		st->len = sz;
		for (i = 0; i <= sz; i++)
		{
			st->sk[i] = s_new[i];
		}
		return 1;
	}
	return 0;
}

/*Delete stack*/
void stack_destroy(Stack* st)
{
	if (st->sk == NULL)
	{
		printf("There is nothing to delete!\n");
		getch();
	}
	else
	{
	st->len = 0;
	st->size = 0;
	free(st->sk);
	st->sk = NULL;
	printf("Stack has been deleted!\n");
	}
}

/*Show stack size*/
void stack_size(Stack *st)
{
	printf("Stack current size: %d\n", st->len);
	getch();
}

/*Push elememnt*/
void stack_push(Stack *st, int user_size, int user_increment, int default_size)
{
	point val;
	if (st->sk == NULL)
	{
		printf("There is no stack!\n");
		getch();
	}
	else
	{
		if (st->len != 0)
		if (stack_resize(st, user_size, user_increment, default_size))
		{
			printf("Stack has been resized to %d\n", st->size);
		}
		printf("Enter the value\n");
		scanf("%d", &val);
		st->sk[st->len] = val;
		st->len++;
		printf("Element %d has been added\n", val);
		getch();
	}
}

/*Pop element*/
void stack_pop(Stack *st, int user_size, int user_increment, int default_size)
{		
	if (st->sk == NULL)
	{
		printf("There is no stack!\n");
		getch();
	}
	else
		if (st->len == 0)
	{
		printf("There are no elements!\n");
		getch();
	}
	else
	{
		if (st->len != 0)
		if (stack_resize(st, user_size, user_increment, default_size))
		{
			printf("Stack has been resized to %d\n", st->size);
		}
		printf("Element: %d\n", st->sk[st->len-1]);
		st->len--;
		getch();
	}
}

/*Peek element*/
void stack_peek(Stack *st)
{
	if (st->sk == NULL)
	{
		printf("There is no stack!\n");
		getch();
	}
	else
		if (st->len == 0)
	{
		printf("There are no elements!\n");
		getch();
	}
	else
	{
		printf("Element: %d\n", st->sk[st->len-1]);
		getch();
	}
}

/*Show memory usage*/
void mem_size(Stack *st)
{
	printf("Memory used: %d\n", st->size);
	getch();
}

/*Stack settings*/
void stack_settings(char c, int* user_size, int* user_increment, int* e)
{
	int val = 0;
	if (c != '1' && c != '2')
		return;
	system("cls");
	if (c == '1')
	{
	printf("Current default size: %d\n", *user_size);
	printf("Enter new value (>=1)\n");
	scanf("%d", &val);
	if (val < 1)
	{
		*e++;	
		return;
	}
	*user_size = val;
	system("cls");
	printf("Default size has been changed to: %d\n", *user_size);
	}
	else
	{
		printf("Current increment: %d\n", *user_increment);
		printf("Enter new value (>=2)\n");
		scanf("%d", &val);
		if (val <= 1)
		{
			*e++;
			return;
		}
		*user_increment = val;
		system("cls");
		printf("Increment has been changed to: %d\n", *user_size);
	}
}
