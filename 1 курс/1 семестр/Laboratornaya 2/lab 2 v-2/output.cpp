#include <iostream>
using namespace std;
void output(int *a, int n)
{
	for (int i = 0; i < n; i++)
		cout << "number[" << i << "]=" << (a)[i] << '\n';
	return;
}