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
	if(node->left != NULL && node->right != NULL)
	{
            left = probe(node->left);
            right = probe(node->right);
	    if (left != right)
		sym = false;
	}
	else if(node->left == NULL && node->right == NULL)
		return node->val;
	else {
		sym = false;
		return 0;
	}
	
        return left + right + node->val;
    }
   bool isSymmetric(TreeNode *root)
   {
	if(root == NULL) return true;
	sym = true;
        probe(root);
        return sym;
    }
    private:
    	bool sym;
};
