#include <iostream>
#include <stdio.h>
#include <map>
#include <vector>
#include <string>
using namespace std; 

template <typename Comparable>
void printVec(vector<Comparable> &items)
{
	for (auto &i : items)
	{
		cout << i << " ";
	}
}

void test(int *t)
{
	*t = 1233;
}

int main()
{
	const char * de = "sdfsdf" "FFFFFFsdfsd";
	
	cout << de;

	return 0;
}