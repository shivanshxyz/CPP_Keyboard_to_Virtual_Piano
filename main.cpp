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