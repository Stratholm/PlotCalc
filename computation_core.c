#include "computation_core_head.h"

/* Functions */
//Input string to infix notation
List str_to_inf(char* in, Dbase* fc, Dbase* ct, Dbase* var)
{
	int symbol = 0;
	unsigned int in_len;
	Element el; 
	List* lt= (List*)malloc(sizeof(List));
	in_len = strlen(in);
	queue_create(lt);
    while (symbol < in_len) 
	{
//////////////////////////////////////////////////////////////////
		if (in[symbol] == ' ')				//Space
		{
			symbol++;
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
			continue;
        } 
		lexem_find(&symbol, in, lt, ct, const_amount, CONST);
		lexem_find(&symbol, in, lt, fc, func_amount, FUNC);
		
		//lexem_find(&symbol, in, lt, fc, var_amount, VAR);
	
//////////////////////////////////////////////////////////////////
    }
	return *lt;
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
						return 1;
					}
					if ((mode == CONST)||(mode == VAR))
					{
						el.key = NUM;
						el.data = db[lex].data;
						*smb = mother_mother;
						return 1;
					}
					queue_add_end(lt, &el);
					break;
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
}
