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
    int GetNumberOfK(vector<int> data ,int k) 
	{
		int start = 0, end, firstK;
		end = data.size() - 1;
		
		firstK = getFirstK(data, start, end, k);
		
		int numOfK = 0;
		for (; firstK < data.size(); ++firstK)
		{
			if (data[firstK] == k)
				++numOfK;
			else 
				return numOfK;
		}
		
		return -1;
    }
	
	int getFirstK(vector<int> &data, int start, int end, int k)
	{
		int mid = (end + start) / 2;
		
		if (start == end)
			return start;
		
		if (end - start == 1)
			return data[start] == k ? start : end;
		
		if (data[mid] >= k)
			end = mid;
		else if (data[mid] < k)
			start = mid;
		
		return getFirstK(data, start, end, k);
	}
};

int main()
{
	vector<int> data = {1,2,3,3,3,3,4,5};

	Solution sol;
	cout << sol.GetNumberOfK(data, 3);
}