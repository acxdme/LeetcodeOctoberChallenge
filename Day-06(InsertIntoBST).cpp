/*
Time complexity : O(H) h is the height of the tree
Space complexity : O(1) ignoring the recursive stack
My approach : Search for the correct position where you can insert the node by comparing the given value with the value of the nodes.
*/
 void searchBST(TreeNode* root,int val)
    {
        if(root==NULL)
            return ;
        if(root->val > val )
        {
            if(root->left==NULL)
            {
                TreeNode* l = new TreeNode(val);
                root->left =l;
            } 
            searchBST(root->left,val);
        }
            
        if(root->val < val )
        {
            if(root->right == NULL)
            {
                TreeNode* r = new TreeNode(val);
                 root->right = r;
            }
               
            searchBST(root->right,val);
        }
            
    
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL) 
        {
            TreeNode* root= new TreeNode(val);
             return root;
        }
        
         searchBST(root,val);
        
        return root;
        
    }
};
