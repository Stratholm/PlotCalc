// PlotCalc.c
/*Programm calculates arithmetical equasions, bulds plots*/

#include "PlotCalc_Head.h"
#include "computation_core_head.h"
#include "Graph_Head.h"


int main(int argc, char *argv[])
{
	//&symbol = (int*)malloc(sizeof(int));
    screen_first_init();					//first screen initialisation
	database_func = func_init(database_func);		//
	database_const = const_init(database_const);	//database loading
	vars_init(vars);
	while (1) interface_read();			}			//
//	while (e == 0)
//	{
/////////////////////////////////////////////////////////////
//		while (i <= awruk_size)     //Input cycle //check if string is short enough
//		{
//			int p = 0, j = 0, k = 0;
//			char* tmp;
//			int len = 0;
//			interface_main(Pointer_ariph, string, M, &ariph_list, &plot_list, vars, message, symbol);	//output all the interface
//			switch(c = SDL_getch())		//read key
//			{
//				case F1:					//help
//					{
//						interface_help_main();
//						string[i - 1] = '\0';
//						continue;
//					}
//					case insert:          //insert
//					{
//						int tmp_i = 0;
//						Note* tmp_R = plot.head;
//						if (Pointer_ariph == NULL)
//							if ((!str_to_inf(&ariph, string, database_func, database_const, vars, var_amount, ARIPH, M, &symbol)) && (ariph.amount == 1))
//								M = ((Element*)(ariph.head->data))->data;
//							else
//								M = ((Element*)(ariph_list.tail->data))->data;
//						Pointer_ariph = NULL;
//						for (i = 0; i < awruk_size; i++)
//								string[i] = '\0';
//						i = 0;
//						//LineTo(hdc,tmp_i+2,(Plot*)(tmp_R->data)->coord[tmp_i+1]);
//						//printf("INSERT SUCCEDED!");
//						//M = ((Ariph*)(Pointer_ariph->data))->ans;
//						continue;
//					}
//					case del:          //Del
//					{
//						recent_del(&ariph_list, &plot_list, vars, Pointer_ariph, &var_amount);
//						//printf("DEL SUCCEDED!");
//						//M = 0;
//						continue;
//					}
//				case enter:          //if string input finished and confirmed
//				{
//					if (message != 0)
//					{
//						for (i = 0; i < awruk_size; i++)
//							string[i] = '\0';
//						i = 0;
//						message = 0;
//						continue;
//					}
//					switch(message = string_analyse(string, Pointer_ariph, database_func, database_const, vars, var_amount))
//					{					//choose working mode
//					case ARIPH:				//ariphmetical expr
//					{
//						double ans = 0;
//						message = 0;
//						message = str_to_inf(&ariph, string, database_func, database_const, vars, var_amount, ARIPH, M, &symbol);		//sting to infix
//						if (message == 0)		//if there are no errors
//						{
//							postfix = inf_to_post(&ariph);		//infix to postfix
//							if (postfix != NULL)				//if correct bracket balance
//							{
//								message = ARIPH;
//								post_calc(postfix, &ans, coordinates, &message, resize, push_up, push_right);	//calculate!
//								if (message != ARIPH)
//									continue;
//								queue_add_end(&ariph_list, ariph_create(string, ans));
//								if (ariph_list.amount > ariph_height)
//								{
//									queue_el_del(&ariph_list, 1);
//									queue_renum(&ariph_list);
//								}
//								for (i = 0; i < awruk_size; i++)
//									string[i] = '\0';
//								i = 0;
//								Pointer_ariph = ariph_list.tail;
//							}
//							else
//								message = ERR_BR;
//						}
//						else
//							continue;
//						continue;
//					}
//					case FUNC:
//					{
//						double ans = 0;						//restore defaults
//						push_right = 0;
//						push_up = 0;
//						resize = cell;
//						plots_recalc(&plot_list, &ans, coordinates, &message, resize, push_up, push_right);
//						message = 0;
//						message = str_to_inf(&plot, string, database_func, database_const, vars, var_amount, FUNC, M, &symbol);
//						if (message == 0)
//						{
//							postfix = (List*)malloc(sizeof(List));
//							postfix = inf_to_post(&plot);
//							if (postfix != NULL)
//							{
//								message = FUNC;
//								post_calc(postfix, &ans, coordinates, &message, resize, push_up, push_right);
//								queue_add_end(&plot_list, plot_create(string, postfix, coordinates));
//								if (plot_list.amount > plot_height)
//								{
//									queue_el_del(&plot_list, 1);
//									queue_renum(&plot_list);
//								}
//								for (i = 0; i < awruk_size; i++)
//									string[i] = '\0';
//								i = 0;
//								Pointer_ariph = ariph_list.tail;
//								graph_draw_asix(push_right, push_up);
//								graph_draw_graps(plot_list);
//								while ((c = SDL_getch()) != esc)
//								{
//									switch(c)
//									{
//									case esc:
//										{
//											int j = 0;
//											Pointer_ariph = NULL;
//											for (j = 0; j <= awruk_size; j++)
//												string[j] = '\0';
//											break;
//										}
//									case arr_up:
//										{
//											push_up++;
//											plots_recalc(&plot_list, &ans, coordinates, &message, resize, push_up, push_right);
//											graph_draw_asix(-push_right, -push_up);
//											graph_draw_graps(plot_list);
//											continue;
//										}
//									case arr_down:
//										{
//											push_up--;
//											plots_recalc(&plot_list, &ans, coordinates, &message, resize, push_up, push_right);
//											graph_draw_asix(-push_right, -push_up);
//											graph_draw_graps(plot_list);
//											continue;
//										}
//									case arr_right:
//										{
//											push_right++;
//											plots_recalc(&plot_list, &ans, coordinates, &message, resize, push_up, push_right);
//											graph_draw_asix(-push_right, -push_up);
//											graph_draw_graps(plot_list);
//											continue;
//										}
//									case arr_left:
//										{
//											push_right--;
//											plots_recalc(&plot_list, &ans, coordinates, &message, resize, push_up, push_right);
//											graph_draw_asix(-push_right, -push_up);
//											graph_draw_graps(plot_list);
//											continue;
//										}
//									case '+':
//										{
//											resize *= 2;
//											plots_recalc(&plot_list, &ans, coordinates, &message, resize, push_up, push_right);
//											graph_draw_asix(-push_right, -push_up);
//											graph_draw_graps(plot_list);
//											continue;
//										}
//									case '-':
//										{
//											resize /= 2;
//											plots_recalc(&plot_list, &ans, coordinates, &message, resize, push_up, push_right);
//											graph_draw_asix(-push_right, -push_up);
//											graph_draw_graps(plot_list);
//											continue;
//										}
//									}
//
//								}
//							}
//							else
//								message = ERR_BR;
//						}
//						else
//							continue;
//						continue;
//					}
//					case VAR:
//					{
//						//int p = 0, j = 0, k = 0;
//
//						while (string[p] != '=')
//							p++;
//						if (p > dbase_name_len)
//						{
//							message = ERR_LONG_VAR;
//							continue;
//						}
//						else
//						{
//							len = strlen(string);
//							message = 0;
//							tmp = (char*)malloc((len)*sizeof(char));
//							for (j = 0; j < p; j++)
//							{
//								tmp[j] = string[j];
//								if (isdigit(tmp[j]))
//								{
//									message = DIGIT_VAR;
//									break;;
//								}
//							}
//							tmp[j] = '\0';
//								//vars[var_amount].name[j] = string[j];
//							for (j = 0; j < p; j++)
//							{
//								if ((message = lexem_find(&j, tmp, &empty, vars, var_amount, VAR_SEARCH)) < 10)
//										continue;
//								else
//								{
//									if (message >= 10)
//									{
//
//										i = 0;
//										for (k = p + 1; k < len; k++)
//										{
//											if (!isdigit(string[k]))
//											{
//												message = CHAR_VAR;
//												break;
//											}
//											tmp[i] = string[k];
//											i++;
//										}
//										if ((!str_to_inf(&ariph, tmp, database_func, database_const, vars, var_amount, ARIPH, M, &symbol)) && (ariph.amount == 1))
//										{
//											vars[message - 10].data = ((Element*)(ariph.head->data))->data;
//											var_amount--;
//										}
//									}
//								}
//							}
//							if (message != DIGIT_VAR)
//							{
//								p = strlen(tmp);
//								for (j = 0; j < p; j++)
//								{
//									vars[var_amount].name[j] = tmp[j];
//
//								}
//								vars[var_amount].name[j] = '\0';
//								for (j = p + 1; j < len; j++)
//								{
//									if (!isdigit(string[j]))
//									{
//										message = CHAR_VAR;
//										break;
//									}
//									tmp[k] = string[j];
//									k++;
//								}
//								tmp[k] = '\0';
//							}
//							if ((message == CHAR_VAR) || (message == DIGIT_VAR))
//								continue;
//							if ((!str_to_inf(&ariph, tmp, database_func, database_const, vars, var_amount, ARIPH, M, &symbol)) && (ariph.amount == 1))
//							{
//								vars[var_amount].data = ((Element*)(ariph.head->data))->data;
//							}
//							var_amount++;
//							message = X_VAR;
//							continue;
//						}
//					}
//					case ERR_EMPTY:			//empty string
//					{
//						continue;
//					}
//					case ERR_SPEC:
//					{
//						continue;
//					}
//					case ERR_EQUAS:
//					{
//						continue;
//					}
//					case ERR_LONG_VAR:
//					{
//						continue;
//					}
//					case 0:				//if message or answer wasn't empty
//					{
//						string[0] = '\0';
//						Pointer_ariph = NULL;
//						continue;
//					}
//					}
//					//queue_create(&ariph);
//					/*if (str_to_inf(&ariph, string, database_func, database_const, vars))
//						string[0] = '\0';
//					else string[0] = 'E';*/
//					/*if (ariph.amount  = 4)
//						answer = ((Element*)(ariph.head->data))->data + ((Element*)(ariph.head->next->data))->data + ((Element*)(ariph.head->next->next->data))->data + ((Element*)(ariph.head->next->next->next->data))->data;
//					for (i = 0; i < answer; i++)
//					{
//						printf("\a");
//					}*/
//					continue;
//				}
//				case backspace:           //Backspace
//				{
//					message = 0;
//					if (Pointer_ariph == NULL)
//					{
//						if (i > 0)
//						{
//							i--;
//							string[i] = '\0';
//						}
//					}
//					else
//					{
//						int j = 0;
//						Pointer_ariph = NULL;
//						for (j = 0; j <= awruk_size; j++)
//							string[j] = '\0';
//						message = 0;
//					}
//					//lol = 0
//					continue;
//				}
//				case esc:          //Esc
//				{
//					interface_exit();
//					switch(SDL_getch())  //Check
//					{
//						case enter:
//						{
//							e = 1;
//							return 1;
//						}
//					}
//					continue;
//				}
//				case space:		  //Space
//				{
//					if (M != 0)
//					{
//						string[i] = 'M';
//						i++;
//					}
//					continue;
//				}
//				case F2:		  //F2
//				{
//					message = interface_list_plots(&plot_list);
//					continue;
//				}
//				case F3:		  //F3
//				{
//					message = interface_list_vars(vars);
//					continue;
//				}
//				case 0:		  //Non-allowed symbols
//				{
//					continue;
//				}
//				default:			//input
//				{
//					if (message == 0)
//					{
//						if (Pointer_ariph == NULL)
//						{
//							if (i < awruk_size)
//							{
//								string[i] = c;
//								i++;
//							}
//						}
//						else
//						{
//							int j = 0;
//							Pointer_ariph = NULL;
//							for (j = 0; j <= awruk_size; j++)
//								string[j] = '\0';
//							i = 0;
//							string[i] = c;
//							i++;
//						}
//					}
//					else
//					{
//						int j = 0;
//						Pointer_ariph = NULL;
//						for (j = 0; j <= awruk_size; j++)
//							string[j] = '\0';
//						message = 0;
//						string[0] = '\0';
//						i = 0;
//						string[i] = c;
//						i++;
//					}
//					/*
//					else
//						lol++;
//					if lol > 5 printf(random place) one of the phrases from the array
//						'Nope, stop, no more, please,
//						if lol > 15
//							'are you kidding? you wanna break me? stop right there, criminal scum, damn it'
//							if lol > 30
//								'hell you, press backspace!!! you are a bad person, you know it'*/
//				}
//			}
//		}
/////////////////////////////////////////////////////////////
//	}
//}



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
			switch(c = getch())
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
