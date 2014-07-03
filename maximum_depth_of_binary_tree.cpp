    void probe(TreeNode *node, int depth)
    {
        if(node == NULL) 
        {
            max = 0;
            return;
        }
        if(node->left != NULL)
            probe(node->left,depth + 1);
        if(node->right != NULL)
            probe(node->right,depth + 1);
        if(node->right == NULL && node->left == NULL)
            if((depth + 1) > max)
                max = depth + 1;
    
        return;
    }
    int maxDepth(TreeNode *root) {
        max = -1;
        probe(root, 0);
        return max;
    }

    private:
        int max;
