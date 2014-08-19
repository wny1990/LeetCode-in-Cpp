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
void probe( TreeNode *node, int num)
{
	
	if (node->left != NULL)
		probe(node->left, 10*num + node->val);
	if (node->right != NULL)
		probe(node->right,10*num + node->val);
	if (node->right == NULL  &&  node->left == NULL  )
		sum += (num*10 + node->val);
	return;
} 
int sumNumbers(TreeNode *root) 
{
      if (root == NULL) return 0;
	sum = 0;
	probe(root,0);
	return sum;
}
private:
	int sum;
};
