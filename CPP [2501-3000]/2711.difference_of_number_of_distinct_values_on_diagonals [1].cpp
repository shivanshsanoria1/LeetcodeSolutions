class Solution {
public:
    // T.C.=O(m*n*k), S.C.=O(k)
    // k = min(m, n)
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();

        vector<vector<int>> ans(m, vector<int>(n, 0));

        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
            {
                unordered_set<int> leftNums;
                int left_i = i-1, left_j = j-1;
                while(left_i >= 0 && left_j >= 0)
                {
                    leftNums.insert(grid[left_i][left_j]);
                    left_i--;
                    left_j--;
                }

                unordered_set<int> rightNums;
                int right_i = i+1, right_j = j+1;
                while(right_i < m && right_j < n)
                {
                    rightNums.insert(grid[right_i][right_j]);
                    right_i++;
                    right_j++;
                }

                ans[i][j] = abs((int)leftNums.size() - (int)rightNums.size());
            }

        return ans;
    }
};