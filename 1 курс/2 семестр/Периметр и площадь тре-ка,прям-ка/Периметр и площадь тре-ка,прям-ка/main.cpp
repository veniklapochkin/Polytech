#include "Polygon.h"
int main()
{
	setlocale(0, "");
	//int n, col;
	//float x, y, rad;
	//cout << "������� �1\n";
	//cout << "������� ���������� �����\n";
	//cin >> n;
	//cout << "������� ������\n";
	//cin >> rad;
	//col = 0;
	//Point *ob = new Point[n];
	//cout << "������� ��������� �����\n";
	//for (int i = 0; i < n; i++)
	//{
	//	cin >> x >> y;
	//	ob[i].setxy(x, y);
	//	if (ob[i].radius(Point()) < rad)
	//		col++;
	//}
	//cout << "���������� ����� � �����\n" << col<< "\n";

	/*cout << "������� �2\n";*/
	Point obt[3];
	cout << "������� ���������� ����� ������������\n";
	for (int i = 1; i < 4; i++)
	{
		float xx, yy;
		cout << "�����[" << i << "]:" << '\n';
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
		cout << "�������� ������������\n" << triangle.pTriangle() << "\n";
		cout << "������� ������������\n" << triangle.sTriangle() << "\n";
	}
	else
		cout << "��� �� �����������\n";

	Point obr;
	cout << "������� ���������� ������� ������� ������ ���� ��������������\n";
	float xx, yy, lenght, width;
	cout << "x=  ";
	cin >> xx;
	cout << "y=  ";
	cin >> yy;
	obr.setxy(xx, yy);
	cout << "������� ����� � ������\n";
	cout << "�����:  ";
	cin >> lenght;
	cout << "������  ";
	cin >> width;
	Rectangle rectangle;
	rectangle = Rectangle(obr, lenght, width);
	cout << "�������� ��������������\n" << rectangle.pRectangle() << "\n";
	cout << "������� ��������������\n" << rectangle.sRectangle() << "\n";

	if (triangle.isTriangle)
	{
		int comparison = comparisonTR(triangle, rectangle);
		if (comparison == 0) cout << "������� ������������ ������ ������� ��������������\n";
		else if (comparison == 1) cout << "������� ������������ ������ ������� ��������������\n";
		else cout << "������� ������������ ����� ������� ��������������\n";
	}

	/*cout << "������� �3\n";*/
	int n1;
	cout << "������� ������ ������� �������������\n";
	cin >> n1;
	Triangle *array = new Triangle[n1];
	for (int j = 1; j<n1; j++)
	{
		cout << "������� ���������� ����������� �" << j << "\n";
		Point obt1[3];
		for (int i = 1; i < 4; i++)
		{
			float xx, yy;
			cout << "�����[" << i << "]:" << '\n';
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
		cout << "����� ������������ � ����������� �������� " << ans << "\n";
	else
		cout << "��� �������������\n";
	arrayoftriangle.~arrayoftriangle();

	/*cout << "������� �4\n";*/
	int n2;
	cout << "������� ���������� ����� �� ��������������\n";
	cin >> n2;
	Point *array1 = new Point[n2];
	for (int j = 1; j<n2; j++)
	{
		cout << "������� ���������� ����� �" << j << "\n";
		cout << "�����[" << j << "]:" << '\n';
		float xx, yy;
		cout << "x=  ";
		cin >> xx;
		cout << "y=  ";
		cin >> yy;
		array1[j].setxy(xx, yy);
	}
	Polygon polygon = Polygon(n2, array1);
	cout << "�������� �������������� " << polygon.pPolygon() << "\n";
	polygon.~Polygon();
	system("pause");
}