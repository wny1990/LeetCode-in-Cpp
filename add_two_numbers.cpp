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
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) 
{
	ListNode* l0 = new ListNode;
	ListNode* start;
	int carry = 0;
	start = l0;
 
	while( l1!=NULL || l2!=NULL)
	{
		if(l2 == NULL)
		{
			int sum = l1->val +carry;
			l1->val = sum%10;
			carry = sum/10;
			l0->next = l1;
			l1 = l1->next;
		}
	    	else if(l1 == NULL)
		{
			int sum = l2->val +carry;
			l2->val = sum%10;
			carry = sum/10;
			l0->next = l2;
			l2 = l2->next;
		}

		else
		{
			int sum = l1->val + l2->val +carry;
			l1->val = sum%10;
			carry = sum/10;
			l0->next = l1;
			l1 = l1->next;
			l2 = l2->next;
		}
		l0 = l0->next;
	}       

	ListNode* tail = new ListNode;
	if(carry)
	{
		tail->val =carry;
		l0->next = tail;
		l0 = l0->next;
	}
	l0->next = NULL;
	return start->next;
}
};
