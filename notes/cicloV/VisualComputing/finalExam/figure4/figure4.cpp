#include <windows.h> // Neccesary for the GLUT-Windows integration
#include <GL/glut.h> // Includes the OpenGL Utility Toolkit
#include <math.h>

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
    glBegin(GL_LINE_STRIP);
    for (float theta = 0; theta <= 10 * M_PI; theta += 0.01f) {
        float r = 4 * (sin((3.0/7.0) * theta));
        float x = r * cos(theta);
        float y = r * sin(theta);
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
    glutCreateWindow("figure 3: globos"); 
    
    inicio(); 
    glutDisplayFunc(pantalla); 
    glutMainLoop();
    
    return EXIT_SUCCESS;
}

