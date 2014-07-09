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
TreeNode* build( vector<int> &postorder, int p,vector<int> &inorder, int i, int j)
{
	if ( j < i )
		return NULL;
	TreeNode* node = new TreeNode(postorder[p]);
	auto it = find(inorder.begin()+i,inorder.begin()+j,postorder[p]);
	int pivot = it - inorder.begin();
	TreeNode* right  = build(postorder,p-1,inorder,pivot + 1,j);
	TreeNode* left = build(postorder,p-1 - (j - pivot),inorder,i,pivot - 1);
	node->left = left;
	node->right = right;
	return node;
}
TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) 
{
	return build(postorder,postorder.size() - 1,inorder,0,inorder.size()-1);
}
};
