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

    glLineWidth(5);

    glBegin(GL_LINE_STRIP);
    glColor3f(1.0f, 0.0f, 0.0f); // Rojo
    glVertex2f(0.0, 0.0); // v_0
    glVertex2f(50.0, 100.0);
    glVertex2f(100.0, 40.0);
    glVertex2f(100.0, -40.0);
    glVertex2f(50.0, -100.0); // v_4
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(255.0f, 255.0f, 255.0f); // Rojo
    glVertex2f(0.0, 0.0);
    glVertex2f(50.0, 100.0);
    glVertex2f(100.0, 40.0);
    glVertex2f(100.0, -40.0);
    glVertex2f(50.0, -100.0); // v_4
    glEnd(),

    glBegin(GL_LINES);
    glColor3f(1.0f, 0.0f, 0.0f); // Rojo
    glVertex2f(0.0, 0.0);
    glVertex2f(50.0, 100.0);
    glVertex2f(0.0, 0.0);
    glVertex2f(100.0, 40.0);
    glVertex2f(0.0, 0.0);
    glVertex2f(100.0, -40.0);
    glVertex2f(0.0, 0.0);
    glVertex2f(50.0, -100.0);
    glEnd();

    glFlush(); // Renderiza los comandos en cola
}

int main(int argc, char *argv[]) {
    glutInit(&argc, argv); // Inicializa GLUT y procesa línea de comandos
    glutInitWindowSize(680, 480); // Tamaño inicial de la pantalla
    glutInitWindowPosition(10, 10); // Posición inicial de la ventana en la pantalla
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE); // Establece buffer RGB y un solo buffer
    glutCreateWindow("GL_TRIANGLE_FAN"); // La nueva ventana
    
    inicio(); // Configura la proyección y el color de la limpieza
    glutDisplayFunc(pantalla); // Se llamará a "pantalla" cada que se necesite redibujar la pantalla
    
    // Inicia el bucle principal de GLUT, que procesa eventos y llama a las funciones registradas
    glutMainLoop();
    
    return EXIT_SUCCESS;
}

