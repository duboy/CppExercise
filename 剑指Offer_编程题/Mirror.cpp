#include <iostream>
#include <vector>
#include <stack>
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
    void Mirror(TreeNode *pRoot) 
	{
		TreeNode *temp;
		if (!pRoot)
			return;
		if (!pRoot->left && !pRoot->right)
			return;
		else
		{
		temp = pRoot->left;
			pRoot->left = pRoot->right;
			pRoot->right = temp;
			Mirror(pRoot->left);
			Mirror(pRoot->right);
		}
    }

	bool isLeaf(TreeNode *pRoot)
	{
		if (!pRoot->left && !pRoot->right )
		{
			return true;
		}
		else
			return false;
	}
};

void printTree(TreeNode *pRoot)
{
	if (!pRoot)
		return;
	else
	{
		cout << pRoot->val << " ";
		printTree(pRoot->left);
		printTree(pRoot->right);
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
	// pRoot2->left->left = new TreeNode(9);
	// pRoot2->left->right = new TreeNode(2);
	
	
	Solution sol;
	//cout << sol.HasSSubtree(&a2, &b1);
	printTree(pRoot1);
	sol.Mirror(&a1);
	sol.Mirror(pRoot1);
	// cout << endl << sol.isLeaf(&a5) << endl;
	cout <<endl;
	printTree(&a1);
}