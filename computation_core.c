#include "computation_core_head.h"

/* Functions */
//Input string to infix notation
List str_to_inf(char* in)
{
	int i = 0;
	Element el; 
	List lt;
	int l;
	l = strlen(in);
	//lt = (List*)malloc(sizeof(List));
	queue_create(&lt);
    while (i <= strlen(in)) 
	{
		if (in[i] == ' ') 
		{
			i++;
		} 
		else
		if (isdigit(in[i])) 
		{
			int num = in[i] - '0';
			while (isdigit(in[i])) 
			{
				num = num * 10 + (in[i++]) - '0';
			}
			el.key = 0;
			el.data = num;
			queue_add_end(&lt, &el);
			break;
        } 
		else 
		{
            

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

////Transferes answer to the rational form
//Rat_num ans_to_rat(double ans)
//{
//	/*Used inside string_analyse by ariph*/
//}
//
