class Solution {
public:
    int nthUglyNumber(int n) { //T.C.=O(n) ; S.C.=O(n)
        vector<int> dp(n); //vector to store first n ugly numbers
        int i2=0, i3=0, i5=0; //pointers to the index where 2,3,5 will be multiplied
        dp[0]=1; //1st ugly num is 1
        for(int i=1; i<n; i++)
        {
            dp[i]=min(2*dp[i2],min(3*dp[i3],5*dp[i5]));
            if(dp[i]==2*dp[i2])
                i2++;
            if(dp[i]==3*dp[i3])
                i3++;
            if(dp[i]==5*dp[i5])
                i5++;
        }
        return dp[n-1]; //return last element in dp[]
    }
};