/*
Time complexity  :  O(N)
Space complexity :  O(1) ignoring the call stack
My approach      :  traverse the tree ,the intial level is 1, as we go deep down in recursion increase the value of level as level+1 and if a
                    leaf node occurs update the answer as minimum of value of level and previous value of answer.
*/
class Solution {
public:
    int answer=1e6;
    void helper(TreeNode* root,int level)
    {
      if(root==NULL) return ;
      if(root->left ==NULL and root->right==NULL)
      {
          answer= min(answer,level);
      }
        helper(root->left,level+1);
        helper(root->right,level+1);

    }
    int minDepth(TreeNode* root) {
        if(root==NULL)  return 0;
        helper(root,1);
        return answer;
    }
};
