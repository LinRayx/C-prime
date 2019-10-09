/*************************************************************************
    > File Name: mytime1.h
    > Author: kyrie
    > Mail: linkyrie2016@gmail.com 
    > Created Time: 二 10/ 8 16:22:04 2019
 ************************************************************************/

#ifndef MYTIME1_H_
#define MYTIME1_H_

class Time {
	private:
		int hours;
		int minutes;
	public:
		Time();
		Time(int h, int m = 0);
		void AddMin(int m);
		void AddHr(int h);
		void Reset(int h= 0, int m = 0);
		Time operator+(const Time& t) const;
		void Show() const;
};
#endif
