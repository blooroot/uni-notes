#include <windows.h> 
#include <GL/glut.h> 
#include <math.h>

static const int X = 600;
static const int Y = 600;
static const int SCALE = 20;

void init() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Fondo blanco
    gluOrtho2D(-X, X, -Y, Y); 
}

void drawGrid() {
    // Rejilla (verde)
    glColor3f(0.0f, 1.0f, 0.498f); 
    for (int i = -600; i <= 600; i += 20) {
        glBegin(GL_LINES);
        glVertex2i(i, -600);
        glVertex2i(i, 600);
        glVertex2i(-600, i);
        glVertex2i(600, i);
        glEnd();
    }
    // Ejes (azul)
    glColor3f(0.098f, 0.098f, 0.439f);
    glBegin(GL_LINES);
    glVertex2i(-X, 0);
    glVertex2i(X, 0);
    glVertex2i(0, -Y);
    glVertex2i(0, Y);
    glEnd();
}

void pintar(int x, int y) {
    glPointSize(1); 
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
    glFlush();
}

void bresenham(int x1, int y1, int x2, int y2) {
	int dx, dy, e;
	int incx, incy, inc1, inc2;

	dx = x2-x1;
	dy = y2-y1;

	if (dx < 0) dx = -dx;
	if (dy < 0) dy = -dy;
	incx = 1;

	if (x2 < x1) incx = -1;
	incy = 1;
	if (y2 < y1) incy = -1;

	int x = x1; 
    int y = y1;

	if (dx > dy) {
		pintar(x, y);
		e = 2 * dy-dx;
		inc1 = 2*(dy-dx);
		inc2 = 2*dy;
		for (int i=0; i<dx; i++) {
			if (e >= 0) {
				y += incy;
				e += inc1;
			}
			else
				e += inc2;
			x += incx;
			pintar(x, y);
		}
	} else {
		pintar(x, y);
		e = 2*dx-dy;
		inc1 = 2*(dx-dy);
		inc2 = 2*dx;
		for (int i=0; i<dy; i++) {
			if (e >= 0) {
				x += incx;
				e += inc1;
			}
			else
				e += inc2;
			y += incy;
			pintar(x, y);
		}
	}
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    drawGrid();
    glFlush();
    // Dibujo de la recta utilizando el algoritmo de Bresenham (punto medio)
    glColor3f(1.0f, 0.0f, 1.0f);
    bresenham(0, 0, -350, 450);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(10, 10);
    glutCreateWindow("basic algorithm");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
