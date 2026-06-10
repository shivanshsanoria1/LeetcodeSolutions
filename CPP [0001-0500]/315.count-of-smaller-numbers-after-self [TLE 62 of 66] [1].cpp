class Solution {
public:
    // T.C.=O(n^2), S.C.=O(1)
    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n, 0);

        for(int i=0; i<n-1; i++)
            for(int j=i+1; j<n; j++)
                if(nums[j] < nums[i])
                    ans[i]++;

        return ans;
    }
};