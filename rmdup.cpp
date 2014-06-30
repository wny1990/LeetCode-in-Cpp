 ListNode *deleteDuplicates(ListNode *head)
 {
 	ListNode *p,*s,*head0;
	head0 = head;
	p = head;
	s = head;
	while(p != NULL)
	{
		s = p;
//		bool multi = false;
		while(p->next != NULL &&  p->val == (p->next)->val)
		{
			p = p->next;

		}
		s->next = p->next;
		p = p->next;
	}
	return head0;
}
