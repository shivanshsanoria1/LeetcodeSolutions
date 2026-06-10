class Solution {
public:
    int maximumProduct(vector<int>& nums) { //T.C.=O(nlogn) , S.C.=O(1)
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int max1=nums[n-1], max2=nums[n-2], max3=nums[n-3]; //3 max nums
        int min1=nums[0], min2=nums[1]; //2 min nums
        int ans= max(max1*max2*max3,min1*min2*max1);
        return ans;
    }
};