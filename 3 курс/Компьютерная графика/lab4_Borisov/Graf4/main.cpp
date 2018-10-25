#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <cmath>
#include <GL/freeglut.h>
#include <algorithm>
#include <vector>
#include "set.hpp"
#include "math3.hpp"
#include "functions.hpp"
#include <windows.h>									
#include <gl\gl.h>										
#include <gl\glu.h>
#include <GL/glaux.h>
#include <stdio.h>
#include <stdlib.h>

void VMatr(GLmatrix16f M, GLvector4f v)
{
	GLfloat res[4];								
	res[0] = M[0] * v[0] + M[4] * v[1] + M[8] * v[2] + M[12] * v[3];
	res[1] = M[1] * v[0] + M[5] * v[1] + M[9] * v[2] + M[13] * v[3];
	res[2] = M[2] * v[0] + M[6] * v[1] + M[10] * v[2] + M[14] * v[3];
	res[3] = M[3] * v[0] + M[7] * v[1] + M[11] * v[2] + M[15] * v[3];
	v[0] = res[0];										
	v[1] = res[1];
	v[2] = res[2];
	v[3] = res[3];										
}

int InitGLObjects()										// Initialize Objects
{
	if (!readObject("Cube.txt", objc))			// Read Object2 Into obj
	{
		return FALSE;									// If Failed Return False
	}
	if (!readObject("Sphere.txt", sphere))
	{
		return FALSE;
	}
	SetConnectivity(&sphere);
	SetConnectivity(&objc);								// Set Face To Face Connectivity
	for (unsigned int i = 0; i<sphere.nFaces; i++)
		calculatePlane(sphere, (sphere.pFaces[i]));

	for (unsigned int i = 0;i<objc.nFaces;i++)			// Loop Through All Object Planes
		calculatePlane(objc, (objc.pFaces[i]));				// Compute Plane Equations For All Faces

	return TRUE;										// Return True
}


GLvoid LoadGLTextures()
{
	// Загрузка картинки
	AUX_RGBImageRec *texture1;
	AUX_RGBImageRec *texture2;
	AUX_RGBImageRec *texture3;
	AUX_RGBImageRec *texture4;
	AUX_RGBImageRec *texture5;
	AUX_RGBImageRec *texture6;
	AUX_RGBImageRec *texture7;
	texture1 = auxDIBImageLoad(L"Textures/ball.bmp");
	texture2 = auxDIBImageLoad(L"Textures/cubeOne.bmp");
	texture3 = auxDIBImageLoad(L"Textures/cubeFour.bmp");
	texture4 = auxDIBImageLoad(L"Textures/cubeThree.bmp");
	texture5 = auxDIBImageLoad(L"Textures/cubeSix.bmp");
	texture6 = auxDIBImageLoad(L"Textures/cubeFive.bmp");
	// Создание текстуры
	glGenTextures(7, &texture[0]);
	glBindTexture(GL_TEXTURE_2D, texture[0]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, texture1->sizeX, texture1->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, texture1->data);
	glBindTexture(GL_TEXTURE_2D, texture[1]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, texture2->sizeX, texture2->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, texture2->data);
	glBindTexture(GL_TEXTURE_2D, texture[2]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, texture3->sizeX, texture3->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, texture3->data);
	glBindTexture(GL_TEXTURE_2D, texture[3]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, texture4->sizeX, texture4->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, texture4->data);
	glBindTexture(GL_TEXTURE_2D, texture[4]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, texture5->sizeX, texture5->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, texture5->data);
	glBindTexture(GL_TEXTURE_2D, texture[5]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, texture6->sizeX, texture6->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, texture6->data);
}


void changeSize(int w, int h) {
	if (h == 0)
		h = 1;
	// используем матрицу проекции
	glMatrixMode(GL_PROJECTION);
	// обнуляем матрицу
	glLoadIdentity();
	// установить параметры вьюпорта
	glViewport(0, 0, w, h);
	// установить корректную перспективу
	gluPerspective(45.0f, w * 1.0 / h, 0.1f, 100.0f);
	// вернуться к матрице проекции
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void initialize(int w, int h)
{
	LoadGLTextures();
	glEnable(GL_TEXTURE_2D);
	glShadeModel(GL_SMOOTH);	
	glClearColor(0.0f, 0.0f, 0.0f ,1);				
	glClearDepth(1.0f);
	glClearStencil(0);							

	glEnable(GL_DEPTH_TEST);						
	glDepthFunc(GL_LEQUAL);							
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// 

	glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
	glLightfv(GL_LIGHT1, GL_POSITION, LightPos);		// Set Light1 Position
	glLightfv(GL_LIGHT1, GL_AMBIENT, LightAmb);			// Set Light1 Ambience

	glLightfv(GL_LIGHT1, GL_DIFFUSE, LightDif);			// Set Light1 Diffuse
	glLightfv(GL_LIGHT1, GL_SPECULAR, LightSpc);		// Set Light1 Specular
	glEnable(GL_LIGHT1);
	glEnable(GL_LIGHTING);
	//glDisable(GL_LIGHT0);

	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);
	glAlphaFunc(GL_GREATER, 0.1);
	glEnable(GL_ALPHA_TEST);
	glCullFace(GL_BACK);
	glEnable(GL_CULL_FACE);
	glClearColor(0.0f, 0.0f, 1.5f, 0.0f);

}

void DrawGLRoom()										// Draw The Room (Box)
{
	glEnable(GL_COLOR_MATERIAL);
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
	glBindTexture(GL_TEXTURE_2D, texture[1]);
	glBegin(GL_QUADS);
	// Floor
	glNormal3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-10.0f, -10.0f, -20.0f); glTexCoord3d(0.0f, 1.0f, -20.0f);				// Back Left
	glVertex3f(-10.0f, -10.0f, 20.0f);	glTexCoord3d(0.0f, 0.0f, 20.0f);
	glVertex3f(10.0f, -10.0f, 20.0f);	glTexCoord3d(1.0f, 0.0f, 20.0f);
	glVertex3f(10.0f, -10.0f, -20.0f);	glTexCoord3d(1.0f, 0.0f, -20.0f);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, texture[2]);
	glBegin(GL_QUADS);
	// Ceiling
	glNormal3f(0.0f, -1.0f, 0.0f);
	glVertex3f(-10.0f, 10.0f, 20.0f); glTexCoord3d(0.0f, 0.0f, 20.0f);
	glVertex3f(-10.0f, 10.0f, -20.0f); glTexCoord3d(1.0f, 0.0f, -20.0f);
	glVertex3f(10.0f, 10.0f, -20.0f); glTexCoord3d(1.0f, 1.0f, -20.0f);
	glVertex3f(10.0f, 10.0f, 20.0f); glTexCoord3d(1.0f, 1.0f, 20.0f);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, texture[4]);
	glBegin(GL_QUADS);
	// Front Wall
	glNormal3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-10.0f, 10.0f, -20.0f); glTexCoord2d(0.0f, 1.0f);
	glVertex3f(-10.0f, -10.0f, -20.0f); glTexCoord2d(0.0f, 0.0f);
	glVertex3f(10.0f, -10.0f, -20.0f); glTexCoord2d(1.0f, 0.0f);
	glVertex3f(10.0f, 10.0f, -20.0f); glTexCoord2d(1.0f, 1.0f);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, texture[2]);
	glBegin(GL_QUADS);
	// Left Wall
	glNormal3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-10.0f, 10.0f, 20.0f); glTexCoord2d(0.0f, 1.0f);
	glVertex3f(-10.0f, -10.0f, 20.0f); glTexCoord2d(0.0f, 0.0f);
	glVertex3f(-10.0f, -10.0f, -20.0f); glTexCoord2d(1.0f, 0.0f);
	glVertex3f(-10.0f, 10.0f, -20.0f); glTexCoord2d(0.0f, 1.0f);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, texture[5]);
	glBegin(GL_QUADS);
	// Right Wall
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glVertex3f(10.0f, 10.0f, -20.0f); glTexCoord3d(1.0f, 1.0f, -20.0f);
	glVertex3f(10.0f, -10.0f, -20.0f); glTexCoord3d(1.0f, 0.0f, -20.0f);
	glVertex3f(10.0f, -10.0f, 20.0f); glTexCoord3d(0.0f, 0.0f, 20.0f);
	glVertex3f(10.0f, 10.0f, 20.0f); glTexCoord3d(1.0f, 1.0f, 20.0f);
	glEnd();
	//glBindTexture(GL_TEXTURE_2D, texture[1]);
	glDisable(GL_COLOR_MATERIAL);
}

void drawScene()
{
	GLmatrix16f Minv;
	GLvector4f wlp, lp, wlp2, lp2;


	LightPos[0] = LPX;
	LightPos[1] = LPY;
	LightPos[2] = LPZ;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
	glEnable(GL_CULL_FACE);
	glLoadIdentity();
	gluLookAt(CX, CY, CZ, 0, 0, 0, 0, 1, 0);
	//glLightfv(GL_LIGHT1, GL_DIFFUSE, LightDif);
	glLightfv(GL_LIGHT1, GL_POSITION, LightPos);
	glLoadIdentity();
	glGetFloatv(GL_MODELVIEW_MATRIX, Minv); // Получить матрицу
	lp[0] = LightPos[0];            // Сохранить позицию света X в lp[0]
	lp[1] = LightPos[1];            // Сохранить позицию света Y в lp[1]
	lp[2] = LightPos[2];            // Сохранить позицию света Z в lp[2]
	lp[3] = LightPos[3];            // Сохранить позицию света в lp[3]
	VMatr(Minv, lp);             // Сохраним преобразованный вектор в массиве 'lp'
	glTranslatef(-ObjPos[0], -ObjPos[1], -ObjPos[2]); // Сдвинуть в противоположном направлении по всем осям исходя из значений ObjPos[] (X, Y, Z)
	glGetFloatv(GL_MODELVIEW_MATRIX, Minv);				
	wlp[0] = 0.0f;										
	wlp[1] = 0.0f;									
	wlp[2] = 0.0f;									
	wlp[3] = 1.0f;
	VMatr(Minv, wlp);								
													
	lp[0] += wlp[0];									
	lp[1] += wlp[1];									
	lp[2] += wlp[2];	

	glLoadIdentity();          // Сброс матрицы



	glGetFloatv(GL_MODELVIEW_MATRIX, Minv); // Получить матрицу
	lp2[0] = LightPos[0];            // Сохранить позицию света X в lp[0]
	lp2[1] = LightPos[1];            // Сохранить позицию света Y в lp[1]
	lp2[2] = LightPos[2];            // Сохранить позицию света Z в lp[2]
	lp2[3] = LightPos[3];            // Сохранить позицию света в lp[3]
	VMatr(Minv, lp2);             // Сохраним преобразованный вектор в массиве 'lp'
	glTranslatef(-KonPos[0], -KonPos[1], -KonPos[2]); // Сдвинуть в противоположном направлении по всем осям исходя из значений ObjPos[] (X, Y, Z)
	glGetFloatv(GL_MODELVIEW_MATRIX, Minv);				
	wlp2[0] = 0.0f;										
	wlp2[1] = 0.0f;										
	wlp2[2] = 0.0f;										
	wlp2[3] = 1.0f;
	VMatr(Minv, wlp2);								
														
	lp2[0] += wlp2[0];									
	lp2[1] += wlp2[1];									
	lp2[2] += wlp2[2];

	glLoadIdentity();          




	///////////////////////////////////////////////////////////////////////
	gluLookAt(CX, CY, CZ, 0, 0, 0, 0, 1, 0);
		glFrontFace(GL_CCW);
	glColor4f(1, 1, 0, 1);
	glEnable(GL_TEXTURE_2D);
	
	q = gluNewQuadric();								// Initialize Quadratic
	gluQuadricNormals(q, GL_SMOOTH);					// Enable Smooth Normal Generation
	gluQuadricTexture(q, GL_FALSE); 
	glBindTexture(GL_TEXTURE_2D, texture[2]);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, RoomDif);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, RoomSpc);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, RoomShn);
	DrawGLRoom();
	glDisable(GL_LIGHTING);
	glPushMatrix();
	glTranslatef(LPX, LPY, LPZ);
	glColor4f(1, 1, 0, 1);
	gluSphere(q, 0.3, 16, 8);
	glEnable(GL_LIGHTING);
	glLoadIdentity();
	//////////////////////////////////////////////////////////////////////


	gluLookAt(CX, CY, CZ, 0, 0, 0, 0, 1, 0);
	glTranslatef(ObjPos[0], ObjPos[1], ObjPos[2]);
	if(!((LDX<0.1)&& (LDY<0.1)&& (LDZ<0.1)))
	   castShadow(objc, lp);

	glLoadIdentity();
	///////////////////////////////////////////////////////////////////////////////////

	gluLookAt(CX, CY, CZ, 0, 0, 0, 0, 1, 0);
	glTranslatef(KonPos[0], KonPos[1], KonPos[2]);
	//glBindTexture(GL_TEXTURE_2D, texture[0]);
	glFrontFace(GL_CW);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_FRONT);
	drawObject(sphere);
	glCullFace(GL_BACK);
	drawObject(sphere);
	if (!((LDX < 0.1) && (LDY < 0.1) && (LDZ < 0.1))) 
		castShadow(sphere, lp2);


	glLoadIdentity();
	//////////////////////////////////////////////////////////////////////////////////

	gluLookAt(CX, CY, CZ, 0, 0, 0, 0, 1, 0);
	glBindTexture(GL_TEXTURE_2D, texture[0]);
	glPushMatrix();
	glFrontFace(GL_CW);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_FRONT);
	q = gluNewQuadric();
	gluQuadricTexture(q, GL_TRUE);
	gluQuadricDrawStyle(q, GLU_FILL);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, KonDif);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, KonSpc);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, KonShn);
	gluSphere(q,1.1, 16, 16);
	glCullFace(GL_BACK);
	q = gluNewQuadric();
	gluQuadricTexture(q, GL_TRUE);
	gluQuadricDrawStyle(q, GLU_FILL);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, KonDif);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, KonSpc);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, KonShn);
	gluSphere(q,1.1,16,16);
	glPopMatrix();
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, ObjDif);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, ObjSpc);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, ObjShn);
	glEnable(GL_BLEND);
	glPushMatrix();
	glTranslatef(ObjPos[0], ObjPos[1], ObjPos[2]);
	glFrontFace(GL_CW);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_FRONT);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, KonDif);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, KonSpc);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, KonShn);
	glEnable(GL_BLEND);
	drawObject(objc);
	glCullFace(GL_BACK);
	drawObject(objc);
	glPopMatrix();
	glDisable(GL_CULL_FACE);
	glutSwapBuffers();
}





void processNormalKeys(unsigned char key, int x, int y) {
	if (key == 27)
		exit(0);
	if (key == 'q' || key == 'Q' || key == 'й' || key == 'Й')
		if (LPZ < 18.0f) {
			LPZ += 0.2;
			LightPos[2] = LPZ;
		}
	if (key == 'e' || key == 'E' || key == 'у' || key == 'У')
		if (LPZ > -18.0f) {
			LPZ -= 0.2;
			LightPos[2] = LPZ;
		}
	if (key == 'a' || key == 'A' || key == 'ф' || key == 'Ф')
		if (LPX > -9.0f) {
			LPX -= 0.2;
			LightPos[0] = LPX;
		}
	if (key == 'd' || key == 'D' || key == 'в' || key == 'В')
		if (LPX < 9.0f) {
			LPX += 0.2;
			LightPos[0] = LPX;
		}
	if (key == 's' || key == 'S' || key == 'ы' || key == 'Ы')
		if (LPY > -9.0f) {
			LPY -= 0.2;
			LightPos[1] = LPY;
		}
	if (key == 'w' || key == 'W' || key == 'ц' || key == 'Ц')
		if (LPY < 9.0f) {
			LPY += 0.2;
			LightPos[1] = LPY;
		}
}

void makeObjects() {
	InitGLObjects();	
}

int main(int argc, char** argv)
{
	// Инициализация  и создание окна
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(WidWid, WidHei);
	glutInitWindowPosition(PosX, PosY);
	glutCreateWindow("BorisovLab4");
	//
	makeObjects();

	// регистрация
	initialize(WidWid, WidHei);

	glutDisplayFunc(drawScene);
	glutReshapeFunc(changeSize);
	glutIdleFunc(drawScene);
	
	glutKeyboardFunc(processNormalKeys);

	// основной цикл
	glutMainLoop();

	return 1;
}
