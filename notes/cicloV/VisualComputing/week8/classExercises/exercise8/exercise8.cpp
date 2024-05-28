#include <windows.h> // Es necesaria para la integración del GLUT con windows
#include <GL/glut.h> // Incluye el OpenGL Utility Toolkit
#include <math.h>

void inicio() {
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-60, 100, -50, 100); // Rango de coordenadas
    glClearColor(0.2, 0.1, 0.7, 0.4); // Color de limpieza de la pantalla
}

void pantalla() {
    glClear(GL_COLOR_BUFFER_BIT); // Pinta la pantalla
    glColor3f(1.0, 1.0, 1.0); // Color de los objetos a dibujar

    //glPointSize(2.0);

    float height = 80.0; // Altura del polígono
    float y_center = (-50.0 + 100.0 - height) / 2.0; // Punto y de inicio para que salga centrado 

    // Con GL_LINE_LOOP los vertices se conectan al anterior y al siguiente, 
    // y el ultimo se conecta de vuelta con el primero
    glBegin(GL_LINE_LOOP);
    glVertex3f(0.0, y_center, 0.0);  
    glVertex3f(40.0, y_center, 0.0); 
    glVertex3f(40.0, y_center + height, 0.0); 
    glVertex3f(0.0, y_center + height, 0.0);
    glEnd();

    glFlush(); // Renderiza los comandos en cola
}

int main(int argc, char *argv[]) {
    glutInit(&argc, argv); // Inicializa el GLUT y procesa cualquier argumento de línea de comandos
    glutInitWindowSize(680,480); // Tamaño de la pantalla
    glutInitWindowPosition(10,10); // Posición inicial de la ventana en pantalla
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE); // Establece un solo buffer RGB
    glutCreateWindow("Poligono creado con la funcion GL_LINE_LOOP uniendo puntos aleatoriamente");
    
    inicio(); // Configura la proyeccion y el color de la limpieza
    glutDisplayFunc(pantalla); // Se llama a "pantalla" cada que se necesite redibujar la ventana
    
    // Bucle principal de GLUT: llama funciones registradas
    glutMainLoop();
    
    return EXIT_SUCCESS;
}