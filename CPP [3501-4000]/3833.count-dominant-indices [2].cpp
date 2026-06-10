class Solution {
public:
    // T.C.=O(n), S.C.=O(n)
    int dominantIndices(vector<int>& nums) {
        const int n = nums.size();
        vector<int> postFixSum(n, 0);
        for(int i=n-2; i>=0; i--)
            postFixSum[i] = postFixSum[i+1] + nums[i+1];

        int count = 0;
        for(int i=0; i<n-1; i++)
            if(nums[i] > postFixSum[i]/(n-i-1))
                count++;

        return count;
    }
};

// postFixSum[i]: nums[i+1] + nums[i+2] + ... + nums[n-1]