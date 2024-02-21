class Solution {
public:
    int maximumDifference(vector<int>& nums) { //T.C.=O(n)
        int n=nums.size();
        int max_diff=-1, min_ele=nums[0];
        for(int i=1; i<n; i++)
        {
            if(nums[i] > min_ele) //check to update the max difference
                max_diff=max(max_diff,nums[i]-min_ele);
            else //update the min element
                min_ele=nums[i];
        }
        return max_diff;
    }
};