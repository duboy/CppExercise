#include <iostream>
#include <stdio.h>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std; 

class Foo
{
public:
	Foo() : a(5) {}
	int a;
};

class String
{
public:
	/**/
	//String() {}
	//String(char * s) : str(s) {}
	//String(String &strs) {}
private:
	/*
	*****当有指针时vs工程的默认构造函数会把其他成员变量连同指针一起初始化****
	*****这应该时VS的优化，并不是c++的特性，使用CL无参数编译不会有这样的情况****
	*/
	char *str;
	int len;
	Foo foo;
	
};

class X
{
public:
	int xfoo()
	{
		return 1;
	}
	X() : a(xfoo()) {}
	~X() {};

private:
	int b;
	int a;
	//char *ch;

};


int main()
{
	//String noun("book");
	//String verb = noun;
	String s1;

	X x;
	int a;
	cin >> a;

	return 0;
}