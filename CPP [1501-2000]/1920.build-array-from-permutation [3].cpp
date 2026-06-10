class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    // modulo-arithmatic
    // modifying the original vector
    vector<int> buildArray(vector<int>& nums) { 
        const int M = 1000;

        for(int& num: nums)
            num += (nums[num] % M) * M;

        for(int& num: nums)
            num /= M;

        return nums;
    }
};

/*
# each num can be thought of as 
  num = a + b*M; a,b < M
# num % M = a
# num / M = b
*/