class Solution {
public:
    int minOperations(vector<int>& nums, int x) { // T.C.=O(n), S.C.=O(1)
        int n=nums.size();
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        if(totalSum == x)
            return n;
        int left = 0, right = 0;
        int sum = 0;
        int maxSubArrSize = INT_MIN; 
        while(right < n)
        {
            sum += nums[right];
            while(left <= right && sum >= totalSum - x)
            {
                if(sum == totalSum - x)
                    maxSubArrSize = max(maxSubArrSize, right - left + 1);
                sum -= nums[left];
                left++;
            }
            right++;
        }
        return maxSubArrSize == INT_MIN ? -1 : n - maxSubArrSize;
    }
};
/*
# sliding-window
# just find the max size subarray which sum upto (totalSum - x)
  and substract its size from the size of initial array
*/