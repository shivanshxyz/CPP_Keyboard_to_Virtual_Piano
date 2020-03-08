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

