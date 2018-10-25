//¬вод структуры
#include <fstream>
using namespace std;
#include "header.h"
void inputf(Abonent *a, const int n)
{
	ifstream in("input.txt"); 
	for (int i=0; i<n; i++) 
	{	
		in>>a[i].numPhone; a[i].numPhone[NUMPHONE-1]=0;
		in>>a[i].tarif; a[i].tarif[TARIF-1]=0;
		in>>a[i].name; 
	}
}
