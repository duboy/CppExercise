#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) 
	{
		if (pListHead == NULL)
			return NULL;
		ListNode* pFront  = pListHead;
		ListNode* pResult = pListHead;

		while(--k)
		{
			if (pFront->next)
				pFront = pFront->next;
			else 
				return NULL;
		}

		while (pFront->next)
		{
			pFront = pFront->next;
			pResult = pResult->next;
		}
		return pResult;
    }
};

int main()
{
	ListNode a1(1), a2(2), a3(3), a4(4), a5(5), a6(6), b1(0);;
	a1.next = &a2;
	a2.next = &a3;
	a3.next = &a4;
	a4.next = &a5;
	a5.next = &a6;

	Solution sol;
	auto resl = sol.FindKthToTail(&b1, 1);
	if (resl == NULL)
		cout << "NULL";
	else
		cout << resl->val;
}