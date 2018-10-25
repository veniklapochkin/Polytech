#ifndef BIGNUM_H_
#define BIGNUM_H_
#include <iostream>
#include <fstream>
#include <string>
#include <inttypes.h>
#include <bitset>
#include <iomanip>
#include <vector>
#include <math.h>
#include <algorithm>
#include <cassert>
#include <cstring> // strcmp, memcpy, memset
#include <ctime>
#define MEMORY_BLOCK 2
#define MAX_ULONG 18446744073709551615
#define MAX_UINT 4294967295

#ifndef NDEBUG
#   define ASSERT(condition, message) 
do {

if (!(condition)) {
	
	std::cerr << "Assertion `" condition "` failed in " << __FILE__ 
	<< " line " << __LINE__ << ": " << message << std::endl; 
} 
} while (false)
#else
#   define ASSERT(condition, message) do { } while (false)
#endif
using namespace std;
enum numSign {
	NEG, POS
};

class BigNum {
public:

	BigNum();  //+++
	BigNum(string num);  //+++
	BigNum(long num); //+++
	BigNum(const BigNum & copy);  //+++
	~BigNum();  //+++

	BigNum operator +(const BigNum & oper) const;//+++
	BigNum operator -(const BigNum & oper) const;//+++
	BigNum operator *(const BigNum & oper) const;//+++
	BigNum operator /(const BigNum & oper) const;//+++

	BigNum & operator =(const BigNum & oper); //+++

	friend BigNum & operator +=(BigNum & oper1, const BigNum & oper2);//+++
	friend BigNum & operator +=(BigNum & oper1, const unsigned int oper2); //+++
	friend BigNum & operator -=(BigNum & oper1, const BigNum & oper2);//+++
	friend BigNum & operator *=(BigNum & oper1, const BigNum & oper2);//+++
	friend BigNum & operator /=(BigNum & oper1, const BigNum & oper2);//+++
	friend BigNum & operator /=(BigNum & oper1, unsigned long oper2);//+++
	friend BigNum & operator >>=(BigNum & oper1, unsigned int oper2); //+++

	friend BigNum bnmod(BigNum & oper1, BigNum & mod);//+++
	friend BigNum bnmod(BigNum & oper1, unsigned long mod);//+++

	friend BigNum opposite(BigNum & oper1, BigNum & mod);
	friend BigNum opposite(BigNum & oper1, unsigned long mod);

	friend bool operator ==(const BigNum & oper1, const BigNum & oper2);//+++
	friend bool operator !=(const BigNum & oper1, const BigNum & oper2);//+++
	friend bool operator >(const BigNum & oper1, const BigNum & oper2);//+++
	friend bool operator >=(const BigNum & oper1, const BigNum & oper2);//+++
	friend bool operator <(const BigNum & oper1, const BigNum & oper2);//+++
	friend bool operator <=(const BigNum & oper1, const BigNum & oper2);//+++

	friend istream operator <<(istream & in, BigNum & oper);
	friend ostream operator >>(ostream & out, const BigNum & oper);

	BigNum bnpow(unsigned long oper, BigNum & mod);
	BigNum bnpow(BigNum & oper, BigNum & mod);
	BigNum bnpow(BigNum & oper); //+++
	BigNum bnpow(unsigned long oper); //+++

	unsigned int getSize() const;//+++
	unsigned int getMemorySize() const;  //+++
	unsigned int getBitSize() const;
	numSign getSign() const; //+++
	int64_t & getBlock(unsigned int num); // а надо?

	void giveMemory(); //+++
	void checkVal(); //+++



	void clean(); //+++
	void stringToBigNum(string num); //+++


	unsigned int * value; //TODO должен быть private

private:

	unsigned int realSize;
	numSign sign;
	unsigned int size;

};

BigNum bnmod(BigNum & oper, BigNum & mod){
	/*BigNum result(mod);
	result.clean();

	ulong n1 = oper1.getSize();
	ulong n = mod.getSize();

	for(int i = n - 1; i >= 0; i--){
	result.value[i] = oper1.value[i];
	}

	ulong d = ((ulong)MAX_UINT + 1) / ((ulong)mod.value[n - 1] + 1);

	result /= d;*/

	// TODO negative numbers. (look tests)

	BigNum temp(mod);
	BigNum oper1(oper);
	BigNum result(oper1);
	result.clean();

	//CRAZY
	if (oper1 == mod)
		return result;
	if (oper1 < mod && oper1.sign == POS){
		result = oper1;
		return result;
	}
	if (mod.sign == NEG){
		ASSERT(0, "NEGATIVE MOD");
		return BigNum(0);
	}
	//TODO костыль костылей. Аминь.
	if (1){
		if (oper1.sign == POS){
			return (oper1 - (oper1 / mod) * mod);
		}
		else {
			BigNum temp2(oper1);
			temp2.sign = POS;
			temp2 = (temp2 - (temp2 / mod) * mod);
			temp2 = mod - temp2;
			//temp2.realSize = temp2.getSize();
			return temp2;
		}
	}


	//		ulong n1 = oper1.getSize();
	//		ulong n = temp.getSize();
	//
	//		if(n == 0){
	//			//TODO нет обработки деления на ноль. Возвращаем делимое без изменений
	//			return oper1;
	//		}
	//		if(temp > oper1){
	//			oper1 = result;
	//			return oper1;
	//		}
	//
	//		ulong d = ((ulong)MAX_UINT + 1) / ((ulong)temp.value[n - 1] + 1);
	//
	//		BigNum D(d);
	//		oper1 *= D;
	//		temp *= D;
	//
	//		ulong q;
	//		ulong r;
	//		bool negFlag;
	//
	//		for(int j = n1 - n ; j >= 0; j--){
	//			q = ((ulong)oper1.value[j + n]*((ulong)MAX_UINT + 1) + (ulong)oper1.value[j + n - 1])
	//					/ ((ulong)temp.value[n - 1]);
	//			r = ((ulong)oper1.value[j + n]*((ulong)MAX_UINT + 1) + (ulong)oper1.value[j + n - 1])
	//					% ((ulong)temp.value[n - 1]);
	//
	//			if(n > 1){
	//				if( (q == ((ulong)MAX_UINT + 1)) || ((ulong)temp.value[n - 2])*q > ((ulong)MAX_UINT + 1)*r + (ulong)oper1.value[j + n - 2] ){
	//					q--;
	//					r += (ulong)temp.value[n - 1];
	//				}
	//				if((r < ((ulong)MAX_UINT + 1)) && ((ulong)temp.value[n - 2])*q > ((ulong)MAX_UINT + 1)*r + (ulong)oper1.value[j + n - 2] ){
	//					q--;
	//					r += (ulong)temp.value[n - 1];
	//				}
	//			}
	//
	//			BigNum Q(q);
	//			Q *= temp;
	//
	//			BigNum pieceOper1(oper1);
	//			for(int h = 0; h < j; h++){
	//				pieceOper1 >>= 32;
	//			}
	//			pieceOper1 -= Q;
	//
	//			if(pieceOper1.getSign() == NEG){
	//				cout << "LLLLLLLLLLLLLLLL" << endl;
	//				BigNum B(((ulong)MAX_UINT + 1));
	//				negFlag = true;
	//				pieceOper1 += B.bnpow(n+1);
	//			} else negFlag = false;
	//
	//			if(negFlag){
	//				q--;
	//				pieceOper1 += temp;
	//			}
	//
	//			for(int h = pieceOper1.getSize() - 1; h >= 0; h--){
	//				oper1.value[j + h] = pieceOper1.value[h];
	//			}
	//
	//			result.value[j] = q;
	//
	//		}
	//
	//		//oper1 = result;
	///////////////////////////////
	//	BigNum result2(mod);
	//	result2.clean();
	//
	//	for(int i = n - 1; i >= 0; i--){
	//		result2.value[i] = oper1.value[i];
	//	}
	//	//oper1.checkVal();
	//	//result2.checkVal();
	//	//cout << d << endl;
	//	result2 /= d;
	//	//result2.checkVal();
	//	//cout << d << endl;
	/////////////////////////////
	//	return result2;
	return NULL;
}

BigNum bnmod(BigNum & oper1, ulong mod){
	BigNum temp(mod);
	return bnmod(oper1, temp);
}

BigNum & operator /=(BigNum & oper1, const BigNum & oper2){
	BigNum temp(oper2);

	BigNum result(oper1);
	result.clean();

	if (oper1.sign == oper2.sign){
		result.sign = POS;
	}
	else {
		result.sign = NEG;
	}
	oper1.sign = POS;
	temp.sign = POS;

	ulong n1 = oper1.getSize();
	ulong n = temp.getSize();

	if (n == 0){
		return oper1;
	}
	if (temp > oper1){
		oper1 = result;
		return oper1;
	}

	ulong d = ((ulong)MAX_UINT + 1) / ((ulong)temp.value[n - 1] + 1);

	BigNum D(d);
	oper1 *= D;
	temp *= D;

	ulong q;
	ulong r;
	bool negFlag;

	for (int j = n1 - n; j >= 0; j--){
		q = ((ulong)oper1.value[j + n] * ((ulong)MAX_UINT + 1) + (ulong)oper1.value[j + n - 1])
			/ ((ulong)temp.value[n - 1]);
		r = ((ulong)oper1.value[j + n] * ((ulong)MAX_UINT + 1) + (ulong)oper1.value[j + n - 1])
			% ((ulong)temp.value[n - 1]);

		if (n > 1){
			if ((q == ((ulong)MAX_UINT + 1)) || ((ulong)temp.value[n - 2])*q > ((ulong)MAX_UINT + 1)*r + (ulong)oper1.value[j + n - 2]){
				q--;
				r += (ulong)temp.value[n - 1];
			}
			if ((r < ((ulong)MAX_UINT + 1)) && ((ulong)temp.value[n - 2])*q >((ulong)MAX_UINT + 1)*r + (ulong)oper1.value[j + n - 2]){
				q--;
				r += (ulong)temp.value[n - 1];
			}
		}

		BigNum Q(q);
		Q *= temp;

		BigNum pieceOper1(oper1);
		for (int h = 0; h < j; h++){
			pieceOper1 >>= 32;
		}
		pieceOper1 -= Q;

		if (pieceOper1.getSign() == NEG){
			cout << "LLLLLLLLLLLLLLLL" << endl;
			BigNum B(((ulong)MAX_UINT + 1));
			negFlag = true;
			pieceOper1 += B.bnpow(n + 1);
		}
		else negFlag = false;

		if (negFlag){
			q--;
			pieceOper1 += temp;
		}

		for (int h = pieceOper1.getSize() - 1; h >= 0; h--){
			oper1.value[j + h] = pieceOper1.value[h];
		}

		result.value[j] = q;

	}

	oper1 = result;
	return oper1;
}

BigNum & operator /=(BigNum & oper1, ulong oper2){
	BigNum temp(oper2);
	oper1 /= temp;
	return oper1;
}
BigNum & operator +=(BigNum & oper1, const BigNum & oper22){
	bool transfer = false;

	BigNum oper2(oper22);

	while (oper2.realSize >= oper1.getMemorySize()){
		oper1.giveMemory();
	}

	if (oper1.sign == oper2.sign){

		uint sz = oper2.realSize;
		for (uint i = 0; i < sz; i++){
			if (transfer == true){
				oper1.value[i]++;
				if (oper1.value[i] == 0)
					transfer = true;
				else
					transfer = false;
			}

			oper1.value[i] += oper2.value[i];
			if (oper1.value[i] < oper2.value[i])
				transfer = true;

		}
		while (transfer == true){
			if (sz == oper1.getMemorySize()){
				oper1.giveMemory();
			}
			oper1.value[sz]++;
			if (oper1.value[sz] == 0){
				transfer = true;
				sz++;
			}
			else transfer = false;
		}

	}
	else {
		numSign s = oper1.sign;
		oper1.sign = oper2.sign;

		BigNum temp1, temp2;
		if (oper2.sign == POS){
			if (oper1 > oper2){
				oper1.sign = s;
				temp1 = oper1;
				temp2 = oper2;
			}
			else {
				temp2 = oper1;
				temp1 = oper2;
			}
		}
		else {
			if (oper1 < oper2){
				oper1.sign = s;
				temp1 = oper1;
				temp2 = oper2;
			}
			else {
				temp2 = oper1;
				temp1 = oper2;
			}
		}

		if (oper1 == oper2){
			oper1.sign = POS;
		}

		uint sz = temp2.realSize;
		for (uint i = 0; i < sz; i++){

			if (transfer == true){
				temp1.value[i]--;
				if (temp1.value[i] == MAX_UINT)
					transfer = true;
				else
					transfer = false;
			}

			temp1.value[i] += (MAX_UINT - temp2.value[i]) + 1;

			if (temp1.value[i] >= (MAX_UINT - temp2.value[i]) + 1)
				transfer = true;

		}
		while (transfer == true){
			temp1.value[sz]--;

			if (temp1.value[sz] == MAX_UINT){
				transfer = true;
				sz++;
			}
			else transfer = false;
		}

		temp1.sign = oper1.sign;
		oper1 = temp1;
	}



	oper1.realSize = oper1.getSize();
	if (oper1.realSize == 0)
		oper1.sign = POS;

	return oper1;
}

BigNum & operator -=(BigNum & oper1, const BigNum & oper22){
	numSign s = oper1.sign;
	BigNum oper2(oper22);

	if (oper1.realSize == 0){
		oper1 = oper2;

		if (oper2.sign == POS && (oper2.realSize != 0))
			oper1.sign = NEG;
		else
			oper1.sign = POS;


		if (oper1.getSize() == 0)
			oper1.sign = POS;
		return oper1;
	}

	if (s == POS)
		oper1.sign = NEG;
	else
		oper1.sign = POS;

	oper1 += oper2;
	oper1.sign = s;

	if (oper1.realSize == 0)
		oper1.sign = POS;
	return oper1;
}

/**
* Используется для реализации умножения. Знак не учитывается.
*/
BigNum & operator +=(BigNum & oper1, const uint oper2){
	bool transfer = false;

	oper1.value[0] += oper2;

	if (oper1.value[0] < oper2)
		transfer = true;

	uint sz = 1;

	while (transfer == true){
		if (sz == oper1.getMemorySize()){
			oper1.giveMemory();
		}
		oper1.value[sz]++;
		if (oper1.value[sz] == 0){
			transfer = true;
			sz++;
		}
		else transfer = false;
	}

	oper1.realSize = oper1.getSize();
	return oper1;
}

BigNum & operator *=(BigNum & oper1, const BigNum & oper2){

	BigNum result;
	BigNum t;

	uint m = oper1.realSize;
	uint n = oper2.realSize;
	ulong uv, k;


	if (oper1.sign == oper2.sign){
		result.sign = POS;
	}
	else {
		result.sign = NEG;
	}

	while ((m + n) > result.getMemorySize()){
		result.giveMemory();
	}

	for (uint j = 0; j < n; j++){

		if (oper2.value[j] == 0){
			result.value[m + j] = 0;
		}
		else {

			k = 0;

			for (uint i = 0; i < m; i++){
				t.clean();

				uv = (ulong)oper2.value[j] * (ulong)oper1.value[i];
				t.value[0] = (uv << 32) >> 32;
				t.value[1] = (uv >> 32);
				t += result.value[i + j];
				t += k;

				result.value[i + j] = t.value[0];
				k = t.value[1];
				//
			}
			result.value[m + j] = k;
		}

	}

	result.realSize = result.getSize();
	if (result.realSize == 0){
		result.sign = POS;
	}

	oper1 = result;
	return oper1;
}

BigNum & operator >>=(BigNum & oper1, uint oper2){
	uint sz = oper1.realSize;
	uint blockShift = oper2 / 32;
	oper2 %= 32;

	uint j = 0;
	if (blockShift >= sz){
		oper1.clean();
	}
	else {
		if (blockShift != 0){
			for (uint i = blockShift; i < sz; i++){
				oper1.value[j++] = oper1.value[i];
			}
			for (; j < sz; j++){
				oper1.value[j] = 0;
			}
		}

		if (oper2 != 0){
			sz = oper1.realSize;
			for (uint i = 0; i < sz - 1; i++){
				oper1.value[i] = (oper1.value[i] >> oper2) + (oper1.value[i + 1] << (64 - oper2));
			}
			oper1.value[sz - 1] >>= oper2;
		}

	}

	oper1.realSize = oper1.getSize();
	if (oper1.realSize == 0){
		oper1.sign = POS;
	}


	return oper1;
}

BigNum opposite(BigNum & oper1, BigNum & mod){
	BigNum base(oper1);
	BigNum module(mod);
	BigNum temp;
	BigNum zero(0);

	vector<BigNum> matrix;

	while (!(bnmod(base, module) == zero)){
		temp = base / module;
		temp.sign = NEG;
		matrix.push_back(temp);

		temp = bnmod(base, module);
		base = module;
		module = temp;
	}
	temp = base / module;
	temp.sign = NEG;
	matrix.push_back(temp);

	BigNum u(matrix[0]), v(1), x(1), y(0);

	BigNum oldu, oldv, oldx, oldy;
	for (uint i = 1; i < matrix.size(); i++){

		oldu = u;
		oldv = v;
		oldx = x;
		oldy = y;

		u = matrix[i] * oldu + oldv;
		v = oldu;
		x = matrix[i] * oldx + oldy;
		y = oldx;
	}

	return bnmod(y, mod);
}

BigNum opposite(BigNum & oper1, ulong mod){
	BigNum temp(mod);
	return opposite(oper1, temp);
}
BigNum & BigNum::operator =(const BigNum & oper){

	this->clean();

	while (oper.getMemorySize() > this->getMemorySize()){
		this->giveMemory();
	}

	uint k = oper.getSize();

	for (uint i = 0; i < k; i++){
		value[i] = oper.value[i];
	}

	sign = oper.sign;


	realSize = k;
	return *this;
}

BigNum BigNum::operator /(const BigNum & oper) const{
	BigNum temp(*this);
	temp /= oper;
	return temp;
}

BigNum BigNum::operator *(const BigNum & oper) const{
	BigNum temp(*this);
	temp *= oper;
	return temp;
}

BigNum BigNum::operator +(const BigNum & oper) const{
	BigNum temp(*this);
	temp += oper;
	return temp;
}

BigNum BigNum::operator -(const BigNum & oper) const{
	BigNum temp(*this);
	temp -= oper;
	return temp;
}
bool operator ==(const BigNum & oper1, const BigNum & oper2){
	uint sz = oper1.realSize;

	if (oper1.sign != oper2.sign)
		return false;

	if (sz != oper2.realSize)
		return false;
	else {
		for (uint i = 0; i < sz; i++){
			if (oper1.value[i] != oper2.value[i])
				return false;

		}
	}
	return true;
}

bool operator !=(const BigNum & oper1, const BigNum & oper2){
	return !(oper1 == oper2);
}

bool operator >(const BigNum & oper1, const BigNum & oper2){
	uint sz1 = oper1.realSize;
	uint sz2 = oper2.realSize;



	bool negSign = false;

	if (oper1.sign == NEG && oper2.sign == POS)
		return false;
	if (oper1.sign == POS && oper2.sign == NEG)
		return true;
	if (oper1.sign == NEG && oper2.sign == NEG)
		negSign = true;

	if (sz1 > sz2){
		return ((true != negSign)); //XOR

	}
	else if (sz1 < sz2) {
		return ((false != negSign));

	}
	else {
		if (sz1 == 0)
			return false;

		for (long i = sz1 - 1; i >= 0; i--){
			if (oper1.value[i] > oper2.value[i]){
				return ((true != negSign));
			}
			else if (oper1.value[i] < oper2.value[i])
				return ((false != negSign));

		}
	}

	return false;
}

bool operator >=(const BigNum & oper1, const BigNum & oper2){
	if (oper1 == oper2)
		return true;
	else
		return (oper1 > oper2);
}

bool operator <(const BigNum & oper1, const BigNum & oper2){
	if (oper1 == oper2)
		return false;
	else
		return !(oper1 > oper2);
}

bool operator <=(const BigNum & oper1, const BigNum & oper2){
	if (oper1 == oper2)
		return true;
	else
		return !(oper1 > oper2);
}










#endif /* $BIGNUM_H_ */
