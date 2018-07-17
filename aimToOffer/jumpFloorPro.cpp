#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int jumpFloorII(int number) 
	{
		int step = 1;
		while (--number > 0)
		{
			step *= 2;
		}
		return step;
    }
};

int main()
{
	Solution sol;
	cout << sol.jumpFloorII(4);
}