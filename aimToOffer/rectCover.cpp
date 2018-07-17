#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int rectCover(int number) 
	{
		int step1 = 1, step2 = 2, temp = 0, i = 0;
		if (number < 3)
			return number;
		while (i++ < number - 2 )
		{
			temp = step2;
			step2 = step2 + step1;
			step1 = temp;
		}
		return step2;
    }
};

int main()
{
	Solution sol;
	cout << sol.rectCover(4);
}