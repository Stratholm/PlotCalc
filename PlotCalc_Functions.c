/*Includes*/
#include "PlotCalc_Head.h"

/*Main variables defenition*/
int e = 0;
double M = 0;
char c = ' ';
int message = 0;
char string[awruk_size] = {'\0'};
int i = 0;
List plot_list;
List ariph;
List plot;
List* postfix;
List ariph_list;
Note* Pointer_plots;
Note* Pointer_ariph = NULL;
Note* Pointer_vars;
Dbase* database_func;
Dbase* database_const;
Dbase* vars;
int sym_allow[sym_allow_quant];
int var_amount = 0;
long long int coordinates[width];
int push_right = 0;
int push_up = 0;
double resize = 50;


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
int string_analyse(char* str, Note* point, Dbase* fc, Dbase* ct, Dbase* vr, int var_amount)
{
	int i = 0;
	int amount = 0;
	if (point == NULL)
	{
		if (strlen(str) == 0)			//empty string
		{
			return ERR_EMPTY;
		}
		else
		{
			while (i <= strlen(str))		//check alphabit
			{
				if ((((c >= 34) && (c <= 39)) || (c == 44)) || (((c >= 58) && (c <= 64)) && (c != 61)) || (((c >= 91) && (c <= 96)) && (c != 94)))	
					return ERR_SPEC;
				if ((i >= dbase_name_len) && (str[i] == 61))
					return ERR_EQUAS;
				if (str[i] == 61)
				{
					if (amount > 1)
						return ERR_EQUAS;
					amount++;
				}
				if ((i == 0) && (str[i] == 'y') && (str[i+1] == '='))
					return FUNC;
				i++;
			}
			return ARIPH;
		}
	}
	else
	return NULL;
}

//Initialise functions database
Dbase* func_init(Dbase* fc)
{
	fc = (Dbase*)malloc(func_amount * sizeof(Dbase));
	fc[0].name[0] = '(';
	fc[0].name[1] = '\0';
	fc[0].data = 0;
	fc[1].name[0] = ')';
	fc[1].name[1] = '\0';
	fc[1].data = 0;
	fc[2].name[0] = '+';
	fc[2].name[1] = '\0';
	fc[2].data = -1;
	fc[3].name[0] = '-';
	fc[3].name[1] = '\0';
	fc[3].data = -1;
	fc[4].name[0] = '*';
	fc[4].name[1] = '\0';
	fc[4].data = -2;
	fc[5].name[0] = '/';
	fc[5].name[1] = '\0';
	fc[5].data = -2;
	fc[6].name[0] = '^';
	fc[6].name[1] = '\0';
	fc[6].data = 3;
	fc[7].name[0] = 'l';
	fc[7].name[1] = 'n';
	fc[7].name[2] = '\0';
	fc[7].data = 2;
	fc[8].name[0] = 'l';
	fc[8].name[1] = 'o';
	fc[8].name[2] = 'g';
	fc[8].name[3] = '\0';
	fc[8].data = 2;
	fc[9].name[0] = 's';
	fc[9].name[1] = 'q';
	fc[9].name[2] = 'r';
	fc[9].name[3] = 't';
	fc[9].name[4] = '\0';
	fc[9].data = 2;
	fc[10].name[0] = 'c';
	fc[10].name[1] = 'o';
	fc[10].name[2] = 's';
	fc[10].name[3] = '\0';
	fc[10].data = 2;
	fc[11].name[0] = 's';
	fc[11].name[1] = 'i';
	fc[11].name[2] = 'n';
	fc[11].name[3] = '\0';
	fc[11].data = 2;
	fc[12].name[0] = 't';
	fc[12].name[1] = 'a';
	fc[12].name[2] = 'n';
	fc[12].name[3] = '\0';
	fc[12].data = 2;
	fc[13].name[0] = 'c';
	fc[13].name[1] = 't';
	fc[13].name[2] = 'g';
	fc[13].name[3] = '\0';
	fc[13].data = 2;
	return fc;
}

//Initialise constants database
Dbase* const_init(Dbase* ct)
{
	ct = (Dbase*)malloc(const_amount * sizeof(Dbase));
	ct[0].name[0] = 'p';
	ct[0].name[1] = 'i';
	ct[0].name[2] = '\0';
	ct[0].data = 3.1415926535;
}

//Initialise variables
Dbase* vars_init(Dbase* vr)
{
	vr = (Dbase*)malloc(const_amount * sizeof(Dbase));
	vr[0].name[0] = 'a';
	vr[0].name[1] = '\0';
	vr[0].data = 5;
	vr[1].name[0] = 'b';
	vr[1].name[1] = '\0';
	vr[1].data = 2;
}


//
////Initialize allowed symbols
//void sym_allow_init(int* sm)
//{
//	int i = 0;
//	int c = 33;
//	while (i <= sym_allow_quant)
//	{
//		if ((((c >= 34) && (c <= 39)) || (c == 44)) || (((c >= 58) && (c <= 64)) && (c != 61)) || (((c >= 91) && (c <= 96)) && (c != 94)))
//		{
//			c++;
//			continue;
//		}
//		else
//		{
//			sm[i] = c;
//			i++;
//			c++;
//		}
//	}
//}