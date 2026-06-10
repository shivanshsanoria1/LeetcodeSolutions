class Solution {
public:
    int solve(vector<int>& stones, int totalSum, int target, int i, int currSum){
        if(currSum >= target || i >= stones.size())
            return abs(currSum - (totalSum - currSum)); // diff between the 2 partitions
        int include = solve(stones, totalSum, target, i+1, currSum + stones[i]);
        int exclude = solve(stones, totalSum, target, i+1, currSum);
        return min(include, exclude);
    }

    int lastStoneWeightII(vector<int>& stones) { // Recursion
        int totalSum = accumulate(stones.begin(), stones.end(), 0);
        int target = (totalSum + 1) / 2; // basically ceil(totalSum/2)
        return solve(stones, totalSum, target, 0, 0);
    }
};