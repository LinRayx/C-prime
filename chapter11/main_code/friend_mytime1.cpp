/*************************************************************************
    > File Name: mytime1.cpp
    > Author: kyrie
    > Mail: linkyrie2016@gmail.com 
    > Created Time: 二 10/ 8 16:24:02 2019
 ************************************************************************/

#include<iostream>
#include "mytime1.h"

Time::Time() {
	hours = minutes = 0;
}

Time:: Time(int h, int m) {
	hours = h;
	minutes = m;
}
void Time::AddMin(int m) {
	minutes  += m;
	hours += minutes / 60;
	minutes %= 60;
}
void Time::AddHr(int h) {
	hours += h;
}
void Time::Reset(int h, int m) {
	hours = h;
	minutes = m;
}
Time Time::operator+(const Time& t)const {
	Time sum;
	sum.minutes = minutes+t.minutes;
	sum.hours = hours+t.hours+sum.minutes/60;
	sum.minutes %= 60;
	return sum;
}
Time Time::operator*(double mult) const {
	Time result;
	long totalminutes = hours * mult * 60 + minutes * mult;
	result.hours = totalminutes / 60;
	result minutes = totalminutes % 60;
	return result;
}
std::ostream& operator<<(std::ostream& os, const Time& t) {
	os << t.hours << " hours, " << t.minutes << " minutes";
	return os;
}
void Time::Show() const {
	std::cout << hours <<" hours, " << minutes <<" minutes";
}
