#pragma once

#include "stdafx.h"

// the angle discrete method to plot the arc
//inline void Arc_OpenGL(int xc, int yc, double r, double ts, double te)
//{
//	double pi = 3.1415926;
//	if (te < ts)		// When the termination angle is less than the start angle, 
//		te += 2 * pi;	// the termination angle is added to the 2 * pi
//
//	double dt = 0.4 / r;	// Take the angle discrete value so that it 
//							// is inversely proportional to the radius r
//	int n = (int)((te - ts) / dt + 0.5);	// ensure the total step number
//	double ta = ts;
//	int x = xc + int(r*cos(ts));
//	int y = yc + int(r*sin(ts));
//
//	// modify
//	glColor3f(1.0f, 1.0f, 0.0f);
//	glPointSize(1);
//
//	//glBegin(GL_LINE_STRIP);	// if plot the whole circle, GL_LINE_LOOP is better
//	glBegin(GL_POINTS);
//	glVertex2i(x, y);
//	glEnd();
//	for (int i = 1; i <= n; i++)
//	{
//		glBegin(GL_POINTS);
//		ta += dt;
//		double cost = cos(ta);
//		double sint = sin(ta);
//		x = int(xc + r*cost);
//		y = int(yc + r*sint);
//		glVertex2i(x, y);
//		glEnd();
//	}
//	//glEnd();
//}
//
//inline void myDisplay(void)
//{
//	// input
//	int xc, yc;
//	double r, ts, te;
//	//xc = yc = r = ts = te = 0;	// initialization
//	/*cout << "The angle discrete method to plot the arc" << endl;
//	cout << "Please input xc, yc, r, ts, te:" << endl;
//	cin >> xc >> yc >> r >> ts >> te;*/
//	xc = yc = 200;
//	r = 20;
//	ts = 0;
//	te = 3;
//
//	glClearColor(0.0, 0.0, 0.0, 0.0);
//	glClear(GL_COLOR_BUFFER_BIT);
//
//
//	// test
//	//glBegin(GL_TRIANGLES);
//	//glColor3f(1.0f, 0.0f, 0.0f);	glVertex2f(0.0f, 1.0f);
//	//glColor3f(0.0f, 1.0f, 0.0f);	glVertex2f(0.8f, -0.5f);
//	//glColor3f(0.0f, 0.0f, 1.0f);	glVertex2f(-0.8f, -0.5f);
//	//glEnd();
//
//	
//	Arc_OpenGL(xc, yc, r, ts, te);
//
//	glFlush();
//}
//
////// The test function
////inline int Arc_OpenGLTest(int argc, char *argv[])
////{
////	glutInit(&argc, argv);
////	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
////	glutInitWindowPosition(100, 100);
////	glutInitWindowSize(400, 400);
////	glutCreateWindow("OpenGL");
////	glutDisplayFunc(&Show);
////	glutMainLoop();
////	return 0;
////}