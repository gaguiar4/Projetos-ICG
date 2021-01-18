#include <math.h>
#include <GL/glut.h>

float escalaX;
float escalaY;
float angulo;
float translacaoX, translacaoY;

//COR DA JANELA E TAMANHO PLANO CARTESIANO
void inicializar(void) {
     glClearColor(0.0f, 0.8f, 0.9f, 1.0f);
     
     gluOrtho2D(0.0f, 550.0f, 0.0f, 550.0f);
}

//FUNÇÃO CIRCULO
void drawFilledCircle(GLfloat x, GLfloat y, GLfloat radius,float red, float green, float blue){

	int i;
	int triangleAmount = 25; //# of triangles used to draw circle


	GLfloat twicePi = 2.0f * 3.1415;

	glBegin(GL_TRIANGLE_FAN);

        glColor3f(red,green,blue);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
}

void desenhar(void) {
     
     glClear(GL_COLOR_BUFFER_BIT);
     glPushMatrix();
     glScalef(2, 2, 1);
     glTranslatef(30.0, 30.0 , 1);
     
     //SOL 
       glBegin(GL_TRIANGLES);
        glColor3f(1.0,0.9, 0.0);
        glVertex2f( 210, 230);
        glVertex2f( 202, 210);
        glVertex2f( 218, 210);
        
        glVertex2f( 202, 224);
        glVertex2f( 218, 224);
        glVertex2f( 210, 205);
        
        glVertex2f( 205, 228);
        glVertex2f( 205, 207);
        glVertex2f( 220, 217);

        glVertex2f(215, 228);
        glVertex2f( 215, 207);
        glVertex2f( 200, 217);
    glEnd();
    glPopMatrix();
    
   glPushMatrix();
   //BASE AVIÃO COR
   glScalef(escalaX, escalaY, 1);
   glRotatef(angulo,0,0,1);
   glTranslatef(translacaoX, translacaoY, 1);
   glBegin(GL_POLYGON);
         glColor3f(1.0, 1.0, 1.0);
         glVertex2i(65,150);
         glVertex2i(200,150);
         
         glVertex2i(65,150);
         glVertex2i(40,180);
         
         glVertex2i(40,180);
         glVertex2i(27,180);
         
         glVertex2i(27,180);
         glVertex2i(35,150);
         
         glVertex2i(35,150);
         glVertex2i(26,150);
         
         glVertex2i(26,150);
         glVertex2i(26,110);
         
         glVertex2i(26,110);
         glVertex2i(235,110);
         
         glVertex2i(235,110);
         glVertex2i(200,150);
      glEnd();
      
      //CONTORNO BASE AVIÃO COR
      glBegin(GL_LINES);
         glColor3f(0.0, 0.0, 0.0);
         glVertex2i(65,150);
         glVertex2i(200,150);
         
         glVertex2i(65,150);
         glVertex2i(40,180);
         
         glVertex2i(40,180);
         glVertex2i(27,180);
         
         glVertex2i(27,180);
         glVertex2i(35,150);
         
         glVertex2i(35,150);
         glVertex2i(26,150);
         
         glVertex2i(26,150);
         glVertex2i(26,110);
         
         glVertex2i(26,110);
         glVertex2i(235,110);
         
         glVertex2i(235,110);
         glVertex2i(200,150);
      glEnd();
      
      //BICO DO AVIÃO
       glBegin(GL_POLYGON);
         glColor3f(1.0, 0.0, 0.0);
         glVertex2i(226,120);
         glVertex2i(235,110);
         
         glVertex2i(226,120);
         glVertex2i(226,110);
         
         glVertex2i(226,110);
         glVertex2i(235,110);
         
       glEnd();
       
       //ASA DO AVIÃO
       glBegin(GL_POLYGON);
         glColor3f(0.0, 0.0, 1.0);
         glVertex2i(170,120);
         glVertex2i(110,40);
         
         glVertex2i(110,40);
         glVertex2i(100,40);
         
         glVertex2i(100,40);
         glVertex2i(130,120);
         
         glVertex2i(130,120);
         glVertex2i(170,120);
         
       glEnd();
       
       //ASA DE TRÁS DO AVIÃO
       glBegin(GL_POLYGON);
         glColor3f(0.0, 0.0, 1.0);
         glVertex2i(50,140);
         glVertex2i(25,120);
         
         glVertex2i(25,120);
         glVertex2i(15,120);
         
         glVertex2i(15,120);
         glVertex2i(30,140);
         
         glVertex2i(30,140);
         glVertex2i(50,140);
         
       glEnd();
    
        //CABINE
        glBegin(GL_TRIANGLES);
        glColor3f(1.0,0.9, 0.0);
        glVertex2f(200, 150);
        glVertex2f(200, 127);
        glVertex2f(220, 127);
      glEnd();
      
      //JANELAS
      drawFilledCircle(70, 138, 6, 1.0,0.9, 0.0);
      drawFilledCircle(90, 138, 6, 1.0,0.9, 0.0);
      drawFilledCircle(110, 138, 6, 1.0,0.9, 0.0);
      drawFilledCircle(130, 138, 6, 1.0,0.9, 0.0);
      drawFilledCircle(150, 138, 6, 1.0,0.9, 0.0);
      drawFilledCircle(170, 138, 6, 1.0,0.9, 0.0);
      
      glPopMatrix();       
       
     glFlush();

}

void eventoTeclado(unsigned char tecla, int x, int y) {
     switch(tecla){
                   case '+': escalaX += 0.1;
                             escalaY += 0.1;
                             break;
                   case '-': escalaX -= 0.1;
                             escalaY -= 0.1;
                             break;
                   case 't': angulo+=0.5;
                             break;
                   case 'r': angulo-=0.5;
                             break;
                   case 'w': translacaoY+=1.0;
                             break;
                   case 's': translacaoY-=1.0;
                             break;
                   case 'a': translacaoX-=1.0;
                             break;
                   case 'd': translacaoX+=1.0;
                             break;
                   case 27:  exit(0);
                             break;
                   case 'e': 
                             translacaoY+= 0.3;
                             translacaoX+= 0.8;
                             if (angulo <= 18.0) {
                                angulo += 0.1;
                             }
                             break;
                   case 'q': translacaoY -=0.3;
                             translacaoX += 0.8;
                             if(angulo >= -18.0) {
                                angulo -= 0.1;
                                }
                                break;
                   }
                   glutPostRedisplay();
}
     
static void exibir() {
}

int main(int argc, char *argv[]) {
    
    escalaX =1;
    escalaY =1;
    angulo=0;
    translacaoX=1;
    translacaoY=1;
    glutInit(&argc, argv);
    glutInitWindowSize(800,640);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("Avião"); 
    glutDisplayFunc(desenhar);
    glutKeyboardFunc(eventoTeclado);
    inicializar();  
    glutMainLoop();

    return 0;
}


