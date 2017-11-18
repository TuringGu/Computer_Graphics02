#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>


#define LEFT_EDGE 1		// 0001	left
#define RIGHT_EDGE 2	// 0010	right
#define BOTTOM_EDGE 4	// 0100	bottom
#define TOP_EDGE 8		// 1000	top


// draw a line
void LineGL(int x0, int y0, int x1, int y1)
{
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);	glVertex2f(x0, y0);
	glColor3f(1.0f, 1.0f, 1.0f);	glVertex2f(x1, y1);
	glEnd();
}


// define the rectangle struct
struct MyRectangle
{
	float xmin, xmax, ymin, ymax;
};

MyRectangle rect;	// declare global variable
int x0, y0, x1, y1;


// point location encode
int CompCode(int x, int y, MyRectangle rect)
{
	int code = 0x00;
	if (y < rect.ymin) 
		code = code | 4;	// 0000|0100
	if (y > rect.ymax) 
		code = code | 8;	// 0000|1000
	if (x > rect.xmax) 
		code = code | 2;	// 0000|0010
	if (x < rect.xmin) 
		code = code | 1;	// 0000|0001
	return code;
}


// the Cohen-Surtherland algorithm
int cohensutherlandlineclip(MyRectangle rect, 
	int &x0, int &y0, int &x1, int &y1)
{
	int accept, done;	// flag
	float x, y;
	accept = done = 0;	// initial flag

	int code0, code1, codeout;
	code0 = CompCode(x0, y0, rect);	// encode
	code1 = CompCode(x1, y1, rect);	// encode
	do {
		if (!(code0 | code1))	// completely inside the window
		{	
			accept = 1;	// clip done
			done = 1;	// end loop
		}
		else if (code0 & code1)	// completely outside the window
			done = 1;	// end loop
		else					// partly inside the window
		{			
			// make sure that the codeout is outside the window
			if (code0 != 0)	// code0 is outside the window
				codeout = code0;
			else			// code0 is inside the window
				codeout = code1;

			// clipping external line segment
			if (codeout & LEFT_EDGE)	// in the left side
			{
				y = y0 + (y1 - y0)*(rect.xmin - x0) / (x1 - x0);
				x = (float)rect.xmin;
			}
			else if (codeout & RIGHT_EDGE)	// in the right side
			{
				y = y0 + (y1 - y0)*(rect.xmax - x0) / (x1 - x0);
				x = (float)rect.xmax;
			}
			else if (codeout & BOTTOM_EDGE)	// at the bottom
			{
				x = x0 + (x1 - x0)*(rect.ymin - y0) / (y1 - y0);
				y = (float)rect.ymin;
			}
			else if (codeout & TOP_EDGE)	// at the top
			{
				x = x0 + (x1 - x0)*(rect.ymax - y0) / (y1 - y0);
				y = (float)rect.ymax;
			}

			if (codeout == code0)	// when codeout = code0;
			{
				x0 = x;	y0 = y;
				code0 = CompCode(x0, y0, rect);	// encode
			}
			else					// when codeout = code1
			{
				x1 = x; y1 = y;
				code1 = CompCode(x1, y1, rect);	// encode
			}
		}// end-else
	} while (!done);

	if (accept)	// clip done
		LineGL(x0, y0, x1, y1);	// plot the result
	return accept;
}


// display function
void myDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0f, 0.0f, 0.0f);
	glRectf(rect.xmin, rect.ymin, rect.xmax, rect.ymax);
	LineGL(x0, y0, x1, y1);	// draw the line (x0, y0) -> (x1, y1)
	glFlush();
}


// initialization
void Init()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);

	rect.xmin = 100;
	rect.xmax = 300;
	rect.ymin = 100;
	rect.ymax = 300;

	// test instances
	//x0 = 0, y0 = 450, x1 = 450, y1 = 0;		// partly inside the window
	//x0 = 450, y0 = 0, x1 = 0, y1 = 450;		// partly inside the window

	//x0 = 110, y0 = 320, x1 = 280, y1 = 150;	// partly inside the window
	//x0 = 320, y0 = 110, x1 = 150, y1 = 280;	// partly inside the window

	//x0 = 110, y0 = 270, x1 = 280, y1 = 150;	// completely inside the window
	//x0 = 270, y0 = 110, x1 = 150, y1 = 280;	// completely inside the window

	//x0 = 91, y0 = 10, x1 = 406, y1 = 500;		// partly inside the window
	x0 = 10, y0 = 91, x1 = 500, y1 = 406;		// partly inside the window

	//x0 = 380, y0 = 500, x1 = 420, y1 = 296;		// completely outside the window
	
	printf("Press key 'c' to Clip!\nPress key 'r' to Restore!\n");
}


// reshape function
void Reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, (GLdouble)w, 0.0, (GLdouble)h);
}


// interactive by keyboard
void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'c':	// clip
		cohensutherlandlineclip(rect, x0, y0, x1, y1);
		glutPostRedisplay();
		break;
	case 'r':	// restore
		Init();
		glutPostRedisplay();
		break;
	case 'x':	// exit
		exit(0);	// normal exit
		break;
	default:	// invaluable input
		break;
	}
}


// main function entry
int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(640, 480);
	glutCreateWindow("Hello, World!");

	Init();
	glutDisplayFunc(myDisplay);
	glutReshapeFunc(Reshape);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}