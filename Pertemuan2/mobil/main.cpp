#include <windows.h>
#include <gl/glut.h>
#include <gl/gl.h>
#include <math.h>

#define PI 3.1415926535898

void drawCircle(float r)
{
    int i;
    int circle_points = 100;
    float angle;

    glBegin(GL_POLYGON);
    for(i=0;i<circle_points;i++)
    {
        angle = 2 * PI * i / circle_points;
        glVertex2f(r*cos(angle), r*sin(angle));
    }
    glEnd();
}

void RenderScene(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    // ======================
    // BADAN MOBIL 
    // ======================
    glPushMatrix();
	glTranslatef(0.0f,-0.1f,0.0f);

	glColor3f(1,0.016,0.424);
	glBegin(GL_QUADS);
    	glVertex2f(-0.45f,0.0f);
    	glVertex2f(0.45f,0.0f);
    	glVertex2f(0.45f,0.2f);
    	glVertex2f(-0.45f,0.2f);
	glEnd();
	glPopMatrix();
	
	glPushMatrix();
    glTranslatef(0.0f, 0.1f, 0.0f);

    glColor3f(1,0.016,0.424);
    glBegin(GL_POLYGON);
        glVertex2f(-0.2f,0.0f);
        glVertex2f(0.2f,0.0f);
        glVertex2f(0.1f,0.15f);
        glVertex2f(-0.1f,0.15f);
    glEnd();
    glPopMatrix();

    // ======================
    // JENDELA 
    // ======================
    glPushMatrix();
    glTranslatef(-0.07f,0.09f,0.0f);

    glColor3f(0.5,0.8,1);
    glBegin(GL_QUADS);
        glVertex2f(-0.05f, 0.05f); 
    	glVertex2f( 0.05f, 0.05f);
    	glVertex2f( 0.05f,-0.05f); 
    	glVertex2f(-0.05f,-0.05f); 
    glEnd();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0.07f,0.09f,0.0f);

    glColor3f(0.5,0.8,1);
    glBegin(GL_QUADS);
        glVertex2f(-0.05f, 0.05f); 
    	glVertex2f( 0.05f, 0.05f);
    	glVertex2f( 0.05f,-0.05f); 
    	glVertex2f(-0.05f,-0.05f); 
    glEnd();
    glPopMatrix();

    // ======================
    // RODA 
    // ======================
    glPushMatrix();
    glTranslatef(-0.3f,-0.1f,0.0f);

    glColor3f(0,0,0);
    drawCircle(0.1f);
    glPopMatrix();

    glTranslatef(0.3f,-0.1f,0.0f);
    drawCircle(0.1f);

    glPopMatrix();
    
    // ======================
	// LAMPU DEPAN
	// ======================
	glPushMatrix();
	glTranslatef(0.15f, 0.09f, 0.0f); 

	glColor3f(1.0f, 1.0f, 0.0f); 
	glBegin(GL_QUADS);
    	glVertex2f(-0.02f, 0.02f);
    	glVertex2f( 0.02f, 0.02f);
    	glVertex2f( 0.02f,-0.02f);
    	glVertex2f(-0.02f,-0.02f);
	glEnd();

	glPopMatrix();
	
	glFlush();
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutCreateWindow("Biyani Andarisky Maratia");

    glutDisplayFunc(RenderScene);

    glClearColor(0.5f,0.8f,1.0f,1.0f);

    glutMainLoop();
}
