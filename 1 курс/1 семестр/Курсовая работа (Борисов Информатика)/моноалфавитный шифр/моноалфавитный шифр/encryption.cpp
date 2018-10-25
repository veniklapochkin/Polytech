//шифрование
#include <iostream>
#include <fstream>
using namespace std;
int get();
void encryption(int *key, int *array)
{
	ifstream in("input.txt");
	ofstream out("crypt.txt");
	char c;
	int k;
	in.get(c);
	while (!in.eof())
	{
		k = (int)(c);
		in.get(c);
		for (int i = 0; i < 161; i++)
		if (k == key[i])
		{
			out << (char)(array[i]);
			break;
		}
	}
	in.close();
	out.close();
}