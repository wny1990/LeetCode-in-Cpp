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
vector<int> inorderTraversal(TreeNode *root)
{
	vector<int> result;
	stack<TreeNode*> stk;
	if (root == NULL) return result;
	stk.push(root);
	while(stk.size())
	{
		TreeNode *node;
		node = stk.top();
		while(node != NULL)
		{
			node = node->left;
			stk.push(node);
		}
		stk.pop();	
		if(stk.size())
		{
			node = stk.top();
			result.push_back(node->val);
			stk.pop();
			stk.push(node->right);
		}
	}
	return result;
}
};
