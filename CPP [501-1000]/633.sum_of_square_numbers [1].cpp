class Solution {
public:
    bool judgeSquareSum(int c) { // T.C.=O(sqrt(c)) ; S.C.=O(sqrt(c))
        int cr=sqrt(c);
        long int sq[cr+1];
        for(int i=0; i<cr+1; i++) // array of perfect squares [0,1,4,9,16,...,sqrt(n)]
            sq[i]=i*i;
        int start=0, end=cr;
        while(start <= end)
        {
            if(sq[start]+sq[end] == c)
                return true;
            else if(sq[start]+sq[end] > c)
                end--;
            else
                start++;
        }
        return false;
    }
};