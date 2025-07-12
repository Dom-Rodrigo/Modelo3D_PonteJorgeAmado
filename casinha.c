#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>

int largura=500, altura=500;
void Casinha(void);
float a[3]={4.0,4,4};

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
  glBegin( GL_POLYGON ); //Parede de trás
    glColor3f(0.6f,0.0f,0.0f); //Vermelha
    glVertex3f(0.0f,0.0f,0.0f);
    glVertex3f(0.0f,0.2f,0.0f);
    glVertex3f(0.2f,0.3f,0.0f);
    glVertex3f(0.4f,0.2f,0.0f);
    glVertex3f(0.4f,0.0f,0.0f);
  glEnd();
  glBegin( GL_QUADS ); //Parede esquerda
    glColor3f(0.0f,0.0f,0.6f); //Azul
    glVertex3f(0.0f,0.0f,0.0f);
    glVertex3f(0.0f,0.0f,0.4f);
    glVertex3f(0.0f,0.2f,0.4f);
    glVertex3f(0.0f,0.2f,0.0f);
  glEnd();
  glBegin( GL_QUAD_STRIP ); //Telhado
    glColor3f(0.0f,0.6f,0.0f); //Verde
    glVertex3f(0.0f,0.2f,0.0f);
    glVertex3f(0.0f,0.2f,0.4f);
    glVertex3f(0.2f,0.3f,0.0f);
    glVertex3f(0.2f,0.3f,0.4f);
    glVertex3f(0.4f,0.2f,0.0f);
    glVertex3f(0.4f,0.2f,0.4f);
  glEnd();
  glBegin( GL_POLYGON ); //Parede Frente
    glColor3f(0.6f,0.6f,0.6f); //Cinza
    glVertex3f(0.0f,0.0f,0.4f);
    glVertex3f(0.4f,0.0f,0.4f);
    glVertex3f(0.4f,0.2f,0.4f);
    glVertex3f(0.2f,0.3f,0.4f);
    glVertex3f(0.0f,0.2f,0.4f);
  glEnd();
  glBegin( GL_POLYGON ); //Parede Direita
    glColor3f(0.8f,0.8f,0.0f); //Amarelo
    glVertex3f(0.4f,0.0f,0.0f);
    glVertex3f(0.4f,0.0f,0.4f);
    glVertex3f(0.4f,0.2f,0.4f);
    glVertex3f(0.4f,0.2f,0.0f);
  glEnd();
  glBegin(GL_POLYGON);
    glColor3f(0.9098f, 0.9098f, 0.7922f); //Cor de concreto, Torre de cima
    glVertex3f(-0.5f, 16.0f, 0.0f); // A
    glVertex3f(0.5f, 16.0f, 0.0f); // B
    glVertex3f(0.8f, 8.5f, 0.0f); // D
    glVertex3f(-0.8f, 8.5f, 0.0f); // C

  glEnd();
  glBegin(GL_POLYGON);
    glColor3f(0.9098f, 0.9098f, 0.7922f); //Cor de concreto, Trapezio pras pernas
    glVertex3f(-0.8f, 8.5f, 0.0f); // C
    glVertex3f(0.8f, 8.5f, 0.0f); // D
    glVertex3f(0.3f, 7.5f, 0.0f); // F
    glVertex3f(-0.3f, 7.5f, 0.0f); // E
  glEnd();
glBegin(GL_POLYGON);
    glColor3f(0.9098f, 0.9098f, 0.7922f); //Perna esquerda
    glVertex3f(-0.8f, 8.5f, 0.0f); // C
    glVertex3f(-0.3f, 7.5f, 0.0f); // E
    glVertex3f(-2.5f, 0.0f, 0.0f); // H
    glVertex3f(-3.5f, 0.0f, 0.0f); // I1
  glEnd();
  glBegin(GL_POLYGON);
    glColor3f(0.9098f, 0.9098f, 0.7922f); //Perna direita
    glVertex3f(0.8f, 8.5f, 0.0f); // D
    glVertex3f(0.3f, 7.5f, 0.0f); // F
    glVertex3f(2.5f, 0.0f, 0.0f); // G
    glVertex3f(3.5f, 0.0f, 0.0f); // J
  glEnd();
  glBegin(GL_POLYGON);
    glColor3f(0.9098f, 0.9098f, 0.7922f); //Base direita
    glVertex3f(3.5f, 0.0f, 0.0f); // J
    glVertex3f(3.5f, -2.0f, 0.0f); // R1
    glVertex3f(2.5f, -2.0f, 0.0f); // L1
    glVertex3f(2.5f, 0.0f, 0.0f); // G
  glEnd();
  glBegin(GL_POLYGON);
    glColor3f(0.9098f, 0.9098f, 0.7922f); //Base esquerda
    glVertex3f(-2.5f, 0.0f, 0.0f); // H
    glVertex3f(-2.5f, -2.0f, 0.0f); // R
    glVertex3f(-3.5f, -2.0f, 0.0f); // L
    glVertex3f(-3.5f, 0.0f, 0.0f); // I1
  glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.9098f, 0.9098f, 0.7922f); //Base direita XZ TOP
    glVertex3f(3.5f, 0.0f, 0.0f); // J
    glVertex3f(3.5f, 0.0f, 1.0f); // JZ
    glVertex3f(2.5f, 0.0f, 1.0f); // GZ
    glVertex3f(2.5f, 0.0f, 0.0f); // G
  glEnd();
  glBegin(GL_POLYGON);
    glColor3f(0.9098f, 0.9098f, 0.7922f); //Base esquerda XZ TOP
    glVertex3f(-2.5f, 0.0f, 0.0f); // H
    glVertex3f(-2.5f, 0.0f, 1.0f); // HZ
    glVertex3f(-3.5f, 0.0f, 1.0f); // I1Z
    glVertex3f(-3.5f, 0.0f, 0.0f); // I1
  glEnd();
  glBegin(GL_POLYGON);
    glColor3f(0.9098f, 0.9098f, 0.7922f); //Base direita XZ BOT
    glVertex3f(3.5f, -2.0f, 0.0f); // R1
    glVertex3f(2.5f, -2.0f, 0.0f); // L1
    glVertex3f(2.5f, -2.0f, 1.0f); // L1Z
    glVertex3f(3.5f, -2.0f, 1.0f); // R1Z
  glEnd();
  glBegin(GL_POLYGON);
    glColor3f(0.9098f, 0.9098f, 0.7922f); //Base esquerda XZ BOT
    glVertex3f(-2.5f, -2.0f, 0.0f); // R
    glVertex3f(-3.5f, -2.0f, 0.0f); // L
    glVertex3f(-3.5f, -2.0f, 1.0f); // LZ
    glVertex3f(-2.5f, -2.0f, 1.0f); // RZ
  glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.9098f, 0.9098f, 0.7922f); //Cor de concreto, Torre de cima
    glVertex3f(-0.5f, 16.0f, 1.0f); // AZ
    glVertex3f(0.5f, 16.0f,1.0f); // BZ
    glVertex3f(0.8f, 8.5f, 1.0f); // DZ
    glVertex3f(-0.8f, 8.5f,1.0f); // CZ

  glEnd();
  glBegin(GL_POLYGON);
    glColor3f(0.9098f, 0.9098f, 0.7922f); //Cor de concreto, Trapezio pras pernas
    glVertex3f(-0.8f, 8.5f,1.0f); // CZ
    glVertex3f(0.8f, 8.5f, 1.0f); // DZ
    glVertex3f(0.3f, 7.5f, 1.0f); // FZ
    glVertex3f(-0.3f, 7.5f,1.0f); // EZ
  glEnd();
glBegin(GL_POLYGON);
    glColor3f(0.9098f, 0.9098, 0.7922f); //Perna esquerda
    glVertex3f(-0.8f, 8.5f,1.0f); // CZ
    glVertex3f(-0.3f, 7.5f,1.0f); // EZ
    glVertex3f(-2.5f, 0.0f,1.0f); // HZ
    glVertex3f(-3.5f, 0.0f,1.0f); // I1Z
  glEnd();
  glBegin(GL_POLYGON);
    glColor3f(0.9098f, 0.9098, 0.7922f); //Perna direita
    glVertex3f(0.8f, 8.5f, 1.0f); // DZ
    glVertex3f(0.3f, 7.5f, 1.0f); // FZ
    glVertex3f(2.5f, 0.0f, 1.0f); // GZ
    glVertex3f(3.5f, 0.0f, 1.0f); // JZ
  glEnd();
  glBegin(GL_POLYGON);
    glColor3f(0.9098f, 0.9098, 0.7922f); //Base direita
    glVertex3f(3.5f, 0.0f, 1.0f); // JZ
    glVertex3f(3.5f, -2.0f,1.0f); // R1Z
    glVertex3f(2.5f, -2.0f,1.0f); // L1Z
    glVertex3f(2.5f, 0.0f, 1.0f); // GZ
  glEnd();
  glBegin(GL_POLYGON);
    glColor3f(0.9098f, 0.9098, 0.7922f); //Base esquerda
    glVertex3f(-2.5f, 0.0f,1.0f); // HZ
    glVertex3f(-2.5f, -2.0, 1.0f); // RZ
    glVertex3f(-3.5f, -2.0, 1.0f); // LZ
    glVertex3f(-3.5f, 0.0f,1.0f); // I1Z
  glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.9098f, 0.9098, 0.7922f); //Parede direita da torre
    glVertex3f(3.5f, 0.0f, 1.0f); // JZ
    glVertex3f(3.5f, 0.0f, 0.0f); // J
    glVertex3f(0.8f, 8.5f, 0.0f); // D
    glVertex3f(0.8f, 8.5f, 1.0f); // DZ
  glEnd();
glBegin(GL_POLYGON);
    glColor3f(0.9098f, 0.9098, 0.7922f); //Parede esquerda da torre
    glVertex3f(-3.5f, 0.0f, 0.0f); // I1
    glVertex3f(-0.8f, 8.5f, 0.0f); // C
    glVertex3f(-0.8f, 8.5f, 1.0f); // CZ
    glVertex3f(-3.5f, 0.0f, 1.0f); // I1Z
  glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.9098f, 0.9098, 0.7922f); //Base direita Z
    glVertex3f(3.5f, 0.0f, 1.0f); // JZ
    glVertex3f(3.5f, -2.0f,1.0f); // R1Z
    glVertex3f(2.5f, -2.0f,0.0f); // R
    glVertex3f(2.5f, 0.0f, 0.0f); // J
  glEnd();
  glBegin(GL_POLYGON);
    glColor3f(0.9098f, 0.9098, 0.7922f); //Base esquerda Z
    glVertex3f(-2.5f, 0.0f,1.0f); // HZ
    glVertex3f(-2.5f, -2.0, 1.0f); // RZ
    glVertex3f(-3.5f, -2.0, 0.0f); // R
    glVertex3f(-2.5f, 0.0f, 0.0f); // H
  glEnd();
  glBegin(GL_POLYGON);
    glColor3f(0.9098f, 0.9098f, 0.7922f); // Topo
    glVertex3f(-0.5f, 16.0f, 0.0f); // A
    glVertex3f(0.5f, 16.0f, 0.0f); // B
    glVertex3f(0.5f, 16.0f, 1.0f); // BZ
    glVertex3f(-0.5f, 16.0f, 1.0f); // AZ
  glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.9098f, 0.9098f, 0.7922f); // Torre parede do lado
    glVertex3f(0.5f, 16.0f, 0.0f); // B
    glVertex3f(0.8f, 8.5f, 0.0f); // D
    glVertex3f(0.8f, 8.5f, 1.0f); // DZ
    glVertex3f(0.5f, 16.0f, 1.0f); // BZ
  glEnd();
  glBegin(GL_POLYGON);
    glColor3f(0.9098f, 0.9098f, 0.7922f); // Torre parede do outro lado
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
    glColor3ub(255, 255, 255); // Traço pi
    for (float i = -100; i < 200; i++){
        glVertex3f(0.0f, -(pow(i, 2)/1000), i);
    }
  glEnd();
  glBegin(GL_LINES);
    glColor3ub(255, 255, 255); // Cabos de aço direita
    for (float i =0; i < 23; i++){ // 23 linhas
        glVertex3f(0.0f, (8.5 + (i/23 * 6.5)), 0);
        glVertex3f(0.0f, -(pow(i, 2)/1000), 32*(i/23));
    }
  glEnd();
  glBegin(GL_LINES);
    glColor3ub(255, 255, 255); // Cabos de aço esquerda
    for (float i =0; i < 23; i++){ // 23 linhas
        glVertex3f(0.0f, (8.5 + (i/23 * 6.5)), 0);
        glVertex3f(0.0f, -(pow(i, 2)/1000), -32*(i/23));
    }
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
   glClearColor(0.0, 0.0, 0.0, 0.0);
   glutDisplayFunc(Casinha);
   glutKeyboardFunc(Teclado);
   glutMainLoop();
   return 0;
}