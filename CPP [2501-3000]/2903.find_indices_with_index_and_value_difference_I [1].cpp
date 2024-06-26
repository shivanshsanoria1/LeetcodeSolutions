class Solution {
public:
    // T.C.=O(n^2), S.C.=O(1)
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        vector<int> ans(2, -1);
        int n=nums.size();

        for(int i=0; i < n - indexDifference; i++)
            for(int j = i + indexDifference; j<n; j++)
                if(abs(nums[i] - nums[j]) >= valueDifference)
                {
                    ans[0] = i;
                    ans[1] = j;
                    return ans;
                }

        return ans;  
    }
};