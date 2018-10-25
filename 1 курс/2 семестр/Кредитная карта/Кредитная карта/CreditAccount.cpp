#include "CreditAccount.h"

using namespace std;


void CreditAccount::percentReCount()
{
	if (balance_ < 0)
	{
		overdraft_ = balance_ * (percent_ / 100.0);
		balance_ += overdraft_;
	}
}

double CreditAccount::overdraft()
{
	maxOverdraft();
	return overdraft_;
}

double CreditAccount::maxOverdraft()
{
	cout << "Максимальная сумма перерасхода составляет: " << maxOverdraft_ << endl;
	return maxOverdraft_;
}