#include<gl\glut.h>
#include <GL/freeglut.h>
#include <iostream> 
#include <windows.h> 
#include "math.h"
#include <algorithm>
#define roundf(x) floor(x + 0.5f)
float WidWid = 400;
float WidHei = 400;
// Алгоритм Брезенхема
void BresenhamLine(int x1, int y1, int x2, int y2)
{
	glBegin(GL_POINTS);
	glColor3f(0.0, 1.0, 0.0);
	int dx = (x2 - x1 >= 0 ? 1 : -1);
	int dy = (y2 - y1 >= 0 ? 1 : -1);

	int lengthX = abs(x2 - x1);
	int lengthY = abs(y2 - y1);

	int length = fmax(lengthX, lengthY);

	if (length == 0)
	{
		glVertex2f(x1, y1);
		//SetPixel(hdc, x1, y1, 0);
	}

	if (lengthY <= lengthX)
	{
		// Начальные значения
		int x = x1;
		int y = y1;
		int d = -lengthX;

		// Основной цикл
		length++;
		while (length--)
		{
			glVertex2f(x, y);
			//SetPixel(hdc,x, y, 0);
			x += dx;
			d += 2 * lengthY;
			if (d > 0) {
				d -= 2 * lengthX;
				y += dy;
			}
		}
	}
	else
	{
		// Начальные значения
		int x = x1;
		int y = y1;
		int d = -lengthY;

		// Основной цикл
		length++;
		while (length--)
		{
			glVertex2f(x, y);
			//SetPixel(hdc, x, y, 0);
			y += dy;
			d += 2 * lengthX;
			if (d > 0) {
				d -= 2 * lengthY;
				x += dx;
			}
		}
	}
	glEnd();
}
void drawCircle(float x, float y, float r, int amountSegments){
	glBegin(GL_TRIANGLE_FAN);
		glColor3f(0.0, 0.0, 1.0);
	for (int i = 0; i < amountSegments; i++)
	{
			float angle = 2.0 * 3.1415926 * float(i) / float(amountSegments);
			float dx = r * cosf(angle);
			float dy = r * sinf(angle);
			glVertex2f(x + dx , y + dy);
			glRotatef(45.0f, 0.0f, 0.0f, 1.0f);

	}
		glEnd();
}

void Draw()
{
	glutSwapBuffers(); 
	glutPostRedisplay();
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_LINES);
	glColor3f(255.0, 165.0, 0.0);
	//Ось X
	glVertex3f(-WidWid / 2, 0, 0);
	glVertex3f(WidWid / 2, 0, 0);
	//Ось Y
	glVertex3f(0, -WidHei / 2, 0);
	glVertex3f(0, WidHei / 2, 0);
	BresenhamLine(0, 0, 6, 40);
	glEnd();

	glPushMatrix();
	glTranslatef(40, 40, 0); 
	glScalef(0.5, 0.5, 0.5);
	glTranslatef(-40, -40,0); // сжатие
	glRotatef(45.0, 0, 0, 1.0);
	glBegin(GL_POINTS);
	glColor3f(139.0, 0.0, 255.0);
	glVertex3f(40, 40, 0);
	glEnd();
	glBegin(GL_POLYGON); {
		glColor3f(1.0, 0.0, 0.0);
		glVertex3f(20, 20, 0);//A
		glVertex3f(20, 60, 0);//B
		glVertex3f(60, 60, 0);//C
		glVertex3f(60, 20, 0);//D
		glEnd();
	}
	glPopMatrix();
	glPushMatrix();
	glRotatef(45.0, 0, 0, 1.0);
	drawCircle(60, 60, 20, 30);
	glPopMatrix();
	glFlush();//только для GLUT_SINGLE
}

void Initialize()
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glMatrixMode(GL_MODELVIEW);//тип матрицы
	glLoadIdentity();
	glOrtho(-WidWid/2, WidWid/2, -WidHei/2, WidHei/2, -5.0, 5.0);
	//glRotatef(45.0f, 0.0f, 0.0f, 1.0f);
}
int main(int argc, char** argv)
{
	//Инициализация
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(WidWid, WidHei);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Лабораторная работа 1");
	//Регистрация
	glutDisplayFunc(Draw);//Рисование
	Initialize();
	glutMainLoop();
	return 0;
}