class Solution {
public:
    // T.C.=O(n*logn)
    vector<int> sortedSquares(vector<int>& nums) { 
        for(int& num: nums)
            num = num*num;
        sort(nums.begin(), nums.end());
        return nums;
    }
};