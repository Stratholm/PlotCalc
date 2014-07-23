/*Includes*/
#include "PlotCalc_Head.h"
#include "computation_core_head.h"

/*Main variables defenition*/
int e = 0;
double M = 0;
char c = 0;
int message = 0;
char string[awruk_size] = {'\0'};
int i = 0;
int symbol = 0;
List plot_list;
List ariph;
List plot;
List* postfix;
List ariph_list;
List empty;
Note* Pointer_plots;
Note* Pointer_ariph = NULL;
Note* Pointer_vars;
Dbase* database_func;
Dbase* database_const;
Dbase* vars;
int sym_allow[sym_allow_quant];
int var_amount = 0;
int coordinates[screen_width];
int push_right = 0;
int push_up = 0;
double resize = cell;


/*Functions*/
//Open sessinon to save
int session_open()
{
	/*opens files*/
	return 1;
}

//Save plot
int plot_save(Note* point)
{
	return 1;
}

//Close session of storage
int session_close(List* ariph, List* var)
{
	/*saves the rest*/
	return 1;
}

//Analyse string and calculate/save/build
int string_analyse(char* str, Note* point, Dbase* fc, Dbase* ct, Dbase* vr, int var_amount)
{
	int i = 0;
	int amount = 0;
	int strl = strlen(str);
	if (point == NULL)			//check if there is no output now
	{
		if (strl == 0)			//empty string
		{
			return ERR_EMPTY;
		}
		else
		{
			while (i < strl)		//check content of the string
			{
				c = str[i];
				if (c < 0)				//kirillic alphabit
					return ERR_SPEC;
				if ((((c >= 34) && (c <= 39)) || (c == 44)) || (((c >= 58) && (c <= 64)) && (c != 61)) || (((c >= 91) && (c <= 96)) && (c != 94)))
					return ERR_SPEC;		//not allowed symbols filter
				if ((i > dbase_name_len) && (str[i] == '='))	//"=" in imossibru place
					return ERR_LONG_VAR;
				if (str[i] == '=')			//muilty "="
				{
					amount++;
					if (amount > 1)
						return ERR_EQUAS;
				}
				if (c == 'x')						//function if content "x"
					return FUNC;
				if ((i == strl - 1) && (amount == 1))	//variable if content single "="
					return VAR;
				i++;
			}
			return ARIPH;						//else ariphmetical
		}
	}
	else
	return NULL;					//else clean output
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
	ct[1].name[0] = 'e';
	ct[1].name[1] = '\0';
	ct[1].data = 2.7182818284;
	return 0;
}

//Initialise variables
void vars_init(Dbase* vr)
{
	vr = (Dbase*)malloc(var_max_amount * sizeof(Dbase));
}

//Recalculate plots
int plots_recalc(List* plot_list, double* ans, int* coord, int* mess, double resz, int up, int right)
{
	Note* Pointer_plots = (Note*)malloc(sizeof(Note));
	Pointer_plots = plot_list->head;
	while (Pointer_plots != NULL)
	{
		post_calc(&(((Plot*)(Pointer_plots->data))->postfix), ans, ((Plot*)(Pointer_plots->data))->coord, &message, resize, push_up, push_right);
		Pointer_plots = Pointer_plots->next;
	}
	return 1;
}

//Delete all history
int recent_del(List* ariph, List* plot, Dbase* var, Note* point, int* var_amount)
{
	queue_create(ariph);
	queue_create(plot);
	free(var);
	*var_amount = 0;
	point = NULL;
	return 1;
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
