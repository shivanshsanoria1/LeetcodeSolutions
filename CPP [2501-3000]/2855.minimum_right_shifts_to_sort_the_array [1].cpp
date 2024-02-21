class Solution {
public:
    int minimumRightShifts(vector<int>& nums) { // T.C.=O(n), S.C.=O(1)
        int n=nums.size();
        int idx = -1; // index of pivot point
        for(int i=1; i<n; i++)
            if(nums[i-1] > nums[i]) // pivot found
            {
                if(idx != -1) // more than 1 pivot found
                    return -1;
                idx = i;
            }

        if(idx == -1) // no pivot found, ie, array is already sorted
            return 0;
        // min num in the 1st part of array must be greater than the max num in the 2nd part
        return nums[0] > nums[n-1] ? n - idx : -1;
    }
};