/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */  
 struct TreeNodeData {
      int maxheight;
      int maxlength;
};
/*
       maxheight=max(left.maxheight+val,right.maxheight+val,val) ;                        m                                maxlength=max(maxlenghtL,maxlengthR,val,maxheightL+val,maxheightR+val,maxheightL+maxheightR+val);
*/
class Solution {
public:
    int in
    int maxPathSum(TreeNode* root) {
        return solve(root).maxheight;
    }
    struct TreeNodeData solve(TreeNode* root) {
        //recursive maxlength
    }
    int maxLength(TreeNode* root) {
        //max of 
        //1.val+maxLength(left) 
        //2.val+maxLength(right) 
        //3.val 
    }
};