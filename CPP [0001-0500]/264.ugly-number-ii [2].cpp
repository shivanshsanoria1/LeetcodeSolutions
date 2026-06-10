class Solution {
public:
    // T.C.=O(n), S.C.=O(n)
    int nthUglyNumber(int n) { 
        vector<int> dp(n); 
        // pointers to the index where 2,3,5 will be multiplied
        int i2 = 0, i3 = 0, i5 = 0; 
        // 1st ugly num is 1
        dp[0] = 1; 

        for(int i=1; i<n; i++)
        {
            dp[i] = min(2*dp[i2], min(3*dp[i3], 5*dp[i5]));

            if(dp[i] == 2*dp[i2])
                i2++;
            if(dp[i] == 3*dp[i3])
                i3++;
            if(dp[i] == 5*dp[i5])
                i5++;
        }

        // nth ugly num
        return dp[n-1];
    }
};