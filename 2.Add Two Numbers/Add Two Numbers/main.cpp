#include<iostream>
#include<memory>
using namespace  std;



struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) :val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode*l1, ListNode*l2)
	{
		ListNode* p = l1;
		ListNode* q = l2;
		ListNode* first = new ListNode(0);
		ListNode* head = first;
		int t = 0;
		first->val = (p->val + q->val + t) % 10;
		t = (p->val + q->val + t)/10;
		p = p->next;
		q = q->next;
		while (1)
		{
			ListNode* m = new ListNode(0);
			if (p == NULL&q != NULL)
			{
				m->val = (q->val + t) % 10;
				t = (q->val + t) / 10;
				first->next = m;
				first = first->next;
				q = q->next;
			}
			else if (p != NULL&&q == NULL)
			{
				m->val = (p->val + t) % 10;
				t = (p->val+t) / 10;
				first->next = m;
				first = first->next;
				p = p->next;
			}
			else if (p == NULL&&q == NULL&&t == 1)
			{
				m->val = t;
				t = 0;
				first->next = m;
				first = first->next;
			}
			else if (p != NULL&q != NULL)
			{
				m->val = (p->val + q->val + t) % 10;
				t = (p->val + q->val + t) / 10;
				first->next = m;
				first = first->next;
				p = p->next;
				q = q->next;
			}
			else if (p == NULL&&q == NULL&t == 0)
				break;
		}
		return head;
	}
};