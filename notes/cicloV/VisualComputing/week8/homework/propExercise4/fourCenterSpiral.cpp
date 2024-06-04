#include <windows.h> // Neccesary for the GLUT-Windows integration
#include <GL/glut.h> // Includes the OpenGL Utility Toolkit
#include <math.h>

void inicio() {
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-30.0, 30.0, -30.0, 30.0); 
    glClearColor(1.0, 1.0, 1.0, 0.0); // Clearing screen color
}

void pantalla() {
    glClear(GL_COLOR_BUFFER_BIT); // Cleans screen with the set color
    
    // Spiral of four centers

    float x = 2.0f;
    float y = 2.0f;

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
    glVertex2f(x, y + 7); // C
    glVertex2f(x + 9, -y); // D
    glEnd();

    glColor3f(255.0, 0.0, 0.0); // Red
    // The squares
    glBegin(GL_LINES);
    glVertex2f(-x, -y); // v1 y A
    glVertex2f(-x, -3 * y); 
    glVertex2f(-x, y); // v4 y B
    glVertex2f(-5 * x, y); 
    glVertex2f(x, y); // v3 y C
    glVertex2f(x, y + 7); 
    glVertex2f(x, -y); // v2 y D
    glVertex2f(x + 9, -y); 
    glEnd();

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

