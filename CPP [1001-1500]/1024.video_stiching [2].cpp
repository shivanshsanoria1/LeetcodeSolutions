class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        vector<int> dp(time + 1, -1);
        // find the max end-time for each start time
        for(auto& clip: clips)
        {
            int start = min(clip[0], time), end = min(clip[1], time);
            dp[start] = max(dp[start], end);
        }
        // dp[i]: max end-time for start-times in range [0,i] 
        for(int i=1; i<=time; i++)
            dp[i] = max(dp[i], dp[i-1]);
        
        int ans = 0;
        int idx = 0;
        while(idx < time)
        {
            if(dp[idx] <= idx) // dp[idx] will jump back in time instead of forward
                return -1;
            idx = dp[idx]; // use dp[idx] as next idx value
            ans++;
        }
        return ans;
    }
};