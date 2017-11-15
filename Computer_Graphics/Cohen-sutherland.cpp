// Computer_Graphics.cpp : Defines the entry point for the console application.
// The Cohn-Sutherland Algorithm

#include "stdafx.h"
//
//#define LEFT 1		// 0001
//#define RIGHT 2		// 0010
//#define BOTTOM 4	// 0100
//#define TOP 8		// 1000
//
///*
//The area encode
//1001 1000 1010
//0001 0000 0010
//0101 0100 0110
//*/
//inline void encode(float x, float y, float XL, float XR, float YB, float YT, int* code)
//{
//	int c = 0;
//	if (x < XL) c = c | LEFT;
//	else if (x > XR) c = c | RIGHT;
//	if (y < YB) c = c | BOTTOM;
//	else if (y > YT) c = c | TOP;
//	*code = c;
//	return;
//}

//void C_S_LineClip(float *x1, float *y1, float *x2, float *y2, float XL, float XR, float YB, float YT)
//{
//	int code1, code2, code;
//	float x, y;
//	encode(x1, y1, XL, XR, YB, YT, &code1);
//	encode(x2, y2, XL, XR, YB, YT, &code2);
//	while (code1 != 0 || code2 != 0)
//	{	// When code1 and code2 both == 0000, 
//		// Obviously inside the window, break the loop
//		if ((code1 & code2) != 0) return;	// Obviously outside the window
//		code = code1;
//
//		if (code1 == 0) code = code2;		// Partial inside the window
//		if ((LEFT & code) != 0)	
//		{	// The line segment intersects the left boundary
//			x = XL;
//			y = y1 + (y2 - y1) * (XL - x1) / (x2 - x1);
//		}
//		else if ((RIGHT & code) != 0)
//		{	// The line segment intersects the right boundary
//			x = XR;
//			y = y1 + (y2 - y1) * (XR - x1) / (x2 - x1);
//		}
//		else if ((BOTTOM&code) != 0)
//		{	// The line segment intersects the bottom boundary
//			y = YB;
//			x = x1 + (x2 - x1) * (YB - y1) / (y2 - y1);
//		}
//		else if ((TOP&code) != 0)
//		{	// The line segment intersects the top boundary
//			y = YT;
//			x = x1 + (x2 - x1)*(YT - y1) / (y2 - y1);
//		}
//
//		if (code == code1)
//		{
//			*x1 = x;	*y1 = y;
//			encode(x, y, XL, XR, YB, YT, &code1);
//		}
//		else
//		{
//			*x2 = x;	*y2 = y;
//			encode(x, y, XL, XR, YB, YT, &code2);
//		}
//	}
//	return;
//}
//
////Realise
//int main()
//{
//	float XL, XR, YB, YT, x1, y1, x2, y2;
//	printf("Please input XL, XR, YB, YT: \n");
//	scanf_s("%f%f%f%f", &XL, &XR, &YB, &YT);
//	printf("Please input x1, y1, x2, y2: \n");
//	scanf_s("%f%f%f%f", &x1, &y1, &x2, &y2);
//	C_S_LineClip(x1, y1, x2, y2, XL, XR, YB, YT);
//	printf("Results: \n");
//	printf("x1 = %f, y1 = %f, x2 = %f, y2 = %f\n", x1, y1, x2, y2);
//    return 0;
//}

