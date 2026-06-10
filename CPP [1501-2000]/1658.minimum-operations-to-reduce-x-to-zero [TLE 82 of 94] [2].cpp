class Solution {
public:
    int minOperations(vector<int>& nums, int x) { // T.C.=O(n^2), S.C.=O(1)
        int n=nums.size();
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        if(totalSum == x)
            return n;
        int maxSubArrSize = INT_MIN; 
        for(int i=0; i<n; i++)
        {
            int sum = 0;
            for(int j=i; j<n; j++)
            {
                sum += nums[j];
                if(sum == totalSum - x)
                {
                    maxSubArrSize = max(maxSubArrSize, j-i+1);
                    break;
                }
            }
        }
        return maxSubArrSize == INT_MIN ? -1 : n - maxSubArrSize;
    }
};
// just find the max size subarray which sum upto (totalSum - x)
// and substract its size from the size of initial array