#include<graphics.h>
#include<conio.h>
void main()
{
	int gd=DETECT,gm;
	int i;
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	for(i=0;i<50;i++)
	{
      setbkcolor(BLUE);
      circle(300+i,350,30);
      circle(300-i,350,30);
      circle(300,350+i,30);
      circle(300,350-i,30);
      delay(100);
	    cleardevice();
	}
	getch();
	closegraph();
}
