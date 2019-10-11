# C++prime 总结

## 第七章重点

### 函数指针
声明：
```cpp
// 函数原型
double pam(int);
// 函数指针声明
double (*pf)(int);
```
这里`(*pf)`替换了`pam`，`pf`是一个函数地址。

赋值：
```cpp
pf = pam;
```
特征标必须相同，否则无法赋值。
```cpp
double ned(double);
double (*pf)(int);
pf = ned; // 错误
```

使用：
```cpp
double p = pam(5);
//等价于
double p = (*pf)(5);
```

**补充**: void*
`void*` 可以指向任意类型，即任意类型的指针都可以`对void*` 赋值。且不需要显示转换。
不需要显示转换：
```cpp
void* a;
int* p;
p = a;
```
需要显示转换：
```cpp
float* p1;
int* p2;
p2 = (float* )p1;
```

用处：（泛型编程）
函数可以接受任意类型的指针。
```cpp
void * memcpy(void *dest, const void *src, size_t len);
void * memset ( void * buffer, int c, size_t num );
```

## 第八章重点

### 函数模版
```cpp
template <typename T>
void swap(T &a, T &b) {
    T temp;
    temp = a;
    a = b;
    b = temp;
}
```

显示实例化， 隐式实例化，显示具体化：

隐式实例化：使用模板之前，编译器不生成模板的声明和定义示例，后面有程序用了，编译器才会根据模板生成一个实例函数。
显式实例化：是无论是否有程序用，编译器都会生成一个实例函数。
显示具体化：因为对于某些特殊类型，可能不适合模板实现，需要重新定义实现，此时就是使用显示具体化的场景。

模版本身并不会生成函数定义，它只是一个用来生成函数定义的方案。当需要用到时，再由编译器根据类型生成一个实例。

模版显示具体化和显示实例化:
```cpp
// 具体化
template <> void swap<job>(job& a, job& b); 
// 实例化
template void swap<job>(job& a, job& b); 
```
调用优先级：1 > 3 > 2

```cpp
void swap(job& a, job& b);// 1
template <typename T>
void swap(T& a, T& b); // 2
template <> void swap<job>(job& a, job& b);// 3
```

## 第九章重点

### 存储持续性，作用域，链接性(内部，外部)

存储持续性
1. 自动存储持续性：函数中声明的变量，在程序开始执行的函数或代码块时被创建，当退出函数或代码块时便释放。
2. 静态存储持续性：函数外定义的全局变量或static变量。它们在程序运行的整个过程中都存在。
3. 线程存储持续性
4. 动态存储持续性：new,delete

链接性
1. 外部链接性：可在其他文件中访问。
2. 内部链接性：只能在当前文件中访问。
3. 无链接性：只能在当前函数或代码块中访问。

extern关键字

如果要在多个文件中使用外部变量，只需在一个文件中包含该变量的含义。
```cpp
// file0
extern int cats = 20;
int dogs = 22;
// file1
extern int cats;
extern int dogs;
```

static关键字
使得变量的作用域在内部。
```cpp
// file1
int errors = 20;
// file2
static int errors = 30; // 只在file2中有用，并隐藏外部变量
cout << errors <<< endl; // 30
```

const关键字
默认为内部链接性
```cpp
// 默认为内部链接性
const int figners = 20;
// 只有未使用extern的const才能初始化
extern const int figners; // 不能被初始化 
```

名称空间namespace
```cpp
namespace Jill {
    // ...正常程序...
    int use;
    void solve();
}
// 使用
Jill::use;
Jill::solve();
```
声明
```cpp
using Jill::use;
int t = use;
```
编译
```cpp
using namespace Jill;
int t = use;
solve();
```

## 第十章重点

定义头文件
```cpp
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
```

实现类函数
```cpp
void Stock::sell(long num, double price) {
	using std::cout;
	if(num < 0) {
		cout << "Number of shares sold can't be negative." << "Transaction is aborted\n";
	} else if(num > shares) {
		cout << "You can't sell more than you have!" << "Transaction is aborted.\n";
	} else {
		shares -= num;
		share_val = price;
		set_tot();
	}
}
```

const 在类中的使用
在函数后使用const能让this无法修改对象
```cpp
const Stock & Stock::(const Stock & s) const {}
```

类作用域的常量
```cpp
class Barkery {
    static const int Month = 2;
    // 或者
    enum{Months=12}
}
```

## 第十一章重点

运算符重载
```cpp
Time A,B;
int a = 2;
A = B+a;
// 等价于
A = B.operator(a);
```
但如果把a放在前面便会出错。
```cpp
A = a+B；
A = a.operator(B);
```
所以必须声明这样的函数
```cpp
Time operator+(int a, const Time& b)const{}
// 这样子便会调用
A = operator(a,B);
```
但是存在一个问题，即B无法访问内部的私有变量。因此需要引用友元函数。
在头文件中加入`friend`声明。在具体实现中不需要声明`friend`。
```cpp
friend Time operator+(int a, const Time& b)const;
```

自动转换和强制转换，转换函数
使用构造函数来进行强制转换
```cpp
// 构造函数
Stonewt(double lbs);

Stonewt mycat;
mycat = 19.6; // Stonewt(19.6)
```
加入`explict`可以关闭这种转换。
使用转换函数
1. 转换函数必须是类方法
2. 转换函数不能指定返回类型
3. 转换函数不能有参数

```cpp
operator int() const;
operator double() const;
```
