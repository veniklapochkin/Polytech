#include <iostream>
#include  <string>
using namespace std;


class BrassAccount
{
protected:
	string fullName_;
	long int numberAccount_;
	double balance_;
public:

	BrassAccount()
	{
		fullName_ = "";
		numberAccount_ = 0;
		balance_ = 0;
		cout << "Вызван конструктор банковского счёта по умолчанию" << endl;
	}

	BrassAccount(string fullName, long int numberAccount, double balance)
	{
		fullName_ = fullName;
		numberAccount_ = numberAccount;
		balance_ = balance;
		cout << "Вызван конструктор банковского счёта c параметрами" << endl;
	}

	BrassAccount(const BrassAccount & ob)
	{
		fullName_ = ob.fullName_;
		numberAccount_ = ob.numberAccount_;
		balance_ = ob.balance_;

		cout << "Вызван конструктор копирования банковского счёта" << endl;
	}

	~BrassAccount()
	{
		cout << "Вызван деструктор банковского счёа" << endl;
	};

	void setFullName(string fullName);
	void setNumberAccount(long int numberAccount);
	void setBalance(double balance);

	string getFullName();
	long int getNumberAccount();
	double getBalance();

	void showFullName();
	void showNumberAccount();
	void showBalance();

	friend BrassAccount & operator + (BrassAccount &ob, double balance);//для пополнения баланса
	friend BrassAccount & operator - (BrassAccount &ob, double balance); //снятие наличных

	bool operator == (BrassAccount &ob1);


	void increaseBalance(double balance);

	void decreaseBalance(double balance);


};

