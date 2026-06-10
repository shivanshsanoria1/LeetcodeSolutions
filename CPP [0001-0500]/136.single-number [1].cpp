class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
        if(n==1) // only 1 element in array
            return nums[0];
        sort(nums.begin(),nums.end());
        if(nums[0] != nums[1]) // 1st element is different
            return nums[0];
        if(nums[n-2] != nums[n-1]) // last element is different
            return nums[n-1];
        for(int i=0;i<n-2;i++)
        {
            if(nums[i] != nums[i+1] && nums[i+1] != nums[i+2])
                return nums[i+1];
        }
        return -1;
    }
};