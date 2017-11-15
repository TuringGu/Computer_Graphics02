#pragma once

#include "stdafx.h"
#include "CirclePlot.h"

// Bresenham Method to print the circle
inline void Bres_Circle(int x0, int y0, double r, int color)
{
	int x, y, d;
	x = 0;
	y = (int)r;
	d = int(3 - 2 * r);	// when the (0, r) is the start pixel
	while (x < y)	
	{
		Cirpot_eight_part(x0, y0, x, y, color);
		if (d < 0)
			d += 4 * x + 6;
		else
		{
			d += 4 * (x - y) + 10;
			y--;
		}
		x++;
	}
	if (x == y)
		Cirpot_eight_part(x0, y0, x, y, color);
}

// The test function
inline void Bres_CircleTest()
{
	int x0, y0;
	double r;
	x0 = y0 = r = 0;	// initialization
	cout << "Bresenham method to draw a circle" << endl;
	cout << "Please input x0, y0, r:" << endl;
	cin >> x0 >> y0 >> r;
	initgraph(1280, 720);
	Bres_Circle(x0, y0, r, YELLOW);
	getch();
	closegraph();
}