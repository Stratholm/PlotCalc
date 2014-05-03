// PlotCalc.c
/*Programm calculates arithmetical equasions, bulds plots*/

#include "PlotCalc_Head.h"
#pragma once

void main()
{
	while (e == 0)
	{
		int c = 0;

		system("cls");
		printf(">");
		switch(c = getche())
		{
			case 72:          
			{
				system("cls");
				printf("Ra~wr :3");
				continue;
			}
			case '2':       
			{
				Stack stck;
				Element el, *ol;
				double hui;
				el.data = 1.0;
				system("cls");
				stack_create(&stck, 16);
				stack_push(&stck, &el);
				hui = stck.sk[0].data;
				printf("%f", hui);
				getch();
				continue;
			}
			case '3':         
			{
				system("cls");
				continue;
			}
			case '4':       
			{
				system("cls");
				continue;
			}
			case '5':         
			{
				system("cls");
				continue;
			}
			case '6':        
			{
				system("cls");
				continue;
			}
			case '7':         
			{
				system("cls");
				continue;
			}
			case '8':          
			{
				system("cls");
				continue;
			}
			case 27:          //Exit
			{
				e = 1;
				system("cls");
				printf("Good night, rachye!");
				return;
			}
		}
	}
}
