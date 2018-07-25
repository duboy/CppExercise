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

int main(){

	Bell b;
	Whistle w;

	Bell &bb = b;

	flip(b);
	flip(w);

	
	return 0;
}