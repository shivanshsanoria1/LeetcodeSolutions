class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) { // T.C.=O(n^2)
        int n=nums.size();
        vector<int> ans(n, -1);
        if(n < 2*k+1)
            return ans;
        for(int i=k; i<n-k; i++)
        {
            int left = i-1, right = i+1;
            int leftSum = 0, rightSum = 0;
            int tempK = k;
            while(tempK--)
            {
                leftSum += nums[left];
                rightSum += nums[right];
                left--;
                right++;
            }
            ans[i] = (leftSum + nums[i] + rightSum) / (2*k + 1);
        }
        return ans;
    }
};