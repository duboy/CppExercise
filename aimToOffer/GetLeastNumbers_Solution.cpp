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
	vector<int> GetLeastNumbers_Solution(vector<int> input, int k)
	{
		if (k < 1 || input.size() < k)
			return{};
		multiset<int, greater<int>> reslset;
		for (auto &i : input)
		{
			if (reslset.size() < k)
				reslset.insert(i);
			else
			{
				if (i < *(reslset.begin()))
				{
					reslset.erase(reslset.begin());
					reslset.insert(i);
				}
			}
		}
		vector<int> resl;
		for (auto i = reslset.rbegin(); i != reslset.rend(); ++i)
			resl.push_back(*i);
		return resl;

	}
};

template <typename Comparable>
void printVec(vector<Comparable> &items)
{
	for (auto &i : items)
	{
		cout << i << " ";
	}
}

int main()
{
	vector<int> numbers = { 4,5,1,6,2,7,3,8 };
	Solution sol;
	vector<int> resl;
	resl = sol.GetLeastNumbers_Solution(numbers, 4);
	printVec(resl);
}