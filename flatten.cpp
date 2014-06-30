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
void flatten(TreeNode *root)
{
	stack<TreeNode*> stk;
	if( root == NULL ) return;      
	stk.push(root);
	TreeNode* start = new TreeNode(0);
	TreeNode* last = start;
	while(stk.size())
	{
		TreeNode* node = stk.top();
		last->right = node;
		last->left = NULL;
		stk.pop();
		last = node;
		if( node->right != NULL)
			stk.push(node->right);
		if( node->left != NULL)
			stk.push(node->left);
	} 
	last->right =  NULL;
	return;
}
};
