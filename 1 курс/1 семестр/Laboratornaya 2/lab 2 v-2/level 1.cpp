#include <iostream>
using namespace std;
void level_1(int **a, int &n)
{
	cout << "Введите кол-во элементов: ";
	cin >> n;
	*a = new int [n];
	cout << "По порядку введите " << n << " элементов массива: \n";
	for (int i = 0; i < n; i++)
	{
		cout << "number[" << i << "]=";
		cin >> (*a)[i];
	}
	return;
}