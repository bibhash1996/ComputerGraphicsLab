// Drawing a cylinder and parallelopiped

#include <stdio.h>
#include <GL/glut.h>
#include <math.h>

void d_pixel(GLint cx, GLint cy) {
	glColor3f(1, 0, 0);
	glBegin(GL_POINTS);
	glVertex2f(cx, cy);
	glEnd();
}

int min(int a, int b) {
	return (a>b)?b:a;
}

void plotpixels(GLint h, GLint k, GLint x, GLint y) {
	d_pixel(x+h, y+k);
	d_pixel(-x+h, -y+k);
	d_pixel(x+h, -y+k);
	d_pixel(-x+h, y+k);
	d_pixel(y+h, x+k);
	d_pixel(-y+h, x+k);
	d_pixel(y+h, -x+k);
	d_pixel(-y+h, -x+k);
}

void circle_draw(GLint h, GLint k, GLint r) {
	int x, y;
	double sq;
	for(x = 0; x <= r; x++) {
		sq = sqrt(r*r-x*x);
		if(ceil(sq)-sq > sq-floor(sq))
			y = floor(sq);
		else
			y = ceil(sq);
		plotpixels(h, k, x, y);
	}
}

void cylinder_draw() {
	GLint xc = 100, yc = 100, r = 50;
	GLint i, n = 20;
	for(i = 0; i<n; i += 3) {
		circle_draw(xc, yc+i, r);
	}
}

void parallelpiped(int x1, int x2, int y1, int y2) {
	glColor3f(0, 0, 1);
	glPointSize(2);
	glBegin(GL_LINE_LOOP);
	glVertex2i(x1, y1);
	glVertex2i(x1, y2);
	glVertex2i(x2, y2);
	glVertex2i(x2, y1);
	glEnd();
}

void parallelpiped_draw() {
	int x1 = 200, x2 = 300, y1 = 100, y2 = 175;
	GLint i, n =40 ;
	for(i = 0; i < n; i+=2) {
		parallelpiped(x1+i, x2+i, y1+i, y2+i);
	}
}

void myinit(void) {
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, 499, 0, 499);
}

void display(void) {
	glColor3f(1, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(1, 1,1,1);
	glPointSize(2);
	cylinder_draw();
	parallelpiped_draw();
	glFlush();
}

int main(int argc, char ** argv) {
	glutInit(&argc, argv);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Parallelpiped");
	myinit();
	glutDisplayFunc(display);
	glutMainLoop();
}
