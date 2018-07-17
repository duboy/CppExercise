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
	static bool Compare(string &s1, string &s2)
	{
		string temp1 = s1 + s2;
		string temp2 = s2 + s1;
		if (strcmp(temp1.c_str(), temp2.c_str()) <= 0)
			return true;
		else if (strcmp(temp1.c_str(), temp2.c_str()) > 0)
			return false;

		return true;
	}

    string PrintMinNumber(vector<int> numbers) 
	{
		vector<string> strNum;
		for (auto i : numbers)
			strNum.push_back(to_string(i));

		sort(strNum.begin(), strNum.end(), Compare);
		string str;
		for (auto &i : strNum)
			str += i;

		return str;
    }
};

int main()
{
	// vector<int> numbers = { 3, 32, 321};
	// vector<int> numbers = {3,323,32123};
	vector<int> numbers = {3,5,1,4,2};
	Solution sol;
	cout << sol.PrintMinNumber(numbers);
}