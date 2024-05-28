#include <windows.h> // Es necesaria para la integración del GLUT con windows
#include <GL/glut.h> // Incluye el OpenGL Utility Toolkit
#include <math.h>

void inicio() {
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-40, 100, -60, 100);
    glClearColor(0.2, 0.1, 0.7, 0.4);
}

void pantalla() {
    glClear(GL_COLOR_BUFFER_BIT); // Pinta la pantalla
    glColor3f(1.0, 1.0, 1.0); // Color de los objetos a dibujar
    
    glBegin(GL_QUAD_STRIP);
    glVertex3f(0.0, 0.0, 0.0); // Observe que el siguiente vértice no sigue la secuencia recomendada
    glVertex3f(0.0, 50.0, 0.0);
    glVertex3f(30.0, 0.0, 0.0); // Esto se debe a que debe mantener los dos últimos vértices para generar un nuevo cuadrilátero si es necesario.
    glVertex3f(30.0,50.0,0.0);
    glVertex3f(60.0,0.0,0.0); // Se construirá un nuevo cuadrilátero partiendo de los dos últimos vértices
    glVertex3f(60.0,50.0,0.0);
    glEnd();

    // Esta línea nos permite ver la división
    glColor3f(0.0, 0.0, 0.0); 
    glBegin(GL_LINES);
    glVertex3f(30.0, 0.0, 0.0);
    glVertex3f(30.0, 50.0, 0.0);
    glEnd();

    glFlush();
}

int main(int argc, char *argv[]) {
    glutInit(&argc, argv); // Inicializa el GlUT y procesa la línea de comandos
    glutInitWindowSize(680,480); // Tamaño de pantalla
    glutInitWindowPosition(10,10); // Posición inicial de la ventana en pantalla
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE); // Establece un solo buffer RGB
    glutCreateWindow("Cuadrilatero graficado con funcion QUAD_STRIP y relleno blanco");
    inicio(); // Configura la proyección y color de limpieza
    glutDisplayFunc(pantalla); // Establece la función a llamar cada que se redibuje
    glutMainLoop(); // Loop principal de GLUT que llama a la función establecida
    return EXIT_SUCCESS;
}