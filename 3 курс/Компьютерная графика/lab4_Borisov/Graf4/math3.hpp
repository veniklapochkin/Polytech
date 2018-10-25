#ifndef MATH3_HPP
#define MATH3_HPP
 
// ��� ��������� ������������ ��� �������� 3� ����� � ��������. ��� ��������������
// � ����� ������ �� ������, ��������� �����, ����� ������ �����������.
struct CVector3
{
public:
    float x, y, z;
	CVector3()
	{
		x = 0;
		y = 0;
		z = 0;
	}

	CVector3(float _x, float _y, float _z)
	{
		x = _x;
		y = _y;
		z = _z;
	}

	CVector3(const CVector3 &v) {
		x = v.x;
		y = v.y;
		z = v.z;
	}
};
 
// ���������� ������, ���������������� ���� ���������� �������� (���������)
CVector3 Cross(CVector3& vVector1, CVector3& vVector2);
 
// ���������� ������ ����� 2�� �������.
CVector3 Vector(CVector3& vPoint1, CVector3& vPoint2);
 
// ���������� �������� ������� ��� ������ ������� �������
float Magnitude(CVector3& vNormal);
 
// ���������� ��������������� ������ (��� ������ ���������� ������ 1)
CVector3 Normalize(CVector3& vNormal);
 
// ���������� ������� �������� (�����������, ���� �������� �������)
CVector3 Normal(CVector3 vTriangle[]);
 

struct CVector2
{
public:
	float x, y;
	CVector2()
	{
		x = 0;
		y = 0;
	}

	CVector2(float _x, float _y)
	{
		x = _x;
		y = _y;
	}

	CVector2(const CVector2 &v) {
		x = v.x;
		y = v.y;
	}
};

struct CFace {
	int v1, v2, v3;
};


struct Plane
{
	 float a, b, c, d;
};

struct Face
{
	unsigned int vertexIndices[3]; // ������ ������ ������� � �������, ������� ������ ����������� �����
	CVector3 normals[3];   // ������� ������ �������
	Plane planeEquation;  // ��������� ��������� � �������������
	unsigned int neighbourIndices[3]; // ������ ������ �����, ������� �������� ������� � ���� �������
	bool visible;         // ���� ����� ��� �����?
};


#endif