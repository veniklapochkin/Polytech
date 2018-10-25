#ifndef _LONG_INT
#define _LONG_INT

#include <iostream>
#include <string>   
#include <cmath>
#include <algorithm>
#include <cmath>
#include <list>
#include <cstdlib>
#include <ctime>
#include <bitset>

using namespace std;
class longInt
{
public:
	static const long int osn_ = 1000000000; //1000000000
	static const int max_ = 100;
	long int *coef_;
	int dig_ = 9;
	int num_;
	bool zn_;

	void input();
	void output();

	longInt();
	longInt(int N);
	longInt(long int N);
	longInt(long long int N);
	longInt(longInt& A);
	~longInt();

	longInt operator = (longInt& ob);
	longInt operator = (int ob);
	longInt operator = (long int ob);
	longInt operator = (long long int ob);

	bool operator < (longInt& ob);
	bool operator < (long int& ob);
	bool operator < (long long int& ob);
	bool operator > (longInt& ob);
	bool operator > (long int& ob);
	bool operator > (long long int& ob);
	bool operator == (longInt& ob);
	bool operator == (long int& ob);
	bool operator == (long long int& ob);
	bool operator != (longInt& ob);
	bool operator != (long int& ob);
	bool operator != (long long int& ob);
	bool operator <= (longInt& ob);
	bool operator <= (long int& ob);
	bool operator <= (long long int& ob);
	bool operator >= (longInt& ob);
	bool operator >= (long int& ob);
	bool operator >= (long long int& ob);


	longInt operator + (longInt& ob);
	longInt operator + (long int& ob);
	longInt operator + (long long int& ob);
	longInt operator - (longInt& ob);
	longInt operator - (long int& ob);
	longInt operator - (long long int& ob);
	void vich(longInt& a, longInt& b);
	longInt operator * (longInt& ob);
	longInt operator * (int& ob);
	longInt operator * (long int& ob);
	longInt operator * (long long int& ob);
	longInt operator / (longInt& ob);
	longInt operator / (int& ob);
	longInt operator / (long int& ob);
	longInt operator / (long long int& ob);
	longInt operator %  (longInt& ob);
	longInt operator %  (int& ob);
	longInt operator %  (long int& ob);
	longInt operator %  (long long int& ob);


	longInt mod(longInt &b);
	longInt mod(int &b);
	longInt mod(long int &b);
	longInt mod(long long int &b);
	longInt gcd(longInt &ob);
	longInt powLI(longInt &b);
	longInt powMod(longInt &st, longInt &x);
	longInt binpow(longInt n);

	longInt power(longInt& nq);
	longInt power(long long n);
	longInt power(long n);
	longInt power(int n);

	void randomLI(long int n);
	bool isZero();
	void setToZero();

	long long sumL();

};

#endif