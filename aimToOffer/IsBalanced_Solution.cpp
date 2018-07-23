#include <iostream>
#include <vector>
#include <stack>
#include<queue>
#include<string>
#include<set>
#include <functional> 
using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};

class Solution {
public:
	bool IsBalanced_Solution(TreeNode* pRoot)
	{
		int depth = 0;
		return IsBalanced(pRoot, depth);
	}

	bool IsBalanced(TreeNode * pRoot, int &depth)
	{
		if (pRoot == nullptr)
		{
			depth = 0;
			return true;
		}

		int left, right;

		if (IsBalanced(pRoot->left, left) && IsBalanced(pRoot->right, right))
		{
			int diff = left - right;
			if (diff <= 1 && diff >= -1)
			{
				depth = 1 + (left > right ? left : right);
				return true;
			}
		}

		return false;
	}
};

int main()
{
	TreeNode t1(5), t2(3), t3(7), t4(2), t5(4), t6(6), t7(8);

	t1.left = &t2;
	t1.right = &t3;

	t2.left = &t4;
	t2.right = &t5;

	t3.left = &t6;
	t3.right = &t7;


	Solution sol;
	cout << sol.IsBalanced_Solution(&t1);
}