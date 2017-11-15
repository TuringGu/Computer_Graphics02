#pragma once

#include "stdafx.h"
#include "BresenhamCircle.h"
#include "Stack.h"

// seeds filling (flood fill) algorithm 4 - connecteds
inline void FloodFill4(int x, int y, int newcolor, int boundaryColor)
{
	if (getpixel(x, y) != newcolor && getpixel(x, y) != boundaryColor)
	{
		//setpixel(x, y, newcolor, boundaryColor);
		putpixel(x, y, newcolor);

		// 4 - connected
		FloodFill4(x - 1, y, newcolor, boundaryColor);
		FloodFill4(x, y + 1, newcolor, boundaryColor);
		FloodFill4(x + 1, y, newcolor, boundaryColor);
		FloodFill4(x, y - 1, newcolor, boundaryColor);
	}
}

// Nonrecursive seeds filling (flood fill) algorithm 4 - connecteds
inline void FloodFill4_NonRecursive(int x, int y, int newcolor, int boundaryColor)
{
	int xx, yy;		// the temp
	SqStack S;
	PixelType Pseed;// seed pixel and temp pixel

	xx = yy = 0;	// initial
	InitStack(S);	// stack initial

	Pseed.x = x;	Pseed.y = y;	// assignment
	Pseed.color = getpixel(x, y);	
	Push(S, Pseed);	// push seed pixel into the stack

	while (S.base != S.top)	// while the stack is not empty
	{
		PixelType e;	// generate new pixel
		Pop(S, e);	// pop a pixel from the top of the stack
		if (e.color != newcolor && e.color != boundaryColor)
		{
			xx = e.x;	yy = e.y;
			putpixel(xx, yy, newcolor);	// draw the pixel

			// 4 - connecteds
			PixelType e1, e2, e3, e4;	// generate 4 new pixel
			e1.x = xx - 1;	e1.y = yy;	e1.color = getpixel(e1.x, e1.y);
			Push(S, e1);
			e2.x = xx;	e2.y = yy + 1;	e2.color = getpixel(e2.x, e2.y);
			Push(S, e2);
			e3.x = xx + 1;	e3.y = yy;	e3.color = getpixel(e3.x, e3.y);
			Push(S, e3);
			e4.x = xx;	e4.y = yy - 1;	e4.color = getpixel(e4.x, e4.y);
			Push(S, e4);
		}
	}
}


// The test function
inline void FloodFill4Test()
{
	int x0, y0, x, y;
	double r;
	x0 = y0 = r = 0;	// initialization

	cout << "Seed filling (flood file) algorithm to fill the circle" << endl;
	cout << "Please input x0, y0, r to plot the circle:" << endl;
	cin >> x0 >> y0 >> r;

	cout << "Please input seed coordinate x, y:" << endl;
	cin >> x >> y;

	initgraph(1280, 720);
	Bres_Circle(x0, y0, r, YELLOW); 

	/* When use recursive method, 
	r should <= 35£¬to avoid stack overflow*/
	FloodFill4(x, y, RED, YELLOW);

	getch();
	closegraph();
}



// The test function
inline void FloodFill4_NonRecursiveTest()
{
	int x0, y0, x, y;
	double r;
	x0 = y0 = r = 0;	// initialization

	cout << "Seed filling (flood file) algorithm to fill the circle" << endl;
	cout << "Please input x0, y0, r to plot the circle:" << endl;
	cin >> x0 >> y0 >> r;

	cout << "Please input seed coordinate x, y:" << endl;
	cin >> x >> y;
	
	initgraph(1280, 720);
	Bres_Circle(x0, y0, r, YELLOW);
	FloodFill4_NonRecursive(x, y, RED, YELLOW);
	getch();
	closegraph();
}