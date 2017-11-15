#pragma once

#include "stdafx.h"
#include "Swap.h"

// Midpoint Algorithm to Straight-Line
inline void MidPLine(int x0, int y0, int x1, int y1, int color)
{
	int a, b, d, x, y, tag = 0;
	if (abs(x1 - x0) < abs(y1 - y0))
	{	// if slope |k| > 1, exchange the coordinate of x and y
		swap_value_int(&x0, &y0);
		swap_value_int(&x1, &y1);
		tag = 1;	// mark the change
	}
	if (x0 > x1)
	{	// ensure the x0 < x1
		swap_value_int(&x0, &x1);
		swap_value_int(&y0, &y1);
	}
	a = y0 - y1;
	b = x1 - x0;
	d = a + b / 2;
	if (y0 < y1)
	{	// the slope is positive
		x = x0;
		y = y0;
		putpixel(x, y, 255);
		while (x < x1)
		{
			if (d < 0)
			{
				x++;
				y++;
				d = d + a + b;
			}
			else
			{
				x++;
				d += a;
			}
			if (tag)
				putpixel(y, x, color);	// restore the coordinates
			else
				putpixel(x, y, color);
		}	/* while */
	}
	else
	{	// the slope is negative
		x = x1;
		y = y1;
		putpixel(x, y, 255);
		while (x > x0)
		{
			if (d < 0)
			{
				x--;
				y++;
				d = d - a + b;
			}
			else
			{
				x--;
				d -= a;
			}
			if (tag)
				putpixel(y, x, color);	// restore the coordinates
			else
				putpixel(x, y, color);
		}	/* while */
	}
}

// The test function
inline void MidPLineTest()
{
	int x1, y1, x2, y2;
	x1 = y1 = x2 = y2 = 0;	// initialization
	cout << "Midpoint Algorithm to plot Straight-Line" << endl;
	cout << "Please input x1, y1, x2, y2:" << endl;
	cin >> x1 >> y1 >> x2 >> y2;
	initgraph(1280, 720);
	MidPLine(x1, y1, x2, y2, YELLOW);
	getch();
	closegraph();
}