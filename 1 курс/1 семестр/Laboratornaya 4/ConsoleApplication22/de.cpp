//������� ���������� � �������, ������� ��������
#include <iostream>
using namespace std;
#include "header.h"
int comString(char *s1, char *s2, const int n);
void de(Abonent *a, const int n)
{
	try{
		char c[TARIF];
		setlocale (0, "");
		cout<<"������� ����� ������, ��������� �� 3 ���� \n";
		cin>>c;
		{
			for (int i=0; i<TARIF-1; i++)
			if ((c[i]<'0') || (c[i]>'9')) throw "����� ������ ������ �������� �� 3 ����"; 
		}
		c[3]=0;
		int i;
		for (i=n-1; (comString(a[i].tarif, c,n)>0) && (i>=0); i--);
		if (i==0) cout<<"��� �������,����� �������� ������ ���������";
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
		cout<<"������: "<<str;}
}
		