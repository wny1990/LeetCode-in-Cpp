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
void construct(int n)
{
	queue<pair<int,int>> q;
	queue<TreeNode*> nodes;
	q.push({1,n});
	root = new TreeNode(0);
	nodes.push(root);
	while( q.size())
	{
		int i = q.front().first;
		int j = q.front().second;
		q.pop();
		TreeNode* node = nodes.front();
		nodes.pop();
		for( int k = i; k <= j; k++)
		{
			node->val =k;
			node->left = NULL;
			node->right = NULL;
			if( k-1 >= i )
			{
				TreeNode *lnode = new TreeNode(0);
				node->left = lnode;
				q.push({i,k-1});
				nodes.push(lnode);
			}
			if (j >= k+1)
			{
				TreeNode *rnode = new TreeNode(0);
				node->right = rnode;
				q.push({k+1,j});
				nodes.push(rnode);
			}
			if ( k == n)
			{
				TreeNode *root1 = copy(root);
				result.push_back(root1);
			}
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
	construct(n);   
	return result;    
}
private:
	TreeNode *root;
	vector<TreeNode *> result;
	int size;
};
