#include <iostream>
using namespace std;
void output(int *a, int n);
void level_2(int **a, int &n)
{
	cout << "������� ���-�� ���������: ";
	cin >> n;
	*a = new int [n];
	for (int i = 0; i < n; i++)
		(*a)[i] = rand() % 200 - 100;
	cout << "������: \n";
	output(*a,n);
	return;
}