#ifndef WORKER_H
#define WORKER_H
#include <iostream>
#include "Year.h"
#include "M_String.h"
#include <fstream>
#include <iomanip>
int mainMenu();

using namespace std;
class Worker{
private:
	M_String surName_;
	M_String profession_;
	Year year_;
	static u_int workerCounter_;
	static const double dataBaseLenght_;
public:
	Worker();
	M_String getSurName();
	M_String getProfession();
	Year getYear();
	void setSurName(M_String);
	void setProfession(M_String);
	void setYear(Year);
	friend istream& operator>>(istream&, Worker&);
	friend ostream& operator<<(ostream&, Worker&); //const???
	friend fstream& operator>>(fstream&, Worker&);
	friend fstream& operator<<(fstream&, Worker&); // const??
};
void inputFromFile(Worker*, u_int);
void showDB(Worker*, u_int);
void findAndShowYoungestWorker(Worker*, u_int);
#endif