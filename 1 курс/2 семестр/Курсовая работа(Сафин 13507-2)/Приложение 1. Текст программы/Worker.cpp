
#include "Worker.h"


u_int Worker::workerCounter_=0;
const double Worker::dataBaseLenght_=15;

Worker::Worker(){
	system("cls"); 
	workerCounter_++; 
	cout<<"Выделение памяти [ "<<workerCounter_*(100/dataBaseLenght_)<<setprecision(3)<<"% ]\n"; 
}

M_String Worker::getSurName(){
	return surName_;
}

M_String Worker::getProfession(){
	return profession_;
}

Year Worker::getYear(){
	return year_;
}

void Worker::setSurName(M_String string){
	surName_=string;
}

void Worker::setProfession(M_String string){
	profession_=string;
}

void Worker::setYear(Year year){
	year_=year;
}

istream& operator>>(istream& istream, Worker& worker){
	M_String tempString;
	Year tempYear;
	istream>>tempString;
	worker.setSurName(tempString);
	istream>>tempString;
	worker.setProfession(tempString);
	istream>>tempYear;
	worker.setYear(tempYear);
	return istream;
}

ostream& operator<<(ostream& ostream, Worker& worker){
	ostream<<setw(12)<<worker.getSurName()<<"| "<<setw(13)<<worker.getProfession()<<"| "<<setw(7)<<worker.getYear()<<"   |"<<endl;
	return ostream;
}

fstream& operator>>(fstream& inputFstream, Worker& worker){
	M_String tempString;
	Year tempYear;
	inputFstream>>tempString;
	worker.setSurName(tempString);
	inputFstream>>tempString;
	worker.setProfession(tempString);
	inputFstream>>tempYear;

	worker.setYear(tempYear);
	return inputFstream;
}

fstream& operator<<(fstream& outputFstream, Worker& worker){
	outputFstream<<worker.getSurName()<<" "<<worker.getProfession()<<" "<<worker.getYear()<<" "<<endl;
	return outputFstream;
}
