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
ListNode *deleteDuplicates(ListNode *head) 
{
	if (head == NULL || head->next == NULL)
		return head;
	while( head->next!=NULL && head->val == head->next->val)
	{
		while(head->next != NULL && head->val == head->next->val)
			head = head->next;
		head = head->next;
		if (head == NULL) return head;
	}

	ListNode *fast = head,*slow = head;
	fast = fast->next;
	while( fast != NULL)
	{
		if (fast->next == NULL)
		{
			fast = fast->next;
			continue;
		}
		if (fast->val == fast->next->val)
		{
			while(fast->next!=NULL && fast->val == fast->next->val)
				fast = fast->next;
			fast = fast->next;
			slow->next = fast;
			continue;
		}
		fast = fast->next;
		slow = slow->next;
		
	}
	return head;
}
};
