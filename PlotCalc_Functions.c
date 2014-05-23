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
Note* Pointer_plots;
Note* Pointer_ariph = NULL;
Note* Pointer_vars;
Dbase* database_func;
Dbase* database_const;
Dbase* vars;


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
Dbase* func_init(Dbase* fc)
{
	fc = (Dbase*)malloc(func_amount * sizeof(Dbase));
	fc[0].name[0] = '+';
	fc[0].name[1] = '\0';
	fc[0].data = 1;
	fc[1].name[0] = '-';
	fc[1].name[1] = '\0';
	fc[1].data = 1;
	fc[2].name[0] = 'l';
	fc[2].name[1] = 'o';
	fc[2].name[2] = 'l';
	fc[2].name[3] = '\0';
	fc[1].data = 2;
	return fc;
}
