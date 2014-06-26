//Graph_Funct.c - file, that contains functions, which works with graphics. Cinderella cage. Moria's temple is awesome.

/*Includes*/
#include "Graph_Head.h"

SDL_Window *win;
SDL_Renderer *ren;
TTF_Font *font;
SDL_Color textColor={0,0,0};
SDL_Event event;                //for input

/*Functions*/
//First Buffer Initialize
void screen_first_init()
{
	SDL_Init(SDL_INIT_EVERYTHING);                      //SDL turns on
    win = SDL_CreateWindow("PlotCalc", 100, 100, 800, 600, NULL);       //window is creating
    ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);        //and render
    SDL_SetRenderDrawColor(ren, 255, 255, 255, 0);                  //white is background color
    TTF_Init();                                 //Text turns on
    font=TTF_OpenFont("calibri.ttf",16);           //your font here
    if(!font)printf("Well darn, \n%s",TTF_GetError());         //check on errors
    SDL_RenderClear(ren);                   //clear screen
    SDL_RenderPresent(ren);                 //show window to people
}

//Getch alternative for SDL & Linux
int SDL_getch()
{
    SDL_Keycode code;
    while(1)
    {
    SDL_PollEvent(&event);              //Something happened in the program
    if ((event.type==SDL_KEYDOWN)&&!((event.key.keysym.sym==SDLK_LSHIFT)||(event.key.keysym.sym==SDLK_LSHIFT))) //if it was pressing the button, but not Shifts
    {
    code=event.key.keysym.sym;
    while (event.type==SDL_KEYDOWN) SDL_PollEvent(&event);          //to prevent  crazy stuff with backspases and others
    return code;
    }
    if ((event.type==SDL_KEYDOWN)&&((event.key.keysym.sym==SDLK_LSHIFT)||(event.key.keysym.sym==SDLK_LSHIFT))) //if it were shifts
    while(1)                                                                                        //then do shift
    {
        SDL_PollEvent(&event);
        if (event.type==SDL_KEYDOWN)
        {
        if ((((int)event.key.keysym.sym)>96)&&(((int)event.key.keysym.sym)<123)) return ((int)event.key.keysym.sym)-32; //for letters
        switch(event.key.keysym.sym)                                //for others
        {
            case SDLK_LSHIFT: continue;
            case SDLK_RSHIFT: continue;
            case SDLK_1: return SDLK_EXCLAIM;
            case SDLK_2: return SDLK_AT;
            case SDLK_3: return SDLK_HASH;
            case SDLK_4: return SDLK_DOLLAR;
            case SDLK_5: return SDLK_PERCENT;
            case SDLK_6: return SDLK_CARET;
            case SDLK_7: return SDLK_AMPERSAND;
            case SDLK_8: return SDLK_ASTERISK;
            case SDLK_9: return 40;
            case SDLK_0: return 41;
            case SDLK_MINUS: return SDLK_UNDERSCORE;
            case SDLK_EQUALS: return SDLK_PLUS;
            case SDLK_QUOTE: return SDLK_QUOTEDBL;
            case SDLK_SEMICOLON: return SDLK_COLON;
            case SDLK_COMMA: return SDLK_LESS;
            case SDLK_PERIOD: return SDLK_GREATER;
            case SDLK_SLASH: return SDLK_QUESTION;
            default: return event.key.keysym.sym;
        }
        }
    }

    }
}

//Clear Screen
void screen_clear()
{
    SDL_SetRenderDrawColor(ren, 255, 255, 255, 0);
    SDL_RenderClear(ren);
}

//creates frame
void screen_frame_create()
{
    SDL_SetRenderDrawColor(ren, 128, 128, 128, 255);
    SDL_Rect rect={0,0,800,50};                 //do rects
    SDL_RenderFillRect(ren,&rect);              //fill rects
    rect.x=0; rect.y=0; rect.w=50; rect.h=600;
    SDL_RenderFillRect(ren,&rect);
    rect.x=750; rect.y=0; rect.w=50; rect.h=600;
    SDL_RenderFillRect(ren,&rect);
    rect.x=0; rect.y=550; rect.w=800; rect.h=50;
    SDL_RenderFillRect(ren,&rect);
}

//print analog for SDL
void print_graph(char* Str, int tmX, int tmY)
{
    SDL_Surface* currentCounterSurface;             //surface - is were we print at first
    SDL_Texture *text;                              //texture - is our text
    int texW = 0;
    int texH = 0;
    currentCounterSurface=TTF_RenderText_Solid(font,Str,textColor);         //printing our text
    text = SDL_CreateTextureFromSurface(ren,currentCounterSurface);         //doing text from surfase
    SDL_QueryTexture(text, NULL, NULL, &texW, &texH);                       //mesuring size
    SDL_Rect dstrect = { tmX, tmY, texW, texH };                            //doing place
    SDL_RenderCopy(ren, text, NULL, &dstrect);                               //Printing on window!
    SDL_DestroyTexture(text);
}

//Main console initialization
void interface_main(Note* point, char *str, double M, List* ariph, List* plots, Dbase* vars,int message)   //Str - text, after ">"
{
	char *_strtmp=(char*)malloc(100*sizeof(char));
	int _tmp_i=0;
	Note *tmp_ariph;
	Note *tmp_plot;
	SDL_Color tmp_cololr[11]={{255,0,0},{0,255,0},{0,0,255},{255,127,0},{0,80,0},{127,0,127},{255,90,90},{255,255,0},{127,127,255},{80,80,80},{127,0,0}};       //array of COLORS {rgb}
	if (ariph!=NULL) tmp_ariph=ariph->head;     //if ariph exist, tmp_ariph make head of it (& below)
	if (plots!=NULL) tmp_plot=plots->head;
    screen_clear();
	screen_frame_create();
    if (point==NULL)            //then don't write answer
	{
		sprintf(_strtmp,">%s",str);
		print_graph(_strtmp,53,53);
	}
    if ((point!=NULL)&&(message==0))        //then write answer
    {
        sprintf(_strtmp,">%s",(char*)((Ariph*)(point->data))->string);
        print_graph(_strtmp,53,53);
        sprintf(_strtmp,"Answer: %.2f",((Ariph*)(point->data))->ans);
        print_graph(_strtmp,53,86);
    }
        if (message!=0)             //there isan error
    {
        sprintf(_strtmp,">%s",str);
        print_graph(_strtmp,53,53);
        switch(message)
        {
        case 8:
            {
            print_graph("Empty string!",50,86);
            break;
            }
        case 10:
            {
            print_graph("No special symbols allowed!",50,86);
            break;
            }
        case 11:
            {
            print_graph("Wrong Equasion!",50,86);
            break;
            }
        case 13:
            {
            print_graph("Error!",50,86);
            break;
            }
        case 14:
            {
            print_graph("Incorrect fraction!",50,86);
            break;
            }
        case 15:
            {
            print_graph("Wrong Bracket Balance",50,86);
            break;
            }
        case 17:
            {
            print_graph("Division by Zero!",50,86);
            break;
            }
        case 19:
            {
            print_graph("Negative logariphm!",50,86);
            break;
            }
        case 20:
            {
            print_graph("Negative Square root!",50,86);
            break;
            }
        case 21:
            {
            print_graph("Ctg Error!",50,86);
            break;
            }
        case 22:
            {
            print_graph("tan Error!",50,86);
            break;
            }
        }

    }
    SDL_SetRenderDrawColor(ren, 128, 128, 128, 255);
    SDL_RenderDrawLine(ren,50,122,750,122);                 //drawing lines with GREY color (^)
    SDL_RenderDrawLine(ren,50,147,750,147);
    SDL_RenderDrawLine(ren,50,500,750,500);
    SDL_RenderDrawLine(ren,50,525,750,525);
    SDL_RenderDrawLine(ren,400,122,400,525);
    SDL_RenderDrawLine(ren,620,122,620,525);
    print_graph("Previous calculations:",53,127);
    print_graph("Functions",403,127);
    print_graph("Variables",623,127);
    print_graph("Del - to clear",53,505);
    print_graph("to edit",403,505);
    print_graph("to edit",623,505);
    print_graph("tab - switch to plots",53,530);
    print_graph("F1 - help",690,530);
    if (tmp_ariph!=NULL)                        //then printing previous calculations
    {
    while (tmp_ariph->next!=NULL)
    {
        if (strlen(((Ariph*)(tmp_ariph->data))->string)<39)
        {
            sprintf(_strtmp,"%s",((Ariph*)(tmp_ariph->data))->string);
            print_graph(_strtmp,53,150+48*_tmp_i);
        }
        else                                            //that means that the equasion is too long
        {
            ((Ariph*)(tmp_ariph->data))->string[36]='.';
            ((Ariph*)(tmp_ariph->data))->string[37]='.';
            ((Ariph*)(tmp_ariph->data))->string[38]='.';
            ((Ariph*)(tmp_ariph->data))->string[39]='\0';
            sprintf(_strtmp,"%s",((Ariph*)(tmp_ariph->data))->string);
            print_graph(_strtmp,53,150+48*_tmp_i);
        }
        sprintf(_strtmp,"Answer: %.2f",((Ariph*)(tmp_ariph->data))->ans);
        print_graph(_strtmp,53,150+48*_tmp_i+16);
        tmp_ariph=tmp_ariph->next;
        _tmp_i++;
    }
        if (strlen(((Ariph*)(tmp_ariph->data))->string)<39)                 //doing the same to the last
        {
            sprintf(_strtmp,"%s",((Ariph*)(tmp_ariph->data))->string);
            print_graph(_strtmp,53,150+48*_tmp_i);
        }
        else
        {
            ((Ariph*)(tmp_ariph->data))->string[36]='.';
            ((Ariph*)(tmp_ariph->data))->string[37]='.';
            ((Ariph*)(tmp_ariph->data))->string[38]='.';
            ((Ariph*)(tmp_ariph->data))->string[39]='\0';
            sprintf(_strtmp,"%s",((Ariph*)(tmp_ariph->data))->string);
            print_graph(_strtmp,53,150+48*_tmp_i);
        }
        sprintf(_strtmp,"Answer: %.2f",((Ariph*)(tmp_ariph->data))->ans);
        print_graph(_strtmp,53,150+48*_tmp_i+16);
    }
    _tmp_i=0;
    if (tmp_plot!=NULL)                         //then printing plot list
    {
    while (tmp_plot->next!=NULL)
    {

        if (strlen(((Plot*)(tmp_plot->data))->string)<26)
        {
            textColor=tmp_cololr[tmp_plot->num-1];          //choosing color from array
            sprintf(_strtmp,"%d.",tmp_plot->num);              //digits have color of plot
            print_graph(_strtmp,403,150+32*_tmp_i);
            textColor.r=0;textColor.g=0;textColor.b=0;
            sprintf(_strtmp,"%s",((Plot*)(tmp_plot->data))->string);
            print_graph(_strtmp,423,150+32*_tmp_i);
        }
        else                                            //that means plots name is too long
        {
            ((Plot*)(tmp_plot->data))->string[23]='.';
            ((Plot*)(tmp_plot->data))->string[24]='.';
            ((Plot*)(tmp_plot->data))->string[25]='.';
            ((Plot*)(tmp_plot->data))->string[26]='\0';
            textColor=tmp_cololr[tmp_plot->num-1];
            sprintf(_strtmp,"%d.",tmp_plot->num);
            print_graph(_strtmp,403,150+32*_tmp_i);
            textColor.r=0;textColor.g=0;textColor.b=0;
            sprintf(_strtmp,"%s",((Plot*)(tmp_plot->data))->string);
            print_graph(_strtmp,423,150+32*_tmp_i);
        }
        tmp_plot=tmp_plot->next;
        _tmp_i++;
    }
        textColor=tmp_cololr[tmp_plot->num-1];          //doing the same with the last
        sprintf(_strtmp,"%d.",tmp_plot->num);
        print_graph(_strtmp,403,150+32*_tmp_i);
        textColor.r=0;textColor.g=0;textColor.b=0;
        sprintf(_strtmp,"%s",((Plot*)(tmp_plot->data))->string);
        print_graph(_strtmp,423,150+32*_tmp_i);
    }
    _tmp_i=0;
    while (_tmp_i<var_amount)
    {
        sprintf(_strtmp,"%s = %.2f",vars[_tmp_i].name,vars[_tmp_i].data);
        print_graph(_strtmp,623,150+32*_tmp_i);
        _tmp_i++;
    }
    if (M==0) {textColor.r=192;textColor.g=192;textColor.b=192;};           //if there is nothing in memory
    print_graph("M",396,530);
    textColor.r=0;textColor.g=0;textColor.b=0;                              //turn back to black
    SDL_RenderPresent(ren);
}

//Drawing asix
void graph_draw_asix(int right, int up)  //right(up) - number of times, that user presses Right-Left/Up-Down
{
    int i;
    screen_clear();
    SDL_SetRenderDrawColor(ren, 200, 200, 200, 255);            //light grey
    for (i=0;i<17;i++) SDL_RenderDrawLine(ren,50*i,0,50*i,600);         //drawing vertical lines
    for (i=0;i<13;i++) SDL_RenderDrawLine(ren,0,50*i,800,50*i);            //drawing horisontal lines
    SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
    SDL_RenderDrawLine(ren,400+50*right,0,400+50*right,600);                //draw horizontal main axis
    SDL_RenderDrawLine(ren,0,300-50*up,800,300-50*up);                      //draw vertical main axis
    SDL_RenderPresent(ren);
}

//Drawing graphs
void graph_draw_graps(List plots)
{
    int tmp_cololr[11][3]={{255,0,0},{0,255,0},{0,0,255},{255,127,0},{0,80,0},{127,0,127},{255,90,90},{255,255,0},{127,127,255},{80,80,80},{127,0,0}};  //array of COLORS
    int tmp_i;
    Note *tmp_R = plots.head;
    while (tmp_R->next!=NULL)           //going throw the list of plots
    {
        SDL_SetRenderDrawColor(ren,tmp_cololr[tmp_R->num-1][0],tmp_cololr[tmp_R->num-1][1],tmp_cololr[tmp_R->num-1][2],255);    //changing color
        for(tmp_i=0;tmp_i<799;tmp_i++) if((((Plot*)(tmp_R->data))->coord[tmp_i]>=0)&&(((Plot*)(tmp_R->data))->coord[tmp_i+1]>=0)) SDL_RenderDrawLine(ren,tmp_i+1,((Plot*)(tmp_R->data))->coord[tmp_i],tmp_i+2,((Plot*)(tmp_R->data))->coord[tmp_i+1]);      //if graph is visible - draw a line
        tmp_R=tmp_R->next;
    }
    if (tmp_R!=NULL)                        //the last plot
    {
        SDL_SetRenderDrawColor(ren,tmp_cololr[tmp_R->num-1][0],tmp_cololr[tmp_R->num-1][1],tmp_cololr[tmp_R->num-1][2],255);    //changing color
        for(tmp_i=0;tmp_i<799;tmp_i++) if((((Plot*)(tmp_R->data))->coord[tmp_i]>=0)&&(((Plot*)(tmp_R->data))->coord[tmp_i+1]>=0)) SDL_RenderDrawLine(ren,tmp_i+1,((Plot*)(tmp_R->data))->coord[tmp_i],tmp_i+2,((Plot*)(tmp_R->data))->coord[tmp_i+1]);    //if grahp is visible - draw a line
    }
    SDL_RenderPresent(ren);
}

//Exit screen
void interface_exit()
{
    screen_clear();
    screen_frame_create();
    print_graph("Are you sure you want to exit the program?",250,250);
    print_graph("Press 'Enter' to exit",320,266);
    SDL_RenderPresent(ren);
}

//(Main/ariph count) screen  help
void interface_help_main()
{
    char *gig;
    screen_clear();
    screen_frame_create();
    print_graph("Calculator, plots builder.",250,100);
    print_graph("--------------------------------------------------------------------",250,116);
    print_graph("Insert ariphmetical expression you want to calculate,",250,132);
    print_graph("or plot formula you want to visualise.",250,148);
    gig=(char*)malloc(127*sizeof(char));                           //doing that, because it really differs from max number amount of vars
    sprintf(gig,"You can save %d constants, build %d plots at the same time.",var_max_amount,plot_amount);
    print_graph(gig,250,164);
    print_graph("To save constant, print: \"constant_name\" = \"value\".",250,180);
    print_graph("\"constant_name\" can take up to 16 latin letters.",250,196);
    print_graph("Keys:",250,212);
    print_graph("Enter------ Calculate/Build",250,228);
    print_graph("Esc--------- Exit",250,244);
    print_graph("F1----------- Watch help",250,260);
    print_graph("Tab--------- Switch to plots",250,276);
    print_graph("Insert----------- Push value in memory",250,292);
    print_graph("Space----- Recall memory",250,308);
    print_graph("Del---------- Clean memory",250,324);
    SDL_RenderPresent(ren);
    SDL_getch();
}

//Plots screen help
void interface_help_plots()
{
    screen_clear();
    screen_frame_create();
    print_graph("Plots builder help:",250,100);
    print_graph("----------------------------------------",250,116);
    print_graph("Keys:",250,132);
    print_graph("Enter------ Calculate/Build",250,148);
    print_graph("Esc--------- Exit",250,164);
    print_graph("Tab--------- Plots List",250,180);
    print_graph("F1----------- Watch help",250,196);
    print_graph("\"+\"---------- Enlarge scale",250,212);
    print_graph("\"-\"----------- Decrease scale",250,228);
    print_graph("Up----------- Move Asix up",250,244);
    print_graph("Down------- Move Asix down",250,260);
    print_graph("Right-------- Move Asix right",250,276);
    print_graph("Left---------- Move Asix left",250,292);
    SDL_RenderPresent(ren);
    SDL_getch();
}

//destroyes graphics at the end
void graph_exit()
{
    SDL_DestroyRenderer(ren);           //destroys render
    SDL_DestroyWindow(win);             //destroys window
    TTF_Quit();                         //quit text
    SDL_Quit();                         //quit graphics
}

//Variables list
void interface_list_vars(Dbase* var)
{
	char _tmp_c;
	int _tmp_i=0;
	char* _strtmp=(char*)calloc(100*sizeof(char),100*sizeof(char));
	screen_clear();
    screen_frame_create();
    print_graph("List of variables:",250,100);
    if (var==NULL)                                      //then no variables
    {
        print_graph("There are no vars!",250,116);
        SDL_getch();
        return;
    }
    while (_tmp_i<var_amount)
    {
        sprintf(_strtmp,"%d %s %f",_tmp_i+1,var[_tmp_i].name,var[_tmp_i].data);         //print number, name and value
        print_graph(_strtmp,250,116+_tmp_i*16);
        i++;
    }
			int _tmp_n;
            _tmp_c=SDL_getch();
            if (_tmp_c==83)         //if del was pressed
            {
            print_graph("Please, enter the number of variable, that you want to delete:",250,116+_tmp_i*16);
            _tmp_n=SDL_getch()-48;                //get the number of variable
            if((_tmp_n>0)&&(_tmp_n<10))             //if it is actually a number
            for (_tmp_i=_tmp_n;_tmp_i<var_amount;_tmp_i++)
                var[_tmp_i-1]=var[_tmp_i];
                var_amount++;
            }
        return;
}

//Plots list
void interface_list_plots(List* plot)
{
	char _tmp_c;
	Note *provd;
	char* _strtmp=(char*)calloc(100*sizeof(char),100*sizeof(char));
	screen_clear();
	screen_frame_create();
    provd = plot->head;
    print_graph("List of plots:",250,100);
    if (plot->head==plot->tail)             //no plots for you
    {
            print_graph("There are no plots!",250,116);
            SDL_getch();
            return;
    }
    while (provd!=plot->tail)
    {
        sprintf(_strtmp,"%d %s",provd->num,((Plot*)(provd->data))->string);             //print all the plots
        print_graph(_strtmp,250,100+(provd->num)*16);
        provd=provd->next;
    }
        sprintf(_strtmp,"%d %s",provd->num,((Plot*)(provd->data))->string);                 //and the last one
        print_graph(_strtmp,250,100+(provd->num)*16);
			int _tmp_n;
            _tmp_c=SDL_getch();
            if (_tmp_c==83)                             //if del was pressed
            {
            print_graph("Please, enter the number of plot, that you want to delete:",250,116+(provd->num)*16);
            _tmp_n=SDL_getch()-48;                      //get the number of variable
            if((_tmp_n>0)&&(_tmp_n<10))                 //if it is actually a number
            queue_el_del(plot,_tmp_n);
            }
        return;
}
