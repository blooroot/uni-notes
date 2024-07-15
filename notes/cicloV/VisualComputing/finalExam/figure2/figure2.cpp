#include <windows.h> // Neccesary for the GLUT-Windows integration
#include <GL/glut.h> // Includes the OpenGL Utility Toolkit
#include <math.h>

double width = 60;
double heigth = 60;
double scale = 5.0f;

void inicio()
{
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-width/scale, width/scale, -heigth/scale, heigth/scale);
    glClearColor(0.0,0.0,0.0,0.0);
}

void pantalla()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_LINES);
    glVertex2f(0.0, 0.0);
    glVertex2f(-width/scale, 0.0);

    glVertex2f(0.0, 0.0);
    glVertex2f(width/scale, 0.0);

    glVertex2f(0.0, 0.0);
    glVertex2f(0.0, -heigth/scale);

    glVertex2f(0.0, 0.0);
    glVertex2f(0.0, heigth/scale);

    glEnd();

    glColor3f(1.0,0.0,0.0);
    glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    for(float i=0.0f; i < 2*M_PI; i+=0.01){
        float radio = sin(3 * i);

        float x = 11 * radio * cos(1 * i);
        float y = 11 * radio * sin(4 * i);

        glVertex2f(x,y);
    }
    glEnd();

    glFlush();
}
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(800,800);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutCreateWindow("Mascara");
    inicio();
    glutDisplayFunc(pantalla);
    glutMainLoop();
    return EXIT_SUCCESS;
}