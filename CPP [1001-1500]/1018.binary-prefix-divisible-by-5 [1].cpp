class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int n=nums.size();
        vector<bool> ans(n,false);
        int num=0;
        for(int i=0; i<n; i++)
        {
            num=(2*num+nums[i])%5;
            if(num == 0)
                ans[i]=true;
        }
        return ans;
    }
};