class Solution {
public:
    vector<int> buildArray(vector<int>& nums) { //modifying the original vector
        int n=nums.size();
        int MOD=1001; //since  0 <= nums[i] <= 1000
        for(int i=0; i<n; i++)
        {
            int j=nums[i];
            nums[i]= nums[i] + (nums[j] % MOD)*MOD;
        }
        for(int i=0; i<n; i++)
            nums[i]= nums[i]/MOD;
        return nums;
    }
};