class Solution {
public:
    // T.C.=O(n^2), S.C.=O(n)
    int minMoves2(vector<int>& nums) {
        unordered_set<int> finalVals(nums.begin(), nums.end());

        long long int minSum = INT_MAX;
        for(int finalVal: finalVals)
        {
            long long int sum = 0;
            for(int num: nums)
                sum += abs(finalVal - num);
            minSum = min(minSum, sum);
        }

        return minSum;
    }
};
// the final value must be equal to a num already present in the input vector