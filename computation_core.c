#include "comutation_core_head.h"

/* Functions */
//Input string to infix notation
List* str_to_inf(char* in)
{
	int i;
	List* lt;
    while (1) 
	{
        int c = *(in++);
        if (c == '\0') 
		{
            return 0;
        }
		else 
			if (isspace(c)) 
			{
				continue;
			} else 
				if (isdigit(c)) 
				{
					int num = c - '0';
					while (isdigit(*(lex->str))) {
					num = num * 10 + *(lex->str++) - '0';
				}
            lex->number = num;
            return lex->token = NUM;
        } else {
            return lex->token = c;
        }
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
Rat_num ans_to_rat(double ans)
{
	/*Used inside string_analyse by ariph*/
}