#ifndef _SET_HPP
#define _SET_HPP

#include "functions.hpp"

float WidWid = 800;
float WidHei = 600;
float PosX = 200;
float PosY = 100;
//

GLuint	texture[6];


typedef float GLvector4f[4];						
typedef float GLmatrix16f[16];
//камера
float CX = 0.0f;
float CY = 0.0f;
float CZ = 30.0f;
//
double PI = 3.14159265359;

//свет
bool LightActive = true;
float LPX = 5.0f, LPY = 5.0f, LPZ = 2.5f;
float LDX= 1, LDY= 1, LDZ= 0;

float LightAmb[] = { 0.2f, 0.2f, 0.2f, 0.2f };			// Ambient Light Values
float LightDif[] = { LDX, LDY, LDZ, 0.9f };			// Diffuse Light Values
float LightSpc[] = { 0.7f, 0.7f, 0.7f, 0.9f };			// Specular Light Values
float LightPos[] = { LPX, LPY, LPZ, 1.0 };
//
float MatAmb[] = { 0.4f, 0.4f, 0.4f, 1.0f };				// Material - Ambient Values
float MatDif[] = { 0.2f, 0.6f, 0.9f, 1.0f };				// Material - Diffuse Values
float MatSpc[] = { 0.0f, 0.0f, 0.0f, 1.0f };				// Material - Specular Values
float MatShn[] = { 0.0f };								// Material - Shininess

//GLfloat LightSpotDirection1[] = { -5.0, -5.0, 0.0 };
CVector3 Lightv;
CVector3 Lightv0(0.0,0.0,0.0);
//
float RoomDif[] = { 0.2f, 0.6f, 0.5f, 1.0f };				
float RoomSpc[] = { 0.0f, 0.0f, 0.0f, 1.0f };			
float RoomShn[] = { 0.0f };	

float SDif[] = { 0.2f, 0.2f, 0.2f, 1.0f };				
float SSpc[] = { 1.0f, 1.0f, 1.0f, 1.0f };			
float SShn[] = { 128.0f };	

//
float LsDif[] = { 0.8f, 0.5f, 0.1f, 1.0f };
float LsSpc[] = { 0.0f, 0.0f, 0.0f, 1.0f };
float LsShn[] = { 0.0f };
//
ShadowedObject	objc;
ShadowedObject	sphere;
float ObjPos[] = { -6.0f, -6.0f, -5.0f };
float ObjDif[] = { 0.6f, 0.6f, 0.6f, 1 };
float ObjAmb[] = { 0.6f, 0.6f, 0.6f, 1 };
float ObjSpc[] = { 0.0f, 0.0f, 0.0f, 1.0f };
float ObjShn[] = { 0.0f };
//
GLfloat		xrot = 0, xspeed = 0;							// X Rotation & X Speed
GLfloat		yrot = 0, yspeed = 0;
//
GLUquadricObj	*q;

double M_PI = 3.14159;

//
ShadowedObject	objk;

float KonPos[] = { 0.0f,0.0f, -10.0f };
float KonDif[] = { 0.6f, 0.6f, 0.6f, 0.4 };
float KonSpc[] = { 0.0f, 0.0f, 0.0f, 1.0f };
float KonShn[] = { 0.0f };
#endif