class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n=nums.size();
        vector<int> ans;
        for(int i=0; i<n; i++)
            for(int j=max(i-k, 0); j<=min(i+k, n-1); j++)
                if(nums[j] == key)
                {
                    ans.push_back(i);
                    break;
                }
        return ans;
    }
};