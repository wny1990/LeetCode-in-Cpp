/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class CompareP {
public:
    bool operator()(const ListNode *t1, const ListNode *t2)
    {
       if (t1->val > t2->val) return true;
       return false;
    }
};

class Solution {
public:
ListNode *mergeKLists(vector<ListNode *> &lists) 
{
 	ListNode *dummy = new ListNode(0);
 	ListNode *node = dummy;
	priority_queue<ListNode*,vector<ListNode*>,CompareP> q;
	for ( int i = 0; i < lists.size(); i++ )
	{
		if ( lists[i] != NULL )
		{
			q.push(lists[i]);
			lists[i] = lists[i]->next;
		}
	}
	while (q.size())
	{
		ListNode *temp = q.top();
		q.pop();
		node->next = temp;
		node = node->next;
		if (temp->next != NULL)
			q.push(temp->next);
	}
	return dummy->next;
}
};
