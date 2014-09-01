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
TreeNode* copyTree(TreeNode* node,int offset)
{
	if (node == NULL )
		return NULL;
	TreeNode* neo_node = new TreeNode(node->val + offset);
	if (node->left != NULL)
		neo_node->left = copyTree(node->left,offset);
	if (node->right != NULL)
		neo_node->right = copyTree(node->right,offset);
	return neo_node;

}
vector<TreeNode*> generateTrees(int n) 
{
	vector<vector<TreeNode*>> trees(n+1,vector<TreeNode*>());
	trees.at(0).push_back(NULL);
	for( int size  = 1; size <= n; size++)
		for ( int ls = 0; ls < size; ls++)
		{
			for ( int left = 0; left < trees.at(ls).size(); left++)
				for ( int right = 0; right < trees.at(size-ls-1).size(); right++)
				{
					TreeNode *lnode,*rnode;
					lnode = trees.at(ls).at(left);
					rnode = trees.at(size-ls-1).at(right);
					TreeNode* root = new TreeNode(ls+1);
					root->left = lnode;
					rnode = copyTree(rnode,ls+1);
					root->right = rnode;
					trees.at(size).push_back(root);
				}
		}
	return trees.at(n);	
}
};
