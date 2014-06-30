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
    ListNode *detectCycle(ListNode *head) {
        
    ListNode *fast = head;   
    ListNode *slow = head;
    if(head == NULL) return false;
    while( fast != NULL && slow != NULL)
    {
       slow = slow->next;
       fast = fast->next;
       if (fast == NULL)
		return NULL;
	fast = fast->next;
       if (fast == slow) break;
    }   
    if (fast == NULL)
	return NULL;
    slow = head;
    while( fast != slow)
   {
      fast = fast->next;
      slow = slow->next;
   }
   return slow;
    }
};
