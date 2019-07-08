#include<algorithm>
using namespace std;


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n)
	{
		ListNode* t1;
		ListNode* t2;
		ListNode* head1;
		head1 = t2 = new ListNode(0);
		t2->next = head;
		t1 = head;
		if (t1->next == NULL&&n == 1)
			return NULL;
		for (int i = 1; i < n; i++)
			t1 = t1->next;
		while (t1->next!=NULL)
		{
			t1=t1->next;
			t2=t2->next;
		}
		if (n == 1)
			t2->next = NULL;
		else if (head1 == t2)
			head = head->next;
		else
		{
			auto t3 = t2->next->next;
			t2->next = t3;
		}
		return head;
	}
};