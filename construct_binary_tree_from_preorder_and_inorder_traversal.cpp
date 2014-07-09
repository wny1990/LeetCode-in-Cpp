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
TreeNode* build( vector<int> &preorder, int p,vector<int> &inorder, int i, int j)
{
	if ( j < i )
		return NULL;

	TreeNode* node = new TreeNode(preorder[p]);
	auto it = find(inorder.begin()+i,inorder.begin()+j,preorder[p]);
	int pivot = it - inorder.begin();
	TreeNode* left = build(preorder,p+1,inorder,i,pivot - 1);
	TreeNode* right  = build(preorder,p+1 + (pivot - i),inorder,pivot + 1,j);
	node->left = left;
	node->right = right;
	return node;
}
TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) 
{
	return build(preorder,0,inorder,0,inorder.size()-1);
}
};
