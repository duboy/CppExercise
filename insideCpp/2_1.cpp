#include <iostream>
#include <stdio.h>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std; 

template <typename Comparable>
void printVec(vector<Comparable> &items)
{
	for (auto &i : items)
	{
		cout << i << " ";
	}
}

class Widget
{
public:
	virtual void flip() const = 0;
};

class Bell : public Widget
{
public:
	void flip() const
	{
		cout << "Bell";
	}
};

class Whistle : public Widget
{
public:
	void flip() const
	{
		cout << "Whistle";
	}
};

void flip(const Widget &widget) { widget.flip(); }

class X { public: int i; };
class A : public virtual X { public: int j; };
class B : public virtual X { public: double d; };
class C : public A, public B { public: int K; };

void foo( A* pa)
{
	pa->i = 1024;
}

int main()
{
	C c;
	foo(new A);
	foo(new C);

	Bell b;
	Whistle w;

	Bell &bb = b;

	flip(b);
	flip(w);

	
	return 0;
}