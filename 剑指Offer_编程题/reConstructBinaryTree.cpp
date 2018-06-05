#include <iostream>
#include <vector>
using namespace std;

//Definition for binary tree
void print(vector<int> ivec)
{

	for (auto beg = ivec.begin(); beg != ivec.end(); ++beg)
	{
		cout << *beg << " ";
	}
	cout << endl;
}
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
	int findInVin(int trg, vector<int> &vin)
	{
		int index = 0;
		for (auto beg = vin.begin(); beg != vin.end(); ++beg)
		{
			if (trg == *beg)
			{
				break;
			}
			else
				++index;
		}
		return index;
	}
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) 
	{
		if (pre.empty())
			return NULL;
		TreeNode* root = new TreeNode(pre[0]);
		int rootInVin = findInVin(pre[0], vin);
		int size = pre.size();
		
		if (size == 1)
		{
			return root;
		}

		vector<int> headPre(&pre[1], &pre[rootInVin + 1]); 
		vector<int> headVin(&vin[0], &vin[rootInVin]); 
		// print(headPre);
		// print(headVin);
		
		vector<int> rearPre(&pre[rootInVin + 1], &pre[size]); 
		vector<int> rearVin(&vin[rootInVin + 1], &vin[size]); 
		
		// print(rearPre);
		// print(rearVin);
		
		root->left = reConstructBinaryTree(headPre, headVin);
		root->right = reConstructBinaryTree(rearPre, rearVin);
		
		return root;
    }
};

void preOrder(TreeNode *node)
{
    if(node){
        std::cout<<node->val;
        preOrder(node->left);
        preOrder(node->right);
    }

}
int main()
{
	vector<int> pre = {1, 2, 4, 7, 3, 5, 6, 8};
	vector<int> vin = {4, 7, 2, 1, 5, 3, 8, 6};
	// vector<int> pre = {4, 7};
	// vector<int> vin = {4, 7};
	Solution sol;
	preOrder(sol.reConstructBinaryTree(pre, vin));
	
}