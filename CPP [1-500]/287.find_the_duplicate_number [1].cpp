class Solution {
public:
    int findDuplicate(vector<int>& nums) { // T.C.=O(n*logn), S.C.=O(1)
        sort(nums.begin(), nums.end());
        for(int i=1; i<nums.size(); i++)
            if(nums[i-1] == nums[i])
                return nums[i];
        return -1;
    }
};