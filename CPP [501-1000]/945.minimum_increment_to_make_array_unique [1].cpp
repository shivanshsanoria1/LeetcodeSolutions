class Solution {
public:
    // T.C.=O(n*logn), S.C.=O(1)
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int moves = 0;

        for(int i=1; i<nums.size(); i++)
            if(nums[i-1] >= nums[i])
            {
                moves += nums[i-1] - nums[i] + 1;
                nums[i] = nums[i-1] + 1;
            }

        return moves;
    }
};
// prerequisite: [1827. minimum-operations-to-make-the-array-increasing]