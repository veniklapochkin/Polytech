#include <iostream>
#include "Point.h"
using namespace std;
float radius(Point r)
{
	float x = r.getx();
	float y = r.gety();
	return sqrt(x*x + y*y);
}
int f(Point *array, int n, float r)
{
	int k = 0;
	for (int i = 0; i < n; i++)
	if (radius(array[i]) <= r)
		k++;
	return k;
}
int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "���-�� �����: ";
	int n;
	cin >> n;
	Point *array = new Point[n];
	for (int i = 1; i < n+1; i++)
	{
		float k;
		cout << "�����[" << i << "]:" << '\n';
		cout << "x_  ";
		cin >> k;
		array[i].setx(k);
		cout << "y_  ";
		cin >> k;
		array[i].sety(k);
	}
	cout << "������� ������: ";
	float r;
	cin >> r;
	cout << "���-�� �����, ���������� � ���� ��������� �������: " << f(array, n, r) << '\n';
	system("pause");
}