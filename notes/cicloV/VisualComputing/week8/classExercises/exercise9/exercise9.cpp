#include <windows.h> // Es necesaria para la integración del GLUT con windows
#include <GL/glut.h> // Incluye el OpenGL Utility Toolkit
#include <math.h>

void inicio() {
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-50, 150, -50, 150); 
    glClearColor(0.2, 0.1, 0.7, 0.4); // Color de limpieza de la pantalla
}

void pantalla() {
    glClear(GL_COLOR_BUFFER_BIT); // Limpia la pantalla con el color de limpieza
    glColor3f(1.0, 1.0, 1.0); // Establece el color de los objetos a dibujar a blanco

    // Con GL_LINE_STRIP los vertices se conectan al anterior y al siguiente
    // pero el último NO se conecta de vuelta con el primero 
    glBegin(GL_LINE_STRIP);
    glVertex2f(0.0,50.0);
    glVertex2f(0.0,0.0);
    glVertex2f(70.0,0.0);
    glVertex2f(70.0,100.0);
    glVertex2f(0.0,100.0);
    glEnd();
    
    glFlush(); // Rendderiza los componentes en cola
}

int main(int argc, char *argv[]) {
    glutInit(&argc, argv); // Inicializa el GLUT y procesa la línea de comandos
    glutInitWindowSize(680,480); // Tamaño inicial de la pantalla
    glutInitWindowPosition(10,10); // Posición inicial de la ventana en la pantalla
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE); // Establece buffer RGB y un solo buffer
    glutCreateWindow("Rectangulo inconcluso con la función GL_LINE_STRIP");
    
    inicio(); // Configura la proyección y color de limpieza
    glutDisplayFunc(pantalla); // Se llamará a pantalla cada que se necesite redibujar
    
    // Inicia el bucle principal de GLUT, que llama a las funciones registradas
    glutMainLoop();

    return EXIT_SUCCESS;
}