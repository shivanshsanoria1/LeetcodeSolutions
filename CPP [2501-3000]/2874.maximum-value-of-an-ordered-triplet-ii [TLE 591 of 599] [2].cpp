class Solution {
public:
    // T.C.=O(n^2), S.C.=O(1)
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long int ans = 0;

        for(int j=1; j<n-1; j++)
        {
            int maxLeft = 0;
            for(int i=0; i<j; i++)
                maxLeft = max(maxLeft, nums[i]);
            
            int maxRight = 0;
            for(int k=j+1; k<n; k++)
                maxRight = max(maxRight, nums[k]);
            
            ans = max(ans, (long long int)(maxLeft - nums[j]) * maxRight);
        }

        return ans;
    }
};

/*
# given: i < j < k
# we need to maximize the value (nums[i] - nums[j]) * nums[k]
# for each index j, we need to find the max value in index-range [0, j-1], ie, nums[i]
  and the max value in index-range [j+1, n-1], ie, nums[k]
*/