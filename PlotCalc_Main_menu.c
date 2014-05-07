// PlotCalc.c
/*Programm calculates arithmetical equasions, bulds plots*/

#include "PlotCalc_Head.h"

int main()
{
	queue_create(&ariph);
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
					case enter:          //Enter
					{
						printf("\a");
						string_analyse(string, Pointer_ariph, &ariph);
						continue;
					}
					case backspace:           //Backspace
					{
						string[i] = '\0';
						if (i>0)
						i--;
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
				case arr_up:            //Arrow up - previous
				{
					Pointer_ariph = Pointer_ariph->prev;
					continue;
				}
				case arr_down:           //Arrow down - next
				{
					Pointer_ariph = Pointer_ariph->next;
					continue;
				}
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
				case F1:         //F1
				{
					interface_help_main();
					continue;
				}
				case insert:          //insert
				{
					M = ((Ariph*)(Pointer_ariph->data))->ans;
					continue;
				}
				case del:          //Del
				{
					M = 0;
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
