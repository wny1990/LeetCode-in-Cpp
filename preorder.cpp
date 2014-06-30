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
vector<int> preorderTraversal(TreeNode *root)
{
	vector<int> result;
	stack<TreeNode*> stk;
	if (root == NULL) return result;
	stk.push(root);
	while(stk.size())
	{
		TreeNode *node;
		node = stk.top();
		result.push_back(node->val);
		stk.pop();
		if ( node->right!=NULL)
			stk.push(node->right);
		if ( node->left!=NULL)
			stk.push(node->left);
	}
	return result;
}
};
