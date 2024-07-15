#include <windows.h> // Neccesary for the GLUT-Windows integration
#include <GL/glut.h> // Includes the OpenGL Utility Toolkit
#include <math.h>

const int pointsCount = 1000; 
const float param = 10.0f;

void inicio() {
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-10, 10, -10, 10); 
    glClearColor(0.0, 0.0, 0.0, 0.0); // Clearing screen color
}

void pantalla() {
    glClear(GL_COLOR_BUFFER_BIT); // Cleans screen with the set color
    
    glLineWidth(3.0); 
    // axis
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINES);
    // x
    glVertex2f(-10.0, 0.0);
    glVertex2f(10.0, 0.0);
    // y
    glVertex2f(0.0, -10.0);
    glVertex2f(0.0, 10.0);
    glEnd();

    GLUquadricObj *pt;
    pt = gluNewQuadric();
    gluQuadricDrawStyle(pt, GLU_LINE);     
    // polar rose
    glColor3f(1.0, 0.0, 0.0);
    glLineWidth(3.0); 

    glBegin(GL_LINE_LOOP);

    // wings
    for (int i = 0; i < pointsCount; ++i) {
        float t = i * 2 * M_PI / pointsCount;
        float x = param / 1.125 * sin(1 * t) * cos(t);
        float y = param / 1.5 * sin(2 * t) * sin(t);
        glVertex2f(x, y);
    }

    glEnd();
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < pointsCount; ++i) {
        float t = i * 2 * M_PI / pointsCount;
        float x = param / 4 * cos(t) / (1 + sin(t) * sin(t));
        float y = param / 4 * sin(t) * cos(t) / (1 + sin(t) * sin(t));
        glVertex2f(x, y);
    }

    glEnd();
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < pointsCount; ++i) {
        float t = i * 2 * M_PI / pointsCount;
        float x = param / 4 * cos(t);
        float y = param / 2.5 * sin(2 * t);
        glVertex2f(x, y);
    }

    glEnd();

    glFlush(); 
}

int main(int argc, char *argv[]) {
    glutInit(&argc, argv); 
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(10, 10); 
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE); 
    glutCreateWindow("Alas"); 
    
    inicio(); 
    glutDisplayFunc(pantalla); 
    glutMainLoop();
    
    return EXIT_SUCCESS;
}

