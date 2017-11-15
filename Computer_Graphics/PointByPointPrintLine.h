#pragma once

#include "stdafx.h"

// Point-to-Point Comparison Method to print the straight line
inline void PrintLine(int x1, int y1, int x2, int y2, int color)
{
	int x, y, xA, yA;
	if (y1 > y2)
	{	// Translate line coordinates to make the 
		// smaller point in y at the coordinate origin
		// After translation, (0, 0) and (xA, yA) is the end point
		yA = y1 - y2;	
		xA = x1 - x2;
	}
	else
	{	// vice versa
		yA = y2 - y1;
		xA = x2 - x1;
	}

	int F = x = y = 0;
	int n = abs(xA) + abs(yA);	// n is the total step number
	for (int i = 0; i < n; i++)
	{
		if (xA > 0)
		{	// if the slope is positive
			if (F >= 0)
			{
				x++;	
				F -= yA;
			}
			else
			{
				y++;
				F += xA;
			}
		}
		else
		{	// if the slope is negative
			if (F >= 0)
			{
				y++;
				F += xA;
			}
			else
			{
				x--;
				F += yA;
			}
		}
		
		// Restore the coordinates, and draw the pixel
		if (y1 > y2)
			putpixel(x + x2, y + y2, color);
		else
			putpixel(x + x1, y + y1, color);
	}
}

// The test function
inline void PrintLineTest()
{
	int x1, y1, x2, y2;
	x1 = y1 = x2 = y2 = 0;	// initialization
	cout << "Point-to-Point Comparison Method to print the straight line" << endl;
	cout << "Please input x1, y1, x2, y2:" << endl;
	cin >> x1 >> y1 >> x2 >> y2;
	initgraph(1280, 720);
	PrintLine(x1, y1, x2, y2, YELLOW);
	getch();
	closegraph();
}