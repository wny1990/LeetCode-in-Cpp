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

ListNode* reverse(ListNode *head,int k)
{
	if (head == NULL || head->next == NULL)
		return head;

	ListNode *pre = head;
	ListNode *curr = head->next;

	for( int i = 0; i < k - 1  ; i++)
	{
		ListNode *temp = curr->next;
		curr->next = pre;
		pre = curr;
		curr = temp;
	}
	return pre;
}

ListNode *reverseKGroup(ListNode *head, int k) 
{
	if( k == 1 || k == 0)
		return head;
	ListNode *slow = new ListNode(0);
	ListNode *dummy = slow;
	slow->next = head;
	while(slow->next!= NULL)
	{
		ListNode *fast = slow;
		for(int i = 0; i < k && fast != NULL; i++)
			fast= fast->next;
		if (fast == NULL )
			break;
		fast= fast->next;
		ListNode *temp  = slow->next;
		slow->next = reverse(slow->next,k);
		temp->next = fast;
		slow = temp;
	}
	return dummy->next;
}
};
