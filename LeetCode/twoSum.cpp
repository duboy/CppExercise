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

class Solution_1 {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		multimap<int, int> imap;
		int i = 0;
		for (const auto num : nums)
			imap.insert(make_pair(num, i++));

		for (const auto num : nums)
		{
			if ((--imap.upper_bound(target - num))->second != 0)
				return{ imap.find(num)->second, (--imap.upper_bound(target - num))->second };
		}
		return{ 1, 2 };
	}
};

void printVec(const vector<int> &nums)
{
	for (auto i : nums)
		cout << i << " ";
}

int main()
{
	Solution_1 sol;
	vector<int> ivec = { 2,5,5,11 };
	auto resl = sol.twoSum(ivec, 10);

	printVec(resl);
}