class Solution {
public:
    int integerBreak(int n) { // T.C.=O(logn), S.C.=O(1), Math soln.
        if(n == 2) // 2=1+1, pro=1*1=1
            return 1;
        if(n == 3) // 3=2+1, pro=2*1=2
            return 2;

        int rem = n % 3;
        int pro = 1;
        if(rem == 0) // break n into all 3's
            pro = pow(3, n/3);
        else if(rem == 1) // break n as 4 + (n/3-1) 3's
            pro = 4*pow(3, n/3 - 1);
        else // break n as 2 + (n/3) 3's
            pro = 2*pow(3, n/3);
        return pro;
    }
};