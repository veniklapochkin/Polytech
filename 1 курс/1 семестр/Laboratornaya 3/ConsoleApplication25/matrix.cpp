#include <iostream>
using namespace std;
void Matrix(int N,int M)
{
	int S,i,j,a[20][20];
	for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++)
    cin>>a[i][j]; 
    for (S=i=0; i<N; i++)
	for (j=0; j<M; j++)
	if (j<i) S+=a[i][j];//���� ������� ����� ���� ������� ���������, �� ���� �����
	int count = 0;
    bool b;
    for (int i = 0; i < N; i++)
    {
        b = true;
        for (int j = 0; (j < M) && (b == true) ; j++)
        {
            if (a[i][j] <= 0)
            {
                b = false;
            }
        }
        if (b)
        {
            count++;
        }
    }
  cout << "���������� �����,���������� ������ ������������� ��������: "<<count << '\n';
  cout<<"����� ��������� ,������������� ���� ������� ��������� = "<<S<<endl;
}

// //int **A=new int *[x];
//for (int i=0;i<x;i++)
//	A[i]=new int [x];

