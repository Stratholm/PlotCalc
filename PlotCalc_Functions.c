/*Includes*/
#include "PlotCalc_Head.h"

/*Main variables defenition*/
int exit = 0;
double m = 0;
char c = ' ';
char string[awruk_size] = "";
int i = 0;
List plots;
List ariph;
List vars;
Note* Pointer_plots;
Note* Pointer_ariph;
Note* Pointer_vars;

/*Functions*/
//Input string to infix notation
List* str_to_inf(char* in)
{

}

//Queue to postfix
List* inf_to_post(List* inf)
{

}

//Calculate postfix
double post_calc(List* post)
{

}

//Transferes answer to the rational form
Rat_num ans_to_rat(double ans)
{

}

//Open sessinon to save
int session_open()
{

}

//Save plot
int plot_save(Note* point)
{

}

//Close session of storage
int session_close(List* ariph, List* var)
{

}

//Exit screen
void interface_exit()
{
	/*
	Print "Are u sure you want to exit? Press Enter to exit.
	*/
}

//(Main/ariph count) screen  help
void interface_help_main()
{
	/*
	cls
	print:
	{
	Calculator, plots builder.
	--------------------------------
	Insert ariphmetical expression you want to calculate,
	or plot formula you want to visualise.
	You can save %d (var_amount) constants, build %d (plot_amount) plots at the same time.
	To save constant, print: "constant_name" = "value". 
	"constant_name" should take one latin latter.
	Keys:
	Enter - Calculate/Build
	Esc   - Exit
	F1    - Watch help
	Tab   - Watch variables
	Alt   - Push value in memory
	Space - Recall memory
	Del   - Clean memory
	/^/   - Previous ariphmetical expression
	/v/   - Next ariphmetical expression
	}
	getch
	*/
}