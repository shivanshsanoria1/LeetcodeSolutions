class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum=0, n=nums.size();
        for(int i=0; i<n; i++)
            sum+=nums[i];
        int sum_left=0;
        for(int i=0; i<n; i++)
        {
            if(sum_left==sum-nums[i]-sum_left)
                return i;
            sum_left+=nums[i];
        }
        return -1;
    }
};