/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
 	if (l1 == NULL)
		return l2;
 	if (l2 == NULL)
		return l1;

	ListNode* l0;
	ListNode* start;
	if (l1->val < l2->val)
	{
		l0 = l1;
		l1 = l1->next;
	}
	else
	{
		l0 = l2;
		l2 = l2->next;
	}
	start = l0;
	while( l1 != NULL || l2 != NULL)
	{
		if (l1 == NULL) 
		{
			l0->next = l2;
			l2 = l2->next;
		}
		else if (l2 == NULL)
		{
			l0->next = l1;
			l1 = l1->next;
		}
		else if (l1->val > l2->val)
		{

			l0->next = l2;
			l2 = l2->next;
		}
		else
		{
			l0->next = l1;
			l1 = l1->next;
		}
		l0 = l0->next;
	}       
	l0->next =NULL;
	return start;
}
};
