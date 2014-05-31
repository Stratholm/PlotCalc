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
			interface_main(Pointer_ariph, string, M, &ariph_list, &plot, vars);
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
					switch(c = getch())
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
						Note* tmp_R = plot.head;
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
						double ans = 0;
						message = 0;
						message = str_to_inf(&ariph, string, database_func, database_const, vars, var_amount, ARIPH);
						if (message == 0)
						{
							postfix = inf_to_post(&ariph);
							if (postfix != NULL)
							{
								post_calc(postfix, &ans, coordinates, ARIPH);
								queue_add_end(&ariph_list, ariph_create(string, ans));
								if (ariph_list.amount > ariph_height)
								{
									queue_el_del(&ariph_list, 1);
									queue_renum(&ariph_list);
								}
								Pointer_ariph = ariph_list.tail; 
							}
							else
								message = ERR_BR;
						}
						else
							continue;
						continue;
					}
					case FUNC:
					{
						double ans = 0;
						message = 0;
						message = str_to_inf(&plot, string, database_func, database_const, vars, var_amount, FUNC);
						if (message == 0)
						{
							postfix = (List*)malloc(sizeof(List));
							postfix = inf_to_post(&plot);
							if (postfix != NULL)
							{
								post_calc(postfix, &ans, coordinates, FUNC, resize, push_up, push_right);
								queue_add_end(&plot_list, plot_create(string, postfix, coordinates));
								if (plot_list.amount > plot_height)
								{
									queue_el_del(&plot_list, 1);
									queue_renum(&plot_list);
								}
								graph_draw_asix(push_right, push_up);
								graph_draw_graps(plot_list);
								while ((c = getch()) != esc)
								{
									switch(c)
									{
									case esc:
										break;
									case arr_up:
										{
											push_up++;
											Pointer_plots = plot_list.head;
											while (Pointer_plots != NULL)
											{
												post_calc(&(((Plot*)(Pointer_plots->data))->postfix), &ans, ((Plot*)(Pointer_plots->data))->coord, FUNC, resize, push_up, push_right);
												Pointer_plots = Pointer_plots->next; 
											}
											graph_draw_asix(-push_right, -push_up);
											graph_draw_graps(plot_list);
											continue;
										}
									case arr_down:
										{
											system("cls");
											push_up--;
											Pointer_plots = plot_list.head;
											while (Pointer_plots != NULL)
											{
												post_calc(&(((Plot*)(Pointer_plots->data))->postfix), &ans, ((Plot*)(Pointer_plots->data))->coord, FUNC, resize, push_up, push_right);
												Pointer_plots = Pointer_plots->next; 
											}
											graph_draw_asix(-push_right, -push_up);
											graph_draw_graps(plot_list);
											continue;
										}
									case arr_right:
										{
											system("cls");
											push_right++;
											Pointer_plots = plot_list.head;
											while (Pointer_plots != NULL)
											{
												post_calc(&(((Plot*)(Pointer_plots->data))->postfix), &ans, ((Plot*)(Pointer_plots->data))->coord, FUNC, resize, push_up, push_right);
												Pointer_plots = Pointer_plots->next; 
											}
											graph_draw_asix(-push_right, -push_up);
											graph_draw_graps(plot_list);
											continue;
										}
									case arr_left:
										{
											push_right--;
											Pointer_plots = plot_list.head;
											while (Pointer_plots != NULL)
											{
												post_calc(&(((Plot*)(Pointer_plots->data))->postfix), &ans, ((Plot*)(Pointer_plots->data))->coord, FUNC, resize, push_up, push_right);
												Pointer_plots = Pointer_plots->next; 
											}
											graph_draw_asix(-push_right, -push_up);
											graph_draw_graps(plot_list);
											continue;
										}
									case '+':
										{
											resize *= 2;
											Pointer_plots = plot_list.head;
											while (Pointer_plots != NULL)
											{
												post_calc(&(((Plot*)(Pointer_plots->data))->postfix), &ans, ((Plot*)(Pointer_plots->data))->coord, FUNC, resize, push_up, push_right);
												Pointer_plots = Pointer_plots->next; 
											}
											graph_draw_asix(-push_right, -push_up);
											graph_draw_graps(plot_list);
											continue;
										}
									case '-':
										{
											resize /= 2;
											Pointer_plots = plot_list.head;
											while (Pointer_plots != NULL)
											{
												post_calc(&(((Plot*)(Pointer_plots->data))->postfix), &ans, ((Plot*)(Pointer_plots->data))->coord, FUNC, resize, push_up, push_right);
												Pointer_plots = Pointer_plots->next; 
											}
											graph_draw_asix(-push_right, -push_up);
											graph_draw_graps(plot_list);
											continue;
										}
									}
									
								}
							}
							else
								message = ERR_BR;
						}
						else
							continue;
						continue;
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
					if (i > 0)
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

/*
        while ((note->num != num) && (note!=queu->tail))
			note = note->next;
        if ((note->num != num) && (note == queu->tail))
			return 0;
			remover = note;
        if (note != queu->tail)
			{
				note->next->prev = note->prev;
				note->prev->next = note->next;
			}	
        else 
			{
				note->next = NULL;
				queu->tail = note->prev;
			}
        if (note != queu->head)
			note->prev->next=note->next;
        else queu->head=note->next;
        free(remover);
		queu->amount--;
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
