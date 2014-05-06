/*Includes*/
#include "PlotCalc_Head.h"

/*Main variables defenition*/
int e = 0;
double M = 0;
char c = ' ';
char string[awruk_size] = "";
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

//Exit screen
void interface_exit()
{
    HDC hdc=GetDC(GetConsoleWindow());
    HBRUSH BrushClear = CreateSolidBrush(RGB(255,255,255));  //You are fucked, if you have error here. Include "gdi32" in builder.
    RECT RectClear;
    system("cls");
    RectClear.top=0;
    RectClear.left=0;
    RectClear.bottom=600;
    RectClear.right=800;
    FillRect(hdc,&RectClear, BrushClear);
    TextOutA(hdc,250,250,"Are you sure you want to exit the program?",42);
    TextOutA(hdc,320,266,"Press 'Enter' to exit.",22);
    SetPixel(hdc,-1,-1,0);
}

//(Main/ariph count) screen  help
void interface_help_main()
{
    HDC hdc=GetDC(GetConsoleWindow());
    HBRUSH BrushClear = CreateSolidBrush(RGB(255,255,255));  //You are fucked, if you have error here. Include "gdi32" in builder.
    RECT RectClear;
    char *gig;
    system("cls");
    RectClear.top=0;
    RectClear.left=0;
    RectClear.bottom=600;
    RectClear.right=800;
    FillRect(hdc,&RectClear, BrushClear);
    TextOutA(hdc,250,100,"Calculator, plots builder.",26);
    TextOutA(hdc,250,116,"----------------------------------------------------------------------------------",55);
    TextOutA(hdc,250,132,"Insert ariphmetical expression you want to calculate,",53);
    TextOutA(hdc,250,148,"or plot formula you want to visualise.",38);
    gig=(char*)malloc(127*sizeof(char));
    sprintf(gig,"You can save %d constants, build %d plots at the same time.",var_amount,plot_amount);
    TextOutA(hdc,250,164,gig,strlen(gig));
    TextOutA(hdc,250,180,"To save constant, print: \"constant_name\" = \"value\".",51);
    TextOutA(hdc,250,196,"\"constant_name\" should take one latin latter.",45);
    TextOutA(hdc,250,212,"Keys:",5);
    TextOutA(hdc,250,228,"Enter------ Calculate/Build",27);
    TextOutA(hdc,250,244,"Esc--------- Exit",17);
    TextOutA(hdc,250,260,"F1----------- Watch help",24);
    TextOutA(hdc,250,276,"Tab--------- Watch variables",28);
    TextOutA(hdc,250,292,"Alt----------- Push value in memory",35);
    TextOutA(hdc,250,308,"Space----- Recall memory",24);
    TextOutA(hdc,250,324,"Del---------- Clean memory",26);
    TextOutA(hdc,250,340,"Up----------- Previous ariphmetical expression",46);
    TextOutA(hdc,250,356,"Down------- Next ariphmetical expression",40);
    SetPixel(hdc,-1,-1,0);
    _getch();
}

//Plots screen help
void interface_help_plots()
{
    HDC hdc=GetDC(GetConsoleWindow());
    HBRUSH BrushClear = CreateSolidBrush(RGB(255,255,255));  //You are fucked, if you have error here. Include "gdi32" in builder.
    RECT RectClear;
    system("cls");
    RectClear.top=0;
    RectClear.left=0;
    RectClear.bottom=600;
    RectClear.right=800;
    FillRect(hdc,&RectClear, BrushClear);
    TextOutA(hdc,250,100,"Plots builder help:",19);
    TextOutA(hdc,250,116,"----------------------------------------------------------------------------------",55);
    TextOutA(hdc,250,132,"Keys:",5);
    TextOutA(hdc,250,148,"Enter------ Calculate/Build",27);
    TextOutA(hdc,250,164,"Esc--------- Exit",17);
    TextOutA(hdc,250,180,"Tab--------- Plots List",23);
    TextOutA(hdc,250,196,"F1----------- Watch help",24);
    TextOutA(hdc,250,212,"\"+\"---------- Enlarge scale",27);
    TextOutA(hdc,250,228,"\"-\"----------- Decrease scale",29);
    TextOutA(hdc,250,244,"Up----------- Previous ariphmetical expression",46);
    TextOutA(hdc,250,260,"Down------- Next ariphmetical expression",40);
    TextOutA(hdc,250,276,"Right-------- Move Asix right",29);
    TextOutA(hdc,250,292,"Left---------- Move Asix left",29);
    SetPixel(hdc,-1,-1,0);
    _getch();
}

//Analyse string and calculate/save/build
int string_analyse(char* str, Note* point)
{

}
