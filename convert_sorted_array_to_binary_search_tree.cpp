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
void construct(vector<int> &num, int left, int right,TreeNode* node)
{
	if (left == right)
	{
		node->val = num.at(left);
	//	node->left == NULL;
	//	node->right == NULL;
		return;
	}

	int pivot = (left + right)/2;
	node->val = num.at(pivot);
	if ( right - pivot  > 0) 
	{
		TreeNode *rightp = new TreeNode(0);
		node->right = rightp;
		construct(num,pivot+1,right,rightp);
	}
//	else
	//	node->right = NULL;
	if ( pivot -left > 0) 
	{
		TreeNode *leftp = new TreeNode(0);
		node->left = leftp;
		construct(num,left,pivot - 1 ,leftp);

	}	
//	else
//		node->left = NULL;

	return;
}
TreeNode *sortedArrayToBST(vector<int> &num) 
{
	TreeNode *p = new TreeNode(0);
	if (num.size() == 0)
		return NULL;
	construct(num,0,num.size()-1,p);
	return p;      
}
};
