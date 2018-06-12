#include <iostream>
#include <vector>
#include <stack>
using namespace std;


class Solution {
public:
    double Power(double base, int exponent)
	{
		if (exponent == 0)
			return 1;
		double resl = base;
		double exponent_abs = exponent;
		if (exponent < 0)
		{
			exponent_abs = -1 * exponent;
		}
		while (--exponent_abs > 0)
		{
			resl *= base;
		}
		if (exponent < 0)
			return 1 / resl;
		else
			return resl;
    }
};

int main()
{
	Solution sol;
	cout << sol.Power(2, -3);
}