#ifndef ERRORS_H
#define ERRORS_H

class Error
{
public:
	const char * msg;
	Error(const char * msg = "") : msg(msg){}

};

class ErrorHour : public Error
{
public:
	int h_;
	ErrorHour(const char * msg = "", int h = 0) : Error(msg), h_(h) {}
};

class ErrorMinutes : public Error
{
public:
	ErrorMinutes(const char * msg = "") : Error(msg){}
};

class ErrorSeconds : public Error
{
public:
	ErrorSeconds(const char * msg = "") : Error(msg){}
};
#endif