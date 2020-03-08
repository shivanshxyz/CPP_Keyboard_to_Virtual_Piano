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


//MAIN FUNCTION

int main(){
    int b,x,y,key;
    char ch;
    if(initmouse()==-1){
        //TERMINATES THE PROGRAM IF MOUSE IS NOT CONNECTED
        clrscr();
        cout<<"\n\n -----NO MOUSE CONNECTED----- \n\n"

    }

    pointer(SHOW);
    setupscreen();
    exitcode=1;
    while(exitcode)
    {
            if(kbhit())
	        {
	            ch=getch();
	            if(ch==27) break;
	            if(ch==75) a--;
	            if(ch==77) a++;
	            check_keys(x,y);
	            switch(ch)
	            {
		            case 'a':case'A':key=0;break;
		            case 's':case'S':key=1;break;
		            case 'd':case'D':key=2;break;
		            case 'f':case'F':key=3;break;
		            case 'j':case'J':key=4;break;
		            case 'k':case'K':key=5;break;
		            case 'l':case'L':key=6;break;
	            }
	            sound(freq[key]*a);
	            delay(80);
	            nosound();
	        }
	        getmouse(&b,&x,&y);
	        if(b==1)
	        {
		        while(b==1)
		        {
			        getmouse(&b,&x,&y);
			        key=check_xy(x,y);
			        if(key!=-1 && key<7)
		        	{
		        		sound(freq[key]*a);
		        	}
		        	else if(key>6)
			        {
				         sound(freq[12-key]*(a/2));
			        }
		    }
		    nosound();
		    check_keys(x,y);
	        }
        }
        
    }
    textbackground(0);
    clrscr();
    _setcursortype(_NORMALCURSOR);
    return 0;

}  //EOF

void setupscreen() /* Display screen settings */
{
 _setcursortype(_NOCURSOR);
 textbackground(backcolor);
 clrscr();
 drawpiano(9,17);
 BOX(4,5,8,5,0);
 BOX(5,5,7,5,1);
 textcolor(15);
 gotoxy(70,5);
 cprintf(">Quit<");
 gotoxy(4,4);
 cprintf("Range");
 textbackground(0);
 gotoxy(8,5);
 cprintf("");
 gotoxy(4,5);
 cprintf("");
 gotoxy(6,5);
 cprintf("%d",a);
 textcolor(14);
 textbackground(backcolor+7);
 gotoxy(30,4);
 cprintf(" VIRTUAL PIANO ");

}

