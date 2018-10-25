#include <iostream>
using namespace std;
int level()
{
	cout << "¬водить кол-во элементов с клавиатуры? (Press Y or N): ";
	char c;
	cin >> c;
	while (!(c == 'y' || c == 'Y' || c == 'n'  || c == 'N'))
	{
		cout << "¬ведите Y or N: ";
		cin >> c;
	}
	if (c == 'Y' || c == 'y')
	{
		cout << "¬водить элементы с клавиатуры (Press Y) \nили заполнить массив случайными числами от -100 до 100 (Press N)?: ";
		cin >> c;
		while (!(c == 'y' || c == 'Y' || c == 'n'  || c == 'N'))
		{
			cout << "¬ведите Y or N: ";
			cin >> c;
		}
		if (c == 'Y' || c == 'y')
			return 1;
		else
			return 2;
	}
	else 
		return 3;
}
