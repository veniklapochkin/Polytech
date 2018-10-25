//подсчет частоты каждого символа текста
#include <iostream>
#include <fstream>
int get();
using namespace std;
void counting(int *array, bool b, int *order)
{
	ifstream it("text.txt");
	ifstream ic("crypt.txt");
	int i;
	for (i = 0; i < 161; i++)
		array[i] = 0;
	char c;
	if (b == true)
	{
		ic.get(c);
		while (!ic.eof())
		{
			int k = (int)(c);
			for (i = 0; i < 161; i++)
			if (k == order[i])
			{
				array[i]++;
				break;
			}
			ic.get(c);
		}
	}
	else
	{
		it.get(c);
		while (!it.eof())
		{
			int k = (int)(c);
			for (i = 0; i < 161; i++)
			if (k == order[i])
			{
				array[i]++;
				break;
			}
			it.get(c);
		}
	}
	ic.close();
	it.close();
}
