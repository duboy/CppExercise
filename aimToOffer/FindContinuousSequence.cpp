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
	vector<vector<int> > FindContinuousSequence(int sum)
	{
		vector<vector<int>> ivvec;

		int small = 1, big = 2;

		int middle = (1 + sum) / 2;

		int curSum = small + big;

		while (small < middle)
		{
			if (sum == curSum)
				inserSeq(ivvec, small, big);

			while (curSum > sum && small < middle)
			{
				curSum -= small;
				++small;

				if (sum == curSum)
					inserSeq(ivvec, small, big);
			}

			++big;
			curSum += big;
		}

		return ivvec;
	}

	void inserSeq(vector<vector<int>> &ivvec, int small, int big)
	{
		vector<int> temp;
		while (small <= big)
		{
			temp.push_back(small++);
		}
		ivvec.push_back(temp);
	}
};

void printVV(vector<vector<int>> &ivvec)
{
	for (auto &ivec : ivvec)
	{
		for (auto &i : ivec)
			cout << i << " ";
		
		cout << endl;
	}
}

int main()
{
	Solution sol;
	auto reslut = sol.FindContinuousSequence(3);
	
	printVV(reslut);
}