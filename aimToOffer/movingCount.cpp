#include <iostream>
#include <stdio.h>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std; 

class Solution 
{
public:
    int movingCount(int threshold, int rows, int cols)
    {
		bool *visited = new bool[rows * cols];
		for (int i = 0; i < rows * cols; ++i)
			visited[i] = false;

		int count = movingCountCore(threshold, rows, cols, 0, 0, visited);

		delete[] visited;
		
		return count;

    }

	int movingCountCore(int threshold, int rows, int cols, int row, int col, bool *visited)
	{
		int count = 0;
		if (check(threshold, rows, cols, row, col, visited))
		{
			visited[row * cols + col] = true;
			count += 1 + movingCountCore(threshold, rows, cols, row - 1, col, visited)
				+ movingCountCore(threshold, rows, cols, row, col - 1, visited)
				+ movingCountCore(threshold, rows, cols, row + 1, col, visited)
				+ movingCountCore(threshold, rows, cols, row, col + 1, visited);
		}

		return count;
	}

	bool check(int threshold, int rows, int cols, int row, int col, bool *visited)
	{
		if (row >= 0 && col >= 0 && !visited[row * cols + col]
			&& row < rows && col < cols
			&& getDigitSum(row) + getDigitSum(col) <= threshold)
			return true;
		else
			return false;

	}

	int getDigitSum(int number)
	{
		int sum = 0;
		while (number)
		{
			sum += number % 10;
			number /= 10;
		}
		
		return sum;
	}
};

int main()
{
	Solution sol;
	cout << sol.movingCount(10, 10, 10);
}