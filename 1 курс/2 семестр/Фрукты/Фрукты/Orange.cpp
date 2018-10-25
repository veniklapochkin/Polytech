#include "Orange.h"
Orange::Orange() : Fruit(), colPart_(0){};
Orange::Orange(Fruit fruit, int colPart) : Fruit(fruit), colPart_(colPart){};
Orange::Orange(Orange &ob) : Fruit(ob), colPart_(ob.colPart_){};
void Orange::show()
{
	cout << "��������" << "\n";
	this->Fruit::show();
	cout << "���������� ����� " << colPart_ << "\n";
};