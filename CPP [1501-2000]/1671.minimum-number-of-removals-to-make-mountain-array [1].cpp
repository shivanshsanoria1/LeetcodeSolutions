class Solution {
private:
    vector<int> findLIS(vector<int>& nums) { 
        int n = nums.size();
        vector<int> dp(n, 1);

        for(int i=1; i<n; i++)
            for(int prevIdx = 0; prevIdx < i; prevIdx++)
                if(nums[prevIdx] < nums[i])
                    dp[i] = max(dp[i], 1 + dp[prevIdx]);

        return dp;
    }

public:
    // T.C.=O(n^2), S.C.=O(2*n)
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();

        vector<int> lis = findLIS(nums);

        reverse(nums.begin(), nums.end());
        vector<int> lds = findLIS(nums);
        reverse(lds.begin(), lds.end());

        int maxMountainLen = 0;
        for(int i=0; i<n; i++)
            if(lis[i] > 1 && lds[i] > 1)
                maxMountainLen = max(maxMountainLen, lis[i] + lds[i] - 1);
        
        return n - maxMountainLen;
    }
};

/*
# prerequisite: [300. longest-increasing-subsequence]

# "minimum number of elements to remove to make the array a mountain array"
  is equivalent to 
  "subtracting the max length of mountain subsequence 
  from the total length of array"

# max length of mountain subsequence for a index i is given by:
  (lis[i] + lds[i] - 1)
  here, -1 is done since nums[i] is counted in both lis[i] and lds[i]
# lis[i]: length of Longest Increasing Subsequence ending at index i
# lds[i]: length of Longest Decreasing Subsequence ending at index i

# lds[] can be calculated from the same function that calculates lis[]
  just by reversing nums[] before the function call and 
  reversing the obtained lds[] from that function call

# checking the condition (lis[i] > 1 && lds[i] > 1) 
  is necessary before calculating the mountain length 
  to ensure there is atleast 1 element on both the
  left and right sides of index i in the mountain subsequence
*/