#include <windows.h> // Es necesaria para la integración del GLUT con windows
#include <GL/glut.h> // Incluye el OpenGL Utility Toolkit
#include <math.h>

void inicio() {
    glMatrixMode(GL_PROJECTION);
    glOrtho(-10.0, 10.0, -10.0, 10, -10.0, 10.0);
    glClearColor(255.0, 255.0, 255.0, 0.0); // Color de limpieza de la pantalla
}

void pantalla() {
    glClear(GL_COLOR_BUFFER_BIT); // Limpia la pantalla con el color de limpieza
    glColor3f(1.0, 1.0, 1.0); // Establece el color de los objetos a dibujar a blanco

    GLUquadricObj *pt;
    pt = gluNewQuadric();
    gluQuadricDrawStyle(pt, GLU_LINE);
    glColor3f (1.0, 0.0, 0.0);
    // Dibuja Disco parcial izquierdo
    gluPartialDisk(pt, 0, 9, 15, 6, 45, 80);

    pt = gluNewQuadric();
    gluQuadricDrawStyle(pt, GLU_LINE);
    glColor3f (1.0, 0.0, 0.0);
    // Dibuja Disco parcial derecho
    gluPartialDisk(pt, 0, 5, 15, 6, 235, 80);

    float a = 2.0f; // Constante que define el tamaño de la curva (más pequeña)
    int num_segments = 100; // Número de segmentos (puntos)

    glBegin(GL_LINE_LOOP);
    for (int i = 0; i <= num_segments; i++) {
        float t = 2.0f * 3.1415926f * float(i) / float(num_segments); // Calcula el ángulo actual
        float x = (a * cosf(t) * sinf(t)) / (1 + sinf(t) * sinf(t)); // Calcula la coordenada X 
        float y = (a * cosf(t)) / (1 + sinf(t) * sinf(t)); // Calcula la coordenada Y 
        glVertex2f(x, y); // Especifica el vértice
    }
    glEnd();

    glFlush(); // Renderiza los comandos en cola
}

int main(int argc, char *argv[]) {
    glutInit(&argc, argv); // Inicializa GLUT y procesa línea de comandos
    glutInitWindowSize(600, 600); // Tamaño inicial de la pantalla
    glutInitWindowPosition(10, 10); // Posición inicial de la ventana en la pantalla
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE); // Establece buffer RGB y un solo buffer
    glutCreateWindow("Examen Parcial"); // La nueva ventana
    
    inicio(); // Configura la proyección y el color de la limpieza
    glutDisplayFunc(pantalla); // Se llamará a "pantalla" cada que se necesite redibujar la pantalla
    
    // Inicia el bucle principal de GLUT, que procesa eventos y llama a las funciones registradas
    glutMainLoop();
    
    return EXIT_SUCCESS;
}

