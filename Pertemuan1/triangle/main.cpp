#include <windows.h>
#include <GL/glut.h>

void display(){
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1,1,1);

    glBegin(GL_TRIANGLE_STRIP);

        glVertex2f(-0.8,-0.2); 
        glVertex2f(-0.6,0.2);  
        glVertex2f(-0.4,-0.2); 
        glVertex2f(-0.2,0.2); 
        glVertex2f(0.0,-0.2); 
        glVertex2f(0.2,0.2);   
        glVertex2f(0.4,-0.2);  
        glVertex2f(0.6,0.2);   
        glVertex2f(0.8,-0.2);  

    glEnd();

    glFlush();
}

void init(){
    glClearColor(0.0,0.0,1.0,1.0);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); 
}

int main(int argc,char** argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600,400);
    glutCreateWindow("Biyani Andarisky Maratia");

    init();
    glutDisplayFunc(display);
    glutMainLoop();
}
