/*************************************************************************
    > File Name: cp-8-5.cpp
    > Author: zll
    > Mail: zhnllion@126.com 
    > Created Time: 一 10/ 7 11:25:42 2019
 ************************************************************************/

#include<iostream>
using namespace std;

template <typename T>
T getMax(T a[]) {
	T t = a[0];
	for(int i = 1; i < 5; ++i)
		if(a[i] > t)
			t = a[i];
	return t;
}

int main() {
	int a[] = {
		1,2,3,4,5
	};
	double b[] = {
		1.0,2.0,3.0,4.0,5.0
	};
	cout << getMax(a) << endl;
	cout << getMax(b) << endl;
	return 0;
}
