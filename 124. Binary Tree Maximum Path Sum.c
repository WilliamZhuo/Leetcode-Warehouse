/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */  
/*
Root
Lefttree       righttree

Path length : the sum of values of a path
Height: the largest path length from root to leave

Max path length of root=
{
	Max length of lefttree//if the path does not pass root
	Max length of righttree//if the path does not pass root
	Value of root
	Height of lefttree+Value of root
	Height of righttree+Value of root
	Height of lefttree+Value of root+Height of righttree
}

*/
 struct TreeNodeData {
      int maxheight;
      int maxlength;
};
/*
       maxheight=max(left.maxheight+val,right.maxheight+val,val) ;   
	   maxlength=max(maxlenghtL,maxlengthR,val,maxheightL+val,maxheightR+val,maxheightL+maxheightR+val);
*/
class Solution {
public:
    int in
    int maxPathSum(TreeNode* root) {
        return solve(root).maxheight;
    }
    struct TreeNodeData solve(TreeNode* root) {
		struct TreeNodeData dataL;
		struct TreeNodeData dataR;
		struct TreeNodeData ret;
		int val = root->val;
		if (root->left==NULL&&root->right == NULL)
		{
			ret.maxheight=val;
			ret.maxlength=val;
			return ret;
		}
		if (root->left != NULL)
		{
			dataL = solve(root->left);
		}
		if (root->right == NULL)
		{
			dataR = solve(root->right);
		}
		int maxlength=max(
			dataL.maxlength
			,dataR.maxlength
			,dataL.maxheight+dataR.maxheight+val
			,dataL.maxheight+val
			,dataR.maxheight+val
			,val);
		int maxheight=max(
			dataL.maxheight+val
			,dataR.maxheight+val
			,val);
		ret.maxheight=maxheight;
		ret.maxlength=maxlength;
		return ret;		
    }
};