class Solution {
private:
    // 10^9 + 7
    #define MOD 1000000007

public:
    int countGoodStrings(int low, int high, int zero, int one) { // DP, T.C.=O(high), S.C.=O(high)
        vector<int> dp(high + 1, 0); // dp of size (high + 1) filled with 0's
        dp[0] = 1; // 1 string possible with length 0
        for(int i=1; i<=high; i++)
        {
            int count0 = i - zero >= 0 ? dp[i - zero] : 0;
            int count1 = i - one >= 0 ? dp[i - one] : 0;
            dp[i] = (count0 + count1) % MOD;
        }
        int ans = 0;
        for(int i=low; i<=high; i++)
            ans = (ans + dp[i]) % MOD;
        return ans;
    }
};
// dp[i] represents number of strings possible with length i