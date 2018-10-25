#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main()
{
	long double x, Fun2=0, eps;
	int znak, d=2, t=3;
	cout << "Enter x for 1/(1+x)^3: "; cin >> x;
	cout << "Enter eps for accuracy: "; cin >> eps;
	long double Fun = 1 / pow((1 + x), 3);
	for (int i = 1; (abs(Fun - (1+Fun2))) >= eps; i++,t++,d++){
		znak = pow(-1, i);
		Fun2 = Fun2 + znak*d*t / 2 * pow(x, i);
		cout << setw(10) << Fun << setw(10) << 1 + Fun2 << endl;
	}
	return 0;
}