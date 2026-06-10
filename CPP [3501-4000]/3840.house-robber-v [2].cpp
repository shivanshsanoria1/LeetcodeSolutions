class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    // DP: Tabulation (space-optimization)
    long long rob(vector<int>& nums, vector<int>& colors) {
        const int n = nums.size();
        long long int prev2 = 0; // dp[i-2]
        long long int prev1 = 0; // dp[i-1]
        
        for(int i=0; i<n; i++){
            long long int curr = 0;

            if(i-1 >= 0 && colors[i-1] == colors[i])
                curr = max(prev1, nums[i] + prev2);
            else
                curr = nums[i] + max(prev1, prev2);

            prev2 = prev1;
            prev1 = curr;
        }
            
        return prev1;
    }
};

// prerequisite: 198.house-robber