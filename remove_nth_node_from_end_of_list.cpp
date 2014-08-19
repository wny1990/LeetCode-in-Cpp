ListNode *removeNthFromEnd(ListNode *head, int n)
{
     ListNode *fast;   
     ListNode *slow; 
     ListNode *head0 = head; 
     fast = head;  
     slow = head;  
     for(int i = 1 ; i <= n ; i++ )
         fast = fast->next;
     if (fast == NULL) return head0->next;
     while(fast->next != NULL)
     {
	fast = fast->next;
	slow = slow->next;
     }
     slow->next = slow->next->next;
     return head0;
}
