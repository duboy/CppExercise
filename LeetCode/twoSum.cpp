#include <iostream>
#include <stdio.h>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std; 

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
	{
		int pre = 0, behind = 1;

		for (int i = 0; i < nums.size(); ++i)
			for (int j = i + 1; j < nums.size(); ++j)
			{
				if (nums[i] + nums[j] == target)
					return{ i, j };
			}
    }
};

void printVec(const vector<int> &nums)
{
	for (auto i : nums)
		cout << i << " ";
}

int main()
{
	Solution sol;
	vector<int> ivec = { 3, 2, 4 };
	auto resl = sol.twoSum(ivec, 6);

	printVec(resl);
}