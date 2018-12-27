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
int maximum(int * ptr,bool* isavailable,int length)
{
    bool nomaximumfound=true;
    int maxval;
    for(int i=0;i<length;i++)
    {
        if(isavailable[i])
        {
            if(nomaximumfound)
            {   maxval=ptr[i];nomaximumfound=false;}
            else
                maxval=(ptr[i]>maxval)?ptr[i]:maxval;
        }
    }
    return maxval;
}
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
		struct TreeNodeData ret  ={ .maxheight = 0, .maxlength = 0};
		
        int val = root->val;
		if (root->left==NULL&&root->right == NULL)
		{
			ret.maxheight=val;
			ret.maxlength=val;
		}
        else
        {
            struct TreeNodeData dataL ;
		struct TreeNodeData dataR ;
		
            bool leftavailable;
            bool rightavailable;
            if (root->left != NULL)
            {
                dataL = solve(root->left);
                leftavailable=true;
            }
            else
            {
                leftavailable=false;
            }
            if (root->right != NULL)
            {
                dataR = solve(root->right);
                rightavailable=true;
            }
            else
            {
                rightavailable=false;
            }    
        
            bool isavailable[6]={
                true
                ,leftavailable
                ,rightavailable
                ,leftavailable
                ,rightavailable
                ,leftavailable&rightavailable};
            int arr[6] = {
                val
                ,dataL.maxheight + val
                ,dataR.maxheight + val
                ,dataL.maxlength
                ,dataR.maxlength
                ,dataL.maxheight + dataR.maxheight + val
            };
            int maxheight =maximum(arr, isavailable,3);
            ret.maxheight=maxheight;
            
            int maxlength=(leftavailable|rightavailable)?max(maxheight,maximum(arr+3,isavailable+3,3)):maxheight;
            ret.maxlength=maxlength;
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