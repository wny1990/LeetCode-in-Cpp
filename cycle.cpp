/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
public:
    bool hasCycle(ListNode *head)
    {
    ListNode *fast = head;   
    ListNode *slow = head;
    short flag = 0;
    fast = fast->next;
    while( fast != NULL && slow != NULL)
    {
       if (fast == slow) return true;
       if (flag)
           slow = slow->next;
       fast = fast->next;
       flag = 1 - flag;
    }   
    return false;
    }
