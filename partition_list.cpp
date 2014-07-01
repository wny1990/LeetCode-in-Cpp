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
ListNode *partition(ListNode *head, int x) 
{
	if (head == NULL)    
		return NULL;
	ListNode *head1 = new ListNode(0);
	ListNode *head2 = new ListNode(0);
	ListNode *ptr1 = head1;
	ListNode *ptr2 = head2;
	ListNode *ptr = head;
	while ( ptr != NULL)
	{
		if ( ptr->val < x)
		{
			ptr1->next = ptr;
			ptr1 = ptr1->next;
		}
		else
		{
			ptr2->next = ptr;
			ptr2 = ptr2->next;
		}
		ptr = ptr->next;
	}

	if (head1->next == NULL)
		return head2->next;
	if (head2->next == NULL)
		return head1->next;
	ptr1->next = head2->next;
	ptr2->next = NULL;
	return head1->next;
}
};
