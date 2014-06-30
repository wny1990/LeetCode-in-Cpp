void probe(TreeNode *p, TreeNode *q)
{
	if( (p->left == NULL && q->left != NULL)
	|| (p->left != NULL && q->left == NULL) )
	{
		same = false;
		return;
	}
	if( (p->right == NULL && q->right != NULL)
	|| (p->right != NULL && q->right == NULL) )
	{
		same = false;
		return;
	}
	if( (p->right != NULL && q->right != NULL)
		probe(p->right,q->right);

	if( (p->left != NULL && q->left != NULL)
		probe(p->left,q->left);
	return;
}
bool isSameTree(TreeNode *p, TreeNode *q)
{
	same = true;
	if( p == NULL && q==NULL) return true;
	if( p == NULL || q==NULL) return false;
	probe(p,q);
	return same;        
}
private:
	bool same;
