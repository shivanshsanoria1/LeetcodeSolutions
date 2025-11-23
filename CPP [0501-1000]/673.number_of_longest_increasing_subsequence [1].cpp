class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) { // DP, T.C.=O(n^2), S.C.=O(n)
        int n=nums.size();
        // stores the length and count of LIS starting from ith index
        vector<pair<int, int>> lis(n, {1, 1}); // {len of LIS, count of LIS} 
        for(int i=n-2; i>=0; i--)
        {
            int lenLIS = 1;
            int countLIS = 1;
            for(int j=i+1; j<n; j++)
                // increasing subsequence possible
                if(nums[i] < nums[j])
                {
                    // new LIS found
                    if(1 + lis[j].first > lenLIS)
                    {
                        lenLIS = 1 + lis[j].first; // update the length of LIS
                        countLIS = lis[j].second; // reset the count of LIS
                    }
                    // another LIS found
                    else if(1 + lis[j].first == lenLIS)
                        countLIS += lis[j].second; // update the count of LIS
                }
            lis[i].first = lenLIS;
            lis[i].second = countLIS;
        }

        int maxLen = 0; // length of LIS
        int maxCount = 0; // count of LIS
        for(int i=0; i<n; i++)
        {
            if(lis[i].first > maxLen)
            {
                maxLen = lis[i].first;
                maxCount = lis[i].second;
            }
            else if(lis[i].first == maxLen)
                maxCount += lis[i].second;
        }
        return maxCount;
    }
};
// do Leetcode-300. Longest Increasing Subsequence first