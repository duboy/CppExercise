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
	*****����ָ��ʱvs���̵�Ĭ�Ϲ��캯�����������Ա������ָͬ��һ���ʼ��****
	*****��Ӧ��ʱVS���Ż���������c++�����ԣ�ʹ��CL�޲������벻�������������****
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