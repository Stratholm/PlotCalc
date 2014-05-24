#include "computation_core_head.h"

/* Functions */
//Input string to infix notation
int str_to_inf(List* lt, char* in, Dbase* fc, Dbase* ct, Dbase* vr)
{
	int symbol = 0;
	unsigned int in_len;
	Element el; 
	in_len = strlen(in);
	lt->head = NULL;
	lt->tail = NULL;
	lt->amount = 0;
    while (symbol < in_len) 
	{
//////////////////////////////////////////////////////////////////
		if (in[symbol] == ' ')				//Space
		{
			symbol++;
			return 1;
			continue;
		} 
		if (isdigit(in[symbol]))			//number
		{
			int num = in[symbol] - '0';
			symbol++;
			while (isdigit(in[symbol])) 
			{
				num = num * 10 + (in[symbol++]) - '0';
			}
			el.key = NUM;
			el.data = num;
			queue_add_end(lt, &el);
			return 1;
			continue;
        }
		if (lexem_find(&symbol, in, lt, fc, func_amount, FUNC) == 1)
			return 1;
		if (lexem_find(&symbol, in, lt, ct, const_amount, CONST) == 1)
			return 1;
		if (lexem_find(&symbol, in, lt, vr, var_amount, VAR) == 1)
			return 1;
		symbol++;
//////////////////////////////////////////////////////////////////
    }
	return 0;
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
						el.key = FUNC;
						el.data = lex;
						*smb = mother_mother;
						queue_add_end(lt, &el);
						return 1;
					}
					if ((mode == CONST)||(mode == VAR))
					{
						el.key = NUM;
						el.data = db[lex].data;
						*smb = mother_mother;
						queue_add_end(lt, &el);
						return 1;
					}
					//break;
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
