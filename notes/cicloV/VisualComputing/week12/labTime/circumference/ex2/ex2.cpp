#include <windows.h>
#include <GL/glut.h>
#include <math.h>
#include <iostream>

using namespace std;

int radius = 30;
int rgb_red = 1;
int rgb_green = 1;
int rgb_blue = 1;
int global_x = 0;
int global_y = 0;
float thickness = 2.0;

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

void bresenham(int radius, int offsetx, int offsety) {
    int x = 0;
    int y = radius;
    int d = 1 - radius;
    while (x < y) {
        if (d < 0){
            d += 2 * x + 3;
        } else {
            d += 2 * (x - y) + 5;
            y--;
        }
        x++;
        pintar(x + offsetx, y + offsety);
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
    glPointSize(thickness);
    drawExes(global_x, global_y);
    glColor3f(rgb_red, rgb_green, rgb_blue);
    bresenham(radius, global_x, global_y);
    glFlush();
}

int main(int argc, char** argv) {
    cout << "\nCircunferencia con Bresenham en base a color y grosor\n";
    cout << "\n-----------------------------------------------------\n";
    cout << "\n[1] Introduce el radio de la circunferencia: "; cin >> radius;
    cout << "[2] Abscisa: "; cin >> global_x;
    cout << "[3] Ordenada: "; cin >> global_y;
    cout << "[4] RGB Rojo: "; cin >> rgb_red;
    cout << "[5] RGB Verde: "; cin >> rgb_green;
    cout << "[6] RGB Azul: "; cin >> rgb_blue;
    cout << "[7] Grosor: "; cin >> thickness; cout << endl;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(10, 10);
    glutCreateWindow("Circunferencia con Bresenham en base a color y grosor");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
