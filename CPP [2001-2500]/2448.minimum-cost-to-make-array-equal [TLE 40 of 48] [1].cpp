class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) { // T.C.=O(n^2), S.C.=O(1)
        int n=nums.size();
        long long int minCost = LLONG_MAX;
        for(int i=0; i<n; i++)
        {
            int left = i-1, right = i+1;
            long long int currCost = 0;
            while(left >= 0)
            {
                currCost += abs(nums[i] - nums[left]) * (long long int)cost[left];
                if(currCost >= minCost)
                    break;
                left--;
            }
            while(right < n)
            {
                currCost += abs(nums[i] - nums[right]) * (long long int)cost[right];
                if(currCost >= minCost)
                    break;
                right++;
            }
            minCost = min(minCost, currCost);
        }
        return minCost;
    }
};
/*
# Changing all the elements into one of the numbers already existing in the array, say target is optimal.
# assume the num at ith index is the target 
*/