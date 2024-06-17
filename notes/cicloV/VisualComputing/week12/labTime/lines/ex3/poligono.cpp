#include <windows.h>
#include <GL/glut.h>
#include <math.h>

static const int X = 600;
static const int Y = 600;

typedef struct {
    int x, y;
} Point;

void init() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Fondo blanco
    gluOrtho2D(-X, X, -Y, Y);
}

void pintar(int x, int y) {
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
    glFlush();
}

void bresenham(int x0, int y0, int xf, int yf) {
    int dx = abs(xf - x0);
    int dy = abs(yf - y0);
    int sx = (x0 < xf) ? 1 : -1;
    int sy = (y0 < yf) ? 1 : -1;
    int err = dx - dy;

    while (true) {
        pintar(x0, y0);

        if (x0 == xf && y0 == yf) break;
        int e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            x0 += sx;
        }
        if (e2 < dx) {
            err += dx;
            y0 += sy;
        }
    }
}

void drawStarPolygon(int N, int step) {
    Point vertices[N];
    float angleStep = 2 * M_PI / N;
    int radius = 200;

    // Generar vértices del polígono regular
    for (int i = 0; i < N; i++) {
        vertices[i].x = radius * cos(i * angleStep);
        vertices[i].y = radius * sin(i * angleStep);
    }

    // Dibujar el polígono estrellado
    for (int i = 0; i < N; i++) {
        int nextIndex = (i + step) % N;
        bresenham(vertices[i].x, vertices[i].y, vertices[nextIndex].x, vertices[nextIndex].y);
    }
}

void drawGrid() {
    // Rejilla (verde)
    glColor3f(0.0f, 1.0f, 0.498f);
    for (int i = -600; i <= 600; i += 20) {
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

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0f, 0.0f, 0.0f); // Color negro para la línea

    drawGrid();

    // Dibujar un polígono estrellado con 7 lados y un paso de 2 (7/2)
    glColor3f(0.0f, 0.0f, 0.0f); // Color rojo para el polígono estrellado
    drawStarPolygon(9, 4);

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(10, 10);
    glutCreateWindow("Star Polygon with Bresenham");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
