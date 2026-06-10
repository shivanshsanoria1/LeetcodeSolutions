class Solution {
public:
    // T.C.=O(n*logn), S.C.=O(n)
    // DP-Tabulation with Space-Optimization
    int deleteAndEarn(vector<int>& nums) { 
        // num -> freq
        unordered_map<int, int> mp; 
        for(int num: nums)
            mp[num]++;
            
        vector<int> vec;
        for(auto [num, freq]: mp)
            vec.push_back(num);
        sort(vec.begin(), vec.end());

        // prev2 ~ dp[i-2], prev1 ~ dp[i-1]
        int prev2 = 0;
        int prev1 = vec[0] * mp[vec[0]];

        for(int i=1; i<vec.size(); i++)
        {
            int curr = -1;
            if(vec[i] - vec[i-1] == 1)
                curr = max(prev1, prev2 + vec[i] * mp[vec[i]]);
            else
                curr = prev1 + vec[i] * mp[vec[i]];
            
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};
// similar: [198. house-robber]