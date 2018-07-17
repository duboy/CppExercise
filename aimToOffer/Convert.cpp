#include <iostream>
#include <vector>
#include <stack>
#include<queue>
#include<string>
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
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
		TreeNode *pLastNode = nullptr;
		ConvertNode(pRootOfTree, &pLastNode);
		
		
		TreeNode *pHead = pLastNode;
		while (pHead != nullptr && pHead->left != nullptr)
			pHead = pHead->left;
		
        return pHead;
    }
	
	void ConvertNode(TreeNode *pNode, TreeNode **pLastNode)
	{
		if (pNode == nullptr)
			return;
		
		TreeNode *pCurrent = pNode;
		
		if (pCurrent->left != nullptr)
			ConvertNode(pCurrent->left, pLastNode);
		
		pCurrent->left = *pLastNode;
		if (*pLastNode != nullptr)
			(*pLastNode)->right = pCurrent;
		
		*pLastNode = pCurrent;
		
		if (pCurrent->right != nullptr)
			ConvertNode(pCurrent->right, pLastNode);
	}
};

void printList(TreeNode* root)
{
	TreeNode *root1, *b;
	while (root)
	{
		cout << root->val << " ";
		root = root->left;
	}
}

void printTree(TreeNode* root)
{
	if (root == nullptr)
		return;
	printTree(root->left);
	cout << root->val << " ";
	printTree(root->right);
}

int main()
{
	TreeNode l1(8), l2(6), l3(10), l4(5), l5(7), l6(9), l7(11);
	l1.left = &l2;
	l1.right = &l3;
	l2.left = &l4;
	l2.right = &l5;
	l3.left = &l6;
	l3.right = &l7;

	string s1;
	cout << sizeof(s1);
	
	printTree(&l1);
	
	Solution sol;
	printList(sol.Convert(&l1));

}