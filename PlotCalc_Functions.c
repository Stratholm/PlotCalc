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
Func* database_func;
Const constants[32];


/*Functions*/
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

//Analyse string and calculate/save/build
int string_analyse(char* str, Note* point, List *ariph)
{

}

//Initialise database
Func* func_init(Func* fc)
{
	fc = (Func*)malloc(func_amount * sizeof(Func));
	fc[0].name[0] = '+';
	fc[0].name[1] = '\0';
	fc[0].prior = 1;
	fc[1].name[0] = '-';
	fc[1].name[1] = '\0';
	fc[1].prior = 1;
	return fc;
}
