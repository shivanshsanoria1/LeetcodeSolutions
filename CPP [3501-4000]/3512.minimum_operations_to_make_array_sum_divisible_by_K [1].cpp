class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    int minOperations(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        return sum % k;
    }
};