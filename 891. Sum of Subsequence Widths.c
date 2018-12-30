/*
BRUTE force
2^n time cost 
Step1. list all subsequence
Step2. get the width of each subsequence
Step3. get the sum of widths

BRUTE force conclusion
1. (improve step 2)can we get the width of one subsequence from two two subsequences(divide and conquer)-> possible
XX 2. can we record the widths of smaller subsequences(dynamic programming)->difficult->2^n is large
3. (improve step 1)can we avoid list all subsequences?

-------------------------------------
result=allsubseq.sum(max-min)=allsubseq.sum(max)-allsubseq.sum(min)
-------------------------------------
STEP1. SORTING
STEP2. for each number in the sub sequence, get how much times it is maximun and minimum
STEP3. sum of widths=allsubseq.sum(max)-allsubseq.sum(min)

*/
#define NOTEND 0
#define ISEND 1
#define MODNUM 1000000007
#define EXPLIMIT 20000
//MULLIMIT=MODNUM*2
#define MULLIMIT 2000000014  
#define ADDLIMIT 4611686018427387903 
class Solution {
public:
    int sumSubseqWidths(vector<int>& A) {
        //STEP1. SORTING
        std::sort (A.begin(), A.end());
        //I can replace the sort with counting sort
        //STEP2. for each element get (# of becoming maximun - # minimum)*val
        int index=0;
        long int sum=0;
        int size=A.size();
        for(index=0;index<size;index++)
        {
            int countpos=modpower(2, index);
            int countneg=modpower(2, size-index-1);
            int count=countpos-countneg;
            long int sumA=sum+modmul(count,A[index]);

            if(sumA>MODNUM)
                sum=sumA-MODNUM;
            else if(sum<-MODNUM)
                sum=sumA+MODNUM;
            else
                sum=sumA;
            //debug message
           // cout<<"index:"<<index<<endl;
          ////  cout<<"val:"<<A[index]<<endl;
           // cout<<"pos:"<<countpos<<endl;
           // cout<<"neg:"<<countneg<<endl;
          //  cout<<"count:"<<count<<endl;
          //  cout<<"sumA:"<<sumA<<endl;
          //  cout<<"sum:"<<sum<<endl;
        }
        return sum;
        //NOTE: use long int 
    }
    //int precalculatedpower[15]={2^(2^0),2^(2^1),2^(2^2),....};
    long int powtable[15]={2,
                4,
                16,
                256,
                65536,
                294967268,
                582344008,
                279632277,
                792845266,
                418385479,
                812734592,
                409643880,
                246797651,
                112754241,
                774491455};
    int exptable[15]={1,
                2,
                4,
                8,
                16,
                32,
                64,
                128,
                256,
                512,
                1024,
                2048,
                4096,
                8192,
    16384};
    long int modmul(long int a, long int b)
    {
        
        return (a*b)%MODNUM;    
    }
    long int modpower(int base, int exp)
    {
        //2^exp=(2^exp1)*(2^exp2)
        //exp=exp1+exp2+exp3
        //let exp=2^k 
        //    use a table T to store 2^(2^k) k=0~n
        //    exp=2^k1+2^k2+....
        //    2^exp=T[k1]*T[k2]*T[k3].....
        //NOTE1: the number may be very large, so store  2^(2^k) mod 10^9+7 in table T
        //NOTE2: exp may be zero, so the formula should be 2^exp=1*T[k1]*T[k2]*T[k3].....
        int i;
        long int result=1;
        for(i=14;i>=0;i--)
        {
            if(exp>=exptable[i])
            {
                exp-=exptable[i];
                result=modmul(result,powtable[i]);
            }
        }
        return result;
    }
};