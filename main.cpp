#include<iostream.h>
#include<dos.h>
#include<conio.h>
#include<stdlib.h>
#define SHOW 1
#define HIDE 2
union REGS input,output;

class piano
{
    public:int BIGKEY,MIDKEY,back,border;
            piano()  //CONSTRUCTOR INITIALIZATION
            {
                BIGKEY=15;
                MIDKEY=1;
                back=7;
                border=15
            }
}color;

void drawpiano(int x,int y);
int check_xy(int x, int y);
void BOX(int c,int r,int c1,int r1,int col);
int initmouse();
void setupscreen();
void pointer(int on);
void restrictmouse(int x1,int y1,int x2,int y2);
void check_keys(int x,int y);
void getmouse(int *button,int *x,int *y);
float freq[7] = {130.81, 146.83, 164.81, 174.61,196, 220, 246.94 } ;
int n=0,a=4,backcolor=2,exitcode=1;
void showbar(int t)
{
 if(t>65) t=65;
 if(t<1) t=1;
 textcolor(15);
 for(int q=0;q<=t;t++)
 {
	gotoxy(3+q,4);
	cprintf("Û");
 }
}