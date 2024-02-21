class Solution {
public:
    int deleteAndEarn(vector<int>& nums) { //T.C.=O(nlogn) , S.C.=O(n) ; DP
        unordered_map<int,int> freq; //num -> freq
        for(int i=0; i<nums.size(); i++)
            freq[nums[i]]++;
        set<int> s(nums.begin(),nums.end());
        vector<int> vec(s.begin(),s.end()); //removed duplicates and sorted 'nums'
        int n=vec.size();
        vector<int> dp(n);
        if(n == 1) //only 1 identical num in array so just pick that num
            return nums[0]*freq[nums[0]];
        dp[0] = vec[0]*freq[vec[0]];
        dp[1] = (vec[1]-vec[0]==1) ? max(dp[0], vec[1]*freq[vec[1]]) : (dp[0] + vec[1]*freq[vec[1]]);
        for(int i=2; i<n; i++)
            dp[i] = (vec[i]-vec[i-1]==1) ? max(dp[i-1], vec[i]*freq[vec[i]] + dp[i-2]) : (dp[i-1] + vec[i]*freq[vec[i]]);
        return dp[n-1];
    }
};
// dp[i]: max amount earned using the nums upto index i
// similar to Leetcode-198 (House Robber)
