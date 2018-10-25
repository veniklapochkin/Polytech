#include "longInt.h"

longInt::longInt()
{

	num_ = 1;
	coef_ = new long int[max_];
	for (int i = 0; i < max_; i++)
		coef_[i] = 0;
	zn_ = 0;

	long int osntemp = osn_;
	//int kol;
	//for (kol = 0; osntemp != 0; kol++)
	//	osntemp = osntemp / 10;
	//kol--;
	//dig_ = kol;
}
longInt::longInt(int n)
{
	//long int osntemp = osn_;
	//int kol;
	//for (kol = 0; osntemp != 0; kol++)
	//	osntemp = osntemp / 10;
	//kol--;
	//dig_ = kol;

	coef_ = new long int[max_];
	for (int i = 0; i < max_; i++)
		coef_[i] = 0;
	if (n == 0)
	{
		coef_[0] = 0;
		num_ = 1;
		zn_ = 0;
		return;
	}
	if (n < 0)
	{
		zn_ = 1;
		n = 0 - n;
	}
	else
		zn_ = 0;

	int pos = 0;
	while (n >= osn_)
	{
		num_++;
		coef_[pos++] = n % osn_;
		n = n / osn_;
	}
	if (n != 0)
	{
		coef_[pos] = n;
		num_++;
	}
}
longInt::longInt(long int n)
{

	long int osntemp = osn_;
	int kol;
	for (kol = 0; osntemp != 0; kol++)
		osntemp = osntemp / 10;
	kol--;
	dig_ = kol;

	coef_ = new long int[max_];
	for (int i = 0; i < max_; i++)
		coef_[i] = 0;
	if (n == 0)
	{
		coef_[0] = 0;
		num_ = 1;
		zn_ = 0;
		return;
	}
	if (n < 0)
	{
		zn_ = 1;
		n = 0 - n;
	}
	else
		zn_ = 0;

	int pos = 0;
	while (n >= osn_)
	{
		num_++;
		coef_[pos++] = n % osn_;
		n = n / osn_;
	}
	if (n != 0)
	{
		coef_[pos] = n;
		num_++;
	}
}
longInt::longInt(long long int n)
{

	long int osntemp = osn_;
	int kol;
	for (kol = 0; osntemp != 0; kol++)
		osntemp = osntemp / 10;
	kol--;
	dig_ = kol;

	coef_ = new long int[max_];
	for (int i = 0; i < max_; i++)
		coef_[i] = 0;
	if (n == 0)
	{
		coef_[0] = 0;
		num_ = 1;
		zn_ = 0;
		return;
	}
	if (n < 0)
	{
		zn_ = 1;
		n = 0 - n;
	}
	else
		zn_ = 0;

	int pos = 0;
	while (n >= (long long int)osn_)
	{
		num_++;
		coef_[pos++] = n % osn_;
		n = n / osn_;
	}
	if (n != 0)
	{
		coef_[pos] = n;
		num_++;
	}
}
longInt::longInt(longInt &A)
{
	coef_ = new long[max_];
	for (int i = 0; i < max_; i++)
		coef_[i] = 0;

	num_ = A.num_;
	zn_ = A.zn_;

	for (int l = 0; l < A.num_; l++)
		coef_[l] = A.coef_[l];
}
longInt::~longInt()
{
	if (coef_)
		delete[] coef_;
}

longInt longInt::operator = (longInt &A)
{
	if (*this == A)
		return *this;

	if (num_ < A.num_)
	{
		delete coef_;
		coef_ = new long int[max_];
		for (int i = 0; i < max_; i++)
			coef_[i] = 0;
		num_ = A.num_;
	}
	else
	{
		for (int i = 0; i < num_; i++)
			coef_[i] = 0;
		num_ = A.num_;
	}
	for (int i = 0; i < A.num_; i++)
		coef_[i] = A.coef_[i];
	zn_ = A.zn_;
	dig_ = A.dig_;
	return *this;
}
longInt longInt::operator = (int n)
{
	for (int i = 0; i < max_; i++)
		coef_[i] = 0;
	num_ = 0;
	if (n == 0)
	{
		coef_[0] = 0;
		num_ = 1;
		zn_ = 0;
		return *this;
	}
	if (n < 0)
	{
		zn_ = 1;
		n = 0 - n;
	}
	else
		zn_ = 0;
	int pos = 0;
	while (n >= osn_)
	{
		num_++;
		coef_[pos++] = n % osn_;
		n = n / osn_;
	}
	if (n != 0)
	{
		coef_[pos] = n;
		num_++;
	}
	return *this;
}
longInt longInt::operator = (long int n)
{
	for (int i = 0; i < max_; i++)
		coef_[i] = 0;
	num_ = 0;
	if (n == 0)
	{
		coef_[0] = 0;
		num_ = 1;
		zn_ = 0;
		return *this;
	}
	if (n < 0)
	{
		zn_ = 1;
		n = 0 - n;
	}
	else
		zn_ = 0;
	int pos = 0;
	while (n >= osn_)
	{
		num_++;
		coef_[pos++] = n % osn_;
		n = n / osn_;
	}
	if (n != 0)
	{
		coef_[pos] = n;
		num_++;
	}
	return *this;
}
longInt longInt::operator = (long long int n)
{
	for (int i = 0; i < max_; i++)
		coef_[i] = 0;
	num_ = 0;
	if (n == 0)
	{
		coef_[0] = 0;
		num_ = 1;
		zn_ = 0;
		return *this;
	}
	if (n < 0)
	{
		zn_ = 1;
		n = 0 - n;
	}
	else
		zn_ = 0;
	int pos = 0;
	while (n >= osn_)
	{
		num_++;
		coef_[pos++] = n % osn_;
		n = n / osn_;
	}
	if (n != 0)
	{
		coef_[pos] = n;
		num_++;
	}
	return *this;
}

void longInt::output()
{
	if (zn_)
		cout << "-";

	long int temp = osn_;

	string digitFormat = "%.";
	digitFormat += to_string(dig_) + 'd';
	cout << coef_[num_ - 1];
	if (num_ > 1);
	{
		for (int i = num_ - 2; i >= 0; i--)
		{
			printf(digitFormat.c_str(), coef_[i]);
		}
	}
	cout << endl;
}
void longInt::input()
{
	string str;
	int pos = 0;
	cin >> str;

	int q;
	if (str[0] == '-')
	{
		zn_ = 1;
		q = 1;
		num_ = str.length() - 1;
	}
	else
	if (str[0] == '+')
	{
		zn_ = 0;
		q = 1;
		num_ = str.length() - 1;
	}
	else
	if (isdigit(str[0]))
	{
		zn_ = 0;
		q = 0;
		num_ = str.length();
	}
	else
	{
		cerr << "Error: incorrect input value. \n";
		system("pause");
		exit(0);
	}

	int start;
	for (int i = str.size() - 1; i >= q; i -= dig_)
	{
		start = i - dig_ + 1;
		if (start<q) start = q;
		string dig = str.substr(start, i - start + 1);
		coef_[pos++] = atoi(dig.c_str());
	}
	num_ = pos;
}


bool longInt::operator < (longInt &ob)
{
	bool negFlag;
	if ((zn_ == false) && (ob.zn_ == true))
		return false;
	if ((zn_ == true) && (ob.zn_ == false))
		return true;
	if ((zn_ == false) && (ob.zn_ == false))
		negFlag = true;
	else
		negFlag = false;

	if (negFlag)
	{
		if (num_ < ob.num_)
			return true;
		if (num_>ob.num_)
			return false;
	}
	else
	{
		if (num_ < ob.num_)
			return false;
		if (num_>ob.num_)
			return true;

	}
	if (negFlag)
	{
		for (int i = num_ - 1; i >= 0; i--)
		{
			if (coef_[i] != ob.coef_[i])
				return coef_[i] < ob.coef_[i];
		}
	}
	else
	{
		for (int i = num_ - 1; i >= 0; i--)
		{
			if (coef_[i] != ob.coef_[i])
				return ob.coef_[i] < coef_[i];
		}
	}
	return false;
}
bool longInt::operator < (long int &ob)
{
	longInt a(ob);
	return *this<a;
}
bool longInt::operator < (long long int &ob)
{
	longInt a(ob);
	return *this<a;
}
bool longInt::operator > (longInt &ob)
{
	return(ob < *this);
}
bool longInt::operator >(long int &ob)
{
	longInt a(ob);
	return *this>a;
}
bool longInt::operator > (long long int &ob)
{
	longInt a(ob);
	return *this>a;
}
bool longInt::operator ==(longInt &ob)
{
	if (zn_ != ob.zn_)
		return 0;
	if (num_ != ob.num_)
		return 0;
	for (int i = 0; i < num_; i++)
	if (coef_[i] != ob.coef_[i])
		return false;
	return true;
}
bool longInt::operator ==(long int &ob)
{
	longInt a(ob);
	return *this == a;
}
bool longInt::operator ==(long long int &ob)
{
	longInt a(ob);
	return *this == a;
}
bool longInt::operator !=(longInt &ob)
{
	return (!(*this == ob));
}
bool longInt::operator !=(long int &ob)
{
	longInt a(ob);
	return *this != a;
}
bool longInt::operator !=(long long int &ob)
{
	longInt a(ob);
	return *this != a;
}
bool longInt::operator <= (longInt& ob)
{
	return ((*this<ob) || (*this == ob));
}
bool longInt::operator <=(long int &ob)
{
	longInt a(ob);
	return *this <= a;
}
bool longInt::operator <=(long long int &ob)
{
	longInt a(ob);
	return *this <= a;
}
bool longInt::operator >= (longInt& ob)
{
	return ((*this>ob) || (*this == ob));
}
bool longInt::operator >=(long int &ob)
{
	longInt a(ob);
	return *this >= a;
}
bool longInt::operator >=(long long int &ob)
{
	longInt a(ob);
	return *this >= a;
}


longInt longInt::operator + (longInt& b)
{
	long int carry = 0;
	longInt c;
	if (zn_ == b.zn_)
	{
		int size = max(num_, b.num_);
		c.num_ = size;
		int i;
		for (i = 0; i < size || carry; i++)
		{
			c.coef_[i] = coef_[i] + carry + b.coef_[i];
			if (c.coef_[i] >= osn_)
			{
				c.coef_[i] -= osn_;
				carry = 1;
			}
			else
				carry = 0;
			//cout << carry<<endl;
			//c.output();
		}
		if (c.coef_[c.num_])
			c.num_++;
		c.zn_ = zn_;
		return c;
	}
	else
	{
		if ((zn_) && !(b.zn_))
		{
			c = *this;
			c.zn_ = 0;
			if (c > b)
			{
				c = c - b;
				c.zn_ = 1;
				return c;
			}
			else
			{
				return (b - c);
			}
		}
		if (!(zn_) && (b.zn_))
		{
			c = b;
			c.zn_ = 0;
			if (*this > c)
			{
				return (*this - c);
			}
			else
			{
				c = c - *this;
				c.zn_ = 1;
				return c;

			}
		}
	}
}
longInt longInt::operator + (long int& ob)
{
	longInt a(ob);
	return *this + a;
}
longInt longInt::operator + (long long int& ob)
{
	longInt a(ob);
	return *this + a;
}
longInt longInt::operator - (longInt& ob)
{
	longInt res;
	if (*this == ob)
	{
		return res;
	}
	if (zn_ == ob.zn_)
	{
		if (zn_)
		{
			if (*this > ob)
			{
				res = ob;
				vich(res, *this);
				res.zn_ = 0;
				return res;
			}
			else
			{
				res = *this;
				vich(res, ob);
				return res;
			}
		}
		else
		{
			if (*this > ob)
			{
				res = *this;
				vich(res, ob);
				return res;
			}
			else
			{

				res = ob;
				vich(res, *this);
				res.zn_ = 1;
				return res;
			}
		}
	}
	else
	{
		if (zn_)
		{
			res = ob;
			res.zn_ = 1;
			return(*this + res);
		}
		else
		{
			res = ob;
			res.zn_ = 0;
			return(*this + res);
		}
	}
}
longInt longInt::operator - (long int& ob)
{
	longInt a(ob);
	return *this - a;
}
longInt longInt::operator - (long long int& ob)
{
	longInt a(ob);
	return *this - a;
}
void longInt::vich(longInt& a, longInt& b)
{
	for (int i = 0; i < a.num_; i++)
	{
		a.coef_[i] -= b.coef_[i];
		if (a.coef_[i] < 0)
		{
			a.coef_[i] += osn_;
			a.coef_[i + 1]--;
		}
	}
	int pos = a.num_;
	while ((pos) && !(a.coef_[pos]))
		pos--;
	a.num_ = pos + 1;
}

longInt longInt::operator * (longInt& ob)
{
	longInt c;
	if ((this->isZero()) || (ob.isZero()))
	{
		c.setToZero();
		return c;
	}

	int j, i;
	long long int carry, temp;
	for (i = 0; i < num_; i++)
	{
		carry = 0;
		for (j = 0; j < ob.num_; j++)
		{
			temp = (long long int)coef_[i] * (long long int)ob.coef_[j] + (long long int)c.coef_[i + j] + (long long int)carry;
			carry = temp / osn_;
			c.coef_[i + j] = temp - carry*osn_;
		}
		c.coef_[i + j] = carry;
	}
	i = num_ + ob.num_ - 1;
	if (c.coef_[i] == 0) i--;
	c.num_ = i + 1;
	if (zn_ != ob.zn_)
		c.zn_ = 1;
	if (c.isZero())
		c.zn_ = 0;
	return c;
}
longInt longInt::operator * (int& ob)
{
	longInt temp(ob);
	return (*this*temp);
}
longInt longInt::operator * (long int& ob)
{
	longInt temp(ob);
	return (*this*temp);
}
longInt longInt::operator * (long long int& ob)
{
	longInt temp(ob);
	return (*this*temp);
}
//longInt longInt::operator / (longInt& ob)
//{
//	longInt u, v;
//	long int qwe = osn_;
//	u = *this, v = ob;
//	u.zn_ = 0; v.zn_ = 0;
//
//
//	if (u < v)
//	{
//		longInt zer;
//		return  zer;
//	}
//
//	if (ob.isZero())
//	{
//		cout << "Division by zero.";
//		longInt zer;
//		return  zer;
//	}
//
//	//if (ob.num_ == 1)
//	//{
//	//	return *this / ob.coef_[0];
//	//}
//	//if ((ob.coef_[0] / 10 == 0) && (ob.num_ == 1) && (ob.coef_[0] % 10 == 2))
//	//{
//	//	long int a = ob.coef_[0];
//	//	return *this / a;
//	//}
//
//	int n = v.num_;
//	int m = u.num_ - v.num_;
//
//	/*long int *tempArray;
//	tempArray = new long int[m + 1];
//	tempArray[m] = 1;
//*/
//	longInt q; //результат q итое
//	q.num_--;
//
//	//Нормализация
//	long int d = (osn_ / (v.coef_[n - 1] + 1));
//	u = u * d;
//	v = v * d;
//	if (d == 1)
//	{
//		u.num_++;
//	}
//	long int j = m;
//	//Главный цикл
//	while (j >= 0)
//	{
//		//q верменное
//		long long int cur = (long long int)((long int)(u.coef_[j + n]) * (long int)(osn_)+(long int)u.coef_[j + n - 1]);
//		//cout << cur << endl;
//		long long int tempq = (long long int)((long long int)cur / (long long int)v.coef_[n - 1]);
//		//cout << tempq << endl<<endl;
//
//		//cout << tempq << endl;
//		//cout << v.coef_[n - 1] << endl;
//		long long int tempr = (long long int)((long long int)cur % (long long int)v.coef_[n - 1]);
//		//cout << tempr << endl;
//		//cout  << endl;
//
//		do
//		{
//			if (tempq == (long long int)osn_ || tempq * (long long int)v.coef_[n - 2] > (long long int)osn_ * tempr + (long long int)u.coef_[j + n - 2])
//			{
//				tempq--;
//				tempr += (long long int)v.coef_[n - 1];
//
//			}
//			else
//			{
//				break;
//			}
//		} while (tempr < osn_);
//		//Умножить и вычесть
//
//		longInt u2;
//		int pos = 0;
//		for (int i = j; i < (j + n + 1); i++)
//		{
//			u2.coef_[pos++] = u.coef_[i];
//		}
//		int pr;
//		//u2.output();
//		for (pr = pos + 1; pr >= 0; pr--)
//		{
//			if (u2.coef_[pr] != 0)
//				break;
//		}
//		u2.num_ = pr + 1;
//		u2 = u2 - (v*tempq);
//
//		bool flag = false;
//
//
//		//u2.output();
//		if (u2.zn_)//если отрицательные
//		{
//			longInt btemp1(1);
//			for (int k = 0; k < n + 1; k++)
//			{
//				btemp1 = btemp1 * qwe;
//			}
//			//btemp1.output();
//			u2 = u2 + btemp1;
//			//u2.output();
//			flag = true;
//		}
//		//u2.output();
//		//cout<<tempq << endl;
//		//Проверка остатка
//		q.coef_[j] = tempq;
//		q.num_++;
//		//q.output();
//		if (flag)
//		{
//			//Компенсировать сложение
//			q.coef_[j]--;
//			u2 = u2 + v;
//			if (u2.coef_[n + j + 1])
//			{
//				u2.num_--;
//			}
//			u2.coef_[n + j + 1] = 0;
//			flag = false;
//
//		}
//		//cout << q.coef_[j]<<endl;
//		//q.output();
//		//u2.output();
//		//вычитание из u
//		int h;
//		for (h = j; h < j + n + 1; h++)
//		{
//			if (h - j >= u2.num_)
//			{
//				u.coef_[h] = 0;
//				u.num_--;
//			}
//			else
//			{
//				u.coef_[h] = u2.coef_[h - j];
//			}
//		}
//		//u.output();
//		int pr2;
//		for (pr2 = u.num_ + 1; pr2 >= 0; pr2--)
//		{
//			if (u.coef_[pr2] != 0)
//				break;
//		}
//		u.num_ = pr2 + 1;
//		//u.output();
//		j--;
//	}
//
//	if (q.coef_[m] == 0)
//	{
//		q.coef_[m] = 0;
//		q.num_--;
//	}
//
//	if (zn_ == ob.zn_)
//		return q;
//	q.zn_ = 1;
//	return q;
//}

longInt longInt::operator / (longInt& ob)
{
	// ini
	longInt u = *this;
	longInt v = ob;
	u.zn_ = v.zn_ = 0;
	if (v > u)
	{
		u.setToZero();
		return u;
	}
	if (ob.isZero())
	{
		cout << "Error: Div by zero";
	}
	if (isZero())
	{
		u.setToZero();
		return u;
	}
	int n = v.num_;
	if (n == 1)
	{
		if (ob.zn_ == 1)
		{
			long int qwe = -v.coef_[0];
			return *this / qwe;
		}
		else
		{
			long int qwe = v.coef_[0];
			return *this / qwe;
		}
	}
	int m = u.num_ - v.num_;
	longInt q;
	//norm
	long int d = osn_ / (v.coef_[n - 1] + 1);
	u = u*d;
	v = v*d;
	if (d == 1)
	{
		u.coef_[m + n] = 0;
		u.num_++;
	}

	//nach ust
	int j = m;
	longInt osn(osn_);
	longInt ed(1);
	while (j >= 0)
	{
		long long cur = (long long)u.coef_[j + n] * (long long)osn_ + (long long)u.coef_[j + n - 1];
		long long tempql = cur / (long long)v.coef_[n - 1];
		longInt tempq(tempql);
		long long temprl = cur % (long long)v.coef_[n - 1];
		longInt tempr(temprl);
		do
		{
			longInt B = tempq * v.coef_[n - 2];
			longInt S = osn * tempr + u.coef_[j + n - 2];
			if ((tempq == osn) || B > S)
			{
				tempq = tempq - ed;
				tempr = tempr + v.coef_[n - 1];
			}
			else
				break;
		} while (tempr < osn);

		//u.output();
		//v.output();
		//tempq.output();

		//umn i vich
		longInt u2;
		int pos = 0;
		for (int i = j; i < (j + n + 1); i++)
		{
			u2.coef_[pos++] = u.coef_[i];
		}
		int pr;
		//u2.output();
		for (pr = pos + 1; pr >= 0; pr--)
		{
			if (u2.coef_[pr] != 0)
				break;
		}
		u2.num_ = pr + 1;
		u2 = u2 - (v*tempq);
		//u2.output();
		bool flag = false;

		if (u2.zn_)//если отрицательные
		{
			longInt btemp1(1);
			for (int k = 0; k < n + 1; k++)
			{
				btemp1 = btemp1 * osn;
			}
			u2 = u2 + btemp1;
			flag = true;
		}
		//u2.output();
		q.coef_[j] = tempq.coef_[0];
		if (flag)
		{
			//Компенсировать сложение
			q.coef_[j]--;
			longInt vt = v;
			vt.num_++;
			int ud = u2.num_;
			u2 = u2 + vt;
			if (u2.coef_[ud] != 0)
				u2.coef_[ud] = 0;
			u2.num_ = ud;
			flag = false;
		}

		//u2.output();
		int h;
		for (h = j; h < j + n + 1; h++)
		{
			if (h - j >= u2.num_)
			{
				u.coef_[h] = 0;
				u.num_--;
			}
			else
			{
				u.coef_[h] = u2.coef_[h - j];
			}
		}

		int pr2;
		for (pr2 = u.num_ + 1; pr2 >= 0; pr2--)
		{
			if (u.coef_[pr2] != 0)
				break;
		}
		u.num_ = pr2 + 1;
		//u.output();

		j--;
	}

	int mb = this->num_;
	while (q.coef_[mb] == 0)
	{
		mb--;
	}
	q.num_ = mb + 1;
	if (zn_ == ob.zn_)
		q.zn_ = 0;
	else
		q.zn_ = 1;
	return q;
}
longInt longInt::operator / (int& b)
{
	long int ob = (long)b;
	return *this / ob;
}
longInt longInt::operator / (long int& ob)
{
	long int temp = abs(ob);
	longInt u = *this;
	u.zn_ = 0;
	if (*this < ob)
	{
		u.setToZero();
		return u;
	}
	if (ob == 0)
	{
		cout << "Error: Division by zero";
	}
	if (isZero())
	{
		u.setToZero();
		return u;
	}
	longInt res;
	long int r = 0;//остаток
	int j = num_ - 1;
	while (j >= 0)
	{
		long long cur = (long long)(r)* (long long)(osn_)+u.coef_[j];
		res.coef_[j] = (long)(cur / temp);
		r = (long)(cur % temp);
		j--;
	}
	int pos = num_;
	while (res.coef_[pos] == 0)
	{
		pos--;
	}
	res.num_ = pos + 1;
	if (ob < 0)
	{
		if (zn_)
		{
			res.zn_ = 0;
		}
		else
		{
			res.zn_ = 1;
		}
	}
	else
	{
		if (zn_)
		{
			res.zn_ = 1;
		}
		else
		{
			res.zn_ = 0;
		}
	}
	return res;
}
longInt longInt::operator / (long long int& ob)
{
	longInt a(ob);
	return *this / ob;
}

longInt longInt::operator %  (longInt& ob)
{
	longInt a, b, c;
	a = *this; b = ob;

	a.zn_ = b.zn_ = 0;

	if (a >= b)
	{
		c = a / b;
		a = a - (b*c);
		if (zn_ == ob.zn_)
			return a;
		else
		{
			a.zn_ = 1;
			return a;
		}
	}
	else
	if (zn_ == ob.zn_)
		return *this;
	else
	{
		a.zn_ = 1;
		return a;
	}
}
longInt longInt::operator %  (int& ob)
{
	longInt a(ob);
	return *this%a;
}
longInt longInt::operator %  (long int& ob)
{
	longInt a(ob);
	return *this%a;
}
longInt longInt::operator %  (long long int& ob)
{
	longInt a(ob);
	return *this%a;
}


longInt longInt::mod(longInt &b)
{
	longInt temp = *this%b;
	if (zn_ == b.zn_)
	{
		if (zn_ == 0)
		{
			return temp;
		}
		else
		{
			temp.zn_ = 1;
			return temp;
		}
	}

	if (zn_ == 1)
	{
		return b + temp;
	}
	else
	{
		temp = temp - b;
		temp.zn_ = 1;
		return temp;
	}
}
longInt longInt::mod(int &b)
{
	longInt temp(b);
	return *this / temp;
}
longInt longInt::mod(long int &b)
{
	longInt temp(b);
	return *this / temp;
}
longInt longInt::mod(long long int &b)
{
	longInt temp(b);
	return *this / temp;
}

longInt longInt::power(longInt &nq)
{
	if (nq.isZero())
	{
		longInt ed(1);
		return ed;
	}
	if (nq.zn_ == 1)
	{
		cout << "Error: power is not natural ";
		exit(0);
	}
	longInt ed(1);
	if (*this == ed)
	{
		return *this;
	}
	if (isZero())
	{
		longInt zr(0);
		return zr;
	}
	if (nq.num_ < 3)
	{
		long long int n = (long long int)nq.osn_*(long long int)nq.coef_[1] + (long long int)nq.coef_[0];
		if (nq.zn_ == 1)
			n = 0 - n;
		return this->power(n);
	}

	longInt result(1);
	longInt it(*this);
	it.zn_ = 0;
	longInt nqt(nq);
	longInt temp;
	longInt dv(2);

	while (!nqt.isZero())
	{
		temp = nqt % dv;
		if (!temp.isZero())
		{
			result = result * it;
			nqt = nqt - ed;
		}
		it = it*it;
		nqt = nqt / dv;
	}

	if (zn_ == 1)
	if ((nq % dv).isZero())
		result.zn_ = 0;
	else
		result.zn_ = 1;
	return result;
}
longInt longInt::power(long long int on)
{
	long long int n = (long long)on;
	if (n == 0)
	{
		longInt ed(1);
		return ed;
	}
	if (n < 0)
	{
		cout << "Error: power is not natural ";
		exit(0);
	}
	longInt ed(1);
	if (*this == ed)
	{
		return *this;
	}
	if (isZero())
	{
		longInt zr(0);
		return zr;
	}
	longInt result(1);
	longInt it(*this);
	it.zn_ = 0;
	while (n != 0)
	{
		if (n % 2 != 0)
		{
			result = result * it;
			n -= 1;
		}
		it = it*it;
		n /= 2;
	}
	if (zn_ == 1)
	if (on % 2 == 0)
		result.zn_ = 0;
	else
		result.zn_ = 1;
	return result;
}
longInt longInt::power(long on)
{
	long n = on;
	if (n == 0)
	{
		longInt ed(1);
		return ed;
	}
	if (n < 0)
	{
		cout << "Error: power is not natural ";
		exit(0);
	}
	longInt ed(1);
	if (*this == ed)
	{
		return *this;
	}
	if (isZero())
	{
		longInt zr(0);
		return zr;
	}
	longInt result(1);
	longInt it(*this);
	it.zn_ = 0;
	while (n != 0)
	{
		if (n % 2 != 0)
		{
			result = result * it;
			n -= 1;
		}
		it = it*it;
		n /= 2;
	}
	if (zn_ == 1)
	if (on % 2 == 0)
		result.zn_ = 0;
	else
		result.zn_ = 1;
	return result;
}
longInt longInt::power(int on)
{
	int n = on;
	if (n == 0)
	{
		longInt ed(1);
		return ed;
	}
	if (n < 0)
	{
		cout << "Error: power is not natural ";
		exit(0);
	}
	longInt ed(1);
	if (*this == ed)
	{
		return *this;
	}
	if (isZero())
	{
		longInt zr(0);
		return zr;
	}
	longInt result(1);
	longInt it(*this);
	it.zn_ = 0;
	while (n != 0)
	{
		if (n % 2 != 0)
		{
			result = result * it;
			n -= 1;
		}
		it = it*it;
		n /= 2;
	}
	if (zn_ == 1)
	if (on % 2 == 0)
		result.zn_ = 0;
	else
		result.zn_ = 1;
	return result;
}

long long longInt::sumL()
{
	long long a = 0, b;
	for (int i = 0; i < num_; i++)
	{
		b = (long long)coef_[i];
		for (int j = 0; j < dig_; j++)
		{
			a = a + b % 10;
			b = b / 10;
		}
	}
	return a;
}

longInt longInt::gcd(longInt &ob)
{
	longInt u;
	longInt v;
	u = *this;
	v = ob;
	u.zn_ = 0;
	v.zn_ = 0;
	if (v.isZero())
	{
		return u;
	}
	if (u.isZero())
	{
		return v;
	}
	if ((u.num_ < 3) && (v.num_ < 3))
	{
		long long int a = (long long)osn_*(long long)coef_[1] + (long long)coef_[0];
		long long int b = (long long)ob.osn_*(long long)ob.coef_[1] + (long long)ob.coef_[0];
		long long int c;
		while (a != 0)
		{
			c = a; a = b%a;  b = c;
		}
		longInt qw(b);
		return qw;
	}
	if (v.num_ < 3)
	{
		longInt temp = u.mod(v);
		long long int r = (long long)temp.osn_*(long long)temp.coef_[1] + (long long)temp.coef_[0];
		long long int u1 = (long long)v.osn_*(long long)v.coef_[1] + (long long)v.coef_[0];
		long long int v1 = r;
		while (v1 != 0)
		{
			r = u1%v1;
			u1 = v1;
			v1 = r;
		}
		longInt qw(u1);
		return qw;
	}
	if (u.num_ < 3)
	{
		longInt temp = v.mod(u);
		long long int r = (long long)temp.osn_*(long long)temp.coef_[1] + (long long)temp.coef_[0];
		long long int v1 = (long long)v.osn_*(long long)v.coef_[1] + (long long)v.coef_[0];
		long long int u1 = r;
		while (v1 != 0)
		{
			r = u1%v1;
			u1 = v1;
			v1 = r;
		}
		longInt qw(u1);
		return qw;
	}
	if (v > u)
	{
		longInt temp(u);
		u = v;
		v = temp;
	}

	long long ut = (long long)u.coef_[u.num_ - 1];
	long long vt = (long long)v.coef_[u.num_ - 1];
	long long ut1 = u.coef_[u.num_ - 2];
	long long vt1 = v.coef_[u.num_ - 2];;
	int *us; us = new int[dig_];
	int *vs; vs = new int[dig_];
	for (int i = 0; i < dig_; i++)
	{
		us[i] = ut1 % 10;
		vs[i] = vt1 % 10;
		ut1 = ut1 / 10;
		vt1 = vt1 / 10;
	}
	int pos = dig_ - 1;
	while (ut < osn_)
	{
		ut = 10 * ut + us[pos];
		vt = 10 * vt + vs[pos];
		pos--;
	}
	ut /= 10;
	vt /= 10;
	//cout << ut << endl << vt << endl;

	long long A = 1, B = 0, C = 0, D = 1, T, q;

	do
	{
		bool flag = 0;
		if (((vt + C) == 0) || ((vt + D) == 0))
		{
			flag = 1;
		}
		if (!flag)
		{
			q = (ut + A) / (vt + C);
			if (q != (ut + B) / (vt + D))
				flag = 1;
		}
		if (flag)
		{
			if (B == 0)
			{
				longInt t;
				t = u.mod(v);
				u = v;
				v = t;
			}
			else
			{
				longInt t, w;
				t = u * A;
				t = (v * B) + t;
				w = u * C;
				w = (v * D) + w;
				u = t;
				v = w;
			}
			return (u.gcd(v));
		}
		T = A - q * C;
		A = C;
		C = T;
		T = B - q * D;
		B = D;
		D = T;
		T = ut - q * vt;
		ut = vt;
		vt = T;
	} while (true);
}
longInt longInt::powMod(longInt &st, longInt &x)
{
	longInt res = *this;
	longInt ed(1);
	longInt dv(2);
	longInt step = st;
	longInt temp(1);
	while (step > ed)
	{
		if ((step.coef_[0] % 2 == 0)/* && (!step.isZero())*/)
		{
			res = res.power(dv);
			res = res.mod(x);
			step = step / dv;
		}
		else
		{
			temp = (temp*res).mod(x);
			res = (res.power(dv)).mod(x);
			step = step - ed;
			step = step / dv;
		}
	}
	res = (temp*res).mod(x);
	return res;
}


void longInt::setToZero()
{
	delete coef_;
	coef_ = new long int[max_];
	for (int i = 0; i < max_; i++)
		coef_[i] = 0;
	num_ = 1;
	zn_ = 0;
}
bool longInt::isZero()
{
	if ((num_ == 1) && (coef_[0] == 0))
	{
		zn_ = 0;
		return true;
	}
	return false;
}

