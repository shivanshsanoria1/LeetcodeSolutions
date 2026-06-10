class Solution {
public:
    // T.C.=O((n-k)*k), S.C.=O(1)
    vector<int> maxSlidingWindow(vector<int>& nums, int k) { 
        int n=nums.size();
        vector<int> ans;

        for(int i=0; i <= n-k; i++)
        {
            int maxNum = INT_MIN;
            for(int j=i; j<i+k; j++)
                maxNum = max(maxNum, nums[j]);
                
            ans.push_back(maxNum);
        }

        return ans;
    }
};
// for n elements and window size k, num of windows = (n-k+1)