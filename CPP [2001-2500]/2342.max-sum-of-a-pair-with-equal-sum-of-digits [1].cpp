class Solution {
public:
    // returns sum of digits of num
    int digitSum(int num)
    {
        int sum = 0;
        while(num > 0)
        {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }

    int maximumSum(vector<int>& nums) { // T.C.=O(n), S.C.=O(n)
        int n = nums.size();
        // i: digit sum, digitSums[i]: 2 max numbers from nums[] with digit sum i
        vector<pair<int, int>> digSums(82, {-1, -1}); 
        for(int i=0; i<n; i++)
        {
            int idx = digitSum(nums[i]); // find the index for digSums[]
            int max1 = digSums[idx].first; // 1st max 
            int max2 = digSums[idx].second; // 2nd max
            if(nums[i] >= max1) // new 1st max found
            {
                max2 = max1;
                max1 = nums[i];
                // update max1 and max2 in digSums[]
                digSums[idx].first = max1;
                digSums[idx].second = max2;
            }
            else if(nums[i] > max2) // new 2nd max found
            {
                max2 = nums[i];
                // update max2 in digSums[]
                digSums[idx].second = max2;
            }
        }
        int ans = -1;
        for(int i=1; i<=81; i++) // skip i=0 as digit sum 0 is impossible here
        {
            int max1 = digSums[i].first;
            int max2 = digSums[i].second;
            if(max1 > -1 && max2 > -1) // {max1, max2} pair exists
                ans = max(ans, max1 + max2);
        }
        return ans;
    }
};
// since 1 <= nums[i] <= 10^9
// therefore 1 <= digitSum <= 81
// min digitSum is 1 for 1, 10, 100,...
// max digitSum is 81 for 999-999-999