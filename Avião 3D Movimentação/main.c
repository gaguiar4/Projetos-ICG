#include <gl/glut.h>

GLfloat angulo, aspecto;
GLfloat anguloy;
GLfloat aviaox, aviaoy, aviaoz;
//inicializa parâmetros de renderização
void inicializar(void)
{
     glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
     angulo=45;
     anguloy = 0;
     aviaox = 0;
     aviaoy = 0;
     aviaoz = 0;
}

//função callback chamada para fazer o desenho
void desenhar(void)
{
     //limpa a janela de visualização com a cor de fundo especificada
     glClear(GL_COLOR_BUFFER_BIT);
     
     //Especifica a cor corrente dos pontos a seguir
     glColor3f(0.6f, 0.6f, 0.6f);

    //corpo Lado1
     glPushMatrix();
     glRotatef(anguloy,0,1,0);
     glTranslatef(aviaox,aviaoy,aviaoz);
     glScalef(50,50,50);
     glBegin(GL_QUADS);
     glVertex3f(-0.2f, -0.1f, 0.8f);
     glVertex3f(0.0f, 0.0f, 0.8f);
     glVertex3f(0.0f, 0.0f, -1.0f);
     glVertex3f(-0.2f, -0.1f, -1.0f);
     glEnd();
     glBegin(GL_QUADS);
     glVertex3f(-0.2f, -0.1f, 0.8f);
     glVertex3f(-0.2f, -0.3f, 0.8f);
     glVertex3f(-0.2f, -0.3f, -1.0f);
     glVertex3f(-0.2f, -0.1f, -1.0f);
     glEnd();
     glBegin(GL_QUADS);
     glVertex3f(-0.2f, -0.3f, 0.8f);
     glVertex3f(0.0f, -0.4f, 0.8f);
     glVertex3f(0.0f, -0.4f, -1.0f);
     glVertex3f(-0.2f, -0.3f, -1.0f);
     glEnd();
     //corpo Lado2
     glBegin(GL_QUADS);
     glVertex3f(0.2f, -0.1f, 0.8f);
     glVertex3f(0.0f, 0.0f, 0.8f);
     glVertex3f(0.0f, 0.0f, -1.0f);
     glVertex3f(0.2f, -0.1f, -1.0f);
     glEnd();
     glBegin(GL_QUADS);
     glVertex3f(0.2f, -0.1f, 0.8f);
     glVertex3f(0.2f, -0.3f, 0.8f);
     glVertex3f(0.2f, -0.3f, -1.0f);
     glVertex3f(0.2f, -0.1f, -1.0f);
     glEnd();
     glBegin(GL_QUADS);
     glVertex3f(0.2f, -0.3f, 0.8f);
     glVertex3f(0.0f, -0.4f, 0.8f);
     glVertex3f(0.0f, -0.4f, -1.0f);
     glVertex3f(0.2f, -0.3f, -1.0f);
     glEnd();
     
     //Traseira
     glBegin(GL_QUADS);
     glVertex3f(0.0f, -0.0f, 0.8f);
     glVertex3f(-0.2f, -0.1f, 0.8f);
     glVertex3f(-0.2f, -0.3f, 0.8f);
     glVertex3f(0.0f, -0.4f, 0.8f);
     glEnd();
     glBegin(GL_QUADS);
    glVertex3f(0.0f, -0.0f, 0.8f);
     glVertex3f(0.2f, -0.1f, 0.8f);
     glVertex3f(0.2f, -0.3f, 0.8f);
     glVertex3f(0.0f, -0.4f, 0.8f);
     glEnd();
     
     //Frente 
     glBegin(GL_TRIANGLES);
     glVertex3f(0.0f, 0.0f, -1.0f);
     glVertex3f(-0.2f, -0.1f, -1.0f);
     glVertex3f(0.0f, -0.1f, -1.2f);
     glEnd();
     glBegin(GL_TRIANGLES);
     glVertex3f(0.0f, 0.0f, -1.0f);
     glVertex3f(0.2f, -0.1f, -1.0f);
     glVertex3f(0.0f, -0.1f, -1.2f);
     glEnd();
     
     //vidro
     glColor3f(1.0f, 1.0f, 0.0f);
     glBegin(GL_QUADS);
     glVertex3f(-0.2f, -0.1f, -1.0f);
     glVertex3f(0.0f, -0.1f, -1.2f);
     glVertex3f(0.0f, -0.15f, -1.2f);
     glVertex3f(-0.2f, -0.3f, -1.0f);
     glBegin(GL_QUADS);
     glVertex3f(0.2f, -0.1f, -1.0f);
     glVertex3f(0.0f, -0.1f, -1.2f);
     glVertex3f(0.0f, -0.15f, -1.2f);
     glVertex3f(0.2f, -0.3f, -1.0f);
     glEnd();
     
     //bico
     //cima
     glColor3f(0.6f, 0.6f, 0.6f);
     glBegin(GL_TRIANGLES);
     glVertex3f(0.0f, -0.15f, -1.2f);
     glVertex3f(-0.2f, -0.3f, -1.0f);
     glVertex3f(0.0f, -0.25f, -1.5f);
     glEnd();
     glBegin(GL_TRIANGLES);
     glVertex3f(0.0f, -0.15f, -1.2f);
     glVertex3f(0.2f, -0.3f, -1.0f);
     glVertex3f(0.0f, -0.25f, -1.5f);
     glEnd();
     //baixo
     glBegin(GL_TRIANGLES);
     glVertex3f(0.0f, -0.4f, -1.0f);
     glVertex3f(-0.2f, -0.3f, -1.0f);
     glVertex3f(0.0f, -0.25f, -1.5f);
     glEnd();
     glBegin(GL_TRIANGLES);
     glVertex3f(0.0f, -0.4f, -1.0);
     glVertex3f(0.2f, -0.3f, -1.0f);
     glVertex3f(0.0f, -0.25f, -1.5f);
     glEnd();
     
     //Asa
     glBegin(GL_QUADS);
     glVertex3f(-1.5f, -0.18f, -0.0f);
     glVertex3f(-0.9f, -0.18f, -0.4f);
     glVertex3f(-0.2f, -0.18f, -0.6f);
     glVertex3f(-0.2f, -0.18f, -0.2f);
     
     glBegin(GL_QUADS);
     glVertex3f(1.5f, -0.18f, -0.0f);
     glVertex3f(0.9f, -0.18f, -0.4f);
     glVertex3f(0.2f, -0.18f, -0.6f);
     glVertex3f(0.2f, -0.18f, -0.2f);
     glEnd();
     //traseira 
     glBegin(GL_QUADS);
     glVertex3f(0.0f, 0.0f, 0.8f);
     glVertex3f(0.0f, 0.4f, 1.0f);
     glVertex3f(0.0f, 0.4f, 0.8f);
     glVertex3f(0.0f, 0.0f, 0.0f);
     glEnd();
     
     glBegin(GL_QUADS);
     glVertex3f(-0.6f, -0.18f, 0.8f);
     glVertex3f(-0.6f, -0.18f, 0.9f);
     glVertex3f(-0.2f, -0.18f, 0.75f);
     glVertex3f(-0.2f, -0.18f, 0.0f);
     glEnd();
     glBegin(GL_QUADS);
     glVertex3f(0.6f, -0.18f, 0.8f);
     glVertex3f(0.6f, -0.18f, 0.9f);
     glVertex3f(0.2f, -0.18f, 0.75f);
     glVertex3f(0.2f, -0.18f, 0.0f);
     glEnd();
     
     glutPostRedisplay();
     glPopMatrix();
     glFlush();
     //
     //Executa os comandos OpenGL
     glutSwapBuffers();
}

//Função usada para especificar o volume de visualização
void configurarVisualizacao(void)
{
     //Especifica sistema de coordenadas de projeção
     glMatrixMode(GL_PROJECTION);
     //Inicializa sistema de coordenadas de projeção
     glLoadIdentity();
     
     //Especifica a projeção perspectiva
     gluPerspective(angulo, aspecto,0.1,500);
     
     //Especifica sistema de coordenadas do modelo
     glMatrixMode(GL_MODELVIEW);
     //Inicializa sistema de coordenadas do modelo
     glLoadIdentity();
     
     //Especifica posição do observador e do alvo
     gluLookAt(0,80,200, 0,0,0, 0,1,0);
} 

//Função callback chamada quando o tamanho da janela é alterado
void alterarTamanhoJanela(GLsizei w, GLsizei h)
{
     //Para previnir uma divisão por zero
     if( h == 0 ) h = 1;
     
     //Específica o tamanho da viewport
     glViewport(0, 0, w, h);
     
     //Calcula a correção de aspecto
     aspecto = (GLfloat)w/(GLfloat)h;
     
     configurarVisualizacao();
}

void responderTeclado (unsigned char key, int x, int y)
{
    switch (key) {
      case 'A':
      case 'a':
        aviaox -= 5;
        break;          
      case 'D':
      case 'd':
        aviaox += 5;
        break;          
      case 'W':
      case 'w':
        aviaoy += 5;
        break;          
      case 'S':
      case 's':
        aviaoy -= 5;
        break;          
      case 'Z':
      case 'z':
        aviaoz += 5;
        break;          
      case 'X':
      case 'x':
        aviaoz -= 5;
        break;          
   }
	glutPostRedisplay();
		
}

//Função callback chamada para gerenciar eventos do mouse
void eventoMouse(int button, int state, int x, int y)
{
    if(button == GLUT_LEFT_BUTTON)
        if (state == GLUT_DOWN) {  //Zoom-in
                  anguloy -= 10;
          }
    if(button == GLUT_RIGHT_BUTTON)
         if (state == GLUT_DOWN) { //Zomm-out
                   anguloy += 10;
          }
    configurarVisualizacao();
    glutPostRedisplay();
}

//Programa Principal
int main(void)
{
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(350,300);
    glutCreateWindow("Visualizacao 3D");
    glutDisplayFunc(desenhar);
    glutReshapeFunc(alterarTamanhoJanela);
    glutMouseFunc(eventoMouse);
    glutKeyboardFunc(responderTeclado);
    inicializar();
    glutMainLoop();
}
