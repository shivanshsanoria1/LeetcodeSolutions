class Solution {
public:
    // T.C=O(c), S.C.=O(1)
    bool judgeSquareSum(int c) { 
        for(long long int a=0; a*a <= c; a++)
            for(long long int b=0; b*b <= c; b++)
                if(a*a + b*b == c)
                    return true;

        return false;
    }
};