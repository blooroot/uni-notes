#include <windows.h> // Neccesary for windows-glut integration
#include <GL/glut.h> // Includes the OpenGL Utility Toolkit
#include <math.h>
#include <iostream>
#include <stdexcept> // Neccesary for the exceptions

using namespace std;

int numQuads;
int biggestSide;

void inicio() {
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-10, 10, -10, 10); // Sets projection matrix coords range
    glClearColor(1.0, 1.0, 1.0, 0.0); // Clear screen color
    glShadeModel(GL_FLAT);
}

int validateIntegerInput(const string& prompt) { // 'prompt' = message to show

    while(true){ // prompts the message while the input is not typed yet
        string input; // here we'll save our input as a string
        int value; // here we'll save our integer if the input is succesfully converted
        size_t pos; // here we'll save the index of the last character to be converted

        cout << prompt; // we show the prompt
        cin >> input; // we save the input in 'input' (string)

        try {
            value = stoi(input, &pos); // conversion attempt
            if (pos == input.size()) { // if pos is the last character, the value was succesfully converted
                return value;
            } else { // else pos will store the index of the character that stopeed the conversion
                throw invalid_argument("Invalid input. Please enter an integer.");
            }
        } catch (const invalid_argument& e) {
            cerr << e.what() << endl; // throws the exception message
            cin.clear(); // clears the input buffer
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignores the max number of characters in the input buffer ´til it finds '\n'
        }
    }

}

void drawNestedQuads(int numQuads, int biggestSide) {
    float side = static_cast<float>(biggestSide);
    for (int i = 0; i < numQuads; ++i) {
        glPushMatrix(); // Saves current transformation (modelview matrix)
        glRotatef(45.0f * i, 0.0f, 0.0f, 1.0f); // Rotates it by 45 degrees
        // Draw next square
        float half = side / 2.0f; // Its side will be half the last one
        glColor3f(0.0, 255.0, 0.0); // Let's draw it green
        glBegin(GL_LINE_LOOP);
        glVertex2f(-half, -half);
        glVertex2f(half, -half);
        glVertex2f(half, half);
        glVertex2f(-half, half);
        glEnd();
        // Update side for the next iteration
        side *= 0.7071067811865475f; // Aproximately (\sqrt(0.5)), the square's size in every iteration
        glPopMatrix(); // Restore previous transformation (modelview matrix)
    }
} 

void inputs() {
    do {
        numQuads = validateIntegerInput("\n[1] Enter the number of quads: ");
        if (numQuads <= 0) {
            cout << "Error: The number must be greater than zero" << endl;
        }
    } while(numQuads <= 0);
    do {
        biggestSide = validateIntegerInput("\n[2] Enter the bigger quad's side: ");
        if (biggestSide <= 0) {
            cout << "Error: The number must be greater than zero" << endl;
        }
    } while(biggestSide <= 0);
}

void pantalla() {
    glClear(GL_COLOR_BUFFER_BIT); // Clears screen with the set color
    drawNestedQuads(numQuads, biggestSide);
    glFlush(); // Renderizes the commands queue
}

int main(int argc, char *argv[]) {

    inputs(); cout << endl;

    glutInit(&argc, argv); // Initialices GLUT and processes the commands pipeline
    glutInitWindowSize(500, 500); // Initial screen size
    glutInitWindowPosition(10, 10); // Initial position of the screen window
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE); // Sets a single RGB buffer
    glutCreateWindow("Quads Loop"); // New window
    
    inicio(); // Sets the projection coords and clear screen color
    glutDisplayFunc(pantalla); // Every redraw will call 'pantalla' function
    glutMainLoop(); // Initialices the main GLUT loop, that'll call the redrawing set function
    
    return EXIT_SUCCESS;
}

