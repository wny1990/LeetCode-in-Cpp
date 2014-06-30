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
void probe(TreeNode *node)
{
	if (node->left != NULL)
		probe(node->left);
	if (node->val <= last) valid = false;
	last = node->val;
	if (node->right != NULL)
		probe(node->right);
	return;
}
bool isValidBST(TreeNode *root)
{
	last = INT_MIN
	valid = true;
 	if (root == NULL)     
		return true;
	probe(root);
	return valid;
}
private:
	int last;
	bool valid;
};
