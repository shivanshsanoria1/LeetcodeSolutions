class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) { // T.C.=O(n), S.C.=O(1)
        int ans = 0;
        for(int i=0; i<nums.size(); i++)
            ans ^= nums[i];
        return ans;
    }
};
// XOR properties used-
// a ^ 0 = a
// a ^ a = 0
// a ^ b = b ^ a