//#include<graphics.h>
#include<stdio.h>
#include<conio.h>
void midpoint(int x1,int y1,int x2,int y2)
{
	int dx=x2-x1;
	int dy=y2-y1;
	int d=2*(dy)-dx;
	int x=x1, y=y1;
	printf("%d %d",x,y);
	printf("\n");
	while(x<=x2)
	{
		x=x+1;
		if(d>0)
		{       y=y+1;
			d=d+2*(dy-dx);
		       //	y=y+1;
		}
		else
		{
			d=d+2*(dy);
		}
			printf("%d %d",x,y);
		printf("\n");
	}
}
int main()
{
	int x1=2, y1=2,x2=8,y2=5;
	clrscr();
	//int gd=DETECT,gm;
	//initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	//setbkcolor(GREEN);
	midpoint(x1,y1,x2,y2);
	return 0;
}