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

void test(int *t)
{
	*t = 1233;
}
int foo(int a ...)
{
	return *(&a + 1);
}
int main(){
	const char * de = "sdfsdf" "FFFFFFsdfsd";
	cout << foo(1, 2, 3, "abcdsw");
	int a[5] = {1, 5, 2, 3, 54};
	
	sort(a, a+5);
	
	return 0;
}