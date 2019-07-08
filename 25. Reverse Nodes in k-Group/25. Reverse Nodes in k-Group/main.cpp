#include<stdio.h>
using namespace std;


struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x) :val(x), next(NULL) {}
};


class Solution {
public:
	ListNode* reversekGroup(ListNode* head, int k)
	{
		dummy->next = head;
		int len = length(head);
		for (int i = 0; i < len / k; i++)
		{
			for (int j = 1; j < k; j++)
			{
 				ListNode* temp = pre->next;
				pre->next = head->next;
				head->next = head->next->next;
				pre->next->next = temp;
			}
			pre = head;
		    head = head->next;
		}
		return dummy->next;
	}
private:
	ListNode* dummy = new ListNode(0), *pre = dummy;
	int length(ListNode* head)
	{
		int len = 0;
		while (head)
		{
			len++;
			head = head->next;
		}
		return len;
	}
};


int main()
{
	Solution s;
	ListNode s1(1), s2(2), s3(3), s4(4), s5(5);
	s1.next = &s2;s2.next = &s3;s3.next = &s4;s4.next = &s5;
	ListNode* head = &s1;
	ListNode* t = s.reversekGroup(head, 2);
	return 0;
}