#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;
void keygen();
void inkey(int *key);
void encryption(int *key, int *order);
void counting(int *array, bool b, int *order);
void decryption(int *icrypt, int *itext, int *order);
void swap();
int main()
{
	setlocale(LC_ALL, "Russian");
	const clock_t start = clock();
	//keygen(); //генерируем случайный ключ
	int key[161];
	inkey(key);

	int order[161];
	int i;
	for (i = -64; i < 0; i++)
		order[i + 64] = i;
	order[64] = 9;
	order[65] = 10;
	for (i = 32; i < 127; i++)
		order[i + 34] = i;

	//encryption(key, order); //зашифровываем текст

	int crypt[161], text[161], icrypt[161], itext[161];
	counting(crypt, true, order);
	counting(text, false, order);
	for (int i = 0; i < 161; i++)
	{
		icrypt[i] = i;
		itext[i] = i;
	}

	for (int i = 0; i < 160; i++)
	for (int j = i + 1; j < 161; j++)
	{
		if (text[i] < text[j])
		{
			swap(text[i], text[j]);
			swap(itext[i], itext[j]);
		}
		if (crypt[i] < crypt[j])
		{
			swap(crypt[i], crypt[j]);
			swap(icrypt[i], icrypt[j]);
		}
	}
	decryption(icrypt, itext, order); //использу€ индексы, взламываем зашифрованный файл
	const double time = static_cast<double>(clock() - start) / CLOCKS_PER_SEC;
	cout << "¬рем€ работы: " << time << " seconds" << '\n';
	system ("pause");
}