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
vector<int> postorderTraversal(TreeNode *root)
{
	vector<int> result;
	stack<TreeNode*> stk;
	TreeNode *last = new TreeNode(0);
	bool last_pop = false;
	if (root == NULL) return result;
	stk.push(root);
	while(stk.size())
	{
		TreeNode *node;
		node = stk.top();
		if ( last == node->right || last == node->left)
		{
			result.push_back(node->val);
			stk.pop();
		}
		else
		{
			if ( node->right!=NULL)
				stk.push(node->right);
			if ( node->left!=NULL)
				stk.push(node->left);
			if (node->right == NULL && node->left == NULL)
			{
				result.push_back(node->val);
				stk.pop();
			}	
		}
		last = node;
	}
	return result;
}
};
