class Solution {
public:
    // T.C.=O(sqrt(c)), S.C.=O(sqrt(c))
    // 2-pointer
    bool judgeSquareSum(int c) {
        // stores perfect-squares in range [0, sqrt(c)]
        vector<long long int> perfectSquares;
        for(int i=0; i <= sqrt(c); i++)
            perfectSquares.push_back(i*i);

        int left = 0, right = perfectSquares.size() - 1;
        while(left <= right)
        {
            if(perfectSquares[left] + perfectSquares[right] == c)
                return true;
            else if(perfectSquares[left] + perfectSquares[right] < c)
                left++;
            else // perfectSquares[left] + perfectSquares[right] > c
                right--;
        }

        return false;
    }
};