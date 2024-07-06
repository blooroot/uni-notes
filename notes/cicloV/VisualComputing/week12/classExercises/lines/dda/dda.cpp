#include <windows.h>
#include <GL/glut.h>
#include <math.h>
#include <iostream>

using namespace std;

static const int X = 50;
static const int Y = 50;

// Variables globales para almacenar los parámetros de las líneas
int x1_1, y1_1, x2_1, y2_1;

void init() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Fondo blanco
    gluOrtho2D(-X, Y, -X, Y);
}

void drawGrid() {
    // Rejilla (verde)
    glColor3f(0.0f, 1.0f, 0.498f);
    for (int i = -X; i <= X; i++) {
        glBegin(GL_LINES);
        glVertex2i(i, -Y);
        glVertex2i(i, Y);
        glVertex2i(-X, i);
        glVertex2i(X, i);
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
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
    glFlush();
}

void dda(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    int steps = max(abs(dx), abs(dy));
    float xIncrement = dx / float(steps);
    float yIncrement = dy / float(steps);
    float x = x1;
    float y = y1;

    for (int i = 0; i <= steps; i++) {
        glPointSize(4);
        pintar(round(x), round(y));
        x += xIncrement;
        y += yIncrement;
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    drawGrid();
    glFlush();
    
    // Dibujo de las rectas utilizando DDA con los parámetros ingresados por consola
    glColor3f(1.0f, 0.0f, 1.0f);
    dda(x1_1, y1_1, x2_1, y2_1);

    glColor3f(1.0f, 0.0f, 1.0f);
    dda(-x1_1, y1_1, -x2_1, y2_1);

    glColor3f(1.0f, 0.0f, 1.0f);
    dda(-x1_1, -y1_1, -x2_1, -y2_1);

    glColor3f(1.0f, 0.0f, 1.0f);
    dda(x1_1, -y1_1, x2_1, -y2_1);
}

int main(int argc, char** argv) {
    cout << "\n\nIngrese x0: "; cin >> x1_1;
    cout << "Ingrese y0: "; cin >> y1_1;
    cout << "Ingrese x1: "; cin >> x2_1;
    cout << "Ingrese y1: "; cin >> y2_1;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(10, 10);
    glutCreateWindow("Ejercicio 1");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
