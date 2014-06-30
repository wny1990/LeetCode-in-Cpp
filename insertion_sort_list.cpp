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
ListNode* insert_node(ListNode *head, ListNode *node)
{
	if (head == NULL)
	{
		node->next = NULL;
		return node;
	}
	if ( head->val > node->val )
	{
		node->next = head;
		return node;
	}
	ListNode* head0 = head;
	while( head->next != NULL && head->next->val <= node->val)
		head = head->next;
	node->next = head->next;
	head->next = node;
	return head0;
}
ListNode *insertionSortList(ListNode *head) 
{
	ListNode *ptr = head;
	ListNode *head1 = NULL;
	        
	while(ptr != NULL)
	{
		ListNode *temp = ptr ;
		ptr = ptr->next;
		head1 = insert_node(head1,temp);
	}
	return head1;
}
};
