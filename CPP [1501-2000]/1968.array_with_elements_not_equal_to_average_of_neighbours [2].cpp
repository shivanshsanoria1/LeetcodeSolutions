class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) { // Greedy, T.C.=O(n*logn), S.C.=O(1)
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size()-1; i+=2)
            swap(nums[i], nums[i+1]);
        return nums;
    }
};
/*
# 1,2,3,4,5 -> 2,1,4,3,5
# 1,2,3,4,5,6 -> 2,1,4,3,6,5
*/