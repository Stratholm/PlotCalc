// PlotCalc.c
/*Programm calculates arithmetical equasions, bulds plots*/

#include "PlotCalc_Head.h"

int main()
{
    screen_first_init();
	database_func = func_init(database_func);
	queue_create(&vars);
	queue_create(&plots);
	while (e == 0)
	{
///////////////////////////////////////////////////////////
		if (Pointer_ariph == NULL)
		{
			while (i<=awruk_size)     //Input
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
						printf("\a");
						string_analyse(string, Pointer_ariph, &ariph);
						queue_create(&ariph);
						ariph = str_to_inf(string, database_func);
						answer = ((Element*)(ariph.head->data))->data;
						printf("%f", answer);
						/*answer = ((Element*)(ariph.head->next->data))->data;
						printf("%f", answer);*/
						continue;
					}
					case backspace:           //Backspace
					{
						if (i>0)
						i--;
						string[i] = '\0';
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
						if (M !=0)
						string[i] = 'M';
						i++;
						continue;
					}
					default:
					{
					string[i] = c;
					i++;
					}
				}
			}
		}
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
					interface_list_vars(&vars);
					continue;
				}
			}
		}

///////////////////////////////////////////////////////////
	}
}
