#include <windows.h> // Es necesaria para la integración del GLUT con windows
#include <GL/glut.h> // Incluye el OpenGL Utility Toolkit
#include <math.h>

void inicio() {
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-10, 10, -10, 10); 
    glClearColor(1.0, 1.0, 1.0, 0.0); // Color de limpieza de la pantalla
}

void pantalla() {
    glClear(GL_COLOR_BUFFER_BIT); // Limpia la pantalla con el color de limpieza

    GLUquadricObj *pt;
    pt = gluNewQuadric();
    
    gluQuadricDrawStyle(pt, GLU_FILL); // Con GLU_LINE, las figuras serán huecas
    glColor3f (1.0, 0.0, 0.0); // Color de las figuras
    // (radio_interno, radio_externo, n_segments, n_anillos)
    gluDisk(pt, 4, 9, 15, 6);

    glFlush(); // Renderiza los comandos en cola
}

int main(int argc, char *argv[]) {
    glutInit(&argc, argv); // Inicializa GLUT y procesa línea de comandos
    glutInitWindowSize(480, 480); // Tamaño inicial de la pantalla
    glutInitWindowPosition(10, 10); // Posición inicial de la ventana en la pantalla
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE); // Establece buffer RGB y un solo buffer
    glutCreateWindow("Plan Figure"); // La nueva ventana
    
    inicio(); // Configura la proyección y el color de la limpieza
    glutDisplayFunc(pantalla); // Se llamará a "pantalla" cada que se necesite redibujar la pantalla
    
    // Inicia el bucle principal de GLUT, que procesa eventos y llama a las funciones registradas
    glutMainLoop();
    
    return EXIT_SUCCESS;
}

