class Solution {
private:
    bool isArrayAllZeros(vector<int>& nums){
        for(int num: nums)
            if(num != 0)
                return false;

        return true;
    }

public:
    // T.C.=O(n), S.C.=O(1)
    int longestSubsequence(vector<int>& nums) {
        int x = 0;
        for(int num: nums)
            x ^= num;

        if(isArrayAllZeros(nums))
            return 0;

        int n = nums.size();
        return x == 0 ? n-1 : n;
    }
};

/*
# by default the longest subsequence should be the entire array, if the total xor is non-zero
# if the total xor is 0, we can just eliminate a non-zero number to make the xor non-zero
# this elimination only fails if the entire array is filled with 0's, 
  its not possible to get a non-zero xor in this case
*/