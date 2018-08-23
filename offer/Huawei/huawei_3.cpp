#include <iostream>
#include <stdio.h>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <stack>
using namespace std; 

int lvaildC(string &str)
{
	stack<int> SC;
	int max;

	for (size_t i = 0; i < str.size(); ++i)
	{
		if (str[i] == ')' && !SC.empty() && str[SC.top()] == '(')
		{
			SC.pop();
			if (SC.empty())
				max = i + 1;
			else if (i - SC.top() > max)
				max = i - SC.top();
		}
		else
			SC.push(i);
	}
	return max;
}

int main()
{
	string in;
	cin >> in;
	cout << lvaildC(in);
}