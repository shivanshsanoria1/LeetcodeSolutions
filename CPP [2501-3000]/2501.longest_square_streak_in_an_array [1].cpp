class Solution {
public:
    // T.C.=O(n*log(m)), S.C.=O(n)
    // m: max-val in nums[]
    int longestSquareStreak(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int maxVal = *max_element(nums.begin(), nums.end());
        int maxSteps = 0;

        for(int num: nums)
        {
            int steps = 0;
            while(s.find(num) != s.end())
            {
                // max possible length of sequence
                if(++steps == 5)
                    return steps;
                // to prevent int overflow
                if(num > sqrt(maxVal))
                    break;
                // next num in sequence
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