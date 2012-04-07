#include "GL/freeglut.h"
#include "GL/gl.h"

void Draw() {
    glClear(GL_COLOR_BUFFER_BIT);

    glEnable(GL_CULL_FACE);
    //glFrontFace(GL_CW);
    //glCullFace(GL_BACK);
    glCullFace(GL_FRONT);
    
    glColor3f(0.9, 0.9, 0.9);
    
    glBegin(GL_TRIANGLES);
    glVertex2f(-200.0, 200.0);
    glVertex2f(-200.0, -200.0);
    glVertex2f(0.0, 200.0);
    
    glVertex2f(200.0, -200.0);
    glVertex2f(0.0, -200.0);
    glVertex2f(200.0, 200.0);
    
    glEnd();
    glRotatef(1, 0.0, 1.0, 0.0);
    glutSwapBuffers();
}

void Timer(int) {
    Draw();
    glutTimerFunc(10, Timer, 0);
}

void Initsialaize() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-200.0, 200.0, -200.0, 200.0, -200.0, 200.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(100, 200);
    glutCreateWindow("Lesson 13");
    
    glutDisplayFunc(Draw);
    glutTimerFunc(10, Timer, 0);
    Initsialaize();
    glutMainLoop();
    
    return 0;
}