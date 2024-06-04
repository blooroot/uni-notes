#include <windows.h> // Es necesaria para la integración del GLUT con windows
#include <GL/glut.h> // Incluye el OpenGL Utility Toolkit
#include <math.h>

void inicio() {
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-200, 200, -200, 200); 
    glClearColor(0.0, 0.0, 0.0, 0.0); // Color de limpieza de la pantalla
}

void pantalla() {
    glClear(GL_COLOR_BUFFER_BIT); // Limpia la pantalla con el color de limpieza
    glColor3f(1.0, 1.0, 1.0); // Establece el color de los objetos a dibujar a blanco

    glLineWidth(5); // El grosor de las líneas será de 5 pixeles

    glBegin(GL_QUAD_STRIP);
    glVertex2f(-90.0, -20.0); // A
    glVertex2f(-100.0, 50.0); // B
    glVertex2f(-47.0, -15.0); // C
    glVertex2f(-40.0, 30.0); // D
    glVertex2f(20.0, -40.0); // E
    glVertex2f(19.0, 40.0); // F
    glVertex2f(78.0, -35.0); // G
    glVertex2f(85.0, 34.5); // H
    glEnd();

    glColor3f(255.0, 0.0, 0.0);

    glBegin(GL_LINE_STRIP);
    glVertex2f(-90.0, -20.0); // A
    glVertex2f(-100.0, 50.0); // B
    glVertex2f(-40.0, 30.0); // D
    glVertex2f(19.0, 40.0); // F
    glVertex2f(85.0, 34.5); // H
    glVertex2f(78.0, -35.0); // G
    glVertex2f(20.0, -40.0); // E
    glVertex2f(-47.0, -15.0); // C
    glVertex2f(-90.0, -20.0); // A
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(-90.0, -20.0); // A
    glVertex2f(-100.0, 50.0); // B
    glVertex2f(-47.0, -15.0); // C
    glVertex2f(-40.0, 30.0); // D
    glVertex2f(20.0, -40.0); // E
    glVertex2f(19.0, 40.0); // F
    glVertex2f(78.0, -35.0); // G
    glVertex2f(85.0, 34.5); // H
    glEnd();

    glFlush(); // Renderiza los comandos en cola
}

int main(int argc, char *argv[]) {
    glutInit(&argc, argv); // Inicializa GLUT y procesa línea de comandos
    glutInitWindowSize(680, 480); // Tamaño inicial de la pantalla
    glutInitWindowPosition(10, 10); // Posición inicial de la ventana en la pantalla
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE); // Establece buffer RGB y un solo buffer
    glutCreateWindow("GL_QUAD_STRIP"); // La nueva ventana
    
    inicio(); // Configura la proyección y el color de la limpieza
    glutDisplayFunc(pantalla); // Se llamará a "pantalla" cada que se necesite redibujar la pantalla
    
    // Inicia el bucle principal de GLUT, que procesa eventos y llama a las funciones registradas
    glutMainLoop();
    
    return EXIT_SUCCESS;
}

