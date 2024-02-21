class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n=nums.size();
        if(n == 1)
            return true;
        bool inc = false, dec = false;
        for(int i=1; i<n; i++)
        {
            if(nums[i-1] < nums[i])
                inc = true;
            else if(nums[i-1] > nums[i])
                dec = true;
            // array should not be monotonically increasing and decreasing
            if(inc && dec) 
                return false;
        }
        return true;
    }
};