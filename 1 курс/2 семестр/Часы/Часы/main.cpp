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
		cout << "����������� ������ �������� �����!" << ex.msg << ex.h_ << endl;
	}
	catch (ErrorMinutes & ex)
	{
		cout << "����������� ������ �������� �����!" << endl;
	}
	catch (ErrorSeconds & ex)
	{
		cout << "����������� ������ �������� ������!" << endl;
	}
	catch (Error & ex)
	{
		cout << "������!" << endl;
	}
	catch (...)
	{
		cout << "����������� ������!" << endl;
	}
	system ("pause");
}