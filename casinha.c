#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>

int largura=500, altura=500;
void Casinha(void);
float a[3]={4.0,4,4};

void desenha_paralelepipedo(float Cx, float Cy, float Cz, float L, float h, int r, int g, int b){
    float half_L = L/2;
    glBegin(GL_POLYGON);

    glColor3ub(r, g, b);
    glVertex3f(Cx-half_L, Cy, Cz+(half_L)); // A
    glVertex3f(Cx-half_L, Cy, Cz+(-half_L)); // B
    glVertex3f(Cx+half_L, Cy, Cz+(-half_L)); // C
    glVertex3f(Cx+half_L, Cy, Cz+(half_L)); // D
    
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(r, g, b);
    glVertex3f(Cx-half_L, Cy-h, Cz+(half_L)); // AZ
    glVertex3f(Cx-half_L, Cy-h, Cz+(-half_L)); // BZ
    glVertex3f(Cx+half_L, Cy-h, Cz+(-half_L)); // CZ
    glVertex3f(Cx+half_L, Cy-h, Cz+(half_L)); // DZ
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(r, g, b);
    glVertex3f(Cx-half_L, Cy, Cz+(half_L)); // A
    glVertex3f(Cx-half_L, Cy, Cz+(-half_L)); // B
    glVertex3f(Cx-half_L, Cy-h, Cz+(-half_L)); // BZ
    glVertex3f(Cx-half_L, Cy-h, Cz+(half_L)); // AZ    
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(r, g, b);
    glVertex3f(Cx+half_L, Cy, Cz+(half_L)); // D
    glVertex3f(Cx+half_L, Cy, Cz+(-half_L)); // C
    glVertex3f(Cx+half_L, Cy-h, Cz+(-half_L)); // CZ
    glVertex3f(Cx+half_L, Cy-h, Cz+(half_L)); // DZ
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(r, g, b);
    glVertex3f(Cx-half_L, Cy, Cz+(half_L)); // A
    glVertex3f(Cx+half_L, Cy, Cz+(half_L)); // D
    glVertex3f(Cx+half_L, Cy-h, Cz+(half_L)); // DZ
    glVertex3f(Cx-half_L, Cy-h, Cz+(half_L)); // AZ
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(r, g, b);
    glVertex3f(Cx-half_L, Cy, Cz+(-half_L)); // B
    glVertex3f(Cx+half_L, Cy, Cz+(-half_L)); // C
    glVertex3f(Cx+half_L, Cy-h, Cz+(-half_L)); // CZ
    glVertex3f(Cx-half_L, Cy-h, Cz+(-half_L)); // BZ
    glEnd();
}

void arco_ponte(int h, int r, int g, int b){
    // Arco feito com vários triângulos
    glBegin(GL_TRIANGLES);
    glColor3ub(r, g, b);
    glVertex3f(-2.5f, 0.0f, 0.0f+h); // H
    glVertex3f(-1.68f, -0.7f, 0.0f+h);
    glVertex3f(-2.5f, -0.99f, 0.0f+h); 
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(r, g, b);
    glVertex3f(-2.5f, 0.0f, 0.0f+h); // H
    glVertex3f(-1.0f, 0.0f, 0.0f+h);
    glVertex3f(-1.68f, -0.7f, 0.0f+h);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(r, g, b);
    glVertex3f(-1.0f, 0.0f, 0.0f+h);
    glVertex3f(-1.68f, -0.7f, 0.0f+h);
    glVertex3f(-0.86f, -0.53f, 0.0f+h);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(r, g, b);
    glVertex3f(-1.0f, 0.0f, 0.0f+h);
    glVertex3f(-0.86f, -0.53f, 0.0f+h);
    glVertex3f(0.0, 0.0f, 0.0f+h); // J
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(r, g, b);
    glVertex3f(-1.0f, 0.0f, 0.0f+h);
    glVertex3f(-0.86f, -0.53f, 0.0f+h); // 0
    glVertex3f(0.0, 0.0f, 0.0f+h); // J
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(r, g, b);
    glVertex3f(0.0, 0.0f, 0.0f+h); // J
    glVertex3f(-0.86f, -0.53f, 0.0f+h); // 0
    glVertex3f(-0.27f, -0.46f, 0.0f+h); // I
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(r, g, b);
    glVertex3f(0.0, 0.0f, 0.0f+h); // J
    glVertex3f(-0.27f, -0.46f, 0.0f+h); // I
    glVertex3f(1.0f, 0.0f, 0.0f+h); // M
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(r, g, b);
    glVertex3f(1.0f, 0.0f, 0.0f+h); // M
    glVertex3f(-0.27f, -0.46f, 0.0f+h); // I
    glVertex3f(0.44f, -0.48f, 0.0f+h); // K
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(r, g, b);
    glVertex3f(1.0f, 0.0f, 0.0f+h); // M
    glVertex3f(0.44f, -0.48f, 0.0f+h); // K
    glVertex3f(-1.2f, -0.56f, 0.0f+h); // P
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(r, g, b);
    glVertex3f(1.0f, 0.0f, 0.0f+h); // M
    glVertex3f(-1.2f, -0.56f, 0.0f+h); // P
    glVertex3f(1.99f, -0.82f, 0.0f+h); // Q
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(r, g, b);
    glVertex3f(1.0f, 0.0f, 0.0f+h); // M
    glVertex3f(2.5f, 0.0f, 0.0f+h); // G
    glVertex3f(1.99f, -0.82f, 0.0f+h); // Q
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(r, g, b);
    glVertex3f(2.5f, 0.0f, 0.0f+h); // G-
    glVertex3f(1.99f, -0.82f, 0.0f+h); // Q
    glVertex3f(2.5f, -1.0f, 0.0f+h); // N
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(r, g, b);
    glVertex3f(-2.5f, 0.0f, 0.0f); // H
    glVertex3f(2.5f, 0.0f, 0.0f); // G
    glVertex3f(2.5f, 0.0f, 0.0f+h); // GZ
    glVertex3f(-2.5f, 0.0f, 0.0f+h); // HZ
    glEnd();

}
void Casinha(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
   // glClear(GL_COLOR_BUFFER_BIT);
    Iniciar();
    glEnable(GL_DEPTH_TEST);
    glBegin( GL_LINES ); //Eixos cartesianos
    glColor3f(0.0f,0.0f,1.0f);
    glVertex3f(0.0f,0.0f,0.0f);
    glVertex3f(0.7f,0.0f,0.0f); // x azul
    glColor3f(1.0f,0.0f,0.0f);
    glVertex3f(0.0f,0.0f,0.0f);
    glVertex3f(0.0f,0.7f,0.0f); //y vermeho
    glColor3f(0.0f,1.0f,0.0f);
    glVertex3f(0.0f,0.0f,0.0f);
    glVertex3f(0.0f,0.0f,0.7f); // z verde
  glEnd();
  glBegin(GL_POLYGON);
    glColor3ub(189, 189, 189); //Cor de concreto, Torre de cima
    glVertex3f(-0.5f, 16.0f, 0.0f); // A
    glVertex3f(0.5f, 16.0f, 0.0f); // B
    glVertex3f(0.8f, 8.5f, 0.0f); // D
    glVertex3f(-0.8f, 8.5f, 0.0f); // C

  glEnd();
  glBegin(GL_POLYGON);
    glColor3ub(189, 189, 189); //Cor de concreto, Trapezio pras pernas
    glVertex3f(-0.8f, 8.5f, 0.0f); // C
    glVertex3f(0.8f, 8.5f, 0.0f); // D
    glVertex3f(0.3f, 7.5f, 0.0f); // F
    glVertex3f(-0.3f, 7.5f, 0.0f); // E
  glEnd();
glBegin(GL_POLYGON);
    glColor3ub(189, 189, 189); //Perna esquerda
    glVertex3f(-0.8f, 8.5f, 0.0f); // C
    glVertex3f(-0.3f, 7.5f, 0.0f); // E
    glVertex3f(-2.5f, 0.0f, 0.0f); // H
    glVertex3f(-3.5f, 0.0f, 0.0f); // I1
  glEnd();
  glBegin(GL_POLYGON);
    glColor3ub(189, 189, 189); //Perna direita
    glVertex3f(0.8f, 8.5f, 0.0f); // D
    glVertex3f(0.3f, 7.5f, 0.0f); // F
    glVertex3f(2.5f, 0.0f, 0.0f); // G
    glVertex3f(3.5f, 0.0f, 0.0f); // J
  glEnd();
  glBegin(GL_POLYGON);
    glColor3ub(189, 189, 189); //Base direita
    glVertex3f(3.5f, 0.0f, 0.0f); // J
    glVertex3f(3.5f, -2.0f, 0.0f); // R1
    glVertex3f(2.5f, -2.0f, 0.0f); // L1
    glVertex3f(2.5f, 0.0f, 0.0f); // G
  glEnd();
  glBegin(GL_POLYGON);
    glColor3ub(189, 189, 189); //Base esquerda
    glVertex3f(-2.5f, 0.0f, 0.0f); // H
    glVertex3f(-2.5f, -2.0f, 0.0f); // R
    glVertex3f(-3.5f, -2.0f, 0.0f); // L
    glVertex3f(-3.5f, 0.0f, 0.0f); // I1
  glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(189, 189, 189); //Base direita XZ TOP
    glVertex3f(3.5f, 0.0f, 0.0f); // J
    glVertex3f(3.5f, 0.0f, 1.0f); // JZ
    glVertex3f(2.5f, 0.0f, 1.0f); // GZ
    glVertex3f(2.5f, 0.0f, 0.0f); // G
  glEnd();
  glBegin(GL_POLYGON);
    glColor3ub(189, 189, 189); //Base esquerda XZ TOP
    glVertex3f(-2.5f, 0.0f, 0.0f); // H
    glVertex3f(-2.5f, 0.0f, 1.0f); // HZ
    glVertex3f(-3.5f, 0.0f, 1.0f); // I1Z
    glVertex3f(-3.5f, 0.0f, 0.0f); // I1
  glEnd();
  glBegin(GL_POLYGON);
    glColor3ub(189, 189, 189); //Base direita XZ BOT
    glVertex3f(3.5f, -2.0f, 0.0f); // R1
    glVertex3f(2.5f, -2.0f, 0.0f); // L1
    glVertex3f(2.5f, -2.0f, 1.0f); // L1Z
    glVertex3f(3.5f, -2.0f, 1.0f); // R1Z
  glEnd();
  glBegin(GL_POLYGON);
    glColor3ub(189, 189, 189); //Base esquerda XZ BOT
    glVertex3f(-2.5f, -2.0f, 0.0f); // R
    glVertex3f(-3.5f, -2.0f, 0.0f); // L
    glVertex3f(-3.5f, -2.0f, 1.0f); // LZ
    glVertex3f(-2.5f, -2.0f, 1.0f); // RZ
  glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(189, 189, 189); //Cor de concreto, Torre de cima
    glVertex3f(-0.5f, 16.0f, 1.0f); // AZ
    glVertex3f(0.5f, 16.0f,1.0f); // BZ
    glVertex3f(0.8f, 8.5f, 1.0f); // DZ
    glVertex3f(-0.8f, 8.5f,1.0f); // CZ

  glEnd();
  glBegin(GL_POLYGON);
    glColor3ub(189, 189, 189); //Cor de concreto, Trapezio pras pernas
    glVertex3f(-0.8f, 8.5f,1.0f); // CZ
    glVertex3f(0.8f, 8.5f, 1.0f); // DZ
    glVertex3f(0.3f, 7.5f, 1.0f); // FZ
    glVertex3f(-0.3f, 7.5f,1.0f); // EZ
  glEnd();
glBegin(GL_POLYGON);
    glColor3ub(189, 189, 189); //Perna esquerda
    glVertex3f(-0.8f, 8.5f,1.0f); // CZ
    glVertex3f(-0.3f, 7.5f,1.0f); // EZ
    glVertex3f(-2.5f, 0.0f,1.0f); // HZ
    glVertex3f(-3.5f, 0.0f,1.0f); // I1Z
  glEnd();
  glBegin(GL_POLYGON);
    glColor3ub(189, 189, 189); //Perna direita
    glVertex3f(0.8f, 8.5f, 1.0f); // DZ
    glVertex3f(0.3f, 7.5f, 1.0f); // FZ
    glVertex3f(2.5f, 0.0f, 1.0f); // GZ
    glVertex3f(3.5f, 0.0f, 1.0f); // JZ
  glEnd();
  glBegin(GL_POLYGON);
    glColor3ub(189, 189, 189); //Base direita
    glVertex3f(3.5f, 0.0f, 1.0f); // JZ
    glVertex3f(3.5f, -2.0f,1.0f); // R1Z
    glVertex3f(2.5f, -2.0f,1.0f); // L1Z
    glVertex3f(2.5f, 0.0f, 1.0f); // GZ
  glEnd();
  glBegin(GL_POLYGON);
    glColor3ub(189, 189, 189); //Base esquerda
    glVertex3f(-2.5f, 0.0f,1.0f); // HZ
    glVertex3f(-2.5f, -2.0, 1.0f); // RZ
    glVertex3f(-3.5f, -2.0, 1.0f); // LZ
    glVertex3f(-3.5f, 0.0f,1.0f); // I1Z
  glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(189, 189, 189); //Parede direita da torre
    glVertex3f(3.5f, 0.0f, 1.0f); // JZ
    glVertex3f(3.5f, 0.0f, 0.0f); // J
    glVertex3f(0.8f, 8.5f, 0.0f); // D
    glVertex3f(0.8f, 8.5f, 1.0f); // DZ
  glEnd();
glBegin(GL_POLYGON);
    glColor3ub(189, 189, 189); //Parede esquerda da torre
    glVertex3f(-3.5f, 0.0f, 0.0f); // I1
    glVertex3f(-0.8f, 8.5f, 0.0f); // C
    glVertex3f(-0.8f, 8.5f, 1.0f); // CZ
    glVertex3f(-3.5f, 0.0f, 1.0f); // I1Z
  glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(189, 189, 189); //Base direita Z
    glVertex3f(3.5f, 0.0f, 1.0f); // JZ
    glVertex3f(3.5f, -2.0f,1.0f); // R1Z
    glVertex3f(2.5f, -2.0f,0.0f); // R
    glVertex3f(2.5f, 0.0f, 0.0f); // J
  glEnd();
  glBegin(GL_POLYGON);
    glColor3ub(189, 189, 189); //Base esquerda Z
    glVertex3f(-2.5f, 0.0f,1.0f); // HZ
    glVertex3f(-2.5f, -2.0, 1.0f); // RZ
    glVertex3f(-3.5f, -2.0, 0.0f); // R
    glVertex3f(-2.5f, 0.0f, 0.0f); // H
  glEnd();
  glBegin(GL_POLYGON);
    glColor3ub(189, 189, 189); // Topo
    glVertex3f(-0.5f, 16.0f, 0.0f); // A
    glVertex3f(0.5f, 16.0f, 0.0f); // B
    glVertex3f(0.5f, 16.0f, 1.0f); // BZ
    glVertex3f(-0.5f, 16.0f, 1.0f); // AZ
  glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(189, 189, 189); // Torre parede do lado
    glVertex3f(0.5f, 16.0f, 0.0f); // B
    glVertex3f(0.8f, 8.5f, 0.0f); // D
    glVertex3f(0.8f, 8.5f, 1.0f); // DZ
    glVertex3f(0.5f, 16.0f, 1.0f); // BZ
  glEnd();
  glBegin(GL_POLYGON);
    glColor3ub(189, 189, 189); // Torre parede do outro lado
    glVertex3f(-0.5f, 16.0f, 0.0f); // A
    glVertex3f(-0.8f, 8.5f, 0.0f); // C
    glVertex3f(-0.5f, 16.0f, 1.0f); // CZ
    glVertex3f(-0.8f, 8.5f, 1.0f); // AZ
  glEnd();
  glBegin(GL_POLYGON);
    glColor3ub(109, 113, 117); // Embaixo do trapézio
    glVertex3f(-0.3f, 7.5f, 0.0f); // E
    glVertex3f(0.3f, 7.5f, 0.0f); // F
    glVertex3f(0.3f, 7.5f, 1.0f); // FZ
    glVertex3f(-0.3f, 7.5f, 1.0f); // EZ
  glEnd();
  glBegin(GL_LINES);
    glColor3ub(255, 255, 255); // Traço pista
    for (float i = -100; i < 100; i++){
        glVertex3f(0.0f, -(pow(i, 2)/1000), i);
    }
  glEnd();

  glBegin(GL_LINE_STRIP);
    glColor3ub(255, 255, 255); // Traço pista
    for (float i =-100; i < 100; i++){
        glVertex3f(-3.5f, -(pow(i, 2)/1000), i);
    }
  glEnd();

  glBegin(GL_LINE_STRIP);
    glColor3ub(255, 255, 255); // Traço pista
    for (float i =-100; i < 100; i++){
        glVertex3f(3.5f, -(pow(i, 2)/1000), i);
    }
  glEnd();

    glBegin(GL_LINE_STRIP);
    glColor3ub(255, 255, 255); // Traço pista
    for (float i =-100; i < 100; i++){
        glVertex3f(-3.5f, -(pow(i, 2)/1000)+0.5, i);
    }
  glEnd();

  glBegin(GL_LINE_STRIP);
    glColor3ub(255, 255, 255); // Traço pista
    for (float i =-100; i < 100; i++){
        glVertex3f(3.5f, -(pow(i, 2)/1000)+0.5, i);
    }
  glEnd();



  glBegin(GL_TRIANGLE_STRIP_ADJACENCY);
    glColor3ub(227, 225, 98); // Traço pista
    for (float i =-100; i < 100; i++){
        glVertex3f(3.5f, -(pow(i, 2)/1000)+0.5, i);
        glVertex3f(3.5f, -(pow(i, 2)/1000), i);
        glVertex3f(3.5f, -(pow(i+1, 2)/1000)+0.5, i+1);


    }
  glEnd();

    glBegin(GL_TRIANGLE_STRIP_ADJACENCY);
    glColor3ub(227, 225, 98); // Traço pista
    for (float i =-100; i < 100; i++){
        glVertex3f(-3.5f, -(pow(i, 2)/1000)+0.5, i);
        glVertex3f(-3.5f, -(pow(i, 2)/1000), i);
        glVertex3f(-3.5f, -(pow(i+1, 2)/1000)+0.5, i+1);


    }
  glEnd();

      glBegin(GL_TRIANGLES);
    glColor3ub(28, 28, 23); // Traço pista
    for (float i =-100; i < 100; i++){
        glVertex3f(-3.5f, -(pow(i, 2)/1000), i);
        glVertex3f(+3.5f, -(pow(i, 2)/1000), i);
        glVertex3f(-3.5f, -(pow(i+1, 2)/1000), i+1);
    }
  glEnd();

        glBegin(GL_TRIANGLES);
    glColor3ub(28, 28, 23); // Traço pista
    for (float i =-100; i < 100; i++){
        glVertex3f(+3.5f, -(pow(i-1, 2)/1000), i-1);
        glVertex3f(-3.5f, -(pow(i-1, 2)/1000), i-1);
        glVertex3f(-3.5f, -(pow(i+1, 2)/1000), i+1);
    }
  glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(28, 28, 23); // Traço pista
    for (float i =-100; i < 100; i++){
        glVertex3f(+3.5f, -(pow(i-1, 2)/1000), i-1);
        glVertex3f(-3.5f, -(pow(i-1, 2)/1000), i-1);
        glVertex3f(+3.5f, -(pow(i+1, 2)/1000), i+1);
    }
  glEnd();



  glBegin(GL_LINES);
    glColor3ub(0, 0, 0); // Cabos de aço direita
    for (float i =0; i < 23; i++){ // 23 linhas
        glVertex3f(0.0f, (8.5 + (i/23 * 6.5)), 1);
        glVertex3f(0.0f, -(pow(i, 2)/1000), 32*(i/23));
    }
  glEnd();
  glBegin(GL_LINES);
    glColor3ub(0, 0, 0); // Cabos de aço esquerda
    for (float i =0; i < 23; i++){ // 23 linhas
        glVertex3f(0.0f, (8.5 + (i/23 * 6.5)), 0);
        glVertex3f(0.0f, -(pow(i, 2)/1000), -32*(i/23));
    }
  glEnd();
  desenha_paralelepipedo(3, -2, 0.5, 2, 0.5, 155, 155, 143);
  desenha_paralelepipedo(-3, -2, 0.5, 2, 0.5, 155, 155, 143);
  desenha_paralelepipedo(3, -2.5, 0.5, 3, 0.5, 104, 104, 97);
  desenha_paralelepipedo(-3, -2.5, 0.5, 3, 0.5, 104, 104, 97); // Bases das pernas da ponte
  arco_ponte(0, 201, 201, 184);
  arco_ponte(1, 201, 201, 184);

glBegin(GL_POLYGON);
    glColor3ub(21, 64, 107); // MAR
    glVertex3f(-100.0f, -3.5f, 100.0f); // E
    glVertex3f(-100.0f, -3.5f, -100.0f); // F
    glVertex3f(100.0f, -3.5f, -100.0f); // FZ
    glVertex3f(100.0f, -3.5f, 100.0f); // EZ
  glEnd();
  glFlush();
}

void Iniciar() {
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(a[0], a[1], a[2], 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(100.0,largura/altura,2.0,100.0);
}

void Teclado(unsigned char key, int x, int y) {
   switch (key) {
      case 27:
         exit(0);
         break;
        case 'a': 
            a[0]=a[0]-0.2;
            break;
        case 'w': 
            a[1]=a[1]-0.2;
            break;
        case 'd': 
            a[2]=a[2]+0.2;
            break;
  }
   glutPostRedisplay();
}

int main(int argc, char** argv) {
   glutInit(&argc, argv);
   //glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB );
   glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH );
   glutInitWindowSize(largura, altura);
   glutInitWindowPosition(50, 50);
   glutCreateWindow("Casinha 3D ... ");
   glClearColor(255, 236, 91, 0);
   glutDisplayFunc(Casinha);
   glutKeyboardFunc(Teclado);
   glutMainLoop();
   return 0;
}