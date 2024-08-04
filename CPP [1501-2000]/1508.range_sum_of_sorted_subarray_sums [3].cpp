class Solution {
private:
    #define MOD int(1e9 + 7)

public:
	// T.C.=O(n^2 + n*m), S.C.=O(n*m)
	// m: max val in nums[]
    // Counting-sort
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        int maxVal = *max_element(nums.begin(), nums.end());
        vector<int> freq(n*maxVal + 1, 0);

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
# max val in nums[], 'm' is limited to 100 here
# 'take' represents the max amount that can be 
  taken from curr freq as required by 'count'
*/