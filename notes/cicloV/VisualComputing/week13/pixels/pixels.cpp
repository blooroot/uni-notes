#include <GL/glut.h>
#include <vector>

struct Point {
    int x, y;
};

std::vector<Point> selectedPoints;

void init() {
    glClearColor(0.0, 1.0, 0.0, 1.0);
    glPointSize(7);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    glColor3f(0.0, 0.0, 0.0);  
    glBegin(GL_POINTS);
    for (const auto& point : selectedPoints) {
        glVertex2i(point.x, point.y);
    }
    glEnd();

    glutSwapBuffers();
}

void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        int newX = x;
        int newY = glutGet(GLUT_WINDOW_HEIGHT) - y;

        selectedPoints.push_back({ newX, newY });

        glutPostRedisplay();
    }
}

void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, w, 0.0, h);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

// Función principal
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(10, 10);
    glutCreateWindow("pixels");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMouseFunc(mouse);
    glutMainLoop();
    return 0;
}
