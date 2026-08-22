class Solution {
public:
    // T.C.=O(2*n), S.C.=O(1)
    vector<int> concatWithReverse(vector<int>& nums) {
        const int n = nums.size();
        vector<int> nums2(2*n);
        for(int i=0; i<2*n; i++)  
            nums2[i] = i < n ? nums[i] : nums[2*n-1-i];
        
        return nums2;
    }
};