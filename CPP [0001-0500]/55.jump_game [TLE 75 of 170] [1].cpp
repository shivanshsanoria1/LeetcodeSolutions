class Solution {
public:
    bool solve(vector<int>& nums, int n, int index)
    {
        if(index==n-1)
            return true;
        if(nums[index]==0)
            return false;
        bool check=false;
        for(int i=1; i<=nums[index]; i++)
            check=check || solve(nums,n,index+i);
        return check;
    }
    
    bool canJump(vector<int>& nums) { //recursion
        int n=nums.size();
        return solve(nums,n,0);
    }
};