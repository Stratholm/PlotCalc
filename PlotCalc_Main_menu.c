// PlotCalc.c
/*Programm calculates arithmetical equasions, bulds plots*/

#include "PlotCalc_Head.h"
#include "computation_core_head.h"

int main()
{
    screen_first_init();
	database_func = func_init(database_func);
	database_const = const_init(database_const);
	vars = vars_init(vars);
	while (e == 0)
	{
///////////////////////////////////////////////////////////
		while (i <= awruk_size)     //Input
		{
			interface_main(Pointer_ariph, string, M); //(+ &message) (char *message);
			switch(c = getche())
			{
			case 0:
			{
				switch(c = getch())
				{
				case F1:
				{
					interface_help_main();
					string[i - 1] = '\0';
					continue;
				}
				}
			}
			case -32:
				{
					switch(c=getch())
					{
						case arr_up:            //Arrow up - previous
					{
						//Pointer_ariph = Pointer_ariph->prev;
						continue;
					}
					case arr_down:           //Arrow down - next
					{
						//Pointer_ariph = Pointer_ariph->next;
						continue;
					}
					case insert:          //insert
					{
						//printf("INSERT SUCCEDED!");
						//M = ((Ariph*)(Pointer_ariph->data))->ans;
						continue;
					}
					case del:          //Del
					{
						//printf("DEL SUCCEDED!");
						//M = 0;
						continue;
					}
					}
				}
				case enter:          //Enter
				{
					//double answer = 0;
					
					switch(message = string_analyse(string, Pointer_ariph))
					{
					case ARIPH:
					{
						if (str_to_inf(&ariph, string, database_func, database_const, vars, var_amount))
						{

						}
						//check -> calculate
					}
					case FUNC:
					{
						//check -> add
					}
					case VAR:
					{
						//check -> add
					}
					case ERR_EMPTY:
					{
						//print, mess = 1
					}
					case ERR_CONST:
					{
						//print, mess = 1
					}
					case ERR_SPEC:
					{
						//print, mess = 1
					}
					case ERR_EQUAS:
					{
						//print, mess = 1
					}
					default:
					{
						string[0] = '\0';
						Pointer_ariph = NULL;
					}
					}
					//queue_create(&ariph);
					if (str_to_inf(&ariph, string, database_func, database_const, vars))
						string[0] = '\0';
					else string[0] = 'E';
					/*if (ariph.amount  = 4)
						answer = ((Element*)(ariph.head->data))->data + ((Element*)(ariph.head->next->data))->data + ((Element*)(ariph.head->next->next->data))->data + ((Element*)(ariph.head->next->next->next->data))->data;
					for (i = 0; i < answer; i++)
					{
						printf("\a");
					}*/
					continue;
				}
				case backspace:           //Backspace
				{
					if (i>0)
					{
						i--;
						string[i] = '\0';
					}
					//lol = 0
					continue;
				}
				case esc:          //Esc
				{
					interface_exit();
					switch(getche())  //Check
					{
						case enter:
						{
							e = 1;
							return 1;
						}
					}
					continue;
				}
				case space:		  //Space
				{
					if (M != 0)
					{
						string[i] = 'M';
						i++;
					}
					continue;
				}
				default:			//input
				{
					if (message == 0)
					{
					if (Pointer_ariph == NULL)
					{
						if (i < awruk_size)
						{
							string[i] = c;
							i++;
						}
					}
					else 
						Pointer_ariph = NULL;
					}
					else
					{
						message = 0;
						string[0] = '\0';
						i = 0;
						string[i] = c;
						i++;
					}
					/*
					else
						lol++;
					if lol > 5 printf(random place) one of the phrases from the array
						'Nope, stop, no more, please, 
						if lol > 15 
							'are you kidding? you wanna break me? stop right there, criminal scum, damn it'
							if lol > 30 
								'hell you, press backspace!!! you are a bad person, you know it'*/
				}
			}
		}
///////////////////////////////////////////////////////////
	}
}





















/*}
		else
		{
			interface_main(Pointer_ariph, string, M);
			switch(c = getche())
			{

				case enter:          //Enter
				{
					Pointer_ariph = NULL;
					continue;
				}
				case esc:          //Esc
				{
					interface_exit();
					switch(getche())  //Check
					{
						case enter:
						{
							e = 1;
							return 1;
						}
					}
					continue;
				}
				case tab:           //Tab
				{
					//interface_list_vars(&vars);
					continue;
				}
			}
		}*/