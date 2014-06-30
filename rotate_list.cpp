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
ListNode *rotateRight(ListNode *head, int k) 
{
	if ( head == NULL) return NULL;
	ListNode* ptr = head;
	int len = 1;

	while ( ptr->next != NULL)
	{
		ptr = ptr->next; 
		len ++;      
	}
	
	k = k % len;

	if ( k == 0) return head;

	ListNode *fast = head,*slow = head;
	for ( auto i = 0; i < k ; i++)
		fast = fast->next;

	while ( fast->next != NULL)
	{
		fast = fast->next;
		slow = slow->next;
	}
	
	ListNode* result = slow->next;
	slow->next = NULL;
	ptr->next = head;
	
	return result;
}
};
