class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) { // T.C.=O(n^2), S.C.=O(n)
        unordered_set<int> s(nums.begin(), nums.end());
        long long int minCost = LLONG_MAX;
        for(int target: s)
        {
            long long int currCost = 0;
            for(int i=0; i<nums.size(); i++)
            {
                currCost += abs(target - nums[i]) * (long long int)cost[i];
                if(currCost >= minCost)
                    break;
            }
            minCost = min(minCost, currCost);
        }
        return minCost;
    }
};
// Changing all the elements into one of the numbers already existing in the array, say target is optimal.