//step1 check len(s3)==len(s1)+len(s2)
//Brute force n^n-> not available
//use s3 as a queue
//case1: s3 begin==s1 begin, pop s1 and s3,push to s1' stack and s3'stack, and push 1 to decision stack
//case2: s3 begin==s2 begin, pop s2 and s3,push to s2' stack and s3'stack, and push 2 to decision stack
//case3: s3 begin==s2 begin==s1 begin, record the s3 position,  then try *****
//case3.1:pop s1 and s3,push to s1' stack and s3'stack, if this is the wrong path, recover to ***** and try case 3.2
//case3.2:pop s2 and s3,push to s2' stack and s3'stack, if this is the wrong path, there is no solution

//Note: case3: xxxxxA   xxxxxB  xxxxxA you should fork at the last x, instead of every x

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()+s2.size()!=s3.size())
            return false;
        initialize(s1,s2,s3);
        return solve();
        return true;
    }
    
private:
    void initialize(string s1,string s2,string s3)
    {
        int l=0;
        for(l=s1.size()-1;l>=0;l--)
        {
            s1_s.push(s1[l]);
        }
        for(l=s2.size()-1;l>=0;l--)
        {             
            s2_s.push(s2[l]);
        }
        for(l=s3.size()-1;l>=0;l--)
        {
            s3_s.push(s3[l]);
        }
    }
    
    bool solve()
    {
        if(s1_s.size()==0&&s2_s.size()==0&&s3_s.size()==0)
            return true;
        else if(s3_s.size()==0)
            return false;
        char ch=s3_s.top();
        if(s1_s.size()>0)
        {
            if(s1_s.top()==ch)
            {
                //s1_backup.push(s1_s.top());
                s1_s.pop();
                //s3_backup.push(ch);
                s3_s.pop();
                if(solve())
                   return solve();
                //char ch=s3_backup.top();
                s3_s.push(ch);
                s1_s.push(ch);
                //s3_backup.pop();
            }
        }
        if(s2_s.size()>0)
        {
            if(s2_s.top()==ch)
            {
                //s2_backup.push(s2_s.top());
                s2_s.pop();
                //s3_backup.push(ch);
                s3_s.pop();
                if(solve())
                   return solve();
               // char ch=s3_backup.top();
                s3_s.push(ch);
                s2_s.push(ch);
               // s3_backup.pop();            
            }
        }
        return false;
    }
    
    std::stack<char> s1_s;    
    std::stack<char> s2_s;  
    std::stack<char> s3_s;                 
};