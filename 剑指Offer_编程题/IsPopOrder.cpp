#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution 
{
public:
	stack<int> pushS;
    bool IsPopOrder(vector<int> pushV,vector<int> popV) 
	{
		for (auto pushBeg = pushV.begin(), popBeg = popV.begin(); popBeg != popV.end(); ++popBeg)
		{
			while (pushBeg != pushV.end() && *pushBeg != *popBeg )
			{
				pushS.push(*(pushBeg++));
			}
			if (pushBeg != pushV.end())
			{
				if (*pushBeg == *popBeg)
					++pushBeg;
			}
			else if (pushBeg == pushV.end())
			{
				if (pushS.top() == *popBeg)
					pushS.pop();
			}

		}
		if (pushS.empty())
			return true;
		else
			return false;
    }
};

int main()
{
	vector<int> pushV = { 1, 2, 3, 4, 5 };
	vector<int> popV = { 4, 5, 3, 2, 1 };
	Solution sol;
	cout << sol.IsPopOrder(pushV, popV);
}