// PlotCalc.c
/*Programm calculates arithmetical equasions, bulds plots*/

#include "PlotCalc_Head.h"

int main()
{
	queue_create(&plots);
	queue_create(&ariph);
	queue_create(&vars);
	while (exit == 0)
	{
///////////////////////////////////////////////////////////
		if (&Pointer_ariph == NULL)
		{
			while (i<=awruk_size)     //Input
			{
				switch(c = getche())
				{
					case 13:          //Enter
					{
						str_to_inf(string);
					}
					case 8:           //Backspace
					{
						string[i] = '\0';
						i--;
						interface_main(string, m);
					}
					case 27:          //Esc
					{
						interface_exit();
						switch(getche())  //Check
						{
							case 13:
							{
						
								exit = 1;
								return 1;
							}
						}
					}
					case 32:		  //Space
					{

					}

				}
			}
		}
		else
		{
			switch(c = getche())
			{
				case 13:          //Enter
				{
					Pointer_plots = NULL;
					continue;
				}
				case 27:          //Esc
				{
					interface_exit();
					switch(getche())  //Check
					{
						case 13:
						{
						
							exit = 1;
							return 1;
						}
					}
				}
				case 112:         //F1
				{
					interface_help_main();
					continue;
				}
				case 32:          //Space
				{

				}
				case 18:          //Alt
				{

				}
				case 46:          //Del
				{

				}
				case 9:           //Tab
				{

				}
			}
		}

///////////////////////////////////////////////////////////
	}
}
