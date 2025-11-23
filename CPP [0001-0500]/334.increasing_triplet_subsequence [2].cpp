class Solution {
public:
    bool increasingTriplet(vector<int>& nums) { //T.C.=O(n) , S.C.=O(n)
        int n= nums.size();
        if(n < 3) //atleast 3 numbers are needed
            return false;
        
        vector<int> left_min(n);
        left_min[0] = nums[0];
        for(int i=1; i<n; i++)
            left_min[i] = min(left_min[i-1],nums[i]);
        
        vector<int> right_max(n);
        right_max[n-1] = nums[n-1];
        for(int i=n-2; i>=0; i--)
            right_max[i] = max(right_max[i+1],nums[i]);
        
        for(int i=1; i<n-1; i++)
            if(left_min[i-1] < nums[i] && nums[i] < right_max[i+1])
                return true;
        
        return false;
    }
};