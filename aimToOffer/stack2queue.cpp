#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    void push(int node) 
	{
        stack1.push(node);
    }

    int pop() 
	{
		int rear;
		if (!stack2.empty())
		{
			rear = stack2.top();
			stack2.pop();
			return rear;
		}
		
        while (!stack1.empty())
		{
			stack2.push(stack1.top());
			stack1.pop();
		}
		
		rear =  stack2.top();
		stack2.pop();
		return rear;
		
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};

int main()
{
	Solution sol;
}