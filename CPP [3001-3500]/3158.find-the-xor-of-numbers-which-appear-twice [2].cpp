class Solution {
public:
    // T.C.=O(n), S.C.=O(n)
    int duplicateNumbersXOR(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());

        int x = 0;
        for(int num: nums)
            x ^= num;
        for(int num: s)
            x ^= num;

        return x;
    }
};
// the property of xor used here: A^A = 0