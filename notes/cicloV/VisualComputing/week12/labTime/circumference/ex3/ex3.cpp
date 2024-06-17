#include <windows.h>
#include <GL/glut.h>
#include <math.h>
#include <iostream>

using namespace std;

int radius = 30;
int global_x = 0;
int global_y = 0;

void init() {
    glClearColor(1.0, 1.0, 1.0, 0.0); // Fondo blanco
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-50, 50, -50, 50);
}

void pintar(int x, int y) {
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

void parametric(int radius, int offsetx, int offsety){
    float x, y;
    float theta = M_PI / 4;
    float delta = 0.1;
    while (theta < M_PI / 2) {
        x = radius * cos(theta);
        y = radius * sin(theta);
        theta += delta;
        pintar(round(x) + offsetx, round(y) + offsety);
    }
}

void drawExes(int offsetx, int offsety) {
    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_LINES);
    glVertex2f(offsetx, -100);
    glVertex2f(offsetx, 100);
    glVertex2f(150, offsety);
    glVertex2f(-150, offsety);
    glEnd();
}

void drawGrid() {
    glColor3f(0.0f, 1.0f, 0.498f);
    int inc = -150;
    glBegin(GL_LINES);
    for (int i = 0; i <= 300; i++) {
        glVertex2f(-150, inc);
        glVertex2f(150, inc);
        glVertex2f(inc, 150);
        glVertex2f(inc, -150);
        inc++;
    }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    drawGrid();
    glPointSize(4);
    drawExes(global_x, global_y);
    glColor3f(0.0, 0.0, 0.0);
    parametric(radius, global_x, global_y);
    glFlush();
}

int main(int argc, char** argv) {
    cout << "\n[1] Introduce el radio de la circunferencia: "; cin >> radius;
    cout << "[2] Abscisa: "; cin >> global_x;
    cout << "[3] Ordenada: "; cin >> global_y; cout << endl;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(10, 10);
    glutCreateWindow("Circunferencia con representacion parametrica");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}












