#pragma once

#include "stdafx.h"
#include "LineDDA.h"

// calculate cross points parameters
inline int clipTest(float p, float q, float &u1, float &u2)
{
	float r;
	int retVal = 1;
	if (p < 0)
	{
		r = q / p;
		if (r > u2)
			retVal = 0;
		else if (r > u1)
			u1 = r;
	}
	else if (p > 0)
	{
		r = q / p;
		if (r < u1)
			retVal = 0;
		else if (r < u2)
			u2 = r;
	}
	else if (q < 0)
		retVal = 0;

	return retVal;
}


/* x1, y1, x2, y2 is the straight line end points coordinates,
XL, XR, YB, YT is the information of windows' edges */
inline int L_B_LineClip(float &x1, float &y1, float &x2, float &y2,
	float XL, float XR, float YB, float YT)
{
	/* u1: start point parameter, initial value is 0 
	   u2: end point parameter, initial value is 1 */
	float u1 = 0, u2 = 1, dx = x2 - x1, dy;

	// calculate left edge cross point parameter, update u1, u2
	if (clipTest(-dx, x1 - XL, u1, u2))
	{	
		// calculate right edge cross point paramter, update u1, u2
		if (clipTest(dx, XR - x1, u1, u2))
		{	
			dy = y2 - y1;
			// calculate bottom edge cross point paramter, update u1, u2
			if (clipTest(-dy, y1 - YB, u1, u2))
			{
				// calculate top edge cross point paramter, update u1, u2
				if (clipTest(dy, YT - y1, u1, u2))
				{
					if (u2 < 1)
					{
						x2 = x1 + u2 * dx;	// calculate end point coordinate
						y2 = y1 + u2 * dy;
					}
					if (u1 > 0)
					{
						x1 += u1 * dx;		// calculate start point coordinate
						y2 += u1 * dy;
					}
					return 1;
				}
			}
		}
	}
	return 0;
}


// The test function
inline void L_B_LineClipTest()
{
	int x0, y0, x, y;
	double r;
	x0 = y0 = r = 0;	// initialization

	float x1, y1, x2, y2, XL, XR, YB, YT = 0;

	cout << "Liang-Barsky algorithm to clip the line" << endl;

	/*cout << "Please input XL, XR, YB, YT to plot the rectangle:" << endl;
	cin >> XL >> XR >> YB >> YT;

	cout << "Please input a line x1, y1, x2, y2:" << endl;
	cin >> x1 >> y1 >> x2 >> y2;*/

	// test data
	XL = 300, XR = 600, YB = 300, YT = 600;
	x1 = 277, y1 = 556, x2 = 800, y2 = 333;

	initgraph(1280, 720);
	
	// plot the rectangle (float to int cause precision loss)
	LineDDA((int)XL, (int)YB, (int)XL, (int)YT, YELLOW);
	LineDDA((int)XL, (int)YB, (int)XR, (int)YB, YELLOW);
	LineDDA((int)XR, (int)YT, (int)XL, (int)YT, YELLOW);
	LineDDA((int)XR, (int)YT, (int)XR, (int)YB, YELLOW);

	// plot the line
	LineDDA((int)x1, (int)y1, (int)x2, (int)y2, YELLOW);

	getch();	// waiting for user's operation to continue
	L_B_LineClip(x1, y1, x2, y2, XL, XR, YB, YT);

	// plot the line
	LineDDA((int)x1, (int)y1, (int)x2, (int)y2, WHITE);

	getch();
	closegraph();
}