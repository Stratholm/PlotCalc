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

//Initialise functions database
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

//Initialise constants database
Dbase* const_init(Dbase* ct)
{
	ct = (Dbase*)malloc(const_amount * sizeof(Dbase));
	ct[0].name[0] = 'p';
	ct[0].name[1] = 'i';
	ct[0].name[2] = '\0';
	ct[0].data = 3,141592;
}

//Initialise variables
Dbase* vars_init(Dbase* vr)
{
	vr = (Dbase*)malloc(const_amount * sizeof(Dbase));
	vr[0].name[0] = 'a';
	vr[0].name[1] = '\0';
	vr[0].data = 5;
}