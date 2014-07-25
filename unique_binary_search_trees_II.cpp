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
TreeNode* copy( TreeNode * node0)
{
	if (root == NULL)
		return NULL;
	TreeNode *node = new TreeNode(node0->val);
	if (node0->left != NULL)
		node->left = copy(node0->left);
	if (node0->right != NULL)
		node->right = copy(node0->right);
	return node;
}

void construct(int i, int j,TreeNode *node,vector<bool> flag)
{

	for( int k = i; k <= j; k++)
	{
		vector<bool> flag1(flag);
		node->val =k;
		node->left = NULL;
		node->right = NULL;
		flag1[k-1] = true;

		if( k-1 >= i )
		{
			TreeNode *lnode = new TreeNode(0);
			node->left = lnode;
			construct(i,k-1,lnode,flag1);
		}

		for( int s = 0; s <= k-2; s++)
			flag1[s] = true;

		if (j >= k+1)
		{
			TreeNode *rnode = new TreeNode(0);
			node->right = rnode;
			construct(k+1,j,rnode,flag1);
		}
		int fin = 0;
		for( int s = 0; s < flag1.size() ; s++)
			if (flag1[s])	
				fin++;
		if ( fin  == flag1.size())
		{
			TreeNode *root1 = copy(root);
			result.push_back(root1);
		}
	}
	return;
}
vector<TreeNode *> generateTrees(int n) 
{
	size = n;
	if( n == 0)
	{
		result.push_back(NULL);
		return result;
	}
	root = new TreeNode(0);
	vector<bool> flag(n,false);
	construct(1,n,root,flag);   
	return result;    
}
private:
	TreeNode *root;
	vector<TreeNode *> result;
	int size;
};


