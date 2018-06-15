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
    ListNode* ReverseList(ListNode* pHead) 
	{
		if (pHead == NULL || pHead->next == NULL)
			return pHead;
		ListNode *pNNext = NULL, *pNext = pHead->next;
		pHead->next = NULL;
		while (pNext)
		{
			pNNext = pNext->next;
			pNext->next = pHead;
			pHead = pNext;
			pNext = pNNext;
		}
		
		return pHead;
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
	ListNode a1(1), a2(2), a3(3), a4(4), a5(5), a6(6), b1(0);;
	a1.next = &a2;
	a2.next = &a3;
	a3.next = &a4;
	a4.next = &a5;
	a5.next = &a6;

	Solution sol;
	auto resl = sol.ReverseList(&a1);
	//cout << resl->val;
	printList(resl);
}