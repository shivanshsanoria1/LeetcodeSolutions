class Solution {
private:
    #define MOD int(1e9 + 7)

public:
    // T.C.=O((n^2)*log(n^2)), S.C.=O(n^2)
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> sums;

        for(int i=0; i<n; i++)
        {
            int sum = 0;

            for(int j=i; j<n; j++)
            {
                sum = (sum + nums[j]) % MOD;
                sums.push_back(sum);
            }
        }

        sort(sums.begin(), sums.end());

        // convert 'left' and 'right' to 0-based indexing
        left--;
        right--;
        
        int ans = 0;

        for(int i=left; i<=right; i++)
            ans = (ans + sums[i]) % MOD;

        return ans;
    }
};