class Solution {
public:
    // T.C.=O(n*logn), S.C.=O(1)
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n=nums.size();

        int finalVal1 = n % 2 == 0 ? nums[n/2-1] : nums[(n-1)/2];
        int finalVal2 = n % 2 == 0 ? nums[n/2] : nums[(n-1)/2];

        long long int sum1 = 0;
        long long int sum2 = 0;

        for(int num: nums)
        {
            sum1 += abs(finalVal1 - num);
            sum2 += abs(finalVal2 - num);
        }

        return min(sum1, sum2);
    }
};
/*
# the final value must be equal to a num already present in the input vector
# the final value must be the median
# for a vector of size n, median is at index:
  [(n-1) / 2] (if n is odd)
  [n/2 - 1] and [n/2] (if n is even) 
*/