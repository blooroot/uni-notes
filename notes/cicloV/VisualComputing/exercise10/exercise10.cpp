#include <windows.h> // Es necesaria para la integración del GLUT con windows
#include <GL/glut.h> // Incluye el OpenGL Utility Toolkit
#include <math.h>

void inicio() {
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-50, 150, -100, 150);
    glClearColor(0.2, 0.1, 0.7, 0.4);
}

void pantalla() {
    glClear(GL_COLOR_BUFFER_BIT); // Pinta la pantalla
    glColor3f(1.0, 1.0, 1.0); // Color de los objetos a dibujar

    // Con GL_TRIANGLES, cada grupo de 3 vértices especifica un triángulo
    glBegin(GL_TRIANGLES);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(80.0, 0.0, 0.0);
    glVertex3f(40.0, 100.0, 0.0);
    glEnd();

    glFlush(); // Renderiza los comandos en cola
}

int main(int argc, char *argv[]) {
    glutInit(&argc, argv); // Inciializa el GLUT y procesa la línea de comandos
    glutInitWindowSize(680,480); // Tamaño de la pantalla
    glutInitWindowPosition(10,10); // Posición inicial de la ventana en pantalla
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE); // Establece un solo buffer RGB 
    glutCreateWindow("Triangulo usando la función GL_TRIANGLES");
    
    inicio(); // Configura la proyección y color de limpieza
    glutDisplayFunc(pantalla); // Establece la función que se llamará
    glutMainLoop(); // Bucle GLUT que llama a la función establecida
    return EXIT_SUCCESS;
}
