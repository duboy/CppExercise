#include <iostream>
#include <stdio.h>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std; 

class A
{
public:
	~A()
	{
		cout << "deconstruct A" << endl;
	}
	void virtual exec() = 0;

private:

};

class B : public A
{
public:
	~B()
	{
		cout << "deconstruct B" << endl;
	}

	void exec() {}

private:

};


int main()
{
	A *b = new B;

	delete b;

	system("pause");

}