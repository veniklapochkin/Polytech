/*
Перемещение на 1
Вращение сцены на 2
Морфинг на 3
*/
#define _CRT_SECURE_NO_WARNINGS
#include<gl\glut.h>
#include <GL/freeglut.h>
#include <iostream> 
#include <windows.h> 
#include "math.h"
#include <algorithm>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glaux.h>
#include <vector>

struct VERTEX
{
	double x;
	double y;
	double z;
};
namespace
{
	float WidWid = 1360;
	float WidHei = 760;
	GLuint	texture[1];
	GLfloat gfDeltaX = 0.01;
	GLfloat gfDeltaY = -0.02;
	GLfloat gfPosX = 0;
	GLfloat gfPosY = 0;
	GLfloat gfPosZ = 0;
	GLfloat gfDeltaZ = 0.01;
	double cx = 300, y, cz = -300;
	double t = 0;
	double M_PI = 3.14159;
	std::vector<VERTEX> p;
	std::vector<VERTEX> p2;
	std::vector<VERTEX> m;
	bool morph = false;
	int step = 0;
	int steps = 1000;
	int side = 1;
}
void makeSphere()
{
	int r = 10;
	p.clear();
	for (double phi = 0.; phi <= 2 * M_PI; phi += M_PI / 10.) // Azimuth [0, 2PI]
	{
		for (double theta = 0.; theta <= M_PI; theta += M_PI / 10.) // Elevation [0, PI]
		{
			VERTEX point;
			point.x = r * cos(phi) * sin(theta);
			point.y = r * sin(phi) * sin(theta);
			point.z = r            * cos(theta);
			p.push_back(point);
		}
		VERTEX point;
		double theta = M_PI;
		point.x = r * cos(phi) * sin(theta);
		point.y = r * sin(phi) * sin(theta);
		point.z = r            * cos(theta);
		p.push_back(point);
	}
}
void makeChel()
{
	p2 = p;
	for (int i = 0; i<p2.size() / 2; i++)
	{
		p2[i].y = 15;
	}
	for (int i = p.size() / 2; i<p2.size(); i++)
	{
		p2[i].y = -15;
	}
}

void getModVector() {
	VERTEX tempv;
	for (int i = 0; i < p.size(); i++) {
		tempv.x = (p2.at(i).x - p.at(i).x) / steps;
		tempv.y = (p2.at(i).y - p.at(i).y) / steps;
		tempv.z = (p2.at(i).z - p.at(i).z) / steps;
		m.push_back(tempv);
	}
}
void drawSphere()
{
	glBegin(GL_LINE_LOOP);
	glColor4f(1.0, 1.0, 0.0, 1.0);
	for (int i = 0; i<p.size(); i++)
	{
		glVertex3f(p[i].x, p[i].y, p[i].z);
	}
	glEnd();

	glBegin(GL_LINES);
	glColor4f(1.0, 1.0, 0.0, 1.0);
	for (int i = 0; i<p.size(); i++)
	{
		int j = i + 11;
		if (j >= p.size())j -= p.size();
		glVertex3f(p[i].x, p[i].y, p[i].z);
		glVertex3f(p[j].x, p[j].y, p[j].z);
	}

	glEnd();
	return;
}

void Draw()
{
	glMatrixMode(GL_MODELVIEW);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	glLoadIdentity();
	gluLookAt(cx, 100, cz, 0, 0, -300, 0, 1, 0);
	glTranslatef(50 + gfPosX, 40 + gfPosY, -325 + gfPosZ);
	drawSphere();
	if (morph) {
		if (step == steps) {
			morph = false;
			side *= -1;
			step = -1;
		}
		for (int i = 0; i < m.size(); i++) {
			p.at(i).x = p.at(i).x + side * m.at(i).x;
			p.at(i).y = p.at(i).y + side * m.at(i).y;
			p.at(i).z = p.at(i).z + side * m.at(i).z;
		}
		glEnable(GL_DEPTH_TEST);
		glLoadIdentity();
		gluLookAt(cx, 100, cz, 0, 0, -300, 0, 1, 0);
		glTranslatef(50 + gfPosX, 40 + gfPosY, -325 + gfPosZ);
		drawSphere();
		glPopMatrix();
		step++;
	}

	glLoadIdentity();
	gluLookAt(cx, 100, cz, 0, 0, -300, 0, 1, 0);
	glColor3f(1.0, 1.0, 1.0);
	glTranslatef(50 + gfPosX, 40 + gfPosY, -325);
	glRotatef(90, 1.0, 0.0, 0.0);
	glRotatef(180, 0.0, 0.0, 1.0);
	glutWireCylinder(15,60,30,30);
	GLUquadricObj *quadObj;
	quadObj = gluNewQuadric();
	gluQuadricTexture(quadObj, GL_TRUE);
	gluQuadricDrawStyle(quadObj, GLU_FILL);
	glRotatef(180, 1.0, 0.0, 0.0);
	glRotatef(-100, 0.0, 0.0, 1.0);
	glTranslatef(-50 + gfPosX, -40 + gfPosY, -50);
	gluCylinder(quadObj, 15, 15, 60, 20, 20);
	glTranslatef(0, 0, 65);
	glRotatef(90, 1.0, 0.0, 0.0);
	auxSolidTeapot(10);
	glLoadIdentity();
	gluDeleteQuadric(quadObj);
	glutSwapBuffers();
}
GLvoid LoadGLTextures()
{
	AUX_RGBImageRec *texture1;
	texture1 = auxDIBImageLoad("wi.bmp");
	glGenTextures(1, &texture[0]);
	glBindTexture(GL_TEXTURE_2D, texture[0]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, texture1->sizeX, texture1->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, texture1->data);
}

void Initialize(int x, int y)
{
	makeSphere();
	makeChel();
	getModVector();
	LoadGLTextures();
	glEnable(GL_TEXTURE_2D);
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(30.0, (GLdouble)x / (GLdouble)y, 0.5, 500.0);
	glMatrixMode(GL_MODELVIEW);
}

void keyboard_function(unsigned char key, int x, int y)
{
	switch (key)
	{
	case '1':
		if (gfPosX != 20){
			gfPosX = 20;
		}
		else{
			gfPosX = 0;
			gfPosY = 0;
		}
		glutPostRedisplay();
		break;
	case '2':
		cx = 300 * cos(t);
		cz = -300 + 300 * sin(t);
		t += 0.05;
		glutPostRedisplay();
		break;
	case '3':
		morph = (morph) ? false : true;
		glutPostRedisplay();
		break;
	}
}


int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(WidWid, WidHei);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Lab2");
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glutDisplayFunc(Draw);
	glutIdleFunc(Draw);
	Initialize(1300, 760);
	glutKeyboardFunc(keyboard_function);
	glutMainLoop();
}

