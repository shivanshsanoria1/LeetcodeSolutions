class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n=nums.size(), i=0, j=1;
        while(i<n && j<n)
        {
            if(nums[i]%2==0) // nums[i] is even
                i=i+2;
            if(nums[j]%2==1) // nums[j] is odd
                j=j+2;
            else if(nums[i]%2==1 && nums[j]%2==0) // nums[i] is odd and nums[j] is even
                swap(nums[i],nums[j]);
        }
        return nums;
    }
};