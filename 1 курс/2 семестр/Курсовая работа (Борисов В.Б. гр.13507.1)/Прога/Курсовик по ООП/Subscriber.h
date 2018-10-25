#include <iostream>
using namespace std;
const int LEN_FULL_NAME = 20, 
LEN_NUMBER = 11; 
class Subscriber
{
	// �������� ����� ������ (1)
	char *fullName_ = new char[LEN_FULL_NAME], // ���
	     *number_ = new char[LEN_NUMBER]; // ����� ��������
	short tariff_; // ������������� �������� 1000 ��� � �����
public:
	//������������ (2)
	Subscriber();
	Subscriber(char *fullName, char *number, short tariff);
	Subscriber(const Subscriber &ob);
	//��������������� ������� ��������� ������ ��� �������
	void getob(char *fullName, char *number, short tariff);
	//������������� ������� �����-������ (3)
	friend void in(Subscriber &ob);
	friend void out(const Subscriber &ob);
	//���������� ��������� ��������� + (4)
	Subscriber &operator +(short tariff);
	// ���������� ����� �������������� ������� (5)
	friend  Subscriber &operator -(Subscriber &ob, short tariff); //
	//���������� ���������� ��������� > � <
	bool operator >(const Subscriber &ob); 
	friend bool operator <(const Subscriber &ob1, const Subscriber &ob2);
	//���������� ��������� = (6)
	Subscriber & operator =(const Subscriber &ob);
	//���������� ������������ ����������(��������� 100 ��� � ������) (7.1)
	Subscriber &operator ++(int);
	//���������� ����������� ����������(������� 100 ��� � ������) (7.2)
	friend Subscriber &operator --(Subscriber &ob);
	//���������� << � >> (8)
	friend const ostream& operator << (ostream & os, const Subscriber & ob);
	friend istream & operator >> (istream  & is, Subscriber & ob);
};
