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
                sum += nums[j];
                sums.push_back(sum);
            }
        }

        sort(sums.begin(), sums.end());
        
        int totalSum = 0;
        for(int i=left-1; i<=right-1; i++)
            totalSum = (totalSum + sums[i]) % MOD;

        return totalSum;
    }
};