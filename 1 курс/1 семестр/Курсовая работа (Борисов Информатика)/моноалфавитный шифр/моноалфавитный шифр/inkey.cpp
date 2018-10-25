#include <fstream>
using namespace std;
int get;
void inkey(int *array)
{
	ifstream in("key.txt");
	char c;
	for (int i = 0; i < 161; i++)
	{
		in.get(c);
		array[i] = (int)(c);
	}
}