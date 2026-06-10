class Solution {
public:
    // T.C.=O(n^2), S.C.=O(1)
    int countValidSelections(vector<int>& nums) {
        int count = 0;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] != 0)
                continue;

            // sum of elements in index-range [0, i-1]
            int leftSum = accumulate(nums.begin(), nums.begin() + i, 0);
            // sum of elements in index-range [i+1, n-1]
            int rightSum = accumulate(nums.begin() + i+1, nums.end(), 0);

            // can start moving in both left and right dirs
            if(leftSum == rightSum)
                count += 2;
            // can only move in the dir with the larger sum
            else if(abs(leftSum - rightSum) == 1)
                count++;
        }

        return count;
    }
};