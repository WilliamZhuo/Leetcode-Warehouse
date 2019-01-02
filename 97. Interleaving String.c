//step1 check len(s3)==len(s1)+len(s2)
//Brute force n^n-> not available
//use s3 as a queue
//case1: s3 begin==s1 begin, pop s1 and s3,push to s1' stack and s3'stack, and push 1 to decision stack
//case2: s3 begin==s2 begin, pop s2 and s3,push to s2' stack and s3'stack, and push 2 to decision stack
//case3: s3 begin==s2 begin==s1 begin, record the s3 position,  then try *****
//case3.1:pop s1 and s3,push to s1' stack and s3'stack, if this is the wrong path, recover to ***** and try case 3.2
//case3.2:pop s2 and s3,push to s2' stack and s3'stack, if this is the wrong path, there is no solution


class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        
    }
};