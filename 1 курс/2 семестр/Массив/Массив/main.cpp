#include <iostream>
#include <time.h> 
using namespace std;

#include "Array.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));

	const int size = 5;
	Array <int> arr(size);

	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 20;
		cout << "������ ������� ������� � " << i + 1 << " �������� = " << arr[i] << endl;
	}


	system ("pause");
}