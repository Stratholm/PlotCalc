//Graph_Funct.c - file, that contains functions, which works with graphics. Cinderella cage. Moria's temple is awesome.

/*Defines*/
#define _WIN32_WINNT 0x0500

/*Includes*/
#include "Graph_Head.h"

/*Functions*/
int interface_main(char *Str,double m)   //Str - text, after ">"
{
    const int NotUsed = system( "color F0" );
    HWND hWnd = GetConsoleWindow();
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD sz=GetLargestConsoleWindowSize(hStdOut);
    sz.X=100;
    sz.Y=50;
    SMALL_RECT  DisplayArea;
    DisplayArea.Left=0;
    DisplayArea.Top=0;
    DisplayArea.Right=sz.X-1;
    DisplayArea.Bottom=sz.Y-1;
    if(!SetConsoleScreenBufferSize(hStdOut,sz)) return 1;
    if(!MoveWindow(hWnd,283,54,800,600,TRUE)) return 2;
    if(!SetConsoleWindowInfo(hStdOut,TRUE,&DisplayArea)) return 3;
    HDC hdc=GetDC(GetConsoleWindow());
    HBRUSH BrushClear = CreateSolidBrush(RGB(255,255,255));  //You are fucked, if you have error here. Include "gdi32" in builder.
    RECT RectClear;
    RectClear.top=0;
    RectClear.left=0;
    RectClear.bottom=600;
    RectClear.right=800;
    FillRect(hdc,&RectClear, BrushClear);
    system("cls");
    SetPixel(hdc,-1,-1,0);
    printf(">%s",Str);
    //SetConsoleTextAttribute(hStdOut,BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_RED|BACKGROUND_INTENSITY);
    TextOutA(hdc,10,577,"Tab - variables",15);
    TextOutA(hdc,730,577,"F1 - Help",9);
    SetBkMode(hdc,TRANSPARENT);
   // if (m==0) SetTextColor(hdc,RGB(192,192,192));
    if (m!=0) TextOutA(hdc,396,577,"M",1);
    SetPixel(hdc,-1,-1,0);
    return 0;
}

int graph_draw_asix(int right, int up)  //right(up) - number of times, that user presses Right-Left/Up-Down
{
    int i;
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    HDC hdc=GetDC(GetConsoleWindow());
    HBRUSH BrushClear = CreateSolidBrush(RGB(255,255,255));  //You are fucked, if you have error here. Include "gdi32" in builder.
    RECT RectClear;
    RectClear.top=0;
    RectClear.left=0;
    RectClear.bottom=600;
    RectClear.right=800;
    FillRect(hdc,&RectClear, BrushClear);
    system("cls");
    HPEN PenAsix=CreatePen(0,3,RGB(0,0,0)), PenAsiA=CreatePen(0,1,RGB(200,200,200));
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
