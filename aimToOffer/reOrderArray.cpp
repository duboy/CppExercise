#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    void reOrderArray(vector<int> &array) 
	{
        vector<int> odd, even;
		
		for (auto i : array)
		{
			if (i % 2)
				odd.push_back(i);
			else
				even.push_back(i);
		}
		array.clear();
		for (auto i : odd)
			array.push_back(i);
		for (auto i : even)
			array.push_back(i);
    }
};

int main()
{
	Solution sol;
	vector<int> array = {1, 2, 3, 4, 5};
	sol.reOrderArray(array);
	for (auto i : array)
		cout << i << " ";
}