class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size();
        // the next of last element is the 0th element
        int pivotCount = nums[n-1] > nums[0] ? 1 : 0;
        for(int i=0; i<n-1; i++)
        {
            if(nums[i] > nums[i+1])
                pivotCount++;
            if(pivotCount > 1)
                return false;
        }
        return true;
    }
};