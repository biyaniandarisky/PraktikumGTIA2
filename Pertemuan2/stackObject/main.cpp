#include <windows.h>
#include <gl/glut.h>
#include <gl/gl.h>
#include <math.h>

#define PI 3.1415926535898

void drawCircle(float x, float y, float r)
{
    int i;
    int triangleAmount = 100;
    float angle;

    glBegin(GL_POLYGON);
    for(i = 0; i < triangleAmount; i++)
    {
        angle = 2 * PI * i / triangleAmount;
        glVertex2f(x + r*cos(angle), y + r*sin(angle));
    }
    glEnd();
}

void RenderScene(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    // ======================
    // BADAN MOBIL (TRAPESIUM)
    // ======================
    glPushMatrix();
    glColor3f(1.0f, 0.0f, 0.0f);

    glBegin(GL_POLYGON);
        glVertex2f(-0.6f, -0.1f);
        glVertex2f(0.6f, -0.1f);
        glVertex2f(0.4f, 0.2f);
        glVertex2f(-0.4f, 0.2f);
    glEnd();

    glPopMatrix();


    // ======================
    // JENDELA (KOTAK)
    // ======================
    glPushMatrix();
    glColor3f(0.5f, 0.8f, 1.0f);

    glBegin(GL_QUADS);
        glVertex2f(-0.20f, 0.05f);
        glVertex2f(0.20f, 0.05f);
        glVertex2f(0.20f, 0.15f);
        glVertex2f(-0.20f, 0.15f);
    glEnd();

    glPopMatrix();


    // ======================
    // RODA KIRI
    // ======================
    glColor3f(0.0f,0.0f,0.0f);
    drawCircle(-0.35f,-0.1f,0.1f);


    // ======================
    // RODA KANAN
    // ======================
    drawCircle(0.35f,-0.1f,0.1f);

    glFlush();
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutCreateWindow("Mobil OpenGL");

    glutDisplayFunc(RenderScene);

    glClearColor(0.1f,0.1f,1.0f,1.0f);

    glutMainLoop();
    return 0;
}
