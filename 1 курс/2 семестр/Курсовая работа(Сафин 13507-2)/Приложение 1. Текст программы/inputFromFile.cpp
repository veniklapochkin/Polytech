#include "Worker.h"
#include <fstream>
void inputFromFile(Worker* workerPointer, u_int n){
	fstream input;
	string path = "C://DB/input.txt";
	input.open(path, ios::in);
	if(!input) throw "������: ���������� ������� ���� input.txt.\n";
	for(int i=0;i<n;i++){
		input>>workerPointer[i];
		if(!input) throw "������: ����������� ����� �����.\n";
	}
	cout<<"���� ������� ��������.\n";
	input.close();
}

	