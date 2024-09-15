class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    int longestSubarray(vector<int>& nums) {
        int maxVal = *max_element(nums.begin(), nums.end());
        int currLen = 0;
        int maxLen = 0;

        for(int num: nums)
        {
            if(num == maxVal)
            {
                currLen++;
                maxLen = max(maxLen, currLen);
            }
            else
                currLen = 0;
        }

        return maxLen;
    }
};

/*
# we need to find the max-len of subarray with the max bitwise-AND val
# for 2 nums a, b: (a & b) must be in range [0, max(a, b)]
# thus the max bitwise AND possible is the max-element of the entire array
# so the ques. boils down to finding the longest subarray containing only the max-element
*/