class Solution {
public:
    void solve(vector<int>& nums, int n, int target, int sum, int i, int& ans)
    {
        if(i==n)
        {
            if(sum == target)
                ans++;
            return;
        }
        solve(nums,n,target,sum + nums[i],i+1,ans);
        solve(nums,n,target,sum - nums[i],i+1,ans);
    }
    
    int findTargetSumWays(vector<int>& nums, int target) { //T.C.=O(2^n) ; recursion
        target= abs(target);
        int n=nums.size(), ans=0;
        solve(nums,n,target,0,0,ans);
        return ans;
    }
};