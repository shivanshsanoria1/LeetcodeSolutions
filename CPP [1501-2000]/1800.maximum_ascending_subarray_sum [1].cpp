class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int sum=nums[0], max_sum=nums[0];
        for(int i=1; i<nums.size(); i++)
        {
            if(nums[i] > nums[i-1]) //add nums[i] to curr sum
                sum+=nums[i];
            else //reset curr sum to nums[i]
                sum=nums[i];
            max_sum= max(max_sum,sum);
        }
        return max_sum;
    }
};