class Solution {
public:
    // T.C.=O(5*n), S.C.=O(n)
    int longestSquareStreak(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int maxVal = *max_element(nums.begin(), nums.end());
        int maxSteps = 0;

        for(int num: nums)
        {
            int steps = 0;
            while(s.find(num) != s.end())
            {
                if(++steps == 5)
                    return steps;
                if(num > sqrt(maxVal))
                    break;
                num *= num;
            }

            maxSteps = max(maxSteps, steps);
        }

        return maxSteps == 1 ? -1 : maxSteps;
    }
};
// the longest sequence possible is:
// 2^1, 2^2, 2^4, 2^8, 2^16
// the next term 2^32 > 10^5 (since nums[i] <= 10^5)