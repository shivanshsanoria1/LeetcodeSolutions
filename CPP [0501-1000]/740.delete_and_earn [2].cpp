class Solution {
public:
    // T.C.=O(n*logn), S.C.=O(n)
    // DP-Tabulation
    int deleteAndEarn(vector<int>& nums) { 
        // num -> freq
        unordered_map<int, int> mp; 
        for(int num: nums)
            mp[num]++;
            
        vector<int> vec;
        for(auto [num, freq]: mp)
            vec.push_back(num);
        sort(vec.begin(), vec.end());

        int n=vec.size();
        vector<int> dp(n);

        dp[0] = vec[0] * mp[vec[0]];

        if(n == 1) 
            return dp[0];

        dp[1] = (vec[1] - vec[0] == 1) ? max(dp[0], vec[1] * mp[vec[1]]) : dp[0] + vec[1] * mp[vec[1]];

        for(int i=2; i<n; i++)
        {
            if(vec[i] - vec[i-1] == 1)
                dp[i] = max(dp[i-1], dp[i-2] + vec[i] * mp[vec[i]]);
            else
                dp[i] = dp[i-1] + vec[i] * mp[vec[i]];
        }

        return dp[n-1];
    }
};
// dp[i]: max amount earned using the nums upto index i
// similar: [198. house-robber]
