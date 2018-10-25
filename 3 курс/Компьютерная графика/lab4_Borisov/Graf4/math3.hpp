#ifndef MATH3_HPP
#define MATH3_HPP
 
// Ёта структура используетс€ дл€ хранени€ 3д точек и векторов. ќна использовалась
// в наших уроках по камере, вернитесь назад, чтобы узнать подробности.
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
 
// ¬озвращает вектор, перпендикул€рный двум переданным векторам (плоскости)
CVector3 Cross(CVector3& vVector1, CVector3& vVector2);
 
// ¬озвращает вектор между 2м€ точками.
CVector3 Vector(CVector3& vPoint1, CVector3& vPoint2);
 
// ¬озвращает величину нормали или любого другого вектора
float Magnitude(CVector3& vNormal);
 
// ¬озвращает нормализованный вектор (его длинна становитс€ равной 1)
CVector3 Normalize(CVector3& vNormal);
 
// ¬озвращает нормаль полигона (направление, куда повернут полигон)
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
	unsigned int vertexIndices[3]; // »ндекс каждой вершины в объекте, которые задают треугольник грани
	CVector3 normals[3];   // Ќормаль каждой вершины
	Plane planeEquation;  // ”равнение плоскости с треугольником
	unsigned int neighbourIndices[3]; // »ндекс каждой грани, котора€ €вл€етс€ соседом в этом объекте
	bool visible;         // —вет видит эту грань?
};


#endif