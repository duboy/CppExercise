#include <iostream>
#include <vector>
#include <stack>
#include<queue>
#include<string>
using namespace std;

template <typename Comparable>
void printVec(vector<Comparable> &items)
{
	for (auto &i : items)
	{
		cout << i << " ";
	}
}

class Solution {
public:
	vector<string> svec;
    vector<string> Permutation(string str) 
	{
		if (str.length() == 0)
			return svec;
		permut(str, 0);
		sort(svec.begin(), svec.end());
        return svec;
    }
	
	void permut(string &str, int beg)
	{
		if (str.length() == beg)
		{
			if (find(svec.begin(), svec.end(), str) == svec.end())
				svec.push_back(str);

		}
		else
		{
			for (int i = beg; i < str.length(); ++i)
			{
				swap(str[i], str[beg]);
				permut(str, beg + 1);
				swap(str[i], str[beg]);
			}
		}
	}
};

int main()
{
	string str = "aab";
	Solution sol;
	swap(str[0], str[1]);
	auto resl = sol.Permutation(str);
	printVec(resl);
}