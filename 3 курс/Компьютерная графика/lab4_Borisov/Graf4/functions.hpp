#ifndef _FUNCTIONS_H
#define _FUNCTIONS_H

#include "math3.hpp"
#include <windows.h>									
#include <gl\gl.h>										
#include <gl\glu.h>
#include <GL/glaux.h>



struct ShadowedObject
{
	GLuint nVertices;
	CVector3* pVertices; // Динамически выделяется

	GLuint nFaces;
	Face *pFaces;       // Динамически выделяется

	GLuint nTex;
	CVector2 *pTex;       // Динамически выделяется
};

bool readObject(const char *filename, ShadowedObject& object);
void SetConnectivity(ShadowedObject *o);
void drawObject(const ShadowedObject& object);
void castShadow(ShadowedObject& object, GLfloat *lightPosition);
void calculatePlane(const ShadowedObject& object, Face& face);

#endif