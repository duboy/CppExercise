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
    string LeftRotateString(string str, int n) 
	{
		if (str.size() == 0)
			return str;
		n = n % str.size();
        reverse(str.begin(), str.begin() + n);
		reverse(str.begin() + n , str.end());
		reverse(str.begin(), str.end());
		return str;
    }
};

int main()
{
	string str = "abcdefg";
	//reverse(str.begin(), str.end());

	Solution sol;
	cout << sol.LeftRotateString(str, 9);
}