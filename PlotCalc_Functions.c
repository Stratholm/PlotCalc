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
    system("cls");
    HDC hdc=GetDC(GetConsoleWindow());
    HBRUSH BrushClear = CreateSolidBrush(RGB(255,255,255));  //You are fucked, if you have error here. Include "gdi32" in builder.
    RECT RectClear;
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
    system("cls");
    HDC hdc=GetDC(GetConsoleWindow());
    HBRUSH BrushClear = CreateSolidBrush(RGB(255,255,255));  //You are fucked, if you have error here. Include "gdi32" in builder.
    RECT RectClear;
    RectClear.top=0;
    RectClear.left=0;
    RectClear.bottom=600;
    RectClear.right=800;
    FillRect(hdc,&RectClear, BrushClear);
    TextOutA(hdc,250,100,"Calculator, plots builder.",26);
    TextOutA(hdc,250,116,"----------------------------------------------------------------------------------",55);
    TextOutA(hdc,250,132,"Insert ariphmetical expression you want to calculate,",53);
    TextOutA(hdc,250,148,"or plot formula you want to visualise.",38);
    char *gig;
    gig=(char*)malloc(127*sizeof(char));
    sprintf(gig,"You can save %d constants, build %d plots at the same time.",var_amount,plot_amount);
    TextOutA(hdc,250,164,gig,strlen(gig));
    TextOutA(hdc,250,180,"To save constant, print: \"constant_name\" = \"value\".",51);
    TextOutA(hdc,250,196,"\"constant_name\" should take one latin latter.",45);
    TextOutA(hdc,250,212,"Keys:",5);
    TextOutA(hdc,250,228,"Enter - Calculate/Build",23);
    TextOutA(hdc,250,244,"Esc   - Exit",12);
    TextOutA(hdc,250,260,"F1    - Watch help",18);
    TextOutA(hdc,250,276,"Tab   - Watch variables",23);
    TextOutA(hdc,250,292,"Alt   - Push value in memory",28);
    TextOutA(hdc,250,308,"Space - Recall memory",21);
    TextOutA(hdc,250,324,"Del   - Clean memory",20);
    TextOutA(hdc,250,340,"Up    - Previous ariphmetical expression",30);
    TextOutA(hdc,250,356,"Down  - Next ariphmetical expression",30);
    SetPixel(hdc,-1,-1,0);
    _getch();
    interface_main("",0);

}

//Analyse string and calculate/save/build
int string_analyse(char* str, Note* point)
{

}
