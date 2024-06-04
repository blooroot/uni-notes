#include <windows.h> // Neccesary for the GLUT-Windows integration
#include <GL/glut.h> // Includes the OpenGL Utility Toolkit
#include <math.h>

void inicio() {
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-10, 10, -10, 10); 
    glClearColor(1.0, 1.0, 1.0, 0.0); // Clearing screen color
}

void pantalla() {
    glClear(GL_COLOR_BUFFER_BIT); // Cleans screen with the set color
    
    // Polar coordinates
    GLUquadricObj *pt;
    pt = gluNewQuadric();
    gluQuadricDrawStyle(pt, GLU_LINE); 
    glColor3f (1.0, 0.0, 0.0); // It's red
    gluDisk(pt, 0, 9, 15, 6); // (intern_radius, extern_radius, n_segments, n_rings)

    // Cardioid
    glColor3f(0.0, 0.0, 1.0); // Let's make it blue
    float a = 2.0f; // This lil bro draws the inner knot
    glBegin(GL_LINE_STRIP);
    for (float theta = 0; theta <= 2 * M_PI; theta += 0.01f) {
        float r = 2.5 * (1 + a * sin(theta)); // Cardioid radius
        float x = -r * sin(theta);
        float y = r * cos(theta);
        glVertex2f(x, y);
    }
    glEnd();

    glFlush(); // Renders commands pipelines
}

int main(int argc, char *argv[]) {
    glutInit(&argc, argv); // Initializes glut and processes commands pipeline
    glutInitWindowSize(600, 600); // Initial window size
    glutInitWindowPosition(10, 10); // Initial window position
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE); // Set a single RGB buffer
    glutCreateWindow("Hollow Disk"); // New window name
    
    inicio(); // Sets the projection and the clear screen color
    glutDisplayFunc(pantalla); // Sets redrawing function
    glutMainLoop(); // Main glut loop that'll call the set function 
    
    return EXIT_SUCCESS;
}

