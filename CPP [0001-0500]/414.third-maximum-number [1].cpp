class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long int max=LONG_MIN, max2=LONG_MIN, max3=LONG_MIN;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] > max) // curr. value > max
            {
                max3=max2; // update max3 before updating max2
                max2=max; // update max2 before updating max
                max=nums[i]; // update max value
            }
            else if(nums[i] < max && nums[i] > max2) // curr. value is in between max and max2
            {
                max3=max2; // update max3 before updating max2
                max2=nums[i]; // update max2 value
            }
            else if(nums[i] < max2 && nums[i] > max3) // curr. value is in between max2 and max3
                max3=nums[i]; // update max3 value
        }
        if(max3==LONG_MIN) // max3 is not found
            return max;
        return max3;
    }
};