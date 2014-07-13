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

ListNode* reverse(ListNode *head)
{
	if (head == NULL || head->next == NULL)
		return head;

	ListNode *pre = head;
	ListNode *curr = head->next;

	while( curr != NULL)
	{
		ListNode *temp = curr->next;
		curr->next = pre;
		pre = curr;
		curr = temp;
	}

	head->next = NULL;
	return pre;
}
void reorderList(ListNode *head) 
{
	if (head == NULL || head->next == NULL)
		return;
	ListNode *fast = head,*slow = head;
	fast = fast->next;
	while( fast->next != NULL)
	{
		fast = fast->next;
		if (fast->next!=NULL)
			fast = fast->next;
		slow = slow->next;
	}
	ListNode *head2 = slow->next;
	slow->next = NULL;
	head2 = reverse(head2);
	ListNode *p = head;
	while(head2 != NULL)
	{
		ListNode *temp = p->next;
		ListNode *temp1 = head2->next;
		p->next= head2;
		head2->next = temp;
		p =temp;
		head2 = temp1;
	}
	return;
}
};
