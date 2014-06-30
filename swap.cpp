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
ListNode* swap(ListNode *node)
{
	ListNode *next;
	ListNode *nnext;
	ListNode *nnnext;
	next = node->next;
	if (next == NULL)
		return NULL;
	nnext = next->next;
	if (nnext == NULL)
		return NULL;
	nnnext = nnext->next;
	
	node->next = nnext;
	nnext->next = next;
	next->next = nnnext;
	return next;
}
ListNode *swapPairs(ListNode *head)
{
	ListNode *dummy = new ListNode(0);
	dummy->next = head;
	if (head == NULL || head->next == NULL) return head;
	ListNode *start = head->next;
	ListNode *node = dummy;

	while( node != NULL)
	{
		ListNode *temp;
		temp = swap(node);
		node = temp;
	}
	return start;
}
};
