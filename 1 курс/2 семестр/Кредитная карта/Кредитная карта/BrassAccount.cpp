#include "BrassAccount.h"

using namespace std;


void BrassAccount::setFullName(string fullName)
{
	this->fullName_ = fullName;
}

void BrassAccount::setNumberAccount(long int numberAccount)
{
	this->numberAccount_ = numberAccount;
}

void BrassAccount::setBalance(double balance)
{
	this->balance_ = balance;
}

string BrassAccount::getFullName()
{
	return fullName_;
}

long int BrassAccount::getNumberAccount()
{
	return numberAccount_;
}

double BrassAccount::getBalance()
{
	return balance_;
}

//void showFullName ();
//
//void showNumberAccount ();
//
//void showBalance ();

void BrassAccount::showFullName()
{
	cout << "ФИО владельца карты: " << fullName_ << endl;
}

void BrassAccount::showNumberAccount()
{
	cout << "Номер банковского счёта: " << numberAccount_ << endl;
}

void BrassAccount::showBalance()
{
	cout << "Баланс = " << balance_ << endl;
}

bool BrassAccount::operator == (BrassAccount &ob1)
{
	return numberAccount_ == ob1.numberAccount_;
}

void BrassAccount::increaseBalance(double balance)
{
	if (balance <= 0)
	{
		cout << "Ошибка, нельзя увеличить баланс на отрицательную или нулевую величину" << endl;
		return;
	}

	this->balance_ += balance;
}

void BrassAccount::decreaseBalance(double balance)
{
	if (balance > balance_)
	{
		cout << "Ошибка, недостаточно средств" << endl;
		return;
	}

	this->balance_ -= balance;
}

BrassAccount & operator + (BrassAccount & ob, double balance) //для пополнения баланса
{
	ob.balance_ += balance;
	return ob;
}

BrassAccount & operator - (BrassAccount & ob, double balance) //снятие наличных
{
	ob.balance_ -= balance;
	return ob;
}





