class Solution {
public:
    bool judgeSquareSum(int c) { // T.C=O(sqrt(c)*log(c)) ; S.C.=O(1)
        for(long int a=0; a*a<=c; a++) // a varies from 0 to sqrt(c)
        {
            double b=sqrt(c-a*a); // finding sqrt(c-a*a) takes O(log c) time in worst case
            if(b == int(b))
                return true;
        }
        return false;
    }
};