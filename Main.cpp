#include <GL/freeglut.h>

// Fungsi untuk menggambar persegi panjang
void drawRectangle(float x1, float y1, float x2, float y2) {
    glBegin(GL_QUADS);
    glVertex2f(x1, y1);
    glVertex2f(x2, y1);
    glVertex2f(x2, y2);
    glVertex2f(x1, y2);
    glEnd();
}

// Fungsi untuk menggambar trapesium sama kaki (atap)
void drawTrapezoid(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4) {
    glBegin(GL_POLYGON);
    glVertex2f(x1, y1);
    glVertex2f(x2, y1);
    glVertex2f(x3, y3);
    glVertex2f(x4, y3);
    glEnd();
}

// Fungsi untuk menampilkan teks
void drawText(const char* text, float x, float y) {
    glRasterPos2f(x, y);
    for (const char* c = text; *c != '\0'; ++c) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, *c);
    }
}

// Fungsi untuk menggambar bendera
void drawFlag() {
    // Tiang bendera
    glBegin(GL_LINES);
    glVertex2f(0.05f, 0.85f);
    glVertex2f(0.05f, 0.3f);
    glEnd();

    // Bendera merah putih
    glColor3f(1.0f, 0.0f, 0.0f); // Merah
    drawRectangle(0.05f, 0.85f, -0.05f, 0.8f);

    glColor3f(1.0f, 1.0f, 1.0f); // Putih
    drawRectangle(0.05f, 0.8f, -0.05f, 0.75f);

    // Menggambar alas bendera dengan rotasi dan skala
    glPushMatrix();
    glTranslatef(0.1f, 0.4f, 0.0f);
    glRotatef(90.0f, 0.9f, 0.0f, 1.0f); // Rotasi miring
    glScalef(1.5f, 0.2f, 1.0f);         // Membuat lebih lebar dan tipis
    glColor3f(1.0f, 1.0f, 0.8f);
    drawRectangle(-0.1f, -0.5f, -0.05f, 0.5f);
    glPopMatrix();
}

// Fungsi display untuk menggambar gedung dan elemen lainnya
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Menggambar gedung
    glColor3f(0.0f, 0.6f, 0.0f);
    glPushMatrix();
    glTranslatef(0.0f, 0.2f, 0.0f); // Translasi gedung
    drawRectangle(-0.6f, -0.4f, 0.6f, 0.4f);
    glPopMatrix();

    // Menggambar atap
    glColor3f(0.8f, 0.4f, 0.0f);
    glPushMatrix();
    glTranslatef(0.0f, 0.4f, 0.0f); // Translasi atap
    glScalef(1.2f, 0.5f, 1.0f); // Scaling atap
    drawTrapezoid(-0.6f, 0.4f, 0.6f, 0.4f, 0.3f, 0.7f, -0.3f, 0.6f);
    glPopMatrix();

    // Menggambar jendela
    glColor3f(0.0f, 0.0f, 0.0f);
    for (float y = -0.3f; y < 0.4f; y += 0.2f) {
        for (float x = -0.5f; x < 0.6f; x += 0.2f) {
            glPushMatrix();
            glTranslatef(-0.05f, 0.15f, 0.0f);
            drawRectangle(x, y, x + 0.1f, y + 0.1f);
            glPopMatrix();
        }
    }

    //Pintu
    glColor3f(1.0f, 1.0f, 0.8f);
    drawRectangle(0.2f, -0.01f, -0.2f, 0.4f); // Pintu
    glColor3f(0.0f, 0.6f, 0.0f);
    drawRectangle(0.17f, 0.04f, -0.17f, 0.36f); // Pintu hijau

    // Menggambar dua persegi tambahan di samping pintu
    glColor3f(1.0f, 1.0f, 0.8f);
    drawRectangle(-0.15f, -0.2f, -0.1f, 0.0f); // Persegi 1
    drawRectangle(0.1f, -0.2f, 0.15f, 0.0f);   // Persegi 2

    // Menambahkan bendera di samping gedung
    glPushMatrix();
    glTranslatef(0.0f, -0.6f, 0.0f); // Posisikan bendera
    drawFlag();
    glPopMatrix();

    // Menampilkan teks
    glColor3f(1.0f, 1.0f, 1.0f);
    drawText("FAKULTAS TEKNIK", -0.1f, 0.26f);
    drawText("Universitas Negeri Surabaya", -0.16f, 0.11f);

    glutSwapBuffers();
}

// Fungsi untuk inisialisasi tampilan
void init() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Gedung Fakultas Teknik UNESA");

    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}