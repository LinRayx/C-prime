/*************************************************************************
    > File Name: cp-8-4.cpp
    > Author: zll
    > Mail: zhnllion@126.com 
    > Created Time: 一 10/ 7 11:25:17 2019
 ************************************************************************/
#include <iostream>
using namespace std;
#include <cstring>
struct stringy {
    char* str;
    int ct;
};
void show(const stringy&, int cnt=1);
void show(const char*, int cnt = 1);
void set(stringy&, const char*);
int main() {
    stringy beany;
    char testing[] = "Reality isn't what is";
    set(beany, testing);
    show(beany);
    show(beany,2);
    testing[0] = 'D';
    testing[1] = 'u';
    show(testing);
    show(testing, 3);
    show("Done!");
    return 0;
}
void show(const stringy& news, int cnt) {
    for(int i = 0; i < cnt; ++i)
        cout << news.str << endl;
}
void show(const char* str, int cnt) {
    for(int i = 0; i < cnt; ++i)
        cout << str << endl;
}
void set(stringy& sgy, const char* str) {
    int len = int(strlen(str));
    sgy.str = new char[len];
    
    memcpy(sgy.str, str, len);
    
}

