// Este código está baseado nos exemplos disponíveis no livro 
// "OpenGL SuperBible", 2nd Edition, de Richard S. e Wright Jr.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>
#include <KHR/khrplatform.h>


GLfloat angle, fAspect;
GLfloat eixoX = 0.0f, eixoY = 0.0f, eixoZ = 0.0, asas = 0.0f, base = 0.0f;
GLint rodas = 0;
GLUquadricObj *obj = gluNewQuadric();

void DesenhaEixos(void)
{
	glBegin(GL_LINES);
		glColor3f(1.0f,0.0f,0.0f);
		glVertex3f(0.0f,0.0f,0.0f);
		glVertex3f(10.0f,0.0f,0.0f);
		glColor3f(0.0f,1.0f,0.0f);
		glVertex3f(0.0f,0.0f,0.0f);
		glVertex3f(0.0f,10.0f,0.0f);
		glColor3f(0.0f,0.0f,1.0f);
		glVertex3f(0.0f,0.0f,0.0f);
		glVertex3f(0.0f,0.0f,10.0f);
	glEnd();
}

void processKeys(unsigned char key, int x, int y) {

	switch(key){
		case 27: exit(0); break;
		case 's': eixoZ+=2.1; if(eixoZ > 180) eixoZ = 180; break;
		case 'w': eixoZ-=2.1; if(eixoZ < -180) eixoZ = -180; break;
		case 'q': eixoX+=2.1; if(eixoX > 180) eixoX = 180; break;
		case 'e': eixoX-=2.1; if(eixoX < -180) eixoX = -180; break;
		case 'a': eixoY+=2.1; if(eixoY > 180) eixoY = 180; break;
		case 'd': eixoY-=2.1; if(eixoY < -180) eixoY = -180; break;
		case 'z': if(base == 0.0f) rodas += 4.0; break;
		case 'x': base += 1.0; rodas = 0; if(base >= 30) base = 30; break;
		case 'c': base -= 1.0; rodas = 0; if(base <= -30) base = -30; break;
		case 'b': asas = 8.5f; break;
		case 'n': asas = 0.0f; break;
		// case 'z': translacao_dedo1+=1.0; translacao_dedo2-=1.0; if (translacao_dedo1 > 0) translacao_dedo1 = 0; if (translacao_dedo2 < 0) translacao_dedo2 = 0; break;
		// case 'x': translacao_dedo1-=1.0; translacao_dedo2+=1.0; if (translacao_dedo1 < -3) translacao_dedo1 = -3;if (translacao_dedo2 > 1.5) translacao_dedo2 = 1.5; break;
	}
  glutPostRedisplay();
}
            
// Função callback chamada para fazer o desenho
void Desenha(void)
{
	//Especifica sistema de coordenadas do modelo
	glMatrixMode(GL_MODELVIEW);
	// Inicializa sistema de coordenadas do modelo
	glLoadIdentity();
	// Especifica posição do observador e do alvo
 	gluLookAt(0,80,400, 0,0,0, 0,1,0);
	// Limpa a janela e o depth buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glRotatef(eixoX, 0.0f, 0.0f, 1.0f);
	glRotatef(eixoY, 0.0f, 1.0f, 0.0f);
	glRotatef(eixoZ, 1.0f, 0.0f, 0.0f);
	
	glScalef(1.5f, 1.5f, 1.5f);

	//=============teto do carro==========/
	glTranslatef(0.0f, 0.0f, 0.0f);
	glPushMatrix();
	glColor3f(0.0f, 1.0f, 0.0f);
		glScalef(3.5f, 0.25f, 3.5f);
		glutSolidCube(20.0f);
		glScalef(0.28f, 4.0f, 0.28f);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(20.0f, 0.0f, 0.0f);
	glColor3f(0.0f, 1.0f, 0.0f);
		glScalef(3.5f, 0.25f, 3.5f);
		glutSolidCube(20.0f);
	glPopMatrix();	
	//=========Fim do teto do carrro==========/
	
	//==========astes do parabrisa==========/
	glPushMatrix();
	glTranslatef(-45.0f, -15.0f, -32.0f);
	glRotatef(45.0f, 0.0f, 0.0f, 1.0f);
	glColor3f(0.0f, 1.0f, 0.0f);
		glScalef(2.0f, 0.125f, 0.25f);
		glutSolidCube(20.0f);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-45.0f, -15.0f, 32.0f);
	glRotatef(45.0f, 0.0f, 0.0f, 1.0f);
	glColor3f(0.0f, 1.0f, 0.0f);
		glScalef(2.0f, 0.125f, 0.25f);
		glutSolidCube(20.0f);
	glPopMatrix();	
	//====fim das astes do parabrisa==========/

	//==========astes do vidro de tras==========/
	glPushMatrix();
	glTranslatef(60.0f, -13.0f, -32.0f);
	glRotatef(-55.0f, 0.0f, 0.0f, 1.0f);
	glColor3f(0.0f, 1.0f, 0.0f);
		glScalef(1.5f, 0.125f, 0.25f);
		glutSolidCube(20.0f);
	glPopMatrix();

	glPushMatrix();
		glColor3f(0.0f, 1.0f, 0.0f);
		glTranslatef(60.0f, -13.0f, 32.0f);
		glRotatef(-55.0f, 0.0f, 0.0f, 1.0f);
		glScalef(1.5f, 0.125f, 0.25f);
		glutSolidCube(20.0f);
	glPopMatrix();	

	//====fim das astes do vidro de tras==========/

	//===========inicio do capô===============/
	glPushMatrix();
	glTranslatef(-75.0f, -33.0f, 0.0f);
	//glRotatef(10.0f, 0.0f, 0.0f, 1.0f);
	glColor3f(0.0f, 1.0f, 0.0f);
		glScalef(2.0f, 1.0f, 3.5f);
		glutSolidCube(20.0f);
	glPopMatrix();
	//glRotatef(-10.0f, 0.0f, 0.0f, 1.0f);
	

	glPushMatrix();
		glTranslatef(-93.0f, -33.0f, -23.0f);
		glColor3f(1.0f, 1.0f, 0.0f);
		glutSolidSphere(5.0f, 10, 10);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-93.0f, -33.0f, 23.0f);
		glColor3f(1.0f, 1.0f, 0.0f);
		glutSolidSphere(5.0f, 10, 10);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-95.0f, -44.0f, 0.0f);
	//glRotatef(10.0f, 0.0f, 0.0f, 1.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
		glScalef(0.5f, 1.5f, 3.5f);
		glutSolidCube(5.0f);
	glPopMatrix();
	
	//========fim do inicio do capô============/

	//==========portas da frente===================/
	glPushMatrix();
		glTranslatef(-30.0f, -33.0f, 34.0f);
		glColor3f(0.0f, 1.0f, 0.0f);
		glScalef(2.5f, 1.0f, 0.125f);
		glutSolidCube(20.0f);
	glPopMatrix();

	//massaneta
	glPushMatrix();
		glTranslatef(-20.0f, -28.0f, 36.0f);
		glColor3f(0.0f, 0.0f, 0.0f);
		glScalef(1.0f, 0.2f, 0.2f);
		glutSolidCube(10.0f);
	glPopMatrix();


	glPushMatrix();
		glTranslatef(-5.0f, -23.0f, 34.0f);
		glColor3f(0.0f, 1.0f, 0.0f);
		glScalef(0.125f, 2.0f, 0.125f);
		glutSolidCube(20.0f);
	glPopMatrix();



	glPushMatrix();
		glTranslatef(-17.0f, -4.0f, 34.0f);
		glRotatef(90.0f, 0.0f, 0.0f, 1.0f);
		glColor3f(0.0f, 1.0f, 0.0f);
		glScalef(0.125f, 1.3f, 0.125f);
		glutSolidCube(20.0f);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-41.5f, -15.0f, 34.0f);
		glRotatef(-45.0f, 0.0f, 0.0f, 1.0f);
		glColor3f(0.0f, 1.0f, 0.0f);
		glScalef(0.125f, 1.7f, 0.125f);
		glutSolidCube(20.0f);
	glPopMatrix();

	//massaneta
	glPushMatrix();
		glTranslatef(-20.0f, -28.0f, -36.0f);
		glColor3f(0.0f, 0.0f, 0.0f);
		glScalef(1.0f, 0.2f, 0.2f);
		glutSolidCube(10.0f);
	glPopMatrix();


	glPushMatrix();
		glTranslatef(-30.0f, -33.0f, -34.0f);
		glColor3f(0.0f, 1.0f, 0.0f);
		glScalef(2.5f, 1.0f, 0.125f);
		glutSolidCube(20.0f);
	glPopMatrix();


	glPushMatrix();
		glTranslatef(-5.0f, -23.0f, -34.0f);
		glColor3f(0.0f, 1.0f, 0.0f);
		glScalef(0.125f, 2.0f, 0.125f);
		glutSolidCube(20.0f);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-17.0f, -4.0f, -34.0f);
		glRotatef(90.0f, 0.0f, 0.0f, 1.0f);
		glColor3f(0.0f, 1.0f, 0.0f);
		glScalef(0.125f, 1.3f, 0.125f);
		glutSolidCube(20.0f);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-41.5f, -15.0f, -34.0f);
		glRotatef(-45.0f, 0.0f, 0.0f, 1.0f);
		glColor3f(0.0f, 1.0f, 0.0f);
		glScalef(0.125f, 1.7f, 0.125f);
		glutSolidCube(20.0f);
	glPopMatrix();


	//==========fim das portas da frente=============/
	//==============divisão entre portas============/
	glPushMatrix();
		glTranslatef(-2.0f, -23.0f, 34.0f);
		glColor3f(0.0f, 1.0f, 0.0f);
		glScalef(0.25f, 2.02f, 0.125f);
		glutSolidCube(20.0f);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-2.0f, -23.0f, -34.0f);
		glColor3f(0.0f, 1.0f, 0.0f);
		glScalef(0.25f, 2.02f, 0.125f);
		glutSolidCube(20.0f);
	glPopMatrix();

	//=============fim da divisao===================//
	//================portas da tras=============/
	glPushMatrix();
		glTranslatef(20.0f, -33.0f, 34.0f);
		glColor3f(0.0f, 1.0f, 0.0f);
		glScalef(2.0f, 1.0f, 0.125f);
		glutSolidCube(20.0f);
	glPopMatrix();

	//massaneta
	glPushMatrix();
		glTranslatef(25.0f, -28.0f, 36.0f);
		glColor3f(0.0f, 0.0f, 0.0f);
		glScalef(1.0f, 0.2f, 0.2f);
		glutSolidCube(10.0f);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(0.0f, -23.0f, 34.0f);
		glColor3f(0.0f, 1.0f, 0.0f);
		glScalef(0.125f, 2.0f, 0.125f);
		glutSolidCube(20.0f);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(14.0f, -4.0f, 34.0f);
		glColor3f(0.0f, 1.0f, 0.0f);
		glScalef(1.5f, 0.125f, 0.125f);
		glutSolidCube(20.0f);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(33.0f, -14.0f, 34.0f);
		glRotatef(-62.0f, 0.0f, 0.0f, 1.0f);
		glColor3f(0.0f, 1.0f, 0.0f);
		glScalef(1.2f, 0.125f, 0.125f);
		glutSolidCube(20.0f);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(20.0f, -33.0f, -34.0f);
		glColor3f(0.0f, 1.0f, 0.0f);
		glScalef(2.0f, 1.0f, 0.125f);
		glutSolidCube(20.0f);
	glPopMatrix();

	//massaneta
	glPushMatrix();
		glTranslatef(25.0f, -28.0f, -36.0f);
		glColor3f(0.0f, 0.0f, 0.0f);
		glScalef(1.0f, 0.2f, 0.2f);
		glutSolidCube(10.0f);
	glPopMatrix();


	glPushMatrix();
		glTranslatef(0.0f, -23.0f, -34.0f);
		glColor3f(0.0f, 1.0f, 0.0f);
		glScalef(0.125f, 2.0f, 0.125f);
		glutSolidCube(20.0f);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(14.0f, -4.0f, -34.0f);
		glColor3f(0.0f, 1.0f, 0.0f);
		glScalef(1.5f, 0.125f, 0.125f);
		glutSolidCube(20.0f);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(33.0f, -14.0f, -34.0f);
		glRotatef(-62.0f, 0.0f, 0.0f, 1.0f);
		glColor3f(0.0f, 1.0f, 0.0f);
		glScalef(1.2f, 0.125f, 0.125f);
		glutSolidCube(20.0f);
	glPopMatrix();

	//==========fim das portas da tras=============/

	//==============bagageiro================//

	glPushMatrix();
	glTranslatef(55.0f, -33.0f, 0.0f);
	//glRotatef(10.0f, 0.0f, 0.0f, 1.0f);
	glColor3f(0.0f, 1.0f, 0.0f);
		glScalef(1.5f, 1.0f, 3.5f);
		glutSolidCube(20.0f);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(70.0f, -33.0f, -23.0f);
		glColor3f(1.0f, 0.0f, 0.0f);
		glutSolidSphere(5.0f, 10, 10);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(70.0f, -33.0f, 23.0f);
		glColor3f(1.0f, 0.0f, 0.0f);
		glutSolidSphere(5.0f, 10, 10);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(70.0f, -44.0f, 0.0f);
	//glRotatef(10.0f, 0.0f, 0.0f, 1.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
		glScalef(0.5f, 1.5f, 3.5f);
		glutSolidCube(5.0f);
	glPopMatrix();

	// glPushMatrix();
	// 	glTranslatef(75.0f, -33.0f, -23.0f);
	// 	glColor3f(1.0f, 1.0f, 1.0f);
	// 	glutSolidSphere(1.0f, 10, 10);
	// glPopMatrix();

	// glPushMatrix();
	// 	glTranslatef(75.0f, -33.0f, 23.0f);
	// 	glColor3f(2.0f, 1.0f, 1.0f);
	// 	glutSolidSphere(1.0f, 10, 10);
	// glPopMatrix();
	//============fim bagageiro============================//

	//====================vidros================//

	//frente
	glPushMatrix();
	glTranslatef(-45.0f, -15.0f, 0.0f);
	glRotatef(-45.0f, 0.0f, 0.0f, 1.0f);
	glColor3f(0.0f, 0.0f, 1.0f);
		glScalef(0.125f, 1.7f, 3.2f);
		glutSolidCube(20.0f);
	glPopMatrix();

	//tras
	glPushMatrix();
	glTranslatef(60.0f, -13.0f, 0.0f);
	glRotatef(35.0f, 0.0f, 0.0f, 1.0f);
	glColor3f(0.0f, 0.0f, 1.0f);
		glScalef(0.125f, 1.3f, 2.95f);
		glutSolidCube(20.0f);
	glPopMatrix();

	//============lateral esquerda===========//
	
	//porta da frente
	glPushMatrix();
		glColor3f(0.0f, 0.0f, 1.0f);
		glBegin(GL_QUADS);				// start drawing a polygon (4 sided)
	  		glVertex3f(-4.0f, -40.0f, 34.0f);		// Top Left
	  		glVertex3f( -4.0f, -5.0f, 34.0f);		// Top Right
		 	glVertex3f( -30.0f, -5.0f, 34.0f);		// Bottom Right
		  	glVertex3f(-63.0f, -40.0f, 34.0f);		// Bottom Left	
	  	glEnd();	
	glPopMatrix();
	
	//porta de tras

	glPushMatrix();
		glColor3f(0.0f, 0.0f, 1.0f);
		glBegin(GL_QUADS);				// start drawing a polygon (4 sided)
	  		glVertex3f(0.0f, -40.0f, 34.0f);		// Top Left
	  		glVertex3f( 0.0f, -5.0f, 34.0f);		// Top Right
		 	glVertex3f( 30.0f, -5.0f, 34.0f);		// Bottom Right
		  	glVertex3f(40.0f, -40.0f, 34.0f);		// Bottom Left	
	  	glEnd();	
	glPopMatrix();

	//==================lateral direita=================/

	//porta da frente
	glPushMatrix();
		glColor3f(0.0f, 0.0f, 1.0f);
		glBegin(GL_QUADS);				// start drawing a polygon (4 sided)
	  		glVertex3f(-4.0f, -40.0f, -34.0f);		// Top Left
	  		glVertex3f( -4.0f, -5.0f, -34.0f);		// Top Right
		 	glVertex3f( -30.0f, -5.0f, -34.0f);		// Bottom Right
		  	glVertex3f(-63.0f, -40.0f, -34.0f);		// Bottom Left	
	  	glEnd();	
	glPopMatrix();

	//porta de tras

	glPushMatrix();
		glColor3f(0.0f, 0.0f, 1.0f);
		glBegin(GL_QUADS);				// start drawing a polygon (4 sided)
	  		glVertex3f(0.0f, -40.0f, -34.0f);		// Top Left
	  		glVertex3f( 0.0f, -5.0f, -34.0f);		// Top Right
		 	glVertex3f( 30.0f, -5.0f, -34.0f);		// Bottom Right
		  	glVertex3f(40.0f, -40.0f, -34.0f);		// Bottom Left	
	  	glEnd();	
	glPopMatrix();

	//===============fim dos vidros================//


	//================parte sem vidro da lateral de tras===================//

	glPushMatrix();
		glColor3f(0.0f, 1.0f, 0.0f);
		glBegin(GL_QUADS);				// start drawing a polygon (4 sided)
	  		glVertex3f(37.0f, -25.0f, 34.0f);		// Top Left
	  		glVertex3f( 27.0f, -2.0f, 34.0f);		// Top Right
		 	glVertex3f( 53.0f, -2.0f, 34.0f);		// Bottom Right
		  	glVertex3f(68.0f, -25.0f, 34.0f);		// Bottom Left	
	  	glEnd();	
	glPopMatrix();

	glPushMatrix();
		glColor3f(0.0f, 1.0f, 0.0f);
		glBegin(GL_QUADS);				// start drawing a polygon (4 sided)
	  		glVertex3f(37.0f, -25.0f, -34.0f);		// Top Left
	  		glVertex3f( 27.0f, -2.0f, -34.0f);		// Top Right
		 	glVertex3f( 53.0f, -2.0f, -34.0f);		// Bottom Right
		  	glVertex3f(68.0f, -25.0f, -34.0f);		// Bottom Left	
	  	glEnd();	
	glPopMatrix();

	//============fim da parte sem vidro da lateral de tras===============//

	//=====================parte de baixo============================//

	glPushMatrix();
		glTranslatef(-12.0f, -42.0f, 0.0f);
		glColor3f(0.0f, 1.0f, 0.0f);
		glScalef(8.2f, 0.125f, 3.5f);
		glutSolidCube(20.0f);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-85.0f, -50.0f, 0.0f);
		glColor3f(0.0f, 1.0f, 0.0f);
		glScalef(1.0f, 0.7f, 3.5f);
		glutSolidCube(20.0f);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-10.0f, -50.0f, 0.0f);
		glColor3f(0.0f, 1.0f, 0.0f);
		glScalef(3.0f, 0.7f, 3.5f);
		glutSolidCube(20.0f);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(63.0f, -50.0f, 0.0f);
		glColor3f(0.0f, 1.0f, 0.0f);
		glScalef(0.7f, 0.7f, 3.5f);
		glutSolidCube(20.0f);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-12.0f, -42.0f, 0.0f);
		glColor3f(0.0f, 1.0f, 0.0f);
		glScalef(2.0f, 0.125f, asas);
		glutSolidCube(20.0f);
	glPopMatrix();

	//=====================fim parte de baixo==========================//

	//===================== Rodas ==========================//

	glColor3f(0.7,0.7,0.7);
	glPushMatrix();
   		
		glColor3f(0.1, 0.1, 0.1);

		// Roda 1

		glPushMatrix();
  			glTranslatef(-57.5f, -60.0f, 34.0f);
  			glRotatef(rodas, 0, 0, 1);
  			glRotatef(base, 0, 1, 0);
  			glutSolidTorus(4.0, 11.6, 80, 80);
  		glPopMatrix();

  		glPushMatrix();
  			glTranslatef(-57.5f, -60.0f, 34.0f);
  			glColor3f(0.41, 0.41, 0.41);
  			glRotatef(rodas, 0, 0, 1);
			glRotatef(90, 1, 0, 0);
  			gluCylinder(obj, 1.0, 1.0, 10.0, 30, 30);
  			glRotatef(180, 1, 0, 0);
  			gluCylinder(obj, 1.0, 1.0, 10.0, 30, 30);
  		glPopMatrix();

  		glPushMatrix();
  			glTranslatef(-57.5f, -60.0f, 34.0f);
  			glRotatef(90, 0, 1, 0);
  			glRotatef(base, 0, 1, 0);
  			glRotatef(-rodas, 1, 0, 0);
  			gluCylinder(obj, 1.0, 1.0, 10.0, 30, 30);
  			glRotatef(180, 0, 1, 0);
  			gluCylinder(obj, 1.0, 1.0, 10.0, 30, 30);
  		glPopMatrix();

  		// Roda 2

  		glPushMatrix();
  			glColor3f(0.1, 0.1, 0.1);
  			glTranslatef(-57.5f, -60.0f, -34.0f);
  			glRotatef(rodas, 0, 0, 1);
  			glRotatef(base, 0, 1, 0);
  			glutSolidTorus(4.0, 11.6, 80, 80);
  		glPopMatrix();

  		glPushMatrix();
  			glTranslatef(-57.5f, -60.0f, -34.0f);
  			glColor3f(0.41, 0.41, 0.41);
  			glRotatef(rodas, 0, 0, 1);
			glRotatef(90, 1, 0, 0);
  			gluCylinder(obj, 1.0, 1.0, 10.0, 30, 30);
  			glRotatef(180, 1, 0, 0);
  			gluCylinder(obj, 1.0, 1.0, 10.0, 30, 30);
  		glPopMatrix();

  		glPushMatrix();
  			glTranslatef(-57.5f, -60.0f, -34.0f);
  			glRotatef(90, 0, 1, 0);
  			glRotatef(base, 0, 1, 0);
  			glRotatef(-rodas, 1, 0, 0);
  			gluCylinder(obj, 1.0, 1.0, 10.0, 30, 30);
  			glRotatef(180, 0, 1, 0);
  			gluCylinder(obj, 1.0, 1.0, 10.0, 30, 30);
  		glPopMatrix();

  		glPushMatrix();
  			glColor3f(0.41, 0.41, 0.41);
  			glTranslatef(-57.5f, -60.0f, -37.0f);
  			gluCylinder(obj, 3.0, 3.0, 73.0, 50, 50);
  			gluDisk(obj, 0.0f, 3.0, 50, 1);
  			glTranslatef(0.0f, 0.0f, 73.0f);
  			gluDisk(obj, 0.0f, 3.0, 50, 1);
  		glPopMatrix();

  		// Roda 3

  		glPushMatrix();
  			glColor3f(0.1, 0.1, 0.1);
  			glTranslatef(38.0f, -60.0f, 34.0f);
  			glRotatef(rodas, 0, 0, 1);
  			glRotatef(base, 0, 1, 0);
  			glutSolidTorus(4.0, 11.6, 80, 80);
  		glPopMatrix();

  		glPushMatrix();
  			glTranslatef(38.0f, -60.0f, 34.0f);
  			glColor3f(0.41, 0.41, 0.41);
  			glRotatef(rodas, 0, 0, 1);
			glRotatef(90, 1, 0, 0);
  			gluCylinder(obj, 1.0, 1.0, 10.0, 30, 30);
  			glRotatef(180, 1, 0, 0);
  			gluCylinder(obj, 1.0, 1.0, 10.0, 30, 30);
  		glPopMatrix();

  		glPushMatrix();
  			glTranslatef(38.0f, -60.0f, 34.0f);
  			glRotatef(90, 0, 1, 0);
  			glRotatef(-rodas, 1, 0, 0);
  			glRotatef(base, 0, 1, 0);
  			gluCylinder(obj, 1.0, 1.0, 10.0, 30, 30);
  			glRotatef(180, 0, 1, 0);
  			gluCylinder(obj, 1.0, 1.0, 10.0, 30, 30);
  		glPopMatrix();

  		// Roda 4

  		glPushMatrix();
  			glColor3f(0.1, 0.1, 0.1);
  			glTranslatef(38.0f, -60.0f, -34.0f);
  			glRotatef(rodas, 0, 0, 1);
  			glRotatef(base, 0, 1, 0);
  			glutSolidTorus(4.0, 11.6, 80, 80);
  		glPopMatrix();

  		glPushMatrix();
  			glTranslatef(38.0f, -60.0f, -34.0f);
  			glColor3f(0.41, 0.41, 0.41);
  			glRotatef(rodas, 0, 0, 1);
			glRotatef(90, 1, 0, 0);
  			gluCylinder(obj, 1.0, 1.0, 10.0, 30, 30);
  			glRotatef(180, 1, 0, 0);
  			gluCylinder(obj, 1.0, 1.0, 10.0, 30, 30);
  		glPopMatrix();

  		glPushMatrix();
  			glTranslatef(38.0f, -60.0f, -34.0f);
  			glRotatef(90, 0, 1, 0);
  			glRotatef(-rodas, 1, 0, 0);
  			glRotatef(base, 0, 1, 0);
  			gluCylinder(obj, 1.0, 1.0, 10.0, 30, 30);
  			glRotatef(180, 0, 1, 0);
  			gluCylinder(obj, 1.0, 1.0, 10.0, 30, 30);
  		glPopMatrix();

  		glPushMatrix();
  			glColor3f(0.41, 0.41, 0.41);
  			glTranslatef(38.0f, -60.0f, -37.0f);
  			gluCylinder(obj, 3.0, 3.0, 73.0, 50, 50);
  			gluDisk(obj, 0.0f, 3.0, 50, 1);
  			glTranslatef(0.0f, 0.0f, 73.0f);
  			gluDisk(obj, 0.0f, 3.0, 50, 1);
  		glPopMatrix();
  	
  	glPopMatrix();
	
	//===================== Fim das rodas ==========================//

	glutSwapBuffers();
}

// Inicializa parâmetros de rendering
void Inicializa (void)
{ 
	GLfloat luzAmbiente[4]={0.2,0.2,0.2,1.0}; 
	GLfloat luzDifusa[4]={0.7,0.7,0.7,1.0};		 // "cor" 
	GLfloat luzEspecular[4]={1.0, 1.0, 1.0, 1.0};// "brilho" 
	GLfloat posicaoLuz[4]={0.0, 80.0, 400.0, 1.0};

	// Capacidade de brilho do material
	GLfloat especularidade[4]={0.0,0.0,0.0,0.5}; 
	GLint especMaterial = 60;

 	// Especifica que a cor de fundo da janela será preta
    glClearColor(0.85f, 1.0f, 1.0f, 0.1f);
	
	// Habilita o modelo de colorização de Gouraud
	glShadeModel(GL_SMOOTH);

	// Define a refletância do material 
	glMaterialfv(GL_FRONT,GL_SPECULAR, especularidade);
	// Define a concentração do brilho
	glMateriali(GL_FRONT,GL_SHININESS,especMaterial);

	// Ativa o uso da luz ambiente 
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbiente);

	// Define os parâmetros da luz de número 0
	glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente); 
	glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusa );
	glLightfv(GL_LIGHT0, GL_SPECULAR, luzEspecular );
	glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuz );

	// Habilita a definição da cor do material a partir da cor corrente
	glEnable(GL_COLOR_MATERIAL);
	//Habilita o uso de iluminação
	glEnable(GL_LIGHTING);  
	// Habilita a luz de número 0
	glEnable(GL_LIGHT0);
	// Habilita o depth-buffering
	glEnable(GL_DEPTH_TEST);

    angle=45;
}

// Função usada para especificar o volume de visualização
void EspecificaParametrosVisualizacao(void)
{
	// Especifica sistema de coordenadas de projeção
	glMatrixMode(GL_PROJECTION);
	// Inicializa sistema de coordenadas de projeção
	glLoadIdentity();

	// Especifica a projeção perspectiva
    gluPerspective(angle,fAspect,0.4,500);
}

// Função callback chamada quando o tamanho da janela é alterado 
void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
	// Para previnir uma divisão por zero
	if ( h == 0 ) h = 1;

	// Especifica o tamanho da viewport
    glViewport(0, 0, w, h);
 
	// Calcula a correção de aspecto
	fAspect = (GLfloat)w/(GLfloat)h;

	EspecificaParametrosVisualizacao();
}

// Função callback chamada para gerenciar eventos do mouse
void GerenciaMouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON)
		if (state == GLUT_DOWN) {  // Zoom-in
			if (angle >= 10) angle -= 5;
		}
	if (button == GLUT_RIGHT_BUTTON)
		if (state == GLUT_DOWN) {  // Zoom-out
			if (angle <= 130) angle += 5;
		}
	EspecificaParametrosVisualizacao();
	glutPostRedisplay();
}

// Programa Principal
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800, 600);
	glutCreateWindow("Visualizacao 3D");
	glutDisplayFunc(Desenha);
    glutReshapeFunc(AlteraTamanhoJanela);
	glutMouseFunc(GerenciaMouse);
	glutKeyboardFunc(processKeys);
	Inicializa();
	glutMainLoop();
}


