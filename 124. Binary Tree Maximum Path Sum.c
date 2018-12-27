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
	double maxheight;
	double maxlength;
};
/*
maxheight=max(left.maxheight+val,right.maxheight+val,val) ;
maxlength=max(maxlenghtL,maxlengthR,val,maxheightL+val,maxheightR+val,maxheightL+maxheightR+val);
*/
class Solution {
public:
	int maxPathSum(TreeNode* root) {
		return solve(root).maxlength;
	}
	struct TreeNodeData solve(TreeNode* root) {
		struct TreeNodeData dataL = { .maxheight = -std::numeric_limits<float>::infinity(),.maxlength = -std::numeric_limits<float>::infinity() };
		struct TreeNodeData dataR = { .maxheight = -std::numeric_limits<float>::infinity(),.maxlength = -std::numeric_limits<float>::infinity() };
		struct TreeNodeData ret = { .maxheight = 0,.maxlength = 0 };
		int val = root->val;
		if (root->left == NULL&&root->right == NULL)
		{
			ret.maxheight = val;
			ret.maxlength = val;
		}
		else
		{
			if (root->left != NULL)
			{
				dataL = solve(root->left);
			}
			if (root->right != NULL)
			{
				dataR = solve(root->right);
			}
			int arr[6] = { dataL.maxheight + val
				,dataR.maxheight + val
				,val
				,dataL.maxlength
				,dataR.maxlength
				,dataL.maxheight + dataR.maxheight + val
			};
			int maxlength = *max_element(arr, arr + 6);
			int maxheight = *max_element(arr, arr + 3);
			ret.maxheight = maxheight;
			ret.maxlength = maxlength;
		}
		/*
		cout<<"val:"<<val<<endl;
		cout<<"dataR.maxlength:"<<dataR.maxlength<<" dataR.maxheight:"<<dataR.maxheight <<endl;
		cout<<"dataL.maxlength:"<<dataL.maxlength<<" dataL.maxheight:"<<dataL.maxheight<<endl;
		cout<<"ret.maxheight:"<<ret.maxheight<<endl;
		cout<<"ret.maxlength:"<<ret.maxlength<<endl;*/

		return ret;
	}
};