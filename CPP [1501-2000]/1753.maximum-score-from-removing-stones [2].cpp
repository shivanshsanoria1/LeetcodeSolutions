class Solution {
public:
    // T.C.=O(1), S.C.=O(1)
    // Math
    int maximumScore(int a, int b, int c) {
        vector<int> nums = {a, b, c};
        sort(nums.begin(), nums.end());
        
        a = nums[0];
        b = nums[1];
        c = nums[2];
        
        return a + b <= c ? a + b : c + (a + b - c)/2;
    }
};