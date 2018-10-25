#include <fstream>
#include <iostream>
using namespace std;
void output(int *a, int n);
void level_3(int **a, int &n) 
{
	std::ifstream input("input.txt"); 
	input >> n;
	*a = new int [n]; 
	for (int i = 0; i < n; i++)
	{
		int c;
		input >> c;
		(*a)[i] = c;
	}
	output(*a,n); 
	return;
}
