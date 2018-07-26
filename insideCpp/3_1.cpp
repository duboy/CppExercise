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
class A : public Y, public Z {};

int main()
{
	X x;
	Y y;
	Z z;
	A a;
	cout << sizeof(z);
	return 0;
}