// C program to draw a moving car. This
// program run in gcc compiler having
// graphics.h library installed
#include <graphics.h>
#include <stdio.h>

// Function to draw moving car
void draw_moving_car(void) {

	int i, j = 0, gd = DETECT, gm;

	// Passed three arguments to initgraph
	// function to initialize graphics mode
	initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

	for (i = 0; i <= 420; i = i + 10) {

		// Set color of car as red
		setcolor(RED);

		// Thease lines for bonnet and
		// body of car
		line(0 + i, 300, 210 + i, 300);
		line(50 + i, 300, 75 + i, 270);
		line(75 + i, 270, 150 + i, 270);
		line(150 + i, 270, 165 + i, 300);
		line(0 + i, 300, 0 + i, 330);
		line(210 + i, 300, 210 + i, 330);

		// For left wheel of car
		circle(65 + i, 330, 15);
		circle(65 + i, 330, 2);

		// For right wheel of car
		circle(145 + i, 330, 15);
		circle(145 + i, 330, 2);

		// Line left of left wheel
		line(0 + i, 330, 50 + i, 330);

		// Line middle of both wheel
		line(80 + i, 330, 130 + i, 330);

		// Line right of right wheel
		line(210 + i, 330, 160 + i, 330);

		delay(100);

		// To erase previous drawn car, draw
		// the whole car at same position
		// but color using black
		//setcolor(BLACK);
		
		// Lines for bonnet and body of car
		//line(0 + i, 300, 210 + i, 300);
		//line(50 + i, 300, 75 + i, 270);
		//line(75 + i, 270, 150 + i, 270);
		//line(150 + i, 270, 165 + i, 300);
		//line(0 + i, 300, 0 + i, 330);
		//line(210 + i, 300, 210 + i, 330);

		// For left wheel of car
		//circle(65 + i, 330, 15);
		//circle(65 + i, 330, 2);

		// For right wheel of car
		//circle(145 + i, 330, 15);
		//circle(145 + i, 330, 2);

		// Line left of left wheel
		//line(0 + i, 330, 50 + i, 330);

		// Line middle of both wheel
		//line(80 + i, 330, 130 + i, 330);

		// Line right of right wheel
		//line(210 + i, 330, 160 + i, 330);
		Cleardevice();
	}

	getch();

	closegraph();
}

// Driver code
int main()
{
	draw_moving_car();

	return 0;
}
