#include <GL/glut.h>
#include <cmath>

const float PI = 3.14159265358979323846f;
const float Y_OFFSET = 0.5f; // Desplazamiento hacia arriba

void drawPolarGrid() {
    glColor3f(1.0f, 0.0f, 0.0f); // Rojo para las coordenadas polares

    glLineWidth(1.0f);

    // Dibujar c�rculos conc�ntricos
    for (float r = 1.0f; r <= 5.0f; r += 1.0f) {
        glBegin(GL_LINE_LOOP);
        for (float theta = 0.0f; theta <= 2.0f * PI; theta += 0.01f) {
            float x = r * cos(theta);
            float y = r * sin(theta);
            glVertex2f(x, y);
        }
        glEnd();
    }

    // Dibujar l�neas radiales
    glBegin(GL_LINES);
    for (float theta = 0.0f; theta < 2.0f * PI; theta += PI / 6.0f) { // Paso de 30 grados
        glVertex2f(0.0f, 0.0f);
        glVertex2f(5.0f * cos(theta), 5.0f * sin(theta));
    }
    glEnd();
}

void drawFlower() {
    glColor3f(0.0f, 0.0f, 1.0f); // Azul para la flor
    float scaleFactor = 0.6f; // Factor de escala para los pétalos
    float Y_OFFSET = -0.1f; // Desplazamiento en Y

    glLineWidth(2.0f);

    // Dibujar la flor con 5 pétalos
    glBegin(GL_LINE_STRIP);
    for (float theta = 0.0f; theta <= 2.0f * PI; theta += 0.01f) {
        // Radio modificado para los nudos
        float r = 1.0f + 0.5f * cos(5.0f * theta);

        // Coordenadas de la flor
        float x = scaleFactor * r * cos(theta);
        float y = scaleFactor * r * sin(theta) + Y_OFFSET;

        glVertex2f(x, y);
    }
    glEnd();

    // Dibujar un círculo más pequeño en el centro
    glColor3f(0.0f, 0.0f, 1.0f); // Azul para el círculo central
    float scaleFactorCenter = 0.2f; // Factor de escala para el círculo central
    glBegin(GL_LINE_LOOP);
    for (float theta = 0.0f; theta <= 2.0f * PI; theta += 0.01f) {
        float x = scaleFactorCenter * cos(theta);
        float y = scaleFactorCenter * sin(theta);
        glVertex2f(x, y);
    }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    drawPolarGrid();
    drawFlower();

    glFlush();
}

void init() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-6.0f, 6.0f, -6.0f, 6.0f);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 800);
    glutCreateWindow("Flor de 5 pétalos con coordenadas polares");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}