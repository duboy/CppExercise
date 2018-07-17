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
    int NumberOf1Between1AndN_Solution(int n)
    {
		if (n <= 0)
			return 0;

		char strN[50];
		sprintf(strN, "%d", n);

		return Numberof1(strN);
    }

	int Numberof1(const char *strN)
	{
		if (!strN || *strN < '0' || *strN > '9' || *strN == '\0')
			return 0;

		int first = *strN - '0';
		int length = strlen(strN);

		if (length == 1 && first == 0)
			return 0;
		if (length == 1 && first == 1)
			return 1;

		int numFirstDigit = 0;
		if (first > 1)
			numFirstDigit = PowerBase10(length - 1);
		else if (first == 1)
			numFirstDigit = atoi(strN + 1) + 1;

		int numOtherDigits = first * (length - 1) * PowerBase10(length - 2);

		int numRecurisve = Numberof1(strN + 1);

		return numFirstDigit + numOtherDigits + numRecurisve;
	}

	int PowerBase10(int n)
	{
		int result = 1;
		for (int i = 0; i < n; ++i)
			result *= 10;

		return result;
	}
};

int main()
{
	Solution sol;
	cout << sol.NumberOf1Between1AndN_Solution(55);

	string str("123");

}