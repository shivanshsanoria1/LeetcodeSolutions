class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    int minMoves(vector<int>& nums) {
        int maxVal = *max_element(nums.begin(), nums.end());
        int count = 0;
        for(int num: nums)
            count += maxVal - num;
        
        return count;
    }
};