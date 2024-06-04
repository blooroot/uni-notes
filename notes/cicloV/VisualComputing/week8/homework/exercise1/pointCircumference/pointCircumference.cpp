#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>

void init(void);
void display(void);
void reshape(int, int);

int main(int argc, char** argv) {
    glutInit(&argc, argv); // Inicia la renderización
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB); // Establecemos un buffer simple RGB
    glutInitWindowSize(400, 400); // El tamaño inicial de la ventana
    glutInitWindowPosition(100, 100); // La posición inicial de la ventana en pantalla
    glutCreateWindow(argv[0]); // La vebtana tendra el nombre del programa
    init(); // Llamamos la función init
    glutDisplayFunc(display); // Se llamará "display" cada que se redibuje
    glutReshapeFunc(reshape); // Se llamará "reshape" para controlar el window size
    glutMainLoop(); 
    return 0; 
}

void init(void) { // Inicializa el color de la ventana
    glClearColor(0.0, 0.0, 0.0, 0.0); // Parametros: rojo, amarillo, azul, alpha
    glShadeModel(GL_FLAT); // Sombreado
}

void display(void) {
    GLfloat ang, radio = 8.0f, x, y; // 4 variables float 
    glClear(GL_COLOR_BUFFER_BIT); // Limpiamos buffer y establecemos sus pixeles al color especificado por glClearColor
    glPushMatrix(); // Guarda el estado actual de la matriz

    glPointSize(4.0f);

    glBegin(GL_POINTS);
    for (ang = 0.0f; ang < 2 * M_PI; ang += (2*M_PI)/20) {
        x = radio * sin(ang);
        y = radio * cos(ang);
        glVertex2f(x, y);
    }
    glEnd();
    glPopMatrix(); // Reecupera el estado del matriz
    glFlush();
}

void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h); // Posición y tamaño del viewport
    glMatrixMode(GL_PROJECTION); // Parametrizamos la matriz de proyeccion
    glLoadIdentity(); // La limpiamos con la matriz identidad
    glOrtho(-10.0, 10.0, -10.0, 10, -10.0, 10.0); // rango de 'x', 'y' y 'z'
    glMatrixMode(GL_MODELVIEW); 
    glLoadIdentity(); 
}
