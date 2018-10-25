/*Изначально свет выключен управлять им можно с помощью клавиш 0,1,2,3,4*/
#include<gl\glut.h>
#include <GL/freeglut.h>
#include <iostream> 
#include <windows.h> 
#include <stdio.h>
#include "math.h"
#include <algorithm>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glaux.h>
#include <stdlib.h>
float WidWid = 600;
float WidHei = 760;
bool keys[256];       // Массив, использующийся для сохранения состояния клавиатуры
BOOL light;      // Свет ВКЛ / ВЫКЛ
BOOL lp;         // L нажата?
GLfloat xRotated, yRotated, zRotated, xRotatedtea, xRotatedtorus;
GLuint	texture[1];
void Draw()
{
	float MatAmb[] = { 0.4f, 0.4f, 0.4f, 1.0f };
	float MatDif[] = { 1.0f, 1.0f, 0.9f, 1.0f };
	float MatSpc[] = { 0.0f, 0.0f, 0.0f, 0.0f };
	float MatShn[] = { 128.0f };

	glMatrixMode(GL_MODELVIEW);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glEnable(GL_LIGHTING); // включаем освещение
	glBindTexture(GL_TEXTURE_2D, texture[0]);
	glTranslatef(50.0, 40.0, -400.5);
	glColor3f(1.0, 0.0, 0.0);
	glRotatef(xRotated, 1.0, 0.0, 0.0);
	glRotatef(yRotated, 0.0, 1.0, 0.0);
	glRotatef(zRotated, 0.0, 0.0, 1.0);
	glScalef(1.0, 1.0, 1.0);
	glTranslatef(-10.0, 0.0, 0.0);
	glRotatef(xRotatedtorus, 1.0, 0.0, 0.0);
	GLUquadricObj *quadObj;
	quadObj = gluNewQuadric();
	glutSolidTorus(10, 30, 30, 30); // Тор
	glLoadIdentity();
	gluQuadricTexture(quadObj, GL_TRUE);
	gluQuadricDrawStyle(quadObj, GLU_FILL);
	glEnable(GL_DEPTH_TEST);
	glDisable(GL_COLOR_MATERIAL);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, MatAmb);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, MatDif);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, MatSpc);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, MatShn);
	glTranslatef(-50.0, 40.0, -400.5);
	glColor3f(1.0, 1.0, 0.0);
	glRotatef(100, 1.0, 0.0, 0.0);
	glRotatef(180, 0.0, 0.0, 1.0);
	gluCylinder(quadObj, 30, 30, 60, 20, 20);
	glTranslatef(0.0, 0.0, -15.0);
	glRotatef(xRotatedtea, 1.0, 0.0, 0.0);
	glColor4f(1.0, 1.0, 1.0, 0.4); // прозрачность 0.4
	glEnable(GL_BLEND);// смешивание
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); //Функция смешивания 
	glDepthMask(GL_FALSE); //запрет на изменение значений в буфере глубины
	glRotatef(180, 0.0, 1.0, 0.0);
	glutSolidTeapot(20);
	glDisable(GL_LIGHTING); // выключаем освещение
	gluDeleteQuadric(quadObj);
	glDepthMask(GL_TRUE); // снимается запрет на изменение значений в буфере глубины
	glDisable(GL_BLEND); // выключается смешивание
	glutSwapBuffers();
}
// Загрузка картинки и конвертирование в текстуру
GLvoid LoadGLTextures()
{
	// Загрузка картинки
	AUX_RGBImageRec *texture1;
	texture1 = auxDIBImageLoad("wi.bmp");
	// Создание текстуры
	glGenTextures(1, &texture[0]);
	glBindTexture(GL_TEXTURE_2D, texture[0]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, texture1->sizeX, texture1->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, texture1->data);
}

void Initialize(int x, int y)
{
	LoadGLTextures();			// Загрузка текстур
	glEnable(GL_TEXTURE_2D);	// Разрешение наложение текстуры
	glEnable(GL_LIGHTING);
	glDepthFunc(GL_LESS);								// The Type Of Depth Test To Do
	glEnable(GL_DEPTH_TEST);							// Enables Depth Testing
	glShadeModel(GL_SMOOTH);							// Enables Smooth Color Shading
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really Nice Perspective Calculations
	//glEnable(GL_NORMALIZE);
	glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(30.0, (GLdouble)x / (GLdouble)y, 0.1, 500.0);
	glMatrixMode(GL_MODELVIEW);
}

void keyboard_function(unsigned char key, int x, int y)
{
	if (key=='0')
	{
		//свет выключен
		glDisable(GL_LIGHT0);
		glDisable(GL_LIGHT1);
		glDisable(GL_LIGHT2);
		glDisable(GL_LIGHT3);
		glDisable(GL_LIGHT4);
	}
	if (key == '1') {
		GLfloat light1_diffuse[] = { 1, 0.0, 0.0, 1 };
		GLfloat light1_position[] = { 10.0, 1.0, 10.0, 0.0 };
		glEnable(GL_LIGHT1);
		glLightfv(GL_LIGHT1, GL_DIFFUSE, light1_diffuse);
		glLightfv(GL_LIGHT1, GL_POSITION, light1_position);

	}
	else glDisable(GL_LIGHT1);
	if (key == '2') {
		float light_ambient[] = { 0.0, 0.0, 0.0, 1.0 };
		float light_diffuse[] = { 0.0, 1.0, 0.0, 1.0 };
		float light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
		float light_position[] = { 10.0, 1.0, 1.0, 0.0 };

		glLightfv(GL_LIGHT2, GL_AMBIENT, light_ambient);
		glLightfv(GL_LIGHT2, GL_DIFFUSE, light_diffuse);
		glLightfv(GL_LIGHT2, GL_SPECULAR, light_specular);
		glLightfv(GL_LIGHT2, GL_POSITION, light_position);

		glEnable(GL_LIGHT2);
	}
	else glDisable(GL_LIGHT2);
	if (key == '3') {
		GLfloat light0_diffuse[] = { 0.4, 1.0, 1.0 };
		GLfloat light0_direction[] = { 10.0, 10.0, 5.0, 0.0 };
		glLightfv(GL_LIGHT3, GL_DIFFUSE, light0_diffuse);
		glLightfv(GL_LIGHT3, GL_POSITION, light0_direction);
		glEnable(GL_LIGHT3);
	}
	else glDisable(GL_LIGHT3);
	if (key == '4') {
		GLfloat ligth0_ambient_intensity[] = { 0.2f, 0.2f, 0.2f, 1.0f };
		GLfloat ligth0_diffuse_intensity[] = { 1.0f, 1.0f, 0.0f, 1.0f };
		GLfloat ligth0_specular_intensity[] = { 1.0f, 1.0f, 1.0f, 1.0f };
		glLightfv(GL_LIGHT4, GL_AMBIENT, ligth0_ambient_intensity);
		glLightfv(GL_LIGHT4, GL_DIFFUSE, ligth0_diffuse_intensity);
		glLightfv(GL_LIGHT4, GL_SPECULAR, ligth0_specular_intensity);

		GLfloat ligth0_position[] = { 1.0f, 0.0f, 1.0f, 0.0f }; //Соответствует {0.0f, 0.0f, 1.0f. 0.0f}.
		glLightfv(GL_LIGHT4, GL_POSITION, ligth0_position);

		glEnable(GL_LIGHT4);
	}
	else glDisable(GL_LIGHT4);
	glutPostRedisplay();
}
int main(int argc, char** argv)
{
	//Инициализация
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	//glLightfv(GL_LIGHT1, GL_POSITION, LightPosition);
	glutInitWindowSize(WidWid, WidHei);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Лабораторная работа 3");
	xRotated = 100.0;
	xRotatedtea = 270;
	xRotatedtorus = 90;
	yRotated = 0.0;
	zRotated = 0.0;
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glutDisplayFunc(Draw);
	Initialize(600, 760);
	glutKeyboardFunc(keyboard_function);
	glutMainLoop();
}