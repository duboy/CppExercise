#include <iostream>
#include <vector>
#include <stack>
#include<queue>
#include<string>
using namespace std;

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) 
	{
		int length = numbers.size();
		if (length == 0)
			return 0;

		int result = numbers[0];
		int times = 0;
		
		for (auto &i : numbers)
		{
			if (i == result)
				++times;
			else
			{
				if (--times == 0)
				{
					result = i;
					times = 1;
				}
			}
		}
		times = 0;
		for (auto &i : numbers)
		{
			if (i == result)
				++times;
		}
		if (times < length / 2 + 1)
			return 0;

		return result;
    }
};

int main()
{
	vector<int> numbers = {4,2,1,4,2,4};
	Solution sol;
	cout << sol.MoreThanHalfNum_Solution(numbers);
}