#include <iostream>
using namespace std;
int PrimeNumbers(int *a, int n),
	level();
void swap(int *a, int n),
	 level_1(int **a, int &n),
	 level_2(int **a, int &n),
	 level_3(int **a, int &n),
	 output(int *a, int n);
int main()
{
	setlocale(0, "");
	int *a;
	int n, l =level();
	switch(l)
	{
	case 1: level_1(&a,n); break;
	case 2: level_2(&a,n); break;
	case 3: level_3(&a,n);
	}
	cout <<"Простых чисел: " << PrimeNumbers(a,n) << "\n\n";
	swap(a,n);
	cout << "Результат программы: \n";
	output(a,n);
	return 0;
}
