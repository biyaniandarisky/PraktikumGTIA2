#include <windows.h>
#include <GL/glut.h>

// Variabel rotasi
GLfloat xRotated = 0.0f;
GLfloat yRotated = 0.0f;
GLfloat zRotated = 0.0f;

void Display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -4.0);
    glRotatef(xRotated, 1.0, 0.0, 0.0);
    glRotatef(yRotated, 0.0, 1.0, 0.0);
    glRotatef(zRotated, 0.0, 0.0, 1.0);
    glScalef(2.0, 1.0, 1.0);
    glutWireCube(1.0); // Gambar kubusnya
    glFlush();
    glutSwapBuffers();
}

void Reshape(int x, int y)
{
    if (y == 0 || x == 0) return;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(40.0, (GLdouble)x / (GLdouble)y, 0.5, 20.0);

    glMatrixMode(GL_MODELVIEW);
    glViewport(0, 0, x, y);
}

void Idle(void) // ngubah rotasinya
{
    xRotated += 0.3f;
    yRotated += 0.1f;
    zRotated -= 0.4f;

    Display(); 
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(300, 300);
    glutCreateWindow("Cube Example");
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glutDisplayFunc(Display);
    glutReshapeFunc(Reshape);
    glutIdleFunc(Idle);

    glutMainLoop();
    return 0;
}
