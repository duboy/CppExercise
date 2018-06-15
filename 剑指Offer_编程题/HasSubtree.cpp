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
class Solution 
{
public:
    bool HasSSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
		if (pRoot1 == nullptr)
			return false;
		if (pRoot2 == nullptr)
			return true;
		if((pRoot1->val == pRoot2->val) && (pRoot1->left == pRoot1->right))
			return true;
		
		if(pRoot1->val != pRoot2->val)
		{
			return false;
		}
		else
		{
			// if (HasSSubtree(pRoot1->left, pRoot2->left))
				return HasSSubtree(pRoot1->right, pRoot2->right) && HasSSubtree(pRoot1->left, pRoot2->left);
			// else
				// return  false;
		}
    }
	
	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
	{
		bool result;
		if (pRoot1 == NULL || pRoot2 == NULL)
			return false;
		if (HasSSubtree(pRoot1, pRoot2))
			return true;
		
		if (pRoot1 != NULL)
		{
			if (HasSSubtree(pRoot1, pRoot2))
				return true;
			if (HasSubtree(pRoot1->left, pRoot2))
			{
				return true;
			}
			else
			{
				if (pRoot1 != NULL)
					return HasSubtree(pRoot1->right, pRoot2);
				else 
					return false;
			}
		}


		
		return false;
	}

};

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
	cout << sol.HasSSubtree(&a2, &b1);
	// cout << sol.HasSubtree(pRoot1, pRoot2);
}