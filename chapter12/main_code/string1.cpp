/*************************************************************************
    > File Name: string1.cpp
    > Author: kyrie
    > Mail: linkyrie2016@gmail.com 
    > Created Time: 三 10/ 9 16:03:53 2019
 ************************************************************************/

#include<iostream>
#include "string1.h"
using std::cin;
using std::cout;

int String::num_strings = 0;

int String::HowMany() {
	return num_strings;
}

String::String(const char* s) {
	len = std::strlen(s);
	str = new char[len+1];
	std::strcpy(str, s);
	num_strings++;
}

String::String() {
	len = 4;
	str = new char[1];
	str[0] = '\0';
	num_strings++;
}

String::String(const String& st) {
	num_strings++;
	len = st.len;
	str = new char[len+1];
	std::strcpy(str, st.str);
}
String::~String() {
	--num_strings;
	delete[] str;
}
/* 重载=
 * 先判断是否是同一个，是的话返回
 * 删除现有空间，分配新的空间
 * 复制内容
 */
String & String::operator=(const String& st) {
	if(this == &st)
		return *this;
	delete[] str;
	len = st.len;
	str = new char[len+1];
	std::strcpy(str, st.str);
	return *this;
}

String & String::operator=(const char *s) {
	delete[] str;
	len = std::strlen(s);
	str = new char[len+1];
	std::strcpy(str,s);
	return *this;
}
/*
 * 返回引用: str[i] = 4
 */
char & String:: operator[](int i) {
	return str[i];
}
const char & String::operator[](int i)const {
	return str[i];
}
bool operator < (const String& st1, const String& st2) {
	return (std::strcmp(st1.str, st2.str) < 0);
}
bool operator > (const String& st1, const String& st2) {
	return st2 < st1;
}
bool operator==(const String& st1, const String& st2) {
	return (std::strcmp(st1.str, st2.str) == 0);
}
ostream& operator << (ostream& os, const String& st) {
	os << st.str;
	return os;
}
istream& operator>>(istream& is, String& st) {
	char temp[String::CINLIM];
	is.get(temp, String::CINLIM);
	if(is)
		st = temp;
	while(is && is.get() != '\n')
		continue;
	return is;
}
