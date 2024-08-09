class Solution {
public:
    // T.C.=O(l*n*log(n) + q), S.C.=O(l*n)
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        int n=nums.size(), l=nums[0].size();
        vector<vector<int>> grid(l+1, vector<int>(n, -1));

        for(int i=1; i<=l; i++)
        {
            vector<pair<string, int>> temp;
            for(int j=0; j<n; j++)
                temp.push_back({nums[j].substr(l-i), j});

            sort(temp.begin(), temp.end());

            for(int j=0; j<n; j++)
                grid[i][j] = temp[j].second;
        }

        vector<int> ans;
        for(vector<int>& query: queries)
        {
            int k = query[0];
            int d = query[1];
            ans.push_back(grid[d][k-1]);
        }

        return ans;
    }
};
// grid[i]: indexes of nums[] when elements are 
// sorted by taking the rightmost 'i' digits