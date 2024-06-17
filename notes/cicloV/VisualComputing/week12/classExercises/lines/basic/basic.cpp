#include <windows.h> // Es necesaria para la integración del GLUT con windows
#include <GL/glut.h> // Incluye el OpenGL Utility Toolkit
#include <math.h>

static const int X = 600;
static const int Y = 600;

void init() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Fondo blanco
    gluOrtho2D(-X, X, -Y, Y); // Definir el sistema de coordenadas
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
    glPointSize(1.5f);
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
    glFlush();
}

void basic(int x0, int y0, int x1, int y1) {
    float dx, dy, m, b, y;
    // Cálculo de pendiente e intercepto
    dx = x1 - x0;
    dy = y1 - y0;
    m = dy / dx;
    b = y0 - m * x0;
    // Inicializamos y con el valor de y_0
    y = y0;
    // Dibujo de la recta
    for (int x = x0; x <= x1; x++) {
        pintar(x, round(y));
        y = m * x + b;
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    drawGrid();
    glFlush();
    // Dibujo de la recta
    glColor3f(1.0f, 0.0f, 1.0f);
    basic(0, 0, 200, 450);
}

int main(int argc, char** argv){
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










