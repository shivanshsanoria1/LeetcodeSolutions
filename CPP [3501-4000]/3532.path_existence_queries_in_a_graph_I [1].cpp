class Solution {
public:
    // T.C.=O(n + q), S.C.=O(n)
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        // component id of each element
        vector<int> compIds(n, 0);
        for(int i=1, compId = 0; i<n; i++)
        {
            // ith element is in a new component
            if(nums[i] > nums[i-1] + maxDiff)
                compId++;

            compIds[i] = compId;
        }
        
        vector<bool> ans;
        for(vector<int>& query: queries)
        {
            int a = query[0], b = query[1];
            ans.push_back(compIds[a] == compIds[b]);
        }

        return ans;
    }
};