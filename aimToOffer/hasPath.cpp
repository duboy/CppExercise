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
			for ()
		}
    }
};

int main()
{
	char matrix[] = {'a', 'b', 'c', 'e', 's', 'f', 'c', 's', 'a', 'd', 'e', 'e'};
	char str[] = "bcced";
	Solution sol;
	cout << sol.hasPath(matrix, 3, 4, str);
}