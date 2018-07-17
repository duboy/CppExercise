#include <iostream>
#include <stdio.h>
#include <map>
#include <vector>
#include <string>
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
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) 
	{
		int len1 = 0, len2 = 0, deltLen;

		ListNode *p1 = pHead1, *p2 = pHead2;
		while (1)
		{
			if (!p1 && !p2)
				break;
			if (p1)
			{
				++len1;
				p1 = p1->next;
			}
			if (p2)
			{
				++len2;
				p2 = p2->next;
			}

		}

		ListNode *pLang;
		ListNode *pShort;
		if (len1 > len2)
		{
			pLang = pHead1;
			pShort = pHead2;
		}
		else
		{
			pLang = pHead2;
			pShort = pHead1;
		}
			

		deltLen = abs(len1 - len2);

		while (deltLen--)
			pLang = pLang->next;

		while (pLang != pShort)
		{
			pLang = pLang->next;
			pShort = pShort->next;
		}
		return pShort;
			
    }
};

int main()
{
	ListNode l1(1), l2(2), l3(3), l4(4), l5(5), l6(6), l7(7);
	
	l1.next = &l2;
	l2.next = &l3;
	l3.next = &l6;
	l6.next = &l7;

	l4.next = &l5;
	l5.next = &l6;
	
	Solution sol;
	cout << sol.FindFirstCommonNode(&l1, &l4)->val;
}