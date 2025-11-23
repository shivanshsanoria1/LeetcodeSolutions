class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans=nums[0];
        int max_so_far=nums[0], min_so_far=nums[0]; 
        for(int i=1; i<nums.size(); i++)
        {
            if(nums[i]<0)
                swap(max_so_far,min_so_far);
            max_so_far=max(nums[i],nums[i]*max_so_far); //max product for all the subarrays whose end point is nums[i]
            min_so_far=min(nums[i],nums[i]*min_so_far); //min product for all the subarrays whose end point is nums[i]
            ans=max(ans,max_so_far);
        }
        return ans;
    }
};