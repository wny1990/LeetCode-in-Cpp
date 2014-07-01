/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node)
{
	if (head == NULL)
		return NULL;

	//unordered_map<int,RandomListNode*> mymap;
	map<int,RandomListNode*> mymap;
	RandomListNode* ptr = head;
	RandomListNode* head1 = new RandomListNode(head->label) ;
	RandomListNode* ptr1 = head1;
	mymap.insert({ptr1->label,ptr1});
	while( ptr != NULL)
	{
		ptr = ptr->next;
		if (ptr == NULL)
			break;
		RandomListNode* temp = new RandomListNode(ptr->label);
		mymap.insert({temp->label,temp});
		ptr1->next = temp;
		ptr1 = ptr1->next;
	} 
	ptr = head;
	ptr1 = head1;
	while( ptr != NULL)
	{
		if(ptr->random != NULL)
		{
			int num = ptr->random->label;
			RandomListNode* temp = (mymap.find(num))->second;
			ptr1->random = temp;	
		}
		ptr = ptr->next;
		ptr1 = ptr1->next;
	} 
	return head1;
}
};
