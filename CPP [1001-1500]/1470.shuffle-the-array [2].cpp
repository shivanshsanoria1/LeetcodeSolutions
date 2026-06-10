class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) { //in-place
        for(int i=0; i<n; i++) //modify the left half by keeeping both the values of pair (nums[i],nums[i+n]) at each index
            nums[i]= nums[i]+nums[i+n]*10000;
        for(int i=n-1; i>=0; i--)
        {
            nums[2*i+1]= nums[i]/10000;
            nums[2*i]= nums[i]%10000;
        }
        return nums;
    }
};