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
ListNode *lsort(ListNode *head)
{
	if (head == NULL || head->next == NULL)
		return head;
	ListNode *fast,*slow;
	fast = head->next;
	slow = head;
	while( fast->next != NULL)
	{
		fast = fast->next;
		if (fast->next != NULL)
			fast = fast->next;
		slow = slow->next;
	}
	ListNode *head1,*head2;
	head1 = head;
	head2 = slow->next;
	slow->next =NULL;
//sort ther two lists.
	head1 = lsort(head1);
	head2 = lsort(head2);
//merge the two sorted lists.
	ListNode *dummy = new ListNode(0);
	ListNode *p = dummy;
	while ( head2 != NULL || head1 != NULL)
	{
		if (head1 != NULL && head2 != NULL)
		{
			if ( head1->val < head2->val )
			{
				p->next = head1;
				head1 = head1->next;
			}
			else
			{

				p->next = head2;
				head2 = head2->next;
			}			
		}
		else if ( head1 != NULL)
		{
			p->next = head1;
			head1 = head1->next;
		}
		else
		{
			p->next = head2;
			head2 = head2->next;
		}
		p = p->next;
	}
	p->next = NULL;
	p = dummy->next;
	delete dummy;
	return p;
}
ListNode *sortList(ListNode *head) 
{
	head = lsort(head);
	return head;
}
};
