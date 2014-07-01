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
ListNode *reverseBetween(ListNode *head, int m, int n) 
{
	ListNode *ptr1 = head;      
	ListNode *ptr2 = NULL;
	ListNode *pre = NULL;
	ListNode *post = NULL;
	ListNode *dummy = NULL;
	stack<ListNode*> stk;

	if ( m == n) return head;      
		
	for(int i = 1; i < m; i ++ )
	{
		if (i == m-1 ) pre = ptr1;
		ptr1 = ptr1->next;
	}
	ptr2 = ptr1;
	
	if ( m == 1)
	{
		dummy = new ListNode(0);
		pre = dummy;
	}
	for(int i = 0; i < n - m; i ++ )
		ptr2 = ptr2->next;

	post = ptr2->next;

	while( ptr1 != post)
	{
		stk.push(ptr1);
		ptr1 = ptr1->next;
	}
	while (stk.size())
	{
		ListNode *temp = stk.top();
		stk.pop();
		pre->next = temp;
		pre = pre->next;
	}
	pre->next = post;
	if ( m == 1) return dummy->next;
	return head;
}
};
