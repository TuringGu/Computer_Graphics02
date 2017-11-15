#include <GL/glut.h>

typedef GLfloat point2d[2]; // a point data type

void triangle(point2d a, point2d b, point2d c) // display a triangle
{
	glBegin(GL_TRIANGLES);
	glVertex2fv(a);
	glVertex2fv(b);
	glVertex2fv(c);
	glEnd();
}


void display(void)
{
	point2d v[3] = { { -1.0, -0.58 },{ 1.0, -0.58 },{ 0.0, 1.15 } }; //initial triangle vertices
	glClear(GL_COLOR_BUFFER_BIT); // Clear display window
	glColor3f(0.0, 0.0, 1.0); // Set fill color to blue
	glLoadIdentity();// Should be put there£¬to ensure every time have the correct display
	glViewport(0, 0, 300, 400); // Set left viewport
	triangle(v[0], v[1], v[2]);
	glColor3f(1.0, 0.0, 0.0); // Set fill color to red
	glViewport(300, 0, 300, 400); // Set right viewport
	glRotatef(90.0, 0.0, 0.0, 1.0); // Rotate about z axis
	triangle(v[0], v[1], v[2]); // Display blue triangle
	glFlush();
}


void init()
{
	glMatrixMode(GL_PROJECTION);	// Choose projection mode

	/* If put there£¬the first time will be right£¬
	but when refresh again, the graphic rotated */
	//glLoadIdentity();

	gluOrtho2D(-2.0, 2.0, -2.0, 2.0);
	glMatrixMode(GL_MODELVIEW);
	glClearColor(1.0, 1.0, 1.0, 1.0);
}

// Enter
void main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(600, 400);
	glutCreateWindow("Triangle");
	glutDisplayFunc(display);
	init();
	glutMainLoop();
}