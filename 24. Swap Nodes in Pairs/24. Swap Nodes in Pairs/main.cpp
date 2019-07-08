#include<stdio.h>

using namespace std;



struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x) :val(x), next(NULL) {}
};

class Solution
{
public:
	ListNode* swapPairs(ListNode* head)
	{
		int k = 3;
		if (head == nullptr)
			return nullptr;
		ListNode* p = head;
		ListNode* q = head->next;
		ListNode* t;
		int i = 0;
		while (p != nullptr)
		{
			i++;
			p = p->next;
		}
		p = head;
		if (i == 1)
			return head;
		if (i == 2)
		{
			q->next = p;
			p->next = NULL;
			return q;
		}
		p->next = q->next;
		q->next = p;
		t = p;
		head = q;
		p = p->next;
		q = q->next->next->next;

		for(int j = 0;j<(i/2)-1;j++)
		{
			p->next = q->next;
			q->next = p;
			t->next = q;
			t = p;
			p = p->next;
			if (p == nullptr)
				break;
			while (k)
			{
				if (q->next)
				{
					q = q->next;
					k--;
				}
				else
					return head;
			}
			k = 3;
		}
		return head;
	}
};



int main()
{
	Solution s;
	ListNode s1(1); ListNode s2(2); ListNode s3(3); ListNode s4(4);
	s1.next = &s2;
	//s2.next = &s3;
	//s3.next = &s4;
	ListNode* head;
	head = &s1;
	ListNode* h;
	h = s.swapPairs(head);
	return 0;
}