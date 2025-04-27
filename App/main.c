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
        glVertex3f(-1.0f, -1.0f, -1.0f); // Bottom-left
        glVertex3f(1.0f, -1.0f, -1.0f); // Bottom-right
        glVertex3f(1.0f, 1.0f, -1.0f); // Top-right
        glVertex3f(-1.0f, 1.0f, -1.0f); // Top-left
}