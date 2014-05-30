#include "computation_core_head.h"

/* Functions */
//Input string to infix notation
int str_to_inf(List* lt, char* in, Dbase* fc, Dbase* ct, Dbase* vr, int var_amount, int mess)
{
	int symbol = 0;
	int tmp = 0;
	unsigned int in_len;
	Element el;
	queue_create(lt);
	in_len = strlen(in);
	if (mess == FUNC)
		symbol = 2;
    while (symbol < in_len) 
	{
//////////////////////////////////////////////////////////////////
		if (in[symbol] == ' ')				//Space
		{
			symbol++;
			continue;
		} 
		if (in[symbol] == 'x')
		{
			queue_add_end(lt, element_create(X_VAR, 0));
			symbol++;
			continue;
		}
		if (isdigit(in[symbol]))			//number
		{
			double num = 0;
			double count = 0;
			int num_int_len = 0;
			int num_frac_len = 0;
			while ((isdigit(in[symbol])) || (in[symbol] == '.'))
			{
				if (symbol == in_len)
					break;
				if (in[symbol] == '.')
				{
					count++;
					if (count > 1)
						return ERR_FRAC;
					symbol++;
					if (!isdigit(in[symbol]))
						return ERR_FRAC;
				}
				else
				{
					if (count != 0)
					{
						num_frac_len++;
						num = num + (in[symbol] - '0') * pow(10.0,(-num_frac_len));
					}
					else
					{
						num_int_len++;
						num = num * 10 + (in[symbol]) - '0';
					}
					symbol++;
				}
			}
			/* Damn it
			tmp = (int)(num * pow(10.0, num_frac_len + 1));
			if ((tmp % (int)pow(10.0, num_frac_len)) == 9)
			{
				//num += (pow(10.0, (-(num_frac_len + 1)))); num = ((int)count)/(pow(10.0, num_frac_len++)) + (((int)(count) % (int)(pow(10.0, num_frac_len))) * (pow(10.0, -num_frac_len)));
				tmp++;
				num = 0;
				num = (((tmp / 10) % (int)(pow(10.0, num_frac_len))) * (pow(10.0, -num_frac_len)));
				num += (int)((tmp)/(pow(10.0, num_frac_len + 1)));// + (((tmp / 10) % (int)(pow(10.0, num_frac_len))) * (pow(10.0, -num_frac_len)));

			}
			*/
			queue_add_end(lt, element_create(NUM, num));
			continue;
        }
		if (lexem_find(&symbol, in, lt, fc, func_amount, FUNC) == 1)
			continue;
		if (lexem_find(&symbol, in, lt, ct, const_amount, CONS) == 1)
			continue;
		if (lexem_find(&symbol, in, lt, vr, var_amount, VAR) == 1)
			continue;
		return ERR;
//////////////////////////////////////////////////////////////////
    }
	if (symbol == in_len)
		return 0;
	else
		return ERR;
}

//Queue to postfix
List* inf_to_post(List* inf)
{
	List* post = (List*)malloc(sizeof(List));
	List* stack = (List*)malloc(sizeof(List));
	Note* point = (Note*)malloc(sizeof(Note));
	queue_create(post);
	queue_create(stack);
	point = inf->head;
	while (point != NULL)
	{
		if (((Element*)(point->data))->key == NUM)
		{
			queue_add_end(post, element_create(NUM, ((Element*)(point->data))->data));
			point = point->next;
			continue;
		}
		if (((Element*)(point->data))->key == X_VAR)
		{
			queue_add_end(post, element_create(X_VAR, ((Element*)(point->data))->data));
			point = point->next;
			continue;
		}
		if (((Element*)(point->data))->key == LB)
		{
			queue_add_end(stack, element_create(LB, ((Element*)(point->data))->data));
			point = point->next;
			continue;
		}
		if (((Element*)(point->data))->key == RB)
		{
			while (((Element*)(stack->tail->data))->key != LB)
			{
				queue_add_end(post, element_create(((Element*)(stack->tail->data))->key, ((Element*)(stack->tail->data))->data));
				queue_el_del(stack, stack->tail->num);
				if (stack->tail->prev == NULL)
					return NULL;
			}
			if (((Element*)(stack->tail->data))->key == LB)
				queue_el_del(stack, stack->tail->num);
			if (((Element*)(stack->tail->data))->key == FUNC)
			{
				queue_add_end(post, element_create(((Element*)(stack->tail->data))->key, ((Element*)(stack->tail->data))->data));
				queue_el_del(stack, stack->tail->num);
			}
			point = point->next;
			continue;
		}
		if (((Element*)(point->data))->key == FUNC)
		{
			if (stack->amount != 0)
			while ((((Element*)(point->data))->data > 0) ? (  abs( ((Element*)(point->data))->data ) <  abs( ((Element*)(stack->tail->data))->data )  ) : (  abs( ((Element*)(point->data))->data ) <= abs( ((Element*)(stack->tail->data))->data )  ))
			{
				queue_add_end(post, element_create(((Element*)(stack->tail->data))->key, ((Element*)(stack->tail->data))->data));
				queue_el_del(stack, stack->tail->num);
			}
			queue_add_end(stack, element_create(FUNC, ((Element*)(point->data))->data));
			point = point->next;
			continue;
		}
	}
	while (stack->tail != NULL)
	{
		queue_add_end(post, element_create(((Element*)(stack->tail->data))->key, ((Element*)(stack->tail->data))->data));
		queue_el_del(stack, stack->tail->num);
	}
	return post;
}

//Calculate postfix
double post_calc(List* post, double* ans, int* coord, int mess)
{
	int i = 0, max = 0;
	List* post_save = (List*)malloc(sizeof(List));
	Note* point = (Note*)malloc(sizeof(Note));
	Note* point_save = (Note*)malloc(sizeof(Note));
	post_save = queu_el_copy(post);
	*point_save = *post_save->head;
	*ans = 0;
	//point = post->head;
	if (mess == FUNC)
		max = width;
	if (mess == ARIPH)
		max = 1;
	for (i = 0; i < max; i++)
	{
		post = queu_el_copy(post_save);
		point = post->head;
		while (post->amount != 1)
		{
			if (((Element*)(point->data))->key == NUM)
			{
				if (point->next != NULL)
					point = point->next;
				continue;
			}
			if (((Element*)(point->data))->key == X_VAR)
			{
				((Element*)(point->data))->data = i;
				/*if (point->next != NULL)
					point = point->next;
				continue;*/
			}
			if (((Element*)(point->data))->key == FUNC)
			{
				if ((((Element*)(point->data))->data == 2) && (((Element*)(point->data))->key == FUNC))			//+
				{
					((Element*)(point->prev->prev->data))->data += ((Element*)(point->prev->data))->data;
					point = point->prev->prev;
					queue_el_del(post, point->num + 2);
					queue_el_del(post, point->num + 1);
				}
				if ((((Element*)(point->data))->data == 3) && (((Element*)(point->data))->key == FUNC))			//-
				{
					((Element*)(point->prev->prev->data))->data -= ((Element*)(point->prev->data))->data;
					point = point->prev->prev;
					queue_el_del(post, point->num + 2);
					queue_el_del(post, point->num + 1);
				}
				if ((((Element*)(point->data))->data == 4) && (((Element*)(point->data))->key == FUNC))			//*
				{
					((Element*)(point->prev->prev->data))->data *= ((Element*)(point->prev->data))->data;
					point = point->prev->prev;
					queue_el_del(post, point->num + 2);
					queue_el_del(post, point->num + 1);
				}
				if ((((Element*)(point->data))->data == 5) && (((Element*)(point->data))->key == FUNC))			//:
				{
					((Element*)(point->prev->prev->data))->data /= ((Element*)(point->prev->data))->data;
					point = point->prev->prev;
					queue_el_del(post, point->num + 2);
					queue_el_del(post, point->num + 1);
				}
				if ((((Element*)(point->data))->data == 6) && (((Element*)(point->data))->key == FUNC))			//^
				{
					((Element*)(point->prev->prev->data))->data = pow((((Element*)(point->prev->prev->data))->data),(((Element*)(point->prev->data))->data));
					point = point->prev->prev;
					queue_el_del(post, point->num + 2);
					queue_el_del(post, point->num + 1);
				}
				if (point->next != NULL)
					point = point->next;
				continue;
			}
			if (point->next != NULL)
				point = point->next;
			else break;
		}
		if (mess == FUNC)
			coord[i] = ((Element*)(point->data))->data;
		if (mess == ARIPH)
		*ans = ((Element*)(point->data))->data;
	}
	post = queu_el_copy(post_save);
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
	el.key = 0;
	while (lex < amount)		//element
	{
		if (el.key == 0)
		{
			lex_len = strlen(db[lex].name);
			while (chr < lex_len)		//charachter in an element
			{
				if (in[mother_mother] == db[lex].name[chr])	//equivalance
				{
					chr++;
					mother_mother++;
					if (chr == lex_len)		//check
					{
						if (mode == FUNC)
						{
							if (lex == 0)
							{
								*smb = mother_mother;
								queue_add_end(lt, element_create(LB, lex));
								return 1;
							}
							if (lex == 1)
							{
								*smb = mother_mother;
								queue_add_end(lt, element_create(RB, lex));
								return 1;
							}
							*smb = mother_mother;
							queue_add_end(lt, element_create(FUNC, lex));
							return 1;
						}
						if ((mode == CONS)||(mode == VAR))
						{
							*smb = mother_mother;
							queue_add_end(lt, element_create(NUM, db[lex].data));
							return 1;
						}
					}
				}
				else 
				{
					*smb = mother_mother - chr;
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
		return 0;
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
	for (i = 0; i < width; i++)
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