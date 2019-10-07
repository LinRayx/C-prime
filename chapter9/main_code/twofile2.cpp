/*************************************************************************
    > File Name: twofile2.cpp
    > Author: zll
    > Mail: zhnllion@126.com 
    > Created Time: 一 10/ 7 13:12:08 2019
 ************************************************************************/

#include<iostream>

extern int tom;
static int dick = 10;
int harry = 200;

void remote_access() {
	using namespace std;
	cout <<"remote_access() reports the following addresses:\n";
	cout << &tom <<" =&tom, " << &dick << " = &dick, ";
	cout << &harry << " = &harry\n";
}
