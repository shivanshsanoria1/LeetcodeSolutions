class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) { //T.C.=O(nk) , S.C.=O(1)
        vector<int> ans;
        int max, n=nums.size();
        for(int i=0; i<=n-k; i++) // sliding window
        {
            max=nums[i+0]; // first element of window
            for(int j=1; j<k; j++) // elements of window
                if(nums[i+j] > max)
                    max=nums[i+j];
            ans.push_back(max);
        }
        return ans;
    }
};