class Solution {
public:
    int longestSubarray(vector<int>& nums) { // 2-Pointer, T.C.=O(n), S.C.=O(1)
        int left = 0, right = 0;
        int zeros = 0; // keeps track of freq of 0's in curr window
        int ans = 0;
        while(right < nums.size())
        {
            if(nums[right] == 0)
                zeros++;
            if(zeros == 2)
                while(zeros != 1)
                {
                    if(nums[left] == 0)
                        zeros--;
                    left++;
                }
            int curr = right - left;
            ans = max(ans, curr);
            right++;
        }
        return ans;
    }
};

/*
# at any time the freq of 0's in curr window must be 0 or 1, 
# if freq reaches 2, move left forward until freq reaches 1
*/