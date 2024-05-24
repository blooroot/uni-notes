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

    // Una línea desde (0,0) al (100,0)
    glBegin(GL_LINES);
    glVertex2i(0, 0);
    glVertex2i(100, 0);
    glEnd();

    // Una línea desde (100,0) al (100,100)
    glBegin(GL_LINES);
    glVertex2i(100, 0);
    glVertex2i(100, 100);
    glEnd();

    // Una línea desde (100,100) al (0,100) 
    glBegin(GL_LINES);
    glVertex2i(100, 100);
    glVertex2i(0, 100);
    glEnd();

    // Una línea desde (0,100) al (0,0)
    glBegin(GL_LINES);
    glVertex2i(0, 100);
    glVertex2i(0, 0);
    glEnd();

    glFlush(); // Renderiza los comandos en cola
}

int main(int argc, char *argv[]) {
    glutInit(&argc, argv); // Inicializa GLUT y procesa cualquier argumento de línea de comandos específico de GLUT
    glutInitWindowSize(680,480); // Establece el tamaño inicial de la pantalla
    glutInitWindowPosition(10,10); // Establece la posición inicial de la ventana en pantalla
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE); // Establece un buffer RGB y un solo buffer
    glutCreateWindow("Cuadrado vacío"); // La nueva ventana 
    
    inicio(); // Configura la proyección y el color de la limpieza
    glutDisplayFunc(pantalla); // Se llamara a "pantalla" cada que se necesite redibujar la ventana

    // Inicia el bucle principal de GLUT, que procesa eventos y llama las funciones registrada (pantalla)
    glutMainLoop();

    return EXIT_SUCCESS;
}

