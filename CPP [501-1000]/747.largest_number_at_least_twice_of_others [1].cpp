class Solution {
public:
    int dominantIndex(vector<int>& nums) { // T.C.=O(n), S.C.=O(1)
        int max1 = -1, max2 = -1;
        int max1Idx = -1; // max1 index
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] > max1)
            {
                max2 = max1;
                max1 = nums[i];
                max1Idx = i;
            }
            else if(nums[i] >= max2)
                max2 = nums[i];
        }
        return 2 * max2 <= max1 ? max1Idx : -1;
    }
};