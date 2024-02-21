class Solution {
public:
    bool judgeSquareSum(int c) { // T.C=O(c) ; S.C.=O(1)
        for(long int a=0; a*a<=c; a++) // a varies from 0 to sqrt(c)
            for(long int b=0; b*b<=c; b++) // b varies from 0 to sqrt(c)
                if(a*a+b*b==c)
                    return true;
        return false;
    }
};