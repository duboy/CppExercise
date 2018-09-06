#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		vector<vector<int>> F(triangle.size(), vector<int>(triangle[triangle.size() - 1].size(), numeric_limits<int>::max()));

		int minSum = numeric_limits<int>::max();
		F[0][0] = triangle[0][0];

		for (int i = 1; i < triangle.size(); ++i)
		{
			for (int j = 0; j < triangle[i].size(); ++j)
			{
				if (j == 0)
					F[i][j] = F[i - 1][j] + triangle[i][j];
				else
					F[i][j] = min(F[i - 1][j], F[i - 1][j - 1]) + triangle[i][j];
			}
		}
		for (auto i : F[F.size() - 1])
			minSum = minSum < i ? minSum : i;

		return minSum;
	}
};

int main()
{
	Solution sol;

	vector<vector<int>> triangle = { {2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3 } };

	cout << sol.minimumTotal(triangle);

}