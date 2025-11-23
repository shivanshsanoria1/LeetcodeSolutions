class Solution {
public:
    bool solve(vector<int>& nums, int n, vector<int>& dp, int index)
    {
        if(dp[index]!=-1) //already present in dp
            return dp[index];
        if(index==n-1) //reached last index
        {
            dp[index]=1;
            return true;
        }
        if(nums[index]==0) //element is 0 and is not at last index
        {
            dp[index]=0;
            return false;
        }
        for(int i=1; index+i<n && i<=nums[index]; i++)
        {
            if(solve(nums,n,dp,index+i)==true) //return true if 1 recursion tree branch return true
            {
                dp[index]=1;
                return true;
            }
        }
        dp[index]=0; //return false if no recursion tree branch return true
        return false;
    }
    
    bool canJump(vector<int>& nums) { //recusion + dp
        int n=nums.size();
        vector<int> dp(n,-1); //-1:not visited, 0:false, 1:true
        return solve(nums,n,dp,0);
    }
};