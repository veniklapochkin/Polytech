#include <iostream>
using namespace std;
void level_1(int **a, int &n)
{
	cout << "������� ���-�� ���������: ";
	cin >> n;
	*a = new int [n];
	cout << "�� ������� ������� " << n << " ��������� �������: \n";
	for (int i = 0; i < n; i++)
	{
		cout << "number[" << i << "]=";
		cin >> (*a)[i];
	}
	return;
}