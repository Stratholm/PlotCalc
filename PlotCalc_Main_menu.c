// PlotCalc.c
/*Programm calculates arithmetical equasions, bulds plots*/

#include "PlotCalc_Head.h"
#include "Graph_Head.h"

int main()
{
    screen_first_init();
	database_func = func_init(database_func);
	database_const = const_init(database_const);
	vars = vars_init(vars);
	//sym_allow_init(sym_allow);
	while (e == 0)
	{
///////////////////////////////////////////////////////////
		while (i <= awruk_size)     //Input
		{
			interface_main(Pointer_ariph, string, M, &ariph_list, &plots, vars);
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
						int tmp_i = 0;
						Note* tmp_R = plots.head;
						//LineTo(hdc,tmp_i+2,(Plot*)(tmp_R->data)->coord[tmp_i+1]);
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
					switch(message = string_analyse(string, Pointer_ariph, database_func, database_const, vars, var_amount))
					{
					case ARIPH:
					{
						message = 0;
						message = str_to_inf(&ariph, string, database_func, database_const, vars, var_amount);
						if (message == 0)
						{
							postfix = inf_to_post(&ariph);
						}
						else
							continue;
						//check -> calculate
					}
					case FUNC:
					{
						//printf("Lol");
						//check -> add
					}
					case VAR:
					{
						//check -> add
					}
					case ERR_EMPTY:
					{
						//print, mess = ERR_EMPTY
					}
					case ERR_SPEC:
					{
						//print, mess = ERR_SPEC
					}
					case ERR_EQUAS:
					{
						//print, mess = ERR_EQUAS
					}
					case 0:
					{
						string[0] = '\0';
						Pointer_ariph = NULL;
						continue;
					}
					}
					//queue_create(&ariph);
					/*if (str_to_inf(&ariph, string, database_func, database_const, vars))
						string[0] = '\0';
					else string[0] = 'E';*/
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
						{
							Pointer_ariph = NULL;
							string[0] = '\0';
							i = 0;
							string[i] = c;
							i++;
						}
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



 //(+ &message) (char *message);
			/*
			output all the stuff from lists, then:
			if pointer == null
			{
				if message == 0
				{
					print string after >
				}
				else
				{
					if string is emty, print message after >
					else
					print under it, in the place of 'Answer:'
				}
			}
			else
			{
				print string and answer from a pointer
			}
			*/

















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
