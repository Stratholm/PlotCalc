// PlotCalc.c
/*Programm calculates arithmetical equasions, bulds plots*/

#include "PlotCalc_Head.h"
#include "computation_core_head.h"

int main()
{
	Element el1, el2, el3;
    screen_first_init();
	database_func = func_init(database_func);
	database_const = const_init(database_const);
	vars = vars_init(vars);
	/*queue_create(&ariph);
	el1.data = 1;
	el2.data = 2;
	el3.data = 3;
	queue_add_end(&ariph, &el1);
	queue_add_end(&ariph, &el2);
	queue_add_end(&ariph, &el3);*/
	//queue_create(&vars);
	queue_create(&plots);
	while (e == 0)
	{
///////////////////////////////////////////////////////////
		while (i <= awruk_size)     //Input
		{
			interface_main(Pointer_ariph, string, M);
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
					double answer = 0;
					string_analyse(string, Pointer_ariph, &ariph);
					//queue_create(&ariph);
					if (str_to_inf(&ariph, string, database_func, database_const, vars) == 1)
						string[0] = '\0';
					else string[0] = 'E';
					if (ariph.amount  = 3)
						answer = ((Element*)(ariph.head->data))->data + ((Element*)(ariph.head->next->data))->data + ((Element*)(ariph.head->next->next->data))->data;// + ((Element*)(ariph.head->next->next->next->data))->data;
					for (i = 0; i < answer; i++)
					{
						printf("\a");
					}
					continue;
				}
				case backspace:           //Backspace
				{
					if (i>0)
					{
						i--;
						string[i] = '\0';
					}
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
				default:
				{
					string[i] = c;
					i++;
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