#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

float angle = 0.0f; // Initial angle for rotation

void initGL() {
    glEnable(GL_DEPTH_TEST); // Enable depth testing for 3D
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear the color and depth buffers
    glLoadIdentity(); // Load the identity matrix
    glTranslatef(0.0f, 0.0f, -5.0f); // Move the object back along the z-axis
    glRotatef(angle, 0.0f, 1.0f, 0.0f); // Rotate the object around the y-axis

    glBegin(GL_QUADS); // Start drawing a cube
        glColor3f(1.0f, 0.0f, 0.0f); // Red color
        glVertex3f(-1.0f, 1.0f, -1.0f); // Top-left
        glVertex3f(-1.0f, -1.0f, -1.0f); // Bottom-left
        glVertex3f(1.0f, -1.0f, -1.0f); // Bottom-right
        glVertex3f(1.0f, 1.0f, -1.0f); // Top-right

        glColor3f(0.0f, 1.0f, 0.0f); // Green color
        glVertex3f(-1.0f, -1.0f, 1.0f); // Bottom-left
        glVertex3f(-1.0f, -1.0f, -1.0f); // Bottom-right
        glVertex3f(-1.0f, 1.0f, -1.0f); // Top-right
        glVertex3f(-1.0f, 1.0f, 1.0f); // Top-left

        glColor3f(0.0f, 0.0f, 1.0f); // Blue color
        glVertex3f(1.0f, -1.0f, -1.0f); // Bottom-left
        glVertex3f(1.0f, -1.0f, 1.0f); // Bottom-right
        glVertex3f(1.0f, 1.0f, 1.0f); // Top-right
        glVertex3f(1.0f, 1.0f, -1.0f); // Top-left

        glColor3f(1.0f, 1.0f, 0.0f); // Yellow color
        glVertex3f(-1.0f, -1.0f, 1.0f); // Bottom-left
        glVertex3f(-1.0f, 1.0f, 1.0f); // Top-left
        glVertex3f(1.0f, 1.0f, 1.0f); // Top-right
        glVertex3f(1.0f, -1.0f, 1.0f); // Bottom-right

        glColor3f(1.0f, 0.0f, 1.0f); // Magenta color
        glVertex3f(-1.0f, -1.0f, -1.0f); // Bottom-left
        glVertex3f(-1.0f, -1.0f, 1.0f); // Bottom-right
        glVertex3f(1.0f, -1.0f, 1.0f); // Top-right
        glVertex3f(1.0f, -1.0f, -1.0f); // Top-left

        glColor3f(0.0f, 1.0f, 1.0f); // Cyan color
        glVertex3f(-1.0f, 1.0f, -1.0f); // Bottom-left
        glVertex3f(-1.0f, 1.0f, 1.0f); // Bottom-right
        glVertex3f(1.0f, 1.0f, 1.0f); // Top-right
        glVertex3f(1.0f, 1.0f, -1.0f); // Top-left
    glEnd(); // End drawing the cube
    glutSwapBuffers(); // Swap the front and back buffers to display the rendered image

}

void timer(int value) {
    angle += 0.2f; // Increment the rotation angle
    if (angle > 360) {
        angle -= 360; // Reset the angle if it exceeds 360 degrees
    }
    glutPostRedisplay(); // Request a redraw of the window
    glutTimerFunc(16, timer, 0); // Call the timer function again after 16 milliseconds (approx. 60 FPS)
}

void reshape(GLsizei width, GLsizei height) {

    if (height == 0) height = 1; // Prevent division by zero
    Glfloat aspect = (GLfloat)width / (GLfloat)height; // Calculate aspect ratio
    glViewport(0, 0, width, height); // Set the viewport to the new window dimensions


    glMatrixMode(GL_PROJECTION); // Switch to projection matrix mode
    glLoadIdentity(); // Load the identity matrix
    gluPerspective(45.0f, (float)w / (float)h, 0.1f, 100.0f); // Set up a perspective projection matrix

    glMatrixMode(GL_MODELVIEW); // Switch back to modelview matrix mode
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    
}