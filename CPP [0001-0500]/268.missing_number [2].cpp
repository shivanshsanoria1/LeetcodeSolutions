class Solution {
public:
    int missingNumber(vector<int>& nums) { // T.C.=O(n), S.C.=O(1)
        int n=nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        return n*(n+1)/2 - sum;
    }
};