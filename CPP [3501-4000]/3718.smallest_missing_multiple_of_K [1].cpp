class Solution {
public:
    // T.C.=O(n + m), S.C.=O(m)
    // m: max-val in nums
    int missingMultiple(vector<int>& nums, int k) {
        int maxVal = *max_element(nums.begin(), nums.end());
        vector<bool> isPresent(maxVal + 1, false);
        for(int num: nums)
            isPresent[num] = true;
        
        int m = k;
        for(; m<=maxVal; m += k)
            if(!isPresent[m])
                break;
        
        return m;
    }
};