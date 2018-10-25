#include "BrassAccount.h"

using namespace std;


class CreditAccount : public BrassAccount
{
private:
	double percent_;
	double overdraft_;
	double maxOverdraft_;

public:
	CreditAccount() : BrassAccount()
	{
		cout << "Вызван конструктор без параметров для кредитного счёта" << endl;
	}

	CreditAccount(string fullName, long int numberAccount, double balance, double persent, double maxOverdraft) :
		BrassAccount(fullName, numberAccount, balance), percent_(persent), maxOverdraft_(maxOverdraft)
	{
		cout << "Вызван конструктор с параметрами для кредитного счёта" << endl;
	}

	CreditAccount(const CreditAccount & ob)
	{
		percent_ = ob.percent_;
		overdraft_ = ob.overdraft_;
		maxOverdraft_ = ob.maxOverdraft_;
		cout << "Вызван конструктор копирования для кредитного счёта" << endl;
	}

	void percentReCount();

	double overdraft();

	double maxOverdraft();

	~CreditAccount()
	{
		cout << "Вызван деструктор кредитного счёта" << endl;
	}
};