#include <iostream>
using namespace std;
int level()
{
	cout << "������� ���-�� ��������� � ����������? (Press Y or N): ";
	char c;
	cin >> c;
	while (!(c == 'y' || c == 'Y' || c == 'n'  || c == 'N'))
	{
		cout << "������� Y or N: ";
		cin >> c;
	}
	if (c == 'Y' || c == 'y')
	{
		cout << "������� �������� � ���������� (Press Y) \n��� ��������� ������ ���������� ������� �� -100 �� 100 (Press N)?: ";
		cin >> c;
		while (!(c == 'y' || c == 'Y' || c == 'n'  || c == 'N'))
		{
			cout << "������� Y or N: ";
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
