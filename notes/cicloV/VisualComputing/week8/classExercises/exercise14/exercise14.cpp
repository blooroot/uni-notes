#include <windows.h> // Es necesaria para la integración del GLUT con windows
#include <GL/glut.h> // Incluye el OpenGL Utility Toolkit
#include <math.h>

void inicio() {
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-60, 100, -80, 100);
    glClearColor(0.2, 0.1, 0.7, 0.4);
}

void pantalla() {
    glClear(GL_COLOR_BUFFER_BIT); // Pinta la pantalla
    glColor3f(1.0, 1.0, 1.0); // Color de los objetos a dibujar
    
    // GL_POLYGON, ahora especificando 5 vértices
    glBegin(GL_POLYGON);
    glVertex3f(10.0, 0.0, 0.0);
    glVertex3f(30.0, 0.0, 0.0);
    glVertex3f(40.0, 30.0, 0.0);
    glVertex3f(20.0, 60.0, 0.0);
    glVertex3f(0.0, 30.0, 0.0);
    glEnd();

    glFlush(); // Renderiza los comandos en cola
}

int main(int argc, char *argv[]) {
    glutInit(&argc, argv); // Inicializa el GLUT y procesa los comandos en cola
    glutInitWindowSize(680,480); // Tamaño de pantalla
    glutInitWindowPosition(10,10); // Posición inicial de ventana en pantalla
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE); // Establece un solo buffer RGB
    glutCreateWindow("Poligono de cinco lados con la primitiva GL_POLYGON y relleno blanco");
    
    inicio(); // Configura la proyección y color de limpieza
    glutDisplayFunc(pantalla); // Establece la función a llamar cada que se redibuje
    glutMainLoop(); // Loop principal de GLUT que llama a la función establecida
    return EXIT_SUCCESS;
}