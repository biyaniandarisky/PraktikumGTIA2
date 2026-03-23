#include <windows.h>
#include <GL/glut.h>

void kotak(float x, float y){
    glColor3f(0,0,1);
    glBegin(GL_QUADS);
        glVertex2f(x, y);
        glVertex2f(x+1, y);
        glVertex2f(x+1, y+1);
        glVertex2f(x, y+1);
    glEnd();
    glColor3f(1,1,1);
    glBegin(GL_LINE_LOOP);
        glVertex2f(x, y);
        glVertex2f(x+1, y);
        glVertex2f(x+1, y+1);
        glVertex2f(x, y+1);
    glEnd();
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.3,0.6,0.9);
    kotak(-3,-2);
    kotak(-2,-2);
    kotak(-1,-2);
    kotak(-2,-1);
    kotak(-1,-1);
    kotak(-1,0);
    glFlush();
}

void init(){
    glClearColor(1,1,1,1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-5,5,-5,5); 
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600,400);
    glutCreateWindow("Biyani Andarisky Maratia");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
}
