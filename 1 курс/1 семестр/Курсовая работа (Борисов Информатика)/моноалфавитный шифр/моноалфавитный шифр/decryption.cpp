//расшифровка
#include <iostream>
#include <fstream>
using namespace std;
int get();
void decryption(int *icrypt, int *itext, int *order)
{
	ifstream in("crypt.txt");
	ofstream out("result.txt");
	char c;
	in.get(c);
	while (!in.eof())
	{
		int t = (int)(c);
		for (int i = 0; i < 161; i++)
		if (t == order[i])
		{
			for (int j = 0; j < 161; j++)
			if (i == icrypt[j])
			{
				out << (char)(order[itext[j]]);
				break;
			}
			break;
		}
		in.get(c);
	}
	in.close();
	out.close();
}