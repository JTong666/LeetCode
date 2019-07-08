#include<vector>
#include<stdio.h>
#include<queue>
#include<iostream>
using namespace std;



struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(NULL) {}
};
/*
//分而治之思想
class Solution
{
public:
	ListNode* mergeKlists(vector<ListNode*>& lists)
	{
		if (lists.size() == 0)
			return nullptr;
		while (lists.size() > 1)
		{
			lists.push_back(mergeKlists_two_list(lists[0], lists[1]));
			lists.erase(lists.begin());
			lists.erase(lists.begin());
		}

		return lists.front();
	}
private:
	ListNode *mergeKlists_two_list(ListNode* l1, ListNode* l2)
	{
		if (l1 == nullptr)
			return l2;
		if (l2 == nullptr)
			return l1;
		if (l1->val > l2->val)
		{
			l2->next = mergeKlists_two_list(l1, l2->next);
			return l2;
		}
		else
		{
			l1->next = mergeKlists_two_list(l1->next, l2);
			return l1;
		}
	}
};
*/



//采用堆的方式进行求解：
class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*> &lists) {
		priority_queue<ListNode*, vector<ListNode*>, compera> p;
		for (auto it : lists)
			if(it)
				p.push(it);
		ListNode* result;
		if (p.empty())
			return NULL;
		result = p.top();
		p.pop();
		if (result->next)
			p.push(result->next);
		ListNode* it;
		it = result;

		while (!p.empty())
		{
			it->next = p.top();
			p.pop();
			it = it->next;
			if (it->next)
				p.push(it->next);
		}

		return result;
	}
private:
	class compera {
	public:
		bool operator()(const ListNode* l, const ListNode* r)
		{
			return l->val > r->val;
		}
	};
};



int main()
{

	vector<ListNode*> lists{}
}






