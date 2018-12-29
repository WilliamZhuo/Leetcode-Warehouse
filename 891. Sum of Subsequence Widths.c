/*
2^n time cost 
1. (improve step 2)can we get the width of one subsequence from two two subsequences(divide and conquer)-> possible
XX 2. can we record the widths of smaller subsequences(dynamic programming)->difficult->2^n is large
3. (improve step 1)can we avoid list all subsequences?
Step1. list all subsequence
Step2. get the width of each subsequence
Step3. get the sum of widths
*/


#define NOTEND 0
#define ISEND 1

class Solution {
public:
    int sumSubseqWidths(vector<int>& A) {
        
    }
    
    //iterate 0,0,0,0->1,1,1,1
    int iterate(vector<int>& ismenber)
    {
        //if ismenber=1,1,1,1.....1  return ISEND
        //else +1 return NOTEND
    }
    
    int getwidth(vector<int>& A,const vector<int> ismenber)
    {
        
    }
};