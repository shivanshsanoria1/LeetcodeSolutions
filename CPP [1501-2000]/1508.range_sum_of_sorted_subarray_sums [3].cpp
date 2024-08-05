class Solution {
private:
    #define MOD int(1e9 + 7)

public:
    // T.C.=O(n^2 + s), S.C.=O(s)
    // s: sum of all elements in nums[]
    // Counting-sort
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        vector<int> freq(totalSum + 1, 0);

        for(int i=0; i<n; i++)
        {
            int sum = 0;
            for(int j=i; j<n; j++)
            {
                sum += nums[j];
                freq[sum]++;
            }
        }

        // skip the first 'left - 1' elements
        int count = 0;
        for(int i=1; i<freq.size() && count < left-1; i++)
        {
            int take = min(freq[i], left-1 - count);
            count += take;
            freq[i] -= take;
        }

        // calculate the ans for the first 
        // 'right - left + 1' remaining elements
        count = 0;
        int ans = 0;
        for(int i=1; i<freq.size() && count < right-left+1; i++)
        {
            int take = min(freq[i], right-left+1 - count);
            count += take;
            freq[i] -= take;

            ans = (ans + (long long int)take*i) % MOD;
        }

        return ans;
    }
};
/*
# max val of nums[i] is 100, 
  so max sum of entire array is limited to n*100
# 'take' represents the max amount that can be 
  taken from curr freq as required by 'count'
*/