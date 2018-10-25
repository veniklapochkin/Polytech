#include "Worker.h"

void findAndShowYoungestWorker(Worker* workerPointer, u_int n){
	u_int indexOfYoungestWorker=0;
	for(int i=1;i<n;i++)
		if(workerPointer[i].getYear()>workerPointer[indexOfYoungestWorker].getYear())
			indexOfYoungestWorker=i;
	cout<<"Самый молодой(недавно пришедший) специалист:"<<endl;
	cout<<setw(12)<<workerPointer[indexOfYoungestWorker].getSurName()<<"| "<<
		  setw(13)<<workerPointer[indexOfYoungestWorker].getProfession()<<"| "<<
		  setw(7)<<workerPointer[indexOfYoungestWorker].getYear()<<"   |"<<endl;
}