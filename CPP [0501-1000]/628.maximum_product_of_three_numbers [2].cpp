class Solution {
public:
    int maximumProduct(vector<int>& nums) { //T.C.=O(n) , S.C.=O(1)
        int max1=INT_MIN, max2=INT_MIN, max3=INT_MIN;
        int min1=INT_MAX, min2=INT_MAX;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] >= max1) //new max 1 is found
            {
                max3=max2;
                max2=max1;
                max1=nums[i];
            }
            else if(nums[i] >= max2) //new max 2 is found
            {
                max3=max2;
                max2=nums[i];
            }
            else if(nums[i] >= max3) //new max 3 is found
                max3=nums[i];
            if(nums[i] <= min1) //new min 1 is found
            {
                min2=min1;
                min1=nums[i];
            }
            else if(nums[i] <= min2) //new min 2 is found
                min2=nums[i];
        }
        return max(max1*max2*max3,min1*min2*max1);
    }
};