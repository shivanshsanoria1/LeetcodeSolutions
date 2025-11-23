class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int ans=0;
        for(int i=0; i<32; i++) 
        {
            int ones=0, zeros=0; //count of ones and zeros at ith bit of all nums in array
            for(int j=0; j<nums.size(); j++)
            {
                if(nums[j]&1) //ith bit of nums[j] is 1
                    ones++;
                else //ith bit of nums[j] is 0
                    zeros++;
                nums[j]=nums[j]>>1; //right shift nums[j] to get to the next bit
            }
            ans+=ones*zeros;
        }
        return ans;
    }
};