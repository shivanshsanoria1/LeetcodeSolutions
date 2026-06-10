class Solution {
public:
    // T.C.=O(n), S.C.=O(n)
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();

        vector<int> prefixMax(n, 0);
        prefixMax[0] = nums[0];
        for(int i=1; i<n; i++)
            prefixMax[i] = max(nums[i], prefixMax[i-1]);
        
        vector<int> postfixMax(n, 0);
        postfixMax[n-1] = nums[n-1];
        for(int i=n-2; i>=0; i--)
            postfixMax[i] = max(nums[i], postfixMax[i+1]);
        
        long long int ans = 0;
        for(int j=1; j<n-1; j++)
            ans = max(ans, (long long int)(prefixMax[j-1] - nums[j]) * postfixMax[j+1]);

        return ans;
    }
};

/*
# given: i < j < k
# we need to maximize the value (nums[i] - nums[j]) * nums[k]
# for each index j, we need to find the max value in index-range [0, j-1], ie, nums[i]
  and the max value in index-range [j+1, n-1], ie, nums[k]
*/