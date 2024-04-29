class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    int minOperations(vector<int>& nums, int k) {
        int x = 0;

        for(int num: nums)
            x ^= num;

        return __builtin_popcount(x ^ k);
    }
};