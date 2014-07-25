/*Includes*/
#include "PlotCalc_Head.h"
#include "computation_core_head.h"
#include "Graph_Head.h"

/*Main variables defenition*/
int e = 0;
double M = 0;
SDL_Keycode c = 0;
int message = 0;
char string[awruk_size] = {'\0'};
int i = 0;
int symbol = 0;
List plot_list;
List ariph;
List plot;
List* postfix;
List ariph_list;
List empty;
Note* Pointer_plots;
Note* Pointer_ariph = NULL;
Note* Pointer_vars;
Dbase* database_func;
Dbase* database_const;
Dbase* vars;
int sym_allow[sym_allow_quant];
int var_amount = 0;
int coordinates[screen_width];
int push_right = 0;
int push_up = 0;
double resize = cell;


/*Functions*/
//Open sessinon to save
int session_open()
{
	/*opens files*/
	return 1;
}

//Save plot
int plot_save(Note* point)
{
	return 1;
}

//Close session of storage
int session_close(List* ariph, List* var)
{
	/*saves the rest*/
	return 1;
}

void interface_read()
{
    int p = 0, j = 0, k = 0;
    char* tmp;
    int len = 0;
    while (1)
    {
    interface_main(Pointer_ariph, string, M, &ariph_list, &plot_list, vars, message, symbol);
    switch(c = SDL_getch())
    {
				case SDLK_F1:					//help
					{
						interface_help_main();
						string[i - 1] = '\0';
						continue;
					}
					case SDLK_INSERT:          //insert
					{
						int tmp_i = 0;
						Note* tmp_R = plot.head;
						if (Pointer_ariph == NULL)
							if ((!str_to_inf(&ariph, string, database_func, database_const, vars, var_amount, ARIPH, M, &symbol)) && (ariph.amount == 1))
								M = ((Element*)(ariph.head->data))->data;
							else
								M = ((Element*)(ariph_list.tail->data))->data;
						Pointer_ariph = NULL;
						for (i = 0; i < awruk_size; i++)
								string[i] = '\0';
						i = 0;
						//LineTo(hdc,tmp_i+2,(Plot*)(tmp_R->data)->coord[tmp_i+1]);
						//printf("INSERT SUCCEDED!");
						//M = ((Ariph*)(Pointer_ariph->data))->ans;
						continue;
					}
					case SDLK_DELETE:          //Del
					{
						recent_del(&ariph_list, &plot_list, vars, Pointer_ariph, &var_amount);
						//printf("DEL SUCCEDED!");
						//M = 0;
						continue;
					}
				case SDLK_RETURN:          //if string input finished and confirmed
				{
					if (message != 0)
					{
						for (i = 0; i < awruk_size; i++)
							string[i] = '\0';
						i = 0;
						message = 0;
						continue;
					}
					switch(message = string_analyse(string, Pointer_ariph, database_func, database_const, vars, var_amount))
					{					//choose working mode
					case ARIPH:				//ariphmetical expr
					{
						double ans = 0;
						message = 0;
						message = str_to_inf(&ariph, string, database_func, database_const, vars, var_amount, ARIPH, M, &symbol);		//sting to infix
						if (message == 0)		//if there are no errors
						{
							postfix = inf_to_post(&ariph);		//infix to postfix
							if (postfix != NULL)				//if correct bracket balance
							{
								message = ARIPH;
								post_calc(postfix, &ans, coordinates, &message, resize, push_up, push_right);	//calculate!
								if (message != ARIPH)
									continue;
								queue_add_end(&ariph_list, ariph_create(string, ans));
								if (ariph_list.amount > ariph_height)
								{
									queue_el_del(&ariph_list, 1);
									queue_renum(&ariph_list);
								}
								for (i = 0; i < awruk_size; i++)
									string[i] = '\0';
								i = 0;
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
						double ans = 0;						//restore defaults
						push_right = 0;
						push_up = 0;
						resize = cell;
						plots_recalc(&plot_list, &ans, coordinates, &message, resize, push_up, push_right);
						message = 0;
						message = str_to_inf(&plot, string, database_func, database_const, vars, var_amount, FUNC, M, &symbol);
						if (message == 0)
						{
							postfix = (List*)malloc(sizeof(List));
							postfix = inf_to_post(&plot);
							if (postfix != NULL)
							{
								message = FUNC;
								post_calc(postfix, &ans, coordinates, &message, resize, push_up, push_right);
								queue_add_end(&plot_list, plot_create(string, postfix, coordinates));
								if (plot_list.amount > plot_height)
								{
									queue_el_del(&plot_list, 1);
									queue_renum(&plot_list);
								}
								for (i = 0; i < awruk_size; i++)
									string[i] = '\0';
								i = 0;
								Pointer_ariph = ariph_list.tail;
								graph_draw_asix(push_right, push_up);
								graph_draw_graps(plot_list);
								while ((c = SDL_getch()) != esc)
								{
									switch(c)
									{
									case SDLK_RETURN:
										{
											int j = 0;
											Pointer_ariph = NULL;
											for (j = 0; j <= awruk_size; j++)
												string[j] = '\0';
											break;
										}
									case SDLK_UP:
										{
											push_up++;
											plots_recalc(&plot_list, &ans, coordinates, &message, resize, push_up, push_right);
											graph_draw_asix(-push_right, -push_up);
											graph_draw_graps(plot_list);
											continue;
										}
									case SDLK_DOWN:
										{
											push_up--;
											plots_recalc(&plot_list, &ans, coordinates, &message, resize, push_up, push_right);
											graph_draw_asix(-push_right, -push_up);
											graph_draw_graps(plot_list);
											continue;
										}
									case SDLK_RIGHT:
										{
											push_right++;
											plots_recalc(&plot_list, &ans, coordinates, &message, resize, push_up, push_right);
											graph_draw_asix(-push_right, -push_up);
											graph_draw_graps(plot_list);
											continue;
										}
									case SDLK_LEFT:
										{
											push_right--;
											plots_recalc(&plot_list, &ans, coordinates, &message, resize, push_up, push_right);
											graph_draw_asix(-push_right, -push_up);
											graph_draw_graps(plot_list);
											continue;
										}
									case SDLK_PLUS:
										{
											resize *= 2;
											plots_recalc(&plot_list, &ans, coordinates, &message, resize, push_up, push_right);
											graph_draw_asix(-push_right, -push_up);
											graph_draw_graps(plot_list);
											continue;
										}
									case SDLK_MINUS:
										{
											resize /= 2;
											plots_recalc(&plot_list, &ans, coordinates, &message, resize, push_up, push_right);
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
						//int p = 0, j = 0, k = 0;

						while (string[p] != '=')
							p++;
						if (p > dbase_name_len)
						{
							message = ERR_LONG_VAR;
							continue;
						}
						else
						{
							len = strlen(string);
							message = 0;
							tmp = (char*)malloc((len)*sizeof(char));
							for (j = 0; j < p; j++)
							{
								tmp[j] = string[j];
								if (isdigit(tmp[j]))
								{
									message = DIGIT_VAR;
									break;;
								}
							}
							tmp[j] = '\0';
								//vars[var_amount].name[j] = string[j];
							for (j = 0; j < p; j++)
							{
								if ((message = lexem_find(&j, tmp, &empty, vars, var_amount, VAR_SEARCH)) < 10)
										continue;
								else
								{
									if (message >= 10)
									{

										i = 0;
										for (k = p + 1; k < len; k++)
										{
											if (!isdigit(string[k]))
											{
												message = CHAR_VAR;
												break;
											}
											tmp[i] = string[k];
											i++;
										}
										if ((!str_to_inf(&ariph, tmp, database_func, database_const, vars, var_amount, ARIPH, M, &symbol)) && (ariph.amount == 1))
										{
											vars[message - 10].data = ((Element*)(ariph.head->data))->data;
											var_amount--;
										}
									}
								}
							}
							if (message != DIGIT_VAR)
							{
								p = strlen(tmp);
								for (j = 0; j < p; j++)
								{
									vars[var_amount].name[j] = tmp[j];

								}
								vars[var_amount].name[j] = '\0';
								for (j = p + 1; j < len; j++)
								{
									if (!isdigit(string[j]))
									{
										message = CHAR_VAR;
										break;
									}
									tmp[k] = string[j];
									k++;
								}
								tmp[k] = '\0';
							}
							if ((message == CHAR_VAR) || (message == DIGIT_VAR))
								continue;
							if ((!str_to_inf(&ariph, tmp, database_func, database_const, vars, var_amount, ARIPH, M, &symbol)) && (ariph.amount == 1))
							{
								vars[var_amount].data = ((Element*)(ariph.head->data))->data;
							}
							var_amount++;
							message = X_VAR;
							continue;
						}
					}
					case ERR_EMPTY:			//empty string
					{
						continue;
					}
					case ERR_SPEC:
					{
						continue;
					}
					case ERR_EQUAS:
					{
						continue;
					}
					case ERR_LONG_VAR:
					{
						continue;
					}
					case 0:				//if message or answer wasn't empty
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
				case SDLK_BACKSPACE:           //Backspace
				{
					message = 0;
					if (Pointer_ariph == NULL)
					{
						if (i > 0)
						{
							i--;
							string[i] = '\0';
						}
					}
					else
					{
						int j = 0;
						Pointer_ariph = NULL;
						for (j = 0; j <= awruk_size; j++)
							string[j] = '\0';
						message = 0;
					}
					//lol = 0
					continue;
				}
				case SDLK_ESCAPE:          //Esc
				{
					interface_exit();
					switch(SDL_getch())  //Check
					{
						case SDLK_RETURN:
						{
							e = 1;
							exit(1);
                        }
						default: continue;
					}
					continue;
				}
				case SDLK_SPACE:		  //Space
				{
					if (M != 0)
					{
						string[i] = 'M';
						i++;
					}
					continue;
				}
				case SDLK_F2:		  //F2
				{
					message = interface_list_plots(&plot_list);
					continue;
				}
				case SDLK_F3:		  //F3
				{
					message = interface_list_vars(vars);
					continue;
				}
				case 1:
				{
                    continue;
				}
				default:			//input
				{
				char symb;
				symb=c;
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
							int j = 0;
							Pointer_ariph = NULL;
							for (j = 0; j <= awruk_size; j++)
								string[j] = '\0';
							i = 0;
							string[i] = c;
							i++;
						}
					}
					else
					{
						int j = 0;
						Pointer_ariph = NULL;
						for (j = 0; j <= awruk_size; j++)
							string[j] = '\0';
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
}

//Analyse string and calculate/save/build
int string_analyse(char* str, Note* point, Dbase* fc, Dbase* ct, Dbase* vr, int var_amount)
{
	int i = 0;
	int amount = 0;
	int strl = strlen(str);
	if (point == NULL)			//check if there is no output now
	{
		if (strl == 0)			//empty string
		{
			return ERR_EMPTY;
		}
		else
		{
			while (i < strl)		//check content of the string
			{
				c = str[i];
				if (c < 0)				//kirillic alphabit
					return ERR_SPEC;
				if ((((c >= 34) && (c <= 39)) || (c == 44)) || (((c >= 58) && (c <= 64)) && (c != 61)) || (((c >= 91) && (c <= 96)) && (c != 94)))
					return ERR_SPEC;		//not allowed symbols filter
				if ((i > dbase_name_len) && (str[i] == '='))	//"=" in imossibru place
					return ERR_LONG_VAR;
				if (str[i] == '=')			//muilty "="
				{
					amount++;
					if (amount > 1)
						return ERR_EQUAS;
				}
				if (c == 'x')						//function if content "x"
					return FUNC;
				if ((i == strl - 1) && (amount == 1))	//variable if content single "="
					return VAR;
				i++;
			}
			return ARIPH;						//else ariphmetical
		}
	}
	else
	return NULL;					//else clean output
}

//Initialise functions database
Dbase* func_init(Dbase* fc)
{
	fc = (Dbase*)malloc(func_amount * sizeof(Dbase));
	fc[0].name[0] = '(';
	fc[0].name[1] = '\0';
	fc[0].data = 0;
	fc[1].name[0] = ')';
	fc[1].name[1] = '\0';
	fc[1].data = 0;
	fc[2].name[0] = '+';
	fc[2].name[1] = '\0';
	fc[2].data = -1;
	fc[3].name[0] = '-';
	fc[3].name[1] = '\0';
	fc[3].data = -1;
	fc[4].name[0] = '*';
	fc[4].name[1] = '\0';
	fc[4].data = -2;
	fc[5].name[0] = '/';
	fc[5].name[1] = '\0';
	fc[5].data = -2;
	fc[6].name[0] = '^';
	fc[6].name[1] = '\0';
	fc[6].data = 3;
	fc[7].name[0] = 'l';
	fc[7].name[1] = 'n';
	fc[7].name[2] = '\0';
	fc[7].data = 2;
	fc[8].name[0] = 'l';
	fc[8].name[1] = 'o';
	fc[8].name[2] = 'g';
	fc[8].name[3] = '\0';
	fc[8].data = 2;
	fc[9].name[0] = 's';
	fc[9].name[1] = 'q';
	fc[9].name[2] = 'r';
	fc[9].name[3] = 't';
	fc[9].name[4] = '\0';
	fc[9].data = 2;
	fc[10].name[0] = 'c';
	fc[10].name[1] = 'o';
	fc[10].name[2] = 's';
	fc[10].name[3] = '\0';
	fc[10].data = 2;
	fc[11].name[0] = 's';
	fc[11].name[1] = 'i';
	fc[11].name[2] = 'n';
	fc[11].name[3] = '\0';
	fc[11].data = 2;
	fc[12].name[0] = 't';
	fc[12].name[1] = 'a';
	fc[12].name[2] = 'n';
	fc[12].name[3] = '\0';
	fc[12].data = 2;
	fc[13].name[0] = 'c';
	fc[13].name[1] = 't';
	fc[13].name[2] = 'g';
	fc[13].name[3] = '\0';
	fc[13].data = 2;
	return fc;
}

//Initialise constants database
Dbase* const_init(Dbase* ct)
{
	ct = (Dbase*)malloc(const_amount * sizeof(Dbase));
	ct[0].name[0] = 'p';
	ct[0].name[1] = 'i';
	ct[0].name[2] = '\0';
	ct[0].data = 3.1415926535;
	ct[1].name[0] = 'e';
	ct[1].name[1] = '\0';
	ct[1].data = 2.7182818284;
	return 0;
}

//Initialise variables
void vars_init(Dbase* vr)
{
	vr = (Dbase*)malloc(var_max_amount * sizeof(Dbase));
}

//Recalculate plots
int plots_recalc(List* plot_list, double* ans, int* coord, int* mess, double resz, int up, int right)
{
	Note* Pointer_plots = (Note*)malloc(sizeof(Note));
	Pointer_plots = plot_list->head;
	while (Pointer_plots != NULL)
	{
		post_calc(&(((Plot*)(Pointer_plots->data))->postfix), ans, ((Plot*)(Pointer_plots->data))->coord, &message, resize, push_up, push_right);
		Pointer_plots = Pointer_plots->next;
	}
	return 1;
}

//Delete all history
int recent_del(List* ariph, List* plot, Dbase* var, Note* point, int* var_amount)
{
	queue_create(ariph);
	queue_create(plot);
	free(var);
	*var_amount = 0;
	point = NULL;
	return 1;
}

//
////Initialize allowed symbols
//void sym_allow_init(int* sm)
//{
//	int i = 0;
//	int c = 33;
//	while (i <= sym_allow_quant)
//	{
//		if ((((c >= 34) && (c <= 39)) || (c == 44)) || (((c >= 58) && (c <= 64)) && (c != 61)) || (((c >= 91) && (c <= 96)) && (c != 94)))
//		{
//			c++;
//			continue;
//		}
//		else
//		{
//			sm[i] = c;
//			i++;
//			c++;
//		}
//	}
//}
