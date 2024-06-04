#include <windows.h> // Es necesaria para la integración del GLUT con windows
#include <GL/glut.h> // Incluye el OpenGL Utility Toolkit
#include <math.h>

void inicio() {
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-10, 10, -10, 10); 
    glClearColor(1.0, 1.0, 1.0, 0.0); // Color de limpieza de la pantalla blanco
    glShadeModel(GL_FLAT);
}

void pantalla() {
    glClear(GL_COLOR_BUFFER_BIT); // Limpia la pantalla con el color de limpieza
    glColor3f(255.0, 0.0, 0.0);

    float radius = 5.0f; // Radio del círculo
    int numSegments = 5; // Número de segmentos para aproximar el círculo
    float rotationAngle = M_PI / 2.0f;

    glBegin(GL_LINE_LOOP); // Inicia el modo de dibujo de bucle de línea
    for(int i = 0; i < numSegments; i++) {
        float angle = 2.0f * M_PI * i / numSegments + rotationAngle; // Calcula el ángulo en radianes
        float x = radius * cos(angle); // Coordenada x
        float y = radius * sin(angle); // Coordenada y
        glVertex2f(x, y); // Especifica el vértice
    }
    glEnd(); // Finaliza el modo de dibujo

    glFlush(); // Renderiza los comandos en cola
}

int main(int argc, char *argv[]) {
    glutInit(&argc, argv); // Inicializa GLUT y procesa línea de comandos
    glutInitWindowSize(600, 480); // Tamaño inicial de la pantalla
    glutInitWindowPosition(10, 10); // Posición inicial de la ventana en la pantalla
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE); // Establece buffer RGB y un solo buffer
    glutCreateWindow("Exercise 1.1"); // La nueva ventana
    
    inicio(); // Configura la proyección y el color de la limpieza
    glutDisplayFunc(pantalla); // Se llamará a "pantalla" cada que se necesite redibujar la pantalla
    
    // Inicia el bucle principal de GLUT, que procesa eventos y llama a las funciones registradas
    glutMainLoop();
    
    return EXIT_SUCCESS;
}

