class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) { // T.C.=O(n), S.C.=O(1)
        long long int ans = 0;
        long long int zeros = 0; // keeps track of num of consecutive 0's
        for(int num: nums)
        {
            if(num == 0)
                zeros++;
            else
            {
                ans += (zeros*(zeros + 1))/2;
                zeros = 0;
            }
        }
        if(zeros > 0)
            ans += (zeros*(zeros + 1))/2;
        return ans;
    }
};