#include <iostream>
#include <vector>
#include <stack>
#include<queue>
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
	vector<vector<int>> Mat;
    vector<vector<int>> FindPath(TreeNode* root,int expectNumber) 
	{
		if (root == nullptr)
			return Mat;
		vector<int> path;
		int sum = 0;
		addPath(root, expectNumber, path, sum);

		return Mat;
    }

	void addPath(TreeNode* root, int expectNumber, vector<int> &path, int sum)
	{
		sum += root->val;
		path.push_back(root->val);

		bool isLeaf = root->left == nullptr && root->left == nullptr;
		if (sum == expectNumber && isLeaf)
		{
			Mat.push_back(path);
		}

		if (root->left != nullptr)
			addPath(root->left, expectNumber, path, sum);
		if (root->right != nullptr)
			addPath(root->right, expectNumber, path, sum);

		path.pop_back();
	}

};

void printMat(vector<vector<int> > Mat)
{
	for (auto m : Mat)
	{
		for (auto i : m)
			cout << i << " ";
		cout << endl;
	}		
}

int main()
{
	TreeNode a1(8), a2(8), a3(9), a4(2), a5(5);
	TreeNode b1(8), b2(9), b3(3), b4(2);

	a1.right = &a2;
	a2.right = &a3;
	a3.right = &a4;
	a4.right = &a5;

	b1.right = &b2;
	b2.left = &b3;
	b2.right = &b4;

	TreeNode *pRoot1 = new TreeNode(8);
	pRoot1->left = new TreeNode(8);
	pRoot1->right = new TreeNode(7);
	pRoot1->left->left = new TreeNode(9);
	pRoot1->left->right = new TreeNode(2);
	pRoot1->left->right->left = new TreeNode(4);
	pRoot1->left->right->right = new TreeNode(7);

	TreeNode *pRoot2 = new TreeNode(8);
	pRoot2->left = new TreeNode(9);
	pRoot2->right = new TreeNode(2);

	Solution sol;
	printMat(sol.FindPath(pRoot1, 22));
	
}