#include <windows.h> // Neccesary for the GLUT-Windows integration
#include <GL/glut.h> // Includes the OpenGL Utility Toolkit
#include <math.h>

void inicio() {
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-30.0, 30.0, -30.0, 30.0); 
    glClearColor(1.0, 1.0, 1.0, 0.0); // Clearing screen color
}

void drawArc(float x1, float y1, float x2, float y2, float radius) {
    // Calcular el ángulo entre los dos puntos
    float angle1 = atan2(y1, x1);
    float angle2 = atan2(y2, x2);
    // Normalizar los ángulos
    if (angle2 < angle1) {
        angle2 += 2 * M_PI;
    }
    // Dividir el arco en segmentos
    int segments = 100;
    float angleStep = (angle2 - angle1) / segments;

    glBegin(GL_LINE_STRIP);
    for (int i = 0; i <= segments; ++i) {
        float angle = angle1 + i * angleStep;
        float x = radius * cos(angle);
        float y = radius * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();
}

void pantalla() {
    glClear(GL_COLOR_BUFFER_BIT); // Cleans screen with the set color
    
    // Spiral of four centers

    float x = 2.0f;
    float y = 2.0f;

    // Sides

    glColor3f(0.0, 128.0, 0.0); // Green
    // Only the vertex
    glPointSize(5);
    glBegin(GL_POINTS);
    glVertex2f(-x, -y); // v1
    glVertex2f(-x, y); // v4
    glVertex2f(x, y); // v3
    glVertex2f(x, -y); // v2
    glEnd();

    glColor3f(255.0, 0.0, 0.0); // Red
    // The squares
    glBegin(GL_LINE_LOOP);
    glVertex2f(-x, -y); // v1
    glVertex2f(-x, y); // v4
    glVertex2f(x, y); // v3
    glVertex2f(x, -y); // v2
    glEnd();

    glColor3f(0.0, 128.0, 0.0); // Green
    // Only the vertex
    glPointSize(5);
    glBegin(GL_POINTS);
    glVertex2f(-x, -3 * y); // A
    glVertex2f(-5 * x, y); // B
    glVertex2f(x, 7 * y); // C
    glVertex2f(x * 9, -y); // D
    glEnd();

    glColor3f(255.0, 0.0, 0.0); // Red
    // Extends the sides
    glBegin(GL_LINES);
    glVertex2f(-x, -y); // v1 y A
    glVertex2f(-x, -3 * y); 
    glVertex2f(-x, y); // v4 y B
    glVertex2f(-5 * x, y); 
    glVertex2f(x, y); // v3 y C
    glVertex2f(x, 7 * y); 
    glVertex2f(x, -y); // v2 y D
    glVertex2f(x * 9, -y); 
    glEnd();

    glColor3f(0.0, 128.0, 0.0); // Green
    // Only the vertex
    glPointSize(5);
    glBegin(GL_POINTS);
    glVertex2f(-x, -11 * y); // E
    glVertex2f(-13 * x, y); // F
    glVertex2f(x, 15 * y); // G
    glEnd();

    glColor3f(255.0, 0.0, 0.0); // Red
    // The squares
    glBegin(GL_LINES);
    glVertex2f(-x, -3 * y); // A y E
    glVertex2f(-x, -11 * y);
    glVertex2f(-5 * x, y); // B y F
    glVertex2f(-13 * x, y);
    glVertex2f(x, 7 * y); // C y G
    glVertex2f(x, 15 * y);
    glEnd();

    // Bows

    glFlush(); // Renders commands pipelines
}

int main(int argc, char *argv[]) {
    glutInit(&argc, argv); // Initializes glut and processes commands pipeline
    glutInitWindowSize(600, 600); // Initial window size
    glutInitWindowPosition(10, 10); // Initial window position
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE); // Set a single RGB buffer
    glutCreateWindow("Polar Rose"); // New window name
    
    inicio(); // Sets the projection and the clear screen color
    glutDisplayFunc(pantalla); // Sets redrawing function
    glutMainLoop(); // Main glut loop that'll call the set function 
    
    return EXIT_SUCCESS;
}

