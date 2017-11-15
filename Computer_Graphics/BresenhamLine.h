#pragma once

#include "stdafx.h"
#include "Swap.h"

// Bresenham Method to print the straight line
inline void Bres_Line(int x1, int y1, int x2, int y2, int color)
{
	putpixel(x1, y1, color);	// draw the starting point
	int dx = abs(x2 - x1);
	int dy = abs(y2 - y1);
	if (dx == 0 && dy == 0)		// endpoints coincide
		return;
	int flag = 0;
	if (dx < dy)
	{	// transform the slope |k| into [0, 1]
		flag = 1;
		swap_value_int(&x1, &y1);
		swap_value_int(&x2, &y2);
		swap_value_int(&dx, &dy);
	}
	int tx = (x2 - x1) > 0 ? 1 : -1;
	int ty = (y2 - y1) > 0 ? 1 : -1;
	int curx = x1;	// the current point x coordinate
	int cury = y1;	// the current point y coordinate
	int dS = 2 * dy;
	int dT = 2 * (dy - dx);
	int d = dS - dx;
	while (curx != x2)	// when current point is not (x2, y2)
	{
		if (d < 0)
			d += dS;
		else
		{
			cury += ty;	
			d += dT;
		}

		// Restore the coordinates, and draw the pixel
		if (flag)
			putpixel(cury, curx, color);
		else
			putpixel(curx, cury, color);
		curx += tx;
	}
}

// The test function
inline void Bres_LineTest()
{
	int x1, y1, x2, y2;
	x1 = y1 = x2 = y2 = 0;	// initialization
	cout << "Bresenham method to draw a straight line" << endl;
	cout << "Please input x1, y1, x2, y2:" << endl;
	cin >> x1 >> y1 >> x2 >> y2;
	initgraph(1280, 720);
	Bres_Line(x1, y1, x2, y2, YELLOW);
	getch();
	closegraph();
}