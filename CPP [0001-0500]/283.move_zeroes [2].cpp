class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size(), start=0, end=n-1;
        vector<int> ans(n);
        for(int i=0; i<n; i++)
        {
            if(nums[i]==0)
            {
                ans[end]=nums[i];
                end--;
            }
            else
            {
                ans[start]=nums[i];
                start++;
            }
        }
        for(int i=0; i<n; i++)
            nums[i]=ans[i];
    }
};