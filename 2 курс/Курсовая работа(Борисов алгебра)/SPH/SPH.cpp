//метод Полига-Хеллмана
#define _CRT_SECURE_NO_WARNINGS
#include <cmath>
#include <iostream>
#include <ctime>
#include <vector>
#include "longInt.h"
#include "VERYLONG.H"
typedef unsigned long long ull;
using namespace std;

vector<ull> br;//простые числа
ull cr[100000][200];//степени разложения p-1 на простые числа
ull dr[20][1000000];//таблица значений
ull tmp[20][100000];//таблица для китайской теоремы
ull counter;//кол-во простых чисел 
ull n;//кол-во разных простых множителей p-1
//раскладываем p-1 на простые множители
void separ(ull x){
	for (int i = 0; i<100; i++){
		cr[i][0] = 0;
		cr[i][1] = 0;
	}
	n = 0;
	ull p = x;
	bool flag;
	for (int i = 0; i<counter; i++){
		flag = false;
		while (p%br[i] == 0 && p != 0){
			cr[n][1]++;
			cr[n][0] = br[i];
			p /= br[i];
			flag = true;
		}
		if (flag)n++;
	}
}
//заполняем таблицу
void full(ull p,ull g){
	for (int i = 0; i<n; i++)
	for (int j = 0; j<cr[i][0]; j++){
		dr[i][j] = 1;
		for (int f = 0; f < j*(p - 1) / cr[i][0]; f++){
			dr[i][j] = (dr[i][j] * g) % p;
		}
	}
}
//Наибольший общий делитель
ull GSD(ull k1,ull k2){
	if (k2 == 0)return k1;
	return GSD(k2, k1%k2);
}
//функция Эйлера
ull getA(ull p){
	ull ans = 0;
	for (int i = p - 1; i>0; i--)
	if (GSD(p, i) == 1)ans++;
	return ans;
}
//поиск иксов
void finding(int b, int p, int a){
	ull Ailer = getA(p) - 1;
	ull Aa = 1;
	for (int i = 0; i<Ailer; i++)
		Aa = (Aa*a) % p;
	for (int i = 0; i<n; i++){
		ull x0 = b;
		for (int j = 1; j<(p - 1) / cr[i][0]; j++)
			x0 = (x0*b) % p;
		for (int j = 0; j<cr[i][0]; j++)
		if (dr[i][j] == x0){
			tmp[i][0] = j;
		}
		for (int j = 1; j<cr[i][1]; j++){
			x0 = b;
			for (int k = 0; k<j; k++)
			for (int s = 0; s<tmp[i][k] * int(pow(cr[i][0], k)); s++)x0 = (x0*Aa) % p;
			ull x1 = x0;
			for (int k = 1; k<(p - 1) / int(pow(cr[i][0], j + 1)); k++)x0 = (x0*x1) % p;
			for (int k = 0; k<cr[i][0]; k++)
			if (dr[i][k] == x0){
				tmp[i][j] = k;
			}
		}
	}
	ull x1, x2, a1, a2;
	x1 = 0;  x2 = 0;
	for (int i = 0; i<cr[0][1]; i++)
		x1 += tmp[0][i] * ull(pow(cr[0][0], i));
		x2 = 0;
	for (int i = 0; i<cr[1][1]; i++)x2 += tmp[1][i] * int(pow(cr[1][0], i));
	a1 = ull(pow(cr[0][0], cr[0][1]));
	a2 = ull
		(pow(cr[1][0], cr[1][1]));
	x2 -= x1;
	while (x2<0)
		x2 += a2;
	ull bf = getA(a2);
	ull ba = a1;
	for (int i = 1; i<bf - 1; i++)ba = (ba*a1) % a2;
	x2 = (x2*ba) % a2;
	ull x = (x1 + x2*a1) % (a2*a1);  //x решение 
	ull kk = 1;
	for (int i = 0; i<1000000; i++){
		if (kk%p == b){
			cout<<"ответ : "<< i<<endl;
			return;
		}
		kk = (kk*a) % p;
	}
	cout<<"Нет решений\n";
}
int main(){
	setlocale(LC_ALL,"Rus");
	cout << "\t\tАлгоритм Сильвера-Полига-Хеллмана\n";
	cout<<"Введите: a b p\n";
	//инициализация и ввод даных
	 ull a, b, p ;
	scanf("%d %d %d", &a, &b, &p);
	//srand(time(NULL));
	clock_t time;
	time = clock();
	separ(p-1);  //раскладываем p-1 на простые числа
	full(p,a); //заполняем таблицу
	finding(b,p,a);//ищем x для китайской теоремы
	cout<<"Время работы : "<< (clock()-time)/1000.0<<endl;
	system("pause");
}
