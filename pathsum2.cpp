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
void probe(TreeNode *node, vector<int> accum)
{
	accum.push_back(node->val);
        if(node->left != NULL)
            probe(node->left,accum);
        if(node->right != NULL)
            probe(node->right,accum);
        if(node->right == NULL && node->left == NULL)
    	{
	    int spath = 0;
            for ( vector<int>::iterator ii = accum.begin(); ii != accum.end(); ii++)
		spath += *ii;
	    if(spath == sum0 ) result.push_back(accum);
	}
        return;
}
vector<vector<int> > pathSum(TreeNode *root, int sum) 
{
	sum0 = sum;
	vector<int> v0;
	if (root == NULL) return result;
	probe(root,v0);
	return result;
        
}
private:
	int sum0;
        vector<vector<int> > result;
};
