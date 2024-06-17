#include <windows.h>
#include <GL/glut.h>
#include <math.h>
#include <iostream>

using namespace std;

int radio = 30;

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

void parametric(int radius, int offset){
    float x, y;
    float theta = M_PI / 4;
    float delta = 0.1;
    while (theta < M_PI / 2){
        x = radius * cos(theta);
        y = radius * sin(theta);
        theta += delta;
        pintar(round(x) + offset, round(y));
    }
}

void explicita(int radius, int offset){
    float x = 0, y = radius;
    while (x < y){
        y = sqrt(pow(radius, 2) - pow(x, 2));
        pintar(x + offset, round(y));
        x++;
    }
}

void bresenham(int radius, int offset){
    int x = 0;
    int y = radius;
    int d = 1 - radius;
    while (x < y) {
        if (d < 0) {
            d += 2 * x + 3;
        } else {
            d += 2 * (x - y) + 5;
            y--;
        }
        x++;
        pintar(x + offset, y);
    }
}

void drawExes(int offset) {
    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_LINES);
    glVertex2f(offset, -100);
    glVertex2f(offset, 100);
    glVertex2f(150, 0);
    glVertex2f(-150, 0);
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
    int offsetX = -50;
    drawExes(offsetX);

    // basic algorithm
    glColor3f(0.0, 0.0, 0.0);
    parametric(radio, offsetX);
    // explicit
    offsetX = -20;
    drawExes(offsetX);
    glColor3f(0.0, 0.0, 0.0);
    explicita(radio, offsetX);
    // bresenham
    offsetX = 10;
    drawExes(offsetX);
    glColor3f(0.0, 0.0, 0.0);
    bresenham(radio, offsetX);

    glFlush();
}

int main(int argc, char** argv) {
    cout << "\nIngrese el radio de la circunferencia: ";
    cin >> radio; cout << endl;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(10, 10);
    glutCreateWindow("Circumference drawing algorithms");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}







