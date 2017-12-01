#include <iostream>
#include <vector>
#include <algorithm>
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
    vector<int> printListFromTailToHead(ListNode* head) {
		vector<int> ivec;
        while (head)
		{
			ivec.push_back(head->val);
			head = head->next;
		}
        reverse(ivec.begin(), ivec.end());
		return ivec;
    }
};

int main()
{
	ListNode p1(1), p2(2), p3(3);
	p1.next = &p2;
	p2.next = &p3;
	Solution s;
	s.printListFromTailToHead(&p1);
}
