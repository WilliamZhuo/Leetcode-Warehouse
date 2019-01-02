/*
abcde edcba %1337
abcba
*/
/*
100 -1 91+19=110
9100-91=(91-1)*(100)+(100-91)
n=2->99 x 91 = 9009
n=3->
*/
/*
cheat: -> precalculation
solution digit<=2n
n=1
a = 1k, 3x3=9

n=2
ab+ba=11k
(x-1 , 100-x)=Palindromic -> 
x-1=90 
100-x=09

n=3
abccba=100001*a+010010*b+001100*c
gcd=11
990

n=4
abcd+dcba=1001*x+110*y
(x-1 , 10000-x)=Palindromic -> 
x-1=9900
10000-x=0099 

n=5
abcde+edcba=11111*k

n=6
abcdef+fedcba=100001*a+10010*b+1100*c
(x-1 , 1000000-x)=Palindromic -> 
x-1=999000
1000000-x=000999 

n=7
abcdefg+gfedcba=

n=8
abcd+dcba=11111111*k
(x-1 , 100000000-x)=Palindromic -> 
x-1=99990000
100000000-x=00009999 
*/
class Solution {
public:
    int largestPalindrome(int n) {
        
    }
};
