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
    int TreeDepth(TreeNode* pRoot)
    {
		if (!pRoot)
			return 0;
		int nLeft = TreeDepth(pRoot->left);
		int nRight = TreeDepth(pRoot->right);

		return (nLeft > nRight) ? (nLeft + 1) : (nRight + 1);

    }
};

void print(TreeNode *root)
{
	if (!root)
		return;
	print(root->left);
	cout << root->val;
	print(root->right);
}

void printVec(vector<int> ivec)
{
	for (auto i : ivec)
		cout << i << " ";
}

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
	cout << sol.TreeDepth(&t1);

}