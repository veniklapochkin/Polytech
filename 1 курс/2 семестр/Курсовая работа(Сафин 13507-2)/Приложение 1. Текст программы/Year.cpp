#include "Year.h"
#include <bitset>

Year:: Year():year_(0){
	/*cout<<"Year:Сработал конструктор без параметров."<<endl;*/
}

//Упаковка числа. Устанавливаем левый(седьмой) бит в единицу или ноль(19xx или 20xx?):
void Year:: packAndSaveYear(u_int& year){ 	
	if(year<2000){
		year_|=(1<<7);
		year-=1900;
	}
	else{
		year_&=(~(1<<7));
		year-=2000;
	}
//Перевод оставшейся части числа в двоичную систему и побитовое копирование:
	bitset<7> vector(year);
	for(int i=0;i<7;i++)
		year_|=(vector[i]<<i);
}

u_int Year::unpackAndGetYear() const {
	bitset<8> vector(year_);
	u_int temp=0;
	(vector[7]==1)?temp+=1900:temp+=2000;
	for(int i=0;i<7;i++)
		if(vector[i]!=0) 
			temp+=pow(2,i);
	return temp;
}

istream& operator>>(istream& istream, Year& year){
	u_int temporary;
	istream>>temporary;
	if(temporary<1900||temporary>2100){
		cout<<"Ошибка: некорректный год поступления на работу.";
		system("pause");
	}
	year.packAndSaveYear(temporary);
	return istream;
}

ostream& operator<<(ostream& ostream, const Year& year){
	ostream<<year.unpackAndGetYear();
	return ostream;
}

const bool Year:: operator<(const Year& year){
	return (this->unpackAndGetYear()<year.unpackAndGetYear());
}

const bool Year:: operator>(const Year& year){
	return (this->unpackAndGetYear()>year.unpackAndGetYear());
}

const bool Year:: operator==(const Year& year){
	return (this->unpackAndGetYear()==year.unpackAndGetYear());
}

const Year& Year::operator++(){
	u_int temp = (this->unpackAndGetYear());
	temp++;
	this->packAndSaveYear(temp);
	return *this;
}	

const Year operator++(Year& year, int k){
	Year temp = year;
	u_int tempYear = year.unpackAndGetYear();
	tempYear++;
	year.packAndSaveYear(tempYear);
	return temp;
}
//Year:: Year(u_int year):year_(0){
//	////Проверка упаковки:
//	//bitset<8> vector(year_);
//	//cout<<"До упаковки: year_="<<year_<<endl;
//	//for(int i=0;i<8;i++)
//	//	cout<<i<<" бит равен "<<vector[i]<<endl;
//	packAndSaveYear(year);
//	//
//	//bitset<8> vector1(year_);
//	//cout<<"После упаковки: year_="<<year_<<endl;
//	//for(int i=0;i<8;i++)
//	//	cout<<i<<" бит равен "<<vector1[i]<<endl;
//	//cout<<"вы ввели "<<unpackAndGetYear()<<endl;
//	cout<<"Сработал конструктор с параметром."<<endl;
//}













