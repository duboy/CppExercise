#include <iostream>
#include <stdio.h>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std; 

class X {};
class Y : public virtual X {};
class Z : public virtual X {};
class A : public Y, public Z 
{
private:
	char ch; 
	int b;
	
protected:
	int c;
public:
	int a;
private:
	int a1;

};

typedef int length;

class Point3d
{
public:
	Point3d();
	~Point3d();
	void numble(length val) { _val = val; }
	length numble() { return _val; }

private:
	typedef float length;
	length _val;
};

Point3d::Point3d()
{
}

Point3d::~Point3d()
{
}

int main()
{
	X x;
	Y y;
	A a;
	Z z;


	
	cout << sizeof(z);
	return 0;
}