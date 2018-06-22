#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
	stack<int> data;
	stack<int> minData;
    void push(int value) 
	{
		if (data.empty())
			minData.push(value);
		else
			minData.push(value < minData.top() ? value : minData.top());
		data.push(value);
		
    }
    void pop() 
	{
		if (data.empty())
			throw "error! stack is empty.";
		else
		{
			data.pop();
			minData.pop();
		}
    }
    int top() 
	{
		return data.top();
    }
    int min() 
	{
		return minData.top();
    }
};

int main()
{
	Solution sol;
	sol.push(1);
	sol.push(2);
	sol.push(3);
	sol.push(3);
	cout << sol.min() << " ";
	sol.pop();
	cout << sol.min() << " ";
	
	
	
}