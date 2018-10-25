#include "stringl.h"

stringl stringl::operator += (const stringl &a)
{
	char *c;
	c = getcl();
	int l1 = lenght_;
	int l = lenght_+a.lenght_-1;
	this->~stringl();
	lenght_=l;
	data_=new char [lenght_];
	int i;
	for (i = 0; i<l1; i++)
	{
		data_[i]=c[i];
	}
	i++;
	for (int j = 0; j<a.lenght_; j++, i++)
	{
		data_[i]=a.data_[j];
	}
	data_[lenght_]=0;
	return *this;
}

istream& operator >> (istream &is, stringl &s)
{
	s.~stringl();
	char *a = new char [1024];
	is>>a;
	if(a!=0)
	{
	for(s.lenght_=0; ((a[s.lenght_]!=0)&&(s.lenght_!=1023)); s.lenght_++);
	s.data_=new char [s.lenght_];
	for(int i = 0; i<s.lenght_; i++)
		s.data_[i]=a[i];
	s.data_[s.lenght_]=0;
	}
	else
		s.lenght_=0;
	return is;
}

ostream& operator << (ostream &os, stringl &s)
{
		if(s.lenght_!=0)
		{
			os<<s.data_;
			return os;
		}
		throw "Empty string. ";
}

stringl stringl::operator = (const stringl &s)
{
	this->~stringl();
	lenght_=s.lenght_;
	data_=new char [lenght_];
	for (int i = 0; i<lenght_; i++)
		data_[i]=s.data_[i];
	data_[lenght_]=0;
	return *this;
}

char * stringl::getcl ()
{
	char *c = new char[lenght_];
	for (int i = 0; i < lenght_; i++)
		c[i]=data_[i];
	c[lenght_]=0;
	return c;
}