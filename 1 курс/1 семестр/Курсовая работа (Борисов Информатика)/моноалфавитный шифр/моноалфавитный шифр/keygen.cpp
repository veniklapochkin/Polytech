//генерация случайного ключа в файл key.txt
#include <iostream>
#include <fstream>
#include <time.h>
using namespace std;
void swap();
void keygen()
{
	srand(time(NULL));
	char array[161];
	int i;
	for (i = -64; i < 0; i++)
		array[i + 64] = (char)(i);
	array[64] = (char)(9);
	array[65] = (char)(10);
	for (i = 32; i < 127; i++)
		array[i + 34] = (char)(i);

	for (i = 0; i < 161; i++)
	{
		int q = rand() % 161;
		swap(array[i], array[q]);
	}
	ofstream out("key.txt");
	for (i = 0; i < 161; i++)
		out << array[i];
	out.close();
}