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
    int GetNumberOfK(vector<int> data ,int k) 
	{
		int i = 0;
		for (auto &ivec : data)
		{
			if (ivec == k)
				++i;
		}

		return i;
    }
};

int main()
{
	vector<int> data = {1, 2, 3, 3, 4};

	Solution sol;
	cout << sol.GetNumberOfK(data, 3);
}