#include "computation_core_head.h"

/* Functions */
//Input string to infix notation
int str_to_inf(List* lt, char* in, Dbase* fc, Dbase* ct, Dbase* vr, int var_amount, int mess, double M, int* symbol)
{
	int tmp = 0;
	unsigned int in_len;
	Element el;
	queue_create(lt);		//create list for infix
	in_len = strlen(in);
	*symbol = 0;
    while (*symbol < in_len)
	{
//////////////////////////////////////////////////////////////////
		if (in[*symbol] == 'M')					//insert num from the M memory
		{
			queue_add_end(lt, element_create(NUM, M));
			(*symbol)++;
			continue;
		}
		if (in[*symbol] == ' ')				//Space
		{
			(*symbol)++;
			continue;
		}
		if (in[*symbol] == 'x')
		{
			queue_add_end(lt, element_create(X_VAR, 0));
			(*symbol)++;
			continue;
		}
		if (isdigit(in[*symbol]))			//number
		{
			double num = 0;
			double count = 0;
			int num_int_len = 0;
			int num_frac_len = 0;
			while ((isdigit(in[*symbol])) || (in[*symbol] == '.'))
			{
				if (*symbol == in_len)
					break;
				if (in[*symbol] == '.')
				{
					count++;
					if (count > 1)
						return ERR_FRAC;
					(*symbol)++;
					if (!isdigit(in[*symbol]))
						return ERR_FRAC;
				}
				else
				{
					if (count != 0)
					{
						num_frac_len++;
						num = num + (in[*symbol] - '0') * pow(10.0,(-num_frac_len));
					}
					else
					{
						num_int_len++;
						num = num * 10 + (in[*symbol]) - '0';
					}
					(*symbol)++;
				}
			}
			queue_add_end(lt, element_create(NUM, num));
			continue;
        }
		if (lexem_find(symbol, in, lt, fc, func_amount, FUNC) == 0)
			continue;
		if (lexem_find(symbol, in, lt, ct, const_amount, CONS) == 0)
			continue;
		if (lexem_find(symbol, in, lt, vr, var_amount, VAR) == 0)
			continue;
		return ERR_LEX;
//////////////////////////////////////////////////////////////////
    }
	if ((lt->amount == 1) && (key(lt->head) == FUNC))
	{
		(*symbol)--;
		return ERR_LEX;
	}
	if (*symbol == in_len)
		return 0;
	else
		return ERR_LEX;
}

//Queue to postfix
List* inf_to_post(List* inf)
{
	List* post = (List*)malloc(sizeof(List));			//
	List* stack = (List*)malloc(sizeof(List));			//call memory
	Note* point = (Note*)malloc(sizeof(Note));			//
	queue_create(post);
	queue_create(stack);
	point = inf->head;
	while (point != NULL)				//till the end of the list
	{
		if (key(point) == NUM)					//add if number
		{
			queue_add_end(post, element_create(NUM, data(point)));
			point = point->next;
			continue;
		}
		if (key(point) == X_VAR)				//add if "x" variable
		{
			queue_add_end(post, element_create(X_VAR, data(point)));
			point = point->next;
			continue;
		}
		if (key(point) == LB)					//save to stack if "("
		{
			queue_add_end(stack, element_create(LB, data(point)));
			point = point->next;
			continue;
		}
		if (key(point) == RB)					//")"
		{
			if (stack->amount == 0)
				return 0;
			while (key(stack->tail) != LB)				//send stack to out, while not a "("
			{
				queue_add_end(post, element_create(key(stack->tail), data(stack->tail)));
				queue_el_del(stack, stack->tail->num);
				if (stack->tail->prev == NULL)
					return NULL;
			}
			if (key(stack->tail) == LB)					//del "("
				queue_el_del(stack, stack->tail->num);
			if (key(stack->tail) == FUNC)				//add to out, if function
			{
				queue_add_end(post, element_create(key(stack->tail), data(stack->tail)));
				queue_el_del(stack, stack->tail->num);
			}
			point = point->next;
			continue;
		}
		if (key(point) == FUNC)					//case function
		{
			if (stack->amount != 0)		//if data > 0 (while data < stack tail data) else (while data <= stack tail data)
			while ((data(point) > 0) ? (abs(data(point)) < abs(data(stack->tail))) : (abs(data(point)) <= abs(data(stack->tail))))
			{
				queue_add_end(post, element_create(key(stack->tail), data(stack->tail)));	//add to out
				queue_el_del(stack, stack->tail->num);					//del last in stack
			}
			queue_add_end(stack, element_create(FUNC, data(point)));		//add to stack end
			point = point->next;
			continue;
		}
	}
	while (stack->tail != NULL)				//push all from stack to out in the end
	{
		if (key(stack->tail) != FUNC)		//check if correct bracket balance
			return 0;
		queue_add_end(post, element_create(key(stack->tail), data(stack->tail)));
		queue_el_del(stack, stack->tail->num);
	}
	return post;
}

//Calculate postfix
double post_calc(List* post, double* ans, int* coord, int* mess, double resz, int up, int right) //89143682494
{
	int i = 0, max = 0;
	List* post_save = (List*)malloc(sizeof(List));		//
	Note* point = (Note*)malloc(sizeof(Note));			//
	Note* point_save = (Note*)malloc(sizeof(Note));		//save existing postfix
	post_save = queu_el_copy(post);						//
	point_save = post_save->head;						//
	*ans = 0;
	//point = post->head;
	if (*mess == FUNC)		//muilty computation for function
		max = screen_width;
	if (*mess == ARIPH)		//single computation for ariph
		max = 1;
	while (i < max)
	{
		post = queu_el_copy(post_save);		//refresh postfix
		point = post->head;					//
		if ((key(post->head) == X_VAR) && (post->amount == 1))		//for single x
			ins_data(point, (i - 400 + cell*right)/resz);			//
		while (post->amount != 1)				//the last element will be the answer
		{
			if (key(point) == X_VAR)			//case "x" variable
			{
				ins_data(point, (i - 400 + cell*right)/resz);		//set value for "x"
			}
			if (key(point) == FUNC)					//for functions (list below)
			{										//data(point) is an index of function in array database
				if (data(point) == 2)		//sum - "+"
				{
					((Element*)(point->prev->prev->data))->data += data(point->prev);	//sum two previous elements
					point = point->prev->prev;
					queue_el_del(post, point->num + 2);	//delete used
					queue_el_del(post, point->num + 1);	//
					if (point->next != NULL) point = point->next;	//next element
					continue;
				}
				if (data(point) == 3)		//subtraction - "-"
				{
					((Element*)(point->prev->prev->data))->data -= data(point->prev);	//substract two previous elements
					point = point->prev->prev;
					queue_el_del(post, point->num + 2);	//delete used
					queue_el_del(post, point->num + 1);	//
					if (point->next != NULL) point = point->next;
					continue;
				}
				if (data(point) == 4)	//muiltiply - "*"
				{
					((Element*)(point->prev->prev->data))->data *= data(point->prev);	//muiltiply two previous elements
					point = point->prev->prev;
					queue_el_del(post, point->num + 2);	//delete used
					queue_el_del(post, point->num + 1);	//
					if (point->next != NULL) point = point->next;
					continue;
				}
				if (data(point) == 5)	//division - "/"
				{
					if (*mess == ERR) *mess = FUNC;					//restore message
					if ((data(point->prev) > -0.0000001) && (data(point->prev) < 0.0000001))		//case close to Zero
					{
						if (*mess == ARIPH)		//single computation for ariph
						{
							*mess = ERR_ZERO_DIV;
							return;
						}
						if (*mess == FUNC)		//function case
						{
							*mess = ERR;
							break;
						}
					}
					((Element*)(point->prev->prev->data))->data /= data(point->prev);	//divide two previous elements
					point = point->prev->prev;
					queue_el_del(post, point->num + 2);	//delete used
					queue_el_del(post, point->num + 1);	//
					if (point->next != NULL) point = point->next;
					continue;
				}
				if (data(point) == 6)			//degree - "^"
				{
					if (*mess == ERR) *mess = FUNC;					//restore message
					if ((data(point->prev) < 1) && (data(point->prev) > 0))		//case degree is not natural
					{
						if (*mess == ARIPH)		//single computation for ariph
						{
							if (data(point->prev->prev) < 0)
							{
								*mess = ERR_NEG_DEG;
								return;
							}
						}
						if (*mess == FUNC)		//function case
						{
							if (data(point->prev->prev) < 0)
								{
									*mess = ERR;
									break;
								}
						}
					}
					ins_data(point->prev->prev, pow(data(point->prev->prev), data(point->prev)));	//first number in degree of the second
					point = point->prev->prev;
					queue_el_del(post, point->num + 2);	//delete used
					queue_el_del(post, point->num + 1);	//
					if (point->next != NULL) point = point->next;
					continue;
				}
				if (((Element*)(point->data))->data == 7)			//natural logariphm - "ln"
				{
					if (*mess == ERR) *mess = FUNC;					//restore message
					if (data(point->prev) < 0)		//case less than Zero
					{
						if (*mess == ARIPH)		//single computation for ariph
						{
							*mess = ERR_NEG_LN;
							return;
						}
						if (*mess == FUNC)		//function case
						{
							*mess = ERR;
							break;
						}
					}
					ins_data(point->prev, log(data(point->prev)));		//ln of previous element
					point = point->prev;
					queue_el_del(post, point->num + 1);	//delete used
					if (point->next != NULL) point = point->next;
					continue;
				}
				if (data(point) == 8)	//natural logariphm - "log"
				{
					if (*mess == ERR) *mess = FUNC;					//restore message
					if (data(point->prev) < 0)		//case less than Zero
					{
						if (*mess == ARIPH)		//single computation for ariph
						{
							*mess = ERR_NEG_LN;
							return;
						}
						if (*mess == FUNC)		//function case
						{
							*mess = ERR;
							break;
						}
					}
					ins_data(point->prev, log(data(point->prev)));		//ln of previous element
					point = point->prev;
					queue_el_del(post, point->num + 1);	//delete used
					if (point->next != NULL) point = point->next;
					continue;
				}
				if (data(point) == 9)		//square root - "sqrt"
				{
					if (*mess == ERR) *mess = FUNC;					//restore message
					if (data(point->prev) < 0)		//case less than Zero
					{
						if (*mess == ARIPH)		//single computation for ariph
						{
							*mess = ERR_NEG_ROOT;
							return;
						}
						if (*mess == FUNC)		//function case
						{
							*mess = ERR;
							break;
						}
					}
					ins_data(point->prev, sqrt(data(point->prev)));		//square root of previous element
					point = point->prev;
					queue_el_del(post, point->num + 1);	//delete used
					if (point->next != NULL) point = point->next;
					continue;
				}
				if (data(point) == 10)			//cosinus - "cos"
				{
					if (*mess == ERR) *mess = FUNC;					//restore message
					ins_data(point->prev, cos(data(point->prev)));		//cosinus of previous element
					point = point->prev;
					queue_el_del(post, point->num + 1);	//delete used
					if (point->next != NULL) point = point->next;
					continue;
				}
				if (data(point) == 11)			//sinus - "sin"
				{
					if (*mess == ERR) *mess = FUNC;					//restore message
					ins_data(point->prev, sin(data(point->prev)));		//sinus of previous element
					point = point->prev;
					queue_el_del(post, point->num + 1);	//delete used
					if (point->next != NULL) point = point->next;
					continue;
				}
				if (data(point) == 12)			//tanget - "tan"
				{
					double tmp, piz = 3.1415926535;
					tmp = data(point->prev) - ((int) (data(point->prev)/piz)) * piz - piz/2.0;
					if (*mess == ERR) *mess = FUNC;					//restore message
					if ((tmp > -0.00001) && (tmp < 0.00001))		//case close to Zero
					{
						if (*mess == ARIPH)		//single computation for ariph
						{
							*mess = ERR_TAN;
							return;
						}
						if (*mess == FUNC)		//function case
						{
							*mess = ERR;
							break;
						}
					}
					ins_data(point->prev, tan(data(point->prev)));		//tanget of previous element
					point = point->prev;
					queue_el_del(post, point->num + 1);	//delete used
					if (point->next != NULL) point = point->next;
					continue;
				}
				if (data(point) == 13)			//cotanget - "ctg"
				{
					double tmp, piz = 3.1415926535;
					tmp = data(point->prev) - ((int) ((data(point->prev))/piz)) * piz;
					if (*mess == ERR) *mess = FUNC;					//restore message
					if ((tmp > -0.00001) && (tmp < 0.00001))		//case close to Zero
					{
						if (*mess == ARIPH)		//single computation for ariph
						{
							*mess = ERR_CTG;
							return;
						}
						if (*mess == FUNC)		//function case
						{
							*mess = ERR;
							break;
						}
					}
					ins_data(point->prev, ctg(data(point->prev)));		//cotanget of previous element
					point = point->prev;
					queue_el_del(post, point->num + 1);	//delete used
					if (point->next != NULL) point = point->next;
					continue;
				}
				if (point->next != NULL)
					point = point->next;
				continue;
			}
			if (point->next != NULL)		//next element
				point = point->next;
			else break;
		}
		if (*mess == ERR)		//value doesn't exist in that point
			coord[i] = -1;
		if (*mess == FUNC)														//save coordinate
			coord[i] = cell*up + 300 - (((Element*)(point->data))->data)*resz;
		if (*mess == ARIPH)														//extract answer
			*ans = ((Element*)(point->data))->data;
		i++;
	}
	//*mess = 0;
	post = queu_el_copy(post_save);						//refresh postfix
}

//Transferes answer to the rational form
Rat_num* ans_to_rat(double ans)
{
	/*Used inside string_analyse by ariph*/
}

//Finds closest lexems
int lexem_find(int* smb, char* in, List* lt, Dbase* db, int amount, int mode)
{
	int mother_mother = *smb;
	unsigned int lex = 0;
	unsigned int chr = 0;
	unsigned int lex_len;
	Element el;
	if (mode == VAR)
		if (isdigit(string[*smb]))
		{
			return DIGIT_VAR;
		}
	el.key = 0;
	while (lex < amount)		//element
	{
		if (el.key == 0)
		{
			lex_len = strlen(db[lex].name);
			while (chr < lex_len)		//charachter in an element
			{
				if (in[mother_mother] == db[lex].name[chr])	//equivalance of chars
				{
					chr++;
					mother_mother++;
					if (chr == lex_len)		//check if it is a lexem
					{
						if (mode == FUNC)			//case function
						{
							if (lex == 0)				//for left bracket
							{
								*smb = mother_mother;
								queue_add_end(lt, element_create(LB, lex));
								return 0;
							}
							if (lex == 1)				//for right bracket
							{
								*smb = mother_mother;
								queue_add_end(lt, element_create(RB, lex));
								return 0;
							}
							*smb = mother_mother;			//for default function
							queue_add_end(lt, element_create(FUNC, lex));
							return 0;
						}
						if ((mode == CONS)||(mode == VAR))	//for constants or variables
						{
							*smb = mother_mother;
							queue_add_end(lt, element_create(NUM, db[lex].data));
							return 0;
						}
						if (mode == VAR_SEARCH)
							return (10 + lex);
					}
				}
				else					//case lexems not found
				{
					*smb = mother_mother - chr;
					mother_mother = *smb;
					chr = 0;
					break;
				}
			}
			lex++;
		}
		else
		break;
	}
	if (el.key == 0)
		return 1;
}

//Create new Element
Element* element_create(char key, double data)
{
	Element* el = (Element*)malloc(sizeof(Element));
	el->key = key;
	el->data = data;
	return el;
}

//Create new Ariph
Ariph* ariph_create(char* string, double ans)
{
	int i = 0;
	Ariph* af = (Ariph*)malloc(sizeof(Ariph));
	for (i = 0; i < strlen(string); i++)
		af->string[i] = string[i];
	af->string[i] = '\0';
	af->ans = ans;
	return af;
}

//Create new Plot
Plot* plot_create(char* string, List* post, int* coord)
{
	int i = 0;
	Plot* pt = (Plot*)malloc(sizeof(Plot));
	for (i = 0; i < strlen(string); i++)
		pt->string[i] = string[i];
	pt->string[i] = '\0';
	pt->postfix = *post;
	for (i = 0; i < screen_width; i++)
		pt->coord[i] = coord[i];
	return pt;
}

//Copies list of elements
List* queu_el_copy(List* in)
{
	List* copy = (List*)malloc(sizeof(List));
	Note* point = (Note*)malloc(sizeof(Note));
	queue_create(copy);
	point = in->head;
	while (point != NULL)
	{
		queue_add_end(copy, element_create(((Element*)(point->data))->key, ((Element*)(point->data))->data));
		point = point->next;
	}
	return copy;
}

//Extract element key
char key(Note* el)
{
	return ((Element*)(el->data))->key;
}

//Extract element data
double data(Note* el)
{
	return ((Element*)(el->data))->data;
}

//Rewrite element key
void ins_key(Note* el, char in)
{
	((Element*)(el->data))->key = in;
}

//Rewrite element data
void ins_data(Note* el, double in)
{
	((Element*)(el->data))->data = in;
}

//ctg
double ctg(double in)
{
	return (cos(in)/sin(in));
}