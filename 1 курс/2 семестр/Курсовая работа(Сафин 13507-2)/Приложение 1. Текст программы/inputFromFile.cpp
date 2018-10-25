#include "Worker.h"
#include <fstream>
void inputFromFile(Worker* workerPointer, u_int n){
	fstream input;
	string path = "C://DB/input.txt";
	input.open(path, ios::in);
	if(!input) throw "Ошибка: невозможно открыть файл input.txt.\n";
	for(int i=0;i<n;i++){
		input>>workerPointer[i];
		if(!input) throw "Ошибка: неожиданный конец файла.\n";
	}
	cout<<"Файл успешно загружен.\n";
	input.close();
}

	