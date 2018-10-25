#include "Worker.h"

void showDB(Worker* workerPointer, u_int n){
	system("cls");
	cout<<"Вывод базы:\n****************************************\n"<<
		"   Surname  |  Profession  | Join Year |\n"<<
		"------------|--------------|-----------|\n";
	for(int i=0;i<n;i++)
		cout<<workerPointer[i];
}
