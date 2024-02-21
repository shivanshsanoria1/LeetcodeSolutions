class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) { // T.C.=O(n)
        int n=nums.size();
        vector<int> ans(n, -1);
        int winSize = 2*k + 1; // window size
        if(n < winSize)
            return ans;
        long long int winSum = 0; // window sum
        for(int i=0; i<winSize; i++) // 1st window sum
            winSum += nums[i];
        ans[k] = winSum / winSize;
        for(int i=k+1; i<n-k; i++)
        {
            winSum = winSum + nums[i+k] - nums[i-k-1];
            ans[i] = winSum / winSize;
        }
        return ans;
    }
};