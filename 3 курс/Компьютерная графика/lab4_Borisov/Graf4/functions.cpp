#define _CRT_SECURE_NO_WARNINGS

#include "functions.hpp"
#include <iostream>
#include <stdio.h>

#define INFINITY 100

bool readObject(const char *filename, ShadowedObject& object)
{
	FILE *pInputFile;
	int i;

	pInputFile = fopen(filename, "r");
	if (pInputFile == NULL)
	{
		std::cerr << "Не могу открыть файл объекта: " << filename << std::endl;
		return false;
	}

	// Читать вершины
	fscanf(pInputFile, "%d", &object.nVertices);
	object.pVertices = new CVector3[object.nVertices];
	for (i = 0; i < object.nVertices; i++)
	{
		fscanf(pInputFile, "%f", &object.pVertices[i].x);
		fscanf(pInputFile, "%f", &object.pVertices[i].y);
		fscanf(pInputFile, "%f", &object.pVertices[i].z);
	}

	// Читать грани
	fscanf(pInputFile, "%d", &object.nFaces);
	object.pFaces = new Face[object.nFaces];
	for (i = 0; i < object.nFaces; i++)
	{
		int j;
		Face *pFace = &object.pFaces[i];

		for (j = 0; j < 3; j++)
			pFace->neighbourIndices[j] = -1; // Нет соседей

		for (j = 0; j < 3; j++)
		{
			fscanf(pInputFile, "%d", &pFace->vertexIndices[j]);
			pFace->vertexIndices[j]--; // В файле индексы начинают с 1, а в массиве с 0
		}

		for (j = 0; j < 3; j++)
		{
			fscanf(pInputFile, "%f", &pFace->normals[j].x);
			fscanf(pInputFile, "%f", &pFace->normals[j].y);
			fscanf(pInputFile, "%f", &pFace->normals[j].z);
		}
	}
	fscanf(pInputFile, "%d", &object.nTex);
	object.pTex = new CVector2[object.nTex];
	for (i = 0; i < object.nTex; i++)
	{
		fscanf(pInputFile, "%f", &object.pTex[i].x);
		fscanf(pInputFile, "%f", &object.pTex[i].y);
	}
	return true;
}

void killObject(ShadowedObject& object)
{
	delete[] object.pFaces;
	object.pFaces = NULL;
	object.nFaces = 0;

	delete[] object.pVertices;
	object.pVertices = NULL;
	object.nVertices = 0;
}

void SetConnectivity(ShadowedObject *o){
	unsigned int p1i, p2i, p1j, p2j;
	unsigned int P1i, P2i, P1j, P2j;
	unsigned int i=0,j=0,ki=0,kj=0;

	for(i=0;i<o->nFaces-1;i++)
		for(j=i+1;j<o->nFaces;j++)
			for(ki=0;ki<3;ki++)
				if(!o->pFaces[i].neighbourIndices[ki]/*o->pFaces[i].neighbourIndices[ki]==-1*/){
					for(kj=0;kj<3;kj++){

						p1i=ki;
						p1j=kj;
						p2i=(ki+1)%3;
						p2j=(kj+1)%3;

						p1i=o->pFaces[i].vertexIndices[p1i];
						p2i=o->pFaces[i].vertexIndices[p2i];
						p1j=o->pFaces[j].vertexIndices[p1j];
						p2j=o->pFaces[j].vertexIndices[p2j];

						P1i=((p1i+p2i)-abs((int)p1i - (int)p2i))/2;
						P2i=((p1i+p2i)+abs((int)p1i- (int)p2i))/2;
						P1j=((p1j+p2j)-abs((int)p1j- (int)p2j))/2;
						P2j=((p1j+p2j)+abs((int)p1j- (int)p2j))/2;

						if(((p1i == p1j) && (p2i==p2j))|| ((p1i == p2j) && (p2i == p1j)))
						{  
							o->pFaces[i].neighbourIndices[ki] = j+1;	  
							o->pFaces[j].neighbourIndices[kj] = i+1;

						}
					}
				}
}

void drawObject(const ShadowedObject& object)
{
	int k = 0;
	glBegin(GL_TRIANGLES);
	for (int i = 0; i < object.nFaces; i++)
	{
		const Face& face = object.pFaces[i];

		for (int j = 0; j < 3; j++)
		{
			const CVector3& vertex = object.pVertices[face.vertexIndices[j]];
			glTexCoord2f(object.pTex[k].x, object.pTex[k].y);
			k++;
			glNormal3f(face.normals[j].x, face.normals[j].y, face.normals[j].z);
			glVertex3f(vertex.x, vertex.y, vertex.z);
		}
	}
	glEnd();
}

void calculatePlane(const ShadowedObject& object, Face& face)
{
	// Упростить обращение к вершинам объектов
	const CVector3& v1 = object.pVertices[face.vertexIndices[0]];
	const CVector3& v2 = object.pVertices[face.vertexIndices[1]];
	const CVector3& v3 = object.pVertices[face.vertexIndices[2]];

	face.planeEquation.a = v1.y*(v2.z - v3.z) + v2.y*(v3.z - v1.z) + v3.y*(v1.z - v2.z);
	std::cout << face.planeEquation.a << std::endl;
	face.planeEquation.b = v1.z*(v2.x - v3.x) + v2.z*(v3.x - v1.x) + v3.z*(v1.x - v2.x);
	std::cout << face.planeEquation.b << std::endl;
	face.planeEquation.c = v1.x*(v2.y - v3.y) + v2.x*(v3.y - v1.y) + v3.x*(v1.y - v2.y);
	std::cout << face.planeEquation.c << std::endl;
	face.planeEquation.d = -(v1.x*(v2.y*v3.z - v3.y*v2.z) +
		v2.x*(v3.y*v1.z - v1.y*v3.z) +
		v3.x*(v1.y*v2.z - v2.y*v1.z));
	std::cout << face.planeEquation.d << std::endl;
	std::cout << std::endl;
}

void doShadowPass(ShadowedObject& object, GLfloat *lightPosition)
{
	int	i, j, k, jj;
	int	p1, p2;
	float			side;

	CVector3 v1, v2;
	for (int i = 0; i < object.nFaces; i++)
	{
		const Face& face = object.pFaces[i];

		if (face.visible)
		{
			for (int j = 0; j < 3; j++)
			{
				int neighbourIndex = face.neighbourIndices[j];
				if (neighbourIndex == -1 || object.pFaces[neighbourIndex].visible == false)
				{
					p1 = object.pFaces[i].vertexIndices[j];
					jj = (j + 1) % 3;
					p2 = object.pFaces[i].vertexIndices[jj];

			
					v1.x = (object.pVertices[p1].x - lightPosition[0]) * 100;
					v1.y = (object.pVertices[p1].y - lightPosition[1]) * 100;
					v1.z = (object.pVertices[p1].z - lightPosition[2]) * 100;

					v2.x = (object.pVertices[p2].x - lightPosition[0]) * 100;
					v2.y = (object.pVertices[p2].y - lightPosition[1]) * 100;
					v2.z = (object.pVertices[p2].z - lightPosition[2]) * 100;

			
					glBegin(GL_TRIANGLE_STRIP);
					glVertex3f(object.pVertices[p1].x,
						object.pVertices[p1].y,
						object.pVertices[p1].z);
					glVertex3f(object.pVertices[p1].x + v1.x,
						object.pVertices[p1].y + v1.y,
						object.pVertices[p1].z + v1.z);

					glVertex3f(object.pVertices[p2].x,
						object.pVertices[p2].y,
						object.pVertices[p2].z);

					glVertex3f(object.pVertices[p2].x + v2.x,
						object.pVertices[p2].y + v2.y,
						object.pVertices[p2].z + v2.z);
					glEnd();
				}
			}
		}
	}
}

void castShadow(ShadowedObject& object, GLfloat *lightPosition){
	// Определим, какие плоскости видят свет.
	for (int i = 0; i < object.nFaces; i++)
	{
		const Plane& plane = object.pFaces[i].planeEquation;

		GLfloat side = plane.a*lightPosition[0] +
			plane.b*lightPosition[1] +
			plane.c*lightPosition[2] +
			plane.d;

		if (side > 0)
			object.pFaces[i].visible = true;
		else
			object.pFaces[i].visible = false;
	}
	glDisable(GL_LIGHTING);
	glDepthMask(GL_FALSE);
	glDepthFunc(GL_LEQUAL);
	glEnable(GL_STENCIL_TEST);
	glColorMask(0, 0, 0, 0);
	glStencilFunc(GL_ALWAYS, 1, 0xffffffff);
	glFrontFace(GL_CCW);
	glStencilOp(GL_KEEP, GL_KEEP, GL_INCR);

	doShadowPass(object, lightPosition);
	// Второй проход уменьшение значения трафарета в тени

	glFrontFace(GL_CW);
	glStencilOp(GL_KEEP, GL_KEEP, GL_DECR);

	doShadowPass(object, lightPosition);

	glFrontFace(GL_CCW);
	glColorMask(1, 1, 1, 1);


	glColor4f(0.0f, 0.0f, 0.0f, 0.2f);
	glEnable(GL_BLEND);

	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glStencilFunc(GL_NOTEQUAL, 0, 0xffffffff);
	glStencilOp(GL_KEEP, GL_KEEP, GL_KEEP);
	glPushMatrix();
	glLoadIdentity();
	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(-0.1f, 0.1f, -0.10f);
	glVertex3f(-0.1f, -0.1f, -0.10f);
	glVertex3f(0.1f, 0.1f, -0.10f);
	glVertex3f(0.1f, -0.1f, -0.10f);
	glEnd();
	glPopMatrix();
	glDisable(GL_BLEND);

	glDepthFunc(GL_LEQUAL);
	glDepthMask(GL_TRUE);
	glEnable(GL_LIGHTING);
	glDisable(GL_STENCIL_TEST);
	glShadeModel(GL_SMOOTH);
}
