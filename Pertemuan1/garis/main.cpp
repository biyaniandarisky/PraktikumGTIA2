#include <GL/glut.h>

void GarisStrip(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0f, 0.0f, 0.0f);

    glBegin(GL_LINE_STRIP);
        glVertex2f(-0.20f, -0.10f);
        glVertex2f(-0.10f,  0.10f);
        glVertex2f( 0.00f, -0.10f);
        glVertex2f( 0.10f,  0.10f);
        glVertex2f( 0.20f, -0.10f);
    glEnd();

    glFlush();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 400);
    glutCreateWindow("Biyani Andarisky Maratia");

    glutDisplayFunc(GarisStrip);

    glClearColor(0.0f, 0.0f, 1.0f, 1.0f);

    glutMainLoop();
}
