#ifndef STRINGL_H
#define STRINGL_H

#include<iostream>
using namespace std;
class stringl 
{
	char *data_;
	int lenght_;
public:
	stringl()
	{
		lenght_=0;
	}
	stringl(const char *a)
	{		
		if (a!=0)
		{
			for (lenght_=0; a[lenght_]!=0; lenght_++);
		}
		if (lenght_!=0)
		{
			lenght_++;
			data_=new char [lenght_];
			for (int i = 0; i<lenght_; i++)
				data_[i]=a[i];	
			data_[lenght_]=0;
		}
	}
	stringl(const stringl &s)
	{
		lenght_=0;
		if (s.lenght_!=0)
		{
			lenght_=s.lenght_;
			data_=new char [lenght_];
			for (int i = 0; i<lenght_; i++)
				data_[i]=s.data_[i];
			data_[lenght_]=0;
		}		
	}
	~stringl()
	{
		data_=0;
		lenght_=0;
	}
	char * getcl();
	friend istream& operator >> (istream &is, stringl &s);
	friend ostream& operator << (ostream &os, stringl &s);
	stringl operator += (const stringl &a);
	stringl operator = (const stringl &s);
};

#endif


