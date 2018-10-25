#ifndef BASE_H
#define BASE_H

#include <iostream>
#include <iomanip>
#include "stringl.h"
#include <fstream>
using namespace std;
class Base
{
	stringl Name_;
	stringl Shop_;
	double Price_;
public:
	Base(): Name_(), Shop_(), Price_(0){}
	Base(const stringl &N, const stringl &S, const double P)
	{
		Name_=N;
		Shop_=S;
		Price_=P;
	}
	Base(const Base &B)
	{
		Name_=B.Name_;
		Shop_=B.Shop_;
		Price_=B.Price_;
	}
	stringl getName() const;
	stringl getShop() const;
	double getPrice() const;
	void setName(const stringl &N);
	void setShop(const stringl &N);
	void setPrice(const double &N);
	friend ostream& operator <<(ostream & os, Base &B);
	friend istream& operator >>(istream & is, Base &B);
	friend fstream& operator >>(fstream& iF, Base &B);
	friend fstream& operator <<(fstream& oF, Base &B);
	Base operator + (const double& d);
	Base operator += (const Base& d);
	Base operator - (const double& d);
	Base operator -= (const Base& d);
	Base operator ++ ();
	Base operator -- ();
	bool operator > (const Base& B);
	bool operator < (const Base& B);
	bool operator >= (const Base& B);
	bool operator <= (const Base& B);
	bool operator == (const Base& B);
};
void ReadFile(Base*, int);
void ShowBase(Base*, int);
#endif