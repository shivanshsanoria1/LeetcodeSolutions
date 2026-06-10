class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    int minimumPrefixLength(vector<int>& nums) {
        const int n = nums.size();
        int len = 1;
        for(int i=n-2; i>=0 && nums[i] < nums[i+1]; i--)
            len++;
        
        return n - len;
    }
};