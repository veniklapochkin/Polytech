#include "math3.hpp"
#include <math.h>

CVector3 Cross(CVector3& vVector1, CVector3& vVector2)
{
	CVector3 vNormal;  

	vNormal.x = ((vVector1.y * vVector2.z) - (vVector1.z * vVector2.y));
	vNormal.y = ((vVector1.z * vVector2.x) - (vVector1.x * vVector2.z));
	vNormal.z = ((vVector1.x * vVector2.y) - (vVector1.y * vVector2.x));

	return vNormal; 
}

CVector3 Vector(CVector3& vPoint1, CVector3& vPoint2)
{
	CVector3 vVector;

	vVector.x = vPoint1.x - vPoint2.x;
	vVector.y = vPoint1.y - vPoint2.y;
	vVector.z = vPoint1.z - vPoint2.z;

	return vVector;
}

float Magnitude(CVector3& vNormal)
{
	return (float)sqrt((vNormal.x * vNormal.x) +
		(vNormal.y * vNormal.y) +
		(vNormal.z * vNormal.z));
}

CVector3 Normalize(CVector3& vNormal)
{
	float magnitude = Magnitude(vNormal);

	vNormal.x /= magnitude;
	vNormal.y /= magnitude;
	vNormal.z /= magnitude;

	return vNormal;
}


CVector3 Normal(CVector3 vTriangle[])
{
	CVector3 vVector1 = Vector(vTriangle[2], vTriangle[0]);
	CVector3 vVector2 = Vector(vTriangle[1], vTriangle[0]);
	CVector3 vNormal = Cross(vVector1, vVector2);
	vNormal = Normalize(vNormal);
	return vNormal;
}