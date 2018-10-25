#include "BoundQueue.h"
int main()
{
	setlocale(0,"RUS");
	try{
	BoundQueue<int> a;
	//a.deQueue();
	a.enQueue(1);
	a.enQueue(2);
	a.enQueue(3);
	a.enQueue(4);
	a.enQueue(5);
	a.show();
	cout << '\n';
	a.deQueue();
	a.deQueue();
	a.deQueue();
	a.enQueue(6);
	a.enQueue(0);

	//cout<<endl;
	//a.show();
	//cout << '\n';
	a.deQueue();
	a.deQueue();
	a.enQueue(3);
	a.enQueue(4);
	a.enQueue(5);
	cout<<endl;
	a.show();
	
	a.deQueue();
	a.deQueue();
	a.deQueue();
	a.enQueue(6);
	a.enQueue(7);
	
	a.deQueue();
	a.deQueue();
	a.enQueue(0);
	a.enQueue(3);
	a.enQueue(4);
	cout << endl<< '\n';
	a.show();
	cout << '\n';
	}
	catch(const QueueUnderFlow&x){cout<<x.what();}
	/*catch(QueueUnderFlow&){cout<<"Queue Under Flow";}*/
	//catch(QueueOverFlow&){cout<<"Queue Over Flow"/*::what()*/;}
	catch(QueueOverFlow&){cout<<"Queue Over Flow";}
	cout << '\n';
	system ("pause")	;
}
