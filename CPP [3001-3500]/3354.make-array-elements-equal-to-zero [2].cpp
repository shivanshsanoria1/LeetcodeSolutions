class Solution {
public:
    // T.C.=O(n), S.C.=O(n)
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixSum(n, 0);
        prefixSum[0] = nums[0];
        for(int i=1; i<n; i++)
            prefixSum[i] = prefixSum[i-1] + nums[i];

        int count = 0;
        for(int i=0; i<n; i++)
        {
            if(nums[i] != 0)
                continue;

            // sum of elements in index-range [0, i-1]
            int leftSum = i-1 >= 0 ? prefixSum[i-1] : 0;
            // sum of elements in index-range [i+1, n-1]
            int rightSum = prefixSum[n-1] - prefixSum[i];

            // can start moving in both left and right dirs
            if(leftSum == rightSum)
                count += 2;
            // can only move in the dir with the larger sum
            else if(abs(leftSum - rightSum) == 1)
                count++;
        }

        return count;
    }
};