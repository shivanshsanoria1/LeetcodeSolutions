class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    // 2-pointer
    long long countAlternatingSubarrays(vector<int>& nums) {
        int left = 0, right = 1;
        long long int count = 0;

        while(right < nums.size())
        {
            if(nums[right] == nums[right - 1])
                left = right;
            
            count += right - left + 1;
            
            right++;
        }

        return 1 + count;
    }
};
// 1 is added to count at the end to include the subarray starting at index 0 and of size 1