class Solution {
public:
    int integerBreak(int n) { // T.C.=O(n), S.C.=O(1), Math soln.
        if(n == 2) // 2=1+1, pro=1*1=1
            return 1;
        if(n == 3) // 3=2+1, pro=2*1=2
            return 2;

        int pro = 1;
        while(n > 4)
        {
            n -= 3;
            pro *= 3;
        }
        return pro*n;
    }
};