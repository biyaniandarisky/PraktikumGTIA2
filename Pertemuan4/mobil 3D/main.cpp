#include <windows.h>
#include <GL/glut.h>
#include <math.h>

// ======================
// Variabel Kamera
// ======================
float angle = 0.0f;
float deltaAngle = 0.0f;
float x = 0.0f, y = 3.0f, z = 15.0f; //posisi awal kamera
float lx = 0.0f, lz = -1.0f; //pov kamera
int deltaMove = 0;

// ======================
// LIGHTING
// ======================
const GLfloat light_ambient[]  = {0.3f, 0.3f, 0.3f, 1.0f};
const GLfloat light_diffuse[]  = {1.0f, 1.0f, 1.0f, 1.0f};
const GLfloat light_specular[] = {1.0f, 1.0f, 1.0f, 1.0f};
const GLfloat light_position[] = {5.0f, 10.0f, 10.0f, 1.0f};

// ======================
// Fungsi Lighting
// ======================
void lighting() {
    glEnable(GL_DEPTH_TEST); //depth
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0); //aktifin lighting
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);

    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient); //atur cahaya
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
}

// ======================
// Grid Lantai
// ======================
void Grid() {
    glColor3f(0.5, 0.5, 0.5);

    glBegin(GL_LINES);

    for (float i = -20; i <= 20; i++) {
        glVertex3f(i, 0, -20);
        glVertex3f(i, 0, 20);

        glVertex3f(-20, 0, i);
        glVertex3f(20, 0, i);
    }

    glEnd();
}

// ======================
// Kubus
// ======================
void Cube(float panjang, float tinggi, float lebar) {

    float p = panjang / 2;
    float t = tinggi / 2;
    float l = lebar / 2;

    glBegin(GL_QUADS);

    // DEPAN
    glNormal3f(0,0,1);
    glVertex3f(-p,-t,l);
    glVertex3f(p,-t,l);
    glVertex3f(p,t,l);
    glVertex3f(-p,t,l);

    // BELAKANG
    glNormal3f(0,0,-1);
    glVertex3f(-p,-t,-l);
    glVertex3f(-p,t,-l);
    glVertex3f(p,t,-l);
    glVertex3f(p,-t,-l);

    // ATAS
    glNormal3f(0,1,0);
    glVertex3f(-p,t,-l);
    glVertex3f(-p,t,l);
    glVertex3f(p,t,l);
    glVertex3f(p,t,-l);

    // BAWAH
    glNormal3f(0,-1,0);
    glVertex3f(-p,-t,-l);
    glVertex3f(p,-t,-l);
    glVertex3f(p,-t,l);
    glVertex3f(-p,-t,l);

    // KANAN
    glNormal3f(1,0,0);
    glVertex3f(p,-t,-l);
    glVertex3f(p,t,-l);
    glVertex3f(p,t,l);
    glVertex3f(p,-t,l);

    // KIRI
    glNormal3f(-1,0,0);
    glVertex3f(-p,-t,-l);
    glVertex3f(-p,-t,l);
    glVertex3f(-p,t,l);
    glVertex3f(-p,t,-l);

    glEnd();
}

// ======================
// Roda
// ======================
void Wheel() {
    glutSolidTorus(0.2, 0.5, 20, 20);
}

// ======================
// Mobil 3D
// ======================
void Car() {

    // BADAN MOBIL
    glPushMatrix();
    glColor3f(1, 0, 0);
    Cube(6, 1.5, 3);
    glPopMatrix();

    // ATAS MOBIL
    glPushMatrix();
    glTranslatef(0, 1.2, 0);
    glColor3f(0.8, 0.1, 0.1);
    Cube(3, 1.2, 2.5);
    glPopMatrix();

    // RODA DEPAN KIRI
    glPushMatrix();
    glTranslatef(-2, -1, 1.7);
    glRotatef(90, 0, 1, 0);
    glColor3f(0,0,0);
    Wheel();
    glPopMatrix();

    // RODA DEPAN KANAN
    glPushMatrix();
    glTranslatef(-2, -1, -1.7);
    glRotatef(90, 0, 1, 0);
    Wheel();
    glPopMatrix();

    // RODA BELAKANG KIRI
    glPushMatrix();
    glTranslatef(2, -1, 1.7);
    glRotatef(90, 0, 1, 0);
    Wheel();
    glPopMatrix();

    // RODA BELAKANG KANAN
    glPushMatrix();
    glTranslatef(2, -1, -1.7);
    glRotatef(90, 0, 1, 0);
    Wheel();
    glPopMatrix();
}

// ======================
// Kamera
// ======================
void orientMe(float ang) {

    lx = sin(ang);
    lz = -cos(ang);

    glLoadIdentity();

    gluLookAt(
        x, y, z,
        x + lx, y, z + lz,
        0.0f, 1.0f, 0.0f
    );
}

void moveMeFlat(int i) { //gerakin kamera maju mundur

    x = x + i * (lx) * 0.2f;
    z = z + i * (lz) * 0.2f;

    glLoadIdentity();

    gluLookAt(
        x, y, z, //posisi kamera
        x + lx, y, z + lz, //titik yg dilihat
        0.0f, 1.0f, 0.0f //arah atas kamera
    );
}

// ======================
// Display
// ======================
void display() {

    if(deltaMove)
        moveMeFlat(deltaMove);

    if(deltaAngle) {
        angle += deltaAngle;
        orientMe(angle);
    }

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    Grid();

    glPushMatrix();
    glTranslatef(0, 2, 0);
    Car();
    glPopMatrix();

    glutSwapBuffers();
}

// ======================
// Keyboard
// ======================
void pressKey(int key, int xx, int yy) {

    switch(key) {

        case GLUT_KEY_LEFT :
            deltaAngle = -0.01f;
            break;

        case GLUT_KEY_RIGHT :
            deltaAngle = 0.01f;
            break;

        case GLUT_KEY_UP :
            deltaMove = 1;
            break;

        case GLUT_KEY_DOWN :
            deltaMove = -1;
            break;
    }
}

void releaseKey(int key, int x, int y) { //tombol dilepas, kamera berenti

    switch(key) {

        case GLUT_KEY_LEFT :
        case GLUT_KEY_RIGHT :
            deltaAngle = 0.0f;
            break;

        case GLUT_KEY_UP :
        case GLUT_KEY_DOWN :
            deltaMove = 0;
            break;
    }
}

// ======================
// Reshape
// ======================
void Reshape(int w, int h) {
    if(h == 0)
        h = 1;

    float ratio = 1.0f * w / h;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glViewport(0, 0, w, h);

    gluPerspective(45, ratio, 0.1, 100);

    glMatrixMode(GL_MODELVIEW);

    gluLookAt(
        x, y, z,
        0,0,0,
        0,1,0
    );
}

// ======================
// Main
// ======================
int main(int argc, char** argv) {

    glutInit(&argc, argv);

    glutInitDisplayMode(
        GLUT_DEPTH |
        GLUT_DOUBLE |
        GLUT_RGBA
    );

    glutInitWindowPosition(100,100);
    glutInitWindowSize(800,600);

    glutCreateWindow("Biyani Andarisky Maratia");

    lighting();

    glutDisplayFunc(display);
    glutIdleFunc(display);

    glutReshapeFunc(Reshape);

    glutSpecialFunc(pressKey);
    glutSpecialUpFunc(releaseKey);

    glutMainLoop();

    return 0;
}
