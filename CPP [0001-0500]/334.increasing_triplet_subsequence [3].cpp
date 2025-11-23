class Solution {
public:
    bool increasingTriplet(vector<int>& nums) { //T.C.=O(n) , S.C.=O(1)
        int n= nums.size();
        if(n < 3) //atleast 3 numbers are needed
            return false;
        int low=INT_MAX, mid=INT_MAX;
        for(int i=0; i<n; i++)
        {
            if(nums[i] <= low) //new 'low' found
                low=nums[i];
            else if(nums[i] <= mid) //new 'mid' found
                mid=nums[i];
            else //new 'high' found
                return true;
        }
        return false;
    }
};
// idea is to find 3 numbers such that low < mid < high
// try to minimise low and mid