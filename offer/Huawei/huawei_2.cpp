#include <iostream>
#include <stdio.h>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
using namespace std; 

string lsubstr(const string &str)
{
	vector<string> vStr;
	for (size_t i = 0; i < str.size(); ++i)
		vStr.push_back(str.substr(i));

	sort(vStr.begin(), vStr.end());

	int max = 0;
	int flag = 0;

	for (size_t i = 0; i < (vStr.size() - 1); ++i)
	{
		size_t j = 0;
		while (vStr[i][j] == vStr[i + 1][j] && j < vStr[i].size() && j < vStr[i + 1].size())
		{
			++j;
		}

		if (j > max)
		{
			max = j;
			flag = i;
		}
	}
    return vStr[flag].substr(0, max);
}

int main()
{
	string str;
	cin >> str;

	string substr = lsubstr(str);

	cout << substr << ' ' << substr.length();
}