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
		cout << "������ ����������� ��� ���������� ��� ���������� �����" << endl;
	}

	CreditAccount(string fullName, long int numberAccount, double balance, double persent, double maxOverdraft) :
		BrassAccount(fullName, numberAccount, balance), percent_(persent), maxOverdraft_(maxOverdraft)
	{
		cout << "������ ����������� � ����������� ��� ���������� �����" << endl;
	}

	CreditAccount(const CreditAccount & ob)
	{
		percent_ = ob.percent_;
		overdraft_ = ob.overdraft_;
		maxOverdraft_ = ob.maxOverdraft_;
		cout << "������ ����������� ����������� ��� ���������� �����" << endl;
	}

	void percentReCount();

	double overdraft();

	double maxOverdraft();

	~CreditAccount()
	{
		cout << "������ ���������� ���������� �����" << endl;
	}
};