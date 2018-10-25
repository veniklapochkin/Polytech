#include "M_String.h"
#include <cstring>
M_String:: M_String(){
	lenght_=20;
	string_=new char[lenght_];
	/*cout<<"M_String: Сработал конструктор без параметров.\n";*/
}

M_String:: M_String(const u_int& lenght){
	lenght_=lenght;
	string_=new char[lenght_];
	//cout<<"M_String: Сработал конструктор с параметрами.\n";
}

M_String:: M_String(const M_String& object){
	lenght_=object.lenght_;
	string_=object.string_;
	if(lenght_>0)
		string_=new char[lenght_];
	for(int i=0;i<lenght_;i++)
		string_[i]=*(object.string_+i);
}

u_int M_String::getLenght(){
	return lenght_;
}

M_String M_String::operator+(M_String& const object){
	u_int tempLenght=this->getLenght()+object.getLenght();
	M_String tempObject(tempLenght);
	u_int i=0;
	while(this->string_[i]!=NULL){
		tempObject.string_[i]=this->string_[i];
		i++;
	}
	u_int j=0;
	while(object.string_[j]!=NULL){
		tempObject.string_[i]=object.string_[j];
		i++, j++;
	}
	tempObject.string_[i]=NULL;
	return tempObject;
}

M_String M_String::operator=(M_String& const object){
	if(&object==this) return object;
	M_String tempObject(object.lenght_);
	for(int i=0;i<tempObject.lenght_;i++)                   
		tempObject.string_[i]=object.string_[i];
	*this=tempObject;
	return tempObject;
	/*this->lenght_=object.lenght_;
	for(int i=0;i<this->lenght_;i++)
		this->string_[i]=object.string_[i];
	return *this;*/
}

istream& operator>>(istream& istream, M_String& string){
		istream>>string.string_;
	return istream;
}

ostream& operator<<(ostream& ostream, M_String& string){
		ostream<<string.string_;
	return ostream;
}

const bool M_String:: operator==(const M_String& string){
	if ((this->lenght_)!=(string.lenght_)) return false;
	u_int i=0;
	while(this->string_[i]!=NULL){
		if((this->string_[i])!=string.string_[i])
			return false;
		i++;
	}
	return true;
}
