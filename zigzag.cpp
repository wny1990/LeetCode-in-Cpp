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
vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
{
	vector<vector<int> > result;
	vector<int> level;
	queue<TreeNode*> q;
	queue<TreeNode*> temp;
	if (root == NULL)
		return result;
	q.push(root);
	while(q.size())
	{
		TreeNode *node;
		node = q.front();
		q.pop();
		level.push_back(node->val);
		if (node->left != NULL)
			temp.push(node->left);
		if (node->right != NULL)
			temp.push(node->right);
		if (!q.size())
		{
			vector<int> level1;
			if(result.size() % 2 == 1 )
			{	for( int i = level.size() - 1; i >= 0; i--)
					level1.push_back(level.at(i));
				result.push_back(level1);
			}
			else
				result.push_back(level);
			q = temp;
			while(temp.size())
				temp.pop();
			level.clear();
		}
	}
	return result;
}
};
