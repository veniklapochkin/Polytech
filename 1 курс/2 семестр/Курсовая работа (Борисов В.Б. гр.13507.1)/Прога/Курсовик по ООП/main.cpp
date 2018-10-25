// функци€ main
#include "Subscriber.h"
Subscriber maxobject(Subscriber *subscriber, int size);

int main()
{
	setlocale(0, "");
	try {
		int size;
		cout << "¬ведите количество абонентов\n";
		cin >> size;
		if (!cin) throw "¬ведено не число\n";
		if (size <= 0) throw "число должно быть >=1\n";
		Subscriber *subscriber = new Subscriber[size];
		cout << "¬ведите информацию о абоненте(ах)\n";
		// массив из объектов класса 
		for (int i = 0; i < size; i++){
			cout << "абонент [" << i << "]:" << '\n';
			cin >> subscriber[i];
		}
		cout << "»нформаци€ о максимальном cчете\n" << maxobject(subscriber, size);
		delete[] subscriber;
	}
	catch (char* err){
		cerr << err;
	}
	
	system ("pause");
}

