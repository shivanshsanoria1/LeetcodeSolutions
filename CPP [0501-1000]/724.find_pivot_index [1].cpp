class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum=0, n=nums.size();
        for(int i=0; i<n; i++)
            sum+=nums[i];
        int sum_left=0, sum_right=sum-nums[0];
        for(int i=0; i<n; i++)
        {
            if(sum_left==sum_right)
                return i;
            sum_left+=nums[i];
            if(i+1 < n)
                sum_right-=nums[i+1];
            else
                sum_right=0;
        }
        return -1;
    }
};