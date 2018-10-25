//Выводит информацию о номерах, больших введёного
#include <iostream>
using namespace std;
#include "header.h"
int comString(char *s1, char *s2, const int n);
void de(Abonent *a, const int n)
{
	try{
		char c[TARIF];
		setlocale (0, "");
		cout<<"Введите номер тарифа, состоящий из 3 цифр \n";
		cin>>c;
		{
			for (int i=0; i<TARIF-1; i++)
			if ((c[i]<'0') || (c[i]>'9')) throw "Номер тарифа должен состоять из 3 цифр"; 
		}
		c[3]=0;
		int i;
		for (i=n-1; (comString(a[i].tarif, c,n)>0) && (i>=0); i--);
		if (i==0) cout<<"Нет тарифов,номер которого больше введённого";
		else
		for (; (comString(a[i].tarif, c,n)==0) && (i>=0); i-- )
		{
			cout<<a[i].numPhone<<" "; 
			cout<<a[i].tarif<<" "; 
			cout<<a[i].name; 
			cout<<"\n";
		}
	}
	catch (const char* str){
		cout<<"Ошибка: "<<str;}
}
		