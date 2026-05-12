#include <windows.h>
#include <GL/glut.h>
#include <math.h>

// =====================================
// VARIABEL KAMERA
// =====================================

// sudut rotasi kamera
float angle = 0.0f;

// perubahan sudut kamera
float deltaAngle = 0.0f;

// posisi kamera
float x = 0.0f;
float y = 3.0f;
float z = 15.0f;

// arah pandangan kamera
float lx = 0.0f;
float lz = -1.0f;

// gerakan maju mundur
int deltaMove = 0;

// =====================================
// LIGHTING
// =====================================
const GLfloat light_ambient[] = {
    0.3f, 0.3f, 0.3f, 1.0f
};
const GLfloat light_diffuse[] = {
    1.0f, 1.0f, 1.0f, 1.0f
};
const GLfloat light_specular[] = {
    1.0f, 1.0f, 1.0f, 1.0f
};
const GLfloat light_position[] = {
    5.0f, 10.0f, 10.0f, 1.0f
};


// =====================================
// FUNGSI LIGHTING
// =====================================
void lighting() {
    // aktifkan depth test
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    // aktifkan lighting
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
}

// =====================================
// GRID LANTAI
// =====================================
void Grid() {

    // matikan lighting supaya garis jelas
    glDisable(GL_LIGHTING);

    glColor3f(0.5f, 0.5f, 0.5f);

    glBegin(GL_LINES);

    // looping garis grid
    for(float i = -20; i <= 20; i++) {

        glVertex3f(i, 0, -20);
        glVertex3f(i, 0, 20);

        glVertex3f(-20, 0, i);
        glVertex3f(20, 0, i);
    }

    glEnd();

    // nyalakan lighting lagi
    glEnable(GL_LIGHTING);
}


// =====================================
// FUNGSI KUBUS
// =====================================
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

// =====================================
// FUNGSI RODA
// =====================================
void Wheel() {

    // buat object quadric
    GLUquadric *quad = gluNewQuadric();
    glColor3f(0,0,0);

    // badan roda
    gluCylinder(quad,0.5,0.5,0.5,30,30);
    gluDisk(quad,0,0.5,30,1);
    glPushMatrix();
    glTranslatef(0,0,0.5);
    gluDisk( quad,0,0.5,30,1);
    glPopMatrix();
    gluDeleteQuadric(quad);
}

// =====================================
// FUNGSI MOBIL
// =====================================
void Car() {
    // =================================
    // BADAN & ATAS MOBIL 
    // =================================
    glPushMatrix();
        glColor3f(1,0,0);
        Cube(6, 1.5, 3);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0, 1.2, 0);
        glColor3f(0.8,0.1,0.1);
        Cube(3, 1.2, 2.5);
    glPopMatrix();

    // =================================
    // RODA DEPAN KIRI 
    // =================================
    glPushMatrix();
        glTranslatef(-2, -0.6, 1.5); 
        Wheel();
    glPopMatrix();

    // =================================
    // RODA DEPAN KANAN 
    // =================================
    glPushMatrix();
        glTranslatef(-2, -0.6, -1.5 - 0.5); 
        Wheel();
    glPopMatrix();

    // =================================
    // RODA BELAKANG KIRI
    // =================================
    glPushMatrix();
        glTranslatef(2, -0.6, 1.5);
        Wheel();
    glPopMatrix();

    // =================================
    // RODA BELAKANG KANAN
    // =================================
    glPushMatrix();
        glTranslatef(2, -0.6, -1.5 - 0.5);
        Wheel();
    glPopMatrix();
}
// =====================================
// FUNGSI ARAH KAMERA
// =====================================
void orientMe(float ang) {
    lx = sin(ang);
    lz = -cos(ang);
    glLoadIdentity();
    gluLookAt(
        x, y, z,
        x + lx, y, z + lz,
        0.0f, 1.0f, 0.0f);
}

// =====================================
// GERAK MAJU MUNDUR
// =====================================
void moveMeFlat(int i) {
    // update posisi kamera
    x = x + i * lx * 0.2f;
    z = z + i * lz * 0.2f;
    glLoadIdentity();
    gluLookAt(
        x, y, z,
        x + lx, y, z + lz,
        0.0f, 1.0f, 0.0f
    );
}

// =====================================
// DISPLAY
// =====================================
void display() {
    // gerak kamera
    if(deltaMove)
        moveMeFlat(deltaMove);
    // rotasi kamera
    if(deltaAngle) {
        angle += deltaAngle;
        orientMe(angle);
    }
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    Grid();
    glPushMatrix();
    glTranslatef(0, 1.0, 0);
    Car();
    glPopMatrix();
    glutSwapBuffers();
}


// =====================================
// KEYBOARD DITEKAN
// =====================================
void pressKey(int key, int xx, int yy) {
    switch(key) {
        // putar kiri
        case GLUT_KEY_LEFT :
            deltaAngle = -0.01f;
            break;
        // putar kanan
        case GLUT_KEY_RIGHT :
            deltaAngle = 0.01f;
            break;
        // maju
        case GLUT_KEY_UP :
            deltaMove = 1;
            break;
        // mundur
        case GLUT_KEY_DOWN :
            deltaMove = -1;
            break;
    }
}

// =====================================
// KEYBOARD DILEPAS
// =====================================
void releaseKey(int key, int x, int y) {
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

// =====================================
// RESHAPE WINDOW(menampilkan)
// =====================================
void Reshape(int w, int h) {
    if(h == 0)
        h = 1;
    float ratio = 1.0f * w / h;
    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();
    glViewport(0, 0, w, h);
    // perspektif kamera
    gluPerspective(45,ratio, 0.1,100);
    // kembali ke modelview
    glMatrixMode(GL_MODELVIEW);
    // posisi kamera awal
    gluLookAt(
        x, y, z,
        0,0,0,
        0,1,0
    );
}

// =====================================
// MAIN
// =====================================
int main(int argc, char** argv) {
    // init glut
    glutInit(&argc, argv);

    // mode display
    glutInitDisplayMode(
        GLUT_DEPTH |
        GLUT_DOUBLE |
        GLUT_RGBA
    );

    // posisi window
    glutInitWindowPosition(100,100);

    // ukuran window
    glutInitWindowSize(800,600);

    // buat window
    glutCreateWindow("Biyani Andarisky Maratia");

    // lighting
    lighting();

    // callback display
    glutDisplayFunc(display);

    // idle function
    glutIdleFunc(display);

    // reshape function
    glutReshapeFunc(Reshape);

    // keyboard function
    glutSpecialFunc(pressKey);

    // keyboard release
    glutSpecialUpFunc(releaseKey);

    // loop utama
    glutMainLoop();
    return 0;
}
