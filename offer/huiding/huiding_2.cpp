#include <iostream>
#include <stdio.h>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <stack>
using namespace std; 

int main()
{
	string str, str2;
	cin >> str;
	for (auto s = str.begin(); s != str.end(); ++s)
	{
		if ((*s >= '0' && *s <= '9') || (*s >= 'A' && *s <= 'Z'))
			str2 += *s;

	}

	vector<string> vstr;
	string temp;
	
	for (auto s = str2.begin(); s != str2.end(); )
	{
		while (*s >= '0' && *s <= '9' && s != str2.end())
		{
			temp += *s;
			++s;
		}
		vstr.push_back(temp);
		temp.clear();
		while (s != str2.end() && *s >= 'A' && *s <= 'Z')
		{
			temp += *s;
			++s;
		}
		vstr.push_back(temp);
		temp.clear();

	}


	cout << str2;
}