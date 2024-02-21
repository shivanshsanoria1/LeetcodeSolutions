class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n=nums.size();
        int minCost = INT_MAX;
        for(int i=1; i<n-1; i++)
            for(int j=i+1; j<n; j++)
                minCost = min(minCost, nums[i] + nums[j]);
        return nums[0] + minCost;
    }
    /*
    # index 0 is always the start of subarray-1
    # i: start of subarray-2
    # j: start of subarray-3
    */
};