/*************************************************************************
    > File Name: stock00.h
    > Author: zll
    > Mail: zhnllion@126.com 
    > Created Time: 二 10/ 8 11:21:45 2019
 ************************************************************************/

#ifndef STOCK00_H_
#define STOCK00_H_

#include<string>

class Stock {
	private:
		std::string company;
		long shares;
		double share_val;
		double total_val;
		void set_tot {
			total_val = shares * share_val;
		}
	public:
		void acquire(const std::string& co, long n, double pr);
		void buy(long num, double price);
		void sell(long num, double price);
		void update(double price);
		void show();
};
#endif

