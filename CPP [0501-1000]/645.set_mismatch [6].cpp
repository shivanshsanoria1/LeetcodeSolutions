class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    vector<int> findErrorNums(vector<int>& nums) { 
        int n=nums.size();
        long long int miss_minus_dup = 0;
        long long int miss_plus_dup = 0;

        for(int i=0; i<n; i++)
        {
            miss_minus_dup += (i+1) - nums[i];
            miss_plus_dup += (i+1)*(i+1) - nums[i]*nums[i];
        }
        miss_plus_dup /= miss_minus_dup;

        vector<int> ans(2);
        ans[0] = (miss_plus_dup - miss_minus_dup) / 2;
        ans[1] = (miss_plus_dup + miss_minus_dup) / 2;
        return ans;
    }
};
/*
# sum1: sum of all numbers in array
  correctSum1: sum of numbers from 1 to n
  sum2: sum of square of all numbers in array
  correctSum2: sum of square of numbers from 1 to n
  miss: missing number
  dup: duplicate number
# sum1 = correctSum1 - miss + dup
  (miss - dup) = (correctSum1 - sum1) ...(1)
# sum2 = correctSum2 - miss^2 + dup^2
  miss^2 - dup^2 = correctSum2 - sum2
  (miss + dup)*(miss - dup) = correctSum2 - sum2
  (miss + dup)*(correctSum1 - sum1) = (correctSum2 - sum2)
  (miss + dup) = (correctSum2 - sum2) / (correctSum1 - sum1) ...(2)
# miss = ((2) + (1)) / 2
  dup = ((2) - (1)) / 2
*/