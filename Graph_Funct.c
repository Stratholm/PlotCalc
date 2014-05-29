//Graph_Funct.c - file, that contains functions, which works with graphics. Cinderella cage. Moria's temple is awesome.

/*Defines*/
#define _WIN32_WINNT 0x0500

/*Includes*/
#include "Graph_Head.h"
HDC hdc;
/*Functions*/
//First Buffer Initialize
void screen_first_init()
{
	SMALL_RECT  DisplayArea;
	COORD sz;
    const int NotUsed = system( "color F0" );
    HWND hWnd = GetConsoleWindow();
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO structCursorInfo;
    hdc=GetDC(hWnd);
    sz=GetLargestConsoleWindowSize(hStdOut);
    sz.X=100;
    sz.Y=50;
    DisplayArea.Left=0;
    DisplayArea.Top=0;
    DisplayArea.Right=sz.X-1;
    DisplayArea.Bottom=sz.Y-1;
    SetConsoleScreenBufferSize(hStdOut,sz);
    MoveWindow(hWnd,283,54,800,600,TRUE);
    SetConsoleWindowInfo(hStdOut,TRUE,&DisplayArea);
    GetConsoleCursorInfo(hStdOut,&structCursorInfo);
    structCursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(hStdOut, &structCursorInfo );
    SetBkMode(hdc,TRANSPARENT);
}

//Clear Screen
void screen_clear()
{
    HBRUSH BrushClear = CreateSolidBrush(RGB(255,255,255));  //You are fucked, if you have error here. Include "gdi32" in builder.
    RECT RectClear;
    RectClear.top=0;
    RectClear.left=0;
    RectClear.bottom=600;
    RectClear.right=800;
    FillRect(hdc,&RectClear, BrushClear);
    SetPixel(hdc,-1,-1,0);
}

//creates frame
void screen_frame_create()
{
    HBRUSH BrushGrey = CreateSolidBrush(RGB(128,128,128));  //You are fucked, if you have error here. Include "gdi32" in builder.
    RECT RectDraw;
    RectDraw.top=0;
    RectDraw.left=0;
    RectDraw.bottom=50;
    RectDraw.right=800;
    FillRect(hdc,&RectDraw, BrushGrey);
    RectDraw.top=0;
    RectDraw.left=0;
    RectDraw.bottom=600;
    RectDraw.right=50;
    FillRect(hdc,&RectDraw, BrushGrey);
    RectDraw.top=550;
    RectDraw.left=0;
    RectDraw.bottom=600;
    RectDraw.right=800;
    FillRect(hdc,&RectDraw, BrushGrey);
    RectDraw.top=0;
    RectDraw.left=750;
    RectDraw.bottom=600;
    RectDraw.right=800;
    FillRect(hdc,&RectDraw, BrushGrey);
    SetPixel(hdc,-1,-1,0);
}


//Main console initialization
void interface_main(Note* point, char *str, double M, List* ariph, List* plots, Dbase* vars)   //Str - text, after ">"
{
	char *_strtmp=(char*)malloc(100*sizeof(char));
	HPEN PenAsiA=CreatePen(0,1,RGB(128,128,128));
	int _tmp_i=0;
	Note *tmp_ariph;
	Note *tmp_plot;
	if (ariph!=NULL) tmp_ariph=ariph->head;
	if (plots!=NULL) tmp_plot=plots->head;
    screen_clear();
	screen_frame_create();
	SelectObject(hdc,PenAsiA);
    if (point==NULL)
	{
		sprintf(_strtmp,">%s",str);
		TextOutA(hdc,53,53,_strtmp,strlen(_strtmp));
	}
    if (point!=NULL)
    {
        sprintf(_strtmp,">%s",(char*)point->data);
        TextOutA(hdc,53,53,_strtmp,strlen(_strtmp));
        sprintf(_strtmp,"Answer: %d",point->num);
        TextOutA(hdc,50,86,_strtmp,strlen(_strtmp));
    }
    MoveToEx(hdc,50,122,NULL);
    LineTo(hdc,750,122);
    MoveToEx(hdc,50,147,NULL);
    LineTo(hdc,750,147);
    MoveToEx(hdc,50,525,NULL);
    LineTo(hdc,750,525);
    MoveToEx(hdc,50,500,NULL);
    LineTo(hdc,750,500);
    MoveToEx(hdc,400,122,NULL);
    LineTo(hdc,400,525);
    MoveToEx(hdc,620,122,NULL);
    LineTo(hdc,620,525);
    TextOutA(hdc,53,127,"Previous calculations:",22);
    TextOutA(hdc,403,127,"Functions",9);
    TextOutA(hdc,623,127,"Variables",9);
    TextOutA(hdc,53,505,"Del - to clear",14);
    TextOutA(hdc,403,505,"to edit",7);
    TextOutA(hdc,623,505,"to edit",7);
    TextOutA(hdc,53,530,"Tab - switch to plots",21);
    TextOutA(hdc,690,530,"F1 - Help",9);
    if (tmp_ariph!=NULL)
    {
    while (tmp_ariph->next!=NULL)
    {
        sprintf(_strtmp,"%s",((Ariph*)(tmp_ariph->data))->string);
        TextOutA(hdc,53,150+48*_tmp_i,_strtmp,strlen(_strtmp));
        sprintf(_strtmp,"Answer: %f",((Ariph*)(tmp_ariph->data))->ans);
        TextOutA(hdc,53,150+48*_tmp_i+16,_strtmp,strlen(_strtmp));
        tmp_ariph=tmp_ariph->next;
        _tmp_i++;
    }
        sprintf(_strtmp,"%s",((Ariph*)(tmp_ariph->data))->string);
        TextOutA(hdc,53,150+48*_tmp_i,_strtmp,strlen(_strtmp));
        sprintf(_strtmp,"Answer: %f",((Ariph*)(tmp_ariph->data))->ans);
        TextOutA(hdc,53,150+48*_tmp_i+16,_strtmp,strlen(_strtmp));
    }
    if (tmp_plot!=NULL)
    {
    while (tmp_plot->next!=NULL)
    {
        sprintf(_strtmp,"%s",((Plot*)(tmp_plot->data))->string);
        TextOutA(hdc,403,150+32*_tmp_i,_strtmp,strlen(_strtmp));
        tmp_ariph=tmp_ariph->next;
        _tmp_i++;
    }
        sprintf(_strtmp,"%s",((Plot*)(tmp_plot->data))->string);
        TextOutA(hdc,403,150+32*_tmp_i,_strtmp,strlen(_strtmp));
    }
    _tmp_i=0;
    while (_tmp_i<var_amount)
    {
        sprintf(_strtmp,"%s = %f",vars[_tmp_i].name,vars[_tmp_i].data);
        TextOutA(hdc,623,150+32*_tmp_i,_strtmp,strlen(_strtmp));
        i++;
    }
    if (M==0) SetTextColor(hdc,RGB(192,192,192));
    TextOutA(hdc,396,530,"M",1);
    SetTextColor(hdc,RGB(0,0,0));
    SetPixel(hdc,-1,-1,0);
}

//Drawing asix
void graph_draw_asix(int right, int up)  //right(up) - number of times, that user presses Right-Left/Up-Down
{
    int i;
    HPEN PenAsix=CreatePen(0,3,RGB(0,0,0)), PenAsiA=CreatePen(0,1,RGB(200,200,200));
    screen_clear();
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
}

//Drawing graphs
void graph_draw_graps(List plots)
{
    HPEN PenAsix=CreatePen(0,2,RGB(255,0,0));
    int tmp_clr[16]={RGB(255,0,0),RGB(0,255,0),RGB(0,0,255),RGB(0,0,0),RGB(0,0,0),RGB(0,0,0),RGB(0,0,0),RGB(0,0,0),RGB(0,0,0),RGB(0,0,0),RGB(0,0,0),RGB(0,0,0),RGB(0,0,0),RGB(0,0,0),RGB(0,0,0),RGB(0,0,0)};
    int tmp_i;
    Note *tmp_R = plots.head;
    while (tmp_R->next!=NULL)
    {
        PenAsix=CreatePen(0,2,tmp_clr[tmp_R->num-1]);
        SelectObject(hdc,PenAsix);
        for(tmp_i=0;tmp_i<799;tmp_i++)
        {
            MoveToEx(hdc,tmp_i+1,((Plot*)(tmp_R->data))->coord[tmp_i],NULL);
            LineTo(hdc,tmp_i+2,((Plot*)(tmp_R->data))->coord[tmp_i+1]);
        }
        tmp_R=tmp_R->next;
    }
    if (tmp_R!=NULL)
    {
        PenAsix=CreatePen(0,2,tmp_clr[tmp_R->num-1]);
        SelectObject(hdc,PenAsix);
        for(tmp_i=0;tmp_i<799;tmp_i++)
        {
            MoveToEx(hdc,tmp_i+1,((Plot*)(tmp_R->data))->coord[tmp_i],NULL);
            LineTo(hdc,tmp_i+2,((Plot*)(tmp_R->data))->coord[tmp_i+1]);
        }
    }
}

//Exit screen
void interface_exit()
{
    //HDC hdc=GetDC(GetConsoleWindow());
    screen_clear();
    system("cls");
    screen_frame_create();
    TextOutA(hdc,250,250,"Are you sure you want to exit the program?",42);
    TextOutA(hdc,320,266,"Press 'Enter' to exit.",22);
    SetPixel(hdc,-1,-1,0);
}

//(Main/ariph count) screen  help
void interface_help_main()
{
    char *gig;
    screen_clear();
    screen_frame_create();
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
    screen_clear();
    screen_frame_create();
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

//Variables list
void interface_list_vars(Dbase* var)
{
	char _tmp_c;
	int _tmp_i=0;
	screen_clear();
  screen_frame_create();
	system("cls");
    printf("List of variables:\n");
    if (var==NULL)
    {
        printf("There are no plots!");
        getch();
        return;
    }
    while (_tmp_i<var_amount)
    {
        printf("%d ",_tmp_i+1);
        printf("%s ",var[_tmp_i].name);
        printf("%f\n",var[_tmp_i].data);
        i++;
    }
    switch(_tmp_c=getch())
    {
    case -32:
        {
			int _tmp_n;
            _tmp_c=getch();
            if (_tmp_c==83)
            {
            printf("Please, enter the number of variable, that you want to delete:\n");
            scanf("%d",&_tmp_n);
            for (_tmp_i=_tmp_n;_tmp_i<var_amount;_tmp_i++)
                var[_tmp_i-1]=var[_tmp_i];
                var_amount++;
            }
        }
        default: return;
    }
}

//Plots list
void interface_list_plots(List* plot)
{
	char _tmp_c;
	Note *provd;
	screen_clear();
	screen_frame_create();
	system("cls");
    provd = plot->head;
    printf("List of variables:\n");
    if (plot->head==plot->tail)
    {
            printf("There are no plots!");
            getch();
            return;
    }
    while (provd!=plot->tail)
    {
        printf("%d ",provd->num);
        printf("%s ",((Plot*)(provd->data))->string);
        provd=provd->next;
    }
    printf("%d ",provd->num);
    printf("%s ",((Plot*)(provd->data))->string);
    switch(_tmp_c=getch())
    {
    case -32:
        {
			int _tmp_n;
            _tmp_c=getch();
            if (_tmp_c==83)
            {
            printf("Please, enter the number of plot, that you want to delete:\n");
            scanf("%d",&_tmp_n);
            queue_el_del(plot,_tmp_n);
            }
        }
        default: return;
    }
}
