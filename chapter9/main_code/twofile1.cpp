/*************************************************************************
    > File Name: twofile1.cpp
    > Author: zll
    > Mail: zhnllion@126.com 
    > Created Time: 一 10/ 7 13:10:23 2019
 ************************************************************************/

#include<iostream>

int tom = 3;
int dick = 30;
static int harry = 300;

void remote_access();

int main() {
	using namespace std;
	cout << "main() reports the following addresses\n";
	cout << &tom << " = &tom, " << &dick << " = &dick, ";
	cout << &harry << " = &harry\n";
	remote_access();
	return 0;
}
