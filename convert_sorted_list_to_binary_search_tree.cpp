/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
void construct( ListNode *head, TreeNode *node)
{
	ListNode *fast = head;
	ListNode *slow = head;
	ListNode *pre = NULL;
	while( fast->next != NULL)
	{
		fast = fast->next;
		if (fast->next != NULL)
		{
			fast = fast->next;
			pre = slow;
			slow = slow->next;
		}

	}

	node->val = slow->val;
	node->left = NULL;
	node->right = NULL;

	if( fast != slow )
	{
		if ( pre != NULL)
		{
			pre->next = NULL;
			TreeNode *node1 = new TreeNode(0);
			node->left = node1;
			construct(head,node1);
		}

		TreeNode *node2 = new TreeNode(0);
		node->right = node2;
		construct(slow->next,node2);
	}
	return;
}
TreeNode *sortedListToBST(ListNode *head) 
{
	if( head == NULL )
		return NULL;
	TreeNode *root = new TreeNode(0);
	construct(head,root);
	return root;
}
};
