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
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
		 ListNode *pHead = pHead2;
		 if (!pHead1 || !pHead2)
		 {
			 return pHead1 ? pHead1 : pHead2;
		 }
		 if (pHead1->val < pHead2->val)
		 {
			 pHead = pHead1;
			 pHead1 = pHead1->next;
		 }
		 else
		 {
			 pHead = pHead2;
			 pHead2 = pHead2->next;
		 }
		ListNode* pReturn = pHead;
		while (pHead1 && pHead2)
		{
			if (pHead1->val < pHead2->val)
			{
				pHead->next = pHead1;
				pHead = pHead1;
				pHead1 = pHead1->next;
			}
			else
			{
				pHead->next = pHead2;
				pHead = pHead2;
				pHead2 = pHead2->next;

			}
		}
		pHead->next = pHead1 ? pHead1 : pHead2;
		return pReturn;
    }
};


void printList(ListNode* pHead)
{
	while (pHead)
	{
		cout << pHead->val << " ";
		pHead = pHead->next;
	}
}

int main()
{
	ListNode a1(1), a2(3), a3(5), a4(7), a5(9), a6(11);
	ListNode b1(0), b2(2), b3(4), b4(6), b5(8), b6(10);
	a1.next = &a2;
	a2.next = &a3;
	a3.next = &a4;
	a4.next = &a5;
	a5.next = &a6;
	
	b1.next = &b2;
	b2.next = &b3;
	b3.next = &b4;
	b4.next = &b5;
	b5.next = &b6;
	
	Solution sol;
	auto resl = sol.Merge(&a1, &b1);
	printList(resl);
}