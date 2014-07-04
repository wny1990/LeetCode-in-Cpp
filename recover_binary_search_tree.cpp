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
void traversal( TreeNode *node)
{

	if (node->left != NULL)
		traversal(node->left);

	if (temp != NULL && node->val < temp->val)
	{	
		if (pre1 != NULL )
		{
			pre2 = temp;
			post2 = node;
		}
		else
		{
			pre1 = temp;
			post1 = node;
		}
	}
	temp = node;

	if (node->right != NULL)
		traversal(node->right);
	return;
}
void recoverTree(TreeNode *root) 
{
	pre1 = NULL;
	post1 = NULL;
	temp = NULL;
	pre2 = NULL;
	post2 = NULL;
	traversal(root);
	if( pre2 == NULL )
	{
		int temp = pre1->val;
		pre1->val = post1->val;
		post1->val = temp;
	}
	else
	{
		int temp = pre1->val;
		pre1->val = post2->val;
		post2->val = temp;

	}
	return;
	
}
private:
	TreeNode *pre1;
	TreeNode *post1;
	TreeNode *pre2;
	TreeNode *post2;
	TreeNode *temp;
};
