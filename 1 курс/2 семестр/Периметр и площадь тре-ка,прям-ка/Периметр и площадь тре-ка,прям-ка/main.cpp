#include "Polygon.h"
int main()
{
	setlocale(0, "");
	//int n, col;
	//float x, y, rad;
	//cout << "Задание №1\n";
	//cout << "Введите количество точек\n";
	//cin >> n;
	//cout << "Введите радиус\n";
	//cin >> rad;
	//col = 0;
	//Point *ob = new Point[n];
	//cout << "Введите координта точек\n";
	//for (int i = 0; i < n; i++)
	//{
	//	cin >> x >> y;
	//	ob[i].setxy(x, y);
	//	if (ob[i].radius(Point()) < rad)
	//		col++;
	//}
	//cout << "Количество точек в круге\n" << col<< "\n";

	/*cout << "Задание №2\n";*/
	Point obt[3];
	cout << "Введите координаты точек треугольника\n";
	for (int i = 1; i < 4; i++)
	{
		float xx, yy;
		cout << "Точка[" << i << "]:" << '\n';
		cout << "x=  ";
		cin >> xx;
		cout << "y=  ";
		cin >> yy;
		obt[i].setxy(xx, yy);
	}
	Triangle triangle;
	triangle = Triangle(obt[0], obt[1], obt[2]);
	if (triangle.isTriangle) // ()
	{
		cout << "Периметр треугольника\n" << triangle.pTriangle() << "\n";
		cout << "Площадь треугольника\n" << triangle.sTriangle() << "\n";
	}
	else
		cout << "Это не треугольник\n";

	Point obr;
	cout << "Введите координаты вершины нижнего левого угла прямоугольника\n";
	float xx, yy, lenght, width;
	cout << "x=  ";
	cin >> xx;
	cout << "y=  ";
	cin >> yy;
	obr.setxy(xx, yy);
	cout << "Введите длину и ширину\n";
	cout << "длина:  ";
	cin >> lenght;
	cout << "ширина  ";
	cin >> width;
	Rectangle rectangle;
	rectangle = Rectangle(obr, lenght, width);
	cout << "Периметр прямоугольника\n" << rectangle.pRectangle() << "\n";
	cout << "Площадь прямоугольника\n" << rectangle.sRectangle() << "\n";

	if (triangle.isTriangle)
	{
		int comparison = comparisonTR(triangle, rectangle);
		if (comparison == 0) cout << "Площадь треугольника больше площади прямоугольника\n";
		else if (comparison == 1) cout << "Площадь треугольника меньше площади прямоугольника\n";
		else cout << "Площадь треугольника равна площади прямоугольника\n";
	}

	/*cout << "Задание №3\n";*/
	int n1;
	cout << "Введите размер массива треугольников\n";
	cin >> n1;
	Triangle *array = new Triangle[n1];
	for (int j = 1; j<n1; j++)
	{
		cout << "Введите координаты трегольника №" << j << "\n";
		Point obt1[3];
		for (int i = 1; i < 4; i++)
		{
			float xx, yy;
			cout << "Точка[" << i << "]:" << '\n';
			cout << "x=  ";
			cin >> xx;
			cout << "y=  ";
			cin >> yy;
			obt1[i].setxy(xx, yy);
		}
		array[j] = Triangle(obt1[0], obt1[1], obt1[2]);
	}
	ArrayofTriangle arrayoftriangle = ArrayofTriangle(n1, array);
	int ans = arrayoftriangle.minTriangle();
	if ((n1>0) && (ans > -1))
		cout << "Номер треугольника с минимальной площадью " << ans << "\n";
	else
		cout << "Нет треугольников\n";
	arrayoftriangle.~arrayoftriangle();

	/*cout << "Задание №4\n";*/
	int n2;
	cout << "Введите количество точек во многоугольнике\n";
	cin >> n2;
	Point *array1 = new Point[n2];
	for (int j = 1; j<n2; j++)
	{
		cout << "Введите координаты точки №" << j << "\n";
		cout << "Точка[" << j << "]:" << '\n';
		float xx, yy;
		cout << "x=  ";
		cin >> xx;
		cout << "y=  ";
		cin >> yy;
		array1[j].setxy(xx, yy);
	}
	Polygon polygon = Polygon(n2, array1);
	cout << "Периметр многоугольника " << polygon.pPolygon() << "\n";
	polygon.~Polygon();
	system("pause");
}