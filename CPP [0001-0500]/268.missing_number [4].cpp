class Solution {
public:
    int missingNumber(vector<int>& nums) { // T.C.=O(n), S.C.=O(1)
        int ans = 0;
        for(int i=0; i<nums.size(); i++)
            ans = ans ^ nums[i] ^ (i+1);
        return ans;
    }
};