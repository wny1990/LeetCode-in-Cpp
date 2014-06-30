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
        void trace(TreeNode *node, int accum)
    {
        if(node == NULL) return;
        if(node->left != NULL)
            trace(node->left,node->val+accum);
        if(node->right != NULL)
            trace(node->right,node->val+accum);
        if(node->right == NULL && node->left == NULL)
            if((node->val + accum) == target)
                find = true;
    
        return;
    }
        vector<vector<int> > pathSum(TreeNode *root, int sum) 
        {
        
    }
};
