class Solution {
public:
    int maxDivScore(vector<int>& nums, vector<int>& divisors) {
        int maxScore = -1;
        int ans = -1;
        for(int div: divisors)
        {
            int currScore = 0;
            for(int num: nums)
                if(num % div == 0)
                    currScore++;
                    
            if(currScore > maxScore)
            {
                maxScore = currScore;
                ans = div;
            }
            else if(currScore == maxScore && div < ans)
                ans = div;
        }
        return ans;
    }
};