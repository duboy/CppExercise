#include <iostream>
#include <vector>
#include <stack>
#include<queue>
#include<string>
#include<set>
#include <functional> 
using namespace std;

class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) 
	{
		int sum = -10000;
		int currSum = 0;
		for (auto &i : array)
		{
			if (currSum < 0)
				currSum = i;
			else
				currSum += i;
			if (currSum > sum)
 				sum = currSum;

		}

		return sum;
    }
};

int main()
{
	vector<int> numbers = {1,-2,3,10,-4,7,2,-5};
	Solution sol;
	cout << sol.FindGreatestSumOfSubArray(numbers);

}