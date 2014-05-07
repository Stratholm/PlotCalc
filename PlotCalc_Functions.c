/*Includes*/
#include "PlotCalc_Head.h"

/*Main variables defenition*/
int e = 0;
double M = 0;
char c = ' ';
char string[awruk_size] = {'\0'};
int i = 0;
List plots;
List ariph;
List vars;
Note* Pointer_plots;
Note* Pointer_ariph = NULL;
Note* Pointer_vars;

/*Functions*/
//Input string to infix notation
List* str_to_inf(char* in)
{
	/*Used inside string_analyse*/
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

//Open sessinon to save
int session_open()
{
	/*opens files*/
}

//Save plot
int plot_save(Note* point)
{

}

//Close session of storage
int session_close(List* ariph, List* var)
{
	/*saves the rest*/
}

//Variables list
void interface_list_vars(List* var)
{
	/**/
}

//Analyse string and calculate/save/build
int string_analyse(char* str, Note* point)
{

}
