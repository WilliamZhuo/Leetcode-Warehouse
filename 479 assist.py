import math
#https://medium.com/@d_dchris/largest-palindrome-product-problem-brilliant-approach-using-mathematics-python3-leetcode-479-b3f2dd91b1aa
#
def getPalindromeRecursive(n,count,upper,lower):
    if(n==count):
        num=int(pow(10,n))
        limit=num-num%11
        val=upper*num+lower
        for div in range(limit,1,-11):
            if((val%div==0)&(val/div<num)):
                return val
        return -1
    else:    
        upper=upper*10
        lower=lower/10
        for a in range (9,-1,-1):
            nextupper=upper+a             
            nextlower=lower+pow(10,n-1)*a 
            sol=getPalindromeRecursive(n,count+1,nextupper,nextlower)
            if(sol>0):
                return sol
        return -1  
        
def getLargestPalindrome(n):
    if(n==1):
        return 9
    if(n%2==0):
        val=0
        for i in range(0,int(n/2)):
            val=val+9
            val=val*10            
        for i in range(0,int(n/2)):
            val=val*10            
        for i in range(0,int(n/2)):
            val=val*10            
        for i in range(0,int(n/2)):
            val=val+9
            val=val*10            
        return val/10
    return getPalindromeRecursive(n,0,0,0);

a=list()
b=list()
for i in range(1,9):
    a.append(getLargestPalindrome(i))
    b.append(a[i-1]%1337)
    