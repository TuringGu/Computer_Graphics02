#pragma once

#include "stdafx.h"
#include "CirclePlot.h"

// middle point method to print the circle
inline void MidPoint_Circle(int x0, int y0, int r, int color)
{
	int x = 0;
	int y = r;
	int d = 1 - r;	// d is the result of rounding (1.25 - r)
	Cirpot_eight_part(x0, y0, x, y, color);
	while (x < y)
	{
		if (d < 0)
			d += 2 * x + 3;
		else
		{
			d += 2 * (x - y) + 5;
			y--;
		}
		x++;
		Cirpot_eight_part(x0, y0, x, y, color);
	}
}


// The test function
inline void MidPoint_CircleTest()
{
	int x0, y0;
	double r;
	x0 = y0 = r = 0;	// initialization
	cout << "Middle point method to draw a circle" << endl;
	cout << "Please input x0, y0, r:" << endl;
	cin >> x0 >> y0 >> r;
	initgraph(1280, 720);
	MidPoint_Circle(x0, y0, r, YELLOW);
	getch();
	closegraph();
}