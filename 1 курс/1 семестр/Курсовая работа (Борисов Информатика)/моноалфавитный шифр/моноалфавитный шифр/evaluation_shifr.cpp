//������� ������� ������� ������� �����
#include <iostream>
#include <fstream>
int get();
using namespace std;
void eval_shifr(int *array) //������ �������� ������� evalution_text �� ��� ����� � ������
{
	ifstream input("shifr.txt");
	for (int i=0; i<256;i++)
		array[i] = 0;
	char c;
	input.get(c);
	while (!input.eof())
	{
		if (c >= 0)
			array[c]++;
		else 
			array[c + 127]++;
		input.get(c);
	}
	input.close();
	return;
}
