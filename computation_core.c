#include "computation_core_head.h"

/* Functions */
//Input string to infix notation
int str_to_inf(List* lt, char* in, Dbase* fc, Dbase* ct, Dbase* vr, int var_amount)
{
	/*List* lt = (List*)malloc(sizeof(List));*/
	int symbol = 0;
	unsigned int in_len;
	Element el;
	//lt = (List*)malloc(sizeof(List));
	queue_create(lt);
	in_len = strlen(in);
    while (symbol < in_len - 1) 
	{
//////////////////////////////////////////////////////////////////
		if (in[symbol] == ' ')				//Space
		{
			symbol++;
			continue;
		} 
		if (isdigit(in[symbol]))			//number
		{
			double num = 0;
			double count = 0;
			int num_int_len = 0;
			int num_frac_len = 0;
 			//symbol++;
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
						num = num * (pow(10.0,(num_int_len))) + (in[symbol]) - '0';
					}
					symbol++;
				}
			}
			count = (int)(num * pow(10.0, num_frac_len + 1));
			if (((int)count % (int)pow(10.0, num_frac_len)) == 9)
				count++;
			num = ((int)count)/(pow(10.0, num_frac_len)) + (((int)(count) % (int)(pow(10.0, num_frac_len))) * (pow(10.0, -num_frac_len)));
			queue_add_end(lt, element_create(NUM, num));
			continue;
        }
		if (lexem_find(&symbol, in, lt, fc, func_amount, FUNC) == 1)
			continue;
		if (lexem_find(&symbol, in, lt, ct, const_amount, CONS) == 1)
			continue;
		if (lexem_find(&symbol, in, lt, vr, var_amount, VAR) == 1)
			continue;
		return NULL;
//////////////////////////////////////////////////////////////////
    }
	if (symbol == in_len - 1)
		return 1;
	else
		return 0;
	//return lt;
}

//Queue to postfix
List* inf_to_post(List* inf)
{
	/*Used inside string_analyse*/
}

//Calculate postfix
double post_calc(List* post)
{
	/*Used inside string_analyse by ariph and plots (in cycle)*/
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