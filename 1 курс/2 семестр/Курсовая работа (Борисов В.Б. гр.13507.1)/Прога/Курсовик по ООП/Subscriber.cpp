#include "Subscriber.h"
Subscriber::Subscriber() : fullName_(""), number_(""), tariff_(0){}
Subscriber::Subscriber(char *fullName, char *number, short tariff) :
fullName_(fullName), number_(number), tariff_(tariff){}
Subscriber::Subscriber(const Subscriber &ob) :
fullName_(ob.fullName_), number_(ob.number_), tariff_(ob.tariff_){};
void Subscriber::getob(char *fullName, char *number, short tariff)
{
	fullName_ = fullName;
	number_ = number;
	tariff_ = tariff;
};
void in(Subscriber &ob)
{
	char *fullName = new char[LEN_FULL_NAME],
		 *number = new char[LEN_NUMBER];
	int tariff;
	cin >> fullName;
	cin >> number;
	cin >> tariff;
	ob.getob(fullName, number, tariff);
}
void out(const Subscriber &ob)
{
	cout << "ФИО название: " << ob.fullName_ << "\n";
	cout << "Номер телефона : " << ob.number_ << "\n";
	cout << "Тариф : " << ob.tariff_ << "\n";
};
Subscriber & Subscriber::operator +(short tariff)
{
	tariff_ += tariff;
	tariff_ %= 1000;
	return *this;
};
Subscriber &operator -( Subscriber &ob, short tariff)
{
	ob.tariff_ -= tariff;
	ob.tariff_ %= 1000;
	if (ob.tariff_<0)
		ob.tariff_ += 1000;
	return ob;
};
bool Subscriber::operator >(const Subscriber &ob)
{
	return (tariff_ > ob.tariff_);
};
bool operator <(const Subscriber &ob1, const Subscriber &ob2)
{
	return (ob1.tariff_ < ob2.tariff_);
};
Subscriber & Subscriber::operator =(const Subscriber &ob){
if (this!=&ob)
{
	fullName_ = ob.fullName_;
	number_ = ob.number_;
	tariff_ = ob.tariff_;
}
return *this;
};
Subscriber & Subscriber::operator ++(int) 
{
	Subscriber temp = *this;
	this -> tariff_+=100;
	if (tariff_ > 1000)
		tariff_ = 0;
	return temp;

};
Subscriber &operator --(Subscriber &ob)
{

	if (ob.tariff_ < 0)
		ob.tariff_ = 1000;
	return ob;
}
const ostream& operator << (ostream & os, const Subscriber & ob)
{

	os <<  "ФИО название: " << ob.fullName_ << "\n"
		<< "Номер телефона : " << ob.number_ << "\n"
		<< "Тариф : " << ob.tariff_ << "\n";
	return os;
}
istream & operator >> (istream  & is, Subscriber & ob)
{
	char *fullName = new char[LEN_FULL_NAME],
		*number = new char[LEN_NUMBER];
	short tariff;
	is >> fullName;
	is >> number; 
	is >> tariff; 
	ob.getob(fullName, number, tariff);
	return is;
}