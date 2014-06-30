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
void reorderList(ListNode *head) 
{
	queue<int> q1;        
	queue<int> q2;        
	if (head == NULL || head->next == NULL)
		return head;
	ListNode *fast = head; *slow = head;
	fast = fast->next;
	while( fast != NULL)
	{
		q1.push(slow);
		q2.push(fast);
		fast = fast->next;
		slow = slow->next;
	}
	
	while( fast.size() || slow.size())
	{
		LisNode* p1 = NULL;
		LisNode* p2 = NULL;
		if (q1.size())
		{
			p1 = q1.front();
		}
		if (q2.size())
		{
			p2 = q2.front();
		}
		if (p2 == NULL)
			continue;
		
	}
}
};
