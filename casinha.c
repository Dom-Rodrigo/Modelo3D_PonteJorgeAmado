#include <GL/glut.h>
#include <stdlib.h>

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
    glVertex3f(-0.5f, 16.0f, 0.0f);
    glVertex3f(0.5f, 16.0f, 0.0f);
    glVertex3f(0.8f, 8.5f, 0.0f);
    glVertex3f(-0.8f, 8.5f, 0.0f);

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
    glVertex3f(-3.5f, 0.0f, 0.0f); // I
  glEnd();
  glBegin(GL_POLYGON);
    glColor3f(0.9098f, 0.9098f, 0.7922f); //Perna direita
    glVertex3f(0.8f, 8.5f, 0.0f); // D
    glVertex3f(0.3f, 7.5f, 0.0f); // F
    glVertex3f(2.5f, 0.0f, 0.0f); // G
    glVertex3f(3.5f, 0.0f, 0.0f); // J
  glEnd();
  glFlush();
}

void Iniciar() {
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(a[0], a[1], a[2], 0.0, 0.0, 0.0, 0.0, 2.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(100.0,largura/altura,1.0,20.0);
}

void Teclado(unsigned char key, int x, int y) {
   switch (key) {
      case 27:
         exit(0);
         break;
        case 'a': a[0]=a[0]-0.2;
        case 'w': a[1]=a[1]-0.2;
        case 'd': a[2]=a[2]+0.2;
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