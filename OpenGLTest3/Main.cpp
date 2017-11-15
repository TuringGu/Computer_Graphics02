#include <GL/glut.h>

void init(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-5.0, 5.0, -5.0, 5.0); // set display range is X:-5.0~5.0, Y:-5.0~5.0
	glMatrixMode(GL_MODELVIEW);
}

// draw the square which center at the origin and the side equal 2
void drawSquare(void) 
{
	glBegin(GL_POLYGON);		// the vertex specifies the counterclockwise direction
	glVertex2f(-1.0f, -1.0f);	// lower left point
	glVertex2f(1.0f, -1.0f);	// lower right point
	glVertex2f(1.0f, 1.0f);		// upper right point
	glVertex2f(-1.0f, 1.0f);	// upper left point
	glEnd();
}

// draw function
void myDraw(void)
{
	glClear(GL_COLOR_BUFFER_BIT);	// clean
	glLoadIdentity();	// set the current matrix as a identity matrix
	glPushMatrix();		// push into the stack to store the identity matrix

	glTranslatef(0.0f, 2.0f, 0.0f);	// translate
	glScalef(3.0, 0.5, 1.0);		// scale
	glColor3f(1.0, 0.0, 0.0);		// color red
	drawSquare();	// draw the square at the top
	glPopMatrix();	// pop the stored matrix
	glPushMatrix();

	glTranslatef(-3.0, 0.0, 0.0);
	glPushMatrix();
	glRotatef(45.0, 0.0, 0.0, 1.0);	// rotate
	glColor3f(0.0, 1.0, 0.0);	// color green
	drawSquare(); // draw the square in the middle

	glPopMatrix();
	glTranslatef(3.0, 0.0, 0.0);
	glPushMatrix();
	glRotatef(45.0, 0.0, 0.0, 1.0);
	glColor3f(0.0, 0.7, 0.0);
	drawSquare(); // draw the square 

	glPopMatrix();
	glTranslatef(3.0, 0.0, 0.0);
	glPushMatrix();
	glRotatef(45.0, 0.0, 0.0, 1.0);
	glColor3f(0.0, 0.4, 0.0);
	drawSquare(); // draw the square in the right

	glPopMatrix();
	glPopMatrix();
	glTranslatef(0.0, -3.0, 0.0);
	glScalef(4.0, 1.5, 1.0);
	glColor3f(0.0, 0.0, 1.0);
	drawSquare(); // draw the square at the bottom

	glFlush();
}

// Main function
void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(600, 600);
	glutCreateWindow("Synthesis example of geometric transformation function");
	init();
	glutDisplayFunc(myDraw);
	glutMainLoop();

}