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
int probe(TreeNode *node)
{
	int left,right;
	left = INT_MIN;
	right = INT_MIN;
	if(node->left != NULL)
		left = probe(node->left);	
	if(node->right != NULL)
		right = probe(node->right);

	
	if(node->left != NULL && node->right != NULL)
		if ( max(left,max(right,left + right)) + node->val > max_sum)
			max_sum = max(left,max(right,left+right))+node->val;
		
	if(node->left == NULL && node->right != NULL)
		if(right + node->val > max_sum)
			max_sum = right + node->val;

	if(node->left != NULL && node->right == NULL)
		if(left + node->val > max_sum)
			max_sum = left + node->val;

	if (node->val > max_sum)
        	max_sum = node->val;
        
	if(node->right == NULL && node->left == NULL)
		return node->val;

	return max(max(left,right)+ node->val,node->val);
}
int maxPathSum(TreeNode *root) 
{
	max_sum = INT_MIN;
	if (root==NULL) return 0;
	probe(root);
	return max_sum;
}
private:
int max_sum;
};
