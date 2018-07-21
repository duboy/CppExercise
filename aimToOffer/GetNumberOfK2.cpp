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
	int a;
    int GetNumberOfK(vector<int> data ,int k) 
	{
		int start = 0, end, firstK;
		end = data.size() - 1;
		
		firstK = getFirstK(data, start, end, k);
		
		int numOfK = -1;
		for (numOfK = 0; firstK < data.size(); ++firstK)
		{
			if (data[firstK] == k)
				++numOfK;
			else 
				return numOfK;
		}
		
		return numOfK;
    }
	
	int getFirstK(vector<int> &data, int start, int end, int k)
	{
		int mid = (end + start) / 2;
		
		if (start > end)
			return -1;
		
		if (data[mid] == k)
		{
			if ( mid == 0 || (mid > 0 && data[mid - 1] != k))
				return mid;
			else 
				end = mid - 1;
		}
		else if (data[mid] > k)
			end = mid - 1;
		else if (data[mid] < k)
			start = mid + 1;
		
		return getFirstK(data, start, end, k);
	}
};

int main()
{
	vector<int> data = {1,2,3,3,3,3,4,5};

	Solution sol;
	cout << sol.GetNumberOfK(data, 3);
}