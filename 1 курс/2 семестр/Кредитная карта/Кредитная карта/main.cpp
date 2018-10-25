#include "CreditAccount.h"

int main()
{
	setlocale(LC_ALL, "Russian");

	CreditAccount c("123", 132, 50000, 1, 10);

	double a = 0;
	cout << "¬ведите сумму, которую хотите сн€ть " << endl;
	cin >> a;
	c.decreaseBalance(a);
	c.showBalance();

	double b = 0;
	cout << "¬ведите сумму, которую хотите зачислить " << endl;
	cin >> b;
	c.increaseBalance(b);
	c.showBalance();
	system("pause");
}