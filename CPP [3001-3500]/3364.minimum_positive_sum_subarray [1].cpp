class Solution {
public:
    // T.C.=O(n^2), S.C.=O(1)
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        int minSum = INT_MAX;
        for(int i=0; i<n; i++)
        {
            int sum = 0;
            for(int j=i; j<n && j-i+1 <= r; j++)
            {
                sum += nums[j];
                if(sum > 0 && j-i+1 >= l)
                    minSum = min(minSum, sum); 
            }
        }

        return minSum == INT_MAX ? -1 : minSum;
    }
};