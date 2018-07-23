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
    vector<int> FindNumbersWithSum(vector<int> array,int sum) 
	{
		int ahead = 0;
		int behind = array.size() - 1;

		while (ahead < behind)
		{
			int curSum = array[ahead] + array[behind];
			if (curSum == sum)
				return{ array[ahead], array[behind] };
			else if (curSum < sum)
				++ahead;
			else
				--behind;
		}
    }
};

void printV(vector<int> &ivec)
{

	for (auto &i : ivec)
		cout << i << " ";
	
	cout << endl;

}

int main()
{
	vector<int> ivec = {1, 2, 4, 7, 11, 15};
	Solution sol;
	auto reslut = sol.FindNumbersWithSum(ivec, 3);
	
	printV(reslut);
}