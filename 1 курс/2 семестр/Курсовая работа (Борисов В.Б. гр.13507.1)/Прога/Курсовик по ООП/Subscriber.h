#include <iostream>
using namespace std;
const int LEN_FULL_NAME = 20, 
LEN_NUMBER = 11; 
class Subscriber
{
	// Описание полей класса (1)
	char *fullName_ = new char[LEN_FULL_NAME], // ФИО
	     *number_ = new char[LEN_NUMBER]; // номер телефона
	short tariff_; // Фиксированная величина 1000 руб в месяц
public:
	//Конструкторы (2)
	Subscriber();
	Subscriber(char *fullName, char *number, short tariff);
	Subscriber(const Subscriber &ob);
	//Вспомогательная функция получения данных для объекта
	void getob(char *fullName, char *number, short tariff);
	//Дружественные функции ввода-вывода (3)
	friend void in(Subscriber &ob);
	friend void out(const Subscriber &ob);
	//Перегрузка бинарного оператора + (4)
	Subscriber &operator +(short tariff);
	// Перегрузка через дружественнную функцию (5)
	friend  Subscriber &operator -(Subscriber &ob, short tariff); //
	//Перегрзука операторов отношения > и <
	bool operator >(const Subscriber &ob); 
	friend bool operator <(const Subscriber &ob1, const Subscriber &ob2);
	//Перегрузка оператора = (6)
	Subscriber & operator =(const Subscriber &ob);
	//Перегрузка постфиксного инкремента(добавляет 100 руб к тарифу) (7.1)
	Subscriber &operator ++(int);
	//Перегрузка префиксного декремента(снимает 100 руб с тарифа) (7.2)
	friend Subscriber &operator --(Subscriber &ob);
	//Перегрузка << и >> (8)
	friend const ostream& operator << (ostream & os, const Subscriber & ob);
	friend istream & operator >> (istream  & is, Subscriber & ob);
};
