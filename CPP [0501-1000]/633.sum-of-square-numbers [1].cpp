class Solution {
public:
    // T.C=O(sqrt(c)*log(c)), S.C.=O(1)
    bool judgeSquareSum(int c) { 
        for(long long int a=0; a*a <= c; a++)
        {
            double b = sqrt(c - a*a);
            if(b == int(b))
                return true;
        }

        return false;
    }
};