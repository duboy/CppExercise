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
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
		if (matrix == nullptr || rows < 1 || cols < 1 || str == nullptr)
			return false;

		bool *visited = new bool[rows * cols];
		memset(visited, 0, rows * cols);

		int pathLength = 0;
		for (int row = 0; row < rows; ++row)
		{
			for (int col = 0; col < cols; ++col)
			{
				if (hasPathCore(matrix, rows, cols, row, col, str, pathLength, visited))
				{
					return true;
				}
			}
		}

		delete[] visited;
		return false;

    }

	bool hasPathCore(const char *matrix, int rows, int cols, int row,
		int col, const char *str, int &pathLength, bool *visited)
	{
		if (str[pathLength] == '\0')
			return true;

		bool hasPath = false;

		if (row >= 0 && row < rows && col >= 0 && col < cols
			&& matrix[row * cols + col] == str[pathLength] && !visited[row * cols + col])
		{
			++pathLength;
			visited[row * cols + col] = true;

			hasPath = hasPathCore(matrix, rows, cols, row, col - 1,
				str, pathLength, visited)
				|| hasPathCore(matrix, rows, cols, row - 1, col,
					str, pathLength, visited)
				|| hasPathCore(matrix, rows, cols, row, col + 1,
					str, pathLength, visited)
				|| hasPathCore(matrix, rows, cols, row + 1, col,
					str, pathLength, visited);

			if (!hasPath)
			{
				--pathLength;
				visited[row * cols + col] = false;
			}					
		}
		return hasPath;
	}
};

int main()
{
	char matrix[] = {'a', 'b', 'c', 'e', 's', 'f', 'c', 's', 'a', 'd', 'e', 'e'};
	char str[] = "bcced";
	Solution sol;
	cout << sol.hasPath(matrix, 3, 4, str);
}