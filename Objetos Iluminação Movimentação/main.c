#include <GL/glut.h>
#include<conio.h>   

GLfloat angulo, proporcao, rotacaoX, rotacaoY;
GLdouble observadorX, observadorY, observadorZ;

// Inicialização
void inicializar(void)
{
	// Define a cor branca de fundo da janela
	glClearColor(0.8f, 1.0f, 1.0f, 1.0f);

	// Ângulo da projeção da perspectiva
	angulo=60;

	// Inicialição das variáveis da posição do observador virtual
	rotacaoX = 30;
	rotacaoY = 0;
	observadorZ = 380;

	glEnable(GL_DEPTH_TEST);

	glEnable(GL_LIGHTING);

    glEnable(GL_COLOR_MATERIAL);

	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);

	//glShadeModel(GL_SMOOTH);
	//glShadeModel(GL_FLAT);
	glShadeModel(GL_SPECULAR);

}
void prepararMaterial(){

GLfloat especularidade[4]={1.0,1.0,1.0,1.0};
GLint especMaterial = 60;

glMaterialfv(GL_FRONT,GL_SPECULAR,especularidade);
glMateriali(GL_FRONT,GL_SHININESS,especMaterial);

}
void prepararIluminacao(){

    GLfloat luzAmbiente[4]={0.1,0.1,0.1,0.0};
    GLfloat luzDifusa[4]={1.0,1.0,1.0,1.0};
    GLfloat luzEspecular[4]={0.0,0.0,0.0,0.0};

    GLfloat posicaoLuz[4]={-180.0,100.0,0.0};

    glLightfv(GL_LIGHT0,GL_AMBIENT,luzAmbiente);
    glLightfv(GL_LIGHT0,GL_DIFFUSE,luzDifusa);
    glLightfv(GL_LIGHT0,GL_SPECULAR,luzEspecular);
    glLightfv(GL_LIGHT0,GL_POSITION,posicaoLuz);

    glLightModelfv(GL_LIGHT_MODEL_AMBIENT,luzAmbiente);


    //luz 2

    GLfloat posicaoLuz2[4]={210.0,100.0,0.0};

    glLightfv(GL_LIGHT1,GL_AMBIENT,luzAmbiente);
    glLightfv(GL_LIGHT1,GL_DIFFUSE,luzDifusa);
    glLightfv(GL_LIGHT1,GL_SPECULAR,luzEspecular);
    glLightfv(GL_LIGHT1,GL_POSITION,posicaoLuz2);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT,luzAmbiente);
}
// Função callback chamada para fazer o desenho
void desenhar(void)
{
	// Limpa a janela de visualização
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    prepararIluminacao();
    prepararMaterial();
    
    //chão
    glPushMatrix();
    glScalef(3,0.1,2);
    glColor3f(0.0f,0.0f,0.0f);
    glutSolidCube(100);
    glPopMatrix();
    
	//Cone
	glPushMatrix();
	glColor3f(1.0f, 0.8f, 0.9f);
	glTranslatef(90.0f,35.0f,0.0f);
	glutSolidCone(30.0f, 40.0f, 30,30);
	glPopMatrix();
	
	//Anel
	glPushMatrix();
	glColor3f(0.0f, 1.0f, 0.3f);
	glTranslatef(-10.0f,35.0f,0.0f);
	glutSolidTorus(10, 20, 20, 20);
	glPopMatrix();
	
    
    //chaleira
    glPushMatrix();
	glColor3f(1.0f, 0.6f, 0.0f);
	glTranslatef(-100.0f,35.0f,0.0f);
	glutSolidTeapot(30.0f);
	glPopMatrix();
     

    //SPOT LUZ 1, onde esta saindo a primeira luz
    glPushMatrix();
    glColor3f(1.0f, 1.0f, 0.0f);
    glTranslatef(-180.0,100.0,0.0);
	glutSolidSphere(5, 50, 50);
	glPopMatrix();

    //SPOT LUZ 2, onde esta saindo a segunda luz
    glPushMatrix();
    glColor3f(1.0f, 1.0f, 0.0f);
    glTranslatef(210.0,100.0,0.0);
    glutSolidSphere(5, 50, 50);
    glPopMatrix();

	// Troca os bufferes
	glutSwapBuffers();
}


// Função usada para especificar a posição do observador virtual
void posicionarObservador(void)
{
	// Especifica sistema de coordenadas do modelo
	glMatrixMode(GL_MODELVIEW);

	// Inicializa sistema de coordenadas do modelo
	glLoadIdentity();
	prepararIluminacao();
    prepararMaterial();
	// Especifica posição do observador e do alvo
	glTranslatef(0,0,-observadorZ);
	glRotatef(rotacaoX,1,0,0);
	glRotatef(rotacaoY,0,1,0);
}

// Função usada para especificar o volume de visualização
void configurarVisualizacao(void)
{
	// Especifica sistema de coordenadas de projeção
	glMatrixMode(GL_PROJECTION);
	// Inicializa sistema de coordenadas de projeção
	glLoadIdentity();

	// Especifica a projeção perspectiva(angulo,aspecto,zMin,zMax)
	gluPerspective(angulo,proporcao,0.5,500);

	posicionarObservador();
}


// Função callback chamada quando o tamanho da janela é alterado
void respondeRedimensionamentoJanela(GLsizei w, GLsizei h)
{
	// Para previnir uma divisão por zero
	if ( h == 0 ) h = 1;

	// Especifica as dimensões da viewport
	glViewport(0, 0, w, h);

	// Calcula a correção de aspecto
	proporcao = (GLfloat)w/(GLfloat)h;

	configurarVisualizacao();
}


// Callback para gerenciar eventos do mouse
void responderMouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON)
		if (state == GLUT_DOWN) {
			// Zoom-in
			if (angulo >= 10)
				angulo -= 5;
		}
	if (button == GLUT_RIGHT_BUTTON)
		if (state == GLUT_DOWN) {
			// Zoom-out
			if (angulo <= 130)
				angulo += 5;
		}
	configurarVisualizacao();
	glutPostRedisplay();
}


// Função callback chamada para gerenciar eventos de teclas especiais (F1,PgDn,...)
void responderTeclasEspeciais (int tecla, int x, int y)
{
	switch (tecla)
	{
        //MOVIMENTAÇÃO DA TELA
		case GLUT_KEY_LEFT:	rotacaoY--;
							break;
		case GLUT_KEY_RIGHT:rotacaoY++;
							break;
		case GLUT_KEY_UP:	rotacaoX++;
							break;
		case GLUT_KEY_DOWN:	rotacaoX--;
							break;
		case GLUT_KEY_HOME: observadorZ++;
							break;
		case GLUT_KEY_END:	observadorZ--;
							break;
		//ASCENDER A LUZ 1
        case GLUT_KEY_F1: glEnable(GL_LIGHT0);
                          break;
        //ASCENDER A LUZ 2
        case GLUT_KEY_F2: glEnable(GL_LIGHT1);
                          break;
        //APAGAR A LUZ 1
        case GLUT_KEY_F3: glDisable(GL_LIGHT0);
                          break;
        //APAGAR A LUZ 2
        case GLUT_KEY_F4: glDisable(GL_LIGHT1);
                          break;
	}
	posicionarObservador();
	glutPostRedisplay();
}


// Programa Principal
int main(int argc, char *argv[])
{

    glutInit(&argc, argv);
	// Define do modo de operacao da GLUT
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

	// Especifica a posição inicial da janela GLUT
    glutInitWindowPosition(5,5);

	// Especifica o tamanho inicial em pixels da janela GLUT
	glutInitWindowSize(600,400);

	// Cria a janela passando como argumento o titulo da mesma
	glutCreateWindow("Três Objetos com Iluminação");

	// Registra a funcao callback de redesenho da janela de visualizacao
	glutDisplayFunc(desenhar);
	// Registra a funcao callback para tratamento das teclas especiais
	glutSpecialFunc(responderTeclasEspeciais);
	// Registra a funcao callback para tratamento do redimensionamento da janela
    glutReshapeFunc(respondeRedimensionamentoJanela);
	// Registra a funcao callback para tratamento do mouse
	glutMouseFunc(responderMouse);

	inicializar();
	glutMainLoop();
}

