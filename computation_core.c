#include "computation_core_head.h"

/* Functions */
//Input string to infix notation
List* str_to_inf(char* in, Func* fc)
{
	int symbol, func, chr, in_len, func_len;
	Element el; 
	List* lt;
	lt = (List*)malloc(sizeof(List));
	symbol = 0;
	func = 0;
	chr = 0;
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
		else 
		{
			while (func < func_amount)		//function
			{
				func_len = strlen(fc[func].name);
				while (chr <= func_len)
				{
					if (in[symbol] == fc[func].name[chr])
					{
						chr++;
						symbol++;
						if (chr == func_len)
						{
							el.key = FUNC;
							el.data = func;
							queue_add_end(lt, &el);
							break;
						}
					}
					else 
					{
						symbol -= --chr;
						chr = 0;
						break;
					}
				}
				func++;
			}
        }
		else
		{

		}
//////////////////////////////////////////////////////////////////
    }
	return lt;
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

