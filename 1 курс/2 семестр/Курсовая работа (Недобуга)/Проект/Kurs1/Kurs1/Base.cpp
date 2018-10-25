#include "Base.h"
#include "stringl.h"


istream& operator >> (istream& is, Base& B)
{

	cout<<"Enter the Name of Product, Shop and Price: "<<endl;
	is>>B.Name_;
	if(!is) throw "Incorrect input. "; 
	char *N=B.Name_.getcl();
	int i;
	for (i = 0; N[i]!=0; i++)
		if (((N[i]>'Z')&&(N[i]<'a'))||(N[i]<'A')||(N[i]>'z'))
			throw "Invalid characters. ";
	is>>B.Shop_;
	if(!is) throw "Incorrect input. "; 
	char *S = B.Shop_.getcl();
	for (i = 0; S[i]!=0; i++)
		if (((S[i]>'Z')&&(S[i]<'a'))||(S[i]<'A')||(S[i]>'z'))
			throw "Invalid characters. ";
	is>>B.Price_;
	if(!is) throw "Incorrect input. "; 

	return is;
}

ostream& operator <<(ostream& os, Base& B)
{
		char *N  = B.Name_.getcl(), *S = B.Shop_.getcl();
		if(N[0]==0) throw "Empty name";
		if(S[0]==0) throw "Empty shop";
		os<<setw(13)<<B.Name_<<"|"<<setw(14)<<B.Shop_<<"|"<<setw(14)<<B.Price_;
	return os;
}

fstream& operator>>(fstream& iF, Base &B)
{
	stringl saveData;
	double savePrice;
	iF>>saveData;
	B.Name_=saveData;
	iF>>saveData;
	B.Shop_=saveData;
	iF>>savePrice;
	B.Price_=savePrice;
	return iF;
}

fstream& operator<<(fstream& oF, Base &B)
{
	oF<<B.Name_<<" "<<B.Shop_<<" "<<B.Price_;
	return oF;
}
		
Base Base::operator +(const double& d)
{
	Price_+=d;
	return *this;
}

Base Base::operator -(const double& d)
{
	Price_-=d;
	return *this;
}
Base Base::operator++()
{
	Price_+=1;
	return *this;
}
Base Base::operator--()
{
	Price_-=1;
	return *this;
}
Base Base::operator += (const Base& d)
{
	Price_+=d.Price_;
	return *this;
}
Base Base::operator -= (const Base& d)
{
	Price_-=d.Price_;
	return *this;
}
bool Base::operator > (const Base& B)
{
	if(Price_>B.Price_)
		return 1;
	return 0;
}
bool Base::operator < (const Base& B)
{
	if(Price_<B.Price_)
		return 1;
	return 0;
}
bool Base::operator >= (const Base& B)
{
	if(Price_>=B.Price_)
		return 1;
	return 0;
}
bool Base::operator <= (const Base& B)
{
	if(Price_<=B.Price_)
		return 1;
	return 0;
}
bool Base::operator == (const Base& B)
{
	if(Price_==B.Price_)
		return 1;
	return 0;
}
stringl Base::getName() const 
{
	return Name_;
}
stringl Base::getShop() const
{
	return Shop_;
}
double Base::getPrice() const
{
	return Price_;
}
void Base::setName(const stringl &B)
{
	Name_=B;
}
void Base::setShop(const stringl &B)
{
	Shop_=B;
}
void Base::setPrice(const double &N)
{
	Price_=N;
}