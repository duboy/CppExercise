#include <iostream>
#include <vector>
#include <stack>
using namespace std;
void printArray(vector<int> array)
{
	for (auto i : array)
		cout << i << ",";
}

class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) 
	{
		vector<int> array;
		if (matrix.empty())
			return array;
		array = *matrix.begin();
		if (matrix.size() == 1)
		{
			return array;
		}
		vector<vector<int>> left;

		for (auto i = matrix.begin() + 1; i != matrix.end() - 1; ++i)
		{
			array.push_back(*((*i).end() - 1));
			left.push_back(vector<int>(i->begin() + 1, i->end() - 1));
		}
		for (auto i = (matrix.end() - 1)->end() - 1; i != (matrix.end() - 1)->begin(); --i)
		{
			array.push_back(*i);
		}
		for (auto i = matrix.end() - 1; i != matrix.begin(); --i)
		{
			array.push_back(*((*i).begin()));
		}
		vector<int> vecReturn = printMatrix(left);
		array.insert(array.end(), vecReturn.begin(), vecReturn.end());
		return array;
    }
};


int main()
{
	// vector<int> v1 = { 1, 2, 3, 4 };
	vector<int> v1 = { 1 };
	vector<int> v2 = { 5, 6, 7, 8 };
	vector<int> v3 = { 9, 10, 11, 12};
	vector<int> v4 = { 13, 14, 15, 16};
	// vector<vector<int>> matrix = {v1, v2, v3, v4};
	vector<vector<int>> matrix = {v1};

	cout << matrix.size();
	Solution sol;
	// printArray(sol.printMatrix(matrix));

}