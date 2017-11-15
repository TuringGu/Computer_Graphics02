#pragma once

#include "stdafx.h"

// The digital differential analyzer to plot straight line
inline void LineDDA(int x1, int y1, int x2, int y2, int color)
{
	int dm = 0;
	if (abs(x2 - x1) >= abs(y2 - y1))
		dm = abs(x2 - x1);	// set x to be the length direction
	else
		dm = abs(y2 - y1);	// set y to be the length direction
	float dx = (float)(x2 - x1) / dm;	// when x is the length direction, dx = 1
	float dy = (float)(y2 - y1) / dm;	// when y is the length direction, dy = 1
	float x = x1 + 0.5;	// reduce errors
	float y = y1 + 0.5;	// reduce errors
	for (int i = 0; i < dm; i++)
	{
		putpixel((int)x, (int)y, color);	// draw a pixel
		x += dx;
		y += dy;
	}
}

// The test function
inline void LineDDATest()
{
	int x1, y1, x2, y2;
	x1 = y1 = x2 = y2 = 0;	// initialization
	cout << "Digital differential analyzer to plot straight line" << endl;
	cout << "Please input x1, y1, x2, y2:" << endl;
	cin >> x1 >> y1 >> x2 >> y2;
	initgraph(1280, 720);
	LineDDA(x1, y1, x2, y2, YELLOW);
	getch();
	closegraph();
}