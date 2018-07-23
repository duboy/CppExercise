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
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) 
	{
		if (data.size() < 2)
			return;

		int resultExclusiveOR;
		for (auto &i : data)
			resultExclusiveOR ^= i;

		int mask = 1;

		while ((resultExclusiveOR & 1) == 0)
		{
			resultExclusiveOR = resultExclusiveOR >> 1;
			mask = mask << 1;
		}

		for (auto &i : data)
		{
			if (i & mask)
				*num1 ^= i;
			else
				*num2 ^= i;
		}

    }
};

int main()
{
	vector<int> ivec = {2, 4, 3, 6, 3, 2, 5, 5};
	int first = 0, sec = 0;

	Solution sol;
	sol.FindNumsAppearOnce(ivec, &first, &sec);
	cout << first << " " << sec;
}