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
    void probe(TreeNode *lnode, TreeNode *rnode)
    {

	if (lnode->val != rnode->val)
	{
		sym = false;
		return;
	}

	if(lnode->left != NULL && rnode->right == NULL
	|| lnode->left == NULL && rnode->right != NULL)
	{
		sym = false;
		return;
	}
	if(lnode->right != NULL && rnode->left == NULL
	|| lnode->right == NULL && rnode->left != NULL)
	{
		sym = false;
		return;
	}

	if(lnode->right != NULL && rnode->left != NULL)
	{
		probe(lnode->right,rnode->left);
	}
	
	if(lnode->left != NULL && rnode->right != NULL)
	{
		probe(lnode->left,rnode->right);
	}
	return;
    }
   bool isSymmetric(TreeNode *root)
   {
	if(root == NULL) return true;
	if(root->left == NULL && root->right==NULL) return true;
	if(root->left == NULL && root->right!=NULL) return false;
	if(root->left != NULL && root->right==NULL) return false;
	sym = true;
        probe(root->left,root->right);
        return sym;
   }
    private:
    	bool sym;
};
