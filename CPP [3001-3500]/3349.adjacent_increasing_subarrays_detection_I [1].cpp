class Solution {
private:
    // returns true if the subarray starting at 
    // index i and of length k is strictly-increasing
    bool isStrictlyIncreasing(vector<int>& nums, int i, int k){
        bool isInc = true;
        for(int j=i+1; j<i+k; j++)
            if(nums[j-1] >= nums[j])
                return false;

        return true;
    }

public:
    // T.C.=O(n+k), S.C.=O(1)
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        for(int i=0; i<=n-2*k; i++)
            if(isStrictlyIncreasing(nums, i, k) && isStrictlyIncreasing(nums, i+k, k))
                return true;

        return false;
    }
};