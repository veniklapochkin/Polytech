#include <iostream>
using namespace std;
void Matrix(int N,int M);
int main()
{
    setlocale (0,"");
	int N,M,a[20][20];
	cout<<"N="; cin>>N; //ввод количества строк
	cout<<"M="; cin>>M; //ввод количества столбцов
	cout<<"¬ведите матрицу  \n";
    Matrix(N,M);
	return 0;
}