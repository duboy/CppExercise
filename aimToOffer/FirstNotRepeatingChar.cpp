#include <iostream>
#include <stdio.h>
#include <map>
#include <vector>
#include <string>
using namespace std; 

class Solution {
public:
    int FirstNotRepeatingChar(string str) 
	{
		if (str.size() == 0)
			return -1;
        int *table = new int[256];
		for (int i = 0; i < 256; ++i)
			table[i] = 0;
		
		for (int i = 0; i < str.size(); ++i)
			++table[str[i]];
		for (int i = 0; i < str.size(); ++i)
		{
			if (table[str[i]] == 1)
			{
				delete []table;
				return i;
			}
				
		}
		delete []table;
		return -1;
    }
};

int main()
{
	string str("google");
	Solution sol;
	cout << sol.FirstNotRepeatingChar(str);
}