/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
void connect(TreeLinkNode *root) 
{
	vector<int> level;
	queue<TreeLinkNode*> q;
	queue<TreeLinkNode*> temp;
	TreeLinkNode* last = NULL;
	if (root == NULL)
		return ;
	q.push(root);
	while(q.size())
	{
		TreeLinkNode *node;
		node = q.front();
		q.pop();
		if (last!=NULL)
			last->next = node;
		last = node;
		if (node->left != NULL)
			temp.push(node->left);
		if (node->right != NULL)
			temp.push(node->right);
		if (!q.size())
		{
			last = NULL;
			q = temp;
			while(temp.size())
				temp.pop();
		}
	}
	return;
}
};
