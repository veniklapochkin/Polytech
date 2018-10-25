#include "Time12.h"
#include "Time24.h"

#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	try
	{
		Time12 t(19, 50, false); 
		Time24 t2(-17, 70, 0);
	}
	catch (ErrorHour & ex)
	{
		cout << "Неправильно задано значение часов!" << ex.msg << ex.h_ << endl;
	}
	catch (ErrorMinutes & ex)
	{
		cout << "Неправильно задано значение минут!" << endl;
	}
	catch (ErrorSeconds & ex)
	{
		cout << "Неправильно задано значение секунд!" << endl;
	}
	catch (Error & ex)
	{
		cout << "Ошибка!" << endl;
	}
	catch (...)
	{
		cout << "Неизвестная ошибка!" << endl;
	}
	system ("pause");
}