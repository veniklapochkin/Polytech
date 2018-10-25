#ifndef TIME24_H
#define TIME24_H

#include "Errors.h"
#include <string>

class Time24
{
public:
	int hour_;
	int minutes_;
	int seconds_;

	Time24(int hour = 0, int minutes = 0, int seconds = 0)
	{
		if (hour < 0 || hour > 11) throw ErrorHour("   hour < 0 || hour > 11");
		if (minutes < 0 || minutes > 59) throw ErrorMinutes("   minutes < 0 || minutes > 59");
		if (seconds < 0 || seconds > 59) throw ErrorSeconds("   seconds < 0 || seconds > 59");

		this->hour_ = hour;
		this->minutes_ = minutes;
		this->seconds_ = seconds;
	}

	~Time24(){}
};
#endif
