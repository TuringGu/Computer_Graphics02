

#ifndef OPENGL_2D_TOOLS
#define OPENGL_2D_TOOLS
#include <GL/glut.h>
#include <vector>
using std::vector;

//---------------classes for 2d entities-----------
typedef float Point2D[2];
struct Entity2D {
	virtual void drawme();
};

struct Line2D :public Entity2D {
	Point2D sP, eP;
	virtual void drawme() {
		glBegin(GL_LINES);
		glVertex2f(sP[0], sP[1]);
		glVertex2f(eP[0], eP[1]);
		glEnd();
	}
};

struct Polygon2D :public Entity2D {
	vector< Point2D >  points;
	virtual void drawme() {
		glBegin(GL_POLYGON);
		for (int i = 0; i < points.size(); i++) {
			glVertex2f(points[i][0], points[i][1]);
		}
		glEnd();
	}
};

//---------------tools for drawing 2d entities-----------
struct RubbleTool {
	int view_width, view_height;
	float left, right, bottom, top;

	RubbleTool(int w = 400, int h = 300) :
		view_width(w), view_height(h) {

	};

	/*void set_window(float l, float r, float b, float t) :
		left(l), right(r), bottom(b), top(t) {
		
	};*/

	virtual void mouseClicked(int button, int state, int x, int y);
	virtual void glutMotionFunc(int x, int y);
	virtual void mousePassiveMotion(int x, int y);
};


//struct LineTool :public RubbleTool
//{
//	Line2D  line;
//	bool first;
//	LineTool() { first = true; }
//	virtual void mouseClicked(int button, int state, int x, int y) {
//		y = view_height - y;
//		float xf = (x - (float)view_width / 2) / view_width*(right - left);
//		float yf = (y - (float)view_height / 2) / view_height*(top - bottom);
//		if (first) {
//			line.sP[0] = xf; line.sP[1] = yf;
//			first = false;
//		}
//		else {
//			line.eP[0] = xf; line.eP[1] = yf;
//			first = true;
//		}
//	}
//	virtual void mousePassiveMotion(int x, int y) {
//		line.eP[0] = xf; line.eP[1] = yf;
//	}
//};

#endif