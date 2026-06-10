class Solution {
public:
    // T.C.=O(sqrt(c)), S.C.=O(1)
    // 2-pointer
    bool judgeSquareSum(int c) {
        int left = 0, right = sqrt(c);
        while(left <= right)
        {
            long long int aa = left * left;
            long long int bb = right * right;

            if(aa + bb == c)
                return true;
            else if(aa + bb < c)
                left++;
            else // aa + bb > c
                right--;
        }

        return false;
    }
};