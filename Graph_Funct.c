//Graph_Funct.c - file, that contains functions, which works with graphics. Cinderella cage. Moria's temple is awesome.

/*Defines*/
#define _WIN32_WINNT 0x0500

/*Includes*/
#include "Graph_Head.h"

/*Functions*/
//Main console initialization
int interface_main(Note* point, char *str, double M)   //Str - text, after ">"
{
    const int NotUsed = system( "color F0" );
    HWND hWnd = GetConsoleWindow();
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD sz=GetLargestConsoleWindowSize(hStdOut);
    SMALL_RECT  DisplayArea;
    HDC hdc=GetDC(GetConsoleWindow());
    HBRUSH BrushClear = CreateSolidBrush(RGB(255,255,255));  //You are fucked, if you have error here. Include "gdi32" in builder.
    RECT RectClear;
    sz.X=100;
    sz.Y=50;
    DisplayArea.Left=0;
    DisplayArea.Top=0;
    DisplayArea.Right=sz.X-1;
    DisplayArea.Bottom=sz.Y-1;
    if(!SetConsoleScreenBufferSize(hStdOut,sz)) return 1;
    if(!MoveWindow(hWnd,283,54,800,600,TRUE)) return 2;
    if(!SetConsoleWindowInfo(hStdOut,TRUE,&DisplayArea)) return 3;
    RectClear.top=0;
    RectClear.left=0;
    RectClear.bottom=600;
    RectClear.right=800;
    FillRect(hdc,&RectClear, BrushClear);
    system("cls");
    SetPixel(hdc,-1,-1,0);
    printf(">%s",str);
    //SetConsoleTextAttribute(hStdOut,BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_RED|BACKGROUND_INTENSITY);
    TextOutA(hdc,10,577,"Tab - variables",15);
    TextOutA(hdc,730,577,"F1 - Help",9);
    SetBkMode(hdc,TRANSPARENT);
    if (M==0) SetTextColor(hdc,RGB(192,192,192));
    TextOutA(hdc,396,577,"M",1);
    SetPixel(hdc,-1,-1,0);
    return 0;
}

//Drawing asix
int graph_draw_asix(int right, int up)  //right(up) - number of times, that user presses Right-Left/Up-Down
{
    int i;
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    HDC hdc=GetDC(GetConsoleWindow());
    HBRUSH BrushClear = CreateSolidBrush(RGB(255,255,255));  //You are fucked, if you have error here. Include "gdi32" in builder.
    RECT RectClear;
    HPEN PenAsix=CreatePen(0,3,RGB(0,0,0)), PenAsiA=CreatePen(0,1,RGB(200,200,200));
    RectClear.top=0;
    RectClear.left=0;
    RectClear.bottom=600;
    RectClear.right=800;
    FillRect(hdc,&RectClear, BrushClear);
    system("cls");
    SelectObject(hdc,PenAsiA);
    for (i=0; i<17; i++)
    {
        MoveToEx(hdc,50*i,0,NULL);
        LineTo(hdc,50*i,600);
    }
    for (i=0; i<13; i++)
    {
        MoveToEx(hdc,0,50*i,NULL);
        LineTo(hdc,800,50*i);
    }
    SelectObject(hdc,PenAsix);
    MoveToEx(hdc,400+50*right,0,NULL);
    LineTo(hdc,400+50*right,600);
    MoveToEx(hdc,0,300-50*up,NULL);
    LineTo(hdc,800,300-50*up);
    return 0;
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
    TextOutA(hdc,250,308,"Shift----- Recall memory",24);
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
