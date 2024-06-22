#include <GL/glut.h>

void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0); 
    glEnable(GL_DEPTH_TEST); 
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    gluLookAt(0.0, 0.0, 5.0, 
              0.0, 0.0, 0.0,
              0.0, 1.0, 0.0);
    glRotatef(220.0, 1.0, 0.0, 0.0); 
    glRotatef(220.0, 0.0, 1.0, 0.0); 

    // radio 1.0, 20 meridianos y 10 paralelas
    glColor3f(0.0, 0.0, 1.0);
    glutWireSphere(1.0, 20, 10);

    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("solid 2");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}
