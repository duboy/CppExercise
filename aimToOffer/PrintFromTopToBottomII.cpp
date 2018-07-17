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
	
    vector<int> PrintFromTopToBottom(TreeNode* root) 
	{
		vector<int> ivec;
		if (!root)
			return ivec;
		
		queue<TreeNode* > queTreeNode;
		queTreeNode.push(root);

		while (queTreeNode.size())
		{
			TreeNode *pNode = queTreeNode.front();
			ivec.push_back(pNode->val);
			queTreeNode.pop();
			if (pNode->left)
				queTreeNode.push(pNode->left);
			if (pNode->right)
				queTreeNode.push(pNode->right);
		}



		return ivec;
    }
};

void print(TreeNode *root)
{
	if (!root)
		return;
	cout << root->val;
	print(root->left);
	print(root->right);
}

void printVec(vector<int> ivec)
{
	for (auto i : ivec)
		cout << i << " ";
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
	printVec(sol.PrintFromTopToBottom(pRoot1));
	
}