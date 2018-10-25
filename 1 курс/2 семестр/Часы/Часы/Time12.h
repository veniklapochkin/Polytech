#ifndef TIME12_H
#define TIME12_H
#include "Errors.h"

class Time12
{
public:
	int hour_;
	int minutes_;
	bool is_am_;

	Time12(int hour = 0, int minutes = 0, bool is_am = true)
	{
		if (hour < 0 || hour > 11) throw ErrorHour("   hour < 0 || hour > 11, error value = ", hour);
		if (minutes < 0 || minutes > 59) throw ErrorMinutes("   minutes < 0 || minutes > 59");


		this->hour_ = hour;
		this->minutes_ = minutes;
		this->is_am_ = is_am;

		void setH(int h_);
		void getH(int h_);
	}

	~Time12(void){}
};
#endif
