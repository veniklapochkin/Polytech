#include "Year.h"
#include "M_String.h"
#include "Worker.h"
#include <string>
using namespace std;
void (*options[])(Worker*, u_int) = { inputFromFile, showDB, findAndShowYoungestWorker };
int main(){
	setlocale(LC_ALL, "RUS");
	const u_int dataBaseLenght = 15;
	Year year1;
	Worker* workerPointer = new Worker[dataBaseLenght];
	if(!workerPointer) throw "Ошибка: недостаточно памяти.\n";
			int temp = mainMenu();
		while(temp!=-1){
			(*options[temp])(workerPointer, dataBaseLenght);
			temp = mainMenu();
		}
			return 0;
	system("pause");
}
