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
	vector<int> array;
    vector<int> printMatrix(vector<vector<int> > matrix) 
	{
		int row, col;
		int head = 0;
		row = matrix.size();
		col = matrix.begin()->size();

		while (col > head * 2 && row > head * 2)
			printMat(matrix, col, row, head++);
		return array;
	}
	
	void printMat(vector<vector<int> > &matrix, int row, int col, int head)
	{
		
		int endX = row - head - 1;
		int endY = col - head - 1;
			
 		for (int i = head; i <= endX; ++i)
			array.push_back(matrix[head][i]);
		
		if (head < endY)
			for (int i = head + 1; i <= endY; ++i)
				array.push_back(matrix[i][endX]);
		if (head < endX && head < endY)
			for (int i = endX - 1; i >= head; --i)
				array.push_back(matrix[endY][i]);
		if (head < endX && head < endY - 1)
			for (int i = endY - 1; i >= head + 1; --i)
				array.push_back(matrix[i][head]);
	}
};


int main()
{
	// vector<int> v1 = { 1, 2, 3, 4 };
	vector<int> v1 = { 1 };
	vector<int> v2 = { 2 };
	vector<int> v3 = { 3};
	vector<int> v4 = { 4};
	vector<vector<int>> matrix = {v1, v2, v3, v4};
	// vector<vector<int>> matrix = {v1};

	// cout << matrix.size();
	Solution sol;
	printArray(sol.printMatrix(matrix));

}