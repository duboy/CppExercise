#include <iostream>
#include <vector>
#include <stack>
#include<queue>
#include<map>
using namespace std;

struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};

class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
		if (pHead == nullptr)
			return pHead;
		RandomListNode *newHead, *pCurrent;
		
		newHead = pCurrent = new RandomListNode(pHead->label);
		while (pHead->next != nullptr)
		{
			pCurrent->next = new RandomListNode(pHead->next->label);
			pCurrent = pCurrent->next;
			pHead = pHead->next;

		}
		return newHead;
    }
};

int main()
{
	RandomListNode t1(1), t2(2), t3(3), t4(4), t5(5);
	t1.next = &t2; t2.next = &t3; t3.next = &t4; t4.next = &t5;
	t1.random = &t3; t2.random = &t5; t4.random = &t2;

	Solution sol;
	sol.Clone(&t1);
}
