// ������� main
#include "Subscriber.h"
Subscriber maxobject(Subscriber *subscriber, int size);

int main()
{
	setlocale(0, "");
	try {
		int size;
		cout << "������� ���������� ���������\n";
		cin >> size;
		if (!cin) throw "������� �� �����\n";
		if (size <= 0) throw "����� ������ ���� >=1\n";
		Subscriber *subscriber = new Subscriber[size];
		cout << "������� ���������� � ��������(��)\n";
		// ������ �� �������� ������ 
		for (int i = 0; i < size; i++){
			cout << "������� [" << i << "]:" << '\n';
			cin >> subscriber[i];
		}
		cout << "���������� � ������������ c����\n" << maxobject(subscriber, size);
		delete[] subscriber;
	}
	catch (char* err){
		cerr << err;
	}
	
	system ("pause");
}

