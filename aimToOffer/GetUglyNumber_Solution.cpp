#include <iostream>
#include <vector>
#include <stack>
#include<queue>
#include<string>
#include<set>
#include <functional> 
using namespace std;

class Solution 
{
public:
    int GetUglyNumber_Solution(int index) 
	{
		if (index <= 0)
			return 0;

		int *pUglyNumbers = new int[index];
		pUglyNumbers[0] = 1;
		int nextUglyIndex = 1;

		int *pMultiply2 = pUglyNumbers;
		int *pMultiply3 = pUglyNumbers;
		int *pMultiply5 = pUglyNumbers;

		while (nextUglyIndex < index)
		{
			int min = std::min(std::min(*pMultiply2 * 2, *pMultiply3 * 3), *pMultiply5 * 5);
			pUglyNumbers[nextUglyIndex] = min;

			while (*pMultiply2 * 2 <= pUglyNumbers[nextUglyIndex])
				++pMultiply2;
			while (*pMultiply3 * 3 <= pUglyNumbers[nextUglyIndex])
				++pMultiply3;
			while (*pMultiply5 * 5 <= pUglyNumbers[nextUglyIndex])
				++pMultiply5;

			++nextUglyIndex;
		}

		int ugly = pUglyNumbers[nextUglyIndex - 1];
		delete[] pUglyNumbers;

		return ugly;
    
    }
};

int main()
{
	Solution sol;
	cout << sol.GetUglyNumber_Solution(1500);
}