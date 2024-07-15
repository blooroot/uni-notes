#include <windows.h>
#include <GL/glut.h>
#include <math.h>
#include <iostream>

using namespace std;

static const int X = 40;
static const int Y = 40;

int x1_1, y1_1, x2_1, y2_1;

void init() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // white screen
    gluOrtho2D(-X, X, -Y, Y);
}

void drawGrid() {
    // cian grid
    glColor3f(0.0f, 1.0f, 1.0f);
    for (int i = -X; i <= X; i++) {
        glBegin(GL_LINES);
        glVertex2i(i, -Y);
        glVertex2i(i, Y);
        glVertex2i(-X, i);
        glVertex2i(X, i);
        glEnd();
    }
    // blue axis
    glColor3f(0.0f, 0.0f, 1.0f);
    glBegin(GL_LINES);
    glVertex2i(-X, 0);
    glVertex2i(X, 0);
    glVertex2i(0, -Y);
    glVertex2i(0, Y);
    glEnd();
}

void pintar(int x, int y, bool puntoMedio) {
    glPointSize(puntoMedio ? 7.0 : 3.0);
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
    glFlush();
}

void bresenham(int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = x1 < x2 ? 1 : -1;
    int sy = y1 < y2 ? 1 : -1;
    int err = dx - dy;

    int x = x1;
    int y = y1;

    // punto medio 
    int puntoMedioX = (x1 + x2) / 2;
    int puntoMedioY = (y1 + y2) / 2;

    while (true) {
        pintar(x, y, (x == puntoMedioX && y == puntoMedioY));

        if (x == x2 && y == y2) break;

        int e2 = err * 2;
        if (e2 > -dy) {
            err -= dy;
            x += sx;
        }
        if (e2 < dx) {
            err += dx;
            y += sy;
        }
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    drawGrid();
    glFlush();
    
    glColor3f(1.0f, 0.0f, 0.0f);
    bresenham(x1_1, y1_1, x2_1, y2_1);

    glColor3f(1.0f, 0.0f, 0.0f);
    bresenham(-x1_1, y1_1, -x2_1, y2_1);

    glColor3f(1.0f, 0.0f, 0.0f);
    bresenham(-x1_1, -y1_1, -x2_1, -y2_1);

    glColor3f(1.0f, 0.0f, 0.0f);
    bresenham(x1_1, -y1_1, x2_1, -y2_1);
}

int main(int argc, char** argv) {
    // los parametros por consola:
    // x0 = 2, y0 = 3, x1 = 14, y1 = 23
    cout << "\n\nIngrese x0: "; cin >> x1_1;
    cout << "Ingrese y0: "; cin >> y1_1;
    cout << "Ingrese x1: "; cin >> x2_1;
    cout << "Ingrese y1: "; cin >> y2_1;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(10, 10);
    glutCreateWindow("Recta punto medio");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
